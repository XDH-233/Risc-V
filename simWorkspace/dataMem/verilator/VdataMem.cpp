// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VdataMem.h for the primary calling header

#include "VdataMem.h"
#include "VdataMem__Syms.h"

//==========

void VdataMem::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VdataMem::eval\n"); );
    VdataMem__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VdataMem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/home/xdh311/IdeaProjects/Risc-V/tmp/job_1/dataMem.v", 7, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VdataMem::_eval_initial_loop(VdataMem__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/home/xdh311/IdeaProjects/Risc-V/tmp/job_1/dataMem.v", 7, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VdataMem::_sequent__TOP__1(VdataMem__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VdataMem::_sequent__TOP__1\n"); );
    VdataMem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*6:0*/ __Vdlyvdim0__dataMem__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__dataMem__DOT__mem__v0;
    SData/*15:0*/ __Vdlyvval__dataMem__DOT__mem__v0;
    // Body
    __Vdlyvset__dataMem__DOT__mem__v0 = 0U;
    if (vlTOPp->memWrite) {
        __Vdlyvval__dataMem__DOT__mem__v0 = vlTOPp->writeData;
        __Vdlyvset__dataMem__DOT__mem__v0 = 1U;
        __Vdlyvdim0__dataMem__DOT__mem__v0 = (0x7fU 
                                              & ((IData)(vlTOPp->address) 
                                                 >> 1U));
    }
    if (__Vdlyvset__dataMem__DOT__mem__v0) {
        vlTOPp->dataMem__DOT__mem[__Vdlyvdim0__dataMem__DOT__mem__v0] 
            = __Vdlyvval__dataMem__DOT__mem__v0;
    }
}

VL_INLINE_OPT void VdataMem::_settle__TOP__2(VdataMem__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VdataMem::_settle__TOP__2\n"); );
    VdataMem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->readData = ((IData)(vlTOPp->memRead) ? 
                        vlTOPp->dataMem__DOT__mem[(0x7fU 
                                                   & ((IData)(vlTOPp->address) 
                                                      >> 1U))]
                         : 0U);
}

void VdataMem::_eval(VdataMem__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VdataMem::_eval\n"); );
    VdataMem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlTOPp->_settle__TOP__2(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

VL_INLINE_OPT QData VdataMem::_change_request(VdataMem__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VdataMem::_change_request\n"); );
    VdataMem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData VdataMem::_change_request_1(VdataMem__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VdataMem::_change_request_1\n"); );
    VdataMem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VdataMem::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VdataMem::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((memRead & 0xfeU))) {
        Verilated::overWidthError("memRead");}
    if (VL_UNLIKELY((memWrite & 0xfeU))) {
        Verilated::overWidthError("memWrite");}
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
