/* verilator lint_off UNUSED */
module fetch_block_icache(
    input clk,
    input  [64-1:0] inst_addr_i,
    input  [64-1:0] branch_addr_i,
    output [32-1:0] inst_o,
    output [32-1:0] branch_o);

  reg [32-1:0] inst_o, branch_o;
  reg [32-1:0] icache[4096-1:0] /*verilator public*/;

  always @(*) begin
    inst_o = icache[inst_addr_i[11:0]];
    branch_o = icache[branch_addr_i[11:0]];
  end
endmodule
/* verilator lint_off UNUSED */
