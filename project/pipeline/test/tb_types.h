#ifndef TB_TYPES_H_
#define TB_TYPES_H_

#include "Pyrope.h"

#define INST_WIDTH (32)

#define U8 (8)

#define ARITH_IMM_OP (19)

#define ARITH_REG_OP (51)

#define ARITH_IMM_W_OP (27)

#define ARITH_REG_W_OP (59)

#define BRANCH_OP (99)

#define JAL_OP (111)

#define JALR_OP (103)

#define LOAD_OP (3)

#define STORE_OP (35)

#define LUI_OP (55)

#define AUIPC_OP (23)

#define SCALL_OP (115)

#define MEM_SBYTE (0)

#define MEM_SHWORD (1)

#define MEM_UBYTE (4)

#define MEM_UHWORD (5)

#define MEM_SWORD (2)

#define MEM_UWORD (6)

#define MEM_DWORD (3)

#define JAL_IMM_MASK (18446744073708503040)

#define IMM12_MASK (18446744073709547520)

#define MEM_SBYTE_MASK (18446744073709551360)

#define MEM_SHWORD_MASK (18446744073709486080)

#define MEM_SWORD_MASK (18446744069414584320)

#define ADDR_TO_CACHE_INDEX_SHIFT (3)

#define ADDR_TO_CACHE_INDEX_MASK (7)

#define CACHE_LINE_BYTES (8)

#define CACHE_LINE_BITS (64)

#define DATA_WIDTH (64)

#define ADDR_WIDTH (64)

#define DCACHE_SIZE (2048)

#define ICACHE_SIZE (4096)

#define DCACHE_DATA_WIDTH (64)

#define STATE_INIT (0)

#define STATE_RUNNING (1)

#define STATE_IC_REQ (1)

#define STATE_BR (2)

#define STATE_BEFORE_BR (3)

#define CACHE_ADDR_MASK (65535)

#define OPERATION_WIDTH (10)

#define REG_SRC_ADDR_WIDTH (5)

#define REG_COUNT (32)

#define MUL_DIV_FUNC7 (1)

#define REG_ADDR_WIDTH (5)



#endif
