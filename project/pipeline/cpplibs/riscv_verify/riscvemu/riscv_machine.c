/*
 * RISCV machine
 * 
 * Copyright (c) 2016-2017 Fabrice Bellard
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <inttypes.h>
#include <assert.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>

#include "cutils.h"
#include "iomem.h"
#include "riscv_cpu.h"
#include "virtio.h"
#include "machine.h"

/* RISCV machine */

typedef struct RISCVMachine {
    VirtMachine common;
    PhysMemoryMap *mem_map;
    uint8_t *phys_mem;
    size_t phys_mem_size;
    RISCVCPUState *cpu_state;
    uint64_t ram_size;
    /* RTC */
    BOOL rtc_real_time;
    uint64_t rtc_start_time;
    uint64_t timecmp;
    /* PLIC */
    uint32_t plic_pending_irq, plic_served_irq;
    /* HTIF */
    uint64_t htif_tohost, htif_fromhost;

    int virtio_count;
    
    /* kernel command line */
    char cmd_line[512];
} RISCVMachine;

#define LOW_RAM_SIZE   0x00010000 /* 64KB */
#define RAM_BASE_ADDR  0x80000000
#define CLINT_BASE_ADDR 0x02000000
#define CLINT_SIZE      0x000c0000
#define HTIF_BASE_ADDR 0x40008000
#define IDE_BASE_ADDR  0x40009000
#define VIRTIO_BASE_ADDR 0x40010000
#define VIRTIO_SIZE      0x1000
#define VIRTIO_IRQ       1
#define PLIC_BASE_ADDR 0x40100000
#define PLIC_SIZE      0x00400000

#define RTC_FREQ 10000000
#define RTC_FREQ_DIV 16 /* arbitrary, relative to CPU freq to have a
                           10 MHz frequency */

static uint64_t rtc_get_real_time(RISCVMachine *s)
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (uint64_t)ts.tv_sec * RTC_FREQ +
        (ts.tv_nsec / (1000000000 / RTC_FREQ));
}

static uint64_t rtc_get_time(RISCVMachine *m)
{
    uint64_t val;
    if (m->rtc_real_time) {
        val = rtc_get_real_time(m) - m->rtc_start_time;
    } else {
        val = riscv_cpu_get_cycles(m->cpu_state) / RTC_FREQ_DIV;
    }
    //    printf("rtc_time=%" PRId64 "\n", val);
    return val;
}

static uint64_t htif_read(void *opaque, uint64_t offset,
                          int size_log2)
{
    RISCVMachine *s = opaque;
    uint32_t val;

    assert(size_log2 == 2);
    switch(offset) {
    case 0:
        val = s->htif_tohost;
        break;
    case 4:
        val = s->htif_tohost >> 32;
        break;
    case 8:
        val = s->htif_fromhost;
        break;
    case 12:
        val = s->htif_fromhost >> 32;
        break;
    default:
        val = 0;
        break;
    }
    return val;
}

static void htif_handle_cmd(RISCVMachine *s)
{
    uint32_t device, cmd;

    device = s->htif_tohost >> 56;
    cmd = (s->htif_tohost >> 48) & 0xff;
    if (s->htif_tohost == 1) {
        /* shuthost */
        printf("\nPower off.\n");
#ifndef VERIFICATION
        exit(0);
#endif
    } else if (device == 1 && cmd == 1) {
        uint8_t buf[1];
        buf[0] = s->htif_tohost & 0xff;
        s->common.console->write_data(s->common.console->opaque, buf, 1);
        s->htif_tohost = 0;
        s->htif_fromhost = ((uint64_t)device << 56) | ((uint64_t)cmd << 48);
    } else if (device == 1 && cmd == 0) {
        /* request keyboard interrupt */
        s->htif_tohost = 0;
    } else {
        printf("HTIF: unsupported tohost=0x%016" PRIx64 "\n", s->htif_tohost);
    }
}

