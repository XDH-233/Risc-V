package pipeline

import spinal.core._
import spinal.sim._
import spinal.core.sim._
import spinal.lib._
// component from singleCycle
import singleCycle.RF
import singleCycle.instMem


case class globalConfig(operandWidth: Int=64, instNum: Int=128, dataNum: Int= 128)
case class top() extends Component{
    val config = globalConfig()

    // IF
    val PC = Reg(UInt(log2Up(config.instNum) bits)) init(0)     //TODO    PC := Mux(sel = ? , whenTrue = IF2ID.PC + imm, whenFalse = PC + 4)   // Branch prediction design
    val instructionMem = instMem(width = config.operandWidth, depth = config.instNum)

    // IF2ID
    val IF2ID = if2id(pcWidth=log2Up(config.instNum), instWidth=config.operandWidth)

    // ID
    val registerFile = RF(config.operandWidth)






}