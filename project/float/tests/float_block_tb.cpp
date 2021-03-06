#include "Vfloat_block.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <math.h>
#include <iostream>
#include <bitset>

#define MAX_TIME 10000

vluint64_t global_time   = 0;
int       terminate_set  = -1;
VerilatedVcdC     *tfp   = 0;

int errorCheck = 0;

int float_to_bin(float input);
float bin_to_float(int input);
char* int_to_bit_string(int input);
float rand_float(int range);

void eval_feq(Vfloat_block* top);
void eval_flt(Vfloat_block* top);
void eval_fle(Vfloat_block* top);
void eval_fmin(Vfloat_block* top);
void eval_fmax(Vfloat_block* top);
void eval_fadd(Vfloat_block* top);
void eval_fsgnj(Vfloat_block* top);

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

void advance_half_clock(Vfloat_block *top) {

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
    printf("Tested %d cycles. Error = %d.\n", MAX_TIME, errorCheck);
    do_terminate();
  }
}

void advance_clock(Vfloat_block *top, int nclocks=1) {

  for( int i=0;i<nclocks;i++) {
    for (int clk=0; clk<2; clk++) {
      advance_half_clock(top);
    }
  }
}

int main(int argc, char **argv, char **env) {

  Verilated::commandArgs(argc, argv);
  // init top verilog instance
  Vfloat_block* top = new Vfloat_block;

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
  top->start_i = 1;
  top->clk = rand() & 1;
  top->reset_i = 1;
  
  // reset the flops
  advance_clock(top,1);
  top->reset_i = 0;

  /*int float_convert = float_to_bin(19.1);
  printf("Input float: %f, output int: %d\n", 19.1, float_convert);
  float int_convert = bin_to_float(float_convert);
  printf("Input int: %d, output float: %f\n", float_convert, int_convert);*/
  //eval_fmin(top);
  while(1){
    eval_feq(top);
    eval_flt(top);
    eval_fle(top);
    eval_fmin(top);
    eval_fmax(top);
    eval_fadd(top);
    eval_fsgnj(top);
    }
  
  do_terminate();
}

float rand_float(int range){
  float r = ((float)rand()/RAND_MAX) * range;
  return r;
}

/* credit :https://stackoverflow.com/questions/474007/floating-point-to-binary-valuec*/
int float_to_bin(float input){
  union
  {
    float input;   // assumes sizeof(float) == sizeof(int)
    int   output;
  }    data;
  
  data.input = input;
  
  std::bitset<sizeof(float)>   bits(data.output);
  return data.output;
}

char* int_to_bit_string(int input){
  char *output = (char *)malloc(33*sizeof(char));
  for(int i = 31; i>-1; i--){
    if(input & 1 << i){
      output[31-i] = '1';
    }
    else{
      output[31-i] = '0';
    }
  }
  output[32] = '\0';
  return output;
}

/* adapted from https://stackoverflow.com/questions/30521214/converting-a-string-holding-binary-to-float/30521327 */
float bin_to_float(int input){
  char* temp = int_to_bit_string(input);
  
  int n = 0;
  for(int i = 31; i > -1;--i)
    {
      n |= (temp[31-i] - 48) << i;
    }
  float f = *(float *)&n;
  
  free(temp);
  
  return f;
}

void eval_feq(Vfloat_block* top){
  float float1, float2;
  /* First, a case where they are equal */
  top->start_i = 1;
  float1 = float2 = 19.1;
  top->float1_i = float_to_bin(float1);
  top->float2_i = float_to_bin(float2);
  top->opcode_i = 19;
  
  advance_clock(top,1);
  
  if(top->int_o){
    printf("FEQ:   SUCCESS! Expected 1, got 1; float1 = %f, float2 = %f\n", float1, float2);
  }
  else{
    printf("FEQ:   FAILURE! Expected 1, got 0; float1 = %f, float2 = %f\n", float1, float2);
    errorCheck = 1;
  }
  
  advance_clock(top,1);
  
  float1 = rand_float(100);
  float2 = rand_float(100);

  int special = rand() % 10;
  switch(special){
  case 0:
    float1 = INFINITY;
    break;
  case 1:
    float1 = -INFINITY;
    break;
  case 2:
    float1 = SNAN;
    break;
  default:
    break;
  }

  special = rand() % 10;
  switch(special){
  case 3:
    float2 = INFINITY;
    break;
  case 4:
    float2 = -INFINITY;
    break;
  case 5:
    float2 = SNAN;
    break;
  default:
    break;
  }
  
  top->start_i = 1;
  top->float1_i = float_to_bin(float1);
  top->float2_i = float_to_bin(float2);
  
  advance_clock(top,1);
  
  if(float1 == float2){
    if(top->int_o){
      printf("FEQ:   SUCCESS! Expected 1, got 1; float1 = %f, float2 = %f\n", float1, float2);
    }
    else{
      printf("FEQ:   FAILURE! Expected 1, got 0; float1 = %f, float2 = %f\n", float1, float2);
      errorCheck = 1;
    }
  }
  else{
    if(top->int_o){
      printf("FEQ:   FAILURE! Expected 0, got 1; float1 = %f, float2 = %f\n", float1, float2);
      errorCheck = 1;
    }
    else{
      printf("FEQ:   SUCCESS! Expected 0, got 0; float1 = %f, float2 = %f\n", float1, float2);
    }    
  }
  advance_clock(top,1);
}

