// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VinstMem__Syms.h"


//======================

void VinstMem::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void VinstMem::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VinstMem__Syms* __restrict vlSymsp = static_cast<VinstMem__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VinstMem::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void VinstMem::traceInitTop(void* userp, VerilatedVcd* tracep) {
    VinstMem__Syms* __restrict vlSymsp = static_cast<VinstMem__Syms*>(userp);
    VinstMem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void VinstMem::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    VinstMem__Syms* __restrict vlSymsp = static_cast<VinstMem__Syms*>(userp);
    VinstMem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBus(c+1,"address", false,-1, 8,0);
        tracep->declBus(c+2,"instruction", false,-1, 31,0);
        tracep->declBus(c+1,"instMem address", false,-1, 8,0);
        tracep->declBus(c+2,"instMem instruction", false,-1, 31,0);
        tracep->declBus(c+3,"instMem content_0", false,-1, 31,0);
        tracep->declBus(c+4,"instMem content_1", false,-1, 31,0);
        tracep->declBus(c+5,"instMem content_2", false,-1, 31,0);
        tracep->declBus(c+6,"instMem content_3", false,-1, 31,0);
        tracep->declBus(c+7,"instMem content_4", false,-1, 31,0);
        tracep->declBus(c+8,"instMem content_5", false,-1, 31,0);
        tracep->declBus(c+9,"instMem content_6", false,-1, 31,0);
        tracep->declBus(c+10,"instMem content_7", false,-1, 31,0);
        tracep->declBus(c+11,"instMem content_8", false,-1, 31,0);
        tracep->declBus(c+12,"instMem content_9", false,-1, 31,0);
        tracep->declBus(c+13,"instMem content_10", false,-1, 31,0);
        tracep->declBus(c+14,"instMem content_11", false,-1, 31,0);
        tracep->declBus(c+15,"instMem content_12", false,-1, 31,0);
        tracep->declBus(c+16,"instMem content_13", false,-1, 31,0);
        tracep->declBus(c+17,"instMem content_14", false,-1, 31,0);
        tracep->declBus(c+18,"instMem content_15", false,-1, 31,0);
        tracep->declBus(c+19,"instMem content_16", false,-1, 31,0);
        tracep->declBus(c+20,"instMem content_17", false,-1, 31,0);
        tracep->declBus(c+21,"instMem content_18", false,-1, 31,0);
        tracep->declBus(c+22,"instMem content_19", false,-1, 31,0);
        tracep->declBus(c+23,"instMem content_20", false,-1, 31,0);
        tracep->declBus(c+24,"instMem content_21", false,-1, 31,0);
        tracep->declBus(c+25,"instMem content_22", false,-1, 31,0);
        tracep->declBus(c+26,"instMem content_23", false,-1, 31,0);
        tracep->declBus(c+27,"instMem content_24", false,-1, 31,0);
        tracep->declBus(c+28,"instMem content_25", false,-1, 31,0);
        tracep->declBus(c+29,"instMem content_26", false,-1, 31,0);
        tracep->declBus(c+30,"instMem content_27", false,-1, 31,0);
        tracep->declBus(c+31,"instMem content_28", false,-1, 31,0);
        tracep->declBus(c+32,"instMem content_29", false,-1, 31,0);
        tracep->declBus(c+33,"instMem content_30", false,-1, 31,0);
        tracep->declBus(c+34,"instMem content_31", false,-1, 31,0);
        tracep->declBus(c+35,"instMem content_32", false,-1, 31,0);
        tracep->declBus(c+36,"instMem content_33", false,-1, 31,0);
        tracep->declBus(c+37,"instMem content_34", false,-1, 31,0);
        tracep->declBus(c+38,"instMem content_35", false,-1, 31,0);
        tracep->declBus(c+39,"instMem content_36", false,-1, 31,0);
        tracep->declBus(c+40,"instMem content_37", false,-1, 31,0);
        tracep->declBus(c+41,"instMem content_38", false,-1, 31,0);
        tracep->declBus(c+42,"instMem content_39", false,-1, 31,0);
        tracep->declBus(c+43,"instMem content_40", false,-1, 31,0);
        tracep->declBus(c+44,"instMem content_41", false,-1, 31,0);
        tracep->declBus(c+45,"instMem content_42", false,-1, 31,0);
        tracep->declBus(c+46,"instMem content_43", false,-1, 31,0);
        tracep->declBus(c+47,"instMem content_44", false,-1, 31,0);
        tracep->declBus(c+48,"instMem content_45", false,-1, 31,0);
        tracep->declBus(c+49,"instMem content_46", false,-1, 31,0);
        tracep->declBus(c+50,"instMem content_47", false,-1, 31,0);
        tracep->declBus(c+51,"instMem content_48", false,-1, 31,0);
        tracep->declBus(c+52,"instMem content_49", false,-1, 31,0);
        tracep->declBus(c+53,"instMem content_50", false,-1, 31,0);
        tracep->declBus(c+54,"instMem content_51", false,-1, 31,0);
        tracep->declBus(c+55,"instMem content_52", false,-1, 31,0);
        tracep->declBus(c+56,"instMem content_53", false,-1, 31,0);
        tracep->declBus(c+57,"instMem content_54", false,-1, 31,0);
        tracep->declBus(c+58,"instMem content_55", false,-1, 31,0);
        tracep->declBus(c+59,"instMem content_56", false,-1, 31,0);
        tracep->declBus(c+60,"instMem content_57", false,-1, 31,0);
        tracep->declBus(c+61,"instMem content_58", false,-1, 31,0);
        tracep->declBus(c+62,"instMem content_59", false,-1, 31,0);
        tracep->declBus(c+63,"instMem content_60", false,-1, 31,0);
        tracep->declBus(c+64,"instMem content_61", false,-1, 31,0);
        tracep->declBus(c+65,"instMem content_62", false,-1, 31,0);
        tracep->declBus(c+66,"instMem content_63", false,-1, 31,0);
        tracep->declBus(c+67,"instMem content_64", false,-1, 31,0);
        tracep->declBus(c+68,"instMem content_65", false,-1, 31,0);
        tracep->declBus(c+69,"instMem content_66", false,-1, 31,0);
        tracep->declBus(c+70,"instMem content_67", false,-1, 31,0);
        tracep->declBus(c+71,"instMem content_68", false,-1, 31,0);
        tracep->declBus(c+72,"instMem content_69", false,-1, 31,0);
        tracep->declBus(c+73,"instMem content_70", false,-1, 31,0);
        tracep->declBus(c+74,"instMem content_71", false,-1, 31,0);
        tracep->declBus(c+75,"instMem content_72", false,-1, 31,0);
        tracep->declBus(c+76,"instMem content_73", false,-1, 31,0);
        tracep->declBus(c+77,"instMem content_74", false,-1, 31,0);
        tracep->declBus(c+78,"instMem content_75", false,-1, 31,0);
        tracep->declBus(c+79,"instMem content_76", false,-1, 31,0);
        tracep->declBus(c+80,"instMem content_77", false,-1, 31,0);
        tracep->declBus(c+81,"instMem content_78", false,-1, 31,0);
        tracep->declBus(c+82,"instMem content_79", false,-1, 31,0);
        tracep->declBus(c+83,"instMem content_80", false,-1, 31,0);
        tracep->declBus(c+84,"instMem content_81", false,-1, 31,0);
        tracep->declBus(c+85,"instMem content_82", false,-1, 31,0);
        tracep->declBus(c+86,"instMem content_83", false,-1, 31,0);
        tracep->declBus(c+87,"instMem content_84", false,-1, 31,0);
        tracep->declBus(c+88,"instMem content_85", false,-1, 31,0);
        tracep->declBus(c+89,"instMem content_86", false,-1, 31,0);
        tracep->declBus(c+90,"instMem content_87", false,-1, 31,0);
        tracep->declBus(c+91,"instMem content_88", false,-1, 31,0);
        tracep->declBus(c+92,"instMem content_89", false,-1, 31,0);
        tracep->declBus(c+93,"instMem content_90", false,-1, 31,0);
        tracep->declBus(c+94,"instMem content_91", false,-1, 31,0);
        tracep->declBus(c+95,"instMem content_92", false,-1, 31,0);
        tracep->declBus(c+96,"instMem content_93", false,-1, 31,0);
        tracep->declBus(c+97,"instMem content_94", false,-1, 31,0);
        tracep->declBus(c+98,"instMem content_95", false,-1, 31,0);
        tracep->declBus(c+99,"instMem content_96", false,-1, 31,0);
        tracep->declBus(c+100,"instMem content_97", false,-1, 31,0);
        tracep->declBus(c+101,"instMem content_98", false,-1, 31,0);
        tracep->declBus(c+102,"instMem content_99", false,-1, 31,0);
        tracep->declBus(c+103,"instMem content_100", false,-1, 31,0);
        tracep->declBus(c+104,"instMem content_101", false,-1, 31,0);
        tracep->declBus(c+105,"instMem content_102", false,-1, 31,0);
        tracep->declBus(c+106,"instMem content_103", false,-1, 31,0);
        tracep->declBus(c+107,"instMem content_104", false,-1, 31,0);
        tracep->declBus(c+108,"instMem content_105", false,-1, 31,0);
        tracep->declBus(c+109,"instMem content_106", false,-1, 31,0);
        tracep->declBus(c+110,"instMem content_107", false,-1, 31,0);
        tracep->declBus(c+111,"instMem content_108", false,-1, 31,0);
        tracep->declBus(c+112,"instMem content_109", false,-1, 31,0);
        tracep->declBus(c+113,"instMem content_110", false,-1, 31,0);
        tracep->declBus(c+114,"instMem content_111", false,-1, 31,0);
        tracep->declBus(c+115,"instMem content_112", false,-1, 31,0);
        tracep->declBus(c+116,"instMem content_113", false,-1, 31,0);
        tracep->declBus(c+117,"instMem content_114", false,-1, 31,0);
        tracep->declBus(c+118,"instMem content_115", false,-1, 31,0);
        tracep->declBus(c+119,"instMem content_116", false,-1, 31,0);
        tracep->declBus(c+120,"instMem content_117", false,-1, 31,0);
        tracep->declBus(c+121,"instMem content_118", false,-1, 31,0);
        tracep->declBus(c+122,"instMem content_119", false,-1, 31,0);
        tracep->declBus(c+123,"instMem content_120", false,-1, 31,0);
        tracep->declBus(c+124,"instMem content_121", false,-1, 31,0);
        tracep->declBus(c+125,"instMem content_122", false,-1, 31,0);
        tracep->declBus(c+126,"instMem content_123", false,-1, 31,0);
        tracep->declBus(c+127,"instMem content_124", false,-1, 31,0);
        tracep->declBus(c+128,"instMem content_125", false,-1, 31,0);
        tracep->declBus(c+129,"instMem content_126", false,-1, 31,0);
        tracep->declBus(c+130,"instMem content_127", false,-1, 31,0);
    }
}

