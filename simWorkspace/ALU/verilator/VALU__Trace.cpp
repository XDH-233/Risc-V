// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VALU__Syms.h"


void VALU::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    VALU__Syms* __restrict vlSymsp = static_cast<VALU__Syms*>(userp);
    VALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void VALU::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    VALU__Syms* __restrict vlSymsp = static_cast<VALU__Syms*>(userp);
    VALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgCData(oldp+0,(vlTOPp->ALUop),2);
        tracep->chgCData(oldp+1,(vlTOPp->funct7),7);
        tracep->chgCData(oldp+2,(vlTOPp->funct3),3);
        tracep->chgCData(oldp+3,(vlTOPp->data1),8);
        tracep->chgCData(oldp+4,(vlTOPp->data2),8);
        tracep->chgBit(oldp+5,(vlTOPp->Zero));
        tracep->chgCData(oldp+6,(vlTOPp->Result),8);
        tracep->chgCData(oldp+7,(vlTOPp->ALU__DOT__ALUCtrl),4);
    }
}

void VALU::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    VALU__Syms* __restrict vlSymsp = static_cast<VALU__Syms*>(userp);
    VALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
    }
}
