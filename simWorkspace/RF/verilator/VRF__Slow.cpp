// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VRF.h for the primary calling header

#include "VRF.h"
#include "VRF__Syms.h"

//==========

VL_CTOR_IMP(VRF) {
    VRF__Syms* __restrict vlSymsp = __VlSymsp = new VRF__Syms(this, name());
    VRF* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VRF::__Vconfigure(VRF__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

VRF::~VRF() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void VRF::_eval_initial(VRF__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRF::_eval_initial\n"); );
    VRF* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void VRF::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRF::final\n"); );
    // Variables
    VRF__Syms* __restrict vlSymsp = this->__VlSymsp;
    VRF* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VRF::_eval_settle(VRF__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRF::_eval_settle\n"); );
    VRF* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__4(vlSymsp);
}

void VRF::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRF::_ctor_var_reset\n"); );
    // Body
    readReg1 = VL_RAND_RESET_I(5);
    readReg2 = VL_RAND_RESET_I(5);
    writeReg = VL_RAND_RESET_I(5);
    writeData = VL_RAND_RESET_I(16);
    readData1 = VL_RAND_RESET_I(16);
    readData2 = VL_RAND_RESET_I(16);
    RegWrite = VL_RAND_RESET_I(1);
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    RF__DOT___zz_2_ = VL_RAND_RESET_I(16);
    RF__DOT___zz_3_ = VL_RAND_RESET_I(16);
    RF__DOT__regs_0 = VL_RAND_RESET_I(16);
    RF__DOT__regs_1 = VL_RAND_RESET_I(16);
    RF__DOT__regs_2 = VL_RAND_RESET_I(16);
    RF__DOT__regs_3 = VL_RAND_RESET_I(16);
    RF__DOT__regs_4 = VL_RAND_RESET_I(16);
    RF__DOT__regs_5 = VL_RAND_RESET_I(16);
    RF__DOT__regs_6 = VL_RAND_RESET_I(16);
    RF__DOT__regs_7 = VL_RAND_RESET_I(16);
    RF__DOT__regs_8 = VL_RAND_RESET_I(16);
    RF__DOT__regs_9 = VL_RAND_RESET_I(16);
    RF__DOT__regs_10 = VL_RAND_RESET_I(16);
    RF__DOT__regs_11 = VL_RAND_RESET_I(16);
    RF__DOT__regs_12 = VL_RAND_RESET_I(16);
    RF__DOT__regs_13 = VL_RAND_RESET_I(16);
    RF__DOT__regs_14 = VL_RAND_RESET_I(16);
    RF__DOT__regs_15 = VL_RAND_RESET_I(16);
    RF__DOT__regs_16 = VL_RAND_RESET_I(16);
    RF__DOT__regs_17 = VL_RAND_RESET_I(16);
    RF__DOT__regs_18 = VL_RAND_RESET_I(16);
    RF__DOT__regs_19 = VL_RAND_RESET_I(16);
    RF__DOT__regs_20 = VL_RAND_RESET_I(16);
    RF__DOT__regs_21 = VL_RAND_RESET_I(16);
    RF__DOT__regs_22 = VL_RAND_RESET_I(16);
    RF__DOT__regs_23 = VL_RAND_RESET_I(16);
    RF__DOT__regs_24 = VL_RAND_RESET_I(16);
    RF__DOT__regs_25 = VL_RAND_RESET_I(16);
    RF__DOT__regs_26 = VL_RAND_RESET_I(16);
    RF__DOT__regs_27 = VL_RAND_RESET_I(16);
    RF__DOT__regs_28 = VL_RAND_RESET_I(16);
    RF__DOT__regs_29 = VL_RAND_RESET_I(16);
    RF__DOT__regs_30 = VL_RAND_RESET_I(16);
    RF__DOT__regs_31 = VL_RAND_RESET_I(16);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
