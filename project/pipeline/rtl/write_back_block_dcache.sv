/* verilator lint_off UNUSED */
module write_back_block_dcache(
    input clk,
    input [64-1:0] cache_addr_1,
    input [64-1:0] cache_addr_2,
    input [64-1:0] cache_addr_3,
    input [64-1:0] cache_addr_4,
    //input [64-1:0] cache_addr_5,
    input [64-1:0] cache_addr_low,
    input [64-1:0] cache_addr_high,
    input [64-1:0] cache_data_in_high,
    input [64-1:0] cache_data_in_low,
    output [64-1:0] cache_data_out_1,
    output [64-1:0] cache_data_out_2,
    output [64-1:0] cache_data_out_3,
    output [64-1:0] cache_data_out_4
    /*output [64-1:0] cache_data_out_5,
    output [64-1:0] cache_data_out_6,
    output [64-1:0] cache_data_out_7*/
);

  logic [64-1:0] dcache[2048-1:0] /*verilator public*/;

  always @(posedge clk) begin
     dcache[cache_addr_high[10:0]] <= cache_data_in_high;
     dcache[cache_addr_low[10:0]] <= cache_data_in_low;
  end

  assign cache_data_out_1 = dcache[cache_addr_1[10:0]];
  assign cache_data_out_2 = dcache[cache_addr_2[10:0]];
  assign cache_data_out_3 = dcache[cache_addr_3[10:0]];
  assign cache_data_out_4 = dcache[cache_addr_4[10:0]];
  /*assign cache_data_out_5 = dcache[cache_addr_5[10:0]];
  assign cache_data_out_6 = dcache[cache_addr_low[10:0]];
  assign cache_data_out_7 = dcache[cache_addr_high[10:0]];*/
endmodule
/* verilator lint_off UNUSED */
