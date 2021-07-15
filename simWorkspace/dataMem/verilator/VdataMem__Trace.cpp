// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VdataMem__Syms.h"


void VdataMem::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    VdataMem__Syms* __restrict vlSymsp = static_cast<VdataMem__Syms*>(userp);
    VdataMem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void VdataMem::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    VdataMem__Syms* __restrict vlSymsp = static_cast<VdataMem__Syms*>(userp);
    VdataMem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgCData(oldp+0,(vlTOPp->address),8);
        tracep->chgSData(oldp+1,(vlTOPp->writeData),16);
        tracep->chgSData(oldp+2,(vlTOPp->readData),16);
        tracep->chgBit(oldp+3,(vlTOPp->memRead));
        tracep->chgBit(oldp+4,(vlTOPp->memWrite));
        tracep->chgBit(oldp+5,(vlTOPp->clk));
        tracep->chgBit(oldp+6,(vlTOPp->reset));
    }
}

void VdataMem::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    VdataMem__Syms* __restrict vlSymsp = static_cast<VdataMem__Syms*>(userp);
    VdataMem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
    }
}
