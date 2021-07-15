// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VImmGen.h for the primary calling header

#include "VImmGen.h"
#include "VImmGen__Syms.h"

//==========

void VImmGen::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VImmGen::eval\n"); );
    VImmGen__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VImmGen* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("/home/xdh311/IdeaProjects/Risc-V/tmp/job_1/ImmGen.v", 7, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VImmGen::_eval_initial_loop(VImmGen__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("/home/xdh311/IdeaProjects/Risc-V/tmp/job_1/ImmGen.v", 7, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VImmGen::_combo__TOP__1(VImmGen__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VImmGen::_combo__TOP__1\n"); );
    VImmGen* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->ImmGen__DOT___zz_2_ = ((0xfe0U & (vlTOPp->io_instruction 
                                              >> 0x14U)) 
                                   | (0x1fU & (vlTOPp->io_instruction 
                                               >> 7U)));
    vlTOPp->ImmGen__DOT___zz_3_ = ((0x800U & (vlTOPp->io_instruction 
                                              >> 0x14U)) 
                                   | ((0x400U & (vlTOPp->io_instruction 
                                                 << 3U)) 
                                      | ((0x3f0U & 
                                          (vlTOPp->io_instruction 
                                           >> 0x15U)) 
                                         | (0xfU & 
                                            (vlTOPp->io_instruction 
                                             >> 8U)))));
    vlTOPp->io_immGenOut = ((3U == (0x7fU & vlTOPp->io_instruction))
                             ? ((0xfffffffffffff000ULL 
                                 & ((- (QData)((IData)(
                                                       (1U 
                                                        & (vlTOPp->io_instruction 
                                                           >> 0x1fU))))) 
                                    << 0xcU)) | (QData)((IData)(
                                                                (0xfffU 
                                                                 & (vlTOPp->io_instruction 
                                                                    >> 0x14U)))))
                             : ((0x23U == (0x7fU & vlTOPp->io_instruction))
                                 ? ((0xfffffffffffff000ULL 
                                     & ((- (QData)((IData)(
                                                           (1U 
                                                            & ((IData)(vlTOPp->ImmGen__DOT___zz_2_) 
                                                               >> 0xbU))))) 
                                        << 0xcU)) | (QData)((IData)(vlTOPp->ImmGen__DOT___zz_2_)))
                                 : ((0x63U == (0x7fU 
                                               & vlTOPp->io_instruction))
                                     ? ((0xfffffffffffff000ULL 
                                         & ((- (QData)((IData)(
                                                               (1U 
                                                                & ((IData)(vlTOPp->ImmGen__DOT___zz_3_) 
                                                                   >> 0xbU))))) 
                                            << 0xcU)) 
                                        | (QData)((IData)(vlTOPp->ImmGen__DOT___zz_3_)))
                                     : 0ULL)));
}

void VImmGen::_eval(VImmGen__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VImmGen::_eval\n"); );
    VImmGen* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData VImmGen::_change_request(VImmGen__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VImmGen::_change_request\n"); );
    VImmGen* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData VImmGen::_change_request_1(VImmGen__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VImmGen::_change_request_1\n"); );
    VImmGen* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VImmGen::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VImmGen::_eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
