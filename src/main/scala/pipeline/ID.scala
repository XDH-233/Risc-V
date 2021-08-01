package pipeline


import javafx.scene.control.RadioMenuItem
import spinal.core._
import spinal.sim._
import spinal.core.sim._
import spinal.lib._


case class control() extends Component{
    val io = new Bundle{
        val inst = in Bits(globalConfig.operandWidth bits)

        val Branch = out Bool()
        val regWrite = out Bool()
        val memtoReg = out Bool()
        val memWrite = out Bool()
        val memRead = out Bool()
        val ALUop = out Bits(4 bits)
        val load_type = out Bits(2 bits)
        val ALUsrc = out Bool()
    }
    noIoPrefix()

    val BRANCH =new Area{
        when(Riscv.isBType(io.inst(Riscv.opcode))){
            io.Branch := True
        }otherwise{
            io.Branch := False
        }
    }.setName("")

    val REG_WRITE = new Area {
        when(Riscv.isRType(io.inst(Riscv.opcode)) ||
            Riscv.isITyoe(io.inst(Riscv.opcode)) ||
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

    val MEM_READ = new Area{
        when(Riscv.isLoadInstOpcode(io.inst(Riscv.opcode))){
            io.memRead := True
        }otherwise{
            io.memRead := True
        }
    }.setName("")

    val ALU_OP = new Area {
        io.ALUop := Riscv.ALU_NOP
        when(io.inst === Riscv.ADD ||
            io.inst === Riscv.ADDI ||
            io.inst === Riscv.ADDW ||
            io.inst === Riscv.ADDIW){
                io.ALUop := Riscv.ALU_ADD
        }

        when(Riscv.isLoadInstOpcode(io.inst(Riscv.opcode)) ||
            Riscv.isSType(io.inst(Riscv.opcode)) ||
            io.inst === Riscv.AUIPC
        ){
            io.ALUop := Riscv.ALU_RAM
        }

        when(io.inst === Riscv.SUB ||
            io.inst === Riscv.SUBW ||
        ){
            io.ALUop := Riscv.ALU_SUB
        }

        when(io.inst === Riscv.SLT ||
            io.inst === Riscv.SLTI ||
        ){
            io.ALUop := Riscv.ALU_SLT
        }

        when(io.inst === Riscv.SLTIU){
            io.ALUop := Riscv.ALU_SLTU
        }

        when(io.inst === Riscv.SLL ||
            io.inst === Riscv.SLLI ||
            io.inst === Riscv.SLLW ||
            io.inst === Riscv.SLLIW
        ){
            io.ALUop := Riscv.ALU_SLL
        }

        when(io.inst === Riscv.SRL ||
            io.inst === Riscv.SRLI ||
            io.inst === Riscv.SRLW ||
            io.inst === Riscv.SRLIW
        ){
            io.ALUop := Riscv.ALU_SRL
        }

        when(io.inst === Riscv.SRA ||
            io.inst === Riscv.SRAI ||
            io.inst === Riscv.SRAW ||
            io.inst === Riscv.SRAIW
        ){
            io.ALUop := Riscv.ALU_SRA
        }

        when(io.inst === Riscv.XOR || io.inst === Riscv.XORI){
            io.ALUop := Riscv.ALU_XOR
        }

        when(io.inst === Riscv.OR || io.inst === Riscv.ORI){
            io.ALUop := Riscv.ALU_OR
        }

        when(io.inst === Riscv.AND || io.inst === Riscv.ANDI){
            io.ALUop === Riscv.ALU_AND
        }
    }.setName("")


}


case class branchPredict() extends Component{
    val io = new Bundle{
        val rs1 = in SInt(globalConfig.operandWidth bits)
        val rs2 = in SInt(globalConfig.operandWidth bits)
        val branch = in Bool()
    }
    noIoPrefix()

}