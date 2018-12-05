#include "Pyrope.h"
using Pyrope::Pipe;

#include "riscv_verify.h"
#include <list>
using RISCV_Verify::inst_t;
using RISCV_Verify::word_t;
using RISCV_Verify::inst_debug_text;
using RISCV_Verify::Emulator;
using std::list;

#ifndef MAX_CYCLES
#define MAX_CYCLES            10000000
#endif

#ifndef MAX_BENCHMARK_CYCLES
#define MAX_BENCHMARK_CYCLES  10000000
#endif

#define MAX_STALL_CYCLES      10
#define BATCH_SIZE            20

#ifndef DEFAULT_BIN
#define DEFAULT_BIN           "../../../cpplibs/riscv_verify/lib/dhry.bin"
#endif

#define VALID_NOT_RETRY(p)    (p.get_valid() && !p.get_retry())

#define ECHO_INSTS

void verify(Pipe *pipe, Emulator *);
void benchmark(Pipe *pipe);

void clock_and_verify(Emulator *e, Pipe *pipe);
bool verify_cycle(Emulator *e, Pipe *pipe);
void initialize_caches(Emulator *, Pipe *);
bool compare_memory(Emulator *, Pipe *);
void dump(Pipe *);

void dump_list(const list<word_t> &);

unsigned long inst_ctr = 0;

PYROPE_TESTBENCH_MAIN(Pipe *pipe)
{
  Emulator emulator((argc == 2) ? argv[1] : DEFAULT_BIN);
  printf("\n\n");

  initialize_caches(&emulator, pipe);

#ifdef PYR_BENCHMARK
    benchmark(pipe);
#else
    verify(pipe, &emulator);
#endif
}

void benchmark(Pipe *pipe)
{
  clock_t start = clock();

#ifdef PYR_COLLAPSED
  pipe->toggle_clock(MAX_BENCHMARK_CYCLES);
#else
  for (int i = 0; i < MAX_BENCHMARK_CYCLES; i++)
    pipe->toggle_clock();
#endif

  clock_t end = clock();

  double secs = ((double) (end - start)) / CLOCKS_PER_SEC;
  double mhz = ((double) pipe->cycle_count()) / secs / 1000 / 1000;
  printf("\n\t\tRan for %ld cycles, over %f seconds at: %f MHz\n",
      pipe->cycle_count(), secs, mhz);
}

void verify(Pipe *pipe, Emulator *emulator)
{
  while (pipe->cycle_count() < MAX_CYCLES)
    clock_and_verify(emulator, pipe);

  printf("\n\n\t\t...max cycles reached.\n");
  dump(pipe);
}

void clock_and_verify(Emulator *emulator, Pipe *pipe)
{
  if (!verify_cycle(emulator, pipe))
    dump(pipe);
}

bool verify_cycle(Emulator *emulator, Pipe *pipe)
{
  static word_t last_pc = 0;

  pipe->toggle_clock();

  if (pipe->output("debug_committed_pc").get_valid() &&
      !pipe->output("debug_committed_pc").get_retry()) {
    inst_ctr++;
    word_t last_committed_pc = pipe->output("debug_committed_pc").read_u64();

    if (last_pc == last_committed_pc && pipe->cycle_count() > 10) {
      printf("TB jumped to same PC: %016lX\n", last_pc);
      dump(pipe);
    }

    last_pc = last_committed_pc;
    word_t emu_pc = emulator->get_pc();

    if (last_pc != emu_pc) {
      printf("PC mismatch.  UUT: %016lX\n"
             "              EMU: %016lX\n", last_pc, emu_pc);
      return false;
    }

    emulator->run_inst();
    
    if (pipe->output("debug_reg_addr").get_valid() &&
        pipe->output("debug_reg_data").get_valid()) {
      
      word_t raddr = pipe->output("debug_reg_addr").read_u64();
      word_t rdata = pipe->output("debug_reg_data").read_u64();

      if (raddr != 0) {
        word_t emu_rdata = emulator->get_reg(raddr);
        if (emu_rdata != rdata) {
          printf("Regfile mismatch for reg[%s]\n"
                 "                  UUT: %016lX\n"
                 "                  EMU: %016lX\n",
                 emulator->reg_name(raddr), rdata, emu_rdata);
          return false;
        }
      }
    }

#ifdef PYR_VERBOSE
    inst_t inst = emulator->get_inst(last_pc);
    printf("\t(pc=%016lX) %s\n", last_pc, inst_debug_text(inst).c_str());
#endif
  }

  return true;
}

void dump(Pipe *pipe)
{
  printf("\n\n...exiting.\n\n");
  printf("SUCCESS\n");
  printf("\t\tRan %ld instructions, %ld cycles, CPI: %f\n",
      inst_ctr, pipe->cycle_count(),
      ((double) pipe->cycle_count()) / inst_ctr);
}