static void htif_write(void *opaque, uint64_t offset, uint64_t val,
                       int size_log2)
{
    RISCVMachine *s = opaque;

    assert(size_log2 == 2);
    switch(offset) {
    case 0:
        s->htif_tohost = (s->htif_tohost & ~0xffffffff) | val;
        break;
    case 4:
        s->htif_tohost = (s->htif_tohost & 0xffffffff) | ((uint64_t)val << 32);
        htif_handle_cmd(s);
        break;
    case 8:
        s->htif_fromhost = (s->htif_fromhost & ~0xffffffff) | val;
        break;
    case 12:
        s->htif_fromhost = (s->htif_fromhost & 0xffffffff) |
            (uint64_t)val << 32;
        break;
    default:
        break;
    }
}

#if 0
static void htif_poll(RISCVMachine *s)
{
    uint8_t buf[1];
    int ret;

    if (s->htif_fromhost == 0) {
        ret = s->console->read_data(s->console->opaque, buf, 1);
        if (ret == 1) {
            s->htif_fromhost = ((uint64_t)1 << 56) | ((uint64_t)0 << 48) |
                buf[0];
        }
    }
}
#endif

static uint64_t clint_read(void *opaque, uint64_t offset, int size_log2)
{
    RISCVMachine *m = opaque;
    uint32_t val;

    assert(size_log2 == 2);
    switch(offset) {
    case 0xbff8:
        val = rtc_get_time(m);
        break;
    case 0xbffc:
        val = rtc_get_time(m) >> 32;
        break;
    case 0x4000:
        val = m->timecmp;
        break;
    case 0x4004:
        val = m->timecmp >> 32;
        break;
    default:
        val = 0;
        break;
    }
    return val;
}
 
static void clint_write(void *opaque, uint64_t offset, uint64_t val,
                      int size_log2)
{
    RISCVMachine *m = opaque;

    assert(size_log2 == 2);
    switch(offset) {
    case 0x4000:
        m->timecmp = (m->timecmp & ~0xffffffff) | val;
        riscv_cpu_reset_mip(m->cpu_state, MIP_MTIP);
        break;
    case 0x4004:
        m->timecmp = (m->timecmp & 0xffffffff) | ((uint64_t)val << 32);
        riscv_cpu_reset_mip(m->cpu_state, MIP_MTIP);
        break;
    default:
        break;
    }
}

static void plic_update_mip(RISCVMachine *s)
{
    RISCVCPUState *cpu = s->cpu_state;
    uint32_t mask;
    mask = s->plic_pending_irq & ~s->plic_served_irq;
    if (mask) {
        riscv_cpu_set_mip(cpu, MIP_MEIP | MIP_SEIP);
    } else {
        riscv_cpu_reset_mip(cpu, MIP_MEIP | MIP_SEIP);
    }
}

#define PLIC_HART_BASE 0x200000
#define PLIC_HART_SIZE 0x1000

static uint64_t plic_read(void *opaque, uint64_t offset, int size_log2)
{
    RISCVMachine *s = opaque;
    uint32_t val, mask;
    int i;
    assert(size_log2 == 2);
    switch(offset) {
    case PLIC_HART_BASE:
        val = 0;
        break;
    case PLIC_HART_BASE + 4:
        mask = s->plic_pending_irq & ~s->plic_served_irq;
        if (mask != 0) {
            i = ctz32(mask);
            s->plic_served_irq |= 1 << i;
            plic_update_mip(s);
            val = i + 1;
        } else {
            val = 0;
        }
        break;
    default:
        val = 0;
        break;
    }
    return val;
}

static void plic_write(void *opaque, uint64_t offset, uint64_t val,
                       int size_log2)
{
    RISCVMachine *s = opaque;
    
    assert(size_log2 == 2);
    switch(offset) {
    case PLIC_HART_BASE + 4:
        val--;
        if (val < 32) {
            s->plic_served_irq &= ~(1 << val);
            plic_update_mip(s);
        }
        break;
    default:
        break;
    }
}

static void plic_set_irq(RISCVMachine *s, int irq_num, int state)
{
    uint32_t mask;

    mask = 1 << (irq_num - 1);
    if (state) 
        s->plic_pending_irq |= mask;
    else
        s->plic_pending_irq &= ~mask;
    plic_update_mip(s);
}

