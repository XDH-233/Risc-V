// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VRF__Syms.h"


void VRF::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    VRF__Syms* __restrict vlSymsp = static_cast<VRF__Syms*>(userp);
    VRF* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void VRF::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    VRF__Syms* __restrict vlSymsp = static_cast<VRF__Syms*>(userp);
    VRF* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgSData(oldp+0,(vlTOPp->RF__DOT__regs_0),16);
            tracep->chgSData(oldp+1,(vlTOPp->RF__DOT__regs_1),16);
            tracep->chgSData(oldp+2,(vlTOPp->RF__DOT__regs_2),16);
            tracep->chgSData(oldp+3,(vlTOPp->RF__DOT__regs_3),16);
            tracep->chgSData(oldp+4,(vlTOPp->RF__DOT__regs_4),16);
            tracep->chgSData(oldp+5,(vlTOPp->RF__DOT__regs_5),16);
            tracep->chgSData(oldp+6,(vlTOPp->RF__DOT__regs_6),16);
            tracep->chgSData(oldp+7,(vlTOPp->RF__DOT__regs_7),16);
            tracep->chgSData(oldp+8,(vlTOPp->RF__DOT__regs_8),16);
            tracep->chgSData(oldp+9,(vlTOPp->RF__DOT__regs_9),16);
            tracep->chgSData(oldp+10,(vlTOPp->RF__DOT__regs_10),16);
            tracep->chgSData(oldp+11,(vlTOPp->RF__DOT__regs_11),16);
            tracep->chgSData(oldp+12,(vlTOPp->RF__DOT__regs_12),16);
            tracep->chgSData(oldp+13,(vlTOPp->RF__DOT__regs_13),16);
            tracep->chgSData(oldp+14,(vlTOPp->RF__DOT__regs_14),16);
            tracep->chgSData(oldp+15,(vlTOPp->RF__DOT__regs_15),16);
            tracep->chgSData(oldp+16,(vlTOPp->RF__DOT__regs_16),16);
            tracep->chgSData(oldp+17,(vlTOPp->RF__DOT__regs_17),16);
            tracep->chgSData(oldp+18,(vlTOPp->RF__DOT__regs_18),16);
            tracep->chgSData(oldp+19,(vlTOPp->RF__DOT__regs_19),16);
            tracep->chgSData(oldp+20,(vlTOPp->RF__DOT__regs_20),16);
            tracep->chgSData(oldp+21,(vlTOPp->RF__DOT__regs_21),16);
            tracep->chgSData(oldp+22,(vlTOPp->RF__DOT__regs_22),16);
            tracep->chgSData(oldp+23,(vlTOPp->RF__DOT__regs_23),16);
            tracep->chgSData(oldp+24,(vlTOPp->RF__DOT__regs_24),16);
            tracep->chgSData(oldp+25,(vlTOPp->RF__DOT__regs_25),16);
            tracep->chgSData(oldp+26,(vlTOPp->RF__DOT__regs_26),16);
            tracep->chgSData(oldp+27,(vlTOPp->RF__DOT__regs_27),16);
            tracep->chgSData(oldp+28,(vlTOPp->RF__DOT__regs_28),16);
            tracep->chgSData(oldp+29,(vlTOPp->RF__DOT__regs_29),16);
            tracep->chgSData(oldp+30,(vlTOPp->RF__DOT__regs_30),16);
            tracep->chgSData(oldp+31,(vlTOPp->RF__DOT__regs_31),16);
        }
        tracep->chgCData(oldp+32,(vlTOPp->readReg1),5);
        tracep->chgCData(oldp+33,(vlTOPp->readReg2),5);
        tracep->chgCData(oldp+34,(vlTOPp->writeReg),5);
        tracep->chgSData(oldp+35,(vlTOPp->writeData),16);
        tracep->chgSData(oldp+36,(vlTOPp->readData1),16);
        tracep->chgSData(oldp+37,(vlTOPp->readData2),16);
        tracep->chgBit(oldp+38,(vlTOPp->RegWrite));
        tracep->chgBit(oldp+39,(vlTOPp->clk));
        tracep->chgBit(oldp+40,(vlTOPp->reset));
    }
}

void VRF::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    VRF__Syms* __restrict vlSymsp = static_cast<VRF__Syms*>(userp);
    VRF* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
    }
}
