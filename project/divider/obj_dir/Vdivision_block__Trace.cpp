// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdivision_block__Syms.h"


//======================

void Vdivision_block::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vdivision_block* t=(Vdivision_block*)userthis;
    Vdivision_block__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
	t->traceChgThis (vlSymsp, vcdp, code);
    }
}

//======================


void Vdivision_block::traceChgThis(Vdivision_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vdivision_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 2U))))) {
	    vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
	}
	vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vdivision_block::traceChgThis__2(Vdivision_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vdivision_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+1,(vlTOPp->division_block__DOT__done_next));
	vcdp->chgQuad (c+2,(vlTOPp->division_block__DOT__quotient_next),64);
	vcdp->chgArray(c+4,(vlTOPp->division_block__DOT__remainder_next),128);
	vcdp->chgQuad (c+8,(vlTOPp->division_block__DOT__dividend_next),64);
	vcdp->chgQuad (c+10,(vlTOPp->division_block__DOT__divisor_next),64);
	vcdp->chgBit  (c+12,(vlTOPp->division_block__DOT__pending_next));
	vcdp->chgArray(c+13,(vlTOPp->division_block__DOT__diff),65);
	vcdp->chgBit  (c+16,(vlTOPp->division_block__DOT__sign_next));
	vcdp->chgBus  (c+17,(vlTOPp->division_block__DOT__index_next),7);
	vcdp->chgQuad (c+18,((((QData)((IData)(vlTOPp->division_block__DOT__remainder_next[1U])) 
			       << 0x20U) | (QData)((IData)(
							   vlTOPp->division_block__DOT__remainder_next[0U])))),64);
	vcdp->chgQuad (c+20,((((QData)((IData)(vlTOPp->division_block__DOT__remainder_next[3U])) 
			       << 0x20U) | (QData)((IData)(
							   vlTOPp->division_block__DOT__remainder_next[2U])))),64);
    }
}

void Vdivision_block::traceChgThis__3(Vdivision_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vdivision_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgArray(c+22,(vlTOPp->division_block__DOT__remainder),128);
	vcdp->chgQuad (c+26,(vlTOPp->division_block__DOT__dividend),64);
	vcdp->chgQuad (c+28,(vlTOPp->division_block__DOT__divisor),64);
	vcdp->chgBit  (c+30,(vlTOPp->division_block__DOT__pending));
	vcdp->chgBit  (c+31,(vlTOPp->division_block__DOT__sign));
	vcdp->chgBus  (c+32,(vlTOPp->division_block__DOT__index),7);
    }
}

void Vdivision_block::traceChgThis__4(Vdivision_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vdivision_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+33,(vlTOPp->clk));
	vcdp->chgBit  (c+34,(vlTOPp->reset_i));
	vcdp->chgBit  (c+35,(vlTOPp->start_i));
	vcdp->chgQuad (c+36,(vlTOPp->dividend_i),64);
	vcdp->chgQuad (c+38,(vlTOPp->divisor_i),64);
	vcdp->chgBit  (c+40,(vlTOPp->done_o));
	vcdp->chgQuad (c+41,(vlTOPp->quotient_o),64);
	vcdp->chgQuad (c+43,(vlTOPp->remainder_o),64);
    }
}