static uint8_t *get_ram_ptr(RISCVMachine *s, uint64_t paddr)
{
    PhysMemoryRange *pr = get_phys_mem_range(s->mem_map, paddr);
    if (!pr)
        return NULL;
    return s->phys_mem + pr->phys_mem_offset + (uintptr_t)(paddr - pr->addr);
}

/* FDT machine description */

#define FDT_MAGIC	0xd00dfeed
#define FDT_VERSION	17

struct fdt_header {
    uint32_t magic;
    uint32_t totalsize;
    uint32_t off_dt_struct;
    uint32_t off_dt_strings;
    uint32_t off_mem_rsvmap;
    uint32_t version;
    uint32_t last_comp_version; /* <= 17 */
    uint32_t boot_cpuid_phys;
    uint32_t size_dt_strings;
    uint32_t size_dt_struct;
};

struct fdt_reserve_entry {
       uint64_t address;
       uint64_t size;
};

#define FDT_BEGIN_NODE	1
#define FDT_END_NODE	2
#define FDT_PROP	3
#define FDT_NOP		4
#define FDT_END		9

typedef struct {
    uint32_t *tab;
    int tab_len;
    int tab_size;
    int open_node_count;
    
    char *string_table;
    int string_table_len;
    int string_table_size;
} FDTState;

static FDTState *fdt_init(void)
{
    FDTState *s;
    s = mallocz(sizeof(*s));
    return s;
}

static void fdt_alloc_len(FDTState *s, int len)
{
    int new_size;
    if (unlikely(len > s->tab_size)) {
        new_size = max_int(len, s->tab_size * 3 / 2);
        s->tab = realloc(s->tab, new_size * sizeof(uint32_t));
        s->tab_size = new_size;
    }
}

static void fdt_put32(FDTState *s, int v)
{
    fdt_alloc_len(s, s->tab_len + 1);
    s->tab[s->tab_len++] = cpu_to_be32(v);
}

/* the data is zero padded */
static void fdt_put_data(FDTState *s, const uint8_t *data, int len)
{
    int len1;
    
    len1 = (len + 3) / 4;
    fdt_alloc_len(s, s->tab_len + len1);
    memcpy(s->tab + s->tab_len, data, len);
    memset((uint8_t *)(s->tab + s->tab_len) + len, 0, -len & 3);
    s->tab_len += len1;
}

static void fdt_begin_node(FDTState *s, const char *name)
{
    fdt_put32(s, FDT_BEGIN_NODE);
    fdt_put_data(s, (uint8_t *)name, strlen(name) + 1);
    s->open_node_count++;
}

static void fdt_begin_node_num(FDTState *s, const char *name, uint64_t n)
{
    char buf[256];
    snprintf(buf, sizeof(buf), "%s@%" PRIx64, name, n);
    fdt_begin_node(s, buf);
}

static void fdt_end_node(FDTState *s)
{
    fdt_put32(s, FDT_END_NODE);
    s->open_node_count--;
}

static int fdt_get_string_offset(FDTState *s, const char *name)
{
    int pos, new_size, name_size, new_len;

    pos = 0;
    while (pos < s->string_table_len) {
        if (!strcmp(s->string_table + pos, name))
            return pos;
        pos += strlen(s->string_table + pos) + 1;
    }
    /* add a new string */
    name_size = strlen(name) + 1;
    new_len = s->string_table_len + name_size;
    if (new_len > s->string_table_size) {
        new_size = max_int(new_len, s->string_table_size * 3 / 2);
        s->string_table = realloc(s->string_table, new_size);
        s->string_table_size = new_size;
    }
    pos = s->string_table_len;
    memcpy(s->string_table + pos, name, name_size);
    s->string_table_len = new_len;
    return pos;
}

static void fdt_prop(FDTState *s, const char *prop_name,
                     const void *data, int data_len)
{
    fdt_put32(s, FDT_PROP);
    fdt_put32(s, data_len);
    fdt_put32(s, fdt_get_string_offset(s, prop_name));
    fdt_put_data(s, data, data_len);
}