void eval_flt(Vfloat_block* top){
  float float1, float2;
  /* First, a case where they are equal */
  top->start_i = 1;
  float1 = float2 = 19.1;
  top->float1_i = float_to_bin(float1);
  top->float2_i = float_to_bin(float2);
  top->opcode_i = 20;

  advance_clock(top,1);

  if(top->int_o){
    printf("FLT:   FAILURE! Expected 0, got 1; float1 = %f, float2 = %f\n", float1, float2);
    errorCheck = 1;
  }
  else{
    printf("FLT:   SUCCESS! Expected 0, got 0; float1 = %f, float2 = %f\n", float1, float2);
  }
  
  advance_clock(top,1);
  
  float1 = rand_float(100);
  float2 = rand_float(100);

  int special = rand() % 10;
  switch(special){
  case 0:
    float1 = INFINITY;
    break;
  case 1:
    float1 = -INFINITY;
    break;
  case 2:
    float1 = SNAN;
    break;
  default:
    break;
  }

  special = rand() % 10;
  switch(special){
  case 3:
    float2 = INFINITY;
    break;
  case 4:
    float2 = -INFINITY;
    break;
  case 5:
    float2 = SNAN;
    break;
  default:
    break;
  }
  
  top->start_i = 1;
  top->float1_i = float_to_bin(float1);
  top->float2_i = float_to_bin(float2);
  advance_clock(top,1);
  
  if(float1 < float2){
    if(top->int_o){
      printf("FLT:   SUCCESS! Expected 1, got 1; float1 = %f, float2 = %f\n", float1, float2);
    }
    else{
      printf("FLT:   FAILURE! Expected 1, got 0; float1 = %f, float2 = %f\n", float1, float2);
      errorCheck = 1;
    }
  }
  else{
    if(top->int_o){
      printf("FLT:   FAILURE! Expected 0, got 1; float1 = %f, float2 = %f\n", float1, float2);
      errorCheck = 1;
    }
    else{
      printf("FLT:   SUCCESS! Expected 0, got 0; float1 = %f, float2 = %f\n", float1, float2);
    }
  }
  advance_clock(top,1);
}

void eval_fle(Vfloat_block* top){
  float float1, float2;
  /* First, a case where they are equal */
  float1 = float2 = 19.1;
  top->start_i = 1;
  top->float1_i =  float_to_bin(float1);
  top->float2_i =  float_to_bin(float2);
  top->opcode_i = 21;
  advance_clock(top,1);

  if(top->int_o){
    printf("FLE:   SUCCESS! Expected 1, got 1; float1 = %f, float2 = %f\n", float1, float2);
  }
  else{
    printf("FLE:   FAILURE! Expected 1, got 0; float1 = %f, float2 = %f\n", float1, float2);
    errorCheck = 1;
  }
  
  advance_clock(top,1);
  
  float1 = rand_float(100);
  float2 = rand_float(100);

  int special = rand() % 10;
  switch(special){
  case 0:
    float1 = INFINITY;
    break;
  case 1:
    float1 = -INFINITY;
    break;
  case 2:
    float1 = SNAN;
    break;
  default:
    break;
  }

  special = rand() % 10;
  switch(special){
  case 3:
    float2 = INFINITY;
    break;
  case 4:
    float2 = -INFINITY;
    break;
  case 5:
    float2 = SNAN;
    break;
  default:
    break;
  }
  
  top->start_i = 1;
  top->float1_i = float_to_bin(float1);
  top->float2_i = float_to_bin(float2);
  advance_clock(top,1);

  if(float1 <= float2){
    if(top->int_o){
      printf("FLE:   SUCCESS! Expected 1, got 1; float1 = %f, float2 = %f\n", float1, float2);
    }
    else{
      printf("FLE:   FAILURE! Expected 1, got 0; float1 = %f, float2 = %f\n", float1, float2);
      errorCheck = 1;
    }
  }
  else{
    if(top->int_o){
      printf("FLE:   FAILURE! Expected 0, got 1; float1 = %f, float2 = %f\n", float1, float2);
      errorCheck = 1;
    }
    else{
      printf("FLE:   SUCCESS! Expected 0, got 0; float1 = %f, float2 = %f\n", float1, float2);
    }
  }
  advance_clock(top,1);
}

