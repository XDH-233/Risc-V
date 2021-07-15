// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VRF.h for the primary calling header

#include "VRF.h"
#include "VRF__Syms.h"

//==========

void VRF::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VRF::eval\n"); );
    VRF__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VRF* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("/home/xdh311/IdeaProjects/Risc-V/tmp/job_1/RF.v", 7, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VRF::_eval_initial_loop(VRF__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("/home/xdh311/IdeaProjects/Risc-V/tmp/job_1/RF.v", 7, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VRF::_sequent__TOP__2(VRF__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRF::_sequent__TOP__2\n"); );
    VRF* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->reset) {
        vlTOPp->RF__DOT__regs_26 = 0U;
    } else {
        if (vlTOPp->RegWrite) {
            if ((0x4000000U & ((IData)(1U) << (IData)(vlTOPp->writeReg)))) {
                vlTOPp->RF__DOT__regs_26 = vlTOPp->writeData;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->RF__DOT__regs_19 = 0U;
    } else {
        if (vlTOPp->RegWrite) {
            if ((0x80000U & ((IData)(1U) << (IData)(vlTOPp->writeReg)))) {
                vlTOPp->RF__DOT__regs_19 = vlTOPp->writeData;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->RF__DOT__regs_12 = 0U;
    } else {
        if (vlTOPp->RegWrite) {
            if ((0x1000U & ((IData)(1U) << (IData)(vlTOPp->writeReg)))) {
                vlTOPp->RF__DOT__regs_12 = vlTOPp->writeData;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->RF__DOT__regs_5 = 0U;
    } else {
        if (vlTOPp->RegWrite) {
            if ((0x20U & ((IData)(1U) << (IData)(vlTOPp->writeReg)))) {
                vlTOPp->RF__DOT__regs_5 = vlTOPp->writeData;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->RF__DOT__regs_25 = 0U;
    } else {
        if (vlTOPp->RegWrite) {
            if ((0x2000000U & ((IData)(1U) << (IData)(vlTOPp->writeReg)))) {
                vlTOPp->RF__DOT__regs_25 = vlTOPp->writeData;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->RF__DOT__regs_18 = 0U;
    } else {
        if (vlTOPp->RegWrite) {
            if ((0x40000U & ((IData)(1U) << (IData)(vlTOPp->writeReg)))) {
                vlTOPp->RF__DOT__regs_18 = vlTOPp->writeData;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->RF__DOT__regs_11 = 0U;
    } else {
        if (vlTOPp->RegWrite) {
            if ((0x800U & ((IData)(1U) << (IData)(vlTOPp->writeReg)))) {
                vlTOPp->RF__DOT__regs_11 = vlTOPp->writeData;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->RF__DOT__regs_4 = 0U;
    } else {
        if (vlTOPp->RegWrite) {
            if ((0x10U & ((IData)(1U) << (IData)(vlTOPp->writeReg)))) {
                vlTOPp->RF__DOT__regs_4 = vlTOPp->writeData;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->RF__DOT__regs_31 = 0U;
    } else {
        if (vlTOPp->RegWrite) {
            if ((0x80000000U & ((IData)(1U) << (IData)(vlTOPp->writeReg)))) {
                vlTOPp->RF__DOT__regs_31 = vlTOPp->writeData;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->RF__DOT__regs_24 = 0U;
    } else {
        if (vlTOPp->RegWrite) {
            if ((0x1000000U & ((IData)(1U) << (IData)(vlTOPp->writeReg)))) {
                vlTOPp->RF__DOT__regs_24 = vlTOPp->writeData;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->RF__DOT__regs_17 = 0U;
    } else {
        if (vlTOPp->RegWrite) {
            if ((0x20000U & ((IData)(1U) << (IData)(vlTOPp->writeReg)))) {
                vlTOPp->RF__DOT__regs_17 = vlTOPp->writeData;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->RF__DOT__regs_10 = 0U;
    } else {
        if (vlTOPp->RegWrite) {
            if ((0x400U & ((IData)(1U) << (IData)(vlTOPp->writeReg)))) {
                vlTOPp->RF__DOT__regs_10 = vlTOPp->writeData;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->RF__DOT__regs_3 = 0U;
    } else {
        if (vlTOPp->RegWrite) {
            if ((8U & ((IData)(1U) << (IData)(vlTOPp->writeReg)))) {
                vlTOPp->RF__DOT__regs_3 = vlTOPp->writeData;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->RF__DOT__regs_30 = 0U;
    } else {
        if (vlTOPp->RegWrite) {
            if ((0x40000000U & ((IData)(1U) << (IData)(vlTOPp->writeReg)))) {
                vlTOPp->RF__DOT__regs_30 = vlTOPp->writeData;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->RF__DOT__regs_23 = 0U;
    } else {
        if (vlTOPp->RegWrite) {
            if ((0x800000U & ((IData)(1U) << (IData)(vlTOPp->writeReg)))) {
                vlTOPp->RF__DOT__regs_23 = vlTOPp->writeData;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->RF__DOT__regs_16 = 0U;
    } else {
        if (vlTOPp->RegWrite) {
            if ((0x10000U & ((IData)(1U) << (IData)(vlTOPp->writeReg)))) {
                vlTOPp->RF__DOT__regs_16 = vlTOPp->writeData;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->RF__DOT__regs_9 = 0U;
    } else {
        if (vlTOPp->RegWrite) {
            if ((0x200U & ((IData)(1U) << (IData)(vlTOPp->writeReg)))) {
                vlTOPp->RF__DOT__regs_9 = vlTOPp->writeData;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->RF__DOT__regs_2 = 0U;
    } else {
        if (vlTOPp->RegWrite) {
            if ((4U & ((IData)(1U) << (IData)(vlTOPp->writeReg)))) {
                vlTOPp->RF__DOT__regs_2 = vlTOPp->writeData;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->RF__DOT__regs_29 = 0U;
    } else {
        if (vlTOPp->RegWrite) {
            if ((0x20000000U & ((IData)(1U) << (IData)(vlTOPp->writeReg)))) {
                vlTOPp->RF__DOT__regs_29 = vlTOPp->writeData;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->RF__DOT__regs_22 = 0U;
    } else {
        if (vlTOPp->RegWrite) {
            if ((0x400000U & ((IData)(1U) << (IData)(vlTOPp->writeReg)))) {
                vlTOPp->RF__DOT__regs_22 = vlTOPp->writeData;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->RF__DOT__regs_15 = 0U;
    } else {
        if (vlTOPp->RegWrite) {
            if ((0x8000U & ((IData)(1U) << (IData)(vlTOPp->writeReg)))) {
                vlTOPp->RF__DOT__regs_15 = vlTOPp->writeData;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->RF__DOT__regs_8 = 0U;
    } else {
        if (vlTOPp->RegWrite) {
            if ((0x100U & ((IData)(1U) << (IData)(vlTOPp->writeReg)))) {
                vlTOPp->RF__DOT__regs_8 = vlTOPp->writeData;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->RF__DOT__regs_1 = 0U;
    } else {
        if (vlTOPp->RegWrite) {
            if ((2U & ((IData)(1U) << (IData)(vlTOPp->writeReg)))) {
                vlTOPp->RF__DOT__regs_1 = vlTOPp->writeData;
            }
        }
    }
}

VL_INLINE_OPT void VRF::_sequent__TOP__3(VRF__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRF::_sequent__TOP__3\n"); );
    VRF* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->reset) {
        vlTOPp->RF__DOT__regs_28 = 0U;
    } else {
        if (vlTOPp->RegWrite) {
            if ((0x10000000U & ((IData)(1U) << (IData)(vlTOPp->writeReg)))) {
                vlTOPp->RF__DOT__regs_28 = vlTOPp->writeData;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->RF__DOT__regs_21 = 0U;
    } else {
        if (vlTOPp->RegWrite) {
            if ((0x200000U & ((IData)(1U) << (IData)(vlTOPp->writeReg)))) {
                vlTOPp->RF__DOT__regs_21 = vlTOPp->writeData;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->RF__DOT__regs_14 = 0U;
    } else {
        if (vlTOPp->RegWrite) {
            if ((0x4000U & ((IData)(1U) << (IData)(vlTOPp->writeReg)))) {
                vlTOPp->RF__DOT__regs_14 = vlTOPp->writeData;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->RF__DOT__regs_7 = 0U;
    } else {
        if (vlTOPp->RegWrite) {
            if ((0x80U & ((IData)(1U) << (IData)(vlTOPp->writeReg)))) {
                vlTOPp->RF__DOT__regs_7 = vlTOPp->writeData;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->RF__DOT__regs_0 = 0U;
    } else {
        if (vlTOPp->RegWrite) {
            if ((1U & ((IData)(1U) << (IData)(vlTOPp->writeReg)))) {
                vlTOPp->RF__DOT__regs_0 = vlTOPp->writeData;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->RF__DOT__regs_27 = 0U;
    } else {
        if (vlTOPp->RegWrite) {
            if ((0x8000000U & ((IData)(1U) << (IData)(vlTOPp->writeReg)))) {
                vlTOPp->RF__DOT__regs_27 = vlTOPp->writeData;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->RF__DOT__regs_20 = 0U;
    } else {
        if (vlTOPp->RegWrite) {
            if ((0x100000U & ((IData)(1U) << (IData)(vlTOPp->writeReg)))) {
                vlTOPp->RF__DOT__regs_20 = vlTOPp->writeData;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->RF__DOT__regs_13 = 0U;
    } else {
        if (vlTOPp->RegWrite) {
            if ((0x2000U & ((IData)(1U) << (IData)(vlTOPp->writeReg)))) {
                vlTOPp->RF__DOT__regs_13 = vlTOPp->writeData;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->RF__DOT__regs_6 = 0U;
    } else {
        if (vlTOPp->RegWrite) {
            if ((0x40U & ((IData)(1U) << (IData)(vlTOPp->writeReg)))) {
                vlTOPp->RF__DOT__regs_6 = vlTOPp->writeData;
            }
        }
    }
}

VL_INLINE_OPT void VRF::_settle__TOP__4(VRF__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRF::_settle__TOP__4\n"); );
    VRF* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->RF__DOT___zz_2_ = ((0x10U & (IData)(vlTOPp->readReg1))
                                ? ((8U & (IData)(vlTOPp->readReg1))
                                    ? ((4U & (IData)(vlTOPp->readReg1))
                                        ? ((2U & (IData)(vlTOPp->readReg1))
                                            ? ((1U 
                                                & (IData)(vlTOPp->readReg1))
                                                ? (IData)(vlTOPp->RF__DOT__regs_31)
                                                : (IData)(vlTOPp->RF__DOT__regs_30))
                                            : ((1U 
                                                & (IData)(vlTOPp->readReg1))
                                                ? (IData)(vlTOPp->RF__DOT__regs_29)
                                                : (IData)(vlTOPp->RF__DOT__regs_28)))
                                        : ((2U & (IData)(vlTOPp->readReg1))
                                            ? ((1U 
                                                & (IData)(vlTOPp->readReg1))
                                                ? (IData)(vlTOPp->RF__DOT__regs_27)
                                                : (IData)(vlTOPp->RF__DOT__regs_26))
                                            : ((1U 
                                                & (IData)(vlTOPp->readReg1))
                                                ? (IData)(vlTOPp->RF__DOT__regs_25)
                                                : (IData)(vlTOPp->RF__DOT__regs_24))))
                                    : ((4U & (IData)(vlTOPp->readReg1))
                                        ? ((2U & (IData)(vlTOPp->readReg1))
                                            ? ((1U 
                                                & (IData)(vlTOPp->readReg1))
                                                ? (IData)(vlTOPp->RF__DOT__regs_23)
                                                : (IData)(vlTOPp->RF__DOT__regs_22))
                                            : ((1U 
                                                & (IData)(vlTOPp->readReg1))
                                                ? (IData)(vlTOPp->RF__DOT__regs_21)
                                                : (IData)(vlTOPp->RF__DOT__regs_20)))
                                        : ((2U & (IData)(vlTOPp->readReg1))
                                            ? ((1U 
                                                & (IData)(vlTOPp->readReg1))
                                                ? (IData)(vlTOPp->RF__DOT__regs_19)
                                                : (IData)(vlTOPp->RF__DOT__regs_18))
                                            : ((1U 
                                                & (IData)(vlTOPp->readReg1))
                                                ? (IData)(vlTOPp->RF__DOT__regs_17)
                                                : (IData)(vlTOPp->RF__DOT__regs_16)))))
                                : ((8U & (IData)(vlTOPp->readReg1))
                                    ? ((4U & (IData)(vlTOPp->readReg1))
                                        ? ((2U & (IData)(vlTOPp->readReg1))
                                            ? ((1U 
                                                & (IData)(vlTOPp->readReg1))
                                                ? (IData)(vlTOPp->RF__DOT__regs_15)
                                                : (IData)(vlTOPp->RF__DOT__regs_14))
                                            : ((1U 
                                                & (IData)(vlTOPp->readReg1))
                                                ? (IData)(vlTOPp->RF__DOT__regs_13)
                                                : (IData)(vlTOPp->RF__DOT__regs_12)))
                                        : ((2U & (IData)(vlTOPp->readReg1))
                                            ? ((1U 
                                                & (IData)(vlTOPp->readReg1))
                                                ? (IData)(vlTOPp->RF__DOT__regs_11)
                                                : (IData)(vlTOPp->RF__DOT__regs_10))
                                            : ((1U 
                                                & (IData)(vlTOPp->readReg1))
                                                ? (IData)(vlTOPp->RF__DOT__regs_9)
                                                : (IData)(vlTOPp->RF__DOT__regs_8))))
                                    : ((4U & (IData)(vlTOPp->readReg1))
                                        ? ((2U & (IData)(vlTOPp->readReg1))
                                            ? ((1U 
                                                & (IData)(vlTOPp->readReg1))
                                                ? (IData)(vlTOPp->RF__DOT__regs_7)
                                                : (IData)(vlTOPp->RF__DOT__regs_6))
                                            : ((1U 
                                                & (IData)(vlTOPp->readReg1))
                                                ? (IData)(vlTOPp->RF__DOT__regs_5)
                                                : (IData)(vlTOPp->RF__DOT__regs_4)))
                                        : ((2U & (IData)(vlTOPp->readReg1))
                                            ? ((1U 
                                                & (IData)(vlTOPp->readReg1))
                                                ? (IData)(vlTOPp->RF__DOT__regs_3)
                                                : (IData)(vlTOPp->RF__DOT__regs_2))
                                            : ((1U 
                                                & (IData)(vlTOPp->readReg1))
                                                ? (IData)(vlTOPp->RF__DOT__regs_1)
                                                : (IData)(vlTOPp->RF__DOT__regs_0))))));
    vlTOPp->RF__DOT___zz_3_ = ((0x10U & (IData)(vlTOPp->readReg2))
                                ? ((8U & (IData)(vlTOPp->readReg2))
                                    ? ((4U & (IData)(vlTOPp->readReg2))
                                        ? ((2U & (IData)(vlTOPp->readReg2))
                                            ? ((1U 
                                                & (IData)(vlTOPp->readReg2))
                                                ? (IData)(vlTOPp->RF__DOT__regs_31)
                                                : (IData)(vlTOPp->RF__DOT__regs_30))
                                            : ((1U 
                                                & (IData)(vlTOPp->readReg2))
                                                ? (IData)(vlTOPp->RF__DOT__regs_29)
                                                : (IData)(vlTOPp->RF__DOT__regs_28)))
                                        : ((2U & (IData)(vlTOPp->readReg2))
                                            ? ((1U 
                                                & (IData)(vlTOPp->readReg2))
                                                ? (IData)(vlTOPp->RF__DOT__regs_27)
                                                : (IData)(vlTOPp->RF__DOT__regs_26))
                                            : ((1U 
                                                & (IData)(vlTOPp->readReg2))
                                                ? (IData)(vlTOPp->RF__DOT__regs_25)
                                                : (IData)(vlTOPp->RF__DOT__regs_24))))
                                    : ((4U & (IData)(vlTOPp->readReg2))
                                        ? ((2U & (IData)(vlTOPp->readReg2))
                                            ? ((1U 
                                                & (IData)(vlTOPp->readReg2))
                                                ? (IData)(vlTOPp->RF__DOT__regs_23)
                                                : (IData)(vlTOPp->RF__DOT__regs_22))
                                            : ((1U 
                                                & (IData)(vlTOPp->readReg2))
                                                ? (IData)(vlTOPp->RF__DOT__regs_21)
                                                : (IData)(vlTOPp->RF__DOT__regs_20)))
                                        : ((2U & (IData)(vlTOPp->readReg2))
                                            ? ((1U 
                                                & (IData)(vlTOPp->readReg2))
                                                ? (IData)(vlTOPp->RF__DOT__regs_19)
                                                : (IData)(vlTOPp->RF__DOT__regs_18))
                                            : ((1U 
                                                & (IData)(vlTOPp->readReg2))
                                                ? (IData)(vlTOPp->RF__DOT__regs_17)
                                                : (IData)(vlTOPp->RF__DOT__regs_16)))))
                                : ((8U & (IData)(vlTOPp->readReg2))
                                    ? ((4U & (IData)(vlTOPp->readReg2))
                                        ? ((2U & (IData)(vlTOPp->readReg2))
                                            ? ((1U 
                                                & (IData)(vlTOPp->readReg2))
                                                ? (IData)(vlTOPp->RF__DOT__regs_15)
                                                : (IData)(vlTOPp->RF__DOT__regs_14))
                                            : ((1U 
                                                & (IData)(vlTOPp->readReg2))
                                                ? (IData)(vlTOPp->RF__DOT__regs_13)
                                                : (IData)(vlTOPp->RF__DOT__regs_12)))
                                        : ((2U & (IData)(vlTOPp->readReg2))
                                            ? ((1U 
                                                & (IData)(vlTOPp->readReg2))
                                                ? (IData)(vlTOPp->RF__DOT__regs_11)
                                                : (IData)(vlTOPp->RF__DOT__regs_10))
                                            : ((1U 
                                                & (IData)(vlTOPp->readReg2))
                                                ? (IData)(vlTOPp->RF__DOT__regs_9)
                                                : (IData)(vlTOPp->RF__DOT__regs_8))))
                                    : ((4U & (IData)(vlTOPp->readReg2))
                                        ? ((2U & (IData)(vlTOPp->readReg2))
                                            ? ((1U 
                                                & (IData)(vlTOPp->readReg2))
                                                ? (IData)(vlTOPp->RF__DOT__regs_7)
                                                : (IData)(vlTOPp->RF__DOT__regs_6))
                                            : ((1U 
                                                & (IData)(vlTOPp->readReg2))
                                                ? (IData)(vlTOPp->RF__DOT__regs_5)
                                                : (IData)(vlTOPp->RF__DOT__regs_4)))
                                        : ((2U & (IData)(vlTOPp->readReg2))
                                            ? ((1U 
                                                & (IData)(vlTOPp->readReg2))
                                                ? (IData)(vlTOPp->RF__DOT__regs_3)
                                                : (IData)(vlTOPp->RF__DOT__regs_2))
                                            : ((1U 
                                                & (IData)(vlTOPp->readReg2))
                                                ? (IData)(vlTOPp->RF__DOT__regs_1)
                                                : (IData)(vlTOPp->RF__DOT__regs_0))))));
    vlTOPp->readData1 = vlTOPp->RF__DOT___zz_2_;
    vlTOPp->readData2 = vlTOPp->RF__DOT___zz_3_;
}

void VRF::_eval(VRF__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRF::_eval\n"); );
    VRF* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->__Vm_traceActivity[1U] = 1U;
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    vlTOPp->_settle__TOP__4(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

VL_INLINE_OPT QData VRF::_change_request(VRF__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRF::_change_request\n"); );
    VRF* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData VRF::_change_request_1(VRF__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRF::_change_request_1\n"); );
    VRF* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VRF::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRF::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((readReg1 & 0xe0U))) {
        Verilated::overWidthError("readReg1");}
    if (VL_UNLIKELY((readReg2 & 0xe0U))) {
        Verilated::overWidthError("readReg2");}
    if (VL_UNLIKELY((writeReg & 0xe0U))) {
        Verilated::overWidthError("writeReg");}
    if (VL_UNLIKELY((RegWrite & 0xfeU))) {
        Verilated::overWidthError("RegWrite");}
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
