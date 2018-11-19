all: run

float:
	verilator +incdir+rtl --Wall --cc --trace ./rtl/float_block.v --exe tests/float_block_tb.cpp -CFLAGS "-DTRACE=1 -DVL_DEBUG=1"
	make -C obj_dir/ -f Vfloat_block.mk Vfloat_block

run1: float
	./obj_dir/Vfloat_block

run: run1

clean:
	rm -rf obj_dir output.vcd a.out
