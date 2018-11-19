// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vdivision_block_H_
#define _Vdivision_block_H_

#include "verilated.h"

class Vdivision_block__Syms;
class VerilatedVcd;

//----------

VL_MODULE(Vdivision_block) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset_i,0,0);
    VL_IN8(start_i,0,0);
    VL_OUT8(done_o,0,0);
    VL_IN64(dividend_i,63,0);
    VL_IN64(divisor_i,63,0);
    VL_OUT64(quotient_o,63,0);
    VL_OUT64(remainder_o,63,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(division_block__DOT__done_next,0,0);
    VL_SIG8(division_block__DOT__pending,0,0);
    VL_SIG8(division_block__DOT__pending_next,0,0);
    VL_SIG8(division_block__DOT__sign,0,0);
    VL_SIG8(division_block__DOT__sign_next,0,0);
    VL_SIG8(division_block__DOT__index,6,0);
    VL_SIG8(division_block__DOT__index_next,6,0);
    VL_SIGW(division_block__DOT__remainder,127,0,4);
    VL_SIGW(division_block__DOT__remainder_next,127,0,4);
    VL_SIGW(division_block__DOT__diff,64,0,3);
    VL_SIG64(division_block__DOT__quotient_next,63,0);
    VL_SIG64(division_block__DOT__dividend,63,0);
    VL_SIG64(division_block__DOT__dividend_next,63,0);
    VL_SIG64(division_block__DOT__divisor,63,0);
    VL_SIG64(division_block__DOT__divisor_next,63,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__Vclklast__TOP__clk,0,0);
    VL_SIG(__Vm_traceActivity,31,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vdivision_block__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    Vdivision_block& operator= (const Vdivision_block&);  ///< Copying not allowed
    Vdivision_block(const Vdivision_block&);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    Vdivision_block(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vdivision_block();
    /// Trace signals in the model; called by application code
    void trace (VerilatedVcdC* tfp, int levels, int options=0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vdivision_block__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vdivision_block__Syms* symsp, bool first);
  private:
    static QData _change_request(Vdivision_block__Syms* __restrict vlSymsp);
    void _ctor_var_reset();
  public:
    static void _eval(Vdivision_block__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vdivision_block__Syms* __restrict vlSymsp);
    static void _eval_settle(Vdivision_block__Syms* __restrict vlSymsp);
    static void _sequent__TOP__1(Vdivision_block__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vdivision_block__Syms* __restrict vlSymsp);
    static void traceChgThis(Vdivision_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(Vdivision_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(Vdivision_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__4(Vdivision_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(Vdivision_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis__1(Vdivision_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInitThis(Vdivision_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInitThis__1(Vdivision_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInit (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg  (VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif // guard
