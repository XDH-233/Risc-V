package pipeline


import javafx.scene.control.RadioMenuItem
import spinal.core._
import spinal.sim._
import spinal.core.sim._
import spinal.lib._


case class control() extends Component{
    val io = new Bundle{
        val inst = in Bits(32 bits)

        val Branch = out Bool()
        val J = out Bool()
        val JR = out Bool()
        val regWrite = out Bool()
        val memtoReg = out Bool()
        val memWrite = out Bool()
        val memRead = out Bool()
        val ALUop = out Bits(4 bits)
        val loadType = out Bits(3 bits)
        val ALUsrc = out Bool()
    }
    noIoPrefix()
    val JUMP = new Area {
        when(io.inst === Riscv.JAL){
            io.J := True
        }otherwise{
            io.J := False
        }

        when(io.inst === Riscv.JALR){
            io.JR := True
        }otherwise{
            io.JR := False
        }
    }.setName("")

    val BRANCH =new Area{
        when(Riscv.isBType(io.inst(Riscv.opcode))){
            io.Branch := True
        }otherwise{
            io.Branch := False
        }
    }.setName("")

    val REG_WRITE = new Area {
        when(Riscv.isRType(io.inst(Riscv.opcode)) ||
            Riscv.isIType(io.inst(Riscv.opcode)) ||
            Riscv.isUType(io.inst(Riscv.opcode)) ||
            Riscv.isJType(io.inst(Riscv.opcode))){
            io.regWrite := True
        }otherwise{
            io.regWrite := False
        }
    }.setName("")

    val MEM_TO_REG = new Area{
        when(Riscv.isLoadInstOpcode(io.inst(Riscv.opcode))){
            io.memtoReg := True
        }otherwise{
            io.memtoReg := False
        }
    }.setName("")

    val MEM_WRITE = new Area{
        when(Riscv.isSType(io.inst(Riscv.opcode))){
            io.memWrite := True
        }otherwise{
            io.memWrite := False
        }
    }    .setName("")

    val MEM_READ = new Area{
        when(Riscv.isLoadInstOpcode(io.inst(Riscv.opcode))){
            io.memRead := True
        }otherwise{
            io.memRead := True
        }
    }.setName("")

    val ALU_OP = new Area{
        io.ALUop := B(Riscv.ALU_NOP)
        when(io.inst === Riscv.ADD ||
            io.inst === Riscv.ADDI ||
            io.inst === Riscv.ADDW ||
            io.inst === Riscv.ADDIW){
                io.ALUop := B(Riscv.ALU_ADD)
        }

        when(Riscv.isLoadInstOpcode(io.inst(Riscv.opcode)) ||
            Riscv.isSType(io.inst(Riscv.opcode)) ||
            io.inst === Riscv.AUIPC
        ){
            io.ALUop := B(Riscv.ALU_RAM)
        }

        when(io.inst === Riscv.SUB ||
            io.inst === Riscv.SUBW
        ){
            io.ALUop := B(Riscv.ALU_SUB)
        }

        when(io.inst === Riscv.SLT ||
            io.inst === Riscv.SLTI
        ){
            io.ALUop := B(Riscv.ALU_SLT)
        }

        when(io.inst === Riscv.SLTIU){
            io.ALUop := B(Riscv.ALU_SLTU)
        }

        when(io.inst === Riscv.SLL ||
            io.inst === Riscv.SLLI ||
            io.inst === Riscv.SLLW ||
            io.inst === Riscv.SLLIW
        ){
            io.ALUop := B(Riscv.ALU_SLL)
        }

        when(io.inst === Riscv.SRL ||
            io.inst === Riscv.SRLI ||
            io.inst === Riscv.SRLW ||
            io.inst === Riscv.SRLIW
        ){
            io.ALUop := B(Riscv.ALU_SRL)
        }

        when(io.inst === Riscv.SRA ||
            io.inst === Riscv.SRAI ||
            io.inst === Riscv.SRAW ||
            io.inst === Riscv.SRAIW
        ){
            io.ALUop := B(Riscv.ALU_SRA)
        }

        when(io.inst === Riscv.XOR || io.inst === Riscv.XORI){
            io.ALUop := B(Riscv.ALU_XOR)
        }

        when(io.inst === Riscv.OR || io.inst === Riscv.ORI){
            io.ALUop := B(Riscv.ALU_OR)
        }

        when(io.inst === Riscv.AND || io.inst === Riscv.ANDI){
            io.ALUop === B(Riscv.ALU_AND)
        }
    }.setName("")

    val LOAD_TYPE = new Area{
        io.loadType := Riscv.loadDefault
        when(io.inst === Riscv.LB){
           io.loadType := B(Riscv.loadByte)
        }
        when(io.inst === Riscv.LBU){
            io.loadType := B(Riscv.loadByteU)
        }
        when(io.inst === Riscv.LH){
            io.loadType := B(Riscv.loadHalfWord)
        }

        when(io.inst === Riscv.LHU){
            io.loadType := B(Riscv.loadHalfWordU)
        }

        when(io.inst === Riscv.LW){
            io.loadType := B(Riscv.loadWord)
        }

        when(io.inst === Riscv.LWU){
            io.loadType := B(Riscv.loadWordU)
        }
    }.setName("")

    val ALUsrc = new Area{
        when(Riscv.isIType(io.inst(Riscv.opcode)) ||
            Riscv.isSType(io.inst(Riscv.opcode))
        ){
            io.ALUsrc := True
        }otherwise{
            io.ALUsrc := False
        }
    }.setName("")
}

