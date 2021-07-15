// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VImmGen__Syms.h"


//======================

void VImmGen::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void VImmGen::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VImmGen__Syms* __restrict vlSymsp = static_cast<VImmGen__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VImmGen::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void VImmGen::traceInitTop(void* userp, VerilatedVcd* tracep) {
    VImmGen__Syms* __restrict vlSymsp = static_cast<VImmGen__Syms*>(userp);
    VImmGen* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void VImmGen::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    VImmGen__Syms* __restrict vlSymsp = static_cast<VImmGen__Syms*>(userp);
    VImmGen* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBus(c+1,"io_instruction", false,-1, 31,0);
        tracep->declQuad(c+2,"io_immGenOut", false,-1, 63,0);
        tracep->declBus(c+1,"ImmGen io_instruction", false,-1, 31,0);
        tracep->declQuad(c+2,"ImmGen io_immGenOut", false,-1, 63,0);
    }
}

void VImmGen::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void VImmGen::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    VImmGen__Syms* __restrict vlSymsp = static_cast<VImmGen__Syms*>(userp);
    VImmGen* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void VImmGen::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    VImmGen__Syms* __restrict vlSymsp = static_cast<VImmGen__Syms*>(userp);
    VImmGen* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullIData(oldp+1,(vlTOPp->io_instruction),32);
        tracep->fullQData(oldp+2,(vlTOPp->io_immGenOut),64);
    }
}
