// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vmultiplication_block__Syms.h"


//======================

void Vmultiplication_block::trace (VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback (&Vmultiplication_block::traceInit, &Vmultiplication_block::traceFull, &Vmultiplication_block::traceChg, this);
}
void Vmultiplication_block::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vmultiplication_block* t=(Vmultiplication_block*)userthis;
    Vmultiplication_block__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    vcdp->scopeEscape(' ');
    t->traceInitThis (vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vmultiplication_block::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vmultiplication_block* t=(Vmultiplication_block*)userthis;
    Vmultiplication_block__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis (vlSymsp, vcdp, code);
}

//======================


void Vmultiplication_block::traceInitThis(Vmultiplication_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vmultiplication_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
	vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vmultiplication_block::traceFullThis(Vmultiplication_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vmultiplication_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vmultiplication_block::traceInitThis__1(Vmultiplication_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vmultiplication_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->declBit  (c+29,"clk",-1);
	vcdp->declBit  (c+30,"reset_i",-1);
	vcdp->declBit  (c+31,"start_i",-1);
	vcdp->declQuad (c+32,"multiplier_i",-1,63,0);
	vcdp->declQuad (c+34,"multiplicand_i",-1,63,0);
	vcdp->declBit  (c+36,"done_o",-1);
	vcdp->declQuad (c+37,"product_low_o",-1,63,0);
	vcdp->declQuad (c+39,"product_high_o",-1,63,0);
	vcdp->declBit  (c+29,"multiplication_block clk",-1);
	vcdp->declBit  (c+30,"multiplication_block reset_i",-1);
	vcdp->declBit  (c+31,"multiplication_block start_i",-1);
	vcdp->declQuad (c+32,"multiplication_block multiplier_i",-1,63,0);
	vcdp->declQuad (c+34,"multiplication_block multiplicand_i",-1,63,0);
	vcdp->declBit  (c+36,"multiplication_block done_o",-1);
	vcdp->declQuad (c+37,"multiplication_block product_low_o",-1,63,0);
	vcdp->declQuad (c+39,"multiplication_block product_high_o",-1,63,0);
	vcdp->declArray(c+21,"multiplication_block partial",-1,127,0);
	vcdp->declArray(c+4,"multiplication_block partial_next",-1,127,0);
	vcdp->declQuad (c+8,"multiplication_block product_low_next",-1,63,0);
	vcdp->declQuad (c+10,"multiplication_block product_high_next",-1,63,0);
	vcdp->declQuad (c+12,"multiplication_block current",-1,63,0);
	vcdp->declQuad (c+14,"multiplication_block temp",-1,63,0);
	vcdp->declBus  (c+25,"multiplication_block index",-1,5,0);
	vcdp->declBus  (c+16,"multiplication_block index_next",-1,5,0);
	vcdp->declBus  (c+26,"multiplication_block leading_one",-1,5,0);
	vcdp->declBus  (c+17,"multiplication_block leading_one_next",-1,5,0);
	vcdp->declBus  (c+27,"multiplication_block recode",-1,2,0);
	vcdp->declBus  (c+18,"multiplication_block recode_next",-1,2,0);
	vcdp->declBit  (c+28,"multiplication_block pending",-1);
	vcdp->declBit  (c+19,"multiplication_block pending_next",-1);
	vcdp->declBit  (c+20,"multiplication_block done_next",-1);
	vcdp->declBit  (c+1,"multiplication_block negate",-1);
	vcdp->declBit  (c+2,"multiplication_block zero",-1);
	vcdp->declBit  (c+3,"multiplication_block shift",-1);
	vcdp->declBus  (c+41,"multiplication_block product_low_flop Bits",-1,31,0);
	vcdp->declBit  (c+29,"multiplication_block product_low_flop clk",-1);
	vcdp->declBit  (c+30,"multiplication_block product_low_flop reset",-1);
	vcdp->declBit  (c+42,"multiplication_block product_low_flop load",-1);
	vcdp->declQuad (c+43,"multiplication_block product_low_flop load_val",-1,63,0);
	vcdp->declQuad (c+8,"multiplication_block product_low_flop d",-1,63,0);
	vcdp->declQuad (c+37,"multiplication_block product_low_flop q",-1,63,0);
	vcdp->declBus  (c+41,"multiplication_block product_high_flop Bits",-1,31,0);
	vcdp->declBit  (c+29,"multiplication_block product_high_flop clk",-1);
	vcdp->declBit  (c+30,"multiplication_block product_high_flop reset",-1);
	vcdp->declBit  (c+42,"multiplication_block product_high_flop load",-1);
	vcdp->declQuad (c+43,"multiplication_block product_high_flop load_val",-1,63,0);
	vcdp->declQuad (c+10,"multiplication_block product_high_flop d",-1,63,0);
	vcdp->declQuad (c+39,"multiplication_block product_high_flop q",-1,63,0);
	vcdp->declBus  (c+45,"multiplication_block partial_flop Bits",-1,31,0);
	vcdp->declBit  (c+29,"multiplication_block partial_flop clk",-1);
	vcdp->declBit  (c+30,"multiplication_block partial_flop reset",-1);
	vcdp->declBit  (c+42,"multiplication_block partial_flop load",-1);
	vcdp->declArray(c+46,"multiplication_block partial_flop load_val",-1,127,0);
	vcdp->declArray(c+4,"multiplication_block partial_flop d",-1,127,0);
	vcdp->declArray(c+21,"multiplication_block partial_flop q",-1,127,0);
	vcdp->declBus  (c+50,"multiplication_block done_flop Bits",-1,31,0);
	vcdp->declBit  (c+29,"multiplication_block done_flop clk",-1);
	vcdp->declBit  (c+30,"multiplication_block done_flop reset",-1);
	vcdp->declBit  (c+42,"multiplication_block done_flop load",-1);
	vcdp->declBus  (c+42,"multiplication_block done_flop load_val",-1,0,0);
	vcdp->declBus  (c+20,"multiplication_block done_flop d",-1,0,0);
	vcdp->declBus  (c+36,"multiplication_block done_flop q",-1,0,0);
	vcdp->declBus  (c+51,"multiplication_block recode_flop Bits",-1,31,0);
	vcdp->declBit  (c+29,"multiplication_block recode_flop clk",-1);
	vcdp->declBit  (c+30,"multiplication_block recode_flop reset",-1);
	vcdp->declBit  (c+42,"multiplication_block recode_flop load",-1);
	vcdp->declBus  (c+52,"multiplication_block recode_flop load_val",-1,2,0);
	vcdp->declBus  (c+18,"multiplication_block recode_flop d",-1,2,0);
	vcdp->declBus  (c+27,"multiplication_block recode_flop q",-1,2,0);
	vcdp->declBus  (c+53,"multiplication_block recode_index_flop Bits",-1,31,0);
	vcdp->declBit  (c+29,"multiplication_block recode_index_flop clk",-1);
	vcdp->declBit  (c+30,"multiplication_block recode_index_flop reset",-1);
	vcdp->declBit  (c+42,"multiplication_block recode_index_flop load",-1);
	vcdp->declBus  (c+54,"multiplication_block recode_index_flop load_val",-1,5,0);
	vcdp->declBus  (c+16,"multiplication_block recode_index_flop d",-1,5,0);
	vcdp->declBus  (c+25,"multiplication_block recode_index_flop q",-1,5,0);
	vcdp->declBus  (c+53,"multiplication_block leading_one_flop Bits",-1,31,0);
	vcdp->declBit  (c+29,"multiplication_block leading_one_flop clk",-1);
	vcdp->declBit  (c+30,"multiplication_block leading_one_flop reset",-1);
	vcdp->declBit  (c+42,"multiplication_block leading_one_flop load",-1);
	vcdp->declBus  (c+54,"multiplication_block leading_one_flop load_val",-1,5,0);
	vcdp->declBus  (c+17,"multiplication_block leading_one_flop d",-1,5,0);
	vcdp->declBus  (c+26,"multiplication_block leading_one_flop q",-1,5,0);
	vcdp->declBus  (c+50,"multiplication_block pending_flop Bits",-1,31,0);
	vcdp->declBit  (c+29,"multiplication_block pending_flop clk",-1);
	vcdp->declBit  (c+30,"multiplication_block pending_flop reset",-1);
	vcdp->declBit  (c+42,"multiplication_block pending_flop load",-1);
	vcdp->declBus  (c+42,"multiplication_block pending_flop load_val",-1,0,0);
	vcdp->declBus  (c+19,"multiplication_block pending_flop d",-1,0,0);
	vcdp->declBus  (c+28,"multiplication_block pending_flop q",-1,0,0);
	vcdp->declBus  (c+27,"multiplication_block recoder value_i",-1,2,0);
	vcdp->declBit  (c+1,"multiplication_block recoder negate_o",-1);
	vcdp->declBit  (c+2,"multiplication_block recoder zero_o",-1);
	vcdp->declBit  (c+3,"multiplication_block recoder shift_o",-1);
    }
}

void Vmultiplication_block::traceFullThis__1(Vmultiplication_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vmultiplication_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Variables
    VL_SIGW(__Vtemp11,127,0,4);
    // Body
    {
	vcdp->fullBit  (c+1,(vlTOPp->multiplication_block__DOT__negate));
	vcdp->fullBit  (c+2,(vlTOPp->multiplication_block__DOT__zero));
	vcdp->fullBit  (c+3,(vlTOPp->multiplication_block__DOT__shift));
	vcdp->fullArray(c+4,(vlTOPp->multiplication_block__DOT__partial_next),128);
	vcdp->fullQuad (c+8,(vlTOPp->multiplication_block__DOT__product_low_next),64);
	vcdp->fullQuad (c+10,(vlTOPp->multiplication_block__DOT__product_high_next),64);
	vcdp->fullQuad (c+12,(vlTOPp->multiplication_block__DOT__current),64);
	vcdp->fullQuad (c+14,(vlTOPp->multiplication_block__DOT__temp),64);
	vcdp->fullBus  (c+16,(vlTOPp->multiplication_block__DOT__index_next),6);
	vcdp->fullBus  (c+17,(vlTOPp->multiplication_block__DOT__leading_one_next),6);
	vcdp->fullBus  (c+18,(vlTOPp->multiplication_block__DOT__recode_next),3);
	vcdp->fullBit  (c+19,(vlTOPp->multiplication_block__DOT__pending_next));
	vcdp->fullBit  (c+20,(vlTOPp->multiplication_block__DOT__done_next));
	vcdp->fullArray(c+21,(vlTOPp->multiplication_block__DOT__partial),128);
	vcdp->fullBus  (c+25,(vlTOPp->multiplication_block__DOT__index),6);
	vcdp->fullBus  (c+26,(vlTOPp->multiplication_block__DOT__leading_one),6);
	vcdp->fullBus  (c+27,(vlTOPp->multiplication_block__DOT__recode),3);
	vcdp->fullBit  (c+28,(vlTOPp->multiplication_block__DOT__pending));
	vcdp->fullBit  (c+29,(vlTOPp->clk));
	vcdp->fullBit  (c+30,(vlTOPp->reset_i));
	vcdp->fullBit  (c+31,(vlTOPp->start_i));
	vcdp->fullQuad (c+32,(vlTOPp->multiplier_i),64);
	vcdp->fullQuad (c+34,(vlTOPp->multiplicand_i),64);
	vcdp->fullBit  (c+36,(vlTOPp->done_o));
	vcdp->fullQuad (c+37,(vlTOPp->product_low_o),64);
	vcdp->fullQuad (c+39,(vlTOPp->product_high_o),64);
	vcdp->fullBus  (c+41,(0x40U),32);
	vcdp->fullBit  (c+42,(0U));
	vcdp->fullQuad (c+43,(VL_ULL(0)),64);
	vcdp->fullBus  (c+45,(0x80U),32);
	__Vtemp11[0U] = 0U;
	__Vtemp11[1U] = 0U;
	__Vtemp11[2U] = 0U;
	__Vtemp11[3U] = 0U;
	vcdp->fullArray(c+46,(__Vtemp11),128);
	vcdp->fullBus  (c+50,(1U),32);
	vcdp->fullBus  (c+51,(3U),32);
	vcdp->fullBus  (c+52,(0U),3);
	vcdp->fullBus  (c+53,(6U),32);
	vcdp->fullBus  (c+54,(0U),6);
    }
}
