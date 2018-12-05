/* verilator lint_off UNUSED */
`include "rv64.vh"

module pyrm_decode_block(
  input clk,
  input  reset_pyri,

  input  [64-1:0] reg_addr_pyri,
  input           reg_addr_valid_pyri,
  output          reg_addr_retry_pyro,

  input  [64-1:0] reg_data_pyri,
  input           reg_data_valid_pyri,
  output          reg_data_retry_pyro,

  input  [32-1:0] inst_pyri,
  input           inst_valid_pyri,
  output          inst_retry_pyro,

  input  [64-1:0] pc_pyri,
  input           pc_valid_pyri,
  output          pc_retry_pyro,

  output [32-1:0] inst_pyro,
  output          inst_valid_pyro,
  input           inst_retry_pyri,

  output [64-1:0] pc_pyro,
  output          pc_valid_pyro,
  input           pc_retry_pyri,

  output [64-1:0] src1_pyro,
  output          src1_valid_pyro,
  input           src1_retry_pyri,

  output [64-1:0] src2_pyro,
  output          src2_valid_pyro,
  input           src2_retry_pyri
);

reg          reg_addr_retry_pyro, reg_data_retry_pyro, inst_retry_pyro, pc_retry_pyro;

reg [32-1:0] inst_pyro;
reg          inst_valid_pyro;

reg [64-1:0] pc_pyro;
reg          pc_valid_pyro;

reg [64-1:0] src1_pyro;
reg          src1_valid_pyro;

reg [64-1:0] src2_pyro;
reg          src2_valid_pyro;

reg  [32-1:0] raw_next;
wire [32-1:0] raw;

wire [5-1:0] rs1, rs2, rd;
wire [7-1:0] opcode;
wire         all_valid;

wire [64-1:0] rs1_arith_data, rs1_jalr_data, rs2_data;

wire [11:0] inst_imm;
wire [19:0] inst_imm_u;

wire [64-1:0] reg_addr_in;
wire [64-1:0] reg_data_in;

wire retry;

assign opcode = inst_pyri[6:0];

assign rd  = inst_pyri[11:7];
assign rs1 = inst_pyri[19:15];
assign rs2 = inst_pyri[24:20];

assign all_valid = inst_valid_pyri && pc_valid_pyri; // fetch block inputs, may not need inputs from writeback block to be valid
assign retry = inst_retry_pyri || pc_retry_pyri || src1_retry_pyri || src2_retry_pyri;

assign inst_imm = inst_pyri[31:20];
assign inst_imm_u = inst_pyri[31:12];

assign reg_addr_in = reg_addr_pyri & {64{reg_addr_valid_pyri}} & {64{reg_data_valid_pyri}};
assign reg_data_in = reg_data_pyri & {64{reg_addr_valid_pyri}} & {64{reg_data_valid_pyri}} & {64{reg_addr_pyri[4:0] != 5'b0}};

always @(*) begin
  raw_next = raw;
  reg_data_retry_pyro = 1'b0;
  reg_addr_retry_pyro = 1'b0;
  raw_next[0] = 1'b0;
  inst_retry_pyro = 1'b1;
  pc_retry_pyro = 1'b1;

  inst_pyro = 32'b0;
  inst_valid_pyro = 1'b0;

  pc_pyro = 64'b0;
  pc_valid_pyro = 1'b0;

  src1_pyro = 64'b0;
  src1_valid_pyro = 1'b0;

  src2_pyro = 64'b0;
  src2_valid_pyro = 1'b0;
  if(reg_addr_valid_pyri && reg_data_valid_pyri) begin
    if(reg_addr_pyri[4:0] != 5'b0)
      raw_next[reg_addr_pyri[4:0]] = 1'b0;
  end
  if(all_valid && !retry) begin
    if(opcode == `OP_ARITH || opcode == `OP_ARITH_W || opcode == `OP_BRANCH || opcode == `OP_STORE) begin
      //$display("arith or something");
      if(!(raw[rs1] || raw[rs2]) && !(opcode == `OP_BRANCH && raw[rd])) begin
        inst_pyro = inst_pyri;
        inst_valid_pyro = 1'b1;
        inst_retry_pyro = 1'b0;

        pc_pyro = pc_pyri;
        pc_valid_pyro = 1'b1;
        pc_retry_pyro = 1'b0;

        if(reg_addr_valid_pyri && rs1 != 5'b0 && reg_addr_pyri[4:0] == rs1) begin
          src1_pyro = reg_data_pyri;
          src1_valid_pyro = reg_data_valid_pyri;
        end else begin
          src1_pyro = rs1_arith_data;
          src1_valid_pyro = 1'b1;
        end

        if(reg_addr_valid_pyri && rs2 != 5'b0 && reg_addr_pyri[4:0] == rs2) begin
          src2_pyro = reg_data_pyri;
          src2_valid_pyro = reg_data_valid_pyri;
        end else begin
          src2_pyro = rs2_data;
          src2_valid_pyro = 1'b1;
        end
        if(opcode == `OP_ARITH || opcode == `OP_ARITH_W)
          raw_next[rd] = 1'b1;
      end
    end else if(opcode == `OP_ARITHI || opcode == `OP_ARITHI_W || opcode == `OP_LOAD) begin
      if(!(raw[rs1] || raw[rd])) begin
        inst_pyro = inst_pyri;
        inst_valid_pyro = 1'b1;
        inst_retry_pyro = 1'b0;

        pc_pyro = pc_pyri;
        pc_valid_pyro = 1'b1;
        pc_retry_pyro = 1'b0;

        if(reg_addr_valid_pyri && rs1 != 5'b0 && reg_addr_pyri[4:0] == rs1) begin
          src1_pyro = reg_data_pyri;
          src1_valid_pyro = reg_data_valid_pyri;
        end else begin
          src1_pyro = rs1_arith_data;
          src1_valid_pyro = 1'b1;
        end

        src2_pyro = {{52{inst_imm[11]}}, inst_imm};
        src2_valid_pyro = 1'b1;

        raw_next[rd] = 1'b1;
      end
    end else if(opcode == `OP_JALR) begin
      if(!(raw[rs1] == 1'b1 || raw[rd] == 1'b1)) begin
        inst_pyro = inst_pyri;
        inst_valid_pyro = 1'b1;
        inst_retry_pyro = 1'b0;

        pc_pyro = pc_pyri;
        pc_valid_pyro = 1'b1;
        pc_retry_pyro = 1'b0;
       
        raw_next[rd] = 1'b1;

        if(reg_addr_valid_pyri && rs1 != 5'b0 && reg_addr_pyri[4:0] == rs1) begin
          src1_pyro = reg_data_pyri;
          src1_valid_pyro = reg_data_valid_pyri;
        end else begin
          src1_pyro = rs1_jalr_data;
          src1_valid_pyro = 1'b1;
        end
      end
    end else if(opcode == `OP_JAL) begin
      if(!raw[rd]) begin
        inst_pyro = inst_pyri;
        inst_valid_pyro = 1'b1;
        inst_retry_pyro = 1'b0;

        pc_pyro = pc_pyri;
        pc_valid_pyro = 1'b1;
        pc_retry_pyro = 1'b0;
      end
    end else if(opcode == `OP_LUI || opcode == `OP_AUIPC) begin
      //$display("lui or auipc");
      if(!raw[rd]) begin
        inst_pyro = inst_pyri;
        inst_valid_pyro = 1'b1;
        inst_retry_pyro = 1'b0;

        pc_pyro = pc_pyri;
        pc_valid_pyro = 1'b1;
        pc_retry_pyro = 1'b0;
        src1_pyro = {{44{inst_imm_u[19]}}, inst_imm_u};
        src1_valid_pyro = 1'b1;
        raw_next[rd] = 1'b1;
      end
    end
  end
end

decode_block_data decode_block_data_inst
(.clk            (clk),
 .reg_addr       (reg_addr_in),
 .rs1_arith_addr (rs1),
 .rs1_jalr_addr  (rs1),
 .rs2_addr       (rs2),
 .data_in        (reg_data_in),
 .rs1_arith_data (rs1_arith_data),
 .rs1_jalr_data  (rs1_jalr_data),
 .rs2_data       (rs2_data)
);

flop
#(.Bits(32)) raw_flop
(.clk (clk),
 .reset(reset_pyri),
 .load(1'b0),
 .load_val(32'b0),
 .d(raw_next),
 .q(raw)
);

endmodule
/* verilator lint_off UNUSED */
