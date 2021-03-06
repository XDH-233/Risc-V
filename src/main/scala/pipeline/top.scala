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
    val dataNum      = 1024
}


case class top() extends Component {
    val PC                 = Reg(UInt(globalConfig.PCWidth bits)) init (0)
    val instructionMem     = instMem(width = globalConfig.instWidth, depth = globalConfig.instNum)
    val IF2ID              = new Stage(Stages.if2idB()).setDefinitionName("IF2ID")
    val Ctrl               = control()
    val RF                 = registerFile(globalConfig.operandWidth)
    val hazDet             = hazardDet()
    val BP                 = branchPredict()
    val ImmGen             = immGen()
    val ID2EX              = new Stage(Stages.id2exB()).setDefinitionName("ID2EX")
    val ALU                = alu(width = globalConfig.operandWidth)
    val ALUresTypeConv     = typeConv()
    val forwardBData       = Bits(globalConfig.operandWidth bits)
    val Forward            = forward()
    val EX2MEM             = new Stage(Stages.ex2memB()).setDefinitionName("EX2MEM")
    val dataMemInTypeConv  = typeConv()
    val DataMem            = dataMem(width = globalConfig.operandWidth, depth = globalConfig.dataNum)
    val dataMemOutTypeConv = typeConv()
    val MEM2WB             = new Stage(Stages.mem2wbB()).setDefinitionName("MEM2WB")
    val writeBack          = Bits(globalConfig.operandWidth bits)

    //-------------------------------------IF---------------------
    // PC
    val readData1PC = Bits(globalConfig.operandWidth bits)
    when(hazDet.io.stall) {
        PC := PC
    } elsewhen (BP.io.flush || Ctrl.io.J) {
        PC := ImmGen.io.immGenOut.asUInt.resize(PC.getWidth) + IF2ID.right.PC
    }elsewhen(Ctrl.io.JR){
        PC := (ImmGen.io.immGenOut.asUInt + readData1PC.asUInt).resize(globalConfig.PCWidth) //TODO negative?
    }otherwise {
        PC := PC + U(4, globalConfig.PCWidth bits)
    }

    // inst
    instructionMem.io.address := PC

    //********************************IF/ID***************************
    IF2ID.left.inst := instructionMem.io.instruction
    IF2ID.left.PC   := PC
    IF2ID.stall     := hazDet.io.stall
    IF2ID.flush     := BP.io.flush | Ctrl.io.J | (Ctrl.io.JR && !hazDet.io.stall)

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
        hazDet.io.JR             := Ctrl.io.JR
        hazDet.io.id2exMemRead   := ID2EX.right.memRead
        hazDet.io.if2idRs1       := IF2ID.right.inst(Riscv.rs1Range).asUInt
        hazDet.io.id2exRd        := ID2EX.right.rd
        hazDet.io.if2idRs2       := IF2ID.right.inst(Riscv.rs2Range).asUInt
        hazDet.io.id2exRegWrite  := ID2EX.right.regWrite
        hazDet.io.ex2memRegWrite := EX2MEM.right.regWrite
        hazDet.io.ex2memRd       := EX2MEM.right.rd
        hazDet.io.ex2memMemtoReg := ID2EX.right.memtoReg
    }

    // branch prediction and JALR readData1PC
    val BPInputConnect = {
        BP.io.ctrlBranch := Ctrl.io.Branch
        BP.io.funct3 := IF2ID.right.inst(Riscv.funct3Range)
        BP.io.stall := hazDet.io.stall
        switch(Forward.io.forwardBranchRs1) {
            is(B(Riscv.fromRF)) {
                BP.io.readData1 := RF.io.readData1.asBits
                readData1PC := RF.io.readData1
            }
            is(B(Riscv.fromEX2MEM)) {
                BP.io.readData1 := EX2MEM.right.ALUResult
                readData1PC := EX2MEM.right.ALUResult
            }
            is(B(Riscv.fromMEM2WB)) {
                BP.io.readData1 := writeBack
                readData1PC := writeBack
            }
            default {
                BP.io.readData1 := RF.io.readData1.asBits
                readData1PC := RF.io.readData1
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
    }

    // immGen
    ImmGen.io.inst := IF2ID.right.inst

    //*****************************************ID/EX*********************************************
    val ID2EXLeftConnect = {
        // stall
        ID2EX.left.regWrite := Mux(sel = hazDet.io.stall, whenTrue = False, whenFalse = Ctrl.io.regWrite)
        ID2EX.left.memtoReg := Mux(sel = hazDet.io.stall, whenTrue = False, whenFalse = Ctrl.io.memtoReg)
        ID2EX.left.memRead  := Mux(sel = hazDet.io.stall, whenTrue = False, whenFalse = Ctrl.io.memRead)
        ID2EX.left.memWrite := Mux(sel = hazDet.io.stall, whenTrue = False, whenFalse = Ctrl.io.memWrite)
        ID2EX.left.ALUop    := Mux(sel = hazDet.io.stall, whenTrue = B(15, 4 bits), whenFalse = Ctrl.io.ALUop)       // can't flush to 0
        ID2EX.left.ALUsrc   := Mux(sel = hazDet.io.stall, whenTrue = False, whenFalse = Ctrl.io.ALUsrc)

        ID2EX.left.readData1 := Mux(sel = hazDet.io.stall, whenTrue = B(0, globalConfig.operandWidth bits), whenFalse = RF.io.readData1.asBits)
        ID2EX.left.readData2 := Mux(sel = hazDet.io.stall, whenTrue = B(0, globalConfig.operandWidth bits), whenFalse = RF.io.readData2.asBits)
        ID2EX.left.immGenOut := Mux(sel = hazDet.io.stall, whenTrue = B(0, globalConfig.operandWidth bits), whenFalse = ImmGen.io.immGenOut)
        ID2EX.left.rs1       := Mux(sel = hazDet.io.stall, whenTrue = U(0,5 bits), whenFalse = IF2ID.right.inst(Riscv.rs1Range).asUInt)
        ID2EX.left.rs2       := Mux(sel = hazDet.io.stall, whenTrue = U(0, 5 bits), whenFalse = IF2ID.right.inst(Riscv.rs2Range).asUInt)
        ID2EX.left.rd        := Mux(sel = hazDet.io.stall, whenTrue = U(0, 5 bits), whenFalse = IF2ID.right.inst(Riscv.rdRange).asUInt)
        ID2EX.left.PC4       := Mux(sel = hazDet.io.stall, whenTrue = U(0, globalConfig.PCWidth bits), whenFalse = IF2ID.right.PC + U(4, globalConfig.PCWidth bits))
        ID2EX.left.J         := Mux(sel = hazDet.io.stall, whenTrue = False, whenFalse = Ctrl.io.J)
        ID2EX.left.JR        := Mux(sel = hazDet.io.stall, whenTrue = False, whenFalse = Ctrl.io.JR)
        ID2EX.left.lui       := Mux(sel = hazDet.io.stall, whenTrue = False, whenFalse = Ctrl.io.lui)
        ID2EX.left.auiPC     := Mux(sel = hazDet.io.stall, whenTrue = False, whenFalse = Ctrl.io.auiPC)
        ID2EX.left.PCimm     := Mux(sel = hazDet.io.stall, whenTrue = B(0, globalConfig.operandWidth bits), whenFalse = (IF2ID.right.PC.resize(globalConfig.operandWidth) + ImmGen.io.immGenOut.asUInt).asBits)
        ID2EX.left.loadType  := Mux(sel = hazDet.io.stall, whenTrue = B(Riscv.loadDefault), whenFalse = Ctrl.io.loadType)
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
    // ALUresTypeConv connect
    ALUresTypeConv.io.en := !(ID2EX.right.memRead || ID2EX.right.memWrite)
    ALUresTypeConv.io.loadType := ID2EX.right.loadType
    ALUresTypeConv.io.dataIn := ALU.io.res
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
        Forward.io.ctrlJR         := Ctrl.io.JR
        Forward.io.lui            := ID2EX.right.lui
        Forward.io.auiPC          := ID2EX.right.auiPC
    }
    //**************************************EX/MEM*****************************************
    val EX2MEMLeftConnect = {
        EX2MEM.left.regWrite         := ID2EX.right.regWrite
        EX2MEM.left.memtoReg         := ID2EX.right.memtoReg
        EX2MEM.left.memRead          := ID2EX.right.memRead
        EX2MEM.left.memWrite         := ID2EX.right.memWrite
        EX2MEM.left.regFileReadData2 := forwardBData
        EX2MEM.left.rs2              := ID2EX.right.rs2
        EX2MEM.left.rd               := ID2EX.right.rd
        EX2MEM.left.loadType         := ID2EX.right.loadType
        switch((ID2EX.right.J || ID2EX.right.JR) ## ID2EX.right.lui ## ID2EX.right.auiPC){
            is(B"100"){
                EX2MEM.left.ALUResult := ID2EX.right.PC4.resize(globalConfig.operandWidth bits).asBits
            }
            is(B"010"){
                EX2MEM.left.ALUResult := ID2EX.right.immGenOut
            }
            is(B("001")){
                EX2MEM.left.ALUResult := ID2EX.right.PCimm
            }
            default{
                EX2MEM.left.ALUResult := ALUresTypeConv.io.dataOut
            }
        }
        EX2MEM.stall.clear()
        EX2MEM.flush.clear()
    }

    //------------------------------------------MEM-----------------------------------------
    val dataMemForwardIn = Bits(globalConfig.operandWidth bits)
    dataMemForwardIn := Mux(sel = Forward.io.forwardC, whenTrue = writeBack, whenFalse = EX2MEM.right.regFileReadData2)
    dataMemInTypeConv.io.en := EX2MEM.right.memWrite
    dataMemInTypeConv.io.loadType := EX2MEM.right.loadType
    dataMemInTypeConv.io.dataIn := dataMemForwardIn
    // dataMem
    val DataMemInConnect = {
        DataMem.io.memRead   := EX2MEM.right.memRead
        DataMem.io.memWrite  := EX2MEM.right.memWrite
        DataMem.io.address   := EX2MEM.right.ALUResult.asUInt.resize(DataMem.io.address.getWidth)
        DataMem.io.writeData := dataMemInTypeConv.io.dataOut
    }
    dataMemOutTypeConv.io.en := EX2MEM.right.memRead
    dataMemOutTypeConv.io.loadType := EX2MEM.right.loadType
    dataMemOutTypeConv.io.dataIn := DataMem.io.readData

    //***************************************MEM/WB******************************************

    val MEM2WBLeftConnect = {
        MEM2WB.left.regWrite  := EX2MEM.right.regWrite
        MEM2WB.left.memtoReg  := EX2MEM.right.memtoReg
        MEM2WB.left.readData  := dataMemOutTypeConv.io.dataOut
        MEM2WB.left.ALUResult := EX2MEM.right.ALUResult
        MEM2WB.left.rd        := EX2MEM.right.rd
        MEM2WB.left.loadType := EX2MEM.right.loadType
        MEM2WB.stall.clear()
        MEM2WB.flush.clear()
    }
    //***************************************WB********************************************
    writeBack := Mux(sel = MEM2WB.right.memtoReg, whenTrue = MEM2WB.right.readData, whenFalse = MEM2WB.right.ALUResult)
}