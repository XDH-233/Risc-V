// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VImmGen__Syms.h"


void VImmGen::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    VImmGen__Syms* __restrict vlSymsp = static_cast<VImmGen__Syms*>(userp);
    VImmGen* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void VImmGen::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    VImmGen__Syms* __restrict vlSymsp = static_cast<VImmGen__Syms*>(userp);
    VImmGen* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgIData(oldp+0,(vlTOPp->io_instruction),32);
        tracep->chgQData(oldp+1,(vlTOPp->io_immGenOut),64);
    }
}

void VImmGen::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    VImmGen__Syms* __restrict vlSymsp = static_cast<VImmGen__Syms*>(userp);
    VImmGen* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
    }
}
