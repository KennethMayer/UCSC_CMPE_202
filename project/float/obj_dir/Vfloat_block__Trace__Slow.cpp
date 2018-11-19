// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfloat_block__Syms.h"


//======================

void Vfloat_block::trace (VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback (&Vfloat_block::traceInit, &Vfloat_block::traceFull, &Vfloat_block::traceChg, this);
}
void Vfloat_block::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vfloat_block* t=(Vfloat_block*)userthis;
    Vfloat_block__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    vcdp->scopeEscape(' ');
    t->traceInitThis (vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vfloat_block::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vfloat_block* t=(Vfloat_block*)userthis;
    Vfloat_block__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis (vlSymsp, vcdp, code);
}

//======================


void Vfloat_block::traceInitThis(Vfloat_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vfloat_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
	vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vfloat_block::traceFullThis(Vfloat_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vfloat_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vfloat_block::traceInitThis__1(Vfloat_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vfloat_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->declBit  (c+1,"clk",-1);
	vcdp->declBit  (c+2,"reset_i",-1);
	vcdp->declBit  (c+3,"start_i",-1);
	vcdp->declBus  (c+4,"float1_i",-1,31,0);
	vcdp->declBus  (c+5,"float2_i",-1,31,0);
	vcdp->declBus  (c+6,"float3_i",-1,31,0);
	vcdp->declBus  (c+7,"opcode_i",-1,4,0);
	vcdp->declBit  (c+8,"done_o",-1);
	vcdp->declBus  (c+9,"exceptions_o",-1,3,0);
	vcdp->declBus  (c+10,"float_low_o",-1,31,0);
	vcdp->declBus  (c+11,"float_high_o",-1,31,0);
	vcdp->declQuad (c+12,"int_o",-1,63,0);
	vcdp->declBit  (c+1,"float_block clk",-1);
	vcdp->declBit  (c+2,"float_block reset_i",-1);
	vcdp->declBit  (c+3,"float_block start_i",-1);
	vcdp->declBus  (c+4,"float_block float1_i",-1,31,0);
	vcdp->declBus  (c+5,"float_block float2_i",-1,31,0);
	vcdp->declBus  (c+6,"float_block float3_i",-1,31,0);
	vcdp->declBus  (c+7,"float_block opcode_i",-1,4,0);
	vcdp->declBit  (c+8,"float_block done_o",-1);
	vcdp->declBus  (c+9,"float_block exceptions_o",-1,3,0);
	vcdp->declBus  (c+10,"float_block float_low_o",-1,31,0);
	vcdp->declBus  (c+11,"float_block float_high_o",-1,31,0);
	vcdp->declQuad (c+12,"float_block int_o",-1,63,0);
    }
}

void Vfloat_block::traceFullThis__1(Vfloat_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vfloat_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->fullBit  (c+1,(vlTOPp->clk));
	vcdp->fullBit  (c+2,(vlTOPp->reset_i));
	vcdp->fullBit  (c+3,(vlTOPp->start_i));
	vcdp->fullBus  (c+4,(vlTOPp->float1_i),32);
	vcdp->fullBus  (c+5,(vlTOPp->float2_i),32);
	vcdp->fullBus  (c+6,(vlTOPp->float3_i),32);
	vcdp->fullBus  (c+7,(vlTOPp->opcode_i),5);
	vcdp->fullBit  (c+8,(vlTOPp->done_o));
	vcdp->fullBus  (c+9,(vlTOPp->exceptions_o),4);
	vcdp->fullBus  (c+10,(vlTOPp->float_low_o),32);
	vcdp->fullBus  (c+11,(vlTOPp->float_high_o),32);
	vcdp->fullQuad (c+12,(vlTOPp->int_o),64);
    }
}
