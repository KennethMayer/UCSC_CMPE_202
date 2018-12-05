#include "Vmultiplication_block.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

#define MAX_TIME 2000

vluint64_t global_time   = 0;
int       terminate_set  = -1;
VerilatedVcdC     *tfp   = 0;

void do_terminate() {
#ifdef TRACE
      tfp->dump(global_time);
#endif
#ifdef TRACE
  tfp->close();
#endif

  printf("simulation finished at cycle %lld\n",(long long)global_time);

  exit(0);
}

void advance_half_clock(Vmultiplication_block *top) {

  top->eval();
#ifdef TRACE
  tfp->dump(global_time);
#endif

  top->clk = !top->clk;

  top->eval();
#ifdef TRACE
  tfp->dump(global_time);
#endif

  global_time++;
  if (terminate_set>0)
    terminate_set--;

  if (Verilated::gotFinish() || global_time >= MAX_TIME ){
    printf("Couldn't get the result within 2000 cycles.");
    do_terminate();
  }
}

void advance_clock(Vmultiplication_block *top, int nclocks=1) {

  for( int i=0;i<nclocks;i++) {
    for (int clk=0; clk<2; clk++) {
      advance_half_clock(top);
    }
  }
}

int main(int argc, char **argv, char **env) {

  Verilated::commandArgs(argc, argv);
  // init top verilog instance
  Vmultiplication_block* top = new Vmultiplication_block;

#ifdef TRACE
  // init trace dump
  Verilated::traceEverOn(true);
  tfp = new VerilatedVcdC;
  
  top->trace(tfp, 99);
  tfp->open("output.vcd");
#endif
  
  // initialize simulation inputs
  int sim_seed = time(0);
  srand(sim_seed);
  top->multiplier_i = -rand();
  top->multiplicand_i = rand();
  top->start_i = 1;
  top->clk = rand() & 1;
  top->reset_i = 1;
  
  // reset the flops
  advance_clock(top,1);
  top->reset_i = 0;

  while(true) {
    advance_clock(top,1);
    // start the evaluation
    if(top->start_i == 1){
      top->start_i = 0;
    }
    if(top->done_o == 1){
      break;
    }
  }
  if(top->product_low_o != top->multiplier_i * top->multiplicand_i){
    printf("Error: expected %ld, got %ld\n", top->multiplier_i * top->multiplicand_i, top->product_low_o);
  }
  else{
    printf("Success! expected %ld, got %ld\n", top->multiplier_i * top->multiplicand_i, top->product_low_o);
  }
  do_terminate();
}
 
