// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VControl__Syms.h"


//======================

void VControl::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void VControl::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VControl__Syms* __restrict vlSymsp = static_cast<VControl__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VControl::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void VControl::traceInitTop(void* userp, VerilatedVcd* tracep) {
    VControl__Syms* __restrict vlSymsp = static_cast<VControl__Syms*>(userp);
    VControl* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void VControl::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    VControl__Syms* __restrict vlSymsp = static_cast<VControl__Syms*>(userp);
    VControl* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBus(c+1,"opCode", false,-1, 6,0);
        tracep->declBit(c+2,"Branch", false,-1);
        tracep->declBit(c+3,"MemRead", false,-1);
        tracep->declBit(c+4,"MemtoReg", false,-1);
        tracep->declBus(c+5,"ALUop", false,-1, 1,0);
        tracep->declBit(c+6,"MemWrite", false,-1);
        tracep->declBit(c+7,"ALUSrc", false,-1);
        tracep->declBit(c+8,"RegWrite", false,-1);
        tracep->declBus(c+1,"Control opCode", false,-1, 6,0);
        tracep->declBit(c+2,"Control Branch", false,-1);
        tracep->declBit(c+3,"Control MemRead", false,-1);
        tracep->declBit(c+4,"Control MemtoReg", false,-1);
        tracep->declBus(c+5,"Control ALUop", false,-1, 1,0);
        tracep->declBit(c+6,"Control MemWrite", false,-1);
        tracep->declBit(c+7,"Control ALUSrc", false,-1);
        tracep->declBit(c+8,"Control RegWrite", false,-1);
    }
}

void VControl::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void VControl::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    VControl__Syms* __restrict vlSymsp = static_cast<VControl__Syms*>(userp);
    VControl* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void VControl::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    VControl__Syms* __restrict vlSymsp = static_cast<VControl__Syms*>(userp);
    VControl* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullCData(oldp+1,(vlTOPp->opCode),7);
        tracep->fullBit(oldp+2,(vlTOPp->Branch));
        tracep->fullBit(oldp+3,(vlTOPp->MemRead));
        tracep->fullBit(oldp+4,(vlTOPp->MemtoReg));
        tracep->fullCData(oldp+5,(vlTOPp->ALUop),2);
        tracep->fullBit(oldp+6,(vlTOPp->MemWrite));
        tracep->fullBit(oldp+7,(vlTOPp->ALUSrc));
        tracep->fullBit(oldp+8,(vlTOPp->RegWrite));
    }
}
