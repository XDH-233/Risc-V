package pipeline


import spinal.core._
import spinal.sim._
import spinal.core.sim._
import spinal.lib._

case class forward() extends Component {
    val io = new Bundle {
        val id2exRs1       = in UInt (5 bits)
        val id2exRs2       = in UInt (5 bits)
        val ex2memRd       = in UInt (5 bits)
        val mem2wbRd       = in UInt (5 bits)
        val ex2memRegWrite = in Bool()
        val mem2wbRegWrite = in Bool()
        val ex2memRs2      = in UInt (5 bits)
        val ex2memMemWrite = in Bool()

        val if2idRs1       = in UInt (5 bits)
        val if2idRs2       = in UInt (5 bits)
        val ctrlBranch     = in Bool()
        val mem2wbMemtoReg = in Bool()
        val ex2memMemtoReg = in Bool()

        val forwardA         = out Bits (2 bits)
        val forwardB         = out Bits (2 bits)
        val forwardC         = out Bool()
        val forwardBranchRs1 = out Bits (2 bits)
        val forwardBranchRs2 = out Bits (2 bits)
    }
    noIoPrefix()
    // default
    io.forwardA := B(Riscv.fromID2EX)
    io.forwardB := B(Riscv.fromID2EX)
    // EX hazard
    val exHar    = new Area {
        when(io.ex2memRegWrite &&
          io.ex2memRd =/= 0 &&
          io.ex2memRd === io.id2exRs1
        ) {
            io.forwardA := B(Riscv.fromEX2MEM)
        }

        when(io.ex2memRegWrite &&
          io.ex2memRd =/= 0 &&
          io.ex2memRd === io.id2exRs2
        ) {
            io.forwardB := B(Riscv.fromEX2MEM)
        }
    }.setName("")
    // MEM hazard
    val memHar   = new Area {
        when(io.mem2wbRegWrite &&
          io.mem2wbRd =/= 0 &&
          !(io.ex2memRegWrite && io.ex2memRd =/= 0 && io.ex2memRd === io.id2exRs1) &&
          io.mem2wbRd === io.id2exRs1
        ) {
            io.forwardA := B(Riscv.fromMEM2WB)
        }

        when(io.mem2wbRegWrite &&
          io.mem2wbRd =/= 0 &&
          !(io.ex2memRegWrite && io.ex2memRd =/= 0 && io.ex2memRd === io.id2exRs2) &&
          io.mem2wbRd === io.id2exRs2
        ) {
            io.forwardB := B(Riscv.fromMEM2WB)
        }

    }.setName("")
    // load hazard
    val loaddHar = new Area {
        when(io.mem2wbRegWrite &&
          io.mem2wbRd =/= 0 &&
          io.ex2memMemWrite &&
          io.mem2wbRd === io.ex2memRs2
        ) {
            io.forwardC := True
        } otherwise {
            io.forwardC := False
        }
    }.setName("")

    // branch source hazard
    val branchHar = new Area {
        io.forwardBranchRs1 := B(Riscv.fromRF)
        io.forwardBranchRs2 := B(Riscv.fromRF)
        //----------------MEM-------------------------
        //rs1
        when(io.mem2wbRegWrite &&
          io.mem2wbRd =/= 0 &&
          io.mem2wbMemtoReg &&
          io.mem2wbRd === io.if2idRs1 &&
          io.ctrlBranch
        ) {
            io.forwardBranchRs1 := B(Riscv.fromMEM2WB)
        }
        // rs2
        when(io.mem2wbRegWrite &&
          io.mem2wbRd =/= 0 &&
          io.mem2wbMemtoReg &&
          io.mem2wbRd === io.if2idRs2 &&
          io.ctrlBranch
        ) {
            io.forwardBranchRs2 := B(Riscv.fromMEM2WB)
        }
        //----------------EX-------------------------
        // rs1
        when(io.ex2memRegWrite &&
          io.ex2memRd =/= 0 &&
          io.ex2memRd === io.if2idRs1 &&
          (!io.ex2memMemtoReg) &&
          io.ctrlBranch
        ) {
            io.forwardBranchRs1 := B(Riscv.fromEX2MEM)
        }
        // rs2
        when(io.ex2memRegWrite &&
          io.ex2memRd =/= 0 &&
          io.ex2memRd === io.if2idRs2 &&
          (!io.ex2memMemtoReg) &&
          io.ctrlBranch
        ) {
            io.forwardBranchRs2 := B(Riscv.fromEX2MEM)
        }

    }.setName("")

}

case class alu(width: Int) extends Component {
    val io = new Bundle {
        val ALUop = in Bits (4 bits)
        val data1 = in Bits (width bits)
        val data2 = in Bits (width bits)
        val zero  = out Bool()
        val res   = out Bits (width bits)
    }
    noIoPrefix()
    io.zero := (io.res === 0)
    switch(io.ALUop) {
        is(B(Riscv.ALU_RAM)) {
            io.res := (io.data1.asUInt + io.data2.asUInt).asBits
        }

        is(B(Riscv.ALU_ADD)) {
            io.res := (io.data1.asSInt + io.data2.asSInt).asBits
        }

        is(B(Riscv.ALU_SUB)) {
            io.res := (io.data1.asSInt - io.data2.asSInt).asBits
        }

        is(B(Riscv.ALU_SLT)) {
            when(io.data1.asSInt < io.data2.asSInt) {
                io.res := B(1)
            } otherwise {
                io.res := B(0)
            }
        }

        is(B(Riscv.ALU_SLTU)) {
            when(io.data1.asUInt < io.data2.asUInt) {
                io.res := B(1)
            } otherwise {
                io.res := B(0)
            }
        }

        is(B(Riscv.ALU_SLL)) {
            io.res := (io.data1.asUInt |<< io.data2.asUInt).asBits
        }

        is(B(Riscv.ALU_SRL)) {
            io.res := (io.data1.asUInt |>> io.data2.asUInt).asBits
        }

        is(B(Riscv.ALU_SRA)) {
            io.res := (io.data1.asSInt >> io.data2.asUInt).asBits
        }

        is(B(Riscv.ALU_XOR)) {
            io.res := io.data1 ^ io.data2
        }

        is(B(Riscv.ALU_OR)) {
            io.res := io.data1 | io.data2
        }

        is(B(Riscv.ALU_AND)) {
            io.res := io.data1 & io.data2
        }

        is(B(Riscv.ALU_NOP)) {
            io.res := B(0)
        }
        default {
            io.res := B(0)
        }
    }
}