void eval_fmin(Vfloat_block* top){
  float float1, float2;
  /* First, a case where they are equal */
  float1 = INFINITY;
  float2 = -INFINITY;
  top->start_i = 1;
  top->float1_i = float_to_bin(float1);
  top->float2_i = float_to_bin(float2);
  top->opcode_i = 14;
  advance_clock(top,1);

  if(top->float_low_o == float_to_bin(float2)){
    printf("FMIN:  SUCCESS! Expected %f, got %f; float1 = %f, float2 = %f\n", float2, bin_to_float(top->float_low_o), float1, float2);
  }
  else{
    printf("FMIN:  FAILURE! Expected %f, got %f; float1 = %f, float2 = %f\n", float1, bin_to_float(top->float_low_o), float1, float2);
    errorCheck = 1;
  }
  
  advance_clock(top,1);
  
  float1 = rand_float(100);
  float2 = rand_float(100);

  int special = rand() % 10;
  switch(special){
  case 0:
    float1 = INFINITY;
    break;
  case 1:
    float1 = -INFINITY;
    break;
  case 2:
    float1 = SNAN;
    break;
  default:
    break;
  }

  special = rand() % 10;
  switch(special){
  case 3:
    float2 = INFINITY;
    break;
  case 4:
    float2 = -INFINITY;
    break;
  case 5:
    float2 = SNAN;
    break;
  default:
    break;
  }
  
  top->start_i = 1;
  top->float1_i = float_to_bin(float1);
  top->float2_i = float_to_bin(float2);
  advance_clock(top,1);

  if(isnan(float1) || isnan(float2) && !(isnan(float1) && isnan(float2))){
    if(isnan(float1)){
      if(top->float_low_o == float_to_bin(float2)){
	printf("FMIN:  SUCCESS! Expected %f, got %f; float1 = %f, float2 = %f\n", float2, bin_to_float(top->float_low_o), float1, float2);
      }
      else{
	printf("FMIN:  FAILURE! Expected %f, got %f; float1 = %f, float2 = %f\n", float2, bin_to_float(top->float_low_o), float1, float2);
	errorCheck = 1;
      }
    }
    else{
      if(top->float_low_o == float_to_bin(float1)){
	printf("FMIN:  SUCCESS! Expected %f, got %f; float1 = %f, float2 = %f\n", float1, bin_to_float(top->float_low_o), float1, float2);
      }
      else{
	printf("FMIN:  FAILURE! Expected %f, got %f; float1 = %f, float2 = %f\n", float1, bin_to_float(top->float_low_o), float1, float2);
	errorCheck = 1;
      }
    }
  }
  else if(float1 <= float2){
    if(top->float_low_o == float_to_bin(float1)){
      printf("FMIN:  SUCCESS! Expected %f, got %f; float1 = %f, float2 = %f\n", float1, bin_to_float(top->float_low_o), float1, float2);
    }
    else{
      printf("FMIN:  FAILURE! Expected %f, got %f; float1 = %f, float2 = %f\n", float1, bin_to_float(top->float_low_o), float1, float2);
      errorCheck = 1;
    }
  }
  else{
    if(top->float_low_o == float_to_bin(float2)){
      printf("FMIN:  SUCCESS! Expected %f, got %f; float1 = %f, float2 = %f\n", float2, bin_to_float(top->float_low_o), float1, float2);
    }
    else{
      printf("FMIN:  FAILURE! Expected %f, got %f; float1 = %f, float2 = %f\n", float2, bin_to_float(top->float_low_o), float1, float2);
      errorCheck = 1;
    }
  }
  advance_clock(top,1);
}

