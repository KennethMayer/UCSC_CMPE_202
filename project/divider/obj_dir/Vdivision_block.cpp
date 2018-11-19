// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdivision_block.h for the primary calling header

#include "Vdivision_block.h"   // For This
#include "Vdivision_block__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vdivision_block) {
    Vdivision_block__Syms* __restrict vlSymsp = __VlSymsp = new Vdivision_block__Syms(this, name());
    Vdivision_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vdivision_block::__Vconfigure(Vdivision_block__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vdivision_block::~Vdivision_block() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vdivision_block::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vdivision_block::eval\n"); );
    Vdivision_block__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vdivision_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vdivision_block::_eval_initial_loop(Vdivision_block__Syms* __restrict vlSymsp) {
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

VL_INLINE_OPT void Vdivision_block::_sequent__TOP__1(Vdivision_block__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivision_block::_sequent__TOP__1\n"); );
    Vdivision_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/flop.v:13
    vlTOPp->remainder_o = ((IData)(vlTOPp->reset_i)
			    ? VL_ULL(0) : (((QData)((IData)(
							    vlTOPp->division_block__DOT__remainder_next[3U])) 
					    << 0x20U) 
					   | (QData)((IData)(
							     vlTOPp->division_block__DOT__remainder_next[2U]))));
    // ALWAYS at rtl/flop.v:13
    vlTOPp->division_block__DOT__dividend = ((IData)(vlTOPp->reset_i)
					      ? VL_ULL(0)
					      : vlTOPp->division_block__DOT__dividend_next);
    // ALWAYS at rtl/flop.v:13
    vlTOPp->division_block__DOT__divisor = ((IData)(vlTOPp->reset_i)
					     ? VL_ULL(0)
					     : vlTOPp->division_block__DOT__divisor_next);
    // ALWAYS at rtl/flop.v:13
    vlTOPp->division_block__DOT__index = ((IData)(vlTOPp->reset_i)
					   ? 0U : (IData)(vlTOPp->division_block__DOT__index_next));
    // ALWAYS at rtl/flop.v:13
    vlTOPp->division_block__DOT__pending = ((~ (IData)(vlTOPp->reset_i)) 
					    & (IData)(vlTOPp->division_block__DOT__pending_next));
    // ALWAYS at rtl/flop.v:13
    vlTOPp->done_o = ((~ (IData)(vlTOPp->reset_i)) 
		      & (IData)(vlTOPp->division_block__DOT__done_next));
    // ALWAYS at rtl/flop.v:13
    vlTOPp->division_block__DOT__sign = ((~ (IData)(vlTOPp->reset_i)) 
					 & (IData)(vlTOPp->division_block__DOT__sign_next));
    // ALWAYS at rtl/flop.v:13
    vlTOPp->quotient_o = ((IData)(vlTOPp->reset_i) ? VL_ULL(0)
			   : (((QData)((IData)(vlTOPp->division_block__DOT__remainder_next[1U])) 
			       << 0x20U) | (QData)((IData)(
							   vlTOPp->division_block__DOT__remainder_next[0U]))));
    // ALWAYS at rtl/flop.v:13
    vlTOPp->division_block__DOT__remainder[0U] = ((IData)(vlTOPp->reset_i)
						   ? 0U
						   : 
						  vlTOPp->division_block__DOT__remainder_next[0U]);
    vlTOPp->division_block__DOT__remainder[1U] = ((IData)(vlTOPp->reset_i)
						   ? 0U
						   : 
						  vlTOPp->division_block__DOT__remainder_next[1U]);
    vlTOPp->division_block__DOT__remainder[2U] = ((IData)(vlTOPp->reset_i)
						   ? 0U
						   : 
						  vlTOPp->division_block__DOT__remainder_next[2U]);
    vlTOPp->division_block__DOT__remainder[3U] = ((IData)(vlTOPp->reset_i)
						   ? 0U
						   : 
						  vlTOPp->division_block__DOT__remainder_next[3U]);
}

VL_INLINE_OPT void Vdivision_block::_settle__TOP__2(Vdivision_block__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivision_block::_settle__TOP__2\n"); );
    Vdivision_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIGW(__Vtemp4,95,0,3);
    VL_SIGW(__Vtemp5,95,0,3);
    VL_SIGW(__Vtemp6,95,0,3);
    // Body
    // ALWAYS at rtl/division_block.v:37
    vlTOPp->division_block__DOT__done_next = vlTOPp->done_o;
    vlTOPp->division_block__DOT__quotient_next = vlTOPp->quotient_o;
    vlTOPp->division_block__DOT__pending_next = vlTOPp->division_block__DOT__pending;
    vlTOPp->division_block__DOT__dividend_next = vlTOPp->division_block__DOT__dividend;
    vlTOPp->division_block__DOT__divisor_next = vlTOPp->division_block__DOT__divisor;
    vlTOPp->division_block__DOT__index_next = vlTOPp->division_block__DOT__index;
    vlTOPp->division_block__DOT__sign_next = vlTOPp->division_block__DOT__sign;
    if (((IData)(vlTOPp->start_i) & (~ (IData)(vlTOPp->division_block__DOT__pending)))) {
	vlTOPp->division_block__DOT__pending_next = 1U;
	vlTOPp->division_block__DOT__index_next = 0x3fU;
	if ((VL_ULL(0) == vlTOPp->divisor_i)) {
	    vlTOPp->division_block__DOT__done_next = 1U;
	    vlTOPp->division_block__DOT__quotient_next = VL_ULL(0xffffffffffffffff);
	    vlTOPp->division_block__DOT__pending_next = 0U;
	}
	vlTOPp->division_block__DOT__sign_next = (VL_GTS_IQQ(1,64,64, VL_ULL(0), vlTOPp->dividend_i) 
						  ^ 
						  VL_GTS_IQQ(1,64,64, VL_ULL(0), vlTOPp->divisor_i));
	vlTOPp->division_block__DOT__dividend_next 
	    = (VL_GTS_IQQ(1,64,64, VL_ULL(0), vlTOPp->dividend_i)
	        ? (VL_ULL(1) + (~ vlTOPp->dividend_i))
	        : vlTOPp->dividend_i);
	vlTOPp->division_block__DOT__divisor_next = 
	    (VL_GTS_IQQ(1,64,64, VL_ULL(0), vlTOPp->divisor_i)
	      ? (VL_ULL(1) + (~ vlTOPp->divisor_i))
	      : vlTOPp->divisor_i);
	vlTOPp->division_block__DOT__remainder_next[0U] 
	    = (IData)(vlTOPp->division_block__DOT__dividend_next);
	vlTOPp->division_block__DOT__remainder_next[1U] 
	    = (IData)((vlTOPp->division_block__DOT__dividend_next 
		       >> 0x20U));
    } else {
	if (vlTOPp->division_block__DOT__pending) {
	    __Vtemp4[0U] = ((vlTOPp->division_block__DOT__remainder[2U] 
			     << 1U) | (vlTOPp->division_block__DOT__remainder[1U] 
				       >> 0x1fU));
	    __Vtemp4[1U] = ((vlTOPp->division_block__DOT__remainder[3U] 
			     << 1U) | (vlTOPp->division_block__DOT__remainder[2U] 
				       >> 0x1fU));
	    __Vtemp4[2U] = (vlTOPp->division_block__DOT__remainder[3U] 
			    >> 0x1fU);
	    VL_EXTEND_WQ(65,64, __Vtemp5, vlTOPp->division_block__DOT__divisor);
	    VL_SUB_W(3, __Vtemp6, __Vtemp4, __Vtemp5);
	    vlTOPp->division_block__DOT__diff[0U] = 
		__Vtemp6[0U];
	    vlTOPp->division_block__DOT__diff[1U] = 
		__Vtemp6[1U];
	    vlTOPp->division_block__DOT__diff[2U] = 
		(1U & __Vtemp6[2U]);
	    vlTOPp->division_block__DOT__remainder_next[0U] 
		= ((1U & vlTOPp->division_block__DOT__diff[2U])
		    ? (0xfffffffeU & (vlTOPp->division_block__DOT__remainder[0U] 
				      << 1U)) : (IData)(
							(VL_ULL(1) 
							 | (VL_ULL(0xfffffffffffffffe) 
							    & (((QData)((IData)(
										vlTOPp->division_block__DOT__remainder[1U])) 
								<< 0x21U) 
							       | ((QData)((IData)(
										vlTOPp->division_block__DOT__remainder[0U])) 
								  << 1U))))));
	    vlTOPp->division_block__DOT__remainder_next[1U] 
		= ((1U & vlTOPp->division_block__DOT__diff[2U])
		    ? ((1U & (vlTOPp->division_block__DOT__remainder[0U] 
			      >> 0x1fU)) | (0xfffffffeU 
					    & (vlTOPp->division_block__DOT__remainder[1U] 
					       << 1U)))
		    : (IData)(((VL_ULL(1) | (VL_ULL(0xfffffffffffffffe) 
					     & (((QData)((IData)(
								 vlTOPp->division_block__DOT__remainder[1U])) 
						 << 0x21U) 
						| ((QData)((IData)(
								   vlTOPp->division_block__DOT__remainder[0U])) 
						   << 1U)))) 
			       >> 0x20U)));
	    vlTOPp->division_block__DOT__remainder_next[2U] 
		= ((1U & vlTOPp->division_block__DOT__diff[2U])
		    ? ((1U & (vlTOPp->division_block__DOT__remainder[1U] 
			      >> 0x1fU)) | (0xfffffffeU 
					    & (vlTOPp->division_block__DOT__remainder[2U] 
					       << 1U)))
		    : (IData)((((QData)((IData)(vlTOPp->division_block__DOT__diff[1U])) 
				<< 0x20U) | (QData)((IData)(
							    vlTOPp->division_block__DOT__diff[0U])))));
	    vlTOPp->division_block__DOT__remainder_next[3U] 
		= ((1U & vlTOPp->division_block__DOT__diff[2U])
		    ? ((1U & (vlTOPp->division_block__DOT__remainder[2U] 
			      >> 0x1fU)) | (0xfffffffeU 
					    & (vlTOPp->division_block__DOT__remainder[3U] 
					       << 1U)))
		    : (IData)(((((QData)((IData)(vlTOPp->division_block__DOT__diff[1U])) 
				 << 0x20U) | (QData)((IData)(
							     vlTOPp->division_block__DOT__diff[0U]))) 
			       >> 0x20U)));
	    vlTOPp->division_block__DOT__index_next 
		= (0x7fU & ((IData)(vlTOPp->division_block__DOT__index) 
			    - (IData)(1U)));
	    if ((0U == (IData)(vlTOPp->division_block__DOT__index))) {
		vlTOPp->division_block__DOT__pending_next = 0U;
	    }
	} else {
	    if (vlTOPp->division_block__DOT__sign) {
		vlTOPp->division_block__DOT__remainder_next[0U] 
		    = (IData)((VL_ULL(1) + (~ (((QData)((IData)(
								vlTOPp->division_block__DOT__remainder[1U])) 
						<< 0x20U) 
					       | (QData)((IData)(
								 vlTOPp->division_block__DOT__remainder[0U]))))));
		vlTOPp->division_block__DOT__remainder_next[1U] 
		    = (IData)(((VL_ULL(1) + (~ (((QData)((IData)(
								 vlTOPp->division_block__DOT__remainder[1U])) 
						 << 0x20U) 
						| (QData)((IData)(
								  vlTOPp->division_block__DOT__remainder[0U]))))) 
			       >> 0x20U));
	    }
	    vlTOPp->division_block__DOT__done_next = 1U;
	}
    }
}

void Vdivision_block::_eval(Vdivision_block__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivision_block::_eval\n"); );
    Vdivision_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
	vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_settle__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vdivision_block::_eval_initial(Vdivision_block__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivision_block::_eval_initial\n"); );
    Vdivision_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vdivision_block::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivision_block::final\n"); );
    // Variables
    Vdivision_block__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vdivision_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vdivision_block::_eval_settle(Vdivision_block__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivision_block::_eval_settle\n"); );
    Vdivision_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

VL_INLINE_OPT QData Vdivision_block::_change_request(Vdivision_block__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivision_block::_change_request\n"); );
    Vdivision_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vdivision_block::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivision_block::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
	Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset_i & 0xfeU))) {
	Verilated::overWidthError("reset_i");}
    if (VL_UNLIKELY((start_i & 0xfeU))) {
	Verilated::overWidthError("start_i");}
}
#endif // VL_DEBUG

void Vdivision_block::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdivision_block::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset_i = VL_RAND_RESET_I(1);
    start_i = VL_RAND_RESET_I(1);
    dividend_i = VL_RAND_RESET_Q(64);
    divisor_i = VL_RAND_RESET_Q(64);
    done_o = VL_RAND_RESET_I(1);
    quotient_o = VL_RAND_RESET_Q(64);
    remainder_o = VL_RAND_RESET_Q(64);
    division_block__DOT__done_next = VL_RAND_RESET_I(1);
    division_block__DOT__quotient_next = VL_RAND_RESET_Q(64);
    VL_RAND_RESET_W(128,division_block__DOT__remainder);
    VL_RAND_RESET_W(128,division_block__DOT__remainder_next);
    division_block__DOT__dividend = VL_RAND_RESET_Q(64);
    division_block__DOT__dividend_next = VL_RAND_RESET_Q(64);
    division_block__DOT__divisor = VL_RAND_RESET_Q(64);
    division_block__DOT__divisor_next = VL_RAND_RESET_Q(64);
    division_block__DOT__pending = VL_RAND_RESET_I(1);
    division_block__DOT__pending_next = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(65,division_block__DOT__diff);
    division_block__DOT__sign = VL_RAND_RESET_I(1);
    division_block__DOT__sign_next = VL_RAND_RESET_I(1);
    division_block__DOT__index = VL_RAND_RESET_I(7);
    division_block__DOT__index_next = VL_RAND_RESET_I(7);
    __Vclklast__TOP__clk = VL_RAND_RESET_I(1);
    __Vm_traceActivity = VL_RAND_RESET_I(32);
}
