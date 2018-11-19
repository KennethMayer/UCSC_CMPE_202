all: Vpipe

LIB_DEPS=-lrt -lcurl -lcrypto


VERILOG_FILES=./rtl/pipe.sv
VERILATOR_ARGS=-O3 -I. -Irtl -Icpplibs/riscv_verify


CFLAGS=-DTRACE=1 -DVL_DEBUG=1 -std=c++11 -O3 $(USR_FLAGS) -DPYR_VERILOG -I. -I.. -L.
CFLAGS+=-I../cpplibs/riscv_verify $(LIB_DEPS)


CPP_FILES=test/main.cpp



LDFLAGS=-LDFLAGS "$(LIB_DEPS) -L."


Vpipe:
	verilator -I./rtl $(VERILATOR_ARGS) $(LIB_OBJS) --Wall --cc --trace $(VERILOG_FILES) --exe $(CPP_FILES) -CFLAGS "$(CFLAGS)" ../cpplibs/riscv_verify/libriscv_checker.a ../cpplibs/riscv_verify/riscvdis/disasm.o ../cpplibs/riscv_verify/riscvdis/regnames.o $(LDFLAGS)
	make -C obj_dir/ -f Vpipe.mk Vpipe

RISCV_Verify:
	make -C cpplibs/riscv_verify clean
	make -C cpplibs/riscv_verify

clean:
	rm -rf obj_dir output.vcd a.out