case class branchPredict() extends Component{
    val io = new Bundle{
        val funct3 = in Bits(3 bits)
        val rs1 = in Bits(globalConfig.operandWidth bits)
        val rs2 = in Bits(globalConfig.operandWidth bits)
        val ctrlBranch = in Bool()
        val flush = out Bool()
        val branch = out Bool()
    }
    noIoPrefix()
    io.flush := False
    io.branch := False
    when(io.ctrlBranch){
        when(io.funct3 === Riscv.BEQ_funct3){
            when(io.rs1.asSInt === io.rs2.asSInt){
                io.flush := True
            }otherwise{
                io.flush := False
            }
        }
        when(io.funct3 === Riscv.BNE_funct3){
            when(io.rs1.asSInt =/= io.rs2.asSInt){
                io.flush := True
            }otherwise{
                io.flush := False
            }
        }
        when(io.funct3 === Riscv.BLT_funct3){
            when(io.rs1.asSInt < io.rs2.asSInt){
                io.flush := True
            }otherwise{
                io.flush := False
            }
        }
        when(io.funct3 === Riscv.BGE_funct3){
            when(io.rs1.asSInt >= io.rs2.asSInt){
                io.flush := True
            }otherwise{
                io.flush := False
            }
        }
        when(io.funct3 === Riscv.BLTU_funct3){
            when(io.rs1.asUInt < io.rs2.asUInt){
                io.flush := True
            }otherwise{
                io.flush := False
            }
        }
        when(io.funct3 === Riscv.BGEU_funct3){
            when(io.rs1.asUInt >= io.rs2.asUInt){
                io.flush := True
            }otherwise{
                io.flush := False
            }
        }

    }
}



case class hazardDet() extends Component{
    val io = new Bundle{
        val id2exMemRead = in Bool()
        val if2idRs1 = in Bits(5 bits)
        val id2exRd = in Bits(5 bits)
        val if2idRs2 = in Bits(5 bits)

        val id2exRegWrite = in Bool()
        
        val mem2wbRegWrite = in Bool()
        val mem2wbRd = in Bits(5 bits)
        
        val branch = in Bool()
        val stall = out Bool()
    }
    noIoPrefix()
    when(io.id2exMemRead &&
        (io.id2exRd === io.if2idRs1 || io.id2exRd === io.if2idRs2) 
    ){
        io.stall := True
    }otherwise{
        io.stall := False
    }


    // stall for branch in EX
    when(io.id2exRegWrite &&
        io.id2exRd =/= 0 &&
        ((io.id2exRd === io.if2idRs1 ||io.id2exRd === io.if2idRs2) && io.branch)
    ){
        io.stall := True
    }otherwise{
        io.stall := False
    }
    
    // stall for branch in MEM
    when(io.mem2wbRegWrite &&
        io.mem2wbRd =/= 0 &&
        ((io.if2idRs1 === io.mem2wbRd || io.if2idRs2 === io.mem2wbRd) && io.branch)
    ){
        io.stall := True
    }otherwise{
        io.stall := False
    }

}

