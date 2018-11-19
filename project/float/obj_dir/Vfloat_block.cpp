// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfloat_block.h for the primary calling header

#include "Vfloat_block.h"      // For This
#include "Vfloat_block__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vfloat_block) {
    Vfloat_block__Syms* __restrict vlSymsp = __VlSymsp = new Vfloat_block__Syms(this, name());
    Vfloat_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vfloat_block::__Vconfigure(Vfloat_block__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vfloat_block::~Vfloat_block() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vfloat_block::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vfloat_block::eval\n"); );
    Vfloat_block__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vfloat_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    while (VL_LIKELY(__Vchange)) {
	VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
	vlSymsp->__Vm_activity = true;
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
    }
}

void Vfloat_block::_eval_initial_loop(Vfloat_block__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    int __VclockLoop = 0;
    QData __Vchange = 1;
    while (VL_LIKELY(__Vchange)) {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
    }
}

//--------------------
// Internal Methods

VL_INLINE_OPT void Vfloat_block::_combo__TOP__1(Vfloat_block__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfloat_block::_combo__TOP__1\n"); );
    Vfloat_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/float_block.v:101
    vlTOPp->done_o = 0U;
    vlTOPp->exceptions_o = 0U;
    vlTOPp->float_low_o = 0U;
    vlTOPp->float_high_o = 0U;
    vlTOPp->int_o = VL_ULL(0);
    if (vlTOPp->start_i) {
	if ((0x10U & (IData)(vlTOPp->opcode_i))) {
	    if ((1U & (~ ((IData)(vlTOPp->opcode_i) 
			  >> 3U)))) {
		if ((4U & (IData)(vlTOPp->opcode_i))) {
		    if ((2U & (IData)(vlTOPp->opcode_i))) {
			if ((1U & (~ (IData)(vlTOPp->opcode_i)))) {
			    // Function: classifyFloat at rtl/float_block.v:168
			    // Function: isNan at rtl/float_block.v:278
			    // Function: isNan at rtl/float_block.v:280
			    vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__float_in 
				= vlTOPp->float1_i;
			    vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__unnamedblk1__DOT__mask = 0U;
			    if ((0xfff00000U == vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__float_in)) {
				vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__unnamedblk1__DOT__mask 
				    = (1U | (IData)(vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__unnamedblk1__DOT__mask));
			    }
			    if (((0U != (0xffU & (vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__float_in 
						  >> 0x17U))) 
				 & (vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__float_in 
				    >> 0x1fU))) {
				vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__unnamedblk1__DOT__mask 
				    = (2U | (IData)(vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__unnamedblk1__DOT__mask));
			    }
			    if (((0U == (0xffU & (vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__float_in 
						  >> 0x17U))) 
				 & (vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__float_in 
				    >> 0x1fU))) {
				vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__unnamedblk1__DOT__mask 
				    = (4U | (IData)(vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__unnamedblk1__DOT__mask));
			    }
			    if (((0U == (0xffU & (vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__float_in 
						  >> 0x17U))) 
				 & (~ (vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__float_in 
				       >> 0x1fU)))) {
				vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__unnamedblk1__DOT__mask 
				    = (0x20U | (IData)(vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__unnamedblk1__DOT__mask));
			    }
			    if (((0U != (0xffU & (vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__float_in 
						  >> 0x17U))) 
				 & (~ (vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__float_in 
				       >> 0x1fU)))) {
				vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__unnamedblk1__DOT__mask 
				    = (0x40U | (IData)(vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__unnamedblk1__DOT__mask));
			    }
			    if (((0U == (0x7fffffffU 
					 & vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__float_in)) 
				 & (vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__float_in 
				    >> 0x1fU))) {
				vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__unnamedblk1__DOT__mask 
				    = (8U | (IData)(vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__unnamedblk1__DOT__mask));
				vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__unnamedblk1__DOT__mask 
				    = (0x3fbU & (IData)(vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__unnamedblk1__DOT__mask));
				vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__unnamedblk1__DOT__mask 
				    = (0x3dfU & (IData)(vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__unnamedblk1__DOT__mask));
			    }
			    if (((0U == (0x7fffffffU 
					 & vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__float_in)) 
				 & (~ (vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__float_in 
				       >> 0x1fU)))) {
				vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__unnamedblk1__DOT__mask 
				    = (0x10U | (IData)(vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__unnamedblk1__DOT__mask));
				vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__unnamedblk1__DOT__mask 
				    = (0x3fbU & (IData)(vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__unnamedblk1__DOT__mask));
				vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__unnamedblk1__DOT__mask 
				    = (0x3dfU & (IData)(vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__unnamedblk1__DOT__mask));
			    }
			    if ((0x7ff00000U == vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__float_in)) {
				vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__unnamedblk1__DOT__mask 
				    = (0x80U | (IData)(vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__unnamedblk1__DOT__mask));
			    }
			    vlTOPp->__Vfunc_float_block__DOT__isNan__1__float_in 
				= vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__float_in;
			    vlTOPp->__Vfunc_float_block__DOT__isNan__1__Vfuncout = 0U;
			    if ((((0x7fffffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__1__float_in) 
				  & (0x7fc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__1__float_in)) 
				 | (0xffc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__1__float_in))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__1__Vfuncout = 1U;
			    }
			    if ((((0x7fbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__1__float_in) 
				  & (0x7f800001U <= vlTOPp->__Vfunc_float_block__DOT__isNan__1__float_in)) 
				 | ((0xffbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__1__float_in) 
				    & (0xff800001U 
				       <= vlTOPp->__Vfunc_float_block__DOT__isNan__1__float_in)))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__1__Vfuncout = 2U;
			    }
			    if ((1U == (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__1__Vfuncout))) {
				vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__unnamedblk1__DOT__mask 
				    = (0x100U | (IData)(vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__unnamedblk1__DOT__mask));
			    }
			    vlTOPp->__Vfunc_float_block__DOT__isNan__2__float_in 
				= vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__float_in;
			    vlTOPp->__Vfunc_float_block__DOT__isNan__2__Vfuncout = 0U;
			    if ((((0x7fffffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__2__float_in) 
				  & (0x7fc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__2__float_in)) 
				 | (0xffc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__2__float_in))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__2__Vfuncout = 1U;
			    }
			    if ((((0x7fbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__2__float_in) 
				  & (0x7f800001U <= vlTOPp->__Vfunc_float_block__DOT__isNan__2__float_in)) 
				 | ((0xffbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__2__float_in) 
				    & (0xff800001U 
				       <= vlTOPp->__Vfunc_float_block__DOT__isNan__2__float_in)))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__2__Vfuncout = 2U;
			    }
			    if ((2U == (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__2__Vfuncout))) {
				vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__unnamedblk1__DOT__mask 
				    = (0x200U | (IData)(vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__unnamedblk1__DOT__mask));
			    }
			    vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__Vfuncout 
				= vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__unnamedblk1__DOT__mask;
			    vlTOPp->int_o = (QData)((IData)(vlTOPp->__Vfunc_float_block__DOT__classifyFloat__0__Vfuncout));
			    vlTOPp->done_o = 1U;
			}
		    } else {
			if ((1U & (IData)(vlTOPp->opcode_i))) {
			    // Function: floatLess at rtl/float_block.v:164
			    // Function: floatEquality at rtl/float_block.v:164
			    // Function: isNan at rtl/float_block.v:204
			    // Function: isNan at rtl/float_block.v:204
			    // Function: floatEquality at rtl/float_block.v:231
			    // Function: isNan at rtl/float_block.v:204
			    // Function: isNan at rtl/float_block.v:204
			    // Function: isNan at rtl/float_block.v:233
			    // Function: isNan at rtl/float_block.v:233
			    vlTOPp->__Vfunc_float_block__DOT__floatEquality__4__float_in2 
				= vlTOPp->float2_i;
			    vlTOPp->__Vfunc_float_block__DOT__floatEquality__4__float_in1 
				= vlTOPp->float1_i;
			    vlTOPp->__Vfunc_float_block__DOT__floatEquality__4__Vfuncout 
				= (((((0xffU & (vlTOPp->__Vfunc_float_block__DOT__floatEquality__4__float_in1 
						>> 0x17U)) 
				      == (0xffU & (vlTOPp->__Vfunc_float_block__DOT__floatEquality__4__float_in2 
						   >> 0x17U))) 
				     & ((0x7fffffU 
					 & vlTOPp->__Vfunc_float_block__DOT__floatEquality__4__float_in1) 
					== (0x7fffffU 
					    & vlTOPp->__Vfunc_float_block__DOT__floatEquality__4__float_in2))) 
				    & ((1U & (vlTOPp->__Vfunc_float_block__DOT__floatEquality__4__float_in1 
					      >> 0x1fU)) 
				       == (1U & (vlTOPp->__Vfunc_float_block__DOT__floatEquality__4__float_in2 
						 >> 0x1fU)))) 
				   | ((((0x7fffffffU 
					 & vlTOPp->__Vfunc_float_block__DOT__floatEquality__4__float_in1) 
					== (0x7fffffffU 
					    & vlTOPp->__Vfunc_float_block__DOT__floatEquality__4__float_in2)) 
				       & (0U == (0x7fffffffU 
						 & vlTOPp->__Vfunc_float_block__DOT__floatEquality__4__float_in1))) 
				      | (((0x7ff00000U 
					   == vlTOPp->__Vfunc_float_block__DOT__floatEquality__4__float_in1) 
					  & (0x7ff00000U 
					     == vlTOPp->__Vfunc_float_block__DOT__floatEquality__4__float_in2)) 
					 | ((0xfff00000U 
					     == vlTOPp->__Vfunc_float_block__DOT__floatEquality__4__float_in1) 
					    & (0xfff00000U 
					       == vlTOPp->__Vfunc_float_block__DOT__floatEquality__4__float_in2)))));
			    vlTOPp->__Vfunc_float_block__DOT__isNan__6__float_in 
				= vlTOPp->__Vfunc_float_block__DOT__floatEquality__4__float_in2;
			    vlTOPp->__Vfunc_float_block__DOT__isNan__6__Vfuncout = 0U;
			    if ((((0x7fffffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__6__float_in) 
				  & (0x7fc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__6__float_in)) 
				 | (0xffc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__6__float_in))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__6__Vfuncout = 1U;
			    }
			    if ((((0x7fbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__6__float_in) 
				  & (0x7f800001U <= vlTOPp->__Vfunc_float_block__DOT__isNan__6__float_in)) 
				 | ((0xffbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__6__float_in) 
				    & (0xff800001U 
				       <= vlTOPp->__Vfunc_float_block__DOT__isNan__6__float_in)))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__6__Vfuncout = 2U;
			    }
			    vlTOPp->__Vfunc_float_block__DOT__isNan__5__float_in 
				= vlTOPp->__Vfunc_float_block__DOT__floatEquality__4__float_in1;
			    vlTOPp->__Vfunc_float_block__DOT__isNan__5__Vfuncout = 0U;
			    if ((((0x7fffffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__5__float_in) 
				  & (0x7fc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__5__float_in)) 
				 | (0xffc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__5__float_in))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__5__Vfuncout = 1U;
			    }
			    if ((((0x7fbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__5__float_in) 
				  & (0x7f800001U <= vlTOPp->__Vfunc_float_block__DOT__isNan__5__float_in)) 
				 | ((0xffbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__5__float_in) 
				    & (0xff800001U 
				       <= vlTOPp->__Vfunc_float_block__DOT__isNan__5__float_in)))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__5__Vfuncout = 2U;
			    }
			    if (((0U < (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__5__Vfuncout)) 
				 | (0U < (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__6__Vfuncout)))) {
				vlTOPp->__Vfunc_float_block__DOT__floatEquality__4__Vfuncout = 0U;
			    }
			    vlTOPp->__Vfunc_float_block__DOT__floatLess__3__float_in2 
				= vlTOPp->float2_i;
			    vlTOPp->__Vfunc_float_block__DOT__floatLess__3__float_in1 
				= vlTOPp->float1_i;
			    vlTOPp->__Vfunc_float_block__DOT__floatLess__3__Vfuncout 
				= (((0xffU & (vlTOPp->__Vfunc_float_block__DOT__floatLess__3__float_in1 
					      >> 0x17U)) 
				    < (0xffU & (vlTOPp->__Vfunc_float_block__DOT__floatLess__3__float_in2 
						>> 0x17U))) 
				   | (((0xffU & (vlTOPp->__Vfunc_float_block__DOT__floatLess__3__float_in1 
						 >> 0x17U)) 
				       == (0xffU & 
					   (vlTOPp->__Vfunc_float_block__DOT__floatLess__3__float_in2 
					    >> 0x17U)))
				       ? ((0x7fffffU 
					   & vlTOPp->__Vfunc_float_block__DOT__floatLess__3__float_in1) 
					  < (0x7fffffU 
					     & vlTOPp->__Vfunc_float_block__DOT__floatLess__3__float_in2))
				       : (0xfff00000U 
					  == vlTOPp->__Vfunc_float_block__DOT__floatLess__3__float_in1)));
			    if (((1U & (vlTOPp->__Vfunc_float_block__DOT__floatLess__3__float_in1 
					>> 0x1fU)) 
				 > (1U & (vlTOPp->__Vfunc_float_block__DOT__floatLess__3__float_in2 
					  >> 0x1fU)))) {
				vlTOPp->__Vfunc_float_block__DOT__floatLess__3__Vfuncout = 1U;
			    } else {
				if (((1U & (vlTOPp->__Vfunc_float_block__DOT__floatLess__3__float_in1 
					    >> 0x1fU)) 
				     < (1U & (vlTOPp->__Vfunc_float_block__DOT__floatLess__3__float_in2 
					      >> 0x1fU)))) {
				    vlTOPp->__Vfunc_float_block__DOT__floatLess__3__Vfuncout = 0U;
				}
			    }
			    vlTOPp->__Vfunc_float_block__DOT__floatEquality__7__float_in2 
				= vlTOPp->__Vfunc_float_block__DOT__floatLess__3__float_in2;
			    vlTOPp->__Vfunc_float_block__DOT__floatEquality__7__float_in1 
				= vlTOPp->__Vfunc_float_block__DOT__floatLess__3__float_in1;
			    vlTOPp->__Vfunc_float_block__DOT__floatEquality__7__Vfuncout 
				= (((((0xffU & (vlTOPp->__Vfunc_float_block__DOT__floatEquality__7__float_in1 
						>> 0x17U)) 
				      == (0xffU & (vlTOPp->__Vfunc_float_block__DOT__floatEquality__7__float_in2 
						   >> 0x17U))) 
				     & ((0x7fffffU 
					 & vlTOPp->__Vfunc_float_block__DOT__floatEquality__7__float_in1) 
					== (0x7fffffU 
					    & vlTOPp->__Vfunc_float_block__DOT__floatEquality__7__float_in2))) 
				    & ((1U & (vlTOPp->__Vfunc_float_block__DOT__floatEquality__7__float_in1 
					      >> 0x1fU)) 
				       == (1U & (vlTOPp->__Vfunc_float_block__DOT__floatEquality__7__float_in2 
						 >> 0x1fU)))) 
				   | ((((0x7fffffffU 
					 & vlTOPp->__Vfunc_float_block__DOT__floatEquality__7__float_in1) 
					== (0x7fffffffU 
					    & vlTOPp->__Vfunc_float_block__DOT__floatEquality__7__float_in2)) 
				       & (0U == (0x7fffffffU 
						 & vlTOPp->__Vfunc_float_block__DOT__floatEquality__7__float_in1))) 
				      | (((0x7ff00000U 
					   == vlTOPp->__Vfunc_float_block__DOT__floatEquality__7__float_in1) 
					  & (0x7ff00000U 
					     == vlTOPp->__Vfunc_float_block__DOT__floatEquality__7__float_in2)) 
					 | ((0xfff00000U 
					     == vlTOPp->__Vfunc_float_block__DOT__floatEquality__7__float_in1) 
					    & (0xfff00000U 
					       == vlTOPp->__Vfunc_float_block__DOT__floatEquality__7__float_in2)))));
			    vlTOPp->__Vfunc_float_block__DOT__isNan__9__float_in 
				= vlTOPp->__Vfunc_float_block__DOT__floatEquality__7__float_in2;
			    vlTOPp->__Vfunc_float_block__DOT__isNan__9__Vfuncout = 0U;
			    if ((((0x7fffffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__9__float_in) 
				  & (0x7fc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__9__float_in)) 
				 | (0xffc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__9__float_in))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__9__Vfuncout = 1U;
			    }
			    if ((((0x7fbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__9__float_in) 
				  & (0x7f800001U <= vlTOPp->__Vfunc_float_block__DOT__isNan__9__float_in)) 
				 | ((0xffbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__9__float_in) 
				    & (0xff800001U 
				       <= vlTOPp->__Vfunc_float_block__DOT__isNan__9__float_in)))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__9__Vfuncout = 2U;
			    }
			    vlTOPp->__Vfunc_float_block__DOT__isNan__8__float_in 
				= vlTOPp->__Vfunc_float_block__DOT__floatEquality__7__float_in1;
			    vlTOPp->__Vfunc_float_block__DOT__isNan__8__Vfuncout = 0U;
			    if ((((0x7fffffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__8__float_in) 
				  & (0x7fc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__8__float_in)) 
				 | (0xffc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__8__float_in))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__8__Vfuncout = 1U;
			    }
			    if ((((0x7fbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__8__float_in) 
				  & (0x7f800001U <= vlTOPp->__Vfunc_float_block__DOT__isNan__8__float_in)) 
				 | ((0xffbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__8__float_in) 
				    & (0xff800001U 
				       <= vlTOPp->__Vfunc_float_block__DOT__isNan__8__float_in)))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__8__Vfuncout = 2U;
			    }
			    if (((0U < (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__8__Vfuncout)) 
				 | (0U < (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__9__Vfuncout)))) {
				vlTOPp->__Vfunc_float_block__DOT__floatEquality__7__Vfuncout = 0U;
			    }
			    if (vlTOPp->__Vfunc_float_block__DOT__floatEquality__7__Vfuncout) {
				vlTOPp->__Vfunc_float_block__DOT__floatLess__3__Vfuncout = 0U;
			    }
			    vlTOPp->__Vfunc_float_block__DOT__isNan__11__float_in 
				= vlTOPp->__Vfunc_float_block__DOT__floatLess__3__float_in2;
			    vlTOPp->__Vfunc_float_block__DOT__isNan__11__Vfuncout = 0U;
			    if ((((0x7fffffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__11__float_in) 
				  & (0x7fc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__11__float_in)) 
				 | (0xffc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__11__float_in))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__11__Vfuncout = 1U;
			    }
			    if ((((0x7fbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__11__float_in) 
				  & (0x7f800001U <= vlTOPp->__Vfunc_float_block__DOT__isNan__11__float_in)) 
				 | ((0xffbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__11__float_in) 
				    & (0xff800001U 
				       <= vlTOPp->__Vfunc_float_block__DOT__isNan__11__float_in)))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__11__Vfuncout = 2U;
			    }
			    vlTOPp->__Vfunc_float_block__DOT__isNan__10__float_in 
				= vlTOPp->__Vfunc_float_block__DOT__floatLess__3__float_in1;
			    vlTOPp->__Vfunc_float_block__DOT__isNan__10__Vfuncout = 0U;
			    if ((((0x7fffffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__10__float_in) 
				  & (0x7fc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__10__float_in)) 
				 | (0xffc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__10__float_in))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__10__Vfuncout = 1U;
			    }
			    if ((((0x7fbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__10__float_in) 
				  & (0x7f800001U <= vlTOPp->__Vfunc_float_block__DOT__isNan__10__float_in)) 
				 | ((0xffbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__10__float_in) 
				    & (0xff800001U 
				       <= vlTOPp->__Vfunc_float_block__DOT__isNan__10__float_in)))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__10__Vfuncout = 2U;
			    }
			    if (((0U < (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__10__Vfuncout)) 
				 | (0U < (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__11__Vfuncout)))) {
				vlTOPp->__Vfunc_float_block__DOT__floatLess__3__Vfuncout = 0U;
			    }
			    vlTOPp->int_o = (QData)((IData)(
							    ((IData)(vlTOPp->__Vfunc_float_block__DOT__floatLess__3__Vfuncout) 
							     | (IData)(vlTOPp->__Vfunc_float_block__DOT__floatEquality__4__Vfuncout))));
			    vlTOPp->done_o = 1U;
			} else {
			    // Function: floatLess at rtl/float_block.v:160
			    // Function: floatEquality at rtl/float_block.v:231
			    // Function: isNan at rtl/float_block.v:204
			    // Function: isNan at rtl/float_block.v:204
			    // Function: isNan at rtl/float_block.v:233
			    // Function: isNan at rtl/float_block.v:233
			    vlTOPp->__Vfunc_float_block__DOT__floatLess__12__float_in2 
				= vlTOPp->float2_i;
			    vlTOPp->__Vfunc_float_block__DOT__floatLess__12__float_in1 
				= vlTOPp->float1_i;
			    vlTOPp->__Vfunc_float_block__DOT__floatLess__12__Vfuncout 
				= (((0xffU & (vlTOPp->__Vfunc_float_block__DOT__floatLess__12__float_in1 
					      >> 0x17U)) 
				    < (0xffU & (vlTOPp->__Vfunc_float_block__DOT__floatLess__12__float_in2 
						>> 0x17U))) 
				   | (((0xffU & (vlTOPp->__Vfunc_float_block__DOT__floatLess__12__float_in1 
						 >> 0x17U)) 
				       == (0xffU & 
					   (vlTOPp->__Vfunc_float_block__DOT__floatLess__12__float_in2 
					    >> 0x17U)))
				       ? ((0x7fffffU 
					   & vlTOPp->__Vfunc_float_block__DOT__floatLess__12__float_in1) 
					  < (0x7fffffU 
					     & vlTOPp->__Vfunc_float_block__DOT__floatLess__12__float_in2))
				       : (0xfff00000U 
					  == vlTOPp->__Vfunc_float_block__DOT__floatLess__12__float_in1)));
			    if (((1U & (vlTOPp->__Vfunc_float_block__DOT__floatLess__12__float_in1 
					>> 0x1fU)) 
				 > (1U & (vlTOPp->__Vfunc_float_block__DOT__floatLess__12__float_in2 
					  >> 0x1fU)))) {
				vlTOPp->__Vfunc_float_block__DOT__floatLess__12__Vfuncout = 1U;
			    } else {
				if (((1U & (vlTOPp->__Vfunc_float_block__DOT__floatLess__12__float_in1 
					    >> 0x1fU)) 
				     < (1U & (vlTOPp->__Vfunc_float_block__DOT__floatLess__12__float_in2 
					      >> 0x1fU)))) {
				    vlTOPp->__Vfunc_float_block__DOT__floatLess__12__Vfuncout = 0U;
				}
			    }
			    vlTOPp->__Vfunc_float_block__DOT__floatEquality__13__float_in2 
				= vlTOPp->__Vfunc_float_block__DOT__floatLess__12__float_in2;
			    vlTOPp->__Vfunc_float_block__DOT__floatEquality__13__float_in1 
				= vlTOPp->__Vfunc_float_block__DOT__floatLess__12__float_in1;
			    vlTOPp->__Vfunc_float_block__DOT__floatEquality__13__Vfuncout 
				= (((((0xffU & (vlTOPp->__Vfunc_float_block__DOT__floatEquality__13__float_in1 
						>> 0x17U)) 
				      == (0xffU & (vlTOPp->__Vfunc_float_block__DOT__floatEquality__13__float_in2 
						   >> 0x17U))) 
				     & ((0x7fffffU 
					 & vlTOPp->__Vfunc_float_block__DOT__floatEquality__13__float_in1) 
					== (0x7fffffU 
					    & vlTOPp->__Vfunc_float_block__DOT__floatEquality__13__float_in2))) 
				    & ((1U & (vlTOPp->__Vfunc_float_block__DOT__floatEquality__13__float_in1 
					      >> 0x1fU)) 
				       == (1U & (vlTOPp->__Vfunc_float_block__DOT__floatEquality__13__float_in2 
						 >> 0x1fU)))) 
				   | ((((0x7fffffffU 
					 & vlTOPp->__Vfunc_float_block__DOT__floatEquality__13__float_in1) 
					== (0x7fffffffU 
					    & vlTOPp->__Vfunc_float_block__DOT__floatEquality__13__float_in2)) 
				       & (0U == (0x7fffffffU 
						 & vlTOPp->__Vfunc_float_block__DOT__floatEquality__13__float_in1))) 
				      | (((0x7ff00000U 
					   == vlTOPp->__Vfunc_float_block__DOT__floatEquality__13__float_in1) 
					  & (0x7ff00000U 
					     == vlTOPp->__Vfunc_float_block__DOT__floatEquality__13__float_in2)) 
					 | ((0xfff00000U 
					     == vlTOPp->__Vfunc_float_block__DOT__floatEquality__13__float_in1) 
					    & (0xfff00000U 
					       == vlTOPp->__Vfunc_float_block__DOT__floatEquality__13__float_in2)))));
			    vlTOPp->__Vfunc_float_block__DOT__isNan__15__float_in 
				= vlTOPp->__Vfunc_float_block__DOT__floatEquality__13__float_in2;
			    vlTOPp->__Vfunc_float_block__DOT__isNan__15__Vfuncout = 0U;
			    if ((((0x7fffffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__15__float_in) 
				  & (0x7fc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__15__float_in)) 
				 | (0xffc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__15__float_in))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__15__Vfuncout = 1U;
			    }
			    if ((((0x7fbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__15__float_in) 
				  & (0x7f800001U <= vlTOPp->__Vfunc_float_block__DOT__isNan__15__float_in)) 
				 | ((0xffbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__15__float_in) 
				    & (0xff800001U 
				       <= vlTOPp->__Vfunc_float_block__DOT__isNan__15__float_in)))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__15__Vfuncout = 2U;
			    }
			    vlTOPp->__Vfunc_float_block__DOT__isNan__14__float_in 
				= vlTOPp->__Vfunc_float_block__DOT__floatEquality__13__float_in1;
			    vlTOPp->__Vfunc_float_block__DOT__isNan__14__Vfuncout = 0U;
			    if ((((0x7fffffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__14__float_in) 
				  & (0x7fc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__14__float_in)) 
				 | (0xffc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__14__float_in))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__14__Vfuncout = 1U;
			    }
			    if ((((0x7fbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__14__float_in) 
				  & (0x7f800001U <= vlTOPp->__Vfunc_float_block__DOT__isNan__14__float_in)) 
				 | ((0xffbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__14__float_in) 
				    & (0xff800001U 
				       <= vlTOPp->__Vfunc_float_block__DOT__isNan__14__float_in)))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__14__Vfuncout = 2U;
			    }
			    if (((0U < (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__14__Vfuncout)) 
				 | (0U < (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__15__Vfuncout)))) {
				vlTOPp->__Vfunc_float_block__DOT__floatEquality__13__Vfuncout = 0U;
			    }
			    if (vlTOPp->__Vfunc_float_block__DOT__floatEquality__13__Vfuncout) {
				vlTOPp->__Vfunc_float_block__DOT__floatLess__12__Vfuncout = 0U;
			    }
			    vlTOPp->__Vfunc_float_block__DOT__isNan__17__float_in 
				= vlTOPp->__Vfunc_float_block__DOT__floatLess__12__float_in2;
			    vlTOPp->__Vfunc_float_block__DOT__isNan__17__Vfuncout = 0U;
			    if ((((0x7fffffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__17__float_in) 
				  & (0x7fc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__17__float_in)) 
				 | (0xffc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__17__float_in))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__17__Vfuncout = 1U;
			    }
			    if ((((0x7fbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__17__float_in) 
				  & (0x7f800001U <= vlTOPp->__Vfunc_float_block__DOT__isNan__17__float_in)) 
				 | ((0xffbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__17__float_in) 
				    & (0xff800001U 
				       <= vlTOPp->__Vfunc_float_block__DOT__isNan__17__float_in)))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__17__Vfuncout = 2U;
			    }
			    vlTOPp->__Vfunc_float_block__DOT__isNan__16__float_in 
				= vlTOPp->__Vfunc_float_block__DOT__floatLess__12__float_in1;
			    vlTOPp->__Vfunc_float_block__DOT__isNan__16__Vfuncout = 0U;
			    if ((((0x7fffffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__16__float_in) 
				  & (0x7fc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__16__float_in)) 
				 | (0xffc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__16__float_in))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__16__Vfuncout = 1U;
			    }
			    if ((((0x7fbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__16__float_in) 
				  & (0x7f800001U <= vlTOPp->__Vfunc_float_block__DOT__isNan__16__float_in)) 
				 | ((0xffbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__16__float_in) 
				    & (0xff800001U 
				       <= vlTOPp->__Vfunc_float_block__DOT__isNan__16__float_in)))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__16__Vfuncout = 2U;
			    }
			    if (((0U < (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__16__Vfuncout)) 
				 | (0U < (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__17__Vfuncout)))) {
				vlTOPp->__Vfunc_float_block__DOT__floatLess__12__Vfuncout = 0U;
			    }
			    vlTOPp->int_o = (QData)((IData)(vlTOPp->__Vfunc_float_block__DOT__floatLess__12__Vfuncout));
			    vlTOPp->done_o = 1U;
			}
		    }
		} else {
		    if ((2U & (IData)(vlTOPp->opcode_i))) {
			if ((1U & (IData)(vlTOPp->opcode_i))) {
			    // Function: floatEquality at rtl/float_block.v:156
			    // Function: isNan at rtl/float_block.v:204
			    // Function: isNan at rtl/float_block.v:204
			    vlTOPp->__Vfunc_float_block__DOT__floatEquality__18__float_in2 
				= vlTOPp->float2_i;
			    vlTOPp->__Vfunc_float_block__DOT__floatEquality__18__float_in1 
				= vlTOPp->float1_i;
			    vlTOPp->__Vfunc_float_block__DOT__floatEquality__18__Vfuncout 
				= (((((0xffU & (vlTOPp->__Vfunc_float_block__DOT__floatEquality__18__float_in1 
						>> 0x17U)) 
				      == (0xffU & (vlTOPp->__Vfunc_float_block__DOT__floatEquality__18__float_in2 
						   >> 0x17U))) 
				     & ((0x7fffffU 
					 & vlTOPp->__Vfunc_float_block__DOT__floatEquality__18__float_in1) 
					== (0x7fffffU 
					    & vlTOPp->__Vfunc_float_block__DOT__floatEquality__18__float_in2))) 
				    & ((1U & (vlTOPp->__Vfunc_float_block__DOT__floatEquality__18__float_in1 
					      >> 0x1fU)) 
				       == (1U & (vlTOPp->__Vfunc_float_block__DOT__floatEquality__18__float_in2 
						 >> 0x1fU)))) 
				   | ((((0x7fffffffU 
					 & vlTOPp->__Vfunc_float_block__DOT__floatEquality__18__float_in1) 
					== (0x7fffffffU 
					    & vlTOPp->__Vfunc_float_block__DOT__floatEquality__18__float_in2)) 
				       & (0U == (0x7fffffffU 
						 & vlTOPp->__Vfunc_float_block__DOT__floatEquality__18__float_in1))) 
				      | (((0x7ff00000U 
					   == vlTOPp->__Vfunc_float_block__DOT__floatEquality__18__float_in1) 
					  & (0x7ff00000U 
					     == vlTOPp->__Vfunc_float_block__DOT__floatEquality__18__float_in2)) 
					 | ((0xfff00000U 
					     == vlTOPp->__Vfunc_float_block__DOT__floatEquality__18__float_in1) 
					    & (0xfff00000U 
					       == vlTOPp->__Vfunc_float_block__DOT__floatEquality__18__float_in2)))));
			    vlTOPp->__Vfunc_float_block__DOT__isNan__20__float_in 
				= vlTOPp->__Vfunc_float_block__DOT__floatEquality__18__float_in2;
			    vlTOPp->__Vfunc_float_block__DOT__isNan__20__Vfuncout = 0U;
			    if ((((0x7fffffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__20__float_in) 
				  & (0x7fc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__20__float_in)) 
				 | (0xffc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__20__float_in))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__20__Vfuncout = 1U;
			    }
			    if ((((0x7fbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__20__float_in) 
				  & (0x7f800001U <= vlTOPp->__Vfunc_float_block__DOT__isNan__20__float_in)) 
				 | ((0xffbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__20__float_in) 
				    & (0xff800001U 
				       <= vlTOPp->__Vfunc_float_block__DOT__isNan__20__float_in)))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__20__Vfuncout = 2U;
			    }
			    vlTOPp->__Vfunc_float_block__DOT__isNan__19__float_in 
				= vlTOPp->__Vfunc_float_block__DOT__floatEquality__18__float_in1;
			    vlTOPp->__Vfunc_float_block__DOT__isNan__19__Vfuncout = 0U;
			    if ((((0x7fffffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__19__float_in) 
				  & (0x7fc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__19__float_in)) 
				 | (0xffc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__19__float_in))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__19__Vfuncout = 1U;
			    }
			    if ((((0x7fbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__19__float_in) 
				  & (0x7f800001U <= vlTOPp->__Vfunc_float_block__DOT__isNan__19__float_in)) 
				 | ((0xffbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__19__float_in) 
				    & (0xff800001U 
				       <= vlTOPp->__Vfunc_float_block__DOT__isNan__19__float_in)))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__19__Vfuncout = 2U;
			    }
			    if (((0U < (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__19__Vfuncout)) 
				 | (0U < (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__20__Vfuncout)))) {
				vlTOPp->__Vfunc_float_block__DOT__floatEquality__18__Vfuncout = 0U;
			    }
			    vlTOPp->int_o = (QData)((IData)(vlTOPp->__Vfunc_float_block__DOT__floatEquality__18__Vfuncout));
			    vlTOPp->done_o = 1U;
			}
		    }
		}
	    }
	} else {
	    if ((8U & (IData)(vlTOPp->opcode_i))) {
		if ((4U & (IData)(vlTOPp->opcode_i))) {
		    if ((2U & (IData)(vlTOPp->opcode_i))) {
			if ((1U & (IData)(vlTOPp->opcode_i))) {
			    // Function: maxFloat at rtl/float_block.v:146
			    // Function: minFloat at rtl/float_block.v:417
			    // Function: floatEquality at rtl/float_block.v:440
			    // Function: floatLess at rtl/float_block.v:442
			    // Function: floatEquality at rtl/float_block.v:231
			    // Function: isNan at rtl/float_block.v:204
			    // Function: isNan at rtl/float_block.v:204
			    // Function: isNan at rtl/float_block.v:233
			    // Function: isNan at rtl/float_block.v:233
			    // Function: isNan at rtl/float_block.v:204
			    // Function: isNan at rtl/float_block.v:204
			    // Function: isNan at rtl/float_block.v:447
			    // Function: isNan at rtl/float_block.v:447
			    // Function: isNan at rtl/float_block.v:422
			    // Function: isNan at rtl/float_block.v:422
			    vlTOPp->__Vfunc_float_block__DOT__maxFloat__21__float_in2 
				= vlTOPp->float2_i;
			    vlTOPp->__Vfunc_float_block__DOT__maxFloat__21__float_in1 
				= vlTOPp->float1_i;
			    vlTOPp->__Vfunc_float_block__DOT__minFloat__22__float_in2 
				= vlTOPp->__Vfunc_float_block__DOT__maxFloat__21__float_in2;
			    vlTOPp->__Vfunc_float_block__DOT__minFloat__22__float_in1 
				= vlTOPp->__Vfunc_float_block__DOT__maxFloat__21__float_in1;
			    vlTOPp->__Vfunc_float_block__DOT__floatLess__24__float_in2 
				= vlTOPp->__Vfunc_float_block__DOT__minFloat__22__float_in2;
			    vlTOPp->__Vfunc_float_block__DOT__floatLess__24__float_in1 
				= vlTOPp->__Vfunc_float_block__DOT__minFloat__22__float_in1;
			    vlTOPp->__Vfunc_float_block__DOT__floatLess__24__Vfuncout 
				= (((0xffU & (vlTOPp->__Vfunc_float_block__DOT__floatLess__24__float_in1 
					      >> 0x17U)) 
				    < (0xffU & (vlTOPp->__Vfunc_float_block__DOT__floatLess__24__float_in2 
						>> 0x17U))) 
				   | (((0xffU & (vlTOPp->__Vfunc_float_block__DOT__floatLess__24__float_in1 
						 >> 0x17U)) 
				       == (0xffU & 
					   (vlTOPp->__Vfunc_float_block__DOT__floatLess__24__float_in2 
					    >> 0x17U)))
				       ? ((0x7fffffU 
					   & vlTOPp->__Vfunc_float_block__DOT__floatLess__24__float_in1) 
					  < (0x7fffffU 
					     & vlTOPp->__Vfunc_float_block__DOT__floatLess__24__float_in2))
				       : (0xfff00000U 
					  == vlTOPp->__Vfunc_float_block__DOT__floatLess__24__float_in1)));
			    if (((1U & (vlTOPp->__Vfunc_float_block__DOT__floatLess__24__float_in1 
					>> 0x1fU)) 
				 > (1U & (vlTOPp->__Vfunc_float_block__DOT__floatLess__24__float_in2 
					  >> 0x1fU)))) {
				vlTOPp->__Vfunc_float_block__DOT__floatLess__24__Vfuncout = 1U;
			    } else {
				if (((1U & (vlTOPp->__Vfunc_float_block__DOT__floatLess__24__float_in1 
					    >> 0x1fU)) 
				     < (1U & (vlTOPp->__Vfunc_float_block__DOT__floatLess__24__float_in2 
					      >> 0x1fU)))) {
				    vlTOPp->__Vfunc_float_block__DOT__floatLess__24__Vfuncout = 0U;
				}
			    }
			    vlTOPp->__Vfunc_float_block__DOT__floatEquality__25__float_in2 
				= vlTOPp->__Vfunc_float_block__DOT__floatLess__24__float_in2;
			    vlTOPp->__Vfunc_float_block__DOT__floatEquality__25__float_in1 
				= vlTOPp->__Vfunc_float_block__DOT__floatLess__24__float_in1;
			    vlTOPp->__Vfunc_float_block__DOT__floatEquality__25__Vfuncout 
				= (((((0xffU & (vlTOPp->__Vfunc_float_block__DOT__floatEquality__25__float_in1 
						>> 0x17U)) 
				      == (0xffU & (vlTOPp->__Vfunc_float_block__DOT__floatEquality__25__float_in2 
						   >> 0x17U))) 
				     & ((0x7fffffU 
					 & vlTOPp->__Vfunc_float_block__DOT__floatEquality__25__float_in1) 
					== (0x7fffffU 
					    & vlTOPp->__Vfunc_float_block__DOT__floatEquality__25__float_in2))) 
				    & ((1U & (vlTOPp->__Vfunc_float_block__DOT__floatEquality__25__float_in1 
					      >> 0x1fU)) 
				       == (1U & (vlTOPp->__Vfunc_float_block__DOT__floatEquality__25__float_in2 
						 >> 0x1fU)))) 
				   | ((((0x7fffffffU 
					 & vlTOPp->__Vfunc_float_block__DOT__floatEquality__25__float_in1) 
					== (0x7fffffffU 
					    & vlTOPp->__Vfunc_float_block__DOT__floatEquality__25__float_in2)) 
				       & (0U == (0x7fffffffU 
						 & vlTOPp->__Vfunc_float_block__DOT__floatEquality__25__float_in1))) 
				      | (((0x7ff00000U 
					   == vlTOPp->__Vfunc_float_block__DOT__floatEquality__25__float_in1) 
					  & (0x7ff00000U 
					     == vlTOPp->__Vfunc_float_block__DOT__floatEquality__25__float_in2)) 
					 | ((0xfff00000U 
					     == vlTOPp->__Vfunc_float_block__DOT__floatEquality__25__float_in1) 
					    & (0xfff00000U 
					       == vlTOPp->__Vfunc_float_block__DOT__floatEquality__25__float_in2)))));
			    vlTOPp->__Vfunc_float_block__DOT__isNan__27__float_in 
				= vlTOPp->__Vfunc_float_block__DOT__floatEquality__25__float_in2;
			    vlTOPp->__Vfunc_float_block__DOT__isNan__27__Vfuncout = 0U;
			    if ((((0x7fffffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__27__float_in) 
				  & (0x7fc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__27__float_in)) 
				 | (0xffc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__27__float_in))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__27__Vfuncout = 1U;
			    }
			    if ((((0x7fbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__27__float_in) 
				  & (0x7f800001U <= vlTOPp->__Vfunc_float_block__DOT__isNan__27__float_in)) 
				 | ((0xffbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__27__float_in) 
				    & (0xff800001U 
				       <= vlTOPp->__Vfunc_float_block__DOT__isNan__27__float_in)))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__27__Vfuncout = 2U;
			    }
			    vlTOPp->__Vfunc_float_block__DOT__isNan__26__float_in 
				= vlTOPp->__Vfunc_float_block__DOT__floatEquality__25__float_in1;
			    vlTOPp->__Vfunc_float_block__DOT__isNan__26__Vfuncout = 0U;
			    if ((((0x7fffffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__26__float_in) 
				  & (0x7fc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__26__float_in)) 
				 | (0xffc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__26__float_in))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__26__Vfuncout = 1U;
			    }
			    if ((((0x7fbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__26__float_in) 
				  & (0x7f800001U <= vlTOPp->__Vfunc_float_block__DOT__isNan__26__float_in)) 
				 | ((0xffbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__26__float_in) 
				    & (0xff800001U 
				       <= vlTOPp->__Vfunc_float_block__DOT__isNan__26__float_in)))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__26__Vfuncout = 2U;
			    }
			    if (((0U < (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__26__Vfuncout)) 
				 | (0U < (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__27__Vfuncout)))) {
				vlTOPp->__Vfunc_float_block__DOT__floatEquality__25__Vfuncout = 0U;
			    }
			    if (vlTOPp->__Vfunc_float_block__DOT__floatEquality__25__Vfuncout) {
				vlTOPp->__Vfunc_float_block__DOT__floatLess__24__Vfuncout = 0U;
			    }
			    vlTOPp->__Vfunc_float_block__DOT__isNan__29__float_in 
				= vlTOPp->__Vfunc_float_block__DOT__floatLess__24__float_in2;
			    vlTOPp->__Vfunc_float_block__DOT__isNan__29__Vfuncout = 0U;
			    if ((((0x7fffffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__29__float_in) 
				  & (0x7fc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__29__float_in)) 
				 | (0xffc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__29__float_in))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__29__Vfuncout = 1U;
			    }
			    if ((((0x7fbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__29__float_in) 
				  & (0x7f800001U <= vlTOPp->__Vfunc_float_block__DOT__isNan__29__float_in)) 
				 | ((0xffbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__29__float_in) 
				    & (0xff800001U 
				       <= vlTOPp->__Vfunc_float_block__DOT__isNan__29__float_in)))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__29__Vfuncout = 2U;
			    }
			    vlTOPp->__Vfunc_float_block__DOT__isNan__28__float_in 
				= vlTOPp->__Vfunc_float_block__DOT__floatLess__24__float_in1;
			    vlTOPp->__Vfunc_float_block__DOT__isNan__28__Vfuncout = 0U;
			    if ((((0x7fffffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__28__float_in) 
				  & (0x7fc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__28__float_in)) 
				 | (0xffc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__28__float_in))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__28__Vfuncout = 1U;
			    }
			    if ((((0x7fbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__28__float_in) 
				  & (0x7f800001U <= vlTOPp->__Vfunc_float_block__DOT__isNan__28__float_in)) 
				 | ((0xffbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__28__float_in) 
				    & (0xff800001U 
				       <= vlTOPp->__Vfunc_float_block__DOT__isNan__28__float_in)))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__28__Vfuncout = 2U;
			    }
			    if (((0U < (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__28__Vfuncout)) 
				 | (0U < (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__29__Vfuncout)))) {
				vlTOPp->__Vfunc_float_block__DOT__floatLess__24__Vfuncout = 0U;
			    }
			    vlTOPp->__Vfunc_float_block__DOT__floatEquality__23__float_in2 
				= vlTOPp->__Vfunc_float_block__DOT__minFloat__22__float_in2;
			    vlTOPp->__Vfunc_float_block__DOT__floatEquality__23__float_in1 
				= vlTOPp->__Vfunc_float_block__DOT__minFloat__22__float_in1;
			    vlTOPp->__Vfunc_float_block__DOT__floatEquality__23__Vfuncout 
				= (((((0xffU & (vlTOPp->__Vfunc_float_block__DOT__floatEquality__23__float_in1 
						>> 0x17U)) 
				      == (0xffU & (vlTOPp->__Vfunc_float_block__DOT__floatEquality__23__float_in2 
						   >> 0x17U))) 
				     & ((0x7fffffU 
					 & vlTOPp->__Vfunc_float_block__DOT__floatEquality__23__float_in1) 
					== (0x7fffffU 
					    & vlTOPp->__Vfunc_float_block__DOT__floatEquality__23__float_in2))) 
				    & ((1U & (vlTOPp->__Vfunc_float_block__DOT__floatEquality__23__float_in1 
					      >> 0x1fU)) 
				       == (1U & (vlTOPp->__Vfunc_float_block__DOT__floatEquality__23__float_in2 
						 >> 0x1fU)))) 
				   | ((((0x7fffffffU 
					 & vlTOPp->__Vfunc_float_block__DOT__floatEquality__23__float_in1) 
					== (0x7fffffffU 
					    & vlTOPp->__Vfunc_float_block__DOT__floatEquality__23__float_in2)) 
				       & (0U == (0x7fffffffU 
						 & vlTOPp->__Vfunc_float_block__DOT__floatEquality__23__float_in1))) 
				      | (((0x7ff00000U 
					   == vlTOPp->__Vfunc_float_block__DOT__floatEquality__23__float_in1) 
					  & (0x7ff00000U 
					     == vlTOPp->__Vfunc_float_block__DOT__floatEquality__23__float_in2)) 
					 | ((0xfff00000U 
					     == vlTOPp->__Vfunc_float_block__DOT__floatEquality__23__float_in1) 
					    & (0xfff00000U 
					       == vlTOPp->__Vfunc_float_block__DOT__floatEquality__23__float_in2)))));
			    vlTOPp->__Vfunc_float_block__DOT__isNan__31__float_in 
				= vlTOPp->__Vfunc_float_block__DOT__floatEquality__23__float_in2;
			    vlTOPp->__Vfunc_float_block__DOT__isNan__31__Vfuncout = 0U;
			    if ((((0x7fffffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__31__float_in) 
				  & (0x7fc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__31__float_in)) 
				 | (0xffc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__31__float_in))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__31__Vfuncout = 1U;
			    }
			    if ((((0x7fbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__31__float_in) 
				  & (0x7f800001U <= vlTOPp->__Vfunc_float_block__DOT__isNan__31__float_in)) 
				 | ((0xffbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__31__float_in) 
				    & (0xff800001U 
				       <= vlTOPp->__Vfunc_float_block__DOT__isNan__31__float_in)))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__31__Vfuncout = 2U;
			    }
			    vlTOPp->__Vfunc_float_block__DOT__isNan__30__float_in 
				= vlTOPp->__Vfunc_float_block__DOT__floatEquality__23__float_in1;
			    vlTOPp->__Vfunc_float_block__DOT__isNan__30__Vfuncout = 0U;
			    if ((((0x7fffffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__30__float_in) 
				  & (0x7fc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__30__float_in)) 
				 | (0xffc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__30__float_in))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__30__Vfuncout = 1U;
			    }
			    if ((((0x7fbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__30__float_in) 
				  & (0x7f800001U <= vlTOPp->__Vfunc_float_block__DOT__isNan__30__float_in)) 
				 | ((0xffbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__30__float_in) 
				    & (0xff800001U 
				       <= vlTOPp->__Vfunc_float_block__DOT__isNan__30__float_in)))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__30__Vfuncout = 2U;
			    }
			    if (((0U < (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__30__Vfuncout)) 
				 | (0U < (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__31__Vfuncout)))) {
				vlTOPp->__Vfunc_float_block__DOT__floatEquality__23__Vfuncout = 0U;
			    }
			    vlTOPp->__Vfunc_float_block__DOT__minFloat__22__Vfuncout 
				= ((IData)(vlTOPp->__Vfunc_float_block__DOT__floatEquality__23__Vfuncout)
				    ? vlTOPp->__Vfunc_float_block__DOT__minFloat__22__float_in1
				    : ((IData)(vlTOPp->__Vfunc_float_block__DOT__floatLess__24__Vfuncout)
				        ? vlTOPp->__Vfunc_float_block__DOT__minFloat__22__float_in1
				        : vlTOPp->__Vfunc_float_block__DOT__minFloat__22__float_in2));
			    vlTOPp->__Vfunc_float_block__DOT__isNan__33__float_in 
				= vlTOPp->__Vfunc_float_block__DOT__minFloat__22__float_in2;
			    vlTOPp->__Vfunc_float_block__DOT__isNan__33__Vfuncout = 0U;
			    if ((((0x7fffffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__33__float_in) 
				  & (0x7fc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__33__float_in)) 
				 | (0xffc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__33__float_in))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__33__Vfuncout = 1U;
			    }
			    if ((((0x7fbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__33__float_in) 
				  & (0x7f800001U <= vlTOPp->__Vfunc_float_block__DOT__isNan__33__float_in)) 
				 | ((0xffbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__33__float_in) 
				    & (0xff800001U 
				       <= vlTOPp->__Vfunc_float_block__DOT__isNan__33__float_in)))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__33__Vfuncout = 2U;
			    }
			    vlTOPp->__Vfunc_float_block__DOT__isNan__32__float_in 
				= vlTOPp->__Vfunc_float_block__DOT__minFloat__22__float_in1;
			    vlTOPp->__Vfunc_float_block__DOT__isNan__32__Vfuncout = 0U;
			    if ((((0x7fffffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__32__float_in) 
				  & (0x7fc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__32__float_in)) 
				 | (0xffc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__32__float_in))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__32__Vfuncout = 1U;
			    }
			    if ((((0x7fbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__32__float_in) 
				  & (0x7f800001U <= vlTOPp->__Vfunc_float_block__DOT__isNan__32__float_in)) 
				 | ((0xffbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__32__float_in) 
				    & (0xff800001U 
				       <= vlTOPp->__Vfunc_float_block__DOT__isNan__32__float_in)))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__32__Vfuncout = 2U;
			    }
			    if (((2U == (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__32__Vfuncout)) 
				 | (2U == (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__33__Vfuncout)))) {
				vlTOPp->__Vfunc_float_block__DOT__minFloat__22__Vfuncout = 0x7fc00000U;
			    } else {
				// Function: isNan at rtl/float_block.v:449
				// Function: isNan at rtl/float_block.v:449
				vlTOPp->__Vfunc_float_block__DOT__isNan__35__float_in 
				    = vlTOPp->__Vfunc_float_block__DOT__minFloat__22__float_in2;
				vlTOPp->__Vfunc_float_block__DOT__isNan__35__Vfuncout = 0U;
				if ((((0x7fffffffU 
				       >= vlTOPp->__Vfunc_float_block__DOT__isNan__35__float_in) 
				      & (0x7fc00000U 
					 <= vlTOPp->__Vfunc_float_block__DOT__isNan__35__float_in)) 
				     | (0xffc00000U 
					<= vlTOPp->__Vfunc_float_block__DOT__isNan__35__float_in))) {
				    vlTOPp->__Vfunc_float_block__DOT__isNan__35__Vfuncout = 1U;
				}
				if ((((0x7fbfffffU 
				       >= vlTOPp->__Vfunc_float_block__DOT__isNan__35__float_in) 
				      & (0x7f800001U 
					 <= vlTOPp->__Vfunc_float_block__DOT__isNan__35__float_in)) 
				     | ((0xffbfffffU 
					 >= vlTOPp->__Vfunc_float_block__DOT__isNan__35__float_in) 
					& (0xff800001U 
					   <= vlTOPp->__Vfunc_float_block__DOT__isNan__35__float_in)))) {
				    vlTOPp->__Vfunc_float_block__DOT__isNan__35__Vfuncout = 2U;
				}
				vlTOPp->__Vfunc_float_block__DOT__isNan__34__float_in 
				    = vlTOPp->__Vfunc_float_block__DOT__minFloat__22__float_in1;
				vlTOPp->__Vfunc_float_block__DOT__isNan__34__Vfuncout = 0U;
				if ((((0x7fffffffU 
				       >= vlTOPp->__Vfunc_float_block__DOT__isNan__34__float_in) 
				      & (0x7fc00000U 
					 <= vlTOPp->__Vfunc_float_block__DOT__isNan__34__float_in)) 
				     | (0xffc00000U 
					<= vlTOPp->__Vfunc_float_block__DOT__isNan__34__float_in))) {
				    vlTOPp->__Vfunc_float_block__DOT__isNan__34__Vfuncout = 1U;
				}
				if ((((0x7fbfffffU 
				       >= vlTOPp->__Vfunc_float_block__DOT__isNan__34__float_in) 
				      & (0x7f800001U 
					 <= vlTOPp->__Vfunc_float_block__DOT__isNan__34__float_in)) 
				     | ((0xffbfffffU 
					 >= vlTOPp->__Vfunc_float_block__DOT__isNan__34__float_in) 
					& (0xff800001U 
					   <= vlTOPp->__Vfunc_float_block__DOT__isNan__34__float_in)))) {
				    vlTOPp->__Vfunc_float_block__DOT__isNan__34__Vfuncout = 2U;
				}
				if (((1U == (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__34__Vfuncout)) 
				     & (1U == (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__35__Vfuncout)))) {
				    vlTOPp->__Vfunc_float_block__DOT__minFloat__22__Vfuncout = 0x7fc00000U;
				} else {
				    // Function: isNan at rtl/float_block.v:451
				    // Function: isNan at rtl/float_block.v:451
				    vlTOPp->__Vfunc_float_block__DOT__isNan__37__float_in 
					= vlTOPp->__Vfunc_float_block__DOT__minFloat__22__float_in2;
				    vlTOPp->__Vfunc_float_block__DOT__isNan__37__Vfuncout = 0U;
				    if ((((0x7fffffffU 
					   >= vlTOPp->__Vfunc_float_block__DOT__isNan__37__float_in) 
					  & (0x7fc00000U 
					     <= vlTOPp->__Vfunc_float_block__DOT__isNan__37__float_in)) 
					 | (0xffc00000U 
					    <= vlTOPp->__Vfunc_float_block__DOT__isNan__37__float_in))) {
					vlTOPp->__Vfunc_float_block__DOT__isNan__37__Vfuncout = 1U;
				    }
				    if ((((0x7fbfffffU 
					   >= vlTOPp->__Vfunc_float_block__DOT__isNan__37__float_in) 
					  & (0x7f800001U 
					     <= vlTOPp->__Vfunc_float_block__DOT__isNan__37__float_in)) 
					 | ((0xffbfffffU 
					     >= vlTOPp->__Vfunc_float_block__DOT__isNan__37__float_in) 
					    & (0xff800001U 
					       <= vlTOPp->__Vfunc_float_block__DOT__isNan__37__float_in)))) {
					vlTOPp->__Vfunc_float_block__DOT__isNan__37__Vfuncout = 2U;
				    }
				    vlTOPp->__Vfunc_float_block__DOT__isNan__36__float_in 
					= vlTOPp->__Vfunc_float_block__DOT__minFloat__22__float_in1;
				    vlTOPp->__Vfunc_float_block__DOT__isNan__36__Vfuncout = 0U;
				    if ((((0x7fffffffU 
					   >= vlTOPp->__Vfunc_float_block__DOT__isNan__36__float_in) 
					  & (0x7fc00000U 
					     <= vlTOPp->__Vfunc_float_block__DOT__isNan__36__float_in)) 
					 | (0xffc00000U 
					    <= vlTOPp->__Vfunc_float_block__DOT__isNan__36__float_in))) {
					vlTOPp->__Vfunc_float_block__DOT__isNan__36__Vfuncout = 1U;
				    }
				    if ((((0x7fbfffffU 
					   >= vlTOPp->__Vfunc_float_block__DOT__isNan__36__float_in) 
					  & (0x7f800001U 
					     <= vlTOPp->__Vfunc_float_block__DOT__isNan__36__float_in)) 
					 | ((0xffbfffffU 
					     >= vlTOPp->__Vfunc_float_block__DOT__isNan__36__float_in) 
					    & (0xff800001U 
					       <= vlTOPp->__Vfunc_float_block__DOT__isNan__36__float_in)))) {
					vlTOPp->__Vfunc_float_block__DOT__isNan__36__Vfuncout = 2U;
				    }
				    if (((1U == (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__36__Vfuncout)) 
					 ^ (1U == (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__37__Vfuncout)))) {
					// Function: isNan at rtl/float_block.v:452
					vlTOPp->__Vfunc_float_block__DOT__isNan__38__float_in 
					    = vlTOPp->__Vfunc_float_block__DOT__minFloat__22__float_in1;
					vlTOPp->__Vfunc_float_block__DOT__isNan__38__Vfuncout = 0U;
					if ((((0x7fffffffU 
					       >= vlTOPp->__Vfunc_float_block__DOT__isNan__38__float_in) 
					      & (0x7fc00000U 
						 <= vlTOPp->__Vfunc_float_block__DOT__isNan__38__float_in)) 
					     | (0xffc00000U 
						<= vlTOPp->__Vfunc_float_block__DOT__isNan__38__float_in))) {
					    vlTOPp->__Vfunc_float_block__DOT__isNan__38__Vfuncout = 1U;
					}
					if ((((0x7fbfffffU 
					       >= vlTOPp->__Vfunc_float_block__DOT__isNan__38__float_in) 
					      & (0x7f800001U 
						 <= vlTOPp->__Vfunc_float_block__DOT__isNan__38__float_in)) 
					     | ((0xffbfffffU 
						 >= vlTOPp->__Vfunc_float_block__DOT__isNan__38__float_in) 
						& (0xff800001U 
						   <= vlTOPp->__Vfunc_float_block__DOT__isNan__38__float_in)))) {
					    vlTOPp->__Vfunc_float_block__DOT__isNan__38__Vfuncout = 2U;
					}
					vlTOPp->__Vfunc_float_block__DOT__minFloat__22__Vfuncout 
					    = ((1U 
						== (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__38__Vfuncout))
					        ? vlTOPp->__Vfunc_float_block__DOT__minFloat__22__float_in2
					        : vlTOPp->__Vfunc_float_block__DOT__minFloat__22__float_in1);
				    }
				}
			    }
			    vlTOPp->__Vfunc_float_block__DOT__maxFloat__21__Vfuncout 
				= ((vlTOPp->__Vfunc_float_block__DOT__minFloat__22__Vfuncout 
				    == vlTOPp->__Vfunc_float_block__DOT__maxFloat__21__float_in1)
				    ? vlTOPp->__Vfunc_float_block__DOT__maxFloat__21__float_in2
				    : vlTOPp->__Vfunc_float_block__DOT__maxFloat__21__float_in1);
			    vlTOPp->__Vfunc_float_block__DOT__isNan__40__float_in 
				= vlTOPp->__Vfunc_float_block__DOT__maxFloat__21__float_in2;
			    vlTOPp->__Vfunc_float_block__DOT__isNan__40__Vfuncout = 0U;
			    if ((((0x7fffffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__40__float_in) 
				  & (0x7fc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__40__float_in)) 
				 | (0xffc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__40__float_in))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__40__Vfuncout = 1U;
			    }
			    if ((((0x7fbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__40__float_in) 
				  & (0x7f800001U <= vlTOPp->__Vfunc_float_block__DOT__isNan__40__float_in)) 
				 | ((0xffbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__40__float_in) 
				    & (0xff800001U 
				       <= vlTOPp->__Vfunc_float_block__DOT__isNan__40__float_in)))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__40__Vfuncout = 2U;
			    }
			    vlTOPp->__Vfunc_float_block__DOT__isNan__39__float_in 
				= vlTOPp->__Vfunc_float_block__DOT__maxFloat__21__float_in1;
			    vlTOPp->__Vfunc_float_block__DOT__isNan__39__Vfuncout = 0U;
			    if ((((0x7fffffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__39__float_in) 
				  & (0x7fc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__39__float_in)) 
				 | (0xffc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__39__float_in))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__39__Vfuncout = 1U;
			    }
			    if ((((0x7fbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__39__float_in) 
				  & (0x7f800001U <= vlTOPp->__Vfunc_float_block__DOT__isNan__39__float_in)) 
				 | ((0xffbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__39__float_in) 
				    & (0xff800001U 
				       <= vlTOPp->__Vfunc_float_block__DOT__isNan__39__float_in)))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__39__Vfuncout = 2U;
			    }
			    if (((2U == (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__39__Vfuncout)) 
				 | (2U == (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__40__Vfuncout)))) {
				vlTOPp->__Vfunc_float_block__DOT__maxFloat__21__Vfuncout = 0x7fc00000U;
			    } else {
				// Function: isNan at rtl/float_block.v:424
				// Function: isNan at rtl/float_block.v:424
				vlTOPp->__Vfunc_float_block__DOT__isNan__42__float_in 
				    = vlTOPp->__Vfunc_float_block__DOT__maxFloat__21__float_in2;
				vlTOPp->__Vfunc_float_block__DOT__isNan__42__Vfuncout = 0U;
				if ((((0x7fffffffU 
				       >= vlTOPp->__Vfunc_float_block__DOT__isNan__42__float_in) 
				      & (0x7fc00000U 
					 <= vlTOPp->__Vfunc_float_block__DOT__isNan__42__float_in)) 
				     | (0xffc00000U 
					<= vlTOPp->__Vfunc_float_block__DOT__isNan__42__float_in))) {
				    vlTOPp->__Vfunc_float_block__DOT__isNan__42__Vfuncout = 1U;
				}
				if ((((0x7fbfffffU 
				       >= vlTOPp->__Vfunc_float_block__DOT__isNan__42__float_in) 
				      & (0x7f800001U 
					 <= vlTOPp->__Vfunc_float_block__DOT__isNan__42__float_in)) 
				     | ((0xffbfffffU 
					 >= vlTOPp->__Vfunc_float_block__DOT__isNan__42__float_in) 
					& (0xff800001U 
					   <= vlTOPp->__Vfunc_float_block__DOT__isNan__42__float_in)))) {
				    vlTOPp->__Vfunc_float_block__DOT__isNan__42__Vfuncout = 2U;
				}
				vlTOPp->__Vfunc_float_block__DOT__isNan__41__float_in 
				    = vlTOPp->__Vfunc_float_block__DOT__maxFloat__21__float_in1;
				vlTOPp->__Vfunc_float_block__DOT__isNan__41__Vfuncout = 0U;
				if ((((0x7fffffffU 
				       >= vlTOPp->__Vfunc_float_block__DOT__isNan__41__float_in) 
				      & (0x7fc00000U 
					 <= vlTOPp->__Vfunc_float_block__DOT__isNan__41__float_in)) 
				     | (0xffc00000U 
					<= vlTOPp->__Vfunc_float_block__DOT__isNan__41__float_in))) {
				    vlTOPp->__Vfunc_float_block__DOT__isNan__41__Vfuncout = 1U;
				}
				if ((((0x7fbfffffU 
				       >= vlTOPp->__Vfunc_float_block__DOT__isNan__41__float_in) 
				      & (0x7f800001U 
					 <= vlTOPp->__Vfunc_float_block__DOT__isNan__41__float_in)) 
				     | ((0xffbfffffU 
					 >= vlTOPp->__Vfunc_float_block__DOT__isNan__41__float_in) 
					& (0xff800001U 
					   <= vlTOPp->__Vfunc_float_block__DOT__isNan__41__float_in)))) {
				    vlTOPp->__Vfunc_float_block__DOT__isNan__41__Vfuncout = 2U;
				}
				if (((1U == (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__41__Vfuncout)) 
				     & (1U == (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__42__Vfuncout)))) {
				    vlTOPp->__Vfunc_float_block__DOT__maxFloat__21__Vfuncout = 0x7fc00000U;
				} else {
				    // Function: isNan at rtl/float_block.v:426
				    // Function: isNan at rtl/float_block.v:426
				    vlTOPp->__Vfunc_float_block__DOT__isNan__44__float_in 
					= vlTOPp->__Vfunc_float_block__DOT__maxFloat__21__float_in2;
				    vlTOPp->__Vfunc_float_block__DOT__isNan__44__Vfuncout = 0U;
				    if ((((0x7fffffffU 
					   >= vlTOPp->__Vfunc_float_block__DOT__isNan__44__float_in) 
					  & (0x7fc00000U 
					     <= vlTOPp->__Vfunc_float_block__DOT__isNan__44__float_in)) 
					 | (0xffc00000U 
					    <= vlTOPp->__Vfunc_float_block__DOT__isNan__44__float_in))) {
					vlTOPp->__Vfunc_float_block__DOT__isNan__44__Vfuncout = 1U;
				    }
				    if ((((0x7fbfffffU 
					   >= vlTOPp->__Vfunc_float_block__DOT__isNan__44__float_in) 
					  & (0x7f800001U 
					     <= vlTOPp->__Vfunc_float_block__DOT__isNan__44__float_in)) 
					 | ((0xffbfffffU 
					     >= vlTOPp->__Vfunc_float_block__DOT__isNan__44__float_in) 
					    & (0xff800001U 
					       <= vlTOPp->__Vfunc_float_block__DOT__isNan__44__float_in)))) {
					vlTOPp->__Vfunc_float_block__DOT__isNan__44__Vfuncout = 2U;
				    }
				    vlTOPp->__Vfunc_float_block__DOT__isNan__43__float_in 
					= vlTOPp->__Vfunc_float_block__DOT__maxFloat__21__float_in1;
				    vlTOPp->__Vfunc_float_block__DOT__isNan__43__Vfuncout = 0U;
				    if ((((0x7fffffffU 
					   >= vlTOPp->__Vfunc_float_block__DOT__isNan__43__float_in) 
					  & (0x7fc00000U 
					     <= vlTOPp->__Vfunc_float_block__DOT__isNan__43__float_in)) 
					 | (0xffc00000U 
					    <= vlTOPp->__Vfunc_float_block__DOT__isNan__43__float_in))) {
					vlTOPp->__Vfunc_float_block__DOT__isNan__43__Vfuncout = 1U;
				    }
				    if ((((0x7fbfffffU 
					   >= vlTOPp->__Vfunc_float_block__DOT__isNan__43__float_in) 
					  & (0x7f800001U 
					     <= vlTOPp->__Vfunc_float_block__DOT__isNan__43__float_in)) 
					 | ((0xffbfffffU 
					     >= vlTOPp->__Vfunc_float_block__DOT__isNan__43__float_in) 
					    & (0xff800001U 
					       <= vlTOPp->__Vfunc_float_block__DOT__isNan__43__float_in)))) {
					vlTOPp->__Vfunc_float_block__DOT__isNan__43__Vfuncout = 2U;
				    }
				    if (((1U == (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__43__Vfuncout)) 
					 ^ (1U == (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__44__Vfuncout)))) {
					// Function: isNan at rtl/float_block.v:427
					vlTOPp->__Vfunc_float_block__DOT__isNan__45__float_in 
					    = vlTOPp->__Vfunc_float_block__DOT__maxFloat__21__float_in1;
					vlTOPp->__Vfunc_float_block__DOT__isNan__45__Vfuncout = 0U;
					if ((((0x7fffffffU 
					       >= vlTOPp->__Vfunc_float_block__DOT__isNan__45__float_in) 
					      & (0x7fc00000U 
						 <= vlTOPp->__Vfunc_float_block__DOT__isNan__45__float_in)) 
					     | (0xffc00000U 
						<= vlTOPp->__Vfunc_float_block__DOT__isNan__45__float_in))) {
					    vlTOPp->__Vfunc_float_block__DOT__isNan__45__Vfuncout = 1U;
					}
					if ((((0x7fbfffffU 
					       >= vlTOPp->__Vfunc_float_block__DOT__isNan__45__float_in) 
					      & (0x7f800001U 
						 <= vlTOPp->__Vfunc_float_block__DOT__isNan__45__float_in)) 
					     | ((0xffbfffffU 
						 >= vlTOPp->__Vfunc_float_block__DOT__isNan__45__float_in) 
						& (0xff800001U 
						   <= vlTOPp->__Vfunc_float_block__DOT__isNan__45__float_in)))) {
					    vlTOPp->__Vfunc_float_block__DOT__isNan__45__Vfuncout = 2U;
					}
					vlTOPp->__Vfunc_float_block__DOT__maxFloat__21__Vfuncout 
					    = ((1U 
						== (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__45__Vfuncout))
					        ? vlTOPp->__Vfunc_float_block__DOT__maxFloat__21__float_in2
					        : vlTOPp->__Vfunc_float_block__DOT__maxFloat__21__float_in1);
				    }
				}
			    }
			    vlTOPp->float_low_o = vlTOPp->__Vfunc_float_block__DOT__maxFloat__21__Vfuncout;
			    vlTOPp->done_o = 1U;
			} else {
			    // Function: minFloat at rtl/float_block.v:142
			    // Function: floatEquality at rtl/float_block.v:440
			    // Function: floatLess at rtl/float_block.v:442
			    // Function: floatEquality at rtl/float_block.v:231
			    // Function: isNan at rtl/float_block.v:204
			    // Function: isNan at rtl/float_block.v:204
			    // Function: isNan at rtl/float_block.v:233
			    // Function: isNan at rtl/float_block.v:233
			    // Function: isNan at rtl/float_block.v:204
			    // Function: isNan at rtl/float_block.v:204
			    // Function: isNan at rtl/float_block.v:447
			    // Function: isNan at rtl/float_block.v:447
			    vlTOPp->__Vfunc_float_block__DOT__minFloat__46__float_in2 
				= vlTOPp->float2_i;
			    vlTOPp->__Vfunc_float_block__DOT__minFloat__46__float_in1 
				= vlTOPp->float1_i;
			    vlTOPp->__Vfunc_float_block__DOT__floatLess__48__float_in2 
				= vlTOPp->__Vfunc_float_block__DOT__minFloat__46__float_in2;
			    vlTOPp->__Vfunc_float_block__DOT__floatLess__48__float_in1 
				= vlTOPp->__Vfunc_float_block__DOT__minFloat__46__float_in1;
			    vlTOPp->__Vfunc_float_block__DOT__floatLess__48__Vfuncout 
				= (((0xffU & (vlTOPp->__Vfunc_float_block__DOT__floatLess__48__float_in1 
					      >> 0x17U)) 
				    < (0xffU & (vlTOPp->__Vfunc_float_block__DOT__floatLess__48__float_in2 
						>> 0x17U))) 
				   | (((0xffU & (vlTOPp->__Vfunc_float_block__DOT__floatLess__48__float_in1 
						 >> 0x17U)) 
				       == (0xffU & 
					   (vlTOPp->__Vfunc_float_block__DOT__floatLess__48__float_in2 
					    >> 0x17U)))
				       ? ((0x7fffffU 
					   & vlTOPp->__Vfunc_float_block__DOT__floatLess__48__float_in1) 
					  < (0x7fffffU 
					     & vlTOPp->__Vfunc_float_block__DOT__floatLess__48__float_in2))
				       : (0xfff00000U 
					  == vlTOPp->__Vfunc_float_block__DOT__floatLess__48__float_in1)));
			    if (((1U & (vlTOPp->__Vfunc_float_block__DOT__floatLess__48__float_in1 
					>> 0x1fU)) 
				 > (1U & (vlTOPp->__Vfunc_float_block__DOT__floatLess__48__float_in2 
					  >> 0x1fU)))) {
				vlTOPp->__Vfunc_float_block__DOT__floatLess__48__Vfuncout = 1U;
			    } else {
				if (((1U & (vlTOPp->__Vfunc_float_block__DOT__floatLess__48__float_in1 
					    >> 0x1fU)) 
				     < (1U & (vlTOPp->__Vfunc_float_block__DOT__floatLess__48__float_in2 
					      >> 0x1fU)))) {
				    vlTOPp->__Vfunc_float_block__DOT__floatLess__48__Vfuncout = 0U;
				}
			    }
			    vlTOPp->__Vfunc_float_block__DOT__floatEquality__49__float_in2 
				= vlTOPp->__Vfunc_float_block__DOT__floatLess__48__float_in2;
			    vlTOPp->__Vfunc_float_block__DOT__floatEquality__49__float_in1 
				= vlTOPp->__Vfunc_float_block__DOT__floatLess__48__float_in1;
			    vlTOPp->__Vfunc_float_block__DOT__floatEquality__49__Vfuncout 
				= (((((0xffU & (vlTOPp->__Vfunc_float_block__DOT__floatEquality__49__float_in1 
						>> 0x17U)) 
				      == (0xffU & (vlTOPp->__Vfunc_float_block__DOT__floatEquality__49__float_in2 
						   >> 0x17U))) 
				     & ((0x7fffffU 
					 & vlTOPp->__Vfunc_float_block__DOT__floatEquality__49__float_in1) 
					== (0x7fffffU 
					    & vlTOPp->__Vfunc_float_block__DOT__floatEquality__49__float_in2))) 
				    & ((1U & (vlTOPp->__Vfunc_float_block__DOT__floatEquality__49__float_in1 
					      >> 0x1fU)) 
				       == (1U & (vlTOPp->__Vfunc_float_block__DOT__floatEquality__49__float_in2 
						 >> 0x1fU)))) 
				   | ((((0x7fffffffU 
					 & vlTOPp->__Vfunc_float_block__DOT__floatEquality__49__float_in1) 
					== (0x7fffffffU 
					    & vlTOPp->__Vfunc_float_block__DOT__floatEquality__49__float_in2)) 
				       & (0U == (0x7fffffffU 
						 & vlTOPp->__Vfunc_float_block__DOT__floatEquality__49__float_in1))) 
				      | (((0x7ff00000U 
					   == vlTOPp->__Vfunc_float_block__DOT__floatEquality__49__float_in1) 
					  & (0x7ff00000U 
					     == vlTOPp->__Vfunc_float_block__DOT__floatEquality__49__float_in2)) 
					 | ((0xfff00000U 
					     == vlTOPp->__Vfunc_float_block__DOT__floatEquality__49__float_in1) 
					    & (0xfff00000U 
					       == vlTOPp->__Vfunc_float_block__DOT__floatEquality__49__float_in2)))));
			    vlTOPp->__Vfunc_float_block__DOT__isNan__51__float_in 
				= vlTOPp->__Vfunc_float_block__DOT__floatEquality__49__float_in2;
			    vlTOPp->__Vfunc_float_block__DOT__isNan__51__Vfuncout = 0U;
			    if ((((0x7fffffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__51__float_in) 
				  & (0x7fc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__51__float_in)) 
				 | (0xffc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__51__float_in))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__51__Vfuncout = 1U;
			    }
			    if ((((0x7fbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__51__float_in) 
				  & (0x7f800001U <= vlTOPp->__Vfunc_float_block__DOT__isNan__51__float_in)) 
				 | ((0xffbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__51__float_in) 
				    & (0xff800001U 
				       <= vlTOPp->__Vfunc_float_block__DOT__isNan__51__float_in)))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__51__Vfuncout = 2U;
			    }
			    vlTOPp->__Vfunc_float_block__DOT__isNan__50__float_in 
				= vlTOPp->__Vfunc_float_block__DOT__floatEquality__49__float_in1;
			    vlTOPp->__Vfunc_float_block__DOT__isNan__50__Vfuncout = 0U;
			    if ((((0x7fffffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__50__float_in) 
				  & (0x7fc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__50__float_in)) 
				 | (0xffc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__50__float_in))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__50__Vfuncout = 1U;
			    }
			    if ((((0x7fbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__50__float_in) 
				  & (0x7f800001U <= vlTOPp->__Vfunc_float_block__DOT__isNan__50__float_in)) 
				 | ((0xffbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__50__float_in) 
				    & (0xff800001U 
				       <= vlTOPp->__Vfunc_float_block__DOT__isNan__50__float_in)))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__50__Vfuncout = 2U;
			    }
			    if (((0U < (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__50__Vfuncout)) 
				 | (0U < (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__51__Vfuncout)))) {
				vlTOPp->__Vfunc_float_block__DOT__floatEquality__49__Vfuncout = 0U;
			    }
			    if (vlTOPp->__Vfunc_float_block__DOT__floatEquality__49__Vfuncout) {
				vlTOPp->__Vfunc_float_block__DOT__floatLess__48__Vfuncout = 0U;
			    }
			    vlTOPp->__Vfunc_float_block__DOT__isNan__53__float_in 
				= vlTOPp->__Vfunc_float_block__DOT__floatLess__48__float_in2;
			    vlTOPp->__Vfunc_float_block__DOT__isNan__53__Vfuncout = 0U;
			    if ((((0x7fffffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__53__float_in) 
				  & (0x7fc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__53__float_in)) 
				 | (0xffc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__53__float_in))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__53__Vfuncout = 1U;
			    }
			    if ((((0x7fbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__53__float_in) 
				  & (0x7f800001U <= vlTOPp->__Vfunc_float_block__DOT__isNan__53__float_in)) 
				 | ((0xffbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__53__float_in) 
				    & (0xff800001U 
				       <= vlTOPp->__Vfunc_float_block__DOT__isNan__53__float_in)))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__53__Vfuncout = 2U;
			    }
			    vlTOPp->__Vfunc_float_block__DOT__isNan__52__float_in 
				= vlTOPp->__Vfunc_float_block__DOT__floatLess__48__float_in1;
			    vlTOPp->__Vfunc_float_block__DOT__isNan__52__Vfuncout = 0U;
			    if ((((0x7fffffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__52__float_in) 
				  & (0x7fc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__52__float_in)) 
				 | (0xffc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__52__float_in))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__52__Vfuncout = 1U;
			    }
			    if ((((0x7fbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__52__float_in) 
				  & (0x7f800001U <= vlTOPp->__Vfunc_float_block__DOT__isNan__52__float_in)) 
				 | ((0xffbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__52__float_in) 
				    & (0xff800001U 
				       <= vlTOPp->__Vfunc_float_block__DOT__isNan__52__float_in)))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__52__Vfuncout = 2U;
			    }
			    if (((0U < (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__52__Vfuncout)) 
				 | (0U < (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__53__Vfuncout)))) {
				vlTOPp->__Vfunc_float_block__DOT__floatLess__48__Vfuncout = 0U;
			    }
			    vlTOPp->__Vfunc_float_block__DOT__floatEquality__47__float_in2 
				= vlTOPp->__Vfunc_float_block__DOT__minFloat__46__float_in2;
			    vlTOPp->__Vfunc_float_block__DOT__floatEquality__47__float_in1 
				= vlTOPp->__Vfunc_float_block__DOT__minFloat__46__float_in1;
			    vlTOPp->__Vfunc_float_block__DOT__floatEquality__47__Vfuncout 
				= (((((0xffU & (vlTOPp->__Vfunc_float_block__DOT__floatEquality__47__float_in1 
						>> 0x17U)) 
				      == (0xffU & (vlTOPp->__Vfunc_float_block__DOT__floatEquality__47__float_in2 
						   >> 0x17U))) 
				     & ((0x7fffffU 
					 & vlTOPp->__Vfunc_float_block__DOT__floatEquality__47__float_in1) 
					== (0x7fffffU 
					    & vlTOPp->__Vfunc_float_block__DOT__floatEquality__47__float_in2))) 
				    & ((1U & (vlTOPp->__Vfunc_float_block__DOT__floatEquality__47__float_in1 
					      >> 0x1fU)) 
				       == (1U & (vlTOPp->__Vfunc_float_block__DOT__floatEquality__47__float_in2 
						 >> 0x1fU)))) 
				   | ((((0x7fffffffU 
					 & vlTOPp->__Vfunc_float_block__DOT__floatEquality__47__float_in1) 
					== (0x7fffffffU 
					    & vlTOPp->__Vfunc_float_block__DOT__floatEquality__47__float_in2)) 
				       & (0U == (0x7fffffffU 
						 & vlTOPp->__Vfunc_float_block__DOT__floatEquality__47__float_in1))) 
				      | (((0x7ff00000U 
					   == vlTOPp->__Vfunc_float_block__DOT__floatEquality__47__float_in1) 
					  & (0x7ff00000U 
					     == vlTOPp->__Vfunc_float_block__DOT__floatEquality__47__float_in2)) 
					 | ((0xfff00000U 
					     == vlTOPp->__Vfunc_float_block__DOT__floatEquality__47__float_in1) 
					    & (0xfff00000U 
					       == vlTOPp->__Vfunc_float_block__DOT__floatEquality__47__float_in2)))));
			    vlTOPp->__Vfunc_float_block__DOT__isNan__55__float_in 
				= vlTOPp->__Vfunc_float_block__DOT__floatEquality__47__float_in2;
			    vlTOPp->__Vfunc_float_block__DOT__isNan__55__Vfuncout = 0U;
			    if ((((0x7fffffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__55__float_in) 
				  & (0x7fc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__55__float_in)) 
				 | (0xffc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__55__float_in))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__55__Vfuncout = 1U;
			    }
			    if ((((0x7fbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__55__float_in) 
				  & (0x7f800001U <= vlTOPp->__Vfunc_float_block__DOT__isNan__55__float_in)) 
				 | ((0xffbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__55__float_in) 
				    & (0xff800001U 
				       <= vlTOPp->__Vfunc_float_block__DOT__isNan__55__float_in)))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__55__Vfuncout = 2U;
			    }
			    vlTOPp->__Vfunc_float_block__DOT__isNan__54__float_in 
				= vlTOPp->__Vfunc_float_block__DOT__floatEquality__47__float_in1;
			    vlTOPp->__Vfunc_float_block__DOT__isNan__54__Vfuncout = 0U;
			    if ((((0x7fffffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__54__float_in) 
				  & (0x7fc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__54__float_in)) 
				 | (0xffc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__54__float_in))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__54__Vfuncout = 1U;
			    }
			    if ((((0x7fbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__54__float_in) 
				  & (0x7f800001U <= vlTOPp->__Vfunc_float_block__DOT__isNan__54__float_in)) 
				 | ((0xffbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__54__float_in) 
				    & (0xff800001U 
				       <= vlTOPp->__Vfunc_float_block__DOT__isNan__54__float_in)))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__54__Vfuncout = 2U;
			    }
			    if (((0U < (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__54__Vfuncout)) 
				 | (0U < (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__55__Vfuncout)))) {
				vlTOPp->__Vfunc_float_block__DOT__floatEquality__47__Vfuncout = 0U;
			    }
			    vlTOPp->__Vfunc_float_block__DOT__minFloat__46__Vfuncout 
				= ((IData)(vlTOPp->__Vfunc_float_block__DOT__floatEquality__47__Vfuncout)
				    ? vlTOPp->__Vfunc_float_block__DOT__minFloat__46__float_in1
				    : ((IData)(vlTOPp->__Vfunc_float_block__DOT__floatLess__48__Vfuncout)
				        ? vlTOPp->__Vfunc_float_block__DOT__minFloat__46__float_in1
				        : vlTOPp->__Vfunc_float_block__DOT__minFloat__46__float_in2));
			    vlTOPp->__Vfunc_float_block__DOT__isNan__57__float_in 
				= vlTOPp->__Vfunc_float_block__DOT__minFloat__46__float_in2;
			    vlTOPp->__Vfunc_float_block__DOT__isNan__57__Vfuncout = 0U;
			    if ((((0x7fffffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__57__float_in) 
				  & (0x7fc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__57__float_in)) 
				 | (0xffc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__57__float_in))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__57__Vfuncout = 1U;
			    }
			    if ((((0x7fbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__57__float_in) 
				  & (0x7f800001U <= vlTOPp->__Vfunc_float_block__DOT__isNan__57__float_in)) 
				 | ((0xffbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__57__float_in) 
				    & (0xff800001U 
				       <= vlTOPp->__Vfunc_float_block__DOT__isNan__57__float_in)))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__57__Vfuncout = 2U;
			    }
			    vlTOPp->__Vfunc_float_block__DOT__isNan__56__float_in 
				= vlTOPp->__Vfunc_float_block__DOT__minFloat__46__float_in1;
			    vlTOPp->__Vfunc_float_block__DOT__isNan__56__Vfuncout = 0U;
			    if ((((0x7fffffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__56__float_in) 
				  & (0x7fc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__56__float_in)) 
				 | (0xffc00000U <= vlTOPp->__Vfunc_float_block__DOT__isNan__56__float_in))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__56__Vfuncout = 1U;
			    }
			    if ((((0x7fbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__56__float_in) 
				  & (0x7f800001U <= vlTOPp->__Vfunc_float_block__DOT__isNan__56__float_in)) 
				 | ((0xffbfffffU >= vlTOPp->__Vfunc_float_block__DOT__isNan__56__float_in) 
				    & (0xff800001U 
				       <= vlTOPp->__Vfunc_float_block__DOT__isNan__56__float_in)))) {
				vlTOPp->__Vfunc_float_block__DOT__isNan__56__Vfuncout = 2U;
			    }
			    if (((2U == (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__56__Vfuncout)) 
				 | (2U == (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__57__Vfuncout)))) {
				vlTOPp->__Vfunc_float_block__DOT__minFloat__46__Vfuncout = 0x7fc00000U;
			    } else {
				// Function: isNan at rtl/float_block.v:449
				// Function: isNan at rtl/float_block.v:449
				vlTOPp->__Vfunc_float_block__DOT__isNan__59__float_in 
				    = vlTOPp->__Vfunc_float_block__DOT__minFloat__46__float_in2;
				vlTOPp->__Vfunc_float_block__DOT__isNan__59__Vfuncout = 0U;
				if ((((0x7fffffffU 
				       >= vlTOPp->__Vfunc_float_block__DOT__isNan__59__float_in) 
				      & (0x7fc00000U 
					 <= vlTOPp->__Vfunc_float_block__DOT__isNan__59__float_in)) 
				     | (0xffc00000U 
					<= vlTOPp->__Vfunc_float_block__DOT__isNan__59__float_in))) {
				    vlTOPp->__Vfunc_float_block__DOT__isNan__59__Vfuncout = 1U;
				}
				if ((((0x7fbfffffU 
				       >= vlTOPp->__Vfunc_float_block__DOT__isNan__59__float_in) 
				      & (0x7f800001U 
					 <= vlTOPp->__Vfunc_float_block__DOT__isNan__59__float_in)) 
				     | ((0xffbfffffU 
					 >= vlTOPp->__Vfunc_float_block__DOT__isNan__59__float_in) 
					& (0xff800001U 
					   <= vlTOPp->__Vfunc_float_block__DOT__isNan__59__float_in)))) {
				    vlTOPp->__Vfunc_float_block__DOT__isNan__59__Vfuncout = 2U;
				}
				vlTOPp->__Vfunc_float_block__DOT__isNan__58__float_in 
				    = vlTOPp->__Vfunc_float_block__DOT__minFloat__46__float_in1;
				vlTOPp->__Vfunc_float_block__DOT__isNan__58__Vfuncout = 0U;
				if ((((0x7fffffffU 
				       >= vlTOPp->__Vfunc_float_block__DOT__isNan__58__float_in) 
				      & (0x7fc00000U 
					 <= vlTOPp->__Vfunc_float_block__DOT__isNan__58__float_in)) 
				     | (0xffc00000U 
					<= vlTOPp->__Vfunc_float_block__DOT__isNan__58__float_in))) {
				    vlTOPp->__Vfunc_float_block__DOT__isNan__58__Vfuncout = 1U;
				}
				if ((((0x7fbfffffU 
				       >= vlTOPp->__Vfunc_float_block__DOT__isNan__58__float_in) 
				      & (0x7f800001U 
					 <= vlTOPp->__Vfunc_float_block__DOT__isNan__58__float_in)) 
				     | ((0xffbfffffU 
					 >= vlTOPp->__Vfunc_float_block__DOT__isNan__58__float_in) 
					& (0xff800001U 
					   <= vlTOPp->__Vfunc_float_block__DOT__isNan__58__float_in)))) {
				    vlTOPp->__Vfunc_float_block__DOT__isNan__58__Vfuncout = 2U;
				}
				if (((1U == (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__58__Vfuncout)) 
				     & (1U == (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__59__Vfuncout)))) {
				    vlTOPp->__Vfunc_float_block__DOT__minFloat__46__Vfuncout = 0x7fc00000U;
				} else {
				    // Function: isNan at rtl/float_block.v:451
				    // Function: isNan at rtl/float_block.v:451
				    vlTOPp->__Vfunc_float_block__DOT__isNan__61__float_in 
					= vlTOPp->__Vfunc_float_block__DOT__minFloat__46__float_in2;
				    vlTOPp->__Vfunc_float_block__DOT__isNan__61__Vfuncout = 0U;
				    if ((((0x7fffffffU 
					   >= vlTOPp->__Vfunc_float_block__DOT__isNan__61__float_in) 
					  & (0x7fc00000U 
					     <= vlTOPp->__Vfunc_float_block__DOT__isNan__61__float_in)) 
					 | (0xffc00000U 
					    <= vlTOPp->__Vfunc_float_block__DOT__isNan__61__float_in))) {
					vlTOPp->__Vfunc_float_block__DOT__isNan__61__Vfuncout = 1U;
				    }
				    if ((((0x7fbfffffU 
					   >= vlTOPp->__Vfunc_float_block__DOT__isNan__61__float_in) 
					  & (0x7f800001U 
					     <= vlTOPp->__Vfunc_float_block__DOT__isNan__61__float_in)) 
					 | ((0xffbfffffU 
					     >= vlTOPp->__Vfunc_float_block__DOT__isNan__61__float_in) 
					    & (0xff800001U 
					       <= vlTOPp->__Vfunc_float_block__DOT__isNan__61__float_in)))) {
					vlTOPp->__Vfunc_float_block__DOT__isNan__61__Vfuncout = 2U;
				    }
				    vlTOPp->__Vfunc_float_block__DOT__isNan__60__float_in 
					= vlTOPp->__Vfunc_float_block__DOT__minFloat__46__float_in1;
				    vlTOPp->__Vfunc_float_block__DOT__isNan__60__Vfuncout = 0U;
				    if ((((0x7fffffffU 
					   >= vlTOPp->__Vfunc_float_block__DOT__isNan__60__float_in) 
					  & (0x7fc00000U 
					     <= vlTOPp->__Vfunc_float_block__DOT__isNan__60__float_in)) 
					 | (0xffc00000U 
					    <= vlTOPp->__Vfunc_float_block__DOT__isNan__60__float_in))) {
					vlTOPp->__Vfunc_float_block__DOT__isNan__60__Vfuncout = 1U;
				    }
				    if ((((0x7fbfffffU 
					   >= vlTOPp->__Vfunc_float_block__DOT__isNan__60__float_in) 
					  & (0x7f800001U 
					     <= vlTOPp->__Vfunc_float_block__DOT__isNan__60__float_in)) 
					 | ((0xffbfffffU 
					     >= vlTOPp->__Vfunc_float_block__DOT__isNan__60__float_in) 
					    & (0xff800001U 
					       <= vlTOPp->__Vfunc_float_block__DOT__isNan__60__float_in)))) {
					vlTOPp->__Vfunc_float_block__DOT__isNan__60__Vfuncout = 2U;
				    }
				    if (((1U == (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__60__Vfuncout)) 
					 ^ (1U == (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__61__Vfuncout)))) {
					// Function: isNan at rtl/float_block.v:452
					vlTOPp->__Vfunc_float_block__DOT__isNan__62__float_in 
					    = vlTOPp->__Vfunc_float_block__DOT__minFloat__46__float_in1;
					vlTOPp->__Vfunc_float_block__DOT__isNan__62__Vfuncout = 0U;
					if ((((0x7fffffffU 
					       >= vlTOPp->__Vfunc_float_block__DOT__isNan__62__float_in) 
					      & (0x7fc00000U 
						 <= vlTOPp->__Vfunc_float_block__DOT__isNan__62__float_in)) 
					     | (0xffc00000U 
						<= vlTOPp->__Vfunc_float_block__DOT__isNan__62__float_in))) {
					    vlTOPp->__Vfunc_float_block__DOT__isNan__62__Vfuncout = 1U;
					}
					if ((((0x7fbfffffU 
					       >= vlTOPp->__Vfunc_float_block__DOT__isNan__62__float_in) 
					      & (0x7f800001U 
						 <= vlTOPp->__Vfunc_float_block__DOT__isNan__62__float_in)) 
					     | ((0xffbfffffU 
						 >= vlTOPp->__Vfunc_float_block__DOT__isNan__62__float_in) 
						& (0xff800001U 
						   <= vlTOPp->__Vfunc_float_block__DOT__isNan__62__float_in)))) {
					    vlTOPp->__Vfunc_float_block__DOT__isNan__62__Vfuncout = 2U;
					}
					vlTOPp->__Vfunc_float_block__DOT__minFloat__46__Vfuncout 
					    = ((1U 
						== (IData)(vlTOPp->__Vfunc_float_block__DOT__isNan__62__Vfuncout))
					        ? vlTOPp->__Vfunc_float_block__DOT__minFloat__46__float_in2
					        : vlTOPp->__Vfunc_float_block__DOT__minFloat__46__float_in1);
				    }
				}
			    }
			    vlTOPp->float_low_o = vlTOPp->__Vfunc_float_block__DOT__minFloat__46__Vfuncout;
			    vlTOPp->done_o = 1U;
			}
		    }
		}
	    } else {
		if ((4U & (IData)(vlTOPp->opcode_i))) {
		    if ((2U & (IData)(vlTOPp->opcode_i))) {
			if ((1U & (IData)(vlTOPp->opcode_i))) {
			    // Function: addFloats at rtl/float_block.v:126
			    vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in2 
				= ((0x80000000U & (
						   ((IData)(1U) 
						    + 
						    (vlTOPp->float2_i 
						     >> 0x1fU)) 
						   << 0x1fU)) 
				   | (0x7fffffffU & vlTOPp->float2_i));
			    vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in1 
				= vlTOPp->float1_i;
			    if (((0xffU & (vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in1 
					   >> 0x17U)) 
				 == (0xffU & (vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in2 
					      >> 0x17U)))) {
				if (VL_UNLIKELY(((1U 
						  & (vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in1 
						     >> 0x1fU)) 
						 == 
						 (1U 
						  & (vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in2 
						     >> 0x1fU))))) {
				    // Function: round_man_inter at rtl/float_block.v:301
				    vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result 
					= ((0x807fffffU 
					    & vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result) 
					   | (0x7f800000U 
					      & (((IData)(1U) 
						  + 
						  (vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in1 
						   >> 0x17U)) 
						 << 0x17U)));
				    vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter 
					= (0xffffffU 
					   & ((0x7fffffU 
					       & vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in1) 
					      + (0x7fffffU 
						 & vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in2)));
				    vlTOPp->__Vfunc_float_block__DOT__round_man_inter__64__man_inter_in 
					= vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter;
				    VL_WRITEF("intermediate mantissa: %b\n",
					      24,vlTOPp->__Vfunc_float_block__DOT__round_man_inter__64__man_inter_in);
				    if (VL_UNLIKELY(
						    ((0x100000U 
						      <= vlTOPp->__Vfunc_float_block__DOT__round_man_inter__64__man_inter_in) 
						     & (vlTOPp->__Vfunc_float_block__DOT__round_man_inter__64__man_inter_in 
							>> 1U)))) {
					VL_WRITEF("rounding\n");
					vlTOPp->__Vfunc_float_block__DOT__round_man_inter__64__Vfuncout 
					    = (0xffffffU 
					       & ((1U 
						   & vlTOPp->__Vfunc_float_block__DOT__round_man_inter__64__man_inter_in)
						   ? 
						  ((IData)(1U) 
						   + vlTOPp->__Vfunc_float_block__DOT__round_man_inter__64__man_inter_in)
						   : 
						  ((IData)(2U) 
						   + vlTOPp->__Vfunc_float_block__DOT__round_man_inter__64__man_inter_in)));
				    } else {
					vlTOPp->__Vfunc_float_block__DOT__round_man_inter__64__Vfuncout 
					    = vlTOPp->__Vfunc_float_block__DOT__round_man_inter__64__man_inter_in;
				    }
				    vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter 
					= vlTOPp->__Vfunc_float_block__DOT__round_man_inter__64__Vfuncout;
				    vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter 
					= (0xffffffU 
					   & (vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter 
					      >> 1U));
				    vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result 
					= ((0xff800000U 
					    & vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result) 
					   | (0x7fffffU 
					      & vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter));
				    vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result 
					= ((0x7fffffffU 
					    & vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result) 
					   | (0x80000000U 
					      & vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in1));
				} else {
				    if (((1U & (vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in1 
						>> 0x1fU)) 
					 > (1U & (vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in2 
						  >> 0x1fU)))) {
					// Function: findLeadOne at rtl/float_block.v:314
					vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter 
					    = (0xffffffU 
					       & ((0x7fffffU 
						   & vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in2) 
						  - 
						  (0x7fffffU 
						   & vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in1)));
					if (VL_GTS_III(1,24,24, 0U, vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter)) {
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter 
						= (0xffffffU 
						   & ((IData)(1U) 
						      + 
						      (~ vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter)));
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result 
						= (0x80000000U 
						   | vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result);
					}
					vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__num 
					    = vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter;
					if ((1U & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__Vfuncout = 0U;
					}
					if ((2U & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__Vfuncout = 1U;
					}
					if ((4U & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__Vfuncout = 2U;
					}
					if ((8U & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__Vfuncout = 3U;
					}
					if ((0x10U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__Vfuncout = 4U;
					}
					if ((0x20U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__Vfuncout = 5U;
					}
					if ((0x40U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__Vfuncout = 6U;
					}
					if ((0x80U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__Vfuncout = 7U;
					}
					if ((0x100U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__Vfuncout = 8U;
					}
					if ((0x200U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__Vfuncout = 9U;
					}
					if ((0x400U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__Vfuncout = 0xaU;
					}
					if ((0x800U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__Vfuncout = 0xbU;
					}
					if ((0x1000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__Vfuncout = 0xcU;
					}
					if ((0x2000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__Vfuncout = 0xdU;
					}
					if ((0x4000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__Vfuncout = 0xeU;
					}
					if ((0x8000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__Vfuncout = 0xfU;
					}
					if ((0x10000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__Vfuncout = 0x10U;
					}
					if ((0x20000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__Vfuncout = 0x11U;
					}
					if ((0x40000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__Vfuncout = 0x12U;
					}
					if ((0x80000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__Vfuncout = 0x13U;
					}
					if ((0x100000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__Vfuncout = 0x14U;
					}
					if ((0x200000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__Vfuncout = 0x15U;
					}
					if ((0x400000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__Vfuncout = 0x16U;
					}
					if ((0x800000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__Vfuncout = 0x17U;
					}
					vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__lead_one 
					    = vlTOPp->__Vfunc_float_block__DOT__findLeadOne__65__Vfuncout;
					vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result 
					    = ((0x807fffffU 
						& vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result) 
					       | (0x7f800000U 
						  & (((vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in1 
						       >> 0x17U) 
						      - 
						      ((IData)(1U) 
						       + 
						       ((IData)(0x17U) 
							- (IData)(vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__lead_one)))) 
						     << 0x17U)));
					vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result 
					    = ((0xff800000U 
						& vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result) 
					       | (0x7fffffU 
						  & ((0x16U 
						      >= 
						      (0x3fU 
						       & ((IData)(0x18U) 
							  - (IData)(vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__lead_one))))
						      ? 
						     (vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter 
						      << 
						      (0x3fU 
						       & ((IData)(0x18U) 
							  - (IData)(vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__lead_one))))
						      : 0U)));
				    } else {
					// Function: findLeadOne at rtl/float_block.v:325
					vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter 
					    = (0xffffffU 
					       & ((0x7fffffU 
						   & vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in1) 
						  - 
						  (0x7fffffU 
						   & vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in2)));
					if (VL_GTS_III(1,24,24, 0U, vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter)) {
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter 
						= (0xffffffU 
						   & ((IData)(1U) 
						      + 
						      (~ vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter)));
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result 
						= (0x80000000U 
						   | vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result);
					}
					vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__num 
					    = vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter;
					if ((1U & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__Vfuncout = 0U;
					}
					if ((2U & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__Vfuncout = 1U;
					}
					if ((4U & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__Vfuncout = 2U;
					}
					if ((8U & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__Vfuncout = 3U;
					}
					if ((0x10U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__Vfuncout = 4U;
					}
					if ((0x20U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__Vfuncout = 5U;
					}
					if ((0x40U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__Vfuncout = 6U;
					}
					if ((0x80U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__Vfuncout = 7U;
					}
					if ((0x100U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__Vfuncout = 8U;
					}
					if ((0x200U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__Vfuncout = 9U;
					}
					if ((0x400U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__Vfuncout = 0xaU;
					}
					if ((0x800U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__Vfuncout = 0xbU;
					}
					if ((0x1000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__Vfuncout = 0xcU;
					}
					if ((0x2000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__Vfuncout = 0xdU;
					}
					if ((0x4000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__Vfuncout = 0xeU;
					}
					if ((0x8000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__Vfuncout = 0xfU;
					}
					if ((0x10000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__Vfuncout = 0x10U;
					}
					if ((0x20000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__Vfuncout = 0x11U;
					}
					if ((0x40000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__Vfuncout = 0x12U;
					}
					if ((0x80000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__Vfuncout = 0x13U;
					}
					if ((0x100000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__Vfuncout = 0x14U;
					}
					if ((0x200000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__Vfuncout = 0x15U;
					}
					if ((0x400000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__Vfuncout = 0x16U;
					}
					if ((0x800000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__Vfuncout = 0x17U;
					}
					vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__lead_one 
					    = vlTOPp->__Vfunc_float_block__DOT__findLeadOne__66__Vfuncout;
					vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result 
					    = ((0x807fffffU 
						& vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result) 
					       | (0x7f800000U 
						  & (((vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in1 
						       >> 0x17U) 
						      - 
						      ((IData)(1U) 
						       + 
						       ((IData)(0x17U) 
							- (IData)(vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__lead_one)))) 
						     << 0x17U)));
					vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result 
					    = ((0xff800000U 
						& vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result) 
					       | (0x7fffffU 
						  & ((0x16U 
						      >= 
						      (0x3fU 
						       & ((IData)(0x18U) 
							  - (IData)(vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__lead_one))))
						      ? 
						     (vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter 
						      << 
						      (0x3fU 
						       & ((IData)(0x18U) 
							  - (IData)(vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__lead_one))))
						      : 0U)));
				    }
				}
			    } else {
				if (((0xffU & (vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in1 
					       >> 0x17U)) 
				     < (0xffU & (vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in2 
						 >> 0x17U)))) {
				    vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter 
					= (0xffffffU 
					   & ((0x17U 
					       >= (0xffU 
						   & ((vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in2 
						       >> 0x17U) 
						      - 
						      (vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in1 
						       >> 0x17U))))
					       ? ((0x800000U 
						   | (0x7fffffU 
						      & vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in1)) 
						  >> 
						  (0xffU 
						   & ((vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in2 
						       >> 0x17U) 
						      - 
						      (vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in1 
						       >> 0x17U))))
					       : 0U));
				    if (((1U & (vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in1 
						>> 0x1fU)) 
					 == (1U & (vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in2 
						   >> 0x1fU)))) {
					vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter 
					    = (0xffffffU 
					       & (vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter 
						  + 
						  (0x7fffffU 
						   & vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in2)));
					vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result 
					    = ((0x807fffffU 
						& vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result) 
					       | (0x7f800000U 
						  & (((vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in2 
						       >> 0x17U) 
						      + 
						      (1U 
						       & (vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter 
							  >> 0x17U))) 
						     << 0x17U)));
					if (VL_UNLIKELY(
							(0x800000U 
							 & vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter))) {
					    // Function: round_man_inter at rtl/float_block.v:341
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter 
						= (0x7fffffU 
						   & vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter);
					    vlTOPp->__Vfunc_float_block__DOT__round_man_inter__67__man_inter_in 
						= vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter;
					    VL_WRITEF("intermediate mantissa: %b\n",
						      24,
						      vlTOPp->__Vfunc_float_block__DOT__round_man_inter__67__man_inter_in);
					    if (VL_UNLIKELY(
							    ((0x100000U 
							      <= vlTOPp->__Vfunc_float_block__DOT__round_man_inter__67__man_inter_in) 
							     & (vlTOPp->__Vfunc_float_block__DOT__round_man_inter__67__man_inter_in 
								>> 1U)))) {
						VL_WRITEF("rounding\n");
						vlTOPp->__Vfunc_float_block__DOT__round_man_inter__67__Vfuncout 
						    = 
						    (0xffffffU 
						     & ((1U 
							 & vlTOPp->__Vfunc_float_block__DOT__round_man_inter__67__man_inter_in)
							 ? 
							((IData)(1U) 
							 + vlTOPp->__Vfunc_float_block__DOT__round_man_inter__67__man_inter_in)
							 : 
							((IData)(2U) 
							 + vlTOPp->__Vfunc_float_block__DOT__round_man_inter__67__man_inter_in)));
					    } else {
						vlTOPp->__Vfunc_float_block__DOT__round_man_inter__67__Vfuncout 
						    = vlTOPp->__Vfunc_float_block__DOT__round_man_inter__67__man_inter_in;
					    }
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter 
						= vlTOPp->__Vfunc_float_block__DOT__round_man_inter__67__Vfuncout;
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter 
						= (0xffffffU 
						   & (vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter 
						      >> 1U));
					}
					vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result 
					    = ((0xff800000U 
						& vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result) 
					       | (0x7fffffU 
						  & vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter));
					vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result 
					    = ((0x7fffffffU 
						& vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result) 
					       | (0x80000000U 
						  & vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in1));
				    } else {
					if (((1U & 
					      (vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in1 
					       >> 0x1fU)) 
					     > (1U 
						& (vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in2 
						   >> 0x1fU)))) {
					    // Function: findLeadOne at rtl/float_block.v:354
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter 
						= (0xffffffU 
						   & ((0x7fffffU 
						       & vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in2) 
						      - vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter));
					    if (VL_GTS_III(1,24,24, 0U, vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter)) {
						vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter 
						    = 
						    (0xffffffU 
						     & ((IData)(1U) 
							+ 
							(~ vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter)));
						vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result 
						    = 
						    (0x80000000U 
						     | vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result);
					    } else {
						vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result 
						    = 
						    (0x7fffffffU 
						     & vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result);
					    }
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__num 
						= vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter;
					    if ((1U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__Vfuncout = 0U;
					    }
					    if ((2U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__Vfuncout = 1U;
					    }
					    if ((4U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__Vfuncout = 2U;
					    }
					    if ((8U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__Vfuncout = 3U;
					    }
					    if ((0x10U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__Vfuncout = 4U;
					    }
					    if ((0x20U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__Vfuncout = 5U;
					    }
					    if ((0x40U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__Vfuncout = 6U;
					    }
					    if ((0x80U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__Vfuncout = 7U;
					    }
					    if ((0x100U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__Vfuncout = 8U;
					    }
					    if ((0x200U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__Vfuncout = 9U;
					    }
					    if ((0x400U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__Vfuncout = 0xaU;
					    }
					    if ((0x800U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__Vfuncout = 0xbU;
					    }
					    if ((0x1000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__Vfuncout = 0xcU;
					    }
					    if ((0x2000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__Vfuncout = 0xdU;
					    }
					    if ((0x4000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__Vfuncout = 0xeU;
					    }
					    if ((0x8000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__Vfuncout = 0xfU;
					    }
					    if ((0x10000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__Vfuncout = 0x10U;
					    }
					    if ((0x20000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__Vfuncout = 0x11U;
					    }
					    if ((0x40000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__Vfuncout = 0x12U;
					    }
					    if ((0x80000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__Vfuncout = 0x13U;
					    }
					    if ((0x100000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__Vfuncout = 0x14U;
					    }
					    if ((0x200000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__Vfuncout = 0x15U;
					    }
					    if ((0x400000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__Vfuncout = 0x16U;
					    }
					    if ((0x800000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__Vfuncout = 0x17U;
					    }
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__lead_one 
						= vlTOPp->__Vfunc_float_block__DOT__findLeadOne__68__Vfuncout;
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result 
						= (
						   (0x807fffffU 
						    & vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result) 
						   | (0x7f800000U 
						      & (((vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in2 
							   >> 0x17U) 
							  - 
							  ((IData)(0x17U) 
							   - (IData)(vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__lead_one))) 
							 << 0x17U)));
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result 
						= (
						   (0xff800000U 
						    & vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result) 
						   | (0x7fffffU 
						      & ((0x16U 
							  >= 
							  (0x3fU 
							   & ((IData)(0x17U) 
							      - (IData)(vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__lead_one))))
							  ? 
							 (vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter 
							  << 
							  (0x3fU 
							   & ((IData)(0x17U) 
							      - (IData)(vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__lead_one))))
							  : 0U)));
					} else {
					    // Function: findLeadOne at rtl/float_block.v:364
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter 
						= (0xffffffU 
						   & ((0x7fffffU 
						       & vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in2) 
						      - vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter));
					    if (VL_GTS_III(1,24,24, 0U, vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter)) {
						vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter 
						    = 
						    (0xffffffU 
						     & ((IData)(1U) 
							+ 
							(~ vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter)));
						vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result 
						    = 
						    (0x80000000U 
						     | vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result);
					    }
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__num 
						= vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter;
					    if ((1U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__Vfuncout = 0U;
					    }
					    if ((2U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__Vfuncout = 1U;
					    }
					    if ((4U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__Vfuncout = 2U;
					    }
					    if ((8U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__Vfuncout = 3U;
					    }
					    if ((0x10U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__Vfuncout = 4U;
					    }
					    if ((0x20U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__Vfuncout = 5U;
					    }
					    if ((0x40U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__Vfuncout = 6U;
					    }
					    if ((0x80U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__Vfuncout = 7U;
					    }
					    if ((0x100U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__Vfuncout = 8U;
					    }
					    if ((0x200U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__Vfuncout = 9U;
					    }
					    if ((0x400U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__Vfuncout = 0xaU;
					    }
					    if ((0x800U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__Vfuncout = 0xbU;
					    }
					    if ((0x1000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__Vfuncout = 0xcU;
					    }
					    if ((0x2000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__Vfuncout = 0xdU;
					    }
					    if ((0x4000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__Vfuncout = 0xeU;
					    }
					    if ((0x8000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__Vfuncout = 0xfU;
					    }
					    if ((0x10000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__Vfuncout = 0x10U;
					    }
					    if ((0x20000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__Vfuncout = 0x11U;
					    }
					    if ((0x40000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__Vfuncout = 0x12U;
					    }
					    if ((0x80000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__Vfuncout = 0x13U;
					    }
					    if ((0x100000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__Vfuncout = 0x14U;
					    }
					    if ((0x200000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__Vfuncout = 0x15U;
					    }
					    if ((0x400000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__Vfuncout = 0x16U;
					    }
					    if ((0x800000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__Vfuncout = 0x17U;
					    }
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__lead_one 
						= vlTOPp->__Vfunc_float_block__DOT__findLeadOne__69__Vfuncout;
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result 
						= (
						   (0x807fffffU 
						    & vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result) 
						   | (0x7f800000U 
						      & (((vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in2 
							   >> 0x17U) 
							  - 
							  ((IData)(0x17U) 
							   - (IData)(vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__lead_one))) 
							 << 0x17U)));
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result 
						= (
						   (0xff800000U 
						    & vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result) 
						   | (0x7fffffU 
						      & ((0x16U 
							  >= 
							  (0x3fU 
							   & ((IData)(0x17U) 
							      - (IData)(vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__lead_one))))
							  ? 
							 (vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter 
							  << 
							  (0x3fU 
							   & ((IData)(0x17U) 
							      - (IData)(vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__lead_one))))
							  : 0U)));
					}
				    }
				} else {
				    vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter 
					= (0xffffffU 
					   & ((0x17U 
					       >= (0xffU 
						   & ((vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in1 
						       >> 0x17U) 
						      - 
						      (vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in2 
						       >> 0x17U))))
					       ? ((0x800000U 
						   | (0x7fffffU 
						      & vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in2)) 
						  >> 
						  (0xffU 
						   & ((vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in1 
						       >> 0x17U) 
						      - 
						      (vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in2 
						       >> 0x17U))))
					       : 0U));
				    if (((1U & (vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in1 
						>> 0x1fU)) 
					 == (1U & (vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in2 
						   >> 0x1fU)))) {
					vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter 
					    = (0xffffffU 
					       & (vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter 
						  + 
						  (0x7fffffU 
						   & vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in1)));
					vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result 
					    = ((0x807fffffU 
						& vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result) 
					       | (0x7f800000U 
						  & (((vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in1 
						       >> 0x17U) 
						      + 
						      (1U 
						       & (vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter 
							  >> 0x17U))) 
						     << 0x17U)));
					if (VL_UNLIKELY(
							(0x800000U 
							 & vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter))) {
					    // Function: round_man_inter at rtl/float_block.v:378
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter 
						= (0x7fffffU 
						   & vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter);
					    vlTOPp->__Vfunc_float_block__DOT__round_man_inter__70__man_inter_in 
						= vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter;
					    VL_WRITEF("intermediate mantissa: %b\n",
						      24,
						      vlTOPp->__Vfunc_float_block__DOT__round_man_inter__70__man_inter_in);
					    if (VL_UNLIKELY(
							    ((0x100000U 
							      <= vlTOPp->__Vfunc_float_block__DOT__round_man_inter__70__man_inter_in) 
							     & (vlTOPp->__Vfunc_float_block__DOT__round_man_inter__70__man_inter_in 
								>> 1U)))) {
						VL_WRITEF("rounding\n");
						vlTOPp->__Vfunc_float_block__DOT__round_man_inter__70__Vfuncout 
						    = 
						    (0xffffffU 
						     & ((1U 
							 & vlTOPp->__Vfunc_float_block__DOT__round_man_inter__70__man_inter_in)
							 ? 
							((IData)(1U) 
							 + vlTOPp->__Vfunc_float_block__DOT__round_man_inter__70__man_inter_in)
							 : 
							((IData)(2U) 
							 + vlTOPp->__Vfunc_float_block__DOT__round_man_inter__70__man_inter_in)));
					    } else {
						vlTOPp->__Vfunc_float_block__DOT__round_man_inter__70__Vfuncout 
						    = vlTOPp->__Vfunc_float_block__DOT__round_man_inter__70__man_inter_in;
					    }
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter 
						= vlTOPp->__Vfunc_float_block__DOT__round_man_inter__70__Vfuncout;
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter 
						= (0xffffffU 
						   & (vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter 
						      >> 1U));
					}
					vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result 
					    = ((0xff800000U 
						& vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result) 
					       | (0x7fffffU 
						  & vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter));
					vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result 
					    = ((0x7fffffffU 
						& vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result) 
					       | (0x80000000U 
						  & vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in1));
				    } else {
					if (((1U & 
					      (vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in1 
					       >> 0x1fU)) 
					     > (1U 
						& (vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in2 
						   >> 0x1fU)))) {
					    // Function: findLeadOne at rtl/float_block.v:391
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter 
						= (0xffffffU 
						   & (vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter 
						      - 
						      (0x7fffffU 
						       & vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in1)));
					    if (VL_GTS_III(1,24,24, 0U, vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter)) {
						vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter 
						    = 
						    (0xffffffU 
						     & ((IData)(1U) 
							+ 
							(~ vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter)));
						vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result 
						    = 
						    (0x80000000U 
						     | vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result);
					    } else {
						vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result 
						    = 
						    (0x7fffffffU 
						     & vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result);
					    }
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__num 
						= vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter;
					    if ((1U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__Vfuncout = 0U;
					    }
					    if ((2U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__Vfuncout = 1U;
					    }
					    if ((4U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__Vfuncout = 2U;
					    }
					    if ((8U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__Vfuncout = 3U;
					    }
					    if ((0x10U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__Vfuncout = 4U;
					    }
					    if ((0x20U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__Vfuncout = 5U;
					    }
					    if ((0x40U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__Vfuncout = 6U;
					    }
					    if ((0x80U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__Vfuncout = 7U;
					    }
					    if ((0x100U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__Vfuncout = 8U;
					    }
					    if ((0x200U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__Vfuncout = 9U;
					    }
					    if ((0x400U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__Vfuncout = 0xaU;
					    }
					    if ((0x800U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__Vfuncout = 0xbU;
					    }
					    if ((0x1000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__Vfuncout = 0xcU;
					    }
					    if ((0x2000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__Vfuncout = 0xdU;
					    }
					    if ((0x4000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__Vfuncout = 0xeU;
					    }
					    if ((0x8000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__Vfuncout = 0xfU;
					    }
					    if ((0x10000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__Vfuncout = 0x10U;
					    }
					    if ((0x20000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__Vfuncout = 0x11U;
					    }
					    if ((0x40000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__Vfuncout = 0x12U;
					    }
					    if ((0x80000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__Vfuncout = 0x13U;
					    }
					    if ((0x100000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__Vfuncout = 0x14U;
					    }
					    if ((0x200000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__Vfuncout = 0x15U;
					    }
					    if ((0x400000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__Vfuncout = 0x16U;
					    }
					    if ((0x800000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__Vfuncout = 0x17U;
					    }
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__lead_one 
						= vlTOPp->__Vfunc_float_block__DOT__findLeadOne__71__Vfuncout;
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result 
						= (
						   (0x807fffffU 
						    & vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result) 
						   | (0x7f800000U 
						      & (((vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in1 
							   >> 0x17U) 
							  - 
							  ((IData)(0x17U) 
							   - (IData)(vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__lead_one))) 
							 << 0x17U)));
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result 
						= (
						   (0xff800000U 
						    & vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result) 
						   | (0x7fffffU 
						      & ((0x16U 
							  >= 
							  (0x3fU 
							   & ((IData)(0x17U) 
							      - (IData)(vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__lead_one))))
							  ? 
							 (vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter 
							  << 
							  (0x3fU 
							   & ((IData)(0x17U) 
							      - (IData)(vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__lead_one))))
							  : 0U)));
					} else {
					    // Function: findLeadOne at rtl/float_block.v:401
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter 
						= (0xffffffU 
						   & ((0x7fffffU 
						       & vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in1) 
						      - vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter));
					    if (VL_GTS_III(1,24,24, 0U, vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter)) {
						vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter 
						    = 
						    (0xffffffU 
						     & ((IData)(1U) 
							+ 
							(~ vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter)));
						vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result 
						    = 
						    (0x80000000U 
						     | vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result);
					    }
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__num 
						= vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter;
					    if ((1U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__Vfuncout = 0U;
					    }
					    if ((2U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__Vfuncout = 1U;
					    }
					    if ((4U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__Vfuncout = 2U;
					    }
					    if ((8U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__Vfuncout = 3U;
					    }
					    if ((0x10U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__Vfuncout = 4U;
					    }
					    if ((0x20U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__Vfuncout = 5U;
					    }
					    if ((0x40U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__Vfuncout = 6U;
					    }
					    if ((0x80U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__Vfuncout = 7U;
					    }
					    if ((0x100U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__Vfuncout = 8U;
					    }
					    if ((0x200U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__Vfuncout = 9U;
					    }
					    if ((0x400U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__Vfuncout = 0xaU;
					    }
					    if ((0x800U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__Vfuncout = 0xbU;
					    }
					    if ((0x1000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__Vfuncout = 0xcU;
					    }
					    if ((0x2000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__Vfuncout = 0xdU;
					    }
					    if ((0x4000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__Vfuncout = 0xeU;
					    }
					    if ((0x8000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__Vfuncout = 0xfU;
					    }
					    if ((0x10000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__Vfuncout = 0x10U;
					    }
					    if ((0x20000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__Vfuncout = 0x11U;
					    }
					    if ((0x40000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__Vfuncout = 0x12U;
					    }
					    if ((0x80000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__Vfuncout = 0x13U;
					    }
					    if ((0x100000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__Vfuncout = 0x14U;
					    }
					    if ((0x200000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__Vfuncout = 0x15U;
					    }
					    if ((0x400000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__Vfuncout = 0x16U;
					    }
					    if ((0x800000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__Vfuncout = 0x17U;
					    }
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__lead_one 
						= vlTOPp->__Vfunc_float_block__DOT__findLeadOne__72__Vfuncout;
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result 
						= (
						   (0x807fffffU 
						    & vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result) 
						   | (0x7f800000U 
						      & (((vlTOPp->__Vfunc_float_block__DOT__addFloats__63__float_in1 
							   >> 0x17U) 
							  - 
							  ((IData)(0x17U) 
							   - (IData)(vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__lead_one))) 
							 << 0x17U)));
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result 
						= (
						   (0xff800000U 
						    & vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result) 
						   | (0x7fffffU 
						      & ((0x16U 
							  >= 
							  (0x3fU 
							   & ((IData)(0x17U) 
							      - (IData)(vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__lead_one))))
							  ? 
							 (vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter 
							  << 
							  (0x3fU 
							   & ((IData)(0x17U) 
							      - (IData)(vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__lead_one))))
							  : 0U)));
					}
				    }
				}
			    }
			    vlTOPp->__Vfunc_float_block__DOT__addFloats__63__Vfuncout 
				= vlTOPp->__Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result;
			    vlTOPp->float_low_o = vlTOPp->__Vfunc_float_block__DOT__addFloats__63__Vfuncout;
			    vlTOPp->done_o = 1U;
			} else {
			    // Function: addFloats at rtl/float_block.v:122
			    vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in2 
				= vlTOPp->float2_i;
			    vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in1 
				= vlTOPp->float1_i;
			    if (((0xffU & (vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in1 
					   >> 0x17U)) 
				 == (0xffU & (vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in2 
					      >> 0x17U)))) {
				if (VL_UNLIKELY(((1U 
						  & (vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in1 
						     >> 0x1fU)) 
						 == 
						 (1U 
						  & (vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in2 
						     >> 0x1fU))))) {
				    // Function: round_man_inter at rtl/float_block.v:301
				    vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result 
					= ((0x807fffffU 
					    & vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result) 
					   | (0x7f800000U 
					      & (((IData)(1U) 
						  + 
						  (vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in1 
						   >> 0x17U)) 
						 << 0x17U)));
				    vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter 
					= (0xffffffU 
					   & ((0x7fffffU 
					       & vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in1) 
					      + (0x7fffffU 
						 & vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in2)));
				    vlTOPp->__Vfunc_float_block__DOT__round_man_inter__74__man_inter_in 
					= vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter;
				    VL_WRITEF("intermediate mantissa: %b\n",
					      24,vlTOPp->__Vfunc_float_block__DOT__round_man_inter__74__man_inter_in);
				    if (VL_UNLIKELY(
						    ((0x100000U 
						      <= vlTOPp->__Vfunc_float_block__DOT__round_man_inter__74__man_inter_in) 
						     & (vlTOPp->__Vfunc_float_block__DOT__round_man_inter__74__man_inter_in 
							>> 1U)))) {
					VL_WRITEF("rounding\n");
					vlTOPp->__Vfunc_float_block__DOT__round_man_inter__74__Vfuncout 
					    = (0xffffffU 
					       & ((1U 
						   & vlTOPp->__Vfunc_float_block__DOT__round_man_inter__74__man_inter_in)
						   ? 
						  ((IData)(1U) 
						   + vlTOPp->__Vfunc_float_block__DOT__round_man_inter__74__man_inter_in)
						   : 
						  ((IData)(2U) 
						   + vlTOPp->__Vfunc_float_block__DOT__round_man_inter__74__man_inter_in)));
				    } else {
					vlTOPp->__Vfunc_float_block__DOT__round_man_inter__74__Vfuncout 
					    = vlTOPp->__Vfunc_float_block__DOT__round_man_inter__74__man_inter_in;
				    }
				    vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter 
					= vlTOPp->__Vfunc_float_block__DOT__round_man_inter__74__Vfuncout;
				    vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter 
					= (0xffffffU 
					   & (vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter 
					      >> 1U));
				    vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result 
					= ((0xff800000U 
					    & vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result) 
					   | (0x7fffffU 
					      & vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter));
				    vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result 
					= ((0x7fffffffU 
					    & vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result) 
					   | (0x80000000U 
					      & vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in1));
				} else {
				    if (((1U & (vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in1 
						>> 0x1fU)) 
					 > (1U & (vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in2 
						  >> 0x1fU)))) {
					// Function: findLeadOne at rtl/float_block.v:314
					vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter 
					    = (0xffffffU 
					       & ((0x7fffffU 
						   & vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in2) 
						  - 
						  (0x7fffffU 
						   & vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in1)));
					if (VL_GTS_III(1,24,24, 0U, vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter)) {
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter 
						= (0xffffffU 
						   & ((IData)(1U) 
						      + 
						      (~ vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter)));
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result 
						= (0x80000000U 
						   | vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result);
					}
					vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__num 
					    = vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter;
					if ((1U & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__Vfuncout = 0U;
					}
					if ((2U & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__Vfuncout = 1U;
					}
					if ((4U & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__Vfuncout = 2U;
					}
					if ((8U & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__Vfuncout = 3U;
					}
					if ((0x10U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__Vfuncout = 4U;
					}
					if ((0x20U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__Vfuncout = 5U;
					}
					if ((0x40U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__Vfuncout = 6U;
					}
					if ((0x80U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__Vfuncout = 7U;
					}
					if ((0x100U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__Vfuncout = 8U;
					}
					if ((0x200U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__Vfuncout = 9U;
					}
					if ((0x400U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__Vfuncout = 0xaU;
					}
					if ((0x800U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__Vfuncout = 0xbU;
					}
					if ((0x1000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__Vfuncout = 0xcU;
					}
					if ((0x2000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__Vfuncout = 0xdU;
					}
					if ((0x4000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__Vfuncout = 0xeU;
					}
					if ((0x8000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__Vfuncout = 0xfU;
					}
					if ((0x10000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__Vfuncout = 0x10U;
					}
					if ((0x20000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__Vfuncout = 0x11U;
					}
					if ((0x40000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__Vfuncout = 0x12U;
					}
					if ((0x80000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__Vfuncout = 0x13U;
					}
					if ((0x100000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__Vfuncout = 0x14U;
					}
					if ((0x200000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__Vfuncout = 0x15U;
					}
					if ((0x400000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__Vfuncout = 0x16U;
					}
					if ((0x800000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__Vfuncout = 0x17U;
					}
					vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__lead_one 
					    = vlTOPp->__Vfunc_float_block__DOT__findLeadOne__75__Vfuncout;
					vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result 
					    = ((0x807fffffU 
						& vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result) 
					       | (0x7f800000U 
						  & (((vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in1 
						       >> 0x17U) 
						      - 
						      ((IData)(1U) 
						       + 
						       ((IData)(0x17U) 
							- (IData)(vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__lead_one)))) 
						     << 0x17U)));
					vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result 
					    = ((0xff800000U 
						& vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result) 
					       | (0x7fffffU 
						  & ((0x16U 
						      >= 
						      (0x3fU 
						       & ((IData)(0x18U) 
							  - (IData)(vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__lead_one))))
						      ? 
						     (vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter 
						      << 
						      (0x3fU 
						       & ((IData)(0x18U) 
							  - (IData)(vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__lead_one))))
						      : 0U)));
				    } else {
					// Function: findLeadOne at rtl/float_block.v:325
					vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter 
					    = (0xffffffU 
					       & ((0x7fffffU 
						   & vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in1) 
						  - 
						  (0x7fffffU 
						   & vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in2)));
					if (VL_GTS_III(1,24,24, 0U, vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter)) {
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter 
						= (0xffffffU 
						   & ((IData)(1U) 
						      + 
						      (~ vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter)));
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result 
						= (0x80000000U 
						   | vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result);
					}
					vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__num 
					    = vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter;
					if ((1U & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__Vfuncout = 0U;
					}
					if ((2U & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__Vfuncout = 1U;
					}
					if ((4U & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__Vfuncout = 2U;
					}
					if ((8U & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__Vfuncout = 3U;
					}
					if ((0x10U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__Vfuncout = 4U;
					}
					if ((0x20U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__Vfuncout = 5U;
					}
					if ((0x40U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__Vfuncout = 6U;
					}
					if ((0x80U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__Vfuncout = 7U;
					}
					if ((0x100U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__Vfuncout = 8U;
					}
					if ((0x200U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__Vfuncout = 9U;
					}
					if ((0x400U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__Vfuncout = 0xaU;
					}
					if ((0x800U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__Vfuncout = 0xbU;
					}
					if ((0x1000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__Vfuncout = 0xcU;
					}
					if ((0x2000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__Vfuncout = 0xdU;
					}
					if ((0x4000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__Vfuncout = 0xeU;
					}
					if ((0x8000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__Vfuncout = 0xfU;
					}
					if ((0x10000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__Vfuncout = 0x10U;
					}
					if ((0x20000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__Vfuncout = 0x11U;
					}
					if ((0x40000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__Vfuncout = 0x12U;
					}
					if ((0x80000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__Vfuncout = 0x13U;
					}
					if ((0x100000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__Vfuncout = 0x14U;
					}
					if ((0x200000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__Vfuncout = 0x15U;
					}
					if ((0x400000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__Vfuncout = 0x16U;
					}
					if ((0x800000U 
					     & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__num)) {
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__Vfuncout = 0x17U;
					}
					vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__lead_one 
					    = vlTOPp->__Vfunc_float_block__DOT__findLeadOne__76__Vfuncout;
					vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result 
					    = ((0x807fffffU 
						& vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result) 
					       | (0x7f800000U 
						  & (((vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in1 
						       >> 0x17U) 
						      - 
						      ((IData)(1U) 
						       + 
						       ((IData)(0x17U) 
							- (IData)(vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__lead_one)))) 
						     << 0x17U)));
					vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result 
					    = ((0xff800000U 
						& vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result) 
					       | (0x7fffffU 
						  & ((0x16U 
						      >= 
						      (0x3fU 
						       & ((IData)(0x18U) 
							  - (IData)(vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__lead_one))))
						      ? 
						     (vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter 
						      << 
						      (0x3fU 
						       & ((IData)(0x18U) 
							  - (IData)(vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__lead_one))))
						      : 0U)));
				    }
				}
			    } else {
				if (((0xffU & (vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in1 
					       >> 0x17U)) 
				     < (0xffU & (vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in2 
						 >> 0x17U)))) {
				    vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter 
					= (0xffffffU 
					   & ((0x17U 
					       >= (0xffU 
						   & ((vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in2 
						       >> 0x17U) 
						      - 
						      (vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in1 
						       >> 0x17U))))
					       ? ((0x800000U 
						   | (0x7fffffU 
						      & vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in1)) 
						  >> 
						  (0xffU 
						   & ((vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in2 
						       >> 0x17U) 
						      - 
						      (vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in1 
						       >> 0x17U))))
					       : 0U));
				    if (((1U & (vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in1 
						>> 0x1fU)) 
					 == (1U & (vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in2 
						   >> 0x1fU)))) {
					vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter 
					    = (0xffffffU 
					       & (vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter 
						  + 
						  (0x7fffffU 
						   & vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in2)));
					vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result 
					    = ((0x807fffffU 
						& vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result) 
					       | (0x7f800000U 
						  & (((vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in2 
						       >> 0x17U) 
						      + 
						      (1U 
						       & (vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter 
							  >> 0x17U))) 
						     << 0x17U)));
					if (VL_UNLIKELY(
							(0x800000U 
							 & vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter))) {
					    // Function: round_man_inter at rtl/float_block.v:341
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter 
						= (0x7fffffU 
						   & vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter);
					    vlTOPp->__Vfunc_float_block__DOT__round_man_inter__77__man_inter_in 
						= vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter;
					    VL_WRITEF("intermediate mantissa: %b\n",
						      24,
						      vlTOPp->__Vfunc_float_block__DOT__round_man_inter__77__man_inter_in);
					    if (VL_UNLIKELY(
							    ((0x100000U 
							      <= vlTOPp->__Vfunc_float_block__DOT__round_man_inter__77__man_inter_in) 
							     & (vlTOPp->__Vfunc_float_block__DOT__round_man_inter__77__man_inter_in 
								>> 1U)))) {
						VL_WRITEF("rounding\n");
						vlTOPp->__Vfunc_float_block__DOT__round_man_inter__77__Vfuncout 
						    = 
						    (0xffffffU 
						     & ((1U 
							 & vlTOPp->__Vfunc_float_block__DOT__round_man_inter__77__man_inter_in)
							 ? 
							((IData)(1U) 
							 + vlTOPp->__Vfunc_float_block__DOT__round_man_inter__77__man_inter_in)
							 : 
							((IData)(2U) 
							 + vlTOPp->__Vfunc_float_block__DOT__round_man_inter__77__man_inter_in)));
					    } else {
						vlTOPp->__Vfunc_float_block__DOT__round_man_inter__77__Vfuncout 
						    = vlTOPp->__Vfunc_float_block__DOT__round_man_inter__77__man_inter_in;
					    }
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter 
						= vlTOPp->__Vfunc_float_block__DOT__round_man_inter__77__Vfuncout;
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter 
						= (0xffffffU 
						   & (vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter 
						      >> 1U));
					}
					vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result 
					    = ((0xff800000U 
						& vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result) 
					       | (0x7fffffU 
						  & vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter));
					vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result 
					    = ((0x7fffffffU 
						& vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result) 
					       | (0x80000000U 
						  & vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in1));
				    } else {
					if (((1U & 
					      (vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in1 
					       >> 0x1fU)) 
					     > (1U 
						& (vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in2 
						   >> 0x1fU)))) {
					    // Function: findLeadOne at rtl/float_block.v:354
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter 
						= (0xffffffU 
						   & ((0x7fffffU 
						       & vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in2) 
						      - vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter));
					    if (VL_GTS_III(1,24,24, 0U, vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter)) {
						vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter 
						    = 
						    (0xffffffU 
						     & ((IData)(1U) 
							+ 
							(~ vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter)));
						vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result 
						    = 
						    (0x80000000U 
						     | vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result);
					    } else {
						vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result 
						    = 
						    (0x7fffffffU 
						     & vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result);
					    }
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__num 
						= vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter;
					    if ((1U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__Vfuncout = 0U;
					    }
					    if ((2U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__Vfuncout = 1U;
					    }
					    if ((4U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__Vfuncout = 2U;
					    }
					    if ((8U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__Vfuncout = 3U;
					    }
					    if ((0x10U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__Vfuncout = 4U;
					    }
					    if ((0x20U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__Vfuncout = 5U;
					    }
					    if ((0x40U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__Vfuncout = 6U;
					    }
					    if ((0x80U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__Vfuncout = 7U;
					    }
					    if ((0x100U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__Vfuncout = 8U;
					    }
					    if ((0x200U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__Vfuncout = 9U;
					    }
					    if ((0x400U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__Vfuncout = 0xaU;
					    }
					    if ((0x800U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__Vfuncout = 0xbU;
					    }
					    if ((0x1000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__Vfuncout = 0xcU;
					    }
					    if ((0x2000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__Vfuncout = 0xdU;
					    }
					    if ((0x4000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__Vfuncout = 0xeU;
					    }
					    if ((0x8000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__Vfuncout = 0xfU;
					    }
					    if ((0x10000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__Vfuncout = 0x10U;
					    }
					    if ((0x20000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__Vfuncout = 0x11U;
					    }
					    if ((0x40000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__Vfuncout = 0x12U;
					    }
					    if ((0x80000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__Vfuncout = 0x13U;
					    }
					    if ((0x100000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__Vfuncout = 0x14U;
					    }
					    if ((0x200000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__Vfuncout = 0x15U;
					    }
					    if ((0x400000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__Vfuncout = 0x16U;
					    }
					    if ((0x800000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__Vfuncout = 0x17U;
					    }
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__lead_one 
						= vlTOPp->__Vfunc_float_block__DOT__findLeadOne__78__Vfuncout;
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result 
						= (
						   (0x807fffffU 
						    & vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result) 
						   | (0x7f800000U 
						      & (((vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in2 
							   >> 0x17U) 
							  - 
							  ((IData)(0x17U) 
							   - (IData)(vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__lead_one))) 
							 << 0x17U)));
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result 
						= (
						   (0xff800000U 
						    & vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result) 
						   | (0x7fffffU 
						      & ((0x16U 
							  >= 
							  (0x3fU 
							   & ((IData)(0x17U) 
							      - (IData)(vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__lead_one))))
							  ? 
							 (vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter 
							  << 
							  (0x3fU 
							   & ((IData)(0x17U) 
							      - (IData)(vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__lead_one))))
							  : 0U)));
					} else {
					    // Function: findLeadOne at rtl/float_block.v:364
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter 
						= (0xffffffU 
						   & ((0x7fffffU 
						       & vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in2) 
						      - vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter));
					    if (VL_GTS_III(1,24,24, 0U, vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter)) {
						vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter 
						    = 
						    (0xffffffU 
						     & ((IData)(1U) 
							+ 
							(~ vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter)));
						vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result 
						    = 
						    (0x80000000U 
						     | vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result);
					    }
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__num 
						= vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter;
					    if ((1U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__Vfuncout = 0U;
					    }
					    if ((2U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__Vfuncout = 1U;
					    }
					    if ((4U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__Vfuncout = 2U;
					    }
					    if ((8U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__Vfuncout = 3U;
					    }
					    if ((0x10U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__Vfuncout = 4U;
					    }
					    if ((0x20U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__Vfuncout = 5U;
					    }
					    if ((0x40U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__Vfuncout = 6U;
					    }
					    if ((0x80U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__Vfuncout = 7U;
					    }
					    if ((0x100U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__Vfuncout = 8U;
					    }
					    if ((0x200U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__Vfuncout = 9U;
					    }
					    if ((0x400U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__Vfuncout = 0xaU;
					    }
					    if ((0x800U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__Vfuncout = 0xbU;
					    }
					    if ((0x1000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__Vfuncout = 0xcU;
					    }
					    if ((0x2000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__Vfuncout = 0xdU;
					    }
					    if ((0x4000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__Vfuncout = 0xeU;
					    }
					    if ((0x8000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__Vfuncout = 0xfU;
					    }
					    if ((0x10000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__Vfuncout = 0x10U;
					    }
					    if ((0x20000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__Vfuncout = 0x11U;
					    }
					    if ((0x40000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__Vfuncout = 0x12U;
					    }
					    if ((0x80000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__Vfuncout = 0x13U;
					    }
					    if ((0x100000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__Vfuncout = 0x14U;
					    }
					    if ((0x200000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__Vfuncout = 0x15U;
					    }
					    if ((0x400000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__Vfuncout = 0x16U;
					    }
					    if ((0x800000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__Vfuncout = 0x17U;
					    }
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__lead_one 
						= vlTOPp->__Vfunc_float_block__DOT__findLeadOne__79__Vfuncout;
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result 
						= (
						   (0x807fffffU 
						    & vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result) 
						   | (0x7f800000U 
						      & (((vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in2 
							   >> 0x17U) 
							  - 
							  ((IData)(0x17U) 
							   - (IData)(vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__lead_one))) 
							 << 0x17U)));
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result 
						= (
						   (0xff800000U 
						    & vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result) 
						   | (0x7fffffU 
						      & ((0x16U 
							  >= 
							  (0x3fU 
							   & ((IData)(0x17U) 
							      - (IData)(vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__lead_one))))
							  ? 
							 (vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter 
							  << 
							  (0x3fU 
							   & ((IData)(0x17U) 
							      - (IData)(vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__lead_one))))
							  : 0U)));
					}
				    }
				} else {
				    vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter 
					= (0xffffffU 
					   & ((0x17U 
					       >= (0xffU 
						   & ((vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in1 
						       >> 0x17U) 
						      - 
						      (vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in2 
						       >> 0x17U))))
					       ? ((0x800000U 
						   | (0x7fffffU 
						      & vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in2)) 
						  >> 
						  (0xffU 
						   & ((vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in1 
						       >> 0x17U) 
						      - 
						      (vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in2 
						       >> 0x17U))))
					       : 0U));
				    if (((1U & (vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in1 
						>> 0x1fU)) 
					 == (1U & (vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in2 
						   >> 0x1fU)))) {
					vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter 
					    = (0xffffffU 
					       & (vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter 
						  + 
						  (0x7fffffU 
						   & vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in1)));
					vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result 
					    = ((0x807fffffU 
						& vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result) 
					       | (0x7f800000U 
						  & (((vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in1 
						       >> 0x17U) 
						      + 
						      (1U 
						       & (vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter 
							  >> 0x17U))) 
						     << 0x17U)));
					if (VL_UNLIKELY(
							(0x800000U 
							 & vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter))) {
					    // Function: round_man_inter at rtl/float_block.v:378
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter 
						= (0x7fffffU 
						   & vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter);
					    vlTOPp->__Vfunc_float_block__DOT__round_man_inter__80__man_inter_in 
						= vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter;
					    VL_WRITEF("intermediate mantissa: %b\n",
						      24,
						      vlTOPp->__Vfunc_float_block__DOT__round_man_inter__80__man_inter_in);
					    if (VL_UNLIKELY(
							    ((0x100000U 
							      <= vlTOPp->__Vfunc_float_block__DOT__round_man_inter__80__man_inter_in) 
							     & (vlTOPp->__Vfunc_float_block__DOT__round_man_inter__80__man_inter_in 
								>> 1U)))) {
						VL_WRITEF("rounding\n");
						vlTOPp->__Vfunc_float_block__DOT__round_man_inter__80__Vfuncout 
						    = 
						    (0xffffffU 
						     & ((1U 
							 & vlTOPp->__Vfunc_float_block__DOT__round_man_inter__80__man_inter_in)
							 ? 
							((IData)(1U) 
							 + vlTOPp->__Vfunc_float_block__DOT__round_man_inter__80__man_inter_in)
							 : 
							((IData)(2U) 
							 + vlTOPp->__Vfunc_float_block__DOT__round_man_inter__80__man_inter_in)));
					    } else {
						vlTOPp->__Vfunc_float_block__DOT__round_man_inter__80__Vfuncout 
						    = vlTOPp->__Vfunc_float_block__DOT__round_man_inter__80__man_inter_in;
					    }
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter 
						= vlTOPp->__Vfunc_float_block__DOT__round_man_inter__80__Vfuncout;
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter 
						= (0xffffffU 
						   & (vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter 
						      >> 1U));
					}
					vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result 
					    = ((0xff800000U 
						& vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result) 
					       | (0x7fffffU 
						  & vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter));
					vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result 
					    = ((0x7fffffffU 
						& vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result) 
					       | (0x80000000U 
						  & vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in1));
				    } else {
					if (((1U & 
					      (vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in1 
					       >> 0x1fU)) 
					     > (1U 
						& (vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in2 
						   >> 0x1fU)))) {
					    // Function: findLeadOne at rtl/float_block.v:391
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter 
						= (0xffffffU 
						   & (vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter 
						      - 
						      (0x7fffffU 
						       & vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in1)));
					    if (VL_GTS_III(1,24,24, 0U, vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter)) {
						vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter 
						    = 
						    (0xffffffU 
						     & ((IData)(1U) 
							+ 
							(~ vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter)));
						vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result 
						    = 
						    (0x80000000U 
						     | vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result);
					    } else {
						vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result 
						    = 
						    (0x7fffffffU 
						     & vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result);
					    }
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__num 
						= vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter;
					    if ((1U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__Vfuncout = 0U;
					    }
					    if ((2U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__Vfuncout = 1U;
					    }
					    if ((4U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__Vfuncout = 2U;
					    }
					    if ((8U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__Vfuncout = 3U;
					    }
					    if ((0x10U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__Vfuncout = 4U;
					    }
					    if ((0x20U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__Vfuncout = 5U;
					    }
					    if ((0x40U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__Vfuncout = 6U;
					    }
					    if ((0x80U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__Vfuncout = 7U;
					    }
					    if ((0x100U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__Vfuncout = 8U;
					    }
					    if ((0x200U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__Vfuncout = 9U;
					    }
					    if ((0x400U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__Vfuncout = 0xaU;
					    }
					    if ((0x800U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__Vfuncout = 0xbU;
					    }
					    if ((0x1000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__Vfuncout = 0xcU;
					    }
					    if ((0x2000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__Vfuncout = 0xdU;
					    }
					    if ((0x4000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__Vfuncout = 0xeU;
					    }
					    if ((0x8000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__Vfuncout = 0xfU;
					    }
					    if ((0x10000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__Vfuncout = 0x10U;
					    }
					    if ((0x20000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__Vfuncout = 0x11U;
					    }
					    if ((0x40000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__Vfuncout = 0x12U;
					    }
					    if ((0x80000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__Vfuncout = 0x13U;
					    }
					    if ((0x100000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__Vfuncout = 0x14U;
					    }
					    if ((0x200000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__Vfuncout = 0x15U;
					    }
					    if ((0x400000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__Vfuncout = 0x16U;
					    }
					    if ((0x800000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__Vfuncout = 0x17U;
					    }
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__lead_one 
						= vlTOPp->__Vfunc_float_block__DOT__findLeadOne__81__Vfuncout;
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result 
						= (
						   (0x807fffffU 
						    & vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result) 
						   | (0x7f800000U 
						      & (((vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in1 
							   >> 0x17U) 
							  - 
							  ((IData)(0x17U) 
							   - (IData)(vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__lead_one))) 
							 << 0x17U)));
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result 
						= (
						   (0xff800000U 
						    & vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result) 
						   | (0x7fffffU 
						      & ((0x16U 
							  >= 
							  (0x3fU 
							   & ((IData)(0x17U) 
							      - (IData)(vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__lead_one))))
							  ? 
							 (vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter 
							  << 
							  (0x3fU 
							   & ((IData)(0x17U) 
							      - (IData)(vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__lead_one))))
							  : 0U)));
					} else {
					    // Function: findLeadOne at rtl/float_block.v:401
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter 
						= (0xffffffU 
						   & ((0x7fffffU 
						       & vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in1) 
						      - vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter));
					    if (VL_GTS_III(1,24,24, 0U, vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter)) {
						vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter 
						    = 
						    (0xffffffU 
						     & ((IData)(1U) 
							+ 
							(~ vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter)));
						vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result 
						    = 
						    (0x80000000U 
						     | vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result);
					    }
					    vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__num 
						= vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter;
					    if ((1U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__Vfuncout = 0U;
					    }
					    if ((2U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__Vfuncout = 1U;
					    }
					    if ((4U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__Vfuncout = 2U;
					    }
					    if ((8U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__Vfuncout = 3U;
					    }
					    if ((0x10U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__Vfuncout = 4U;
					    }
					    if ((0x20U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__Vfuncout = 5U;
					    }
					    if ((0x40U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__Vfuncout = 6U;
					    }
					    if ((0x80U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__Vfuncout = 7U;
					    }
					    if ((0x100U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__Vfuncout = 8U;
					    }
					    if ((0x200U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__Vfuncout = 9U;
					    }
					    if ((0x400U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__Vfuncout = 0xaU;
					    }
					    if ((0x800U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__Vfuncout = 0xbU;
					    }
					    if ((0x1000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__Vfuncout = 0xcU;
					    }
					    if ((0x2000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__Vfuncout = 0xdU;
					    }
					    if ((0x4000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__Vfuncout = 0xeU;
					    }
					    if ((0x8000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__Vfuncout = 0xfU;
					    }
					    if ((0x10000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__Vfuncout = 0x10U;
					    }
					    if ((0x20000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__Vfuncout = 0x11U;
					    }
					    if ((0x40000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__Vfuncout = 0x12U;
					    }
					    if ((0x80000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__Vfuncout = 0x13U;
					    }
					    if ((0x100000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__Vfuncout = 0x14U;
					    }
					    if ((0x200000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__Vfuncout = 0x15U;
					    }
					    if ((0x400000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__Vfuncout = 0x16U;
					    }
					    if ((0x800000U 
						 & vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__num)) {
						vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__Vfuncout = 0x17U;
					    }
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__lead_one 
						= vlTOPp->__Vfunc_float_block__DOT__findLeadOne__82__Vfuncout;
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result 
						= (
						   (0x807fffffU 
						    & vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result) 
						   | (0x7f800000U 
						      & (((vlTOPp->__Vfunc_float_block__DOT__addFloats__73__float_in1 
							   >> 0x17U) 
							  - 
							  ((IData)(0x17U) 
							   - (IData)(vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__lead_one))) 
							 << 0x17U)));
					    vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result 
						= (
						   (0xff800000U 
						    & vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result) 
						   | (0x7fffffU 
						      & ((0x16U 
							  >= 
							  (0x3fU 
							   & ((IData)(0x17U) 
							      - (IData)(vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__lead_one))))
							  ? 
							 (vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter 
							  << 
							  (0x3fU 
							   & ((IData)(0x17U) 
							      - (IData)(vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__lead_one))))
							  : 0U)));
					}
				    }
				}
			    }
			    vlTOPp->__Vfunc_float_block__DOT__addFloats__73__Vfuncout 
				= vlTOPp->__Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result;
			    vlTOPp->float_low_o = vlTOPp->__Vfunc_float_block__DOT__addFloats__73__Vfuncout;
			    vlTOPp->done_o = 1U;
			}
		    }
		}
	    }
	}
    }
}

void Vfloat_block::_eval(Vfloat_block__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfloat_block::_eval\n"); );
    Vfloat_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void Vfloat_block::_eval_initial(Vfloat_block__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfloat_block::_eval_initial\n"); );
    Vfloat_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vfloat_block::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfloat_block::final\n"); );
    // Variables
    Vfloat_block__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vfloat_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vfloat_block::_eval_settle(Vfloat_block__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfloat_block::_eval_settle\n"); );
    Vfloat_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData Vfloat_block::_change_request(Vfloat_block__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfloat_block::_change_request\n"); );
    Vfloat_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vfloat_block::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfloat_block::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
	Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset_i & 0xfeU))) {
	Verilated::overWidthError("reset_i");}
    if (VL_UNLIKELY((start_i & 0xfeU))) {
	Verilated::overWidthError("start_i");}
    if (VL_UNLIKELY((opcode_i & 0xe0U))) {
	Verilated::overWidthError("opcode_i");}
}
#endif // VL_DEBUG

void Vfloat_block::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfloat_block::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset_i = VL_RAND_RESET_I(1);
    start_i = VL_RAND_RESET_I(1);
    float1_i = VL_RAND_RESET_I(32);
    float2_i = VL_RAND_RESET_I(32);
    float3_i = VL_RAND_RESET_I(32);
    opcode_i = VL_RAND_RESET_I(5);
    done_o = VL_RAND_RESET_I(1);
    exceptions_o = VL_RAND_RESET_I(4);
    float_low_o = VL_RAND_RESET_I(32);
    float_high_o = VL_RAND_RESET_I(32);
    int_o = VL_RAND_RESET_Q(64);
    __Vfunc_float_block__DOT__classifyFloat__0__Vfuncout = VL_RAND_RESET_I(10);
    __Vfunc_float_block__DOT__classifyFloat__0__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__classifyFloat__0__unnamedblk1__DOT__mask = VL_RAND_RESET_I(10);
    __Vfunc_float_block__DOT__isNan__1__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__1__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__2__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__2__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__floatLess__3__Vfuncout = VL_RAND_RESET_I(1);
    __Vfunc_float_block__DOT__floatLess__3__float_in1 = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__floatLess__3__float_in2 = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__floatEquality__4__Vfuncout = VL_RAND_RESET_I(1);
    __Vfunc_float_block__DOT__floatEquality__4__float_in1 = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__floatEquality__4__float_in2 = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__5__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__5__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__6__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__6__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__floatEquality__7__Vfuncout = VL_RAND_RESET_I(1);
    __Vfunc_float_block__DOT__floatEquality__7__float_in1 = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__floatEquality__7__float_in2 = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__8__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__8__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__9__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__9__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__10__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__10__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__11__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__11__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__floatLess__12__Vfuncout = VL_RAND_RESET_I(1);
    __Vfunc_float_block__DOT__floatLess__12__float_in1 = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__floatLess__12__float_in2 = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__floatEquality__13__Vfuncout = VL_RAND_RESET_I(1);
    __Vfunc_float_block__DOT__floatEquality__13__float_in1 = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__floatEquality__13__float_in2 = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__14__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__14__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__15__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__15__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__16__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__16__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__17__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__17__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__floatEquality__18__Vfuncout = VL_RAND_RESET_I(1);
    __Vfunc_float_block__DOT__floatEquality__18__float_in1 = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__floatEquality__18__float_in2 = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__19__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__19__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__20__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__20__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__maxFloat__21__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__maxFloat__21__float_in1 = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__maxFloat__21__float_in2 = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__minFloat__22__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__minFloat__22__float_in1 = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__minFloat__22__float_in2 = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__floatEquality__23__Vfuncout = VL_RAND_RESET_I(1);
    __Vfunc_float_block__DOT__floatEquality__23__float_in1 = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__floatEquality__23__float_in2 = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__floatLess__24__Vfuncout = VL_RAND_RESET_I(1);
    __Vfunc_float_block__DOT__floatLess__24__float_in1 = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__floatLess__24__float_in2 = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__floatEquality__25__Vfuncout = VL_RAND_RESET_I(1);
    __Vfunc_float_block__DOT__floatEquality__25__float_in1 = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__floatEquality__25__float_in2 = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__26__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__26__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__27__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__27__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__28__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__28__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__29__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__29__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__30__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__30__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__31__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__31__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__32__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__32__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__33__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__33__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__34__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__34__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__35__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__35__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__36__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__36__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__37__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__37__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__38__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__38__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__39__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__39__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__40__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__40__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__41__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__41__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__42__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__42__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__43__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__43__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__44__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__44__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__45__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__45__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__minFloat__46__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__minFloat__46__float_in1 = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__minFloat__46__float_in2 = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__floatEquality__47__Vfuncout = VL_RAND_RESET_I(1);
    __Vfunc_float_block__DOT__floatEquality__47__float_in1 = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__floatEquality__47__float_in2 = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__floatLess__48__Vfuncout = VL_RAND_RESET_I(1);
    __Vfunc_float_block__DOT__floatLess__48__float_in1 = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__floatLess__48__float_in2 = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__floatEquality__49__Vfuncout = VL_RAND_RESET_I(1);
    __Vfunc_float_block__DOT__floatEquality__49__float_in1 = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__floatEquality__49__float_in2 = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__50__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__50__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__51__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__51__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__52__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__52__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__53__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__53__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__54__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__54__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__55__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__55__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__56__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__56__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__57__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__57__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__58__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__58__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__59__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__59__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__60__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__60__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__61__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__61__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__isNan__62__Vfuncout = VL_RAND_RESET_I(2);
    __Vfunc_float_block__DOT__isNan__62__float_in = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__addFloats__63__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__addFloats__63__float_in1 = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__addFloats__63__float_in2 = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__result = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__man_inter = VL_RAND_RESET_I(24);
    __Vfunc_float_block__DOT__addFloats__63__unnamedblk2__DOT__lead_one = VL_RAND_RESET_I(5);
    __Vfunc_float_block__DOT__round_man_inter__64__Vfuncout = VL_RAND_RESET_I(24);
    __Vfunc_float_block__DOT__round_man_inter__64__man_inter_in = VL_RAND_RESET_I(24);
    __Vfunc_float_block__DOT__findLeadOne__65__Vfuncout = VL_RAND_RESET_I(5);
    __Vfunc_float_block__DOT__findLeadOne__65__num = VL_RAND_RESET_I(24);
    __Vfunc_float_block__DOT__findLeadOne__66__Vfuncout = VL_RAND_RESET_I(5);
    __Vfunc_float_block__DOT__findLeadOne__66__num = VL_RAND_RESET_I(24);
    __Vfunc_float_block__DOT__round_man_inter__67__Vfuncout = VL_RAND_RESET_I(24);
    __Vfunc_float_block__DOT__round_man_inter__67__man_inter_in = VL_RAND_RESET_I(24);
    __Vfunc_float_block__DOT__findLeadOne__68__Vfuncout = VL_RAND_RESET_I(5);
    __Vfunc_float_block__DOT__findLeadOne__68__num = VL_RAND_RESET_I(24);
    __Vfunc_float_block__DOT__findLeadOne__69__Vfuncout = VL_RAND_RESET_I(5);
    __Vfunc_float_block__DOT__findLeadOne__69__num = VL_RAND_RESET_I(24);
    __Vfunc_float_block__DOT__round_man_inter__70__Vfuncout = VL_RAND_RESET_I(24);
    __Vfunc_float_block__DOT__round_man_inter__70__man_inter_in = VL_RAND_RESET_I(24);
    __Vfunc_float_block__DOT__findLeadOne__71__Vfuncout = VL_RAND_RESET_I(5);
    __Vfunc_float_block__DOT__findLeadOne__71__num = VL_RAND_RESET_I(24);
    __Vfunc_float_block__DOT__findLeadOne__72__Vfuncout = VL_RAND_RESET_I(5);
    __Vfunc_float_block__DOT__findLeadOne__72__num = VL_RAND_RESET_I(24);
    __Vfunc_float_block__DOT__addFloats__73__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__addFloats__73__float_in1 = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__addFloats__73__float_in2 = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__result = VL_RAND_RESET_I(32);
    __Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__man_inter = VL_RAND_RESET_I(24);
    __Vfunc_float_block__DOT__addFloats__73__unnamedblk2__DOT__lead_one = VL_RAND_RESET_I(5);
    __Vfunc_float_block__DOT__round_man_inter__74__Vfuncout = VL_RAND_RESET_I(24);
    __Vfunc_float_block__DOT__round_man_inter__74__man_inter_in = VL_RAND_RESET_I(24);
    __Vfunc_float_block__DOT__findLeadOne__75__Vfuncout = VL_RAND_RESET_I(5);
    __Vfunc_float_block__DOT__findLeadOne__75__num = VL_RAND_RESET_I(24);
    __Vfunc_float_block__DOT__findLeadOne__76__Vfuncout = VL_RAND_RESET_I(5);
    __Vfunc_float_block__DOT__findLeadOne__76__num = VL_RAND_RESET_I(24);
    __Vfunc_float_block__DOT__round_man_inter__77__Vfuncout = VL_RAND_RESET_I(24);
    __Vfunc_float_block__DOT__round_man_inter__77__man_inter_in = VL_RAND_RESET_I(24);
    __Vfunc_float_block__DOT__findLeadOne__78__Vfuncout = VL_RAND_RESET_I(5);
    __Vfunc_float_block__DOT__findLeadOne__78__num = VL_RAND_RESET_I(24);
    __Vfunc_float_block__DOT__findLeadOne__79__Vfuncout = VL_RAND_RESET_I(5);
    __Vfunc_float_block__DOT__findLeadOne__79__num = VL_RAND_RESET_I(24);
    __Vfunc_float_block__DOT__round_man_inter__80__Vfuncout = VL_RAND_RESET_I(24);
    __Vfunc_float_block__DOT__round_man_inter__80__man_inter_in = VL_RAND_RESET_I(24);
    __Vfunc_float_block__DOT__findLeadOne__81__Vfuncout = VL_RAND_RESET_I(5);
    __Vfunc_float_block__DOT__findLeadOne__81__num = VL_RAND_RESET_I(24);
    __Vfunc_float_block__DOT__findLeadOne__82__Vfuncout = VL_RAND_RESET_I(5);
    __Vfunc_float_block__DOT__findLeadOne__82__num = VL_RAND_RESET_I(24);
    __Vm_traceActivity = VL_RAND_RESET_I(32);
}
