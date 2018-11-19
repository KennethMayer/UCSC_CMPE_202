/* verilator lint_off UNUSED */
`include "rv64.vh"

module pyrm_fetch_block(
  input           clk,
  input           reset_pyri,

  input  [64-1:0] branch_pc_pyri,
  input           branch_pc_valid_pyri,
  output          branch_pc_retry_pyro,

  output [64-1:0] pc_pyro,
  output          pc_valid_pyro,
  input           pc_retry_pyri,

  output [32-1:0] inst_pyro,
  output          inst_valid_pyro,
  input           inst_retry_pyri
);

wire [64-1:0] pc_int;
reg  [64-1:0] pc_int_next;

wire          state_int;
reg           state_int_next;

wire [32-1:0] inst_int;
wire [32-1:0] inst_int_branch;

reg branch_pc_retry_pyro;

reg [64-1:0] pc_pyro;
reg          pc_valid_pyro;

reg [32-1:0] inst_pyro;
reg          inst_valid_pyro;

reg send_inst;

wire retry;

reg [6:0] opcode;
wire [20:0] imm_jal, imm_jal_branch;

assign imm_jal = {inst_int[31], inst_int[19:12], inst_int[20], inst_int[30:21], 1'b0};
assign imm_jal_branch = {inst_int_branch[31], inst_int_branch[19:12], inst_int_branch[20], inst_int_branch[30:21], 1'b0};

assign retry = inst_retry_pyri || pc_retry_pyri;

always @(*) begin
  pc_int_next = pc_int;
  state_int_next = state_int;

  pc_pyro = 64'b0;
  pc_valid_pyro = 1'b0;

  inst_pyro = 32'b0;
  inst_valid_pyro = 1'b0;

  if(!retry) begin
    send_inst = 1'b1;
    if(state_int == `STATE_BRANCH) begin
      if(branch_pc_valid_pyri) begin
        branch_pc_retry_pyro = 1'b0;
      end else begin
        branch_pc_retry_pyro = 1'b1;
        send_inst = 1'b0;
      end
    end
    if(send_inst == 1'b1) begin
      if(state_int == `STATE_RUNNING) begin
        pc_pyro = pc_int;
        inst_pyro = inst_int;
        opcode = inst_int[6:0];
        pc_int_next = pc_int + 64'd4;
      end else begin
        pc_pyro = branch_pc_pyri;
        inst_pyro = inst_int_branch;
        opcode = inst_int_branch[6:0];
        pc_int_next = branch_pc_pyri + 64'd4;
      end
      pc_valid_pyro = 1'b1;
      inst_valid_pyro = 1'b1;
      if(opcode == `OP_BRANCH || opcode == `OP_JALR) begin
        state_int_next = `STATE_BRANCH;
      end else if(opcode == `OP_JAL) begin
        if(state_int == `STATE_RUNNING) begin
          pc_int_next = $signed(pc_int) + $signed({{43{imm_jal[20]}}, imm_jal});
        end else begin
          pc_int_next = $signed(branch_pc_pyri) + $signed({{43{imm_jal_branch[20]}}, imm_jal_branch});
        end
        state_int_next = `STATE_RUNNING;
      end else
        state_int_next = `STATE_RUNNING;
    end
  end else begin
    if(state_int == `STATE_BRANCH)
      branch_pc_retry_pyro = `RETRY;
  end
end
    
fetch_block_icache fetch_block_icache_inst
(.clk           (clk),
 .inst_addr_i   ((pc_int & 64'hffff) >> 2),
 .branch_addr_i ((branch_pc_pyri & 64'hffff) >> 2),
 .inst_o        (inst_int),
 .branch_o      (inst_int_branch)
);

flop
#(.Bits(64)) pc_int_flop
(.clk      (clk),
 .reset    (1'b0),
 .load     (reset_pyri),
 .load_val (64'h80000000),
 .d        (pc_int_next),
 .q        (pc_int)
);

flop
#(.Bits(1)) state_int_flop
(.clk      (clk),
 .reset    (1'b0),
 .load     (reset_pyri),
 .load_val (`STATE_RUNNING),
 .d        (state_int_next),
 .q        (state_int)
);


endmodule
/* verilator lint_off UNUSED */