void eval_fmax(Vfloat_block* top){
  float float1, float2;
  /* First, a case where they are equal */
  float1 = float2 = 19.1;
  top->start_i = 1;
  top->float1_i = float_to_bin(float1);
  top->float2_i = float_to_bin(float2);
  top->opcode_i = 15;
  advance_clock(top,1);

  if(top->float_low_o == float_to_bin(float1)){
    printf("FMAX:  SUCCESS! Expected %f, got %f; float1 = %f, float2 = %f\n", float1, bin_to_float(top->float_low_o), float1, float2);
  }
  else{
    printf("FMAX:  FAILURE! Expected %f, got %f; float1 = %f, float2 = %f\n", float1, bin_to_float(top->float_low_o), float1, float2);
    errorCheck = 1;
  }
  
  advance_clock(top,1);
  
  float1 = rand_float(100);
  float2 = rand_float(100);

  int special = rand() % 10;
  switch(special){
  case 0:
    float1 = INFINITY;
    break;
  case 1:
    float1 = -INFINITY;
    break;
  case 2:
    float1 = SNAN;
    break;
  default:
    break;
  }

  special = rand() % 10;
  switch(special){
  case 3:
    float2 = INFINITY;
    break;
  case 4:
    float2 = -INFINITY;
    break;
  case 5:
    float2 = SNAN;
    break;
  default:
    break;
  }
  
  top->start_i = 1;
  top->float1_i = float_to_bin(float1);
  top->float2_i = float_to_bin(float2);
  advance_clock(top,1);
  if(isnan(float1) || isnan(float2) && !(isnan(float1) && isnan(float2))){
    if(isnan(float1)){
      if(top->float_low_o == float_to_bin(float2)){
	printf("FMAX:  SUCCESS! Expected %f, got %f; float1 = %f, float2 = %f\n", float2, bin_to_float(top->float_low_o), float1, float2);
      }
      else{
	printf("FMAX:  FAILURE! Expected %f, got %f; float1 = %f, float2 = %f\n", float2, bin_to_float(top->float_low_o), float1, float2);
	errorCheck = 1;
      }
    }
    else{
      if(top->float_low_o == float_to_bin(float1)){
	printf("FMAX:  SUCCESS! Expected %f, got %f; float1 = %f, float2 = %f\n", float1, bin_to_float(top->float_low_o), float1, float2);
      }
      else{
	printf("FMAX:  FAILURE! Expected %f, got %f; float1 = %f, float2 = %f\n", float1, bin_to_float(top->float_low_o), float1, float2);
	errorCheck = 1;
      }
    }
  }
  else if(float1 >= float2){
    if(top->float_low_o == float_to_bin(float1)){
      printf("FMAX:  SUCCESS! Expected %f, got %f; float1 = %f, float2 = %f\n", float1, bin_to_float(top->float_low_o), float1, float2);
    }
    else{
      printf("FMAX:  FAILURE! Expected %f, got %f; float1 = %f, float2 = %f\n", float1, bin_to_float(top->float_low_o), float1, float2);
      errorCheck = 1;
    }
  }
  else{
    if(top->float_low_o == float_to_bin(float2)){
      printf("FMAX:  SUCCESS! Expected %f, got %f; float1 = %f, float2 = %f\n", float2, bin_to_float(top->float_low_o), float1, float2);
    }
    else{
      printf("FMAX:  FAILURE! Expected %f, got %f; float1 = %f, float2 = %f\n", float2, bin_to_float(top->float_low_o), float1, float2);
      errorCheck = 1;
    }
  }
  advance_clock(top,1);
}

