// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmultiplication_block.h for the primary calling header

#include "Vmultiplication_block.h" // For This
#include "Vmultiplication_block__Syms.h"


//--------------------
// STATIC VARIABLES

VL_ST_SIG8(Vmultiplication_block::__Vtable1_multiplication_block__DOT__negate[8],0,0);
VL_ST_SIG8(Vmultiplication_block::__Vtable1_multiplication_block__DOT__zero[8],0,0);
VL_ST_SIG8(Vmultiplication_block::__Vtable1_multiplication_block__DOT__shift[8],0,0);

//--------------------

VL_CTOR_IMP(Vmultiplication_block) {
    Vmultiplication_block__Syms* __restrict vlSymsp = __VlSymsp = new Vmultiplication_block__Syms(this, name());
    Vmultiplication_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vmultiplication_block::__Vconfigure(Vmultiplication_block__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vmultiplication_block::~Vmultiplication_block() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vmultiplication_block::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmultiplication_block::eval\n"); );
    Vmultiplication_block__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vmultiplication_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vmultiplication_block::_eval_initial_loop(Vmultiplication_block__Syms* __restrict vlSymsp) {
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

VL_INLINE_OPT void Vmultiplication_block::_sequent__TOP__1(Vmultiplication_block__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmultiplication_block::_sequent__TOP__1\n"); );
    Vmultiplication_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at rtl/flop.v:13
    vlTOPp->product_low_o = ((IData)(vlTOPp->reset_i)
			      ? VL_ULL(0) : vlTOPp->multiplication_block__DOT__product_low_next);
    // ALWAYS at rtl/flop.v:13
    vlTOPp->product_high_o = ((IData)(vlTOPp->reset_i)
			       ? VL_ULL(0) : vlTOPp->multiplication_block__DOT__product_high_next);
    // ALWAYS at rtl/flop.v:13
    vlTOPp->multiplication_block__DOT__partial[0U] 
	= ((IData)(vlTOPp->reset_i) ? 0U : vlTOPp->multiplication_block__DOT__partial_next[0U]);
    vlTOPp->multiplication_block__DOT__partial[1U] 
	= ((IData)(vlTOPp->reset_i) ? 0U : vlTOPp->multiplication_block__DOT__partial_next[1U]);
    vlTOPp->multiplication_block__DOT__partial[2U] 
	= ((IData)(vlTOPp->reset_i) ? 0U : vlTOPp->multiplication_block__DOT__partial_next[2U]);
    vlTOPp->multiplication_block__DOT__partial[3U] 
	= ((IData)(vlTOPp->reset_i) ? 0U : vlTOPp->multiplication_block__DOT__partial_next[3U]);
    // ALWAYS at rtl/flop.v:13
    vlTOPp->done_o = ((~ (IData)(vlTOPp->reset_i)) 
		      & (IData)(vlTOPp->multiplication_block__DOT__done_next));
    // ALWAYS at rtl/flop.v:13
    vlTOPp->multiplication_block__DOT__index = ((IData)(vlTOPp->reset_i)
						 ? 0U
						 : (IData)(vlTOPp->multiplication_block__DOT__index_next));
    // ALWAYS at rtl/flop.v:13
    vlTOPp->multiplication_block__DOT__leading_one 
	= ((IData)(vlTOPp->reset_i) ? 0U : (IData)(vlTOPp->multiplication_block__DOT__leading_one_next));
    // ALWAYS at rtl/flop.v:13
    vlTOPp->multiplication_block__DOT__pending = ((~ (IData)(vlTOPp->reset_i)) 
						  & (IData)(vlTOPp->multiplication_block__DOT__pending_next));
    // ALWAYS at rtl/flop.v:13
    vlTOPp->multiplication_block__DOT__recode = ((IData)(vlTOPp->reset_i)
						  ? 0U
						  : (IData)(vlTOPp->multiplication_block__DOT__recode_next));
    // ALWAYS at rtl/booth_recoder.v:17
    vlTOPp->__Vtableidx1 = vlTOPp->multiplication_block__DOT__recode;
    vlTOPp->multiplication_block__DOT__negate = vlTOPp->__Vtable1_multiplication_block__DOT__negate
	[vlTOPp->__Vtableidx1];
    vlTOPp->multiplication_block__DOT__zero = vlTOPp->__Vtable1_multiplication_block__DOT__zero
	[vlTOPp->__Vtableidx1];
    vlTOPp->multiplication_block__DOT__shift = vlTOPp->__Vtable1_multiplication_block__DOT__shift
	[vlTOPp->__Vtableidx1];
}

void Vmultiplication_block::_settle__TOP__2(Vmultiplication_block__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmultiplication_block::_settle__TOP__2\n"); );
    Vmultiplication_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIGW(__Vtemp4,127,0,4);
    VL_SIGW(__Vtemp5,127,0,4);
    VL_SIGW(__Vtemp6,127,0,4);
    // Body
    // ALWAYS at rtl/booth_recoder.v:17
    vlTOPp->__Vtableidx1 = vlTOPp->multiplication_block__DOT__recode;
    vlTOPp->multiplication_block__DOT__negate = vlTOPp->__Vtable1_multiplication_block__DOT__negate
	[vlTOPp->__Vtableidx1];
    vlTOPp->multiplication_block__DOT__zero = vlTOPp->__Vtable1_multiplication_block__DOT__zero
	[vlTOPp->__Vtableidx1];
    vlTOPp->multiplication_block__DOT__shift = vlTOPp->__Vtable1_multiplication_block__DOT__shift
	[vlTOPp->__Vtableidx1];
    // ALWAYS at rtl/multiplication_block.v:36
    vlTOPp->multiplication_block__DOT__leading_one_next 
	= vlTOPp->multiplication_block__DOT__leading_one;
    vlTOPp->multiplication_block__DOT__recode_next 
	= vlTOPp->multiplication_block__DOT__recode;
    vlTOPp->multiplication_block__DOT__index_next = vlTOPp->multiplication_block__DOT__index;
    vlTOPp->multiplication_block__DOT__current = VL_ULL(0);
    vlTOPp->multiplication_block__DOT__partial_next[0U] 
	= vlTOPp->multiplication_block__DOT__partial[0U];
    vlTOPp->multiplication_block__DOT__partial_next[1U] 
	= vlTOPp->multiplication_block__DOT__partial[1U];
    vlTOPp->multiplication_block__DOT__partial_next[2U] 
	= vlTOPp->multiplication_block__DOT__partial[2U];
    vlTOPp->multiplication_block__DOT__partial_next[3U] 
	= vlTOPp->multiplication_block__DOT__partial[3U];
    vlTOPp->multiplication_block__DOT__done_next = vlTOPp->done_o;
    vlTOPp->multiplication_block__DOT__product_high_next 
	= vlTOPp->product_high_o;
    vlTOPp->multiplication_block__DOT__product_low_next 
	= vlTOPp->product_low_o;
    vlTOPp->multiplication_block__DOT__temp = VL_ULL(0);
    if (((IData)(vlTOPp->start_i) & (~ (IData)(vlTOPp->multiplication_block__DOT__pending)))) {
	// Function: find_leading_one at rtl/multiplication_block.v:47
	vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
	    = vlTOPp->multiplicand_i;
	vlTOPp->multiplication_block__DOT__pending_next = 1U;
	vlTOPp->multiplication_block__DOT__index_next = 1U;
	vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0U;
	if ((1U & (IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
			   >> 0x3fU)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x3fU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x3eU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x3eU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x3dU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x3dU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x3cU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x3cU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x3bU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x3bU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x3aU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x3aU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x39U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x39U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x38U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x38U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x37U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x37U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x36U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x36U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x35U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x35U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x34U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x34U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x33U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x33U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x32U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x32U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x31U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x31U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x30U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x30U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x2fU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x2fU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x2eU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x2eU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x2dU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x2dU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x2cU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x2cU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x2bU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x2bU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x2aU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x2aU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x29U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x29U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x28U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x28U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x27U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x27U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x26U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x26U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x25U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x25U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x24U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x24U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x23U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x23U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x22U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x22U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x21U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x21U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x20U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x20U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x1fU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x1fU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x1eU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x1eU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x1dU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x1dU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x1cU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x1cU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x1bU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x1bU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x1aU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x1aU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x19U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x19U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x18U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x18U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x17U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x17U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x16U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x16U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x15U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x15U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x14U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x14U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x13U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x13U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x12U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x12U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x11U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x11U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x10U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x10U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0xfU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0xfU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0xeU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0xeU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0xdU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0xdU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0xcU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0xcU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0xbU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0xbU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0xaU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0xaU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 9U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 9U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 8U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 8U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 7U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 7U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 6U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 6U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 5U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 5U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 4U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 4U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 3U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 3U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 2U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 2U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 1U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 1U;
	}
	if (((IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value) 
	     & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0U;
	}
	vlTOPp->multiplication_block__DOT__leading_one_next 
	    = vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out;
	vlTOPp->multiplication_block__DOT__recode_next 
	    = (6U & ((IData)(vlTOPp->multiplicand_i) 
		     << 1U));
    } else {
	if (vlTOPp->multiplication_block__DOT__pending) {
	    vlTOPp->multiplication_block__DOT__index_next 
		= (0x3fU & ((IData)(2U) + (IData)(vlTOPp->multiplication_block__DOT__index)));
	    if (vlTOPp->multiplication_block__DOT__zero) {
		vlTOPp->multiplication_block__DOT__current = VL_ULL(0);
	    } else {
		vlTOPp->multiplication_block__DOT__current 
		    = ((IData)(vlTOPp->multiplication_block__DOT__negate)
		        ? VL_NEGATE_Q(vlTOPp->multiplier_i)
		        : vlTOPp->multiplier_i);
		if (vlTOPp->multiplication_block__DOT__shift) {
		    vlTOPp->multiplication_block__DOT__current 
			= (vlTOPp->multiplication_block__DOT__current 
			   << 1U);
		}
	    }
	    vlTOPp->multiplication_block__DOT__pending_next 
		= ((~ ((0x3dU < (IData)(vlTOPp->multiplication_block__DOT__index_next)) 
		       | ((IData)(vlTOPp->multiplication_block__DOT__leading_one) 
			  < (IData)(vlTOPp->multiplication_block__DOT__index)))) 
		   & (IData)(vlTOPp->multiplication_block__DOT__pending));
	    __Vtemp4[0U] = (IData)(vlTOPp->multiplication_block__DOT__current);
	    __Vtemp4[1U] = (IData)((vlTOPp->multiplication_block__DOT__current 
				    >> 0x20U));
	    __Vtemp4[2U] = (IData)(VL_NEGATE_Q((QData)((IData)(
							       (1U 
								& (IData)(
									  (vlTOPp->multiplication_block__DOT__current 
									   >> 0x3fU)))))));
	    __Vtemp4[3U] = (IData)((VL_NEGATE_Q((QData)((IData)(
								(1U 
								 & (IData)(
									   (vlTOPp->multiplication_block__DOT__current 
									    >> 0x3fU)))))) 
				    >> 0x20U));
	    VL_SHIFTL_WWI(128,128,7, __Vtemp5, __Vtemp4, 
			  (0x7fU & ((IData)(vlTOPp->multiplication_block__DOT__index) 
				    - (IData)(1U))));
	    VL_ADD_W(4, __Vtemp6, __Vtemp5, vlTOPp->multiplication_block__DOT__partial);
	    vlTOPp->multiplication_block__DOT__partial_next[0U] 
		= __Vtemp6[0U];
	    vlTOPp->multiplication_block__DOT__partial_next[1U] 
		= __Vtemp6[1U];
	    vlTOPp->multiplication_block__DOT__partial_next[2U] 
		= __Vtemp6[2U];
	    vlTOPp->multiplication_block__DOT__partial_next[3U] 
		= __Vtemp6[3U];
	    vlTOPp->multiplication_block__DOT__temp 
		= (vlTOPp->multiplicand_i >> (IData)(vlTOPp->multiplication_block__DOT__index));
	    vlTOPp->multiplication_block__DOT__recode_next 
		= (7U & (IData)(vlTOPp->multiplication_block__DOT__temp));
	} else {
	    vlTOPp->multiplication_block__DOT__done_next = 1U;
	    vlTOPp->multiplication_block__DOT__product_low_next 
		= (((QData)((IData)(vlTOPp->multiplication_block__DOT__partial[1U])) 
		    << 0x20U) | (QData)((IData)(vlTOPp->multiplication_block__DOT__partial[0U])));
	    vlTOPp->multiplication_block__DOT__product_high_next 
		= (((QData)((IData)(vlTOPp->multiplication_block__DOT__partial[3U])) 
		    << 0x20U) | (QData)((IData)(vlTOPp->multiplication_block__DOT__partial[2U])));
	    vlTOPp->multiplication_block__DOT__pending_next = 0U;
	}
    }
}

VL_INLINE_OPT void Vmultiplication_block::_combo__TOP__3(Vmultiplication_block__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmultiplication_block::_combo__TOP__3\n"); );
    Vmultiplication_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIGW(__Vtemp8,127,0,4);
    VL_SIGW(__Vtemp9,127,0,4);
    VL_SIGW(__Vtemp10,127,0,4);
    // Body
    // ALWAYS at rtl/multiplication_block.v:36
    vlTOPp->multiplication_block__DOT__leading_one_next 
	= vlTOPp->multiplication_block__DOT__leading_one;
    vlTOPp->multiplication_block__DOT__recode_next 
	= vlTOPp->multiplication_block__DOT__recode;
    vlTOPp->multiplication_block__DOT__index_next = vlTOPp->multiplication_block__DOT__index;
    vlTOPp->multiplication_block__DOT__current = VL_ULL(0);
    vlTOPp->multiplication_block__DOT__partial_next[0U] 
	= vlTOPp->multiplication_block__DOT__partial[0U];
    vlTOPp->multiplication_block__DOT__partial_next[1U] 
	= vlTOPp->multiplication_block__DOT__partial[1U];
    vlTOPp->multiplication_block__DOT__partial_next[2U] 
	= vlTOPp->multiplication_block__DOT__partial[2U];
    vlTOPp->multiplication_block__DOT__partial_next[3U] 
	= vlTOPp->multiplication_block__DOT__partial[3U];
    vlTOPp->multiplication_block__DOT__done_next = vlTOPp->done_o;
    vlTOPp->multiplication_block__DOT__product_high_next 
	= vlTOPp->product_high_o;
    vlTOPp->multiplication_block__DOT__product_low_next 
	= vlTOPp->product_low_o;
    vlTOPp->multiplication_block__DOT__temp = VL_ULL(0);
    if (((IData)(vlTOPp->start_i) & (~ (IData)(vlTOPp->multiplication_block__DOT__pending)))) {
	// Function: find_leading_one at rtl/multiplication_block.v:47
	vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
	    = vlTOPp->multiplicand_i;
	vlTOPp->multiplication_block__DOT__pending_next = 1U;
	vlTOPp->multiplication_block__DOT__index_next = 1U;
	vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0U;
	if ((1U & (IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
			   >> 0x3fU)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x3fU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x3eU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x3eU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x3dU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x3dU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x3cU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x3cU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x3bU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x3bU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x3aU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x3aU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x39U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x39U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x38U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x38U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x37U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x37U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x36U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x36U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x35U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x35U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x34U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x34U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x33U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x33U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x32U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x32U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x31U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x31U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x30U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x30U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x2fU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x2fU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x2eU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x2eU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x2dU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x2dU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x2cU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x2cU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x2bU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x2bU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x2aU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x2aU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x29U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x29U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x28U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x28U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x27U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x27U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x26U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x26U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x25U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x25U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x24U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x24U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x23U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x23U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x22U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x22U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x21U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x21U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x20U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x20U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x1fU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x1fU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x1eU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x1eU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x1dU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x1dU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x1cU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x1cU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x1bU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x1bU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x1aU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x1aU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x19U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x19U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x18U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x18U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x17U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x17U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x16U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x16U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x15U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x15U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x14U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x14U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x13U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x13U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x12U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x12U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x11U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x11U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0x10U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0x10U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0xfU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0xfU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0xeU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0xeU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0xdU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0xdU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0xcU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0xcU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0xbU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0xbU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 0xaU)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0xaU;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 9U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 9U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 8U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 8U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 7U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 7U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 6U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 6U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 5U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 5U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 4U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 4U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 3U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 3U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 2U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 2U;
	}
	if (((IData)((vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value 
		      >> 1U)) & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 1U;
	}
	if (((IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__value) 
	     & (0U == (IData)(vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out)))) {
	    vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = 0U;
	}
	vlTOPp->multiplication_block__DOT__leading_one_next 
	    = vlTOPp->__Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out;
	vlTOPp->multiplication_block__DOT__recode_next 
	    = (6U & ((IData)(vlTOPp->multiplicand_i) 
		     << 1U));
    } else {
	if (vlTOPp->multiplication_block__DOT__pending) {
	    vlTOPp->multiplication_block__DOT__index_next 
		= (0x3fU & ((IData)(2U) + (IData)(vlTOPp->multiplication_block__DOT__index)));
	    if (vlTOPp->multiplication_block__DOT__zero) {
		vlTOPp->multiplication_block__DOT__current = VL_ULL(0);
	    } else {
		vlTOPp->multiplication_block__DOT__current 
		    = ((IData)(vlTOPp->multiplication_block__DOT__negate)
		        ? VL_NEGATE_Q(vlTOPp->multiplier_i)
		        : vlTOPp->multiplier_i);
		if (vlTOPp->multiplication_block__DOT__shift) {
		    vlTOPp->multiplication_block__DOT__current 
			= (vlTOPp->multiplication_block__DOT__current 
			   << 1U);
		}
	    }
	    vlTOPp->multiplication_block__DOT__pending_next 
		= ((~ ((0x3dU < (IData)(vlTOPp->multiplication_block__DOT__index_next)) 
		       | ((IData)(vlTOPp->multiplication_block__DOT__leading_one) 
			  < (IData)(vlTOPp->multiplication_block__DOT__index)))) 
		   & (IData)(vlTOPp->multiplication_block__DOT__pending));
	    __Vtemp8[0U] = (IData)(vlTOPp->multiplication_block__DOT__current);
	    __Vtemp8[1U] = (IData)((vlTOPp->multiplication_block__DOT__current 
				    >> 0x20U));
	    __Vtemp8[2U] = (IData)(VL_NEGATE_Q((QData)((IData)(
							       (1U 
								& (IData)(
									  (vlTOPp->multiplication_block__DOT__current 
									   >> 0x3fU)))))));
	    __Vtemp8[3U] = (IData)((VL_NEGATE_Q((QData)((IData)(
								(1U 
								 & (IData)(
									   (vlTOPp->multiplication_block__DOT__current 
									    >> 0x3fU)))))) 
				    >> 0x20U));
	    VL_SHIFTL_WWI(128,128,7, __Vtemp9, __Vtemp8, 
			  (0x7fU & ((IData)(vlTOPp->multiplication_block__DOT__index) 
				    - (IData)(1U))));
	    VL_ADD_W(4, __Vtemp10, __Vtemp9, vlTOPp->multiplication_block__DOT__partial);
	    vlTOPp->multiplication_block__DOT__partial_next[0U] 
		= __Vtemp10[0U];
	    vlTOPp->multiplication_block__DOT__partial_next[1U] 
		= __Vtemp10[1U];
	    vlTOPp->multiplication_block__DOT__partial_next[2U] 
		= __Vtemp10[2U];
	    vlTOPp->multiplication_block__DOT__partial_next[3U] 
		= __Vtemp10[3U];
	    vlTOPp->multiplication_block__DOT__temp 
		= (vlTOPp->multiplicand_i >> (IData)(vlTOPp->multiplication_block__DOT__index));
	    vlTOPp->multiplication_block__DOT__recode_next 
		= (7U & (IData)(vlTOPp->multiplication_block__DOT__temp));
	} else {
	    vlTOPp->multiplication_block__DOT__done_next = 1U;
	    vlTOPp->multiplication_block__DOT__product_low_next 
		= (((QData)((IData)(vlTOPp->multiplication_block__DOT__partial[1U])) 
		    << 0x20U) | (QData)((IData)(vlTOPp->multiplication_block__DOT__partial[0U])));
	    vlTOPp->multiplication_block__DOT__product_high_next 
		= (((QData)((IData)(vlTOPp->multiplication_block__DOT__partial[3U])) 
		    << 0x20U) | (QData)((IData)(vlTOPp->multiplication_block__DOT__partial[2U])));
	    vlTOPp->multiplication_block__DOT__pending_next = 0U;
	}
    }
}

void Vmultiplication_block::_eval(Vmultiplication_block__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmultiplication_block::_eval\n"); );
    Vmultiplication_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
	vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
    vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vmultiplication_block::_eval_initial(Vmultiplication_block__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmultiplication_block::_eval_initial\n"); );
    Vmultiplication_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vmultiplication_block::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmultiplication_block::final\n"); );
    // Variables
    Vmultiplication_block__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vmultiplication_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vmultiplication_block::_eval_settle(Vmultiplication_block__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmultiplication_block::_eval_settle\n"); );
    Vmultiplication_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

VL_INLINE_OPT QData Vmultiplication_block::_change_request(Vmultiplication_block__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmultiplication_block::_change_request\n"); );
    Vmultiplication_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vmultiplication_block::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmultiplication_block::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
	Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset_i & 0xfeU))) {
	Verilated::overWidthError("reset_i");}
    if (VL_UNLIKELY((start_i & 0xfeU))) {
	Verilated::overWidthError("start_i");}
}
#endif // VL_DEBUG

void Vmultiplication_block::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmultiplication_block::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset_i = VL_RAND_RESET_I(1);
    start_i = VL_RAND_RESET_I(1);
    multiplier_i = VL_RAND_RESET_Q(64);
    multiplicand_i = VL_RAND_RESET_Q(64);
    done_o = VL_RAND_RESET_I(1);
    product_low_o = VL_RAND_RESET_Q(64);
    product_high_o = VL_RAND_RESET_Q(64);
    VL_RAND_RESET_W(128,multiplication_block__DOT__partial);
    VL_RAND_RESET_W(128,multiplication_block__DOT__partial_next);
    multiplication_block__DOT__product_low_next = VL_RAND_RESET_Q(64);
    multiplication_block__DOT__product_high_next = VL_RAND_RESET_Q(64);
    multiplication_block__DOT__current = VL_RAND_RESET_Q(64);
    multiplication_block__DOT__temp = VL_RAND_RESET_Q(64);
    multiplication_block__DOT__index = VL_RAND_RESET_I(6);
    multiplication_block__DOT__index_next = VL_RAND_RESET_I(6);
    multiplication_block__DOT__leading_one = VL_RAND_RESET_I(6);
    multiplication_block__DOT__leading_one_next = VL_RAND_RESET_I(6);
    multiplication_block__DOT__recode = VL_RAND_RESET_I(3);
    multiplication_block__DOT__recode_next = VL_RAND_RESET_I(3);
    multiplication_block__DOT__pending = VL_RAND_RESET_I(1);
    multiplication_block__DOT__pending_next = VL_RAND_RESET_I(1);
    multiplication_block__DOT__done_next = VL_RAND_RESET_I(1);
    multiplication_block__DOT__negate = VL_RAND_RESET_I(1);
    multiplication_block__DOT__zero = VL_RAND_RESET_I(1);
    multiplication_block__DOT__shift = VL_RAND_RESET_I(1);
    __Vtask_multiplication_block__DOT__find_leading_one__0__value = VL_RAND_RESET_Q(64);
    __Vtask_multiplication_block__DOT__find_leading_one__0__leading_one_out = VL_RAND_RESET_I(6);
    __Vtableidx1 = VL_RAND_RESET_I(3);
    __Vtable1_multiplication_block__DOT__negate[0] = 0U;
    __Vtable1_multiplication_block__DOT__negate[1] = 0U;
    __Vtable1_multiplication_block__DOT__negate[2] = 0U;
    __Vtable1_multiplication_block__DOT__negate[3] = 0U;
    __Vtable1_multiplication_block__DOT__negate[4] = 1U;
    __Vtable1_multiplication_block__DOT__negate[5] = 1U;
    __Vtable1_multiplication_block__DOT__negate[6] = 1U;
    __Vtable1_multiplication_block__DOT__negate[7] = 0U;
    __Vtable1_multiplication_block__DOT__zero[0] = 1U;
    __Vtable1_multiplication_block__DOT__zero[1] = 0U;
    __Vtable1_multiplication_block__DOT__zero[2] = 0U;
    __Vtable1_multiplication_block__DOT__zero[3] = 0U;
    __Vtable1_multiplication_block__DOT__zero[4] = 0U;
    __Vtable1_multiplication_block__DOT__zero[5] = 0U;
    __Vtable1_multiplication_block__DOT__zero[6] = 0U;
    __Vtable1_multiplication_block__DOT__zero[7] = 1U;
    __Vtable1_multiplication_block__DOT__shift[0] = 0U;
    __Vtable1_multiplication_block__DOT__shift[1] = 0U;
    __Vtable1_multiplication_block__DOT__shift[2] = 0U;
    __Vtable1_multiplication_block__DOT__shift[3] = 1U;
    __Vtable1_multiplication_block__DOT__shift[4] = 1U;
    __Vtable1_multiplication_block__DOT__shift[5] = 0U;
    __Vtable1_multiplication_block__DOT__shift[6] = 0U;
    __Vtable1_multiplication_block__DOT__shift[7] = 0U;
    __Vclklast__TOP__clk = VL_RAND_RESET_I(1);
    __Vm_traceActivity = VL_RAND_RESET_I(32);
}
