package pipeline

import spinal.core._
import spinal.sim._
import spinal.core.sim._
import spinal.lib._


case class immGen(inWidth: Int=32, outWidth:Int=64) extends Component{
    val io = new Bundle{
        val inst = in Bits(inWidth bits)
        val immGenOut = out Bits(outWidth bits)
    }
    noIoPrefix()
    io.immGenOut := 0
    // I type
    when(Riscv.isIType(io.inst(Riscv.opcode))){
        io.immGenOut  := Riscv.IMM(io.inst).i_sext
    }
    // S type
    when(Riscv.isSType(io.inst(Riscv.opcode))){
        io.immGenOut  := Riscv.IMM(io.inst).s_sext
    }
    // B type
    when(Riscv.isBType(io.inst(Riscv.opcode))){
        io.immGenOut  := Riscv.IMM(io.inst).b_sext
    }
    // J type
    when(Riscv.isJType(io.inst(Riscv.opcode))){
        io.immGenOut  := Riscv.IMM(io.inst).j_sext
    }

    when(Riscv.isUType(io.inst(Riscv.opcode))){
        io.immGenOut := Riscv.IMM(io.inst).u
    }
}


object immGenRTL extends App{
    SpinalVerilog(new immGen())
}
