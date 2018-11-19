// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vfloat_block_H_
#define _Vfloat_block_H_

#include "verilated_heavy.h"

class Vfloat_block__Syms;
class VerilatedVcd;

//----------

VL_MODULE(Vfloat_block) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset_i,0,0);
    VL_IN8(start_i,0,0);
    VL_IN8(opcode_i,4,0);
    VL_OUT8(done_o,0,0);
    VL_OUT8(exceptions_o,3,0);
    VL_IN(float1_i,31,0);
    VL_IN(float2_i,31,0);
    VL_IN(float3_i,31,0);
    VL_OUT(float_low_o,31,0);
    VL_OUT(float_high_o,31,0);
    VL_OUT64(int_o,63,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__Vfunc_float_block__DOT__isNan__1__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__2__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__floatLess__3__Vfuncout,0,0);
    VL_SIG8(__Vfunc_float_block__DOT__floatEquality__4__Vfuncout,0,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__5__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__6__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__floatEquality__7__Vfuncout,0,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__8__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__9__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__10__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__11__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__floatLess__12__Vfuncout,0,0);
    VL_SIG8(__Vfunc_float_block__DOT__floatEquality__13__Vfuncout,0,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__14__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__15__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__16__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__17__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__floatEquality__18__Vfuncout,0,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__19__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__20__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__floatEquality__23__Vfuncout,0,0);
    VL_SIG8(__Vfunc_float_block__DOT__floatLess__24__Vfuncout,0,0);
    VL_SIG8(__Vfunc_float_block__DOT__floatEquality__25__Vfuncout,0,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__26__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__27__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__28__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__29__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__30__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__31__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__32__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__33__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__34__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__35__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__36__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__37__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__38__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__39__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__40__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__41__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__42__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__43__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__44__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__45__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__floatEquality__47__Vfuncout,0,0);
    VL_SIG8(__Vfunc_float_block__DOT__floatLess__48__Vfuncout,0,0);
    VL_SIG8(__Vfunc_float_block__DOT__floatEquality__49__Vfuncout,0,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__50__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__51__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__52__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__53__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__54__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__55__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__56__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__57__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__58__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__59__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__60__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__61__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__isNan__62__Vfuncout,1,0);
    VL_SIG8(__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__lead_one,4,0);
    VL_SIG8(__Vfunc_float_block__DOT__findLeadOne__65__Vfuncout,4,0);
    VL_SIG8(__Vfunc_float_block__DOT__findLeadOne__66__Vfuncout,4,0);
    VL_SIG8(__Vfunc_float_block__DOT__findLeadOne__68__Vfuncout,4,0);
    VL_SIG8(__Vfunc_float_block__DOT__findLeadOne__69__Vfuncout,4,0);
    VL_SIG8(__Vfunc_float_block__DOT__findLeadOne__71__Vfuncout,4,0);
    VL_SIG8(__Vfunc_float_block__DOT__findLeadOne__72__Vfuncout,4,0);
    VL_SIG8(__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__lead_one,4,0);
    VL_SIG8(__Vfunc_float_block__DOT__findLeadOne__75__Vfuncout,4,0);
    VL_SIG8(__Vfunc_float_block__DOT__findLeadOne__76__Vfuncout,4,0);
    VL_SIG8(__Vfunc_float_block__DOT__findLeadOne__78__Vfuncout,4,0);
    VL_SIG8(__Vfunc_float_block__DOT__findLeadOne__79__Vfuncout,4,0);
    VL_SIG8(__Vfunc_float_block__DOT__findLeadOne__81__Vfuncout,4,0);
    VL_SIG8(__Vfunc_float_block__DOT__findLeadOne__82__Vfuncout,4,0);
    VL_SIG16(__Vfunc_float_block__DOT__classifyFloat__0__Vfuncout,9,0);
    VL_SIG16(__Vfunc_float_block__DOT__classifyFloat__0__unnamedblk1__DOT__mask,9,0);
    VL_SIG(__Vfunc_float_block__DOT__classifyFloat__0__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__1__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__2__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__floatLess__3__float_in1,31,0);
    VL_SIG(__Vfunc_float_block__DOT__floatLess__3__float_in2,31,0);
    VL_SIG(__Vfunc_float_block__DOT__floatEquality__4__float_in1,31,0);
    VL_SIG(__Vfunc_float_block__DOT__floatEquality__4__float_in2,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__5__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__6__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__floatEquality__7__float_in1,31,0);
    VL_SIG(__Vfunc_float_block__DOT__floatEquality__7__float_in2,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__8__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__9__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__10__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__11__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__floatLess__12__float_in1,31,0);
    VL_SIG(__Vfunc_float_block__DOT__floatLess__12__float_in2,31,0);
    VL_SIG(__Vfunc_float_block__DOT__floatEquality__13__float_in1,31,0);
    VL_SIG(__Vfunc_float_block__DOT__floatEquality__13__float_in2,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__14__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__15__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__16__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__17__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__floatEquality__18__float_in1,31,0);
    VL_SIG(__Vfunc_float_block__DOT__floatEquality__18__float_in2,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__19__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__20__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__maxFloat__21__Vfuncout,31,0);
    VL_SIG(__Vfunc_float_block__DOT__maxFloat__21__float_in1,31,0);
    VL_SIG(__Vfunc_float_block__DOT__maxFloat__21__float_in2,31,0);
    VL_SIG(__Vfunc_float_block__DOT__minFloat__22__Vfuncout,31,0);
    VL_SIG(__Vfunc_float_block__DOT__minFloat__22__float_in1,31,0);
    VL_SIG(__Vfunc_float_block__DOT__minFloat__22__float_in2,31,0);
    VL_SIG(__Vfunc_float_block__DOT__floatEquality__23__float_in1,31,0);
    VL_SIG(__Vfunc_float_block__DOT__floatEquality__23__float_in2,31,0);
    VL_SIG(__Vfunc_float_block__DOT__floatLess__24__float_in1,31,0);
    VL_SIG(__Vfunc_float_block__DOT__floatLess__24__float_in2,31,0);
    VL_SIG(__Vfunc_float_block__DOT__floatEquality__25__float_in1,31,0);
    VL_SIG(__Vfunc_float_block__DOT__floatEquality__25__float_in2,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__26__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__27__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__28__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__29__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__30__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__31__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__32__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__33__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__34__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__35__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__36__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__37__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__38__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__39__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__40__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__41__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__42__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__43__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__44__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__45__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__minFloat__46__Vfuncout,31,0);
    VL_SIG(__Vfunc_float_block__DOT__minFloat__46__float_in1,31,0);
    VL_SIG(__Vfunc_float_block__DOT__minFloat__46__float_in2,31,0);
    VL_SIG(__Vfunc_float_block__DOT__floatEquality__47__float_in1,31,0);
    VL_SIG(__Vfunc_float_block__DOT__floatEquality__47__float_in2,31,0);
    VL_SIG(__Vfunc_float_block__DOT__floatLess__48__float_in1,31,0);
    VL_SIG(__Vfunc_float_block__DOT__floatLess__48__float_in2,31,0);
    VL_SIG(__Vfunc_float_block__DOT__floatEquality__49__float_in1,31,0);
    VL_SIG(__Vfunc_float_block__DOT__floatEquality__49__float_in2,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__50__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__51__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__52__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__53__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__54__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__55__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__56__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__57__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__58__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__59__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__60__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__61__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__isNan__62__float_in,31,0);
    VL_SIG(__Vfunc_float_block__DOT__addFloats__63__Vfuncout,31,0);
    VL_SIG(__Vfunc_float_block__DOT__addFloats__63__float_in1,31,0);
    VL_SIG(__Vfunc_float_block__DOT__addFloats__63__float_in2,31,0);
    VL_SIG(__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result,31,0);
    VL_SIG(__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter,23,0);
    VL_SIG(__Vfunc_float_block__DOT__round_man_inter__64__Vfuncout,23,0);
    VL_SIG(__Vfunc_float_block__DOT__round_man_inter__64__man_inter_in,23,0);
    VL_SIG(__Vfunc_float_block__DOT__findLeadOne__65__num,23,0);
    VL_SIG(__Vfunc_float_block__DOT__findLeadOne__66__num,23,0);
    VL_SIG(__Vfunc_float_block__DOT__round_man_inter__67__Vfuncout,23,0);
    VL_SIG(__Vfunc_float_block__DOT__round_man_inter__67__man_inter_in,23,0);
    VL_SIG(__Vfunc_float_block__DOT__findLeadOne__68__num,23,0);
    VL_SIG(__Vfunc_float_block__DOT__findLeadOne__69__num,23,0);
    VL_SIG(__Vfunc_float_block__DOT__round_man_inter__70__Vfuncout,23,0);
    VL_SIG(__Vfunc_float_block__DOT__round_man_inter__70__man_inter_in,23,0);
    VL_SIG(__Vfunc_float_block__DOT__findLeadOne__71__num,23,0);
    VL_SIG(__Vfunc_float_block__DOT__findLeadOne__72__num,23,0);
    VL_SIG(__Vfunc_float_block__DOT__addFloats__73__Vfuncout,31,0);
    VL_SIG(__Vfunc_float_block__DOT__addFloats__73__float_in1,31,0);
    VL_SIG(__Vfunc_float_block__DOT__addFloats__73__float_in2,31,0);
    VL_SIG(__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result,31,0);
    VL_SIG(__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter,23,0);
    VL_SIG(__Vfunc_float_block__DOT__round_man_inter__74__Vfuncout,23,0);
    VL_SIG(__Vfunc_float_block__DOT__round_man_inter__74__man_inter_in,23,0);
    VL_SIG(__Vfunc_float_block__DOT__findLeadOne__75__num,23,0);
    VL_SIG(__Vfunc_float_block__DOT__findLeadOne__76__num,23,0);
    VL_SIG(__Vfunc_float_block__DOT__round_man_inter__77__Vfuncout,23,0);
    VL_SIG(__Vfunc_float_block__DOT__round_man_inter__77__man_inter_in,23,0);
    VL_SIG(__Vfunc_float_block__DOT__findLeadOne__78__num,23,0);
    VL_SIG(__Vfunc_float_block__DOT__findLeadOne__79__num,23,0);
    VL_SIG(__Vfunc_float_block__DOT__round_man_inter__80__Vfuncout,23,0);
    VL_SIG(__Vfunc_float_block__DOT__round_man_inter__80__man_inter_in,23,0);
    VL_SIG(__Vfunc_float_block__DOT__findLeadOne__81__num,23,0);
    VL_SIG(__Vfunc_float_block__DOT__findLeadOne__82__num,23,0);
    VL_SIG(__Vm_traceActivity,31,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vfloat_block__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    Vfloat_block& operator= (const Vfloat_block&);  ///< Copying not allowed
    Vfloat_block(const Vfloat_block&);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    Vfloat_block(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vfloat_block();
    /// Trace signals in the model; called by application code
    void trace (VerilatedVcdC* tfp, int levels, int options=0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vfloat_block__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vfloat_block__Syms* symsp, bool first);
  private:
    static QData _change_request(Vfloat_block__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__1(Vfloat_block__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset();
  public:
    static void _eval(Vfloat_block__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vfloat_block__Syms* __restrict vlSymsp);
    static void _eval_settle(Vfloat_block__Syms* __restrict vlSymsp);
    static void traceChgThis(Vfloat_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(Vfloat_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(Vfloat_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis__1(Vfloat_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInitThis(Vfloat_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInitThis__1(Vfloat_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInit (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg  (VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif // guard
