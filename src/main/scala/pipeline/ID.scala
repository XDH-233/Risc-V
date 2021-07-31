package pipeline


import spinal.core._
import spinal.sim._
import spinal.core.sim._
import spinal.lib._


case class control() extends Component{
    val io = new Bundle{
        val opCode, funct7 = in Bits(7 bits)
        val funct3 = in Bits(3 bits)
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

    val branch =new Area{
        when(Riscv.isBType(io.opCode)){
            io.Branch := True
        }otherwise{
            io.Branch := False
        }
    }.setName("")

    val RegWrite = new Area {
        when(Riscv.isRType(io.opCode) ||
            Riscv.isITyoe(io.opCode) ||
            Riscv.isUTYpe(io.opCode) ||
            Riscv.isJTYpe(io.opCode)){
            io.regWrite := True
        }otherwise{
            io.regWrite := False
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