package pipeline

import spinal.core._
import spinal.sim._
import spinal.core.sim._
import spinal.lib._

class Stage[T <: Bundle](gen: => T) extends Component{
    val left:T= gen.flip()
    val right = createOutPort(left)
    def createOutPort(inBundle:Bundle)= {
        new Bundle {
            for(i <- inBundle.elements){
                val a =out (Reg(i._2.clone()))
                a match{
                    case s:Bits => s.init(0)
                    case b:Bool => b.init(False)
                }
                valCallbackRec(a,i._1)
                a := i._2
            }
        }
    }
}


case class if2id(pcWidth: Int, instWidth: Int) extends Component{
    val PCIn = in UInt(pcWidth bits)
    val instIn = in Bits(instWidth bits)
    val PCOut = out UInt(pcWidth bits) setAsReg() init(0)
    val instOut = out Bits(instWidth bits) setAsReg() init(0)

    PCOut := PCIn
    instOut := instIn
}










