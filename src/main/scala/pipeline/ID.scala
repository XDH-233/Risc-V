package pipeline


import javafx.scene.control.RadioMenuItem
import spinal.core._
import spinal.sim._
import spinal.core.sim._
import spinal.lib._


case class control() extends Component {
    val io = new Bundle {
        val inst = in Bits (32 bits)

        val Branch   = out Bool()
        val J        = out Bool()
        val JR       = out Bool()
        val regWrite = out Bool()
        val memtoReg = out Bool()
        val memWrite = out Bool()
        val memRead  = out Bool()
        val ALUop    = out Bits (4 bits)
        val loadType = out Bits (3 bits)
        val ALUsrc   = out Bool()
    }
    noIoPrefix()
    val JUMP = new Area {
        when(io.inst === Riscv.JAL) {
            io.J := True
        } otherwise {
            io.J := False
        }

        when(io.inst === Riscv.JALR) {
            io.JR := True
        } otherwise {
            io.JR := False
        }
    }.setName("")

    val BRANCH = new Area {
        when(Riscv.isBType(io.inst(Riscv.opcode))) {
            io.Branch := True
        } otherwise {
            io.Branch := False
        }
    }.setName("")

    val REG_WRITE = new Area {
        when(Riscv.isRType(io.inst(Riscv.opcode)) ||
          Riscv.isIType(io.inst(Riscv.opcode)) ||
          Riscv.isUType(io.inst(Riscv.opcode)) ||
          Riscv.isJType(io.inst(Riscv.opcode))) {
            io.regWrite := True
        } otherwise {
            io.regWrite := False
        }
    }.setName("")

    val MEM_TO_REG = new Area {
        when(Riscv.isLoadInstOpcode(io.inst(Riscv.opcode))) {
            io.memtoReg := True
        } otherwise {
            io.memtoReg := False
        }
    }.setName("")

    val MEM_WRITE = new Area {
        when(Riscv.isSType(io.inst(Riscv.opcode))) {
            io.memWrite := True
        } otherwise {
            io.memWrite := False
        }
    }.setName("")

    val MEM_READ = new Area {
        when(Riscv.isLoadInstOpcode(io.inst(Riscv.opcode))) {
            io.memRead := True
        } otherwise {
            io.memRead := False
        }
    }.setName("")

    val ALU_OP = new Area {
        io.ALUop := B(Riscv.ALU_NOP)
        when(io.inst === Riscv.ADD ||
          io.inst === Riscv.ADDI ||
          io.inst === Riscv.ADDW ||
          io.inst === Riscv.ADDIW) {
            io.ALUop := B(Riscv.ALU_ADD)
        }

        when(Riscv.isLoadInstOpcode(io.inst(Riscv.opcode)) ||
          Riscv.isSType(io.inst(Riscv.opcode)) ||
          io.inst === Riscv.AUIPC
        ) {
            io.ALUop := B(Riscv.ALU_RAM)
        }

        when(io.inst === Riscv.SUB ||
          io.inst === Riscv.SUBW
        ) {
            io.ALUop := B(Riscv.ALU_SUB)
        }

        when(io.inst === Riscv.SLT ||
          io.inst === Riscv.SLTI
        ) {
            io.ALUop := B(Riscv.ALU_SLT)
        }

        when(io.inst === Riscv.SLTIU) {
            io.ALUop := B(Riscv.ALU_SLTU)
        }

        when(io.inst === Riscv.SLL ||
          io.inst === Riscv.SLLI ||
          io.inst === Riscv.SLLW ||
          io.inst === Riscv.SLLIW
        ) {
            io.ALUop := B(Riscv.ALU_SLL)
        }

        when(io.inst === Riscv.SRL ||
          io.inst === Riscv.SRLI ||
          io.inst === Riscv.SRLW ||
          io.inst === Riscv.SRLIW
        ) {
            io.ALUop := B(Riscv.ALU_SRL)
        }

        when(io.inst === Riscv.SRA ||
          io.inst === Riscv.SRAI ||
          io.inst === Riscv.SRAW ||
          io.inst === Riscv.SRAIW
        ) {
            io.ALUop := B(Riscv.ALU_SRA)
        }

        when(io.inst === Riscv.XOR || io.inst === Riscv.XORI) {
            io.ALUop := B(Riscv.ALU_XOR)
        }

        when(io.inst === Riscv.OR || io.inst === Riscv.ORI) {
            io.ALUop := B(Riscv.ALU_OR)
        }

        when(io.inst === Riscv.AND || io.inst === Riscv.ANDI) {
            io.ALUop === B(Riscv.ALU_AND)
        }
    }.setName("")

    val LOAD_TYPE = new Area {
        io.loadType := Riscv.loadDefault
        when(io.inst === Riscv.LB) {
            io.loadType := B(Riscv.loadByte)
        }
        when(io.inst === Riscv.LBU) {
            io.loadType := B(Riscv.loadByteU)
        }
        when(io.inst === Riscv.LH) {
            io.loadType := B(Riscv.loadHalfWord)
        }

        when(io.inst === Riscv.LHU) {
            io.loadType := B(Riscv.loadHalfWordU)
        }

        when(io.inst === Riscv.LW) {
            io.loadType := B(Riscv.loadWord)
        }

        when(io.inst === Riscv.LWU) {
            io.loadType := B(Riscv.loadWordU)
        }
    }.setName("")

    val ALUsrc = new Area {
        when(Riscv.isIType(io.inst(Riscv.opcode)) ||
          Riscv.isSType(io.inst(Riscv.opcode))
        ) {
            io.ALUsrc := True
        } otherwise {
            io.ALUsrc := False
        }
    }.setName("")
}