void eval_fadd(Vfloat_block* top){
  float float1, float2;

  float1 = 0.00000000001;
  float2 = -0.00000000001;
  top->start_i = 1;
  top->float1_i = float_to_bin(float1);
  top->float2_i = float_to_bin(float2);
  top->opcode_i = 6;
  advance_clock(top,1);
  // printf("Input bit string 1: %s\n                     SE      EM                     M\n", int_to_bit_string(float_to_bin(float1)));
  // printf("Input bit string 2: %s\n                     SE      EM                     M\n", int_to_bit_string(float_to_bin(float2)));

  if(top->float_low_o == float_to_bin(float1+float2) || (isnan(bin_to_float(top->float_low_o)) && isnan(float1+float2))){
    printf("FADD:  SUCCESS! Expected %f, got %f; float1 = %f, float2 = %f\n", float1+float2, bin_to_float(top->float_low_o), float1, float2);
  }
  else{
    printf("FADD:  FAILURE! Expected %f, got %f; float1 = %f, float2 = %f\n", float1+float2, bin_to_float(top->float_low_o), float1, float2);
    errorCheck = 1;
  }
  // printf("Result bit string:   %s\nExpected bit string: %s\n                     SE      EM                     M\n", int_to_bit_string(top->float_low_o), int_to_bit_string(float_to_bin(float1+float2)));
  
  advance_clock(top,1);
  
  float1 = rand_float(100);
  float2 = rand_float(100);

  if(rand() % 2){
    float1 = -float1;
  }
  if(rand() % 2){
    float2 = -float2;
  }
  
  int special = rand() % 10;
  switch(special){
  case 0:
    float1 = INFINITY;
    break;
  case 1:
    float1 = -INFINITY;
    break;
  case 2:
    float1 = SNAN;
    break;
  default:
    break;
  }

  special = rand() % 10;
  switch(special){
  case 3:
    float2 = INFINITY;
    break;
  case 4:
    float2 = -INFINITY;
    break;
  case 5:
    float2 = SNAN;
    break;
  default:
    break;
  }
  
  top->start_i = 1;
  top->float1_i = float_to_bin(float1);
  top->float2_i = float_to_bin(float2);
  top->opcode_i = 6;
  advance_clock(top,1);

  if(top->float_low_o == float_to_bin(float1+float2) || (isnan(bin_to_float(top->float_low_o)) && isnan(float1+float2))){
    printf("FADD:  SUCCESS! Expected %f, got %f; float1 = %f, float2 = %f\n", float1+float2, bin_to_float(top->float_low_o), float1, float2);
  }
  else{
      printf("FADD:  FAILURE! Expected %f, got %f; float1 = %f, float2 = %f\n", float1+float2, bin_to_float(top->float_low_o), float1, float2);
      errorCheck = 1;
  }
  // printf("Result bit string:   %s\nExpected bit string: %s\n                     SE      EM                     M\n", int_to_bit_string(top->float_low_o), int_to_bit_string(float_to_bin(float1+float2)));

  advance_clock(top,1);
}

void eval_fsgnj(Vfloat_block* top){
  float float1, float2;
  
  float1 = rand_float(100);
  float2 = rand_float(100);

  if(rand() % 2){
    float1 = -float1;
  }
  if(rand() % 2){
    float2 = -float2;
  }
  
  int special = rand() % 10;
  switch(special){
  case 0:
    float1 = INFINITY;
    break;
  case 1:
    float1 = -INFINITY;
    break;
  case 2:
    float1 = SNAN;
    break;
  default:
    break;
  }

  special = rand() % 10;
  switch(special){
  case 3:
    float2 = INFINITY;
    break;
  case 4:
    float2 = -INFINITY;
    break;
  case 5:
    float2 = SNAN;
    break;
  default:
    break;
  }
  
  top->start_i = 1;
  top->float1_i = float_to_bin(float1);
  top->float2_i = float_to_bin(float2);
  top->opcode_i = 11;
  advance_clock(top,1);

  float expected = 0.0;
  if(float2 < 0){
    if(float1 < 0){
      expected = float1;
    }
    else{
      expected = -float1;
    }
  }
  else{
    if(float1 < 0){
      expected = -float1;
    }
    else{
      expected = float1;
    }
  }
  // printf("fsgnj: expected value: %f\n", expected);
  
  if(top->float_low_o == float_to_bin(expected) || (isnan(expected) && isnan(bin_to_float(top->float_low_o)))){
    printf("FSGNJ: SUCCESS! Expected %f, got %f; float1 = %f, float2 = %f\n", expected, bin_to_float(top->float_low_o), float1, float2);
  }
  else{
    printf("FSGNJ: FAILURE! Expected %f, got %f; float1 = %f, float2 = %f\n", expected, bin_to_float(top->float_low_o), float1, float2);
    errorCheck = 1;
  }
  
  advance_clock(top,1);
}