static void fdt_prop_tab_u32(FDTState *s, const char *prop_name,
                             uint32_t *tab, int tab_len)
{
    int i;
    fdt_put32(s, FDT_PROP);
    fdt_put32(s, tab_len * sizeof(uint32_t));
    fdt_put32(s, fdt_get_string_offset(s, prop_name));
    for(i = 0; i < tab_len; i++)
        fdt_put32(s, tab[i]);
}

static void fdt_prop_u32(FDTState *s, const char *prop_name, uint32_t val)
{
    fdt_prop_tab_u32(s, prop_name, &val, 1);
}

static void fdt_prop_tab_u64_2(FDTState *s, const char *prop_name,
                               uint64_t v0, uint64_t v1)
{
    uint32_t tab[4];
    tab[0] = v0 >> 32;
    tab[1] = v0;
    tab[2] = v1 >> 32;
    tab[3] = v1;
    fdt_prop_tab_u32(s, prop_name, tab, 4);
}

static void fdt_prop_str(FDTState *s, const char *prop_name,
                         const char *str)
{
    fdt_prop(s, prop_name, str, strlen(str) + 1);
}

/* NULL terminated string list */
static void fdt_prop_tab_str(FDTState *s, const char *prop_name,
                             ...)
{
    va_list ap;
    int size, str_size;
    char *ptr, *tab;

    va_start(ap, prop_name);
    size = 0;
    for(;;) {
        ptr = va_arg(ap, char *);
        if (!ptr)
            break;
        str_size = strlen(ptr) + 1;
        size += str_size;
    }
    va_end(ap);
    
    tab = malloc(size);
    va_start(ap, prop_name);
    size = 0;
    for(;;) {
        ptr = va_arg(ap, char *);
        if (!ptr)
            break;
        str_size = strlen(ptr) + 1;
        memcpy(tab + size, ptr, str_size);
        size += str_size;
    }
    va_end(ap);
    
    fdt_prop(s, prop_name, tab, size);
    free(tab);
}

/* write the FDT to 'dst1'. return the FDT size in bytes */
int fdt_output(FDTState *s, uint8_t *dst)
{
    struct fdt_header *h;
    struct fdt_reserve_entry *re;
    int dt_struct_size;
    int dt_strings_size;
    int pos;

    assert(s->open_node_count == 0);
    
    fdt_put32(s, FDT_END);
    
    dt_struct_size = s->tab_len * sizeof(uint32_t);
    dt_strings_size = s->string_table_len;

    h = (struct fdt_header *)dst;
    h->magic = cpu_to_be32(FDT_MAGIC);
    h->version = cpu_to_be32(FDT_VERSION);
    h->last_comp_version = cpu_to_be32(16);
    h->boot_cpuid_phys = cpu_to_be32(0);
    h->size_dt_strings = cpu_to_be32(dt_strings_size);
    h->size_dt_struct = cpu_to_be32(dt_struct_size);

    pos = sizeof(struct fdt_header);

    h->off_dt_struct = cpu_to_be32(pos);
    memcpy(dst + pos, s->tab, dt_struct_size);
    pos += dt_struct_size;

    /* align to 8 */
    while ((pos & 7) != 0) {
        dst[pos++] = 0;
    }
    h->off_mem_rsvmap = cpu_to_be32(pos);
    re = (struct fdt_reserve_entry *)(dst + pos);
    re->address = 0; /* no reserved entry */
    re->size = 0;
    pos += sizeof(struct fdt_reserve_entry);

    h->off_dt_strings = cpu_to_be32(pos);
    memcpy(dst + pos, s->string_table, dt_strings_size);
    pos += dt_strings_size;

    /* align to 8, just in case */
    while ((pos & 7) != 0) {
        dst[pos++] = 0;
    }

    h->totalsize = cpu_to_be32(pos);
    return pos;
}

void fdt_end(FDTState *s)
{
    free(s->tab);
    free(s->string_table);
    free(s);
}