case class branchPredict() extends Component {
    val io = new Bundle {
        val funct3     = in Bits (3 bits)
        val readData1  = in Bits (globalConfig.operandWidth bits)
        val readData2  = in Bits (globalConfig.operandWidth bits)
        val ctrlBranch = in Bool()
        val flush      = out Bool()
        val branch     = out Bool()
    }
    noIoPrefix()
    io.flush := False
    io.branch := False
    when(io.ctrlBranch) {
        when(io.funct3 === Riscv.BEQ_funct3) {
            when(io.readData1.asSInt === io.readData2.asSInt) {
                io.flush := True
            } otherwise {
                io.flush := False
            }
        }
        when(io.funct3 === Riscv.BNE_funct3) {
            when(io.readData1.asSInt =/= io.readData2.asSInt) {
                io.flush := True
            } otherwise {
                io.flush := False
            }
        }
        when(io.funct3 === Riscv.BLT_funct3) {
            when(io.readData1.asSInt < io.readData2.asSInt) {
                io.flush := True
            } otherwise {
                io.flush := False
            }
        }
        when(io.funct3 === Riscv.BGE_funct3) {
            when(io.readData1.asSInt >= io.readData2.asSInt) {
                io.flush := True
            } otherwise {
                io.flush := False
            }
        }
        when(io.funct3 === Riscv.BLTU_funct3) {
            when(io.readData1.asUInt < io.readData2.asUInt) {
                io.flush := True
            } otherwise {
                io.flush := False
            }
        }
        when(io.funct3 === Riscv.BGEU_funct3) {
            when(io.readData1.asUInt >= io.readData2.asUInt) {
                io.flush := True
            } otherwise {
                io.flush := False
            }
        }

    }
}


case class hazardDet() extends Component {
    val io = new Bundle {
        val id2exMemRead = in Bool()
        val if2idRs1     = in UInt (5 bits)
        val id2exRd      = in UInt (5 bits)
        val if2idRs2     = in UInt (5 bits)

        val id2exRegWrite = in Bool()

        val ex2memRegWrite = in Bool()
        val ex2memRd       = in UInt (5 bits)

        val branch = in Bool()

        val stall = out Bool()
    }
    noIoPrefix()
    io.stall := False
    when(io.id2exMemRead &&
      io.id2exRd =/= 0  &&
      (io.id2exRd === io.if2idRs1 || io.id2exRd === io.if2idRs2)) {
        io.stall := True
    }


    // stall for branch in EX
    when(io.id2exRegWrite &&
      io.id2exRd =/= 0 &&
      ((io.id2exRd === io.if2idRs1 || io.id2exRd === io.if2idRs2) && io.branch)
    ) {
        io.stall := True
    }
    // stall for branch in MEM
    when(io.ex2memRegWrite &&
      io.ex2memRd =/= 0 &&
      (((io.if2idRs1 === io.ex2memRd) || (io.if2idRs2 === io.ex2memRd)) && io.branch)
    ) {
        io.stall := True
    }
}

case class registerFile(width: Int = 64) extends Component {
    val io = new Bundle {
        val readReg1, readReg2, writeReg = in UInt (5 bits)
        val writeData                    = in Bits(width bits)
        val readData1, readData2         = out Bits(width bits)
        val RegWrite                     = in Bool()
    }
    noIoPrefix()
    val regs = Vec(Reg(Bits(width bits)) init (0), 32)
    when(io.RegWrite) {
        regs.access(io.writeReg) := io.writeData
    }

    when(io.RegWrite && io.writeReg === io.readReg1){
        io.readData1 := io.writeData
    }otherwise{
        io.readData1 := regs.read(io.readReg1)
    }
    when(io.RegWrite && io.writeReg === io.readReg2){
        io.readData2 := io.writeData
    }otherwise{
        io.readData2 := regs.read(io.readReg2)
    }
}


case class immGen(inWidth: Int = 32, outWidth: Int = 64) extends Component {
    val io = new Bundle {
        val inst      = in Bits (inWidth bits)
        val immGenOut = out Bits (outWidth bits)
    }
    noIoPrefix()
    io.immGenOut := 0
    // I type
    when(Riscv.isIType(io.inst(Riscv.opcode))) {
        io.immGenOut := Riscv.IMM(io.inst).i_sext
    }
    // S type
    when(Riscv.isSType(io.inst(Riscv.opcode))) {
        io.immGenOut := Riscv.IMM(io.inst).s_sext
    }
    // B type
    when(Riscv.isBType(io.inst(Riscv.opcode))) {
        io.immGenOut := Riscv.IMM(io.inst).b_sext
    }
    // J type
    when(Riscv.isJType(io.inst(Riscv.opcode))) {
        io.immGenOut := Riscv.IMM(io.inst).j_sext
    }

    when(Riscv.isUType(io.inst(Riscv.opcode))) {
        io.immGenOut := Riscv.IMM(io.inst).u
    }
}

