/* verilator lint_off UNUSED */
`include "rv64.vh"

module pyrm_execute_block(
    input clk,
    input reset_pyri,

    input  [64-1:0] pc_pyri,
    input           pc_valid_pyri,
    output          pc_retry_pyro,

    input  [64-1:0] in1_pyri,
    input           in1_valid_pyri,
    output          in1_retry_pyro,

    input  [64-1:0] in2_pyri,
    input           in2_valid_pyri,
    output          in2_retry_pyro,

    input  [32-1:0] inst_pyri,
    input           inst_valid_pyri,
    output          inst_retry_pyro,

    output [64-1:0] pc_pyro,
    output          pc_valid_pyro,
    input           pc_retry_pyri,

    output [32-1:0] inst_pyro,
    output          inst_valid_pyro,
    input           inst_retry_pyri,

    output [64-1:0] rdata_pyro,
    output          rdata_valid_pyro,
    input           rdata_retry_pyri,

    output [64-1:0] raddr_pyro,
    output          raddr_valid_pyro,
    input           raddr_retry_pyri,

    output [64-1:0] branch_pc_pyro,
    output          branch_pc_valid_pyro,
    input           branch_pc_retry_pyri
);

 reg          pc_retry_pyro;
 reg          in1_retry_pyro;
 reg          in2_retry_pyro;
 reg          inst_retry_pyro;
 
 reg [64-1:0] pc_pyro;
 reg          pc_valid_pyro;

 reg [32-1:0] inst_pyro;
 reg          inst_valid_pyro;

 reg [64-1:0] rdata_pyro;
 reg          rdata_valid_pyro;

 reg [64-1:0] raddr_pyro;
 reg          raddr_valid_pyro;

 reg [64-1:0] branch_pc_pyro;
 reg          branch_pc_valid_pyro;

 wire all_valid, most_valid, some_valid;
 wire [6:0] op;
 wire [6:0] funct7;
 wire [5:0] funct6; // used for the shift-immediate ops
 wire [2:0] funct3;
 wire [12:0] branch_offset;
 wire [11:0] immediate, store_immediate;
 wire [4:0] rd, shamt;
 wire [5:0] shamt_6;
 wire [19:0] u_immediate;
 reg [31:0] temp;
 wire retry;

 assign some_valid = pc_valid_pyri & inst_valid_pyri; // JAL needs no source
 assign most_valid = in1_valid_pyri & pc_valid_pyri & inst_valid_pyri; // some instructions need only one source
 assign all_valid = in1_valid_pyri & in2_valid_pyri & pc_valid_pyri & inst_valid_pyri;
 assign op = inst_pyri[6:0];
 assign funct7 = inst_pyri[31:25];
 assign funct3 = inst_pyri[14:12];
 assign funct6 = inst_pyri[31:26];
 assign branch_offset = {inst_pyri[31], inst_pyri[7], inst_pyri[30:25], inst_pyri[11:8], 1'b0};
 assign immediate = inst_pyri[31:20];
 assign store_immediate = {inst_pyri[31:25], inst_pyri[11:7]};
 assign rd = inst_pyri[11:7];
 assign shamt = inst_pyri[24:20];
 assign u_immediate = inst_pyri[31:12];
 assign shamt_6 = inst_pyri[25:20];
 assign retry = pc_retry_pyri || inst_retry_pyri || rdata_retry_pyri || raddr_retry_pyri || branch_pc_retry_pyri;

 always @(*) begin
   pc_pyro = 64'b0;
   pc_valid_pyro = 1'b0;

   inst_pyro = 32'b0;
   inst_valid_pyro = 1'b0;

   branch_pc_pyro = 64'b0; // These will be modified at a later time tick for branch/jump insns
   branch_pc_valid_pyro = 1'b0;

   raddr_pyro = 64'b0;
   raddr_valid_pyro = 1'b0;
   
   rdata_pyro = 64'b0;
   rdata_valid_pyro = 1'b0;

   {pc_retry_pyro, in1_retry_pyro, in2_retry_pyro, inst_retry_pyro} = 4'b1111;
   if(!retry) begin
     pc_pyro = pc_pyri;
     pc_valid_pyro = all_valid;

     inst_pyro = inst_pyri;
     inst_valid_pyro = all_valid;
     // Begin 64-bit arithmetic functions (register inputs)
     if(op == `OP_ARITH && funct3 == `FUNCT3_ARITH_ADD && funct7 == `FUNCT7_ARTIH_ADD) begin
       rdata_pyro = $signed(in1_pyri) + $signed(in2_pyri);
       rdata_valid_pyro = all_valid;
       raddr_pyro = {59'b0, rd};
       raddr_valid_pyro = all_valid;
     end else if(op == `OP_ARITH && funct3 == `FUNCT3_ARITH_SUB && funct7 == `FUNCT7_ARTIH_SUB) begin
       rdata_pyro = $signed(in1_pyri) - $signed(in2_pyri);
       rdata_valid_pyro = all_valid;
       raddr_pyro = {59'b0, rd};
       raddr_valid_pyro = all_valid;
     end else if(op == `OP_ARITH && funct3 == `FUNCT3_ARITH_XOR && funct7 == `FUNCT7_ARITH_XOR) begin
       rdata_pyro = in1_pyri ^ in2_pyri;
       rdata_valid_pyro = all_valid;
       raddr_pyro = {59'b0, rd};
       raddr_valid_pyro = all_valid;
     end else if(op == `OP_ARITH && funct3 == `FUNCT3_ARITH_OR && funct7 == `FUNCT7_ARITH_OR) begin
       rdata_pyro = in1_pyri | in2_pyri;
       rdata_valid_pyro = all_valid;
       raddr_pyro = {59'b0, rd};
       raddr_valid_pyro = all_valid;
     end else if(op == `OP_ARITH && funct3 == `FUNCT3_ARITH_AND && funct7 == `FUNCT7_ARITH_AND) begin
       rdata_pyro = in1_pyri & in2_pyri;
       rdata_valid_pyro = all_valid;
       raddr_pyro = {59'b0, rd};
       raddr_valid_pyro = all_valid;
     end else if(op == `OP_ARITH && funct3 == `FUNCT3_ARITH_SLL && funct7 == `FUNCT7_ARITH_SLL) begin
       rdata_pyro = $signed(in1_pyri) << in2_pyri[5:0];
       rdata_valid_pyro = all_valid;
       raddr_pyro = {59'b0, rd};
       raddr_valid_pyro = all_valid;
     end else if(op == `OP_ARITH && funct3 == `FUNCT3_ARITH_SRL && funct7 == `FUNCT7_ARITH_SRL) begin
       rdata_pyro = $signed(in1_pyri) >> in2_pyri[5:0];
       rdata_valid_pyro = all_valid;
       raddr_pyro = {59'b0, rd};
       raddr_valid_pyro = all_valid;
     end else if(op == `OP_ARITH && funct3 == `FUNCT3_ARITH_SRA && funct7 == `FUNCT7_ARITH_SRA) begin
       rdata_pyro = $signed(in1_pyri) >>> in2_pyri[5:0];
       rdata_valid_pyro = all_valid;
       raddr_pyro = {59'b0, rd};
       raddr_valid_pyro = all_valid;
     end else if(op == `OP_ARITH && funct3 == `FUNCT3_ARITH_SLT && funct7 == `FUNCT7_ARITH_SLT) begin
       if($signed(in1_pyri) < $signed(in2_pyri)) begin
         rdata_pyro = 64'b1;
       end else begin
         rdata_pyro = 64'b0;
       end
       rdata_valid_pyro = all_valid;
       raddr_pyro = {59'b0, rd};
       raddr_valid_pyro = all_valid;
     end else if(op == `OP_ARITH && funct3 == `FUNCT3_ARITH_SLTU && funct7 == `FUNCT7_ARITH_SLT) begin
       if(in1_pyri < in2_pyri) begin
         rdata_pyro = 64'b1;
       end else begin
         rdata_pyro = 64'b0;
       end
       rdata_valid_pyro = all_valid;
       raddr_pyro = {59'b0, rd};
       raddr_valid_pyro = all_valid;
     // begin 64-bit arithmetic operations (with immediate value)
     end else if(op == `OP_ARITHI && funct3 == `FUNCT3_ARITH_ADD) begin 
       rdata_pyro = $signed(in1_pyri) + $signed({{52{immediate[11]}}, immediate});
       rdata_valid_pyro = all_valid;
       raddr_pyro = {59'b0, rd};
       raddr_valid_pyro = all_valid;
     end else if(op == `OP_ARITHI && funct3 == `FUNCT3_ARITH_XOR) begin
       rdata_pyro = in1_pyri ^ {{52{immediate[11]}}, immediate};
       rdata_valid_pyro = all_valid;
       raddr_pyro = {59'b0, rd};
       raddr_valid_pyro = all_valid;
     end else if(op == `OP_ARITHI && funct3 == `FUNCT3_ARITH_OR) begin
       rdata_pyro = in1_pyri | {{52{immediate[11]}}, immediate};
       rdata_valid_pyro = all_valid;
       raddr_pyro = {59'b0, rd};
       raddr_valid_pyro = all_valid;
     end else if(op == `OP_ARITHI && funct3 == `FUNCT3_ARITH_AND) begin
       rdata_pyro = in1_pyri & {{52{immediate[11]}}, immediate};
       rdata_valid_pyro = all_valid;
       raddr_pyro = {59'b0, rd};
       raddr_valid_pyro = all_valid;
     end else if(op == `OP_ARITHI && funct3 == `FUNCT3_ARITH_SLL && funct6 == `FUNCT6_ARITH_SLL) begin
       rdata_pyro = $signed(in1_pyri) << shamt_6;
       rdata_valid_pyro = all_valid;
       raddr_pyro = {59'b0, rd};
       raddr_valid_pyro = all_valid;
     end else if(op == `OP_ARITHI && funct3 == `FUNCT3_ARITH_SRL && funct6 == `FUNCT6_ARITH_SRL) begin
       rdata_pyro = $signed(in1_pyri) >> shamt_6;
       rdata_valid_pyro = all_valid;
       raddr_pyro = {59'b0, rd};
       raddr_valid_pyro = all_valid;
     end else if(op == `OP_ARITHI && funct3 == `FUNCT3_ARITH_SRA && funct6 == `FUNCT6_ARITH_SRA) begin
       rdata_pyro = $signed(in1_pyri) >>> shamt_6;
       rdata_valid_pyro = all_valid;
       raddr_pyro = {59'b0, rd};
       raddr_valid_pyro = all_valid;
     end else if(op == `OP_ARITHI && funct3 == `FUNCT3_ARITH_SLT) begin
       if($signed(in1_pyri) < $signed({{52{immediate[11]}}, immediate})) begin
         rdata_pyro = 64'b1;
       end else begin
         rdata_pyro = 64'b0;
       end
       rdata_valid_pyro = all_valid;
       raddr_pyro = {59'b0, rd};
       raddr_valid_pyro = all_valid;
     end else if(op == `OP_ARITHI && funct3 == `FUNCT3_ARITH_SLTU) begin
       if(in1_pyri < {52'b0, immediate}) begin
         rdata_pyro = 64'b1;
       end else begin
         rdata_pyro = 64'b0;
       end
       rdata_valid_pyro = all_valid;
       raddr_pyro = {59'b0, rd};
       raddr_valid_pyro = all_valid;
     // begin branch operations
     end else if(op == `OP_BRANCH && funct3 == `FUNCT3_BRANCH_EQ) begin
       if($signed(in1_pyri) == $signed(in2_pyri)) begin
         branch_pc_pyro = $signed(pc_pyri) + $signed({{51{branch_offset[12]}} , branch_offset});
         branch_pc_valid_pyro = all_valid;
       end else begin
         branch_pc_pyro = $signed(pc_pyri) + (64'd4);
         branch_pc_valid_pyro = all_valid;
       end
     end else if(op == `OP_BRANCH && funct3 == `FUNCT3_BRANCH_NOTEQ) begin
       if($signed(in1_pyri) != $signed(in2_pyri)) begin
         branch_pc_pyro = $signed(pc_pyri) + $signed({{51{branch_offset[12]}} , branch_offset});
         branch_pc_valid_pyro = all_valid;
       end else begin
         branch_pc_pyro = $signed(pc_pyri) + (64'd4);
         branch_pc_valid_pyro = all_valid;
       end
     end else if(op == `OP_BRANCH && funct3 == `FUNCT3_BRANCH_LESS) begin
       if($signed(in1_pyri) < $signed(in2_pyri)) begin
         branch_pc_pyro = $signed(pc_pyri) + $signed({{51{branch_offset[12]}} , branch_offset});
         branch_pc_valid_pyro = all_valid;
       end else begin
         branch_pc_pyro = $signed(pc_pyri) + (64'd4);
         branch_pc_valid_pyro = all_valid;
       end
     end else if(op == `OP_BRANCH && funct3 == `FUNCT3_BRANCH_GEQ) begin
       if($signed(in1_pyri) >= $signed(in2_pyri)) begin
         branch_pc_pyro = $signed(pc_pyri) + $signed({{51{branch_offset[12]}} , branch_offset});
         branch_pc_valid_pyro = all_valid;
       end else begin
         branch_pc_pyro = $signed(pc_pyri) + (64'd4);
         branch_pc_valid_pyro = all_valid;
       end
     end else if(op == `OP_BRANCH && funct3 == `FUNCT3_BRANCH_LESSU) begin
       if(in1_pyri < in2_pyri) begin
         branch_pc_pyro = $signed(pc_pyri) + $signed({{51{branch_offset[12]}} , branch_offset});
         branch_pc_valid_pyro = all_valid;
       end else begin
         branch_pc_pyro = $signed(pc_pyri) + (64'd4);
         branch_pc_valid_pyro = all_valid;
       end
     end else if(op == `OP_BRANCH && funct3 == `FUNCT3_BRANCH_GEQU) begin
       if(in1_pyri >= in2_pyri) begin
         branch_pc_pyro = $signed(pc_pyri) + $signed({{51{branch_offset[12]}} , branch_offset});
         branch_pc_valid_pyro = all_valid;
       end else begin
         branch_pc_pyro = $signed(pc_pyri) + (64'd4);
         branch_pc_valid_pyro = all_valid;
       end
     // begin 32-bit memory operations
     end else if(op == `OP_LOAD) begin
       rdata_pyro = $signed(in1_pyri) + $signed({{52{immediate[11]}}, immediate});
       rdata_valid_pyro = all_valid;
       raddr_pyro = {59'b0, rd};
       raddr_valid_pyro = all_valid;
     end else if(op == `OP_STORE) begin
       rdata_pyro = in2_pyri;
       rdata_valid_pyro = all_valid;
       raddr_pyro = $signed(in1_pyri) + $signed({{52{store_immediate[11]}}, store_immediate});
       raddr_valid_pyro = all_valid;
     end else if(op == `OP_JAL) begin
       rdata_pyro = pc_pyri + 64'd4;
       rdata_valid_pyro = some_valid;
       raddr_pyro = {59'b0, rd};
       raddr_valid_pyro = some_valid;
       pc_valid_pyro = some_valid;
       inst_valid_pyro = some_valid;
     end else if(op == `OP_JALR && funct3 == `FUNCT3_JALR) begin
       rdata_pyro = pc_pyri + 64'd4;
       rdata_valid_pyro = most_valid;
       branch_pc_pyro = $signed({{51{immediate[11]}}, immediate}) + $signed(in1_pyri);
       branch_pc_pyro = {branch_pc_pyro[63:1], 1'b0};
       branch_pc_valid_pyro = most_valid;
       raddr_pyro = {59'b0, rd};
       raddr_valid_pyro = most_valid;
       pc_valid_pyro = most_valid;
       inst_valid_pyro = most_valid;
     end else if(op == `OP_LUI) begin
       rdata_pyro = $signed({{32{u_immediate[19]}}, u_immediate, 12'b0});
       rdata_valid_pyro = most_valid;
       raddr_pyro = {59'b0, rd};
       raddr_valid_pyro = most_valid;
       pc_valid_pyro = most_valid;
       inst_valid_pyro = most_valid;
     end else if(op == `OP_AUIPC) begin
       rdata_pyro = $signed({{32{u_immediate[19]}}, u_immediate, 12'b0}) + $signed(pc_pyri);
       rdata_valid_pyro = most_valid;
       raddr_pyro = {59'b0, rd};
       raddr_valid_pyro = most_valid;
       pc_valid_pyro = most_valid;
       inst_valid_pyro = most_valid;
     end else if(op == `OP_ARITH_W && funct3 == `FUNCT3_ARITH_ADD && funct7 == `FUNCT7_ARTIH_ADD) begin
       temp = $signed(in1_pyri[31:0]) + $signed(in2_pyri[31:0]);
       rdata_pyro = {{32{temp[31]}}, temp};
       rdata_valid_pyro = all_valid;
       raddr_pyro = {59'b0, rd};
       raddr_valid_pyro = all_valid;
     end else if(op == `OP_ARITH_W && funct3 == `FUNCT3_ARITH_SUB && funct7 == `FUNCT7_ARTIH_SUB) begin
       temp = $signed(in1_pyri[31:0]) - $signed(in2_pyri[31:0]);
       rdata_pyro = {{32{temp[31]}}, temp};
       rdata_valid_pyro = all_valid;
       raddr_pyro = {59'b0, rd};
       raddr_valid_pyro = all_valid;
     end else if(op == `OP_ARITH_W && funct3 == `FUNCT3_ARITH_SLL && funct7 == `FUNCT7_ARITH_SLL) begin
       temp = $signed(in1_pyri[31:0]) << in2_pyri[4:0];
       rdata_pyro = {{32{temp[31]}}, temp};
       rdata_valid_pyro = all_valid;
       raddr_pyro = {59'b0, rd};
       raddr_valid_pyro = all_valid;
     end else if(op == `OP_ARITH_W && funct3 == `FUNCT3_ARITH_SRL && funct7 == `FUNCT7_ARITH_SRL) begin
       temp = $signed(in1_pyri[31:0]) >> in2_pyri[4:0];
       rdata_pyro = {{32{temp[31]}}, temp};
       rdata_valid_pyro = all_valid;
       raddr_pyro = {59'b0, rd};
       raddr_valid_pyro = all_valid;
     end else if(op == `OP_ARITH_W && funct3 == `FUNCT3_ARITH_SRA && funct7 == `FUNCT7_ARITH_SRA) begin
       temp = $signed(in1_pyri[31:0]) >>> in2_pyri[4:0];
       rdata_pyro = {{32{temp[31]}}, temp};
       rdata_valid_pyro = all_valid;
       raddr_pyro = {59'b0, rd};
       raddr_valid_pyro = all_valid;
     end else if(op == `OP_ARITHI_W && funct3 == `FUNCT3_ARITH_ADD) begin 
       temp = $signed(in1_pyri[31:0]) + $signed({{20{immediate[11]}}, immediate});
       rdata_pyro = {{32{temp[31]}}, temp};
       rdata_valid_pyro = all_valid;
       raddr_pyro = {59'b0, rd};
       raddr_valid_pyro = all_valid;
     end else if(op == `OP_ARITHI_W && funct3 == `FUNCT3_ARITH_SLL && funct7 == `FUNCT7_ARITH_SLL) begin
       temp = $signed(in1_pyri[31:0]) << shamt;
       rdata_pyro = {{32{temp[31]}}, temp};
       rdata_valid_pyro = all_valid;
       raddr_pyro = {59'b0, rd};
       raddr_valid_pyro = all_valid;
     end else if(op == `OP_ARITHI_W && funct3 == `FUNCT3_ARITH_SRL && funct7 == `FUNCT7_ARITH_SRL) begin
       temp = $signed(in1_pyri[31:0]) >> shamt;
       rdata_pyro = {{32{temp[31]}}, temp};
       rdata_valid_pyro = all_valid;
       raddr_pyro = {59'b0, rd};
       raddr_valid_pyro = all_valid;
     end else if(op == `OP_ARITHI_W && funct3 == `FUNCT3_ARITH_SRA && funct7 == `FUNCT7_ARITH_SRA) begin
       temp = $signed(in1_pyri[31:0]) >>> shamt;
       rdata_pyro = {{32{temp[31]}}, temp};
       rdata_valid_pyro = all_valid;
       raddr_pyro = {59'b0, rd};
       raddr_valid_pyro = all_valid;
     end
    if(rdata_valid_pyro | raddr_valid_pyro | branch_pc_valid_pyro) // if at least one of these is the valid, no need to retry
      {pc_retry_pyro, in1_retry_pyro, in2_retry_pyro, inst_retry_pyro} = 4'b0000;
   end
 end

endmodule
/* verilator lint_off UNUSED */
