// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdivision_block__Syms.h"


//======================

void Vdivision_block::trace (VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback (&Vdivision_block::traceInit, &Vdivision_block::traceFull, &Vdivision_block::traceChg, this);
}
void Vdivision_block::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vdivision_block* t=(Vdivision_block*)userthis;
    Vdivision_block__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    vcdp->scopeEscape(' ');
    t->traceInitThis (vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vdivision_block::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vdivision_block* t=(Vdivision_block*)userthis;
    Vdivision_block__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis (vlSymsp, vcdp, code);
}

//======================


void Vdivision_block::traceInitThis(Vdivision_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vdivision_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
	vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vdivision_block::traceFullThis(Vdivision_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vdivision_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vdivision_block::traceInitThis__1(Vdivision_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vdivision_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->declBit  (c+33,"clk",-1);
	vcdp->declBit  (c+34,"reset_i",-1);
	vcdp->declBit  (c+35,"start_i",-1);
	vcdp->declQuad (c+36,"dividend_i",-1,63,0);
	vcdp->declQuad (c+38,"divisor_i",-1,63,0);
	vcdp->declBit  (c+40,"done_o",-1);
	vcdp->declQuad (c+41,"quotient_o",-1,63,0);
	vcdp->declQuad (c+43,"remainder_o",-1,63,0);
	vcdp->declBit  (c+33,"division_block clk",-1);
	vcdp->declBit  (c+34,"division_block reset_i",-1);
	vcdp->declBit  (c+35,"division_block start_i",-1);
	vcdp->declQuad (c+36,"division_block dividend_i",-1,63,0);
	vcdp->declQuad (c+38,"division_block divisor_i",-1,63,0);
	vcdp->declBit  (c+40,"division_block done_o",-1);
	vcdp->declQuad (c+41,"division_block quotient_o",-1,63,0);
	vcdp->declQuad (c+43,"division_block remainder_o",-1,63,0);
	vcdp->declBit  (c+1,"division_block done_next",-1);
	vcdp->declQuad (c+2,"division_block quotient_next",-1,63,0);
	vcdp->declArray(c+22,"division_block remainder",-1,127,0);
	vcdp->declArray(c+4,"division_block remainder_next",-1,127,0);
	vcdp->declQuad (c+26,"division_block dividend",-1,63,0);
	vcdp->declQuad (c+8,"division_block dividend_next",-1,63,0);
	vcdp->declQuad (c+28,"division_block divisor",-1,63,0);
	vcdp->declQuad (c+10,"division_block divisor_next",-1,63,0);
	vcdp->declBit  (c+30,"division_block pending",-1);
	vcdp->declBit  (c+12,"division_block pending_next",-1);
	vcdp->declArray(c+13,"division_block diff",-1,64,0);
	vcdp->declBit  (c+31,"division_block sign",-1);
	vcdp->declBit  (c+16,"division_block sign_next",-1);
	vcdp->declBus  (c+32,"division_block index",-1,6,0);
	vcdp->declBus  (c+17,"division_block index_next",-1,6,0);
	vcdp->declBus  (c+45,"division_block dividend_flop Bits",-1,31,0);
	vcdp->declBit  (c+33,"division_block dividend_flop clk",-1);
	vcdp->declBit  (c+34,"division_block dividend_flop reset",-1);
	vcdp->declBit  (c+46,"division_block dividend_flop load",-1);
	vcdp->declQuad (c+47,"division_block dividend_flop load_val",-1,63,0);
	vcdp->declQuad (c+8,"division_block dividend_flop d",-1,63,0);
	vcdp->declQuad (c+26,"division_block dividend_flop q",-1,63,0);
	vcdp->declBus  (c+45,"division_block divisor_flop Bits",-1,31,0);
	vcdp->declBit  (c+33,"division_block divisor_flop clk",-1);
	vcdp->declBit  (c+34,"division_block divisor_flop reset",-1);
	vcdp->declBit  (c+46,"division_block divisor_flop load",-1);
	vcdp->declQuad (c+47,"division_block divisor_flop load_val",-1,63,0);
	vcdp->declQuad (c+10,"division_block divisor_flop d",-1,63,0);
	vcdp->declQuad (c+28,"division_block divisor_flop q",-1,63,0);
	vcdp->declBus  (c+45,"division_block quotient_flop Bits",-1,31,0);
	vcdp->declBit  (c+33,"division_block quotient_flop clk",-1);
	vcdp->declBit  (c+34,"division_block quotient_flop reset",-1);
	vcdp->declBit  (c+46,"division_block quotient_flop load",-1);
	vcdp->declQuad (c+47,"division_block quotient_flop load_val",-1,63,0);
	vcdp->declQuad (c+18,"division_block quotient_flop d",-1,63,0);
	vcdp->declQuad (c+41,"division_block quotient_flop q",-1,63,0);
	vcdp->declBus  (c+45,"division_block remainder_flop Bits",-1,31,0);
	vcdp->declBit  (c+33,"division_block remainder_flop clk",-1);
	vcdp->declBit  (c+34,"division_block remainder_flop reset",-1);
	vcdp->declBit  (c+46,"division_block remainder_flop load",-1);
	vcdp->declQuad (c+47,"division_block remainder_flop load_val",-1,63,0);
	vcdp->declQuad (c+20,"division_block remainder_flop d",-1,63,0);
	vcdp->declQuad (c+43,"division_block remainder_flop q",-1,63,0);
	vcdp->declBus  (c+49,"division_block remainder_int_flop Bits",-1,31,0);
	vcdp->declBit  (c+33,"division_block remainder_int_flop clk",-1);
	vcdp->declBit  (c+34,"division_block remainder_int_flop reset",-1);
	vcdp->declBit  (c+46,"division_block remainder_int_flop load",-1);
	vcdp->declArray(c+50,"division_block remainder_int_flop load_val",-1,127,0);
	vcdp->declArray(c+4,"division_block remainder_int_flop d",-1,127,0);
	vcdp->declArray(c+22,"division_block remainder_int_flop q",-1,127,0);
	vcdp->declBus  (c+54,"division_block index_flop Bits",-1,31,0);
	vcdp->declBit  (c+33,"division_block index_flop clk",-1);
	vcdp->declBit  (c+34,"division_block index_flop reset",-1);
	vcdp->declBit  (c+46,"division_block index_flop load",-1);
	vcdp->declBus  (c+55,"division_block index_flop load_val",-1,6,0);
	vcdp->declBus  (c+17,"division_block index_flop d",-1,6,0);
	vcdp->declBus  (c+32,"division_block index_flop q",-1,6,0);
	vcdp->declBus  (c+56,"division_block pending_flop Bits",-1,31,0);
	vcdp->declBit  (c+33,"division_block pending_flop clk",-1);
	vcdp->declBit  (c+34,"division_block pending_flop reset",-1);
	vcdp->declBit  (c+46,"division_block pending_flop load",-1);
	vcdp->declBus  (c+46,"division_block pending_flop load_val",-1,0,0);
	vcdp->declBus  (c+12,"division_block pending_flop d",-1,0,0);
	vcdp->declBus  (c+30,"division_block pending_flop q",-1,0,0);
	vcdp->declBus  (c+56,"division_block done_flop Bits",-1,31,0);
	vcdp->declBit  (c+33,"division_block done_flop clk",-1);
	vcdp->declBit  (c+34,"division_block done_flop reset",-1);
	vcdp->declBit  (c+46,"division_block done_flop load",-1);
	vcdp->declBus  (c+46,"division_block done_flop load_val",-1,0,0);
	vcdp->declBus  (c+1,"division_block done_flop d",-1,0,0);
	vcdp->declBus  (c+40,"division_block done_flop q",-1,0,0);
	vcdp->declBus  (c+56,"division_block sign_flop Bits",-1,31,0);
	vcdp->declBit  (c+33,"division_block sign_flop clk",-1);
	vcdp->declBit  (c+34,"division_block sign_flop reset",-1);
	vcdp->declBit  (c+46,"division_block sign_flop load",-1);
	vcdp->declBus  (c+46,"division_block sign_flop load_val",-1,0,0);
	vcdp->declBus  (c+16,"division_block sign_flop d",-1,0,0);
	vcdp->declBus  (c+31,"division_block sign_flop q",-1,0,0);
    }
}

void Vdivision_block::traceFullThis__1(Vdivision_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vdivision_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Variables
    VL_SIGW(__Vtemp15,127,0,4);
    // Body
    {
	vcdp->fullBit  (c+1,(vlTOPp->division_block__DOT__done_next));
	vcdp->fullQuad (c+2,(vlTOPp->division_block__DOT__quotient_next),64);
	vcdp->fullArray(c+4,(vlTOPp->division_block__DOT__remainder_next),128);
	vcdp->fullQuad (c+8,(vlTOPp->division_block__DOT__dividend_next),64);
	vcdp->fullQuad (c+10,(vlTOPp->division_block__DOT__divisor_next),64);
	vcdp->fullBit  (c+12,(vlTOPp->division_block__DOT__pending_next));
	vcdp->fullArray(c+13,(vlTOPp->division_block__DOT__diff),65);
	vcdp->fullBit  (c+16,(vlTOPp->division_block__DOT__sign_next));
	vcdp->fullBus  (c+17,(vlTOPp->division_block__DOT__index_next),7);
	vcdp->fullQuad (c+18,((((QData)((IData)(vlTOPp->division_block__DOT__remainder_next[1U])) 
				<< 0x20U) | (QData)((IData)(
							    vlTOPp->division_block__DOT__remainder_next[0U])))),64);
	vcdp->fullQuad (c+20,((((QData)((IData)(vlTOPp->division_block__DOT__remainder_next[3U])) 
				<< 0x20U) | (QData)((IData)(
							    vlTOPp->division_block__DOT__remainder_next[2U])))),64);
	vcdp->fullArray(c+22,(vlTOPp->division_block__DOT__remainder),128);
	vcdp->fullQuad (c+26,(vlTOPp->division_block__DOT__dividend),64);
	vcdp->fullQuad (c+28,(vlTOPp->division_block__DOT__divisor),64);
	vcdp->fullBit  (c+30,(vlTOPp->division_block__DOT__pending));
	vcdp->fullBit  (c+31,(vlTOPp->division_block__DOT__sign));
	vcdp->fullBus  (c+32,(vlTOPp->division_block__DOT__index),7);
	vcdp->fullBit  (c+33,(vlTOPp->clk));
	vcdp->fullBit  (c+34,(vlTOPp->reset_i));
	vcdp->fullBit  (c+35,(vlTOPp->start_i));
	vcdp->fullQuad (c+36,(vlTOPp->dividend_i),64);
	vcdp->fullQuad (c+38,(vlTOPp->divisor_i),64);
	vcdp->fullBit  (c+40,(vlTOPp->done_o));
	vcdp->fullQuad (c+41,(vlTOPp->quotient_o),64);
	vcdp->fullQuad (c+43,(vlTOPp->remainder_o),64);
	vcdp->fullBus  (c+45,(0x40U),32);
	vcdp->fullBit  (c+46,(0U));
	vcdp->fullQuad (c+47,(VL_ULL(0)),64);
	vcdp->fullBus  (c+49,(0x80U),32);
	__Vtemp15[0U] = 0U;
	__Vtemp15[1U] = 0U;
	__Vtemp15[2U] = 0U;
	__Vtemp15[3U] = 0U;
	vcdp->fullArray(c+50,(__Vtemp15),128);
	vcdp->fullBus  (c+54,(7U),32);
	vcdp->fullBus  (c+55,(0U),7);
	vcdp->fullBus  (c+56,(1U),32);
    }
}
