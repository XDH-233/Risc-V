package pipeline

import spinal.core._
import spinal.core.internals.Operator
import spinal.sim._
import spinal.core.sim._
import spinal.lib._

class StageCTRLBundle extends Bundle with IMasterSlave{
    val stateOut = StageStateEnum()

    override def asMaster(): Unit = {
        out(stateOut)
    }
}

object StageStateEnum extends SpinalEnum(binaryOneHot){
    val FLUSH,STALL,ENABLE = newElement()    // Stage state
}

class Stage[T <: Bundle](gen: => T) extends Component{
    val left:T= gen.flip()
    val ctrl = slave(new StageCTRLBundle)
    val right:T= createOutPort(left)

    def <>(l:T,r:T):Unit={
        l<>left
        r<>right
    }

    def getInitData[T <: Data](data:T):Data={
        data match {
            case a:Bits => B(0)
            case u:UInt => U(0)
            case s:UInt => S(0)
            case b:Bool => False
            case e:SpinalEnumCraft[_] => e.spinalEnum.elements(0)
        }
    }
    def defaultData[T <: Data](data:T): Unit={
        data match {
            case v:Vec[_] => v.foreach(a=>initData(a))
            case a => a:= getInitData(a).asInstanceOf[T]
        }
    }
    def initData[T <: Data](data:T): Unit ={
        data match {
            case v:Vec[_] => v.foreach(a=>initData(a))
            case a => a.init(getInitData(a).asInstanceOf[T])
        }
    }

    private def createOutPort(inBundle:Bundle):T= {
        new Bundle {
            for(i <- inBundle.elements){

                val a =out (Reg(i._2.clone()))
                initData(a)
                valCallbackRec(a,i._1)
                when(ctrl.stateOut===StageStateEnum.ENABLE){
                    a := i._2
                }elsewhen(ctrl.stateOut === StageStateEnum.FLUSH){
                    defaultData(a)
                }otherwise{   //Stall
                    // 啥都不干，锁存
                }

            }
        }
    }.asInstanceOf[T]
}


object stages{
    val if2id = new Bundle{
        val PC = out UInt(log2Up(globalConfig.instNum) bits)
        val inst = out Bits(globalConfig.operandWidth bits)
        val flush = out Bool()
    }

    val id2ex = new Bundle{
        val regWrite = out Bool()
        val memtoReg = out Bool()
        val memRead = out Bool()
        val memWrite = out Bool()
        val ALUop = out Bits(2 bits)
        val ALUsrc = out Bool()
        val readData1, readData2, immGenOut= out SInt(globalConfig.operandWidth bits)
        val rs1, rs2, rd = out UInt(5 bits)
    }

    val ex2mem = new Bundle{
        val regWrite = out Bool()
        val memtoReg = out Bool()
        val memRead = out Bool()
        val memWrite = out Bool()
        val ALUResult = out SInt(globalConfig.operandWidth bits)
        val ALUData1 = out SInt(globalConfig.operandWidth bits)
        val rs2, rd = out UInt(5 bits)
    }
    val mem2wb = new Bundle{
        val regWrite = out Bool()
        val memtoReg = out Bool()
        val readData = out Bits(globalConfig.operandWidth bits)
        val ALUResult = out SInt(globalConfig.operandWidth bits)
        val rd = UInt(5 bits)
    }
}






