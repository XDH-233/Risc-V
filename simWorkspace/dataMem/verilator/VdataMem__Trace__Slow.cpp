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
        tracep->declBus(c+8,"dataMem content_0", false,-1, 15,0);
        tracep->declBus(c+9,"dataMem content_1", false,-1, 15,0);
        tracep->declBus(c+10,"dataMem content_2", false,-1, 15,0);
        tracep->declBus(c+11,"dataMem content_3", false,-1, 15,0);
        tracep->declBus(c+12,"dataMem content_4", false,-1, 15,0);
        tracep->declBus(c+13,"dataMem content_5", false,-1, 15,0);
        tracep->declBus(c+14,"dataMem content_6", false,-1, 15,0);
        tracep->declBus(c+15,"dataMem content_7", false,-1, 15,0);
        tracep->declBus(c+16,"dataMem content_8", false,-1, 15,0);
        tracep->declBus(c+17,"dataMem content_9", false,-1, 15,0);
        tracep->declBus(c+18,"dataMem content_10", false,-1, 15,0);
        tracep->declBus(c+19,"dataMem content_11", false,-1, 15,0);
        tracep->declBus(c+20,"dataMem content_12", false,-1, 15,0);
        tracep->declBus(c+21,"dataMem content_13", false,-1, 15,0);
        tracep->declBus(c+22,"dataMem content_14", false,-1, 15,0);
        tracep->declBus(c+23,"dataMem content_15", false,-1, 15,0);
        tracep->declBus(c+24,"dataMem content_16", false,-1, 15,0);
        tracep->declBus(c+25,"dataMem content_17", false,-1, 15,0);
        tracep->declBus(c+26,"dataMem content_18", false,-1, 15,0);
        tracep->declBus(c+27,"dataMem content_19", false,-1, 15,0);
        tracep->declBus(c+28,"dataMem content_20", false,-1, 15,0);
        tracep->declBus(c+29,"dataMem content_21", false,-1, 15,0);
        tracep->declBus(c+30,"dataMem content_22", false,-1, 15,0);
        tracep->declBus(c+31,"dataMem content_23", false,-1, 15,0);
        tracep->declBus(c+32,"dataMem content_24", false,-1, 15,0);
        tracep->declBus(c+33,"dataMem content_25", false,-1, 15,0);
        tracep->declBus(c+34,"dataMem content_26", false,-1, 15,0);
        tracep->declBus(c+35,"dataMem content_27", false,-1, 15,0);
        tracep->declBus(c+36,"dataMem content_28", false,-1, 15,0);
        tracep->declBus(c+37,"dataMem content_29", false,-1, 15,0);
        tracep->declBus(c+38,"dataMem content_30", false,-1, 15,0);
        tracep->declBus(c+39,"dataMem content_31", false,-1, 15,0);
        tracep->declBus(c+40,"dataMem content_32", false,-1, 15,0);
        tracep->declBus(c+41,"dataMem content_33", false,-1, 15,0);
        tracep->declBus(c+42,"dataMem content_34", false,-1, 15,0);
        tracep->declBus(c+43,"dataMem content_35", false,-1, 15,0);
        tracep->declBus(c+44,"dataMem content_36", false,-1, 15,0);
        tracep->declBus(c+45,"dataMem content_37", false,-1, 15,0);
        tracep->declBus(c+46,"dataMem content_38", false,-1, 15,0);
        tracep->declBus(c+47,"dataMem content_39", false,-1, 15,0);
        tracep->declBus(c+48,"dataMem content_40", false,-1, 15,0);
        tracep->declBus(c+49,"dataMem content_41", false,-1, 15,0);
        tracep->declBus(c+50,"dataMem content_42", false,-1, 15,0);
        tracep->declBus(c+51,"dataMem content_43", false,-1, 15,0);
        tracep->declBus(c+52,"dataMem content_44", false,-1, 15,0);
        tracep->declBus(c+53,"dataMem content_45", false,-1, 15,0);
        tracep->declBus(c+54,"dataMem content_46", false,-1, 15,0);
        tracep->declBus(c+55,"dataMem content_47", false,-1, 15,0);
        tracep->declBus(c+56,"dataMem content_48", false,-1, 15,0);
        tracep->declBus(c+57,"dataMem content_49", false,-1, 15,0);
        tracep->declBus(c+58,"dataMem content_50", false,-1, 15,0);
        tracep->declBus(c+59,"dataMem content_51", false,-1, 15,0);
        tracep->declBus(c+60,"dataMem content_52", false,-1, 15,0);
        tracep->declBus(c+61,"dataMem content_53", false,-1, 15,0);
        tracep->declBus(c+62,"dataMem content_54", false,-1, 15,0);
        tracep->declBus(c+63,"dataMem content_55", false,-1, 15,0);
        tracep->declBus(c+64,"dataMem content_56", false,-1, 15,0);
        tracep->declBus(c+65,"dataMem content_57", false,-1, 15,0);
        tracep->declBus(c+66,"dataMem content_58", false,-1, 15,0);
        tracep->declBus(c+67,"dataMem content_59", false,-1, 15,0);
        tracep->declBus(c+68,"dataMem content_60", false,-1, 15,0);
        tracep->declBus(c+69,"dataMem content_61", false,-1, 15,0);
        tracep->declBus(c+70,"dataMem content_62", false,-1, 15,0);
        tracep->declBus(c+71,"dataMem content_63", false,-1, 15,0);
        tracep->declBus(c+72,"dataMem content_64", false,-1, 15,0);
        tracep->declBus(c+73,"dataMem content_65", false,-1, 15,0);
        tracep->declBus(c+74,"dataMem content_66", false,-1, 15,0);
        tracep->declBus(c+75,"dataMem content_67", false,-1, 15,0);
        tracep->declBus(c+76,"dataMem content_68", false,-1, 15,0);
        tracep->declBus(c+77,"dataMem content_69", false,-1, 15,0);
        tracep->declBus(c+78,"dataMem content_70", false,-1, 15,0);
        tracep->declBus(c+79,"dataMem content_71", false,-1, 15,0);
        tracep->declBus(c+80,"dataMem content_72", false,-1, 15,0);
        tracep->declBus(c+81,"dataMem content_73", false,-1, 15,0);
        tracep->declBus(c+82,"dataMem content_74", false,-1, 15,0);
        tracep->declBus(c+83,"dataMem content_75", false,-1, 15,0);
        tracep->declBus(c+84,"dataMem content_76", false,-1, 15,0);
        tracep->declBus(c+85,"dataMem content_77", false,-1, 15,0);
        tracep->declBus(c+86,"dataMem content_78", false,-1, 15,0);
        tracep->declBus(c+87,"dataMem content_79", false,-1, 15,0);
        tracep->declBus(c+88,"dataMem content_80", false,-1, 15,0);
        tracep->declBus(c+89,"dataMem content_81", false,-1, 15,0);
        tracep->declBus(c+90,"dataMem content_82", false,-1, 15,0);
        tracep->declBus(c+91,"dataMem content_83", false,-1, 15,0);
        tracep->declBus(c+92,"dataMem content_84", false,-1, 15,0);
        tracep->declBus(c+93,"dataMem content_85", false,-1, 15,0);
        tracep->declBus(c+94,"dataMem content_86", false,-1, 15,0);
        tracep->declBus(c+95,"dataMem content_87", false,-1, 15,0);
        tracep->declBus(c+96,"dataMem content_88", false,-1, 15,0);
        tracep->declBus(c+97,"dataMem content_89", false,-1, 15,0);
        tracep->declBus(c+98,"dataMem content_90", false,-1, 15,0);
        tracep->declBus(c+99,"dataMem content_91", false,-1, 15,0);
        tracep->declBus(c+100,"dataMem content_92", false,-1, 15,0);
        tracep->declBus(c+101,"dataMem content_93", false,-1, 15,0);
        tracep->declBus(c+102,"dataMem content_94", false,-1, 15,0);
        tracep->declBus(c+103,"dataMem content_95", false,-1, 15,0);
        tracep->declBus(c+104,"dataMem content_96", false,-1, 15,0);
        tracep->declBus(c+105,"dataMem content_97", false,-1, 15,0);
        tracep->declBus(c+106,"dataMem content_98", false,-1, 15,0);
        tracep->declBus(c+107,"dataMem content_99", false,-1, 15,0);
        tracep->declBus(c+108,"dataMem content_100", false,-1, 15,0);
        tracep->declBus(c+109,"dataMem content_101", false,-1, 15,0);
        tracep->declBus(c+110,"dataMem content_102", false,-1, 15,0);
        tracep->declBus(c+111,"dataMem content_103", false,-1, 15,0);
        tracep->declBus(c+112,"dataMem content_104", false,-1, 15,0);
        tracep->declBus(c+113,"dataMem content_105", false,-1, 15,0);
        tracep->declBus(c+114,"dataMem content_106", false,-1, 15,0);
        tracep->declBus(c+115,"dataMem content_107", false,-1, 15,0);
        tracep->declBus(c+116,"dataMem content_108", false,-1, 15,0);
        tracep->declBus(c+117,"dataMem content_109", false,-1, 15,0);
        tracep->declBus(c+118,"dataMem content_110", false,-1, 15,0);
        tracep->declBus(c+119,"dataMem content_111", false,-1, 15,0);
        tracep->declBus(c+120,"dataMem content_112", false,-1, 15,0);
        tracep->declBus(c+121,"dataMem content_113", false,-1, 15,0);
        tracep->declBus(c+122,"dataMem content_114", false,-1, 15,0);
        tracep->declBus(c+123,"dataMem content_115", false,-1, 15,0);
        tracep->declBus(c+124,"dataMem content_116", false,-1, 15,0);
        tracep->declBus(c+125,"dataMem content_117", false,-1, 15,0);
        tracep->declBus(c+126,"dataMem content_118", false,-1, 15,0);
        tracep->declBus(c+127,"dataMem content_119", false,-1, 15,0);
        tracep->declBus(c+128,"dataMem content_120", false,-1, 15,0);
        tracep->declBus(c+129,"dataMem content_121", false,-1, 15,0);
        tracep->declBus(c+130,"dataMem content_122", false,-1, 15,0);
        tracep->declBus(c+131,"dataMem content_123", false,-1, 15,0);
        tracep->declBus(c+132,"dataMem content_124", false,-1, 15,0);
        tracep->declBus(c+133,"dataMem content_125", false,-1, 15,0);
        tracep->declBus(c+134,"dataMem content_126", false,-1, 15,0);
        tracep->declBus(c+135,"dataMem content_127", false,-1, 15,0);
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
        tracep->fullSData(oldp+8,(0U),16);
        tracep->fullSData(oldp+9,(1U),16);
        tracep->fullSData(oldp+10,(2U),16);
        tracep->fullSData(oldp+11,(3U),16);
        tracep->fullSData(oldp+12,(4U),16);
        tracep->fullSData(oldp+13,(5U),16);
        tracep->fullSData(oldp+14,(6U),16);
        tracep->fullSData(oldp+15,(7U),16);
        tracep->fullSData(oldp+16,(8U),16);
        tracep->fullSData(oldp+17,(9U),16);
        tracep->fullSData(oldp+18,(0xaU),16);
        tracep->fullSData(oldp+19,(0xbU),16);
        tracep->fullSData(oldp+20,(0xcU),16);
        tracep->fullSData(oldp+21,(0xdU),16);
        tracep->fullSData(oldp+22,(0xeU),16);
        tracep->fullSData(oldp+23,(0xfU),16);
        tracep->fullSData(oldp+24,(0x10U),16);
        tracep->fullSData(oldp+25,(0x11U),16);
        tracep->fullSData(oldp+26,(0x12U),16);
        tracep->fullSData(oldp+27,(0x13U),16);
        tracep->fullSData(oldp+28,(0x14U),16);
        tracep->fullSData(oldp+29,(0x15U),16);
        tracep->fullSData(oldp+30,(0x16U),16);
        tracep->fullSData(oldp+31,(0x17U),16);
        tracep->fullSData(oldp+32,(0x18U),16);
        tracep->fullSData(oldp+33,(0x19U),16);
        tracep->fullSData(oldp+34,(0x1aU),16);
        tracep->fullSData(oldp+35,(0x1bU),16);
        tracep->fullSData(oldp+36,(0x1cU),16);
        tracep->fullSData(oldp+37,(0x1dU),16);
        tracep->fullSData(oldp+38,(0x1eU),16);
        tracep->fullSData(oldp+39,(0x1fU),16);
        tracep->fullSData(oldp+40,(0x20U),16);
        tracep->fullSData(oldp+41,(0x21U),16);
        tracep->fullSData(oldp+42,(0x22U),16);
        tracep->fullSData(oldp+43,(0x23U),16);
        tracep->fullSData(oldp+44,(0x24U),16);
        tracep->fullSData(oldp+45,(0x25U),16);
        tracep->fullSData(oldp+46,(0x26U),16);
        tracep->fullSData(oldp+47,(0x27U),16);
        tracep->fullSData(oldp+48,(0x28U),16);
        tracep->fullSData(oldp+49,(0x29U),16);
        tracep->fullSData(oldp+50,(0x2aU),16);
        tracep->fullSData(oldp+51,(0x2bU),16);
        tracep->fullSData(oldp+52,(0x2cU),16);
        tracep->fullSData(oldp+53,(0x2dU),16);
        tracep->fullSData(oldp+54,(0x2eU),16);
        tracep->fullSData(oldp+55,(0x2fU),16);
        tracep->fullSData(oldp+56,(0x30U),16);
        tracep->fullSData(oldp+57,(0x31U),16);
        tracep->fullSData(oldp+58,(0x32U),16);
        tracep->fullSData(oldp+59,(0x33U),16);
        tracep->fullSData(oldp+60,(0x34U),16);
        tracep->fullSData(oldp+61,(0x35U),16);
        tracep->fullSData(oldp+62,(0x36U),16);
        tracep->fullSData(oldp+63,(0x37U),16);
        tracep->fullSData(oldp+64,(0x38U),16);
        tracep->fullSData(oldp+65,(0x39U),16);
        tracep->fullSData(oldp+66,(0x3aU),16);
        tracep->fullSData(oldp+67,(0x3bU),16);
        tracep->fullSData(oldp+68,(0x3cU),16);
        tracep->fullSData(oldp+69,(0x3dU),16);
        tracep->fullSData(oldp+70,(0x3eU),16);
        tracep->fullSData(oldp+71,(0x3fU),16);
        tracep->fullSData(oldp+72,(0x40U),16);
        tracep->fullSData(oldp+73,(0x41U),16);
        tracep->fullSData(oldp+74,(0x42U),16);
        tracep->fullSData(oldp+75,(0x43U),16);
        tracep->fullSData(oldp+76,(0x44U),16);
        tracep->fullSData(oldp+77,(0x45U),16);
        tracep->fullSData(oldp+78,(0x46U),16);
        tracep->fullSData(oldp+79,(0x47U),16);
        tracep->fullSData(oldp+80,(0x48U),16);
        tracep->fullSData(oldp+81,(0x49U),16);
        tracep->fullSData(oldp+82,(0x4aU),16);
        tracep->fullSData(oldp+83,(0x4bU),16);
        tracep->fullSData(oldp+84,(0x4cU),16);
        tracep->fullSData(oldp+85,(0x4dU),16);
        tracep->fullSData(oldp+86,(0x4eU),16);
        tracep->fullSData(oldp+87,(0x4fU),16);
        tracep->fullSData(oldp+88,(0x50U),16);
        tracep->fullSData(oldp+89,(0x51U),16);
        tracep->fullSData(oldp+90,(0x52U),16);
        tracep->fullSData(oldp+91,(0x53U),16);
        tracep->fullSData(oldp+92,(0x54U),16);
        tracep->fullSData(oldp+93,(0x55U),16);
        tracep->fullSData(oldp+94,(0x56U),16);
        tracep->fullSData(oldp+95,(0x57U),16);
        tracep->fullSData(oldp+96,(0x58U),16);
        tracep->fullSData(oldp+97,(0x59U),16);
        tracep->fullSData(oldp+98,(0x5aU),16);
        tracep->fullSData(oldp+99,(0x5bU),16);
        tracep->fullSData(oldp+100,(0x5cU),16);
        tracep->fullSData(oldp+101,(0x5dU),16);
        tracep->fullSData(oldp+102,(0x5eU),16);
        tracep->fullSData(oldp+103,(0x5fU),16);
        tracep->fullSData(oldp+104,(0x60U),16);
        tracep->fullSData(oldp+105,(0x61U),16);
        tracep->fullSData(oldp+106,(0x62U),16);
        tracep->fullSData(oldp+107,(0x63U),16);
        tracep->fullSData(oldp+108,(0x64U),16);
        tracep->fullSData(oldp+109,(0x65U),16);
        tracep->fullSData(oldp+110,(0x66U),16);
        tracep->fullSData(oldp+111,(0x67U),16);
        tracep->fullSData(oldp+112,(0x68U),16);
        tracep->fullSData(oldp+113,(0x69U),16);
        tracep->fullSData(oldp+114,(0x6aU),16);
        tracep->fullSData(oldp+115,(0x6bU),16);
        tracep->fullSData(oldp+116,(0x6cU),16);
        tracep->fullSData(oldp+117,(0x6dU),16);
        tracep->fullSData(oldp+118,(0x6eU),16);
        tracep->fullSData(oldp+119,(0x6fU),16);
        tracep->fullSData(oldp+120,(0x70U),16);
        tracep->fullSData(oldp+121,(0x71U),16);
        tracep->fullSData(oldp+122,(0x72U),16);
        tracep->fullSData(oldp+123,(0x73U),16);
        tracep->fullSData(oldp+124,(0x74U),16);
        tracep->fullSData(oldp+125,(0x75U),16);
        tracep->fullSData(oldp+126,(0x76U),16);
        tracep->fullSData(oldp+127,(0x77U),16);
        tracep->fullSData(oldp+128,(0x78U),16);
        tracep->fullSData(oldp+129,(0x79U),16);
        tracep->fullSData(oldp+130,(0x7aU),16);
        tracep->fullSData(oldp+131,(0x7bU),16);
        tracep->fullSData(oldp+132,(0x7cU),16);
        tracep->fullSData(oldp+133,(0x7dU),16);
        tracep->fullSData(oldp+134,(0x7eU),16);
        tracep->fullSData(oldp+135,(0x7fU),16);
    }
}
