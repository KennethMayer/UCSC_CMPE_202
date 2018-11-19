all: run

division:
	verilator +incdir+rtl --Wall --cc --trace ./rtl/division_block.v --exe tests/division_block_tb.cpp -CFLAGS "-DTRACE=1 -DVL_DEBUG=1"
	make -C obj_dir/ -f Vdivision_block.mk Vdivision_block

run1: division
	./obj_dir/Vdivision_block

run: run1

clean:
	rm -rf obj_dir output.vcd a.out
