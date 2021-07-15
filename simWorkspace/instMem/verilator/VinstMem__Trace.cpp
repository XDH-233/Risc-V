// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VinstMem__Syms.h"


void VinstMem::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    VinstMem__Syms* __restrict vlSymsp = static_cast<VinstMem__Syms*>(userp);
    VinstMem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void VinstMem::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    VinstMem__Syms* __restrict vlSymsp = static_cast<VinstMem__Syms*>(userp);
    VinstMem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgSData(oldp+0,(vlTOPp->address),9);
        tracep->chgIData(oldp+1,(vlTOPp->instruction),32);
    }
}

void VinstMem::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    VinstMem__Syms* __restrict vlSymsp = static_cast<VinstMem__Syms*>(userp);
    VinstMem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
    }
}
