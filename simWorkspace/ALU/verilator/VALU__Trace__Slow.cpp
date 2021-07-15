// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VALU__Syms.h"


//======================

void VALU::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void VALU::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VALU__Syms* __restrict vlSymsp = static_cast<VALU__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VALU::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void VALU::traceInitTop(void* userp, VerilatedVcd* tracep) {
    VALU__Syms* __restrict vlSymsp = static_cast<VALU__Syms*>(userp);
    VALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void VALU::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    VALU__Syms* __restrict vlSymsp = static_cast<VALU__Syms*>(userp);
    VALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBus(c+1,"ALUop", false,-1, 1,0);
        tracep->declBus(c+2,"funct7", false,-1, 6,0);
        tracep->declBus(c+3,"funct3", false,-1, 2,0);
        tracep->declBus(c+4,"data1", false,-1, 7,0);
        tracep->declBus(c+5,"data2", false,-1, 7,0);
        tracep->declBit(c+6,"Zero", false,-1);
        tracep->declBus(c+7,"Result", false,-1, 7,0);
        tracep->declBus(c+1,"ALU ALUop", false,-1, 1,0);
        tracep->declBus(c+2,"ALU funct7", false,-1, 6,0);
        tracep->declBus(c+3,"ALU funct3", false,-1, 2,0);
        tracep->declBus(c+4,"ALU data1", false,-1, 7,0);
        tracep->declBus(c+5,"ALU data2", false,-1, 7,0);
        tracep->declBit(c+6,"ALU Zero", false,-1);
        tracep->declBus(c+7,"ALU Result", false,-1, 7,0);
        tracep->declBus(c+8,"ALU ALUCtrl", false,-1, 3,0);
    }
}

void VALU::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void VALU::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    VALU__Syms* __restrict vlSymsp = static_cast<VALU__Syms*>(userp);
    VALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void VALU::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    VALU__Syms* __restrict vlSymsp = static_cast<VALU__Syms*>(userp);
    VALU* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullCData(oldp+1,(vlTOPp->ALUop),2);
        tracep->fullCData(oldp+2,(vlTOPp->funct7),7);
        tracep->fullCData(oldp+3,(vlTOPp->funct3),3);
        tracep->fullCData(oldp+4,(vlTOPp->data1),8);
        tracep->fullCData(oldp+5,(vlTOPp->data2),8);
        tracep->fullBit(oldp+6,(vlTOPp->Zero));
        tracep->fullCData(oldp+7,(vlTOPp->Result),8);
        tracep->fullCData(oldp+8,(vlTOPp->ALU__DOT__ALUCtrl),4);
    }
}
