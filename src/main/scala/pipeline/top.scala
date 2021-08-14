package pipeline

import spinal.core._
import spinal.sim._
import spinal.core.sim._
import spinal.lib._

object globalConfig {
    val operandWidth = 64
    val instWidth = 32
    val instNum      = 128
    val PCWidth = log2Up(instNum * (instWidth / 8) )
    val dataNum      = 128
}


case class top() extends Component {
    val PC             = Reg(UInt(globalConfig.PCWidth bits)) init (0)
    val instructionMem = instMem(width = globalConfig.instWidth, depth = globalConfig.instNum)
    val IF2ID          = new Stage(Stages.if2idB()).setDefinitionName("IF2ID")
    val Ctrl           = control()
    val RF             = registerFile(globalConfig.operandWidth)
    val hazDet         = hazardDet()
    val BP             = branchPredict()
    val ImmGen         = immGen()
    val ID2EX          = new Stage(Stages.id2exB()).setDefinitionName("ID2EX")
    val ALU            = alu(width = globalConfig.operandWidth)
    val forwardBData   = Bits(globalConfig.operandWidth bits)
    val Forward        = forward()
    val EX2MEM         = new Stage(Stages.ex2memB()).setDefinitionName("EX2MEM")
    val DataMem        = dataMem(width = globalConfig.operandWidth, depth = globalConfig.dataNum)
    val MEM2WB         = new Stage(Stages.mem2wbB()).setDefinitionName("MEM2WB")
    val writeBack      = Bits(globalConfig.operandWidth bits)

    //-------------------------------------IF---------------------
    // PC
    when(hazDet.io.stall) {
        PC := PC
    } elsewhen (BP.io.branch) {
        PC := ImmGen.io.immGenOut.asUInt.resize(PC.getWidth) + PC
    } otherwise {
        PC := PC + U(4, globalConfig.PCWidth bits)
    }
    // inst
    instructionMem.io.address := PC

    //********************************IF/ID***************************
    IF2ID.left.inst := instructionMem.io.instruction
    IF2ID.left.PC := PC
    IF2ID.stall := hazDet.io.stall
    IF2ID.flush := BP.io.flush

    //--------------------------------ID------------------------------
    // control
    Ctrl.io.inst := IF2ID.right.inst
    // register file
    val RFInConnect     = {
        RF.io.readReg1 := IF2ID.right.inst(Riscv.rs1Range).asUInt
        RF.io.readReg2 := IF2ID.right.inst(Riscv.rs2Range).asUInt
        RF.io.writeReg := MEM2WB.right.rd
        RF.io.RegWrite := MEM2WB.right.regWrite
        RF.io.writeData := writeBack
    }
    // hazard detect
    val hazDetInConnect = {
        hazDet.io.branch         := Ctrl.io.Branch
        hazDet.io.id2exMemRead   := ID2EX.right.memRead
        hazDet.io.if2idRs1       := IF2ID.right.inst(Riscv.rs1Range).asUInt
        hazDet.io.id2exRd        := ID2EX.right.rd
        hazDet.io.if2idRs2       := IF2ID.right.inst(Riscv.rs2Range).asUInt
        hazDet.io.id2exRegWrite  := ID2EX.right.regWrite
        hazDet.io.ex2memRegWrite := EX2MEM.right.regWrite
        hazDet.io.ex2memRd       := EX2MEM.right.rd
    }

    // branch prediction
    BP.io.ctrlBranch := Ctrl.io.Branch
    switch(Forward.io.forwardBranchRs1) {
        is(B(Riscv.fromRF)) {
            BP.io.readData1 := RF.io.readData1.asBits
        }
        is(B(Riscv.fromEX2MEM)) {
            BP.io.readData1 := EX2MEM.right.ALUResult
        }
        is(B(Riscv.fromMEM2WB)) {
            BP.io.readData1 := writeBack
        }
        default {
            BP.io.readData1 := RF.io.readData1.asBits
        }
    }
    switch(Forward.io.forwardBranchRs2) {
        is(B(Riscv.fromRF)) {
            BP.io.readData2 := RF.io.readData2.asBits
        }
        is(B(Riscv.fromEX2MEM)) {
            BP.io.readData2 := EX2MEM.right.ALUResult
        }
        is(B(Riscv.fromMEM2WB)) {
            BP.io.readData2 := writeBack
        }
        default {
            BP.io.readData2 := RF.io.readData2.asBits
        }
    }
    BP.io.funct3 := IF2ID.right.inst(Riscv.funct3Range)

    // immGen
    ImmGen.io.inst := IF2ID.right.inst

    //*****************************************ID/EX*********************************************
    val ID2EXLeftConnect = {
        // stall
        ID2EX.left.regWrite := Mux(sel = hazDet.io.stall, whenTrue = False, whenFalse = Ctrl.io.regWrite)
        ID2EX.left.memtoReg := Mux(sel = hazDet.io.stall, whenTrue = False, whenFalse = Ctrl.io.memtoReg)
        ID2EX.left.memRead  := Mux(sel = hazDet.io.stall, whenTrue = False, whenFalse = Ctrl.io.memRead)
        ID2EX.left.memWrite := Mux(sel = hazDet.io.stall, whenTrue = False, whenFalse = Ctrl.io.memWrite)
        ID2EX.left.ALUop    := Mux(sel = hazDet.io.stall, whenTrue = B(15, 4 bits), whenFalse = Ctrl.io.ALUop)
        ID2EX.left.ALUsrc   := Mux(sel = hazDet.io.stall, whenTrue = False, whenFalse = Ctrl.io.ALUsrc)

        ID2EX.left.readData1 := Mux(sel = hazDet.io.stall, whenTrue = B(0, globalConfig.operandWidth bits), whenFalse = RF.io.readData1.asBits)
        ID2EX.left.readData2 := Mux(sel = hazDet.io.stall, whenTrue = B(0, globalConfig.operandWidth bits), whenFalse = RF.io.readData2.asBits)
        ID2EX.left.immGenOut := Mux(sel = hazDet.io.stall, whenTrue = B(0, globalConfig.operandWidth bits), whenFalse = ImmGen.io.immGenOut)
        ID2EX.left.rs1       := Mux(sel = hazDet.io.stall, whenTrue = U(0,5 bits), whenFalse = IF2ID.right.inst(Riscv.rs1Range).asUInt)
        ID2EX.left.rs2       := Mux(sel = hazDet.io.stall, whenTrue = U(0, 5 bits), whenFalse = IF2ID.right.inst(Riscv.rs2Range).asUInt)
        ID2EX.left.rd        := Mux(sel = hazDet.io.stall, whenTrue = U(0, 5 bits), whenFalse = IF2ID.right.inst(Riscv.rdRange).asUInt)
        ID2EX.flush.clear()
        ID2EX.stall.clear()
    }





    //------------------------------------------EX----------------------------------------------
    // ALU
    val ALUInConnect = {
        ALU.io.ALUop := ID2EX.right.ALUop
        switch(Forward.io.forwardA) {
            is(B(Riscv.fromRF)) {
                ALU.io.data1 := ID2EX.right.readData1
            }
            is(B(Riscv.fromMEM2WB)) {
                ALU.io.data1 := writeBack
            }
            is(B(Riscv.fromEX2MEM)) {
                ALU.io.data1 := EX2MEM.right.ALUResult
            }
            default {
                ALU.io.data1 := ID2EX.right.readData1
            }
        }
        switch(Forward.io.forwardB) {
            is(B(Riscv.fromRF)) {
                forwardBData := ID2EX.right.readData2
            }
            is(B(Riscv.fromMEM2WB)) {
                forwardBData := writeBack
            }
            is(B(Riscv.fromEX2MEM)) {
                forwardBData := EX2MEM.right.ALUResult
            }
            default {
                forwardBData := ID2EX.right.readData2
            }
        }
        ALU.io.data2 := Mux(sel = ID2EX.right.ALUsrc, whenTrue = ID2EX.right.immGenOut, whenFalse = forwardBData)
    }

    // forward
    val ForwardInputConnect = {
        Forward.io.id2exRs1       := ID2EX.right.rs1
        Forward.io.id2exRs2       := ID2EX.right.rs2
        Forward.io.ex2memRd       := EX2MEM.right.rd
        Forward.io.mem2wbRd       := MEM2WB.right.rd
        Forward.io.ex2memRegWrite := EX2MEM.right.regWrite
        Forward.io.mem2wbRegWrite := MEM2WB.right.regWrite
        Forward.io.ex2memRs2      := EX2MEM.right.rs2
        Forward.io.ex2memMemWrite := EX2MEM.right.memWrite
        Forward.io.if2idRs1       := IF2ID.right.inst(Riscv.rs1Range).asUInt
        Forward.io.if2idRs2       := IF2ID.right.inst(Riscv.rs2Range).asUInt
        Forward.io.ctrlBranch     := Ctrl.io.Branch
        Forward.io.mem2wbMemtoReg := MEM2WB.right.memtoReg
        Forward.io.ex2memMemtoReg := EX2MEM.right.memtoReg
    }
    //**************************************EX/MEM*****************************************
    val EX2MEMLeftConnect = {
        EX2MEM.left.regWrite         := ID2EX.right.regWrite
        EX2MEM.left.memtoReg         := ID2EX.right.memtoReg
        EX2MEM.left.memRead          := ID2EX.right.memRead
        EX2MEM.left.memWrite         := ID2EX.right.memWrite
        EX2MEM.left.ALUResult        := ALU.io.res
        EX2MEM.left.regFileReadData2 := forwardBData
        EX2MEM.left.rs2              := ID2EX.right.rs2
        EX2MEM.left.rd               := ID2EX.right.rd
        EX2MEM.stall.clear()
        EX2MEM.flush.clear()
    }

    //------------------------------------------MEM-----------------------------------------
    // dataMem
    val DataMemInConnect = {
        DataMem.io.memRead   := EX2MEM.right.memRead
        DataMem.io.memWrite  := EX2MEM.right.memWrite
        DataMem.io.address   := EX2MEM.right.ALUResult.asUInt.resize(DataMem.io.address.getWidth)
        DataMem.io.writeData := Mux(sel = Forward.io.forwardC, whenTrue = MEM2WB.right.readData, whenFalse = EX2MEM.right.regFileReadData2)
    }

    //***************************************MEM/WB******************************************
    val MEM2WBLeftConnect = {
        MEM2WB.left.regWrite  := EX2MEM.right.regWrite
        MEM2WB.left.memtoReg  := EX2MEM.right.memtoReg
        MEM2WB.left.readData  := DataMem.io.readData
        MEM2WB.left.ALUResult := EX2MEM.right.ALUResult
        MEM2WB.left.rd        := EX2MEM.right.rd
        MEM2WB.stall.clear()
        MEM2WB.flush.clear()
    }
    //***************************************WB********************************************
    writeBack := Mux(sel = MEM2WB.right.memtoReg, whenTrue = MEM2WB.right.readData, whenFalse = MEM2WB.right.ALUResult)
}