static int riscv_build_fdt(RISCVMachine *m, uint8_t *dst)
{
    FDTState *s;
    int size, max_xlen, i, cur_phandle, intc_phandle, plic_phandle;
    char isa_string[128], *q;
    uint32_t misa;
    uint32_t tab[4];

    s = fdt_init();

    cur_phandle = 1;
    
    fdt_begin_node(s, "");
    fdt_prop_u32(s, "#address-cells", 2);
    fdt_prop_u32(s, "#size-cells", 2);
    fdt_prop_str(s, "compatible", "ucbbar,riscvemu-bar_dev");
    fdt_prop_str(s, "model", "ucbbar,riscvemu-bare");

    /* CPU list */
    fdt_begin_node(s, "cpus");
    fdt_prop_u32(s, "#address-cells", 1);
    fdt_prop_u32(s, "#size-cells", 0);
    fdt_prop_u32(s, "timebase-frequency", RTC_FREQ);

    /* cpu */
    fdt_begin_node_num(s, "cpu", 0);
    fdt_prop_str(s, "device_type", "cpu");
    fdt_prop_u32(s, "reg", 0);
    fdt_prop_str(s, "status", "okay");
    fdt_prop_str(s, "compatible", "riscv");

    max_xlen = riscv_cpu_get_max_xlen();
    misa = riscv_cpu_get_misa(m->cpu_state);
    q = isa_string;
    q += snprintf(isa_string, sizeof(isa_string), "rv%d", max_xlen);
    for(i = 0; i < 26; i++) {
        if (misa & (1 << i))
            *q++ = 'a' + i;
    }
    *q = '\0';
    fdt_prop_str(s, "riscv,isa", isa_string);
    
    fdt_prop_str(s, "mmu-type", max_xlen <= 32 ? "sv32" : "sv48");
    fdt_prop_u32(s, "clock-frequency", 2000000000);

    fdt_begin_node(s, "interrupt-controller");
    fdt_prop_u32(s, "#interrupt-cells", 1);
    fdt_prop(s, "interrupt-controller", NULL, 0);
    fdt_prop_str(s, "compatible", "riscv,cpu-intc");
    intc_phandle = cur_phandle++;
    fdt_prop_u32(s, "phandle", intc_phandle);
    fdt_end_node(s); /* interrupt-controller */
    
    fdt_end_node(s); /* cpu */
    
    fdt_end_node(s); /* cpus */

    fdt_begin_node_num(s, "memory", RAM_BASE_ADDR);
    fdt_prop_str(s, "device_type", "memory");
    tab[0] = (uint64_t)RAM_BASE_ADDR >> 32;
    tab[1] = RAM_BASE_ADDR;
    tab[2] = m->ram_size >> 32;
    tab[3] = m->ram_size;
    fdt_prop_tab_u32(s, "reg", tab, 4);
    
    fdt_end_node(s); /* memory */
    
    fdt_begin_node(s, "soc");
    fdt_prop_u32(s, "#address-cells", 2);
    fdt_prop_u32(s, "#size-cells", 2);
    fdt_prop_tab_str(s, "compatible",
                     "ucbbar,riscvemu-bar-soc", "simple-bus", NULL);
    fdt_prop(s, "ranges", NULL, 0);

    fdt_begin_node_num(s, "clint", CLINT_BASE_ADDR);
    fdt_prop_str(s, "compatible", "riscv,clint0");

    tab[0] = intc_phandle;
    tab[1] = 3; /* M IPI irq */
    tab[2] = intc_phandle;
    tab[3] = 7; /* M timer irq */
    fdt_prop_tab_u32(s, "interrupts-extended", tab, 4);

    fdt_prop_tab_u64_2(s, "reg", CLINT_BASE_ADDR, CLINT_SIZE);
    
    fdt_end_node(s); /* clint */

    fdt_begin_node_num(s, "plic", PLIC_BASE_ADDR);
    fdt_prop_u32(s, "#interrupt-cells", 1);
    fdt_prop(s, "interrupt-controller", NULL, 0);
    fdt_prop_str(s, "compatible", "riscv,plic0");
    fdt_prop_u32(s, "riscv,ndev", 31);
    fdt_prop_tab_u64_2(s, "reg", PLIC_BASE_ADDR, PLIC_SIZE);

    tab[0] = intc_phandle;
    tab[1] = 9; /* S ext irq */
    tab[2] = intc_phandle;
    tab[3] = 11; /* M ext irq */
    fdt_prop_tab_u32(s, "interrupts-extended", tab, 4);

    plic_phandle = cur_phandle++;
    fdt_prop_u32(s, "phandle", plic_phandle);

    fdt_end_node(s); /* plic */
    
    for(i = 0; i < m->virtio_count; i++) {
        fdt_begin_node_num(s, "virtio", VIRTIO_BASE_ADDR + i * VIRTIO_SIZE);
        fdt_prop_str(s, "compatible", "virtio,mmio");
        fdt_prop_tab_u64_2(s, "reg", VIRTIO_BASE_ADDR + i * VIRTIO_SIZE,
                           VIRTIO_SIZE);
        tab[0] = plic_phandle;
        tab[1] = VIRTIO_IRQ + i;
        fdt_prop_tab_u32(s, "interrupts-extended", tab, 2);
        fdt_end_node(s); /* virtio */
    }


    fdt_end_node(s); /* soc */

    fdt_begin_node(s, "chosen");
    fdt_prop_str(s, "bootargs", m->cmd_line);
    fdt_end_node(s); /* chosen */
    
    fdt_end_node(s); /* / */

    size = fdt_output(s, dst);
#if 0
    {
        FILE *f;
        f = fopen("/tmp/riscvemu.dtb", "wb");
        fwrite(dst, 1, size, f);
        fclose(f);
    }
#endif
    fdt_end(s);
    return size;
}

