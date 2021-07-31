package pipeline

import spinal.core._
import spinal.sim._
import spinal.core.sim._
import spinal.lib._
// component from singleCycle
import singleCycle.RF
import singleCycle.instMem


object globalConfig{
    val operandWidth = 64
    val instNum =128
    val dataNum =  128
}
case class top() extends Component{


    // IF
    val PC = Reg(UInt(log2Up(globalConfig.instNum) bits)) init(0)     //TODO    PC := Mux(sel = ? , whenTrue = IF2ID.PC + imm, whenFalse = PC + 4)   // Branch prediction design
    val instructionMem = instMem(width = globalConfig.operandWidth, depth = globalConfig.instNum)

    // IF/ID
   val IF2ID = new Stage(stages.if2id).setDefinitionName("IF2ID")

    // ID
    val registerFile = RF(globalConfig.operandWidth)

    // ID/EX
    val ID2EX = new Stage(stages.id2ex).setDefinitionName("ID2EX")


    // EX

    // EX/MEM

    val EX2MEM = new Stage(stages.ex2mem)

    // MEM

    // MEM/WB
    val MEM2WB = new Stage(stages.mem2wb)
    // WB







}