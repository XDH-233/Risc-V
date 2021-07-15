// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VImmGen.h for the primary calling header

#include "VImmGen.h"
#include "VImmGen__Syms.h"

//==========

VL_CTOR_IMP(VImmGen) {
    VImmGen__Syms* __restrict vlSymsp = __VlSymsp = new VImmGen__Syms(this, name());
    VImmGen* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VImmGen::__Vconfigure(VImmGen__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

VImmGen::~VImmGen() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void VImmGen::_eval_initial(VImmGen__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VImmGen::_eval_initial\n"); );
    VImmGen* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VImmGen::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VImmGen::final\n"); );
    // Variables
    VImmGen__Syms* __restrict vlSymsp = this->__VlSymsp;
    VImmGen* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VImmGen::_eval_settle(VImmGen__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VImmGen::_eval_settle\n"); );
    VImmGen* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void VImmGen::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VImmGen::_ctor_var_reset\n"); );
    // Body
    io_instruction = VL_RAND_RESET_I(32);
    io_immGenOut = VL_RAND_RESET_Q(64);
    ImmGen__DOT___zz_2_ = VL_RAND_RESET_I(12);
    ImmGen__DOT___zz_3_ = VL_RAND_RESET_I(12);
    { int __Vi0=0; for (; __Vi0<1; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