void setup_linux_config(VirtMachine *s1)
{
    RISCVMachine *s = (RISCVMachine *)s1;
    uint32_t fdt_addr;
    uint8_t *ram_ptr;
    uint32_t *q;
    
    ram_ptr = get_ram_ptr(s, 0);
    
    fdt_addr = 0x1000 + 8 * 8;

    riscv_build_fdt(s, ram_ptr + fdt_addr);

    /* jump_addr = 0x80000000 */
    
    q = (uint32_t *)(ram_ptr + 0x1000);
    q[0] = 0x297 + 0x80000000 - 0x1000; /* auipc t0, jump_addr */
    q[1] = 0x597; /* auipc a1, dtb */
    q[2] = 0x58593 + ((fdt_addr - 4) << 20); /* addi a1, a1, dtb */
    q[3] = 0xf1402573; /* csrr a0, mhartid */
    q[4] = 0x00028067; /* jalr zero, t0, jump_addr */
}

static uint8_t *virtio_get_ram_ptr(void *opaque, virtio_phys_addr_t paddr)
{
    RISCVMachine *m = opaque;
    return get_ram_ptr(m, paddr);
}

static void virtio_set_irq(void *opaque, int irq_num, int state)
{
    RISCVMachine *s = opaque;
    plic_set_irq(s, irq_num, state);
}

static uint64_t virtio_read(void *opaque, uint64_t offset,
                                int size_log2)
{
    VIRTIODevice *s = opaque;
    //    printf("read offset=0x%x\n", (int)offset);
    return virtio_mmio_read(s, offset, size_log2);
}
 
static void virtio_write(void *opaque, uint64_t offset, uint64_t val,
                      int size_log2)
{
    VIRTIODevice *s = opaque;
    //    printf("write offset=0x%x\n", (int)offset);
    virtio_mmio_write(s, offset, val, size_log2);
}

void virt_machine_set_defaults(VirtMachineParams *p)
{
    memset(p, 0, sizeof(*p));
}

