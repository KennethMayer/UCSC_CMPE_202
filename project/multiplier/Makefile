all: run

multiplier:
	verilator +incdir+rtl --Wall --cc --trace ./rtl/multiplication_block.v --exe tests/multiplication_block_tb.cpp -CFLAGS "-DTRACE=1 -DVL_DEBUG=1"
	make -C obj_dir/ -f Vmultiplication_block.mk Vmultiplication_block

run1: multiplier
	./obj_dir/Vmultiplication_block

run: run1

clean:
	rm -rf obj_dir output.vcd a.out
