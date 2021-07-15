// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VRF__Syms.h"


//======================

void VRF::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void VRF::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VRF__Syms* __restrict vlSymsp = static_cast<VRF__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VRF::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void VRF::traceInitTop(void* userp, VerilatedVcd* tracep) {
    VRF__Syms* __restrict vlSymsp = static_cast<VRF__Syms*>(userp);
    VRF* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void VRF::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    VRF__Syms* __restrict vlSymsp = static_cast<VRF__Syms*>(userp);
    VRF* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBus(c+33,"readReg1", false,-1, 4,0);
        tracep->declBus(c+34,"readReg2", false,-1, 4,0);
        tracep->declBus(c+35,"writeReg", false,-1, 4,0);
        tracep->declBus(c+36,"writeData", false,-1, 15,0);
        tracep->declBus(c+37,"readData1", false,-1, 15,0);
        tracep->declBus(c+38,"readData2", false,-1, 15,0);
        tracep->declBit(c+39,"RegWrite", false,-1);
        tracep->declBit(c+40,"clk", false,-1);
        tracep->declBit(c+41,"reset", false,-1);
        tracep->declBus(c+33,"RF readReg1", false,-1, 4,0);
        tracep->declBus(c+34,"RF readReg2", false,-1, 4,0);
        tracep->declBus(c+35,"RF writeReg", false,-1, 4,0);
        tracep->declBus(c+36,"RF writeData", false,-1, 15,0);
        tracep->declBus(c+37,"RF readData1", false,-1, 15,0);
        tracep->declBus(c+38,"RF readData2", false,-1, 15,0);
        tracep->declBit(c+39,"RF RegWrite", false,-1);
        tracep->declBit(c+40,"RF clk", false,-1);
        tracep->declBit(c+41,"RF reset", false,-1);
        tracep->declBus(c+1,"RF regs_0", false,-1, 15,0);
        tracep->declBus(c+2,"RF regs_1", false,-1, 15,0);
        tracep->declBus(c+3,"RF regs_2", false,-1, 15,0);
        tracep->declBus(c+4,"RF regs_3", false,-1, 15,0);
        tracep->declBus(c+5,"RF regs_4", false,-1, 15,0);
        tracep->declBus(c+6,"RF regs_5", false,-1, 15,0);
        tracep->declBus(c+7,"RF regs_6", false,-1, 15,0);
        tracep->declBus(c+8,"RF regs_7", false,-1, 15,0);
        tracep->declBus(c+9,"RF regs_8", false,-1, 15,0);
        tracep->declBus(c+10,"RF regs_9", false,-1, 15,0);
        tracep->declBus(c+11,"RF regs_10", false,-1, 15,0);
        tracep->declBus(c+12,"RF regs_11", false,-1, 15,0);
        tracep->declBus(c+13,"RF regs_12", false,-1, 15,0);
        tracep->declBus(c+14,"RF regs_13", false,-1, 15,0);
        tracep->declBus(c+15,"RF regs_14", false,-1, 15,0);
        tracep->declBus(c+16,"RF regs_15", false,-1, 15,0);
        tracep->declBus(c+17,"RF regs_16", false,-1, 15,0);
        tracep->declBus(c+18,"RF regs_17", false,-1, 15,0);
        tracep->declBus(c+19,"RF regs_18", false,-1, 15,0);
        tracep->declBus(c+20,"RF regs_19", false,-1, 15,0);
        tracep->declBus(c+21,"RF regs_20", false,-1, 15,0);
        tracep->declBus(c+22,"RF regs_21", false,-1, 15,0);
        tracep->declBus(c+23,"RF regs_22", false,-1, 15,0);
        tracep->declBus(c+24,"RF regs_23", false,-1, 15,0);
        tracep->declBus(c+25,"RF regs_24", false,-1, 15,0);
        tracep->declBus(c+26,"RF regs_25", false,-1, 15,0);
        tracep->declBus(c+27,"RF regs_26", false,-1, 15,0);
        tracep->declBus(c+28,"RF regs_27", false,-1, 15,0);
        tracep->declBus(c+29,"RF regs_28", false,-1, 15,0);
        tracep->declBus(c+30,"RF regs_29", false,-1, 15,0);
        tracep->declBus(c+31,"RF regs_30", false,-1, 15,0);
        tracep->declBus(c+32,"RF regs_31", false,-1, 15,0);
    }
}