VirtMachine *virt_machine_init(const VirtMachineParams *p)
{
    RISCVMachine *s;
    VIRTIODevice *blk_dev, *net_dev;
    int irq_num, i;
    uint64_t virtio_addr;

    s = mallocz(sizeof(*s));

    s->ram_size = p->ram_size;
    s->phys_mem_size = p->ram_size + LOW_RAM_SIZE;
    s->phys_mem = mallocz(s->phys_mem_size);
    if (!s->phys_mem) {
        fprintf(stderr, "Could not allocate VM memory\n");
        exit(1);
    }
        
    s->mem_map = phys_mem_map_init();

    s->cpu_state = riscv_cpu_init(s->mem_map, s->phys_mem);

    /* RAM */
    cpu_register_ram(s->mem_map, RAM_BASE_ADDR, p->ram_size, 0);
    cpu_register_ram(s->mem_map, 0x00000000, LOW_RAM_SIZE, p->ram_size);
    
    s->rtc_real_time = p->rtc_real_time;
    if (p->rtc_real_time) {
        s->rtc_start_time = rtc_get_real_time(s);
    }
    
    cpu_register_device(s->mem_map, CLINT_BASE_ADDR, CLINT_SIZE, s,
                        clint_read, clint_write, DEVIO_SIZE32);
    cpu_register_device(s->mem_map, PLIC_BASE_ADDR, PLIC_SIZE, s,
                        plic_read, plic_write, DEVIO_SIZE32);
    cpu_register_device(s->mem_map, HTIF_BASE_ADDR, 16,
                        s, htif_read, htif_write, DEVIO_SIZE32);
    s->common.console = p->console;

    virtio_addr = VIRTIO_BASE_ADDR;
    irq_num = VIRTIO_IRQ;
    
    pstrcpy(s->cmd_line, sizeof(s->cmd_line), "loglevel=3");
    
    /* virtio console */
    s->common.console_dev = virtio_console_init(virtio_set_irq, irq_num, 
                                                virtio_get_ram_ptr, s,
                                                p->console);
    cpu_register_device(s->mem_map, virtio_addr, VIRTIO_SIZE,
                        s->common.console_dev, virtio_read, virtio_write,
                        DEVIO_SIZE8 | DEVIO_SIZE16 | DEVIO_SIZE32);
    virtio_addr += VIRTIO_SIZE;
    irq_num++;
    s->virtio_count++;

    /* virtio net device */
    if (p->net) {
        net_dev = virtio_net_init(virtio_set_irq, irq_num,
                                  virtio_get_ram_ptr, s, p->net);
        cpu_register_device(s->mem_map, virtio_addr, VIRTIO_SIZE,
                            net_dev, virtio_read, virtio_write,
                            DEVIO_SIZE8 | DEVIO_SIZE16 | DEVIO_SIZE32);
        s->common.net_dev = net_dev;
        s->common.net = p->net;
        virtio_addr += VIRTIO_SIZE;
        irq_num++;
        s->virtio_count++;
    }

    /* virtio block device */
    for(i = 0; i < p->drive_count; i++) {
        blk_dev = virtio_block_init(virtio_set_irq, irq_num,
                                    virtio_get_ram_ptr, s, p->tab_drive[i]);
        cpu_register_device(s->mem_map, virtio_addr, VIRTIO_SIZE,
                            blk_dev, virtio_read, virtio_write,
                            DEVIO_SIZE8 | DEVIO_SIZE16 | DEVIO_SIZE32);
        virtio_addr += VIRTIO_SIZE;
        irq_num++;
        s->virtio_count++;
    }

    /* virtio filesystem */
    for(i = 0; i < p->fs_count; i++) {
        VIRTIODevice *fs_dev;
        char buf[64];

        if (i == 0)
            strcpy(buf, "/dev/root");
        else
            snprintf(buf, sizeof(buf), "/dev/root%d", i);
        fs_dev = virtio_9p_init(virtio_set_irq, irq_num, virtio_get_ram_ptr, s,
                                p->tab_fs[i], buf);
        cpu_register_device(s->mem_map, virtio_addr, VIRTIO_SIZE,
                            fs_dev, virtio_read, virtio_write,
                            DEVIO_SIZE8 | DEVIO_SIZE16 | DEVIO_SIZE32);
        //        virtio_set_debug(fs_dev, VIRTIO_DEBUG_9P);
        virtio_addr += VIRTIO_SIZE;
        irq_num++;
        s->virtio_count++;
    }

    if (p->drive_count == 0) {
        pstrcat(s->cmd_line, sizeof(s->cmd_line), " root=root rootfstype=9p rootflags=trans=virtio ro");
    } else {
        pstrcat(s->cmd_line, sizeof(s->cmd_line), " root=/dev/vda ro");
    }

    if (p->cmdline) {
        pstrcat(s->cmd_line, sizeof(s->cmd_line), " ");
        pstrcat(s->cmd_line, sizeof(s->cmd_line), p->cmdline);
    }

    return (VirtMachine *)s;
}

