// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VdataMem.h for the primary calling header

#include "VdataMem.h"
#include "VdataMem__Syms.h"

//==========

VL_CTOR_IMP(VdataMem) {
    VdataMem__Syms* __restrict vlSymsp = __VlSymsp = new VdataMem__Syms(this, name());
    VdataMem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VdataMem::__Vconfigure(VdataMem__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

VdataMem::~VdataMem() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void VdataMem::_eval_initial(VdataMem__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VdataMem::_eval_initial\n"); );
    VdataMem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void VdataMem::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VdataMem::final\n"); );
    // Variables
    VdataMem__Syms* __restrict vlSymsp = this->__VlSymsp;
    VdataMem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VdataMem::_eval_settle(VdataMem__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VdataMem::_eval_settle\n"); );
    VdataMem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void VdataMem::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VdataMem::_ctor_var_reset\n"); );
    // Body
    address = VL_RAND_RESET_I(8);
    writeData = VL_RAND_RESET_I(16);
    readData = VL_RAND_RESET_I(16);
    memRead = VL_RAND_RESET_I(1);
    memWrite = VL_RAND_RESET_I(1);
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<128; ++__Vi0) {
            dataMem__DOT__mem[__Vi0] = VL_RAND_RESET_I(16);
    }}
    { int __Vi0=0; for (; __Vi0<1; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
