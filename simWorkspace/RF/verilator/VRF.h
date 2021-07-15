// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VRF_H_
#define _VRF_H_  // guard

#include "verilated.h"

//==========

class VRF__Syms;
class VRF_VerilatedVcd;


//----------

VL_MODULE(VRF) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(readReg1,4,0);
    VL_IN8(readReg2,4,0);
    VL_IN8(writeReg,4,0);
    VL_IN8(RegWrite,0,0);
    VL_IN8(reset,0,0);
    VL_IN16(writeData,15,0);
    VL_OUT16(readData1,15,0);
    VL_OUT16(readData2,15,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    SData/*15:0*/ RF__DOT___zz_2_;
    SData/*15:0*/ RF__DOT___zz_3_;
    SData/*15:0*/ RF__DOT__regs_0;
    SData/*15:0*/ RF__DOT__regs_1;
    SData/*15:0*/ RF__DOT__regs_2;
    SData/*15:0*/ RF__DOT__regs_3;
    SData/*15:0*/ RF__DOT__regs_4;
    SData/*15:0*/ RF__DOT__regs_5;
    SData/*15:0*/ RF__DOT__regs_6;
    SData/*15:0*/ RF__DOT__regs_7;
    SData/*15:0*/ RF__DOT__regs_8;
    SData/*15:0*/ RF__DOT__regs_9;
    SData/*15:0*/ RF__DOT__regs_10;
    SData/*15:0*/ RF__DOT__regs_11;
    SData/*15:0*/ RF__DOT__regs_12;
    SData/*15:0*/ RF__DOT__regs_13;
    SData/*15:0*/ RF__DOT__regs_14;
    SData/*15:0*/ RF__DOT__regs_15;
    SData/*15:0*/ RF__DOT__regs_16;
    SData/*15:0*/ RF__DOT__regs_17;
    SData/*15:0*/ RF__DOT__regs_18;
    SData/*15:0*/ RF__DOT__regs_19;
    SData/*15:0*/ RF__DOT__regs_20;
    SData/*15:0*/ RF__DOT__regs_21;
    SData/*15:0*/ RF__DOT__regs_22;
    SData/*15:0*/ RF__DOT__regs_23;
    SData/*15:0*/ RF__DOT__regs_24;
    SData/*15:0*/ RF__DOT__regs_25;
    SData/*15:0*/ RF__DOT__regs_26;
    SData/*15:0*/ RF__DOT__regs_27;
    SData/*15:0*/ RF__DOT__regs_28;
    SData/*15:0*/ RF__DOT__regs_29;
    SData/*15:0*/ RF__DOT__regs_30;
    SData/*15:0*/ RF__DOT__regs_31;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vm_traceActivity[2];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VRF__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VRF);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VRF(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VRF();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VRF__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VRF__Syms* symsp, bool first);
  private:
    static QData _change_request(VRF__Syms* __restrict vlSymsp);
    static QData _change_request_1(VRF__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VRF__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VRF__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VRF__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__2(VRF__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(VRF__Syms* __restrict vlSymsp);
    static void _settle__TOP__4(VRF__Syms* __restrict vlSymsp);
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
