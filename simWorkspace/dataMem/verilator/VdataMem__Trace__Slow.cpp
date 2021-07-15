// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VdataMem__Syms.h"


//======================

void VdataMem::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void VdataMem::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VdataMem__Syms* __restrict vlSymsp = static_cast<VdataMem__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VdataMem::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void VdataMem::traceInitTop(void* userp, VerilatedVcd* tracep) {
    VdataMem__Syms* __restrict vlSymsp = static_cast<VdataMem__Syms*>(userp);
    VdataMem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void VdataMem::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    VdataMem__Syms* __restrict vlSymsp = static_cast<VdataMem__Syms*>(userp);
    VdataMem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBus(c+1,"address", false,-1, 7,0);
        tracep->declBus(c+2,"writeData", false,-1, 15,0);
        tracep->declBus(c+3,"readData", false,-1, 15,0);
        tracep->declBit(c+4,"memRead", false,-1);
        tracep->declBit(c+5,"memWrite", false,-1);
        tracep->declBit(c+6,"clk", false,-1);
        tracep->declBit(c+7,"reset", false,-1);
        tracep->declBus(c+1,"dataMem address", false,-1, 7,0);
        tracep->declBus(c+2,"dataMem writeData", false,-1, 15,0);
        tracep->declBus(c+3,"dataMem readData", false,-1, 15,0);
        tracep->declBit(c+4,"dataMem memRead", false,-1);
        tracep->declBit(c+5,"dataMem memWrite", false,-1);
        tracep->declBit(c+6,"dataMem clk", false,-1);
        tracep->declBit(c+7,"dataMem reset", false,-1);
    }
}

void VdataMem::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void VdataMem::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    VdataMem__Syms* __restrict vlSymsp = static_cast<VdataMem__Syms*>(userp);
    VdataMem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void VdataMem::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    VdataMem__Syms* __restrict vlSymsp = static_cast<VdataMem__Syms*>(userp);
    VdataMem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullCData(oldp+1,(vlTOPp->address),8);
        tracep->fullSData(oldp+2,(vlTOPp->writeData),16);
        tracep->fullSData(oldp+3,(vlTOPp->readData),16);
        tracep->fullBit(oldp+4,(vlTOPp->memRead));
        tracep->fullBit(oldp+5,(vlTOPp->memWrite));
        tracep->fullBit(oldp+6,(vlTOPp->clk));
        tracep->fullBit(oldp+7,(vlTOPp->reset));
    }
}
