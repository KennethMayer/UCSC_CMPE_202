// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vmultiplication_block_H_
#define _Vmultiplication_block_H_

#include "verilated.h"

class Vmultiplication_block__Syms;
class VerilatedVcd;

//----------

VL_MODULE(Vmultiplication_block) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset_i,0,0);
    VL_IN8(start_i,0,0);
    VL_OUT8(done_o,0,0);
    VL_IN64(multiplier_i,63,0);
    VL_IN64(multiplicand_i,63,0);
    VL_OUT64(product_low_o,63,0);
    VL_OUT64(product_high_o,63,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(multiplication_block__DOT__index,5,0);
    VL_SIG8(multiplication_block__DOT__index_next,5,0);
    VL_SIG8(multiplication_block__DOT__leading_one,5,0);
    VL_SIG8(multiplication_block__DOT__leading_one_next,5,0);
    VL_SIG8(multiplication_block__DOT__recode,2,0);
    VL_SIG8(multiplication_block__DOT__recode_next,2,0);
    VL_SIG8(multiplication_block__DOT__pending,0,0);
    VL_SIG8(multiplication_block__DOT__pending_next,0,0);
    VL_SIG8(multiplication_block__DOT__done_next,0,0);
    VL_SIG8(multiplication_block__DOT__negate,0,0);
    VL_SIG8(multiplication_block__DOT__zero,0,0);
    VL_SIG8(multiplication_block__DOT__shift,0,0);
    VL_SIGW(multiplication_block__DOT__partial,127,0,4);
    VL_SIGW(multiplication_block__DOT__partial_next,127,0,4);
    VL_SIG64(multiplication_block__DOT__product_low_next,63,0);
    VL_SIG64(multiplication_block__DOT__product_high_next,63,0);
    VL_SIG64(multiplication_block__DOT__current,63,0);
    VL_SIG64(multiplication_block__DOT__temp,63,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    static VL_ST_SIG8(__Vtable1_multiplication_block__DOT__negate[8],0,0);
    static VL_ST_SIG8(__Vtable1_multiplication_block__DOT__zero[8],0,0);
    static VL_ST_SIG8(__Vtable1_multiplication_block__DOT__shift[8],0,0);
    VL_SIG8(__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out,5,0);
    VL_SIG8(__Vtableidx1,2,0);
    VL_SIG8(__Vclklast__TOP__clk,0,0);
    VL_SIG(__Vm_traceActivity,31,0);
    VL_SIG64(__Vtask_multiplication_block__DOT__find_leading_one__0__value,63,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vmultiplication_block__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    Vmultiplication_block& operator= (const Vmultiplication_block&);  ///< Copying not allowed
    Vmultiplication_block(const Vmultiplication_block&);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    Vmultiplication_block(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vmultiplication_block();
    /// Trace signals in the model; called by application code
    void trace (VerilatedVcdC* tfp, int levels, int options=0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vmultiplication_block__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vmultiplication_block__Syms* symsp, bool first);
  private:
    static QData _change_request(Vmultiplication_block__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__3(Vmultiplication_block__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset();
  public:
    static void _eval(Vmultiplication_block__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vmultiplication_block__Syms* __restrict vlSymsp);
    static void _eval_settle(Vmultiplication_block__Syms* __restrict vlSymsp);
    static void _sequent__TOP__1(Vmultiplication_block__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vmultiplication_block__Syms* __restrict vlSymsp);
    static void traceChgThis(Vmultiplication_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(Vmultiplication_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(Vmultiplication_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__4(Vmultiplication_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__5(Vmultiplication_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(Vmultiplication_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis__1(Vmultiplication_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInitThis(Vmultiplication_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInitThis__1(Vmultiplication_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInit (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg  (VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif // guard
