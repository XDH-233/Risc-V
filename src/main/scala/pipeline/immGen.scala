package pipeline

import spinal.core._
import spinal.sim._
import spinal.core.sim._
import spinal.lib._


case class immGen(inWidth: Int=32, outWidth:Int=64) extends Component{
    val io = new Bundle{
        val inst = in Bits(inWidth bits)
        val immGenOut = out SInt(outWidth bits)
    }
    noIoPrefix()
    io.immGenOut := 0
    // I type
    when(io.inst(Riscv.opcode) === B"0010011" ||
         io.inst(Riscv.opcode) === B"0000011" ||
         io.inst(Riscv.opcode) === B"0011011" ||
         io.inst(Riscv.opcode) === B"1100111"
         ){
        io.immGenOut  := Riscv.IMM(io.inst).i_sext.asSInt
    }
    // S type
    when(io.inst(Riscv.opcode) === B"0100011"){
        io.immGenOut  := Riscv.IMM(io.inst).s_sext.asSInt
    }
    // B type
    when(io.inst(Riscv.opcode) === B"1100011"){
        io.immGenOut := Riscv.IMM(io.inst).b_sext.asSInt
    }
    // J type
    when(io.inst(Riscv.opcode) === B"1101111"){
        io.immGenOut  := Riscv.IMM(io.inst).j_sext.asSInt
    }
}

