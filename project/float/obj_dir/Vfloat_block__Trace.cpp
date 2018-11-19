// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vfloat_block__Syms.h"


//======================

void Vfloat_block::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vfloat_block* t=(Vfloat_block*)userthis;
    Vfloat_block__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
	t->traceChgThis (vlSymsp, vcdp, code);
    }
}

//======================


void Vfloat_block::traceChgThis(Vfloat_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vfloat_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vfloat_block::traceChgThis__2(Vfloat_block__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vfloat_block* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+1,(vlTOPp->clk));
	vcdp->chgBit  (c+2,(vlTOPp->reset_i));
	vcdp->chgBit  (c+3,(vlTOPp->start_i));
	vcdp->chgBus  (c+4,(vlTOPp->float1_i),32);
	vcdp->chgBus  (c+5,(vlTOPp->float2_i),32);
	vcdp->chgBus  (c+6,(vlTOPp->float3_i),32);
	vcdp->chgBus  (c+7,(vlTOPp->opcode_i),5);
	vcdp->chgBit  (c+8,(vlTOPp->done_o));
	vcdp->chgBus  (c+9,(vlTOPp->exceptions_o),4);
	vcdp->chgBus  (c+10,(vlTOPp->float_low_o),32);
	vcdp->chgBus  (c+11,(vlTOPp->float_high_o),32);
	vcdp->chgQuad (c+12,(vlTOPp->int_o),64);
    }
}