void initialize_caches(Emulator *emu, Pipe *pipe)
{
  int ic_index = 0;
  int dc_index = 0;

  while (ic_index < 0x4000 && dc_index < 0x4000) {
    word_t addr = ic_index | 0x80000000U;
#ifdef PYR_VERILOG
    auto veri = pipe->verilator_ptr();

#if defined(PYR_COLLAPSED) || defined(PYR_FETDECANDEX)
    veri->pipe->pyrm_exec2_inst->exec2_icache_inst->icache[ic_index >> 2] = emu->get_inst(addr);
#else
    veri->pipe->pyrm_fetch_inst->fetch_icache_inst->icache[ic_index >> 2] = emu->get_inst(addr);
#endif
#else

    inst_t inst = emu->get_inst(addr);

#if defined(PYR_COLLAPSED) || defined(PYR_FETDECANDEX)
    pipe->get_stage("exec2")->write_register("icache", (char *) &inst, sizeof(inst_t), ic_index >> 2, sizeof(inst_t));
#else
    pipe->get_stage("fetch")->write_register("icache", (char *) &inst, sizeof(inst_t), ic_index >> 2, sizeof(inst_t));
#endif
#endif
    
    ic_index += 4;

    addr = ic_index | 0x80000000U;

#ifdef PYR_VERILOG
#if defined(PYR_COLLAPSED) || defined(PYR_FETDECANDEX)
    veri->pipe->pyrm_exec2_inst->exec2_icache_inst->icache[ic_index >> 2] = emu->get_inst(addr);
#else
    veri->pipe->pyrm_fetch_inst->fetch_icache_inst->icache[ic_index >> 2] = emu->get_inst(addr);
#endif

#else

    inst = emu->get_inst(addr);

#if defined(PYR_COLLAPSED) || defined(PYR_FETDECANDEX)
    pipe->get_stage("exec2")->write_register("icache", (char *) &inst, sizeof(inst_t), ic_index >> 2, sizeof(inst_t));
#else
    pipe->get_stage("fetch")->write_register("icache", (char *) &inst, sizeof(inst_t), ic_index >> 2, sizeof(inst_t));
#endif
#endif

    ic_index += 4;

    addr = dc_index | 0x80000000U;
#ifdef PYR_VERILOG
#if defined(PYR_EXANDWB) || defined(PYR_SUPER_EX) || defined(PYR_COLLAPSED) || defined(PYR_DECEXANDWB)
    veri->pipe->pyrm_exec2_inst->exec2_dcache_inst->dcache[dc_index >> 3] = emu->get_mem64(addr);
#else
    veri->pipe->pyrm_wb_inst->wb_dcache_inst->dcache[dc_index >> 3] = emu->get_mem64(addr);
#endif

#else

    auto mem = emu->get_mem64(addr);

#if defined(PYR_EXANDWB) || defined(PYR_SUPER_EX) || defined(PYR_COLLAPSED) || defined(PYR_DECEXANDWB)
    pipe->get_stage("exec2")->write_register("dcache", (char *) &mem, sizeof(uint64_t), dc_index >> 3, sizeof(uint64_t));
#else
    pipe->get_stage("wb")->write_register("dcache", (char *) &mem, sizeof(uint64_t), dc_index >> 3, sizeof(uint64_t));
#endif

#endif

    dc_index += 8;
  }
  
  if (compare_memory(emu, pipe))
    printf("Caches loaded, initial memory check completed.\n");
  else {
    printf("Initial memory check failed...exiting.\n");
    exit(1);
  }

  pipe->set_reset(true);
  pipe->toggle_clock();
  pipe->toggle_clock();
  pipe->set_reset(false);

#ifdef PYR_VERILOG
  pipe->toggle_clock();
#endif
}

bool compare_memory(Emulator *emu, Pipe *pipe)
{
  int eaddr = 0;
  int paddr = 0;

  bool had_mismatch = false;

  while (eaddr < 0x4000 && paddr < 0x4000) {
    word_t full_addr = eaddr | 0x80000000U;
    word_t emem = emu->get_mem64(full_addr);
    eaddr += 8;

#ifdef PYR_VERILOG

#if defined(PYR_EXANDWB) || defined(PYR_SUPER_EX) || defined(PYR_COLLAPSED) || defined(PYR_DECEXANDWB)
    word_t pmem = pipe->verilator_ptr()->pipe->pyrm_exec2_inst->exec2_dcache_inst->dcache[paddr >> 3];
#else
    word_t pmem = pipe->verilator_ptr()->pipe->pyrm_wb_inst->wb_dcache_inst->dcache[paddr >> 3];
#endif

#else

#if defined(PYR_EXANDWB) || defined(PYR_SUPER_EX) || defined(PYR_COLLAPSED) || defined(PYR_DECEXANDWB)
    word_t pmem = *(word_t *) pipe->get_stage("exec2")->read_register("dcache", paddr >> 3, sizeof(uint64_t));
#else
    word_t pmem = *(word_t *) pipe->get_stage("wb")->read_register("dcache", paddr >> 3, sizeof(uint64_t));
#endif

#endif
    paddr += 8;

    if (emem != pmem) {
      printf("\t[%016lx] -> (emu: %016lx, uut: %016lx)\n", full_addr, emem, pmem);
      had_mismatch = true;
    }
  }

  return !had_mismatch;
}

void dump_list(const list<word_t> &lst)
{
  for (auto pc : lst)
    printf("%lX ", pc);

  printf("\n");
}
