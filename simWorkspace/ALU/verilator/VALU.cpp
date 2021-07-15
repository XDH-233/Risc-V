// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VALU.h for the primary calling header

#include "VALU.h"
#include "VALU__Syms.h"

//==========

void VALU::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VALU::eval\n"); );
    VALU__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("/home/xdh311/IdeaProjects/Risc-V/tmp/job_1/ALU.v", 7, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VALU::_eval_initial_loop(VALU__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("/home/xdh311/IdeaProjects/Risc-V/tmp/job_1/ALU.v", 7, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VALU::_combo__TOP__1(VALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::_combo__TOP__1\n"); );
    VALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->ALU__DOT__ALUCtrl = 0xfU;
    if (((0U == (IData)(vlTOPp->ALUop)) | (((2U == (IData)(vlTOPp->ALUop)) 
                                            & (0U == (IData)(vlTOPp->funct7))) 
                                           & (0U == (IData)(vlTOPp->funct7))))) {
        vlTOPp->ALU__DOT__ALUCtrl = 2U;
    }
    if (((1U == (IData)(vlTOPp->ALUop)) | (((2U == (IData)(vlTOPp->ALUop)) 
                                            & (0x20U 
                                               == (IData)(vlTOPp->funct7))) 
                                           & (0U == (IData)(vlTOPp->funct3))))) {
        vlTOPp->ALU__DOT__ALUCtrl = 6U;
    }
    if ((((2U == (IData)(vlTOPp->ALUop)) & (7U == (IData)(vlTOPp->funct3))) 
         & (0U == (IData)(vlTOPp->funct7)))) {
        vlTOPp->ALU__DOT__ALUCtrl = 0U;
    }
    if ((((2U == (IData)(vlTOPp->ALUop)) & (6U == (IData)(vlTOPp->funct3))) 
         & (0U == (IData)(vlTOPp->funct7)))) {
        vlTOPp->ALU__DOT__ALUCtrl = 1U;
    }
    vlTOPp->Result = ((8U & (IData)(vlTOPp->ALU__DOT__ALUCtrl))
                       ? 0U : (0xffU & ((4U & (IData)(vlTOPp->ALU__DOT__ALUCtrl))
                                         ? ((2U & (IData)(vlTOPp->ALU__DOT__ALUCtrl))
                                             ? ((1U 
                                                 & (IData)(vlTOPp->ALU__DOT__ALUCtrl))
                                                 ? 0U
                                                 : 
                                                ((IData)(vlTOPp->data1) 
                                                 - (IData)(vlTOPp->data2)))
                                             : 0U) : 
                                        ((2U & (IData)(vlTOPp->ALU__DOT__ALUCtrl))
                                          ? ((1U & (IData)(vlTOPp->ALU__DOT__ALUCtrl))
                                              ? 0U : 
                                             ((IData)(vlTOPp->data1) 
                                              + (IData)(vlTOPp->data2)))
                                          : ((1U & (IData)(vlTOPp->ALU__DOT__ALUCtrl))
                                              ? ((IData)(vlTOPp->data1) 
                                                 | (IData)(vlTOPp->data2))
                                              : ((IData)(vlTOPp->data1) 
                                                 & (IData)(vlTOPp->data2)))))));
    vlTOPp->Zero = (0U == (IData)(vlTOPp->Result));
}

void VALU::_eval(VALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::_eval\n"); );
    VALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData VALU::_change_request(VALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::_change_request\n"); );
    VALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData VALU::_change_request_1(VALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::_change_request_1\n"); );
    VALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VALU::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((ALUop & 0xfcU))) {
        Verilated::overWidthError("ALUop");}
    if (VL_UNLIKELY((funct7 & 0x80U))) {
        Verilated::overWidthError("funct7");}
    if (VL_UNLIKELY((funct3 & 0xf8U))) {
        Verilated::overWidthError("funct3");}
}
#endif  // VL_DEBUG
