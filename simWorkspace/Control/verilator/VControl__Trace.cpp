// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VControl__Syms.h"


void VControl::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    VControl__Syms* __restrict vlSymsp = static_cast<VControl__Syms*>(userp);
    VControl* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void VControl::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    VControl__Syms* __restrict vlSymsp = static_cast<VControl__Syms*>(userp);
    VControl* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgCData(oldp+0,(vlTOPp->opCode),7);
        tracep->chgBit(oldp+1,(vlTOPp->Branch));
        tracep->chgBit(oldp+2,(vlTOPp->MemRead));
        tracep->chgBit(oldp+3,(vlTOPp->MemtoReg));
        tracep->chgCData(oldp+4,(vlTOPp->ALUop),2);
        tracep->chgBit(oldp+5,(vlTOPp->MemWrite));
        tracep->chgBit(oldp+6,(vlTOPp->ALUSrc));
        tracep->chgBit(oldp+7,(vlTOPp->RegWrite));
    }
}

void VControl::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    VControl__Syms* __restrict vlSymsp = static_cast<VControl__Syms*>(userp);
    VControl* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
    }
}
