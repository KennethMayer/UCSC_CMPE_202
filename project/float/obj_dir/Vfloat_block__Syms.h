// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vfloat_block__Syms_H_
#define _Vfloat_block__Syms_H_

#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "Vfloat_block.h"

// SYMS CLASS
class Vfloat_block__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_activity;  ///< Used by trace routines to determine change occurred
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vfloat_block*                  TOPp;
    
    // CREATORS
    Vfloat_block__Syms(Vfloat_block* topp, const char* namep);
    ~Vfloat_block__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    inline bool getClearActivity() { bool r=__Vm_activity; __Vm_activity=false; return r; }
    
} VL_ATTR_ALIGNED(64);

#endif // guard