void VinstMem::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void VinstMem::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    VinstMem__Syms* __restrict vlSymsp = static_cast<VinstMem__Syms*>(userp);
    VinstMem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void VinstMem::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    VinstMem__Syms* __restrict vlSymsp = static_cast<VinstMem__Syms*>(userp);
    VinstMem* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullSData(oldp+1,(vlTOPp->address),9);
        tracep->fullIData(oldp+2,(vlTOPp->instruction),32);
        tracep->fullIData(oldp+3,(0U),32);
        tracep->fullIData(oldp+4,(1U),32);
        tracep->fullIData(oldp+5,(2U),32);
        tracep->fullIData(oldp+6,(3U),32);
        tracep->fullIData(oldp+7,(4U),32);
        tracep->fullIData(oldp+8,(5U),32);
        tracep->fullIData(oldp+9,(6U),32);
        tracep->fullIData(oldp+10,(7U),32);
        tracep->fullIData(oldp+11,(8U),32);
        tracep->fullIData(oldp+12,(9U),32);
        tracep->fullIData(oldp+13,(0xaU),32);
        tracep->fullIData(oldp+14,(0xbU),32);
        tracep->fullIData(oldp+15,(0xcU),32);
        tracep->fullIData(oldp+16,(0xdU),32);
        tracep->fullIData(oldp+17,(0xeU),32);
        tracep->fullIData(oldp+18,(0xfU),32);
        tracep->fullIData(oldp+19,(0x10U),32);
        tracep->fullIData(oldp+20,(0x11U),32);
        tracep->fullIData(oldp+21,(0x12U),32);
        tracep->fullIData(oldp+22,(0x13U),32);
        tracep->fullIData(oldp+23,(0x14U),32);
        tracep->fullIData(oldp+24,(0x15U),32);
        tracep->fullIData(oldp+25,(0x16U),32);
        tracep->fullIData(oldp+26,(0x17U),32);
        tracep->fullIData(oldp+27,(0x18U),32);
        tracep->fullIData(oldp+28,(0x19U),32);
        tracep->fullIData(oldp+29,(0x1aU),32);
        tracep->fullIData(oldp+30,(0x1bU),32);
        tracep->fullIData(oldp+31,(0x1cU),32);
        tracep->fullIData(oldp+32,(0x1dU),32);
        tracep->fullIData(oldp+33,(0x1eU),32);
        tracep->fullIData(oldp+34,(0x1fU),32);
        tracep->fullIData(oldp+35,(0x20U),32);
        tracep->fullIData(oldp+36,(0x21U),32);
        tracep->fullIData(oldp+37,(0x22U),32);
        tracep->fullIData(oldp+38,(0x23U),32);
        tracep->fullIData(oldp+39,(0x24U),32);
        tracep->fullIData(oldp+40,(0x25U),32);
        tracep->fullIData(oldp+41,(0x26U),32);
        tracep->fullIData(oldp+42,(0x27U),32);
        tracep->fullIData(oldp+43,(0x28U),32);
        tracep->fullIData(oldp+44,(0x29U),32);
        tracep->fullIData(oldp+45,(0x2aU),32);
        tracep->fullIData(oldp+46,(0x2bU),32);
        tracep->fullIData(oldp+47,(0x2cU),32);
        tracep->fullIData(oldp+48,(0x2dU),32);
        tracep->fullIData(oldp+49,(0x2eU),32);
        tracep->fullIData(oldp+50,(0x2fU),32);
        tracep->fullIData(oldp+51,(0x30U),32);
        tracep->fullIData(oldp+52,(0x31U),32);
        tracep->fullIData(oldp+53,(0x32U),32);
        tracep->fullIData(oldp+54,(0x33U),32);
        tracep->fullIData(oldp+55,(0x34U),32);
        tracep->fullIData(oldp+56,(0x35U),32);
        tracep->fullIData(oldp+57,(0x36U),32);
        tracep->fullIData(oldp+58,(0x37U),32);
        tracep->fullIData(oldp+59,(0x38U),32);
        tracep->fullIData(oldp+60,(0x39U),32);
        tracep->fullIData(oldp+61,(0x3aU),32);
        tracep->fullIData(oldp+62,(0x3bU),32);
        tracep->fullIData(oldp+63,(0x3cU),32);
        tracep->fullIData(oldp+64,(0x3dU),32);
        tracep->fullIData(oldp+65,(0x3eU),32);
        tracep->fullIData(oldp+66,(0x3fU),32);
        tracep->fullIData(oldp+67,(0x40U),32);
        tracep->fullIData(oldp+68,(0x41U),32);
        tracep->fullIData(oldp+69,(0x42U),32);
        tracep->fullIData(oldp+70,(0x43U),32);
        tracep->fullIData(oldp+71,(0x44U),32);
        tracep->fullIData(oldp+72,(0x45U),32);
        tracep->fullIData(oldp+73,(0x46U),32);
        tracep->fullIData(oldp+74,(0x47U),32);
        tracep->fullIData(oldp+75,(0x48U),32);
        tracep->fullIData(oldp+76,(0x49U),32);
        tracep->fullIData(oldp+77,(0x4aU),32);
        tracep->fullIData(oldp+78,(0x4bU),32);
        tracep->fullIData(oldp+79,(0x4cU),32);
        tracep->fullIData(oldp+80,(0x4dU),32);
        tracep->fullIData(oldp+81,(0x4eU),32);
        tracep->fullIData(oldp+82,(0x4fU),32);
        tracep->fullIData(oldp+83,(0x50U),32);
        tracep->fullIData(oldp+84,(0x51U),32);
        tracep->fullIData(oldp+85,(0x52U),32);
        tracep->fullIData(oldp+86,(0x53U),32);
        tracep->fullIData(oldp+87,(0x54U),32);
        tracep->fullIData(oldp+88,(0x55U),32);
        tracep->fullIData(oldp+89,(0x56U),32);
        tracep->fullIData(oldp+90,(0x57U),32);
        tracep->fullIData(oldp+91,(0x58U),32);
        tracep->fullIData(oldp+92,(0x59U),32);
        tracep->fullIData(oldp+93,(0x5aU),32);
        tracep->fullIData(oldp+94,(0x5bU),32);
        tracep->fullIData(oldp+95,(0x5cU),32);
        tracep->fullIData(oldp+96,(0x5dU),32);
        tracep->fullIData(oldp+97,(0x5eU),32);
        tracep->fullIData(oldp+98,(0x5fU),32);
        tracep->fullIData(oldp+99,(0x60U),32);
        tracep->fullIData(oldp+100,(0x61U),32);
        tracep->fullIData(oldp+101,(0x62U),32);
        tracep->fullIData(oldp+102,(0x63U),32);
        tracep->fullIData(oldp+103,(0x64U),32);
        tracep->fullIData(oldp+104,(0x65U),32);
        tracep->fullIData(oldp+105,(0x66U),32);
        tracep->fullIData(oldp+106,(0x67U),32);
        tracep->fullIData(oldp+107,(0x68U),32);
        tracep->fullIData(oldp+108,(0x69U),32);
        tracep->fullIData(oldp+109,(0x6aU),32);
        tracep->fullIData(oldp+110,(0x6bU),32);
        tracep->fullIData(oldp+111,(0x6cU),32);
        tracep->fullIData(oldp+112,(0x6dU),32);
        tracep->fullIData(oldp+113,(0x6eU),32);
        tracep->fullIData(oldp+114,(0x6fU),32);
        tracep->fullIData(oldp+115,(0x70U),32);
        tracep->fullIData(oldp+116,(0x71U),32);
        tracep->fullIData(oldp+117,(0x72U),32);
        tracep->fullIData(oldp+118,(0x73U),32);
        tracep->fullIData(oldp+119,(0x74U),32);
        tracep->fullIData(oldp+120,(0x75U),32);
        tracep->fullIData(oldp+121,(0x76U),32);
        tracep->fullIData(oldp+122,(0x77U),32);
        tracep->fullIData(oldp+123,(0x78U),32);
        tracep->fullIData(oldp+124,(0x79U),32);
        tracep->fullIData(oldp+125,(0x7aU),32);
        tracep->fullIData(oldp+126,(0x7bU),32);
        tracep->fullIData(oldp+127,(0x7cU),32);
        tracep->fullIData(oldp+128,(0x7dU),32);
        tracep->fullIData(oldp+129,(0x7eU),32);
        tracep->fullIData(oldp+130,(0x7fU),32);
    }
}
