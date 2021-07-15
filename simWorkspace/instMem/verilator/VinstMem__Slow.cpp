// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VinstMem.h for the primary calling header

#include "VinstMem.h"
#include "VinstMem__Syms.h"

//==========

VL_CTOR_IMP(VinstMem) {
    VinstMem__Syms* __restrict vlSymsp = __VlSymsp = new VinstMem__Syms(this, name());
    VinstMem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VinstMem::__Vconfigure(VinstMem__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

VinstMem::~VinstMem() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void VinstMem::_initial__TOP__1(VinstMem__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VinstMem::_initial__TOP__1\n"); );
    VinstMem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*223:0*/ __Vtemp1[7];
    // Body
    __Vtemp1[0U] = 0x2e62696eU;
    __Vtemp1[1U] = 0x5f6d656dU;
    __Vtemp1[2U] = 0x6576656cU;
    __Vtemp1[3U] = 0x746f706cU;
    __Vtemp1[4U] = 0x6d2e765fU;
    __Vtemp1[5U] = 0x73744d65U;
    __Vtemp1[6U] = 0x696eU;
    VL_READMEM_N(false, 32, 128, 0, VL_CVT_PACK_STR_NW(7, __Vtemp1)
                 , vlTOPp->instMem__DOT__mem, 0, ~0ULL);
}

void VinstMem::_eval_initial(VinstMem__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VinstMem::_eval_initial\n"); );
    VinstMem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
}

void VinstMem::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VinstMem::final\n"); );
    // Variables
    VinstMem__Syms* __restrict vlSymsp = this->__VlSymsp;
    VinstMem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VinstMem::_eval_settle(VinstMem__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VinstMem::_eval_settle\n"); );
    VinstMem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
}

void VinstMem::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VinstMem::_ctor_var_reset\n"); );
    // Body
    address = VL_RAND_RESET_I(9);
    instruction = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<128; ++__Vi0) {
            instMem__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<1; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
