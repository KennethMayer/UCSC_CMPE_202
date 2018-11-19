/* verilator lint_off WIDTH */
/* verilator lint_off UNUSED */
`include "rv64.vh"

module pyrm_write_back_block(
  input           reset_pyri,
  input           clk,

  input  [64-1:0] pc_pyri,
  input           pc_valid_pyri,
  output          pc_retry_pyro,

  input  [64-1:0] branch_pc_pyri,
  input           branch_pc_valid_pyri,
  output          branch_pc_retry_pyro,

  input  [64-1:0] raddr_pyri,
  input           raddr_valid_pyri,
  output          raddr_retry_pyro,

  input  [64-1:0] rdata_pyri,
  input           rdata_valid_pyri,
  output          rdata_retry_pyro,

  input  [32-1:0] inst_pyri,
  input           inst_valid_pyri,
  output          inst_retry_pyro,

  output [64-1:0] pc_pyro,
  output          pc_valid_pyro,
  input           pc_retry_pyri,

  output [64-1:0] branch_pc_pyro,
  output          branch_pc_valid_pyro,
  input           branch_pc_retry_pyri,

  output [64-1:0] decode_reg_addr_pyro,
  output          decode_reg_addr_valid_pyro,
  input           decode_reg_addr_retry_pyri,

  output [64-1:0] debug_reg_addr_pyro,
  output          debug_reg_addr_valid_pyro,
  input           debug_reg_addr_retry_pyri,

  output [64-1:0] decode_reg_data_pyro,
  output          decode_reg_data_valid_pyro,
  input           decode_reg_data_retry_pyri,

  output [64-1:0] debug_reg_data_pyro,
  output          debug_reg_data_valid_pyro,
  input           debug_reg_data_retry_pyri
);

reg pc_retry_pyro, branch_pc_retry_pyro, raddr_retry_pyro, inst_retry_pyro;

reg [64-1:0] pc_pyro;
reg          pc_valid_pyro;

reg [64-1:0] branch_pc_pyro;
reg          branch_pc_valid_pyro;

reg [64-1:0] decode_reg_addr_pyro;
reg          decode_reg_addr_valid_pyro;

reg [64-1:0] decode_reg_data_pyro;
reg          decode_reg_data_valid_pyro;

reg [64-1:0] debug_reg_data_pyro;
reg          debug_reg_data_valid_pyro;

reg  [64-1:0] cache_addr_low, cache_addr_high;
reg  [64-1:0] cache_data_in_low, cache_data_in_high;

wire [64-1:0] cache_addr_1;
wire [64-1:0] cache_data_out_1;

wire [64-1:0] cache_addr_2;
wire [64-1:0] cache_data_out_2;

wire [64-1:0] cache_addr_3;
wire [64-1:0] cache_data_out_3;

wire [64-1:0] cache_addr_4;
wire [64-1:0] cache_data_out_4;

wire [6:0] opcode;
wire retry;
wire [2:0] funct3;

assign opcode = inst_pyri[6:0];
assign funct3 = inst_pyri[14:12];

assign cache_addr_1 = {3'b0, rdata_pyri[63:3]};
assign cache_addr_2 = cache_addr_1 + 64'b1;

assign cache_addr_3 = {3'b0, raddr_pyri[63:3]};
assign cache_addr_4 = cache_addr_3 + 64'b1;

assign retry = pc_retry_pyri | decode_reg_addr_retry_pyri | debug_reg_addr_retry_pyri | decode_reg_data_retry_pyri | debug_reg_data_retry_pyri;

assign branch_pc_retry_pyro = 1'b0;

always @(*) begin
  {pc_retry_pyro, branch_pc_retry_pyro, raddr_retry_pyro, inst_retry_pyro, rdata_retry_pyro} = 4'b1111;
  {pc_valid_pyro, branch_pc_valid_pyro, decode_reg_addr_valid_pyro, debug_reg_data_valid_pyro} = 4'b0000;
  pc_pyro = 64'b0;
  branch_pc_pyro = 64'b0;

  decode_reg_addr_pyro = 64'b0;

  decode_reg_data_pyro = 64'b0;
  decode_reg_data_valid_pyro = 1'b0;

  debug_reg_data_pyro = 64'b0;

  cache_addr_low = 64'b0;
  cache_addr_high = 64'b0;
  cache_data_in_low = cache_data_out_3;
  cache_data_in_high = cache_data_out_4;
  if(!retry && inst_valid_pyri) begin
    pc_pyro = pc_pyri;
    pc_valid_pyro = pc_valid_pyri;

   if(opcode == `OP_BRANCH) begin
     branch_pc_pyro = branch_pc_pyri;
     branch_pc_valid_pyro = 1'b1;
   end else if (opcode == `OP_JALR || is_arith(opcode)) begin
     decode_reg_addr_pyro = raddr_pyri;
     decode_reg_addr_valid_pyro = raddr_valid_pyri;
     
     decode_reg_data_pyro = rdata_pyri;
     decode_reg_data_valid_pyro = rdata_valid_pyri;

     debug_reg_addr_pyro = raddr_pyri;
     debug_reg_addr_valid_pyro = raddr_valid_pyri;
     
     debug_reg_data_pyro = rdata_pyri;
     debug_reg_data_valid_pyro = rdata_valid_pyri;

     branch_pc_pyro = branch_pc_pyri;
     branch_pc_valid_pyro = branch_pc_valid_pyri;
   end else if(opcode == `OP_LOAD) begin
     decode_reg_addr_pyro = raddr_pyri;
     decode_reg_addr_valid_pyro = raddr_valid_pyri;

     debug_reg_addr_pyro = raddr_pyri;
     debug_reg_addr_valid_pyro = raddr_valid_pyri;
     
     dcache_read(rdata_pyri, funct3, decode_reg_data_pyro);
     decode_reg_data_valid_pyro = rdata_valid_pyri;

     debug_reg_data_pyro = decode_reg_data_pyro;
     debug_reg_data_valid_pyro = rdata_valid_pyri;
   end else if(opcode == `OP_STORE) begin
     cache_addr_low = cache_addr_3;
     cache_addr_high = cache_addr_4;
     dcache_write(raddr_pyri, funct3, rdata_pyri);
   end
   if(pc_valid_pyro || decode_reg_addr_valid_pyro || decode_reg_data_valid_pyro || debug_reg_addr_valid_pyro || debug_reg_data_valid_pyro || branch_pc_valid_pyro)
     {pc_retry_pyro, branch_pc_retry_pyro, raddr_retry_pyro, inst_retry_pyro, rdata_retry_pyro} = 4'b0000;
  end
end

function is_arith;
  input [6:0] opcode_in;
  begin
    is_arith = opcode_in == `OP_ARITH || opcode == `OP_ARITHI || opcode == `OP_ARITH_W || opcode == `OP_ARITHI_W || opcode == `OP_LUI || opcode == `OP_AUIPC || opcode == `OP_JAL;
  end
endfunction

task dcache_read;
  input [64-1:0] addr;
  input [2:0] access_type;
  output [64-1:0] rdata;
  reg [5:0] byte_offset;
  reg overflow;
  begin
    byte_offset = {3'b0, addr[2:0]};
    rdata = 64'b0;
    overflow = 1'b0;
    if(access_type == `FUNCT3_LOAD_BYTE) begin
      rdata = (cache_data_out_1 & (64'hFF << (byte_offset << 3))) >> (byte_offset << 3);
      rdata = {{56{rdata[7]}}, rdata[7:0]};
    end else if(access_type == `FUNCT3_LOAD_HALF) begin
      overflow = byte_offset == 6'd7;
      if(overflow) begin
        rdata = (cache_data_out_1 & (64'hFFFF << (byte_offset << 3))) >> (byte_offset << 3);
        rdata[15:8] = cache_data_out_2[7:0];
      end else
        rdata = (cache_data_out_1 & 64'hFFFF << (byte_offset << 3)) >> (byte_offset << 3);
      rdata = {{48{rdata[15]}}, rdata[15:0]};
    end else if(access_type == `FUNCT3_LOAD_WORD) begin
      overflow = byte_offset >= 6'd5;
      if(overflow) begin
        rdata = (cache_data_out_1 & (64'hFFFFFFFF << (byte_offset << 3))) >> (byte_offset << 3);
        rdata = rdata | ((cache_data_out_2 & (64'hFFFFFFFF >> ((6'd8 - byte_offset) << 3))) << (byte_offset << 3));
      end else
        rdata = (cache_data_out_1 & (64'hFFFFFFFF << (byte_offset << 3))) >> (byte_offset << 3);
      rdata = {{32{rdata[31]}}, rdata[31:0]};
    end else if(access_type == `FUNCT3_LOAD_BYTEU) begin
      rdata = (cache_data_out_1 & (64'hFF << (byte_offset << 3))) >> (byte_offset << 3);
      rdata = {56'b0, rdata[7:0]};
    end else if(access_type == `FUNCT3_LOAD_HALFU) begin
      overflow = byte_offset == 6'd7;
      if(overflow) begin
        rdata = (cache_data_out_1 & (64'hFFFF << (byte_offset << 3))) >> (byte_offset << 3);
        rdata[15:8] = cache_data_out_2[7:0];
      end else
        rdata = (cache_data_out_1 & (64'hFFFF << (byte_offset << 3))) >> (byte_offset << 3);
      rdata = {48'b0, rdata[15:0]};
    end else if(access_type == `FUNCT3_LOAD_W) begin
     overflow = byte_offset != 6'b0;
      if(overflow) begin
        rdata = (cache_data_out_1 & (64'hFFFFFFFFFFFFFF << (byte_offset << 3))) >> (byte_offset << 3);
        rdata = rdata | ((cache_data_out_2 & (64'hFFFFFFFFFFFFFF >> ((6'd8 - byte_offset) << 3))) << (byte_offset << 3));
      end else
        rdata = cache_data_out_1;
    end else if(access_type == `FUNCT3_LOAD_WORD_WU) begin
      overflow = byte_offset >= 6'd5;
      if(overflow) begin
        rdata = (cache_data_out_1 & (64'hFFFFFFFF << (byte_offset << 3))) >> (byte_offset << 3);
        rdata = rdata | ((cache_data_out_2 & (64'hFFFFFFFF >> ((6'd8 - byte_offset) << 3))) << (byte_offset << 3));
      end else
        rdata = (cache_data_out_1 & (64'hFFFFFFFF << (byte_offset << 3))) >> (byte_offset << 3);
      rdata = {32'b0, rdata[31:0]};
    end
  end
endtask

task dcache_write;
  input [64-1:0] addr;
  input [2:0] access_type;
  input [64-1:0] rdata;
  reg [5:0] byte_offset;
  reg overflow;
  begin
    byte_offset = {3'b0, addr[2:0]};
    overflow = 1'b0;
    if(access_type == `FUNCT3_STORE_BYTE) begin
      cache_data_in_low = cache_data_out_3;
      cache_data_in_low = cache_data_in_low & ~(64'hFF << (byte_offset << 6'd3));
      cache_data_in_low = cache_data_in_low | ({56'b0, rdata[7:0]} << (byte_offset << 6'd3));
    end else if(access_type == `FUNCT3_STORE_HALF) begin
      overflow = byte_offset == 6'd7;
      cache_data_in_low = cache_data_out_3;
      if(overflow) begin
        cache_data_in_high = cache_data_out_4;
        cache_data_in_low[63:56] = rdata[7:0];
        cache_data_in_high[7:0] = rdata[15:8];
      end else begin
        cache_data_in_low = cache_data_in_low & ~(64'hFFFF << (byte_offset << 6'd3));
        cache_data_in_low = cache_data_in_low | ({48'b0, rdata[15:0]} << (byte_offset << 6'd3));
      end
    end else if(access_type == `FUNCT3_STORE_WORD) begin
      overflow = byte_offset >= 6'd5;
      cache_data_in_low = cache_data_out_3;
      if(overflow) begin
        cache_data_in_high = cache_data_out_4;
        cache_data_in_low = cache_data_in_low & ~(64'hFFFFFFFF << (byte_offset << 6'd3));
        cache_data_in_low = cache_data_in_low | ((rdata & 64'hFFFFFFFF) << (byte_offset << 6'd3));
        cache_data_in_high = cache_data_in_high & ~(64'hFFFFFFFF >> ((6'd8 - byte_offset) << 6'd3));
        cache_data_in_high = cache_data_in_high | ((rdata & 64'hFFFFFFFF) >> ((6'd8 - byte_offset) << 6'd3));
      end else begin
        cache_data_in_low = cache_data_in_low & ~(64'hFFFFFFFF << (byte_offset << 6'd3));
        cache_data_in_low = cache_data_in_low | ({32'b0, rdata[31:0]} << (byte_offset << 6'd3));
      end
    end else if(access_type == `FUNCT3_STORE_W) begin
      overflow = byte_offset != 6'd0;
      cache_data_in_low = cache_data_out_3;
      if(overflow) begin
        cache_data_in_high = cache_data_out_4;
        cache_data_in_low = cache_data_in_low & ~(64'hFFFFFFFFFFFFFFFF << (byte_offset << 6'd3));
        cache_data_in_low = cache_data_in_low | ((rdata & 64'hFFFFFFFFFFFFFFFF) << (byte_offset << 6'd3));
        cache_data_in_high = cache_data_in_high & ~(64'hFFFFFFFFFFFFFFF >> ((6'd8 - byte_offset) << 6'd3));
        cache_data_in_high = cache_data_in_high | ((rdata & 64'hFFFFFFFFFFFFFFFF) >> ((6'd8 - byte_offset) << 6'd3));
      end else begin
        cache_data_in_low = rdata;
      end
    end
  end
endtask

write_back_block_dcache write_back_block_dcache_inst
(.clk (clk),
 .cache_addr_low     (cache_addr_low),
 .cache_addr_high    (cache_addr_high),
 .cache_data_in_low  (cache_data_in_low),
 .cache_data_in_high (cache_data_in_high),
 .cache_addr_1       (cache_addr_1),
 .cache_addr_2       (cache_addr_2),
 .cache_addr_3       (cache_addr_3),
 .cache_addr_4       (cache_addr_4),
 .cache_data_out_1   (cache_data_out_1),
 .cache_data_out_2   (cache_data_out_2),
 .cache_data_out_3   (cache_data_out_3),
 .cache_data_out_4   (cache_data_out_4)
 );
endmodule

/* verilator lint_off UNUSED */
/* verilator lint_on WIDTH */
