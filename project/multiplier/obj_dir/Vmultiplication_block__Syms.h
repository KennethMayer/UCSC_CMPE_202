// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vmultiplication_block__Syms_H_
#define _Vmultiplication_block__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vmultiplication_block.h"

// SYMS CLASS
class Vmultiplication_block__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_activity;  ///< Used by trace routines to determine change occurred
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vmultiplication_block*         TOPp;
    
    // CREATORS
    Vmultiplication_block__Syms(Vmultiplication_block* topp, const char* namep);
    ~Vmultiplication_block__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    inline bool getClearActivity() { bool r=__Vm_activity; __Vm_activity=false; return r; }
    
} VL_ATTR_ALIGNED(64);

#endif // guard
