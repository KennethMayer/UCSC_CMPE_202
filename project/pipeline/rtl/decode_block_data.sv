/* verilator lint_off UNUSED */
module decode_block_data(
    input           clk,
    input  [64-1:0] reg_addr, // for input
    input  [5-1:0]  rs1_arith_addr,
    input  [5-1:0]  rs1_jalr_addr,
    input  [5-1:0]  rs2_addr,
    input  [64-1:0] data_in,
    output [64-1:0] rs1_arith_data,
    output [64-1:0] rs1_jalr_data,
    output [64-1:0] rs2_data
);

  reg [64-1:0] data[32-1:0];

  always @(posedge clk) begin
     data[reg_addr[4:0]] <= data_in;
  end

  assign rs1_arith_data = data[rs1_arith_addr[4:0]];
  assign rs1_jalr_data  = data[rs1_jalr_addr[4:0]];
  assign rs2_data       = data[rs2_addr[4:0]];
endmodule
/* verilator lint_off UNUSED */