void VRF::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void VRF::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    VRF__Syms* __restrict vlSymsp = static_cast<VRF__Syms*>(userp);
    VRF* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void VRF::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    VRF__Syms* __restrict vlSymsp = static_cast<VRF__Syms*>(userp);
    VRF* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullSData(oldp+1,(vlTOPp->RF__DOT__regs_0),16);
        tracep->fullSData(oldp+2,(vlTOPp->RF__DOT__regs_1),16);
        tracep->fullSData(oldp+3,(vlTOPp->RF__DOT__regs_2),16);
        tracep->fullSData(oldp+4,(vlTOPp->RF__DOT__regs_3),16);
        tracep->fullSData(oldp+5,(vlTOPp->RF__DOT__regs_4),16);
        tracep->fullSData(oldp+6,(vlTOPp->RF__DOT__regs_5),16);
        tracep->fullSData(oldp+7,(vlTOPp->RF__DOT__regs_6),16);
        tracep->fullSData(oldp+8,(vlTOPp->RF__DOT__regs_7),16);
        tracep->fullSData(oldp+9,(vlTOPp->RF__DOT__regs_8),16);
        tracep->fullSData(oldp+10,(vlTOPp->RF__DOT__regs_9),16);
        tracep->fullSData(oldp+11,(vlTOPp->RF__DOT__regs_10),16);
        tracep->fullSData(oldp+12,(vlTOPp->RF__DOT__regs_11),16);
        tracep->fullSData(oldp+13,(vlTOPp->RF__DOT__regs_12),16);
        tracep->fullSData(oldp+14,(vlTOPp->RF__DOT__regs_13),16);
        tracep->fullSData(oldp+15,(vlTOPp->RF__DOT__regs_14),16);
        tracep->fullSData(oldp+16,(vlTOPp->RF__DOT__regs_15),16);
        tracep->fullSData(oldp+17,(vlTOPp->RF__DOT__regs_16),16);
        tracep->fullSData(oldp+18,(vlTOPp->RF__DOT__regs_17),16);
        tracep->fullSData(oldp+19,(vlTOPp->RF__DOT__regs_18),16);
        tracep->fullSData(oldp+20,(vlTOPp->RF__DOT__regs_19),16);
        tracep->fullSData(oldp+21,(vlTOPp->RF__DOT__regs_20),16);
        tracep->fullSData(oldp+22,(vlTOPp->RF__DOT__regs_21),16);
        tracep->fullSData(oldp+23,(vlTOPp->RF__DOT__regs_22),16);
        tracep->fullSData(oldp+24,(vlTOPp->RF__DOT__regs_23),16);
        tracep->fullSData(oldp+25,(vlTOPp->RF__DOT__regs_24),16);
        tracep->fullSData(oldp+26,(vlTOPp->RF__DOT__regs_25),16);
        tracep->fullSData(oldp+27,(vlTOPp->RF__DOT__regs_26),16);
        tracep->fullSData(oldp+28,(vlTOPp->RF__DOT__regs_27),16);
        tracep->fullSData(oldp+29,(vlTOPp->RF__DOT__regs_28),16);
        tracep->fullSData(oldp+30,(vlTOPp->RF__DOT__regs_29),16);
        tracep->fullSData(oldp+31,(vlTOPp->RF__DOT__regs_30),16);
        tracep->fullSData(oldp+32,(vlTOPp->RF__DOT__regs_31),16);
        tracep->fullCData(oldp+33,(vlTOPp->readReg1),5);
        tracep->fullCData(oldp+34,(vlTOPp->readReg2),5);
        tracep->fullCData(oldp+35,(vlTOPp->writeReg),5);
        tracep->fullSData(oldp+36,(vlTOPp->writeData),16);
        tracep->fullSData(oldp+37,(vlTOPp->readData1),16);
        tracep->fullSData(oldp+38,(vlTOPp->readData2),16);
        tracep->fullBit(oldp+39,(vlTOPp->RegWrite));
        tracep->fullBit(oldp+40,(vlTOPp->clk));
        tracep->fullBit(oldp+41,(vlTOPp->reset));
    }
}
