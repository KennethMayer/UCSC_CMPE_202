// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vmultiplication_block__Syms.h"


//======================

void Vmultiplication_block::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vmultiplication_block* t=(Vmultiplication_block*)userthis;
    Vmultiplication_block__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
	t->traceChgThis (vlSymsp, vcdp, code);
    }
}

//======================


void Vmultiplication_block::traceChgThis(Vmultiplication_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vmultiplication_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 1U))))) {
	    vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 2U))))) {
	    vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
	}
	vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vmultiplication_block::traceChgThis__2(Vmultiplication_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vmultiplication_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+1,(vlTOPp->multiplication_block__DOT__negate));
	vcdp->chgBit  (c+2,(vlTOPp->multiplication_block__DOT__zero));
	vcdp->chgBit  (c+3,(vlTOPp->multiplication_block__DOT__shift));
    }
}

void Vmultiplication_block::traceChgThis__3(Vmultiplication_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vmultiplication_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgArray(c+4,(vlTOPp->multiplication_block__DOT__partial_next),128);
	vcdp->chgQuad (c+8,(vlTOPp->multiplication_block__DOT__product_low_next),64);
	vcdp->chgQuad (c+10,(vlTOPp->multiplication_block__DOT__product_high_next),64);
	vcdp->chgQuad (c+12,(vlTOPp->multiplication_block__DOT__current),64);
	vcdp->chgQuad (c+14,(vlTOPp->multiplication_block__DOT__temp),64);
	vcdp->chgBus  (c+16,(vlTOPp->multiplication_block__DOT__index_next),6);
	vcdp->chgBus  (c+17,(vlTOPp->multiplication_block__DOT__leading_one_next),6);
	vcdp->chgBus  (c+18,(vlTOPp->multiplication_block__DOT__recode_next),3);
	vcdp->chgBit  (c+19,(vlTOPp->multiplication_block__DOT__pending_next));
	vcdp->chgBit  (c+20,(vlTOPp->multiplication_block__DOT__done_next));
    }
}

void Vmultiplication_block::traceChgThis__4(Vmultiplication_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vmultiplication_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgArray(c+21,(vlTOPp->multiplication_block__DOT__partial),128);
	vcdp->chgBus  (c+25,(vlTOPp->multiplication_block__DOT__index),6);
	vcdp->chgBus  (c+26,(vlTOPp->multiplication_block__DOT__leading_one),6);
	vcdp->chgBus  (c+27,(vlTOPp->multiplication_block__DOT__recode),3);
	vcdp->chgBit  (c+28,(vlTOPp->multiplication_block__DOT__pending));
    }
}

void Vmultiplication_block::traceChgThis__5(Vmultiplication_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vmultiplication_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+29,(vlTOPp->clk));
	vcdp->chgBit  (c+30,(vlTOPp->reset_i));
	vcdp->chgBit  (c+31,(vlTOPp->start_i));
	vcdp->chgQuad (c+32,(vlTOPp->multiplier_i),64);
	vcdp->chgQuad (c+34,(vlTOPp->multiplicand_i),64);
	vcdp->chgBit  (c+36,(vlTOPp->done_o));
	vcdp->chgQuad (c+37,(vlTOPp->product_low_o),64);
	vcdp->chgQuad (c+39,(vlTOPp->product_high_o),64);
    }
}
