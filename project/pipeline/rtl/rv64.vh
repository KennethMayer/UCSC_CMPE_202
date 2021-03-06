// Constants for use in the pipeline blocks

`define STATE_RUNNING       1'b0
`define STATE_BRANCH        1'b1
`define NO_RETRY            1'b0
`define RETRY               1'b1

// Bit Encodings for RV64I (look at page 126 in riscv ISA spec 2.3-draft

// Base opcodes for overall function types (RV32I)
`define OP_ARITH             7'b0110011
`define OP_ARITHI            7'b0010011
`define OP_AUIPC             7'b0010111
`define OP_BRANCH            7'b1100011
`define OP_JALR              7'b1100111
`define OP_JAL               7'b1101111
`define OP_LUI               7'b0110111
`define OP_LOAD              7'b0000011
`define OP_STORE             7'b0100011

// Base opcodes for overall function types (RV64I)
`define OP_ARITHI_W          7'b0011011
`define OP_ARITH_W           7'b0111011

// funct3 bits (RV32I)
`define FUNCT3_ARITH_ADD     3'b000
`define FUNCT3_ARITH_SUB     3'b000
`define FUNCT3_ARITH_XOR     3'b100
`define FUNCT3_ARITH_OR      3'b110
`define FUNCT3_ARITH_AND     3'b111
`define FUNCT3_ARITH_SLL     3'b001
`define FUNCT3_ARITH_SRL     3'b101
`define FUNCT3_ARITH_SRA     3'b101
`define FUNCT3_ARITH_SLT     3'b010
`define FUNCT3_ARITH_SLTU    3'b011
`define FUNCT3_BRANCH_EQ     3'b000
`define FUNCT3_BRANCH_NOTEQ  3'b001
`define FUNCT3_BRANCH_LESS   3'b100
`define FUNCT3_BRANCH_GEQ    3'b101
`define FUNCT3_BRANCH_LESSU  3'b110
`define FUNCT3_BRANCH_GEQU   3'b111
`define FUNCT3_LOAD_BYTE     3'b000
`define FUNCT3_LOAD_HALF     3'b001
`define FUNCT3_LOAD_WORD     3'b010
`define FUNCT3_LOAD_BYTEU    3'b100
`define FUNCT3_LOAD_HALFU    3'b101
`define FUNCT3_STORE_BYTE    3'b000
`define FUNCT3_STORE_HALF    3'b001
`define FUNCT3_STORE_WORD    3'b010
`define FUNCT3_JALR          3'b000

// funct3 bits (RV64I)
`define FUNCT3_LOAD_W        3'b011
`define FUNCT3_LOAD_WORD_WU  3'b110
`define FUNCT3_STORE_W       3'b011

// funct6 bits (RV64I)
`define FUNCT6_ARITH_SLL     6'b000000
`define FUNCT6_ARITH_SRL     6'b000000
`define FUNCT6_ARITH_SRA     6'b010000

// funct7 bits (RV32I)
`define FUNCT7_ARITH_SLL     7'b0000000
`define FUNCT7_ARITH_SRL     7'b0000000
`define FUNCT7_ARITH_SRA     7'b0100000
`define FUNCT7_ARITH_XOR     7'b0000000
`define FUNCT7_ARITH_OR      7'b0000000
`define FUNCT7_ARITH_AND     7'b0000000
`define FUNCT7_ARTIH_ADD     7'b0000000
`define FUNCT7_ARTIH_SUB     7'b0100000
`define FUNCT7_ARITH_SLT     7'b0000000

// base opcodes (RV32M)
`define OP_ARITHM            7'b011011

// funct7 bits (RV32M)
`define FUNCT7_ARITHM        7'b0000001

// funct3 bits (RV32M)
`define FUNCT3_ARITHM_MUL    3'b000
`define FUNCT3_ARITHM_MULH   3'b001
`define FUNCT3_ARITHM_MULHSU 3'b010
`define FUNCT3_ARITHM_MULHU  3'b011
`define FUNCT3_ARITHM_DIV    3'b100
`define FUNCT3_ARITHM_DIVU   3'b101
`define FUNCT3_ARITHM_REM    3'b110
`define FUNCT3_ARITHM_REMU   3'b111

// base opcodes (RV64M)
`define OP_ARITHMW           7'b0111011

// funct7 bits (RV64M)
`define FUNCT7_ARITHMW       7'b0000001

// funct3 bits (RV64M)
`define FUNCT3_ARITHMW_MULW  3'b000
`define FUNCT3_ARITHMW_DIVW  3'b100
`define FUNCT3_ARITHMW_DIVUW 3'b101
`define FUNCT3_ARITHMW_REMW  3'b110
`define FUNCT3_ARITHMW_REMUW 3'b111