void virt_machine_end(VirtMachine *s1)
{
    RISCVMachine *s = (RISCVMachine *)s1;
    /* XXX: stop all */
    riscv_cpu_end(s->cpu_state);
    phys_mem_map_end(s->mem_map);
    free(s->phys_mem);
    free(s);
}

void copy_kernel(VirtMachine *s1, const uint8_t *buf, int buf_len)
{
    RISCVMachine *s = (RISCVMachine *)s1;
    uint8_t *ram_ptr;
    assert(buf_len < s->ram_size);
    ram_ptr = get_ram_ptr(s, RAM_BASE_ADDR);
    memcpy(ram_ptr, buf, buf_len);
}

/* in ms */
int virt_machine_get_sleep_duration(VirtMachine *s1, int delay)
{
    RISCVMachine *m = (RISCVMachine *)s1;
    RISCVCPUState *s = m->cpu_state;
    int64_t delay1;
    
    /* wait for an event: the only asynchronous event is the RTC timer */
    if (!(riscv_cpu_get_mip(s) & MIP_MTIP)) {
        delay1 = m->timecmp - rtc_get_time(m);
        if (delay1 <= 0) {
            riscv_cpu_set_mip(s, MIP_MTIP);
            delay = 0;
        } else {
            /* convert delay to ms */
            delay1 = delay1 / (RTC_FREQ / 1000);
            if (delay1 < delay)
                delay = delay1;
        }
    }
    if (!riscv_cpu_get_power_down(s))
        delay = 0;
    return delay;
}

void virt_machine_interp(VirtMachine *s1, int max_exec_cycle)
{
    RISCVMachine *s = (RISCVMachine *)s1;
    riscv_cpu_interp(s->cpu_state, max_exec_cycle);
}

#ifdef VERIFICATION
void  riscv_set_pc(RISCVCPUState *s, uint64_t pc);
uint64_t  riscv_get_pc(RISCVCPUState *s);
uint64_t  riscv_get_reg(RISCVCPUState *s, int rn);
void riscv_set_reg(RISCVCPUState *s, int rn, uint64_t val);
void riscv_dump_regs(RISCVCPUState *s);
int riscv_read_insn(RISCVCPUState *s, uintptr_t *pmem_addend, uint64_t addr);
int riscv_read_u64(RISCVCPUState *s, uint64_t *data, uint64_t addr);

void virt_machine_set_pc(VirtMachine *m, uint64_t pc)
{
  RISCVMachine *s = (RISCVMachine *)m;
  riscv_set_pc(s->cpu_state,pc);
}

void virt_machine_set_reg(VirtMachine *m, int rn, uint64_t val)
{
  RISCVMachine *s = (RISCVMachine *)m;
  riscv_set_reg(s->cpu_state,rn,val);
}

uint64_t  virt_machine_get_pc(VirtMachine *m)
{
  RISCVMachine *s = (RISCVMachine *)m;
  return riscv_get_pc(s->cpu_state);
}

uint64_t  virt_machine_get_reg(VirtMachine *m, int rn)
{
  RISCVMachine *s = (RISCVMachine *)m;
  return riscv_get_reg(s->cpu_state,rn);
}

void virt_machine_dump_regs(VirtMachine *m)
{
  RISCVMachine *s = (RISCVMachine *)m;
  riscv_dump_regs(s->cpu_state);
}

int virt_machine_read_insn(VirtMachine *m, uintptr_t *pmem_addend, uint64_t addr)
{
  RISCVMachine *s = (RISCVMachine *)m;
  return riscv_read_insn(s->cpu_state,pmem_addend,addr);
}

int virt_machine_read_u64(VirtMachine *m, uint64_t *data, uint64_t addr)
{
  RISCVMachine *s = (RISCVMachine *)m;
  return riscv_read_u64(s->cpu_state,data,addr);
}

#endif

