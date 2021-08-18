package pipeline

import spinal.core._
import spinal.core.internals.Operator
import spinal.sim._
import spinal.core.sim._
import spinal.lib._



trait stageOp {
    this: Bundle =>
    def toReg = {
        for ((_, e) <- this.elements) {
            e match {
                case b: Bits => e setAsReg() init (B(0))
                case u: UInt => e setAsReg() init (U(0))
                case s: SInt => e setAsReg() init (S(0))
                case l: Bool => e setAsReg() init (False)
            }
        }
    }
    def doReset = {
        for ((_, e) <- this.elements) {
            e match {
                case b: Bits => e := B(0)
                case u: UInt => e := U(0)
                case s: SInt => e := S(0)
                case l: Bool => e := False
            }
        }
    }
}

object Stages {
    case class if2idB() extends Bundle with stageOp {
        val PC   = UInt(globalConfig.PCWidth bits)
        val inst = Bits(globalConfig.instWidth bits)
    }

    case class id2exB() extends Bundle with stageOp {
        val regWrite                        = Bool()
        val memtoReg                        = Bool()
        val memRead                         = Bool()
        val memWrite                        = Bool()
        val ALUop                           = Bits(4 bits)
        val ALUsrc                          = Bool()
        val readData1, readData2, immGenOut = Bits(globalConfig.operandWidth bits)
        val rs1, rs2, rd                    = UInt(5 bits)
        val PC4                             = UInt(globalConfig.PCWidth bits)
        val J                               = Bool()
        val JR                              = Bool()
    }

    case class ex2memB() extends Bundle with stageOp {
        val regWrite         = Bool()
        val memtoReg         = Bool()
        val memRead          = Bool()
        val memWrite         = Bool()
        val ALUResult        = Bits(globalConfig.operandWidth bits)
        val regFileReadData2 = Bits(globalConfig.operandWidth bits)
        val rs2, rd          = UInt(5 bits)
    }

    case class mem2wbB() extends Bundle with stageOp {
        val regWrite  = Bool()
        val memtoReg  = Bool()
        val readData  = Bits(globalConfig.operandWidth bits)
        val ALUResult = Bits(globalConfig.operandWidth bits)
        val rd        = UInt(5 bits)
    }
}


class Stage[T <: Bundle with stageOp](signals: => T) extends Component {
    val flush    = in Bool()
    val stall    = in Bool()
    val left : T = signals.asInput()
    val right: T = signals.asOutput()
    right.toReg
    when(flush) {
        right.doReset
    } elsewhen (stall) {
        //lock
    } otherwise {
        right <> left
    }
}


object StageRTL extends App {
    SpinalConfig(
        defaultConfigForClockDomains = ClockDomainConfig(resetKind = SYNC, resetActiveLevel = HIGH)
    ).generateVerilog(new Stage(Stages.if2idB()))
}

class if2idDut() extends Component {
    val flush = in Bool()
    val stall = in Bool()
    val inst  = out Bits (globalConfig.operandWidth bits)
    val In    = Stages.if2idB().asInput()

    val IF2ID = new Stage(Stages.if2idB()).setDefinitionName("IF2ID")

    IF2ID.left <> In
    IF2ID.stall := stall
    IF2ID.flush := flush

    inst := IF2ID.right.inst
}


object if2idDutRTL extends App {
    SpinalConfig(
        defaultConfigForClockDomains = ClockDomainConfig(resetKind = SYNC, resetActiveLevel = HIGH)
    ).generateVerilog(new if2idDut())
}

object if2idDutSim extends App {
    SimConfig.withWave.withConfig(SpinalConfig(
        defaultConfigForClockDomains = ClockDomainConfig(resetKind = SYNC, resetActiveLevel = HIGH),
        defaultClockDomainFrequency = FixedFrequency(100 MHz)
    )).compile(new if2idDut()).doSim { dut =>
        dut.clockDomain.forkStimulus(10000)
        dut.flush #= true
        dut.stall #= false
        dut.clockDomain.waitSampling(5)
        for (i <- 0 until 100) {
            val a = scala.util.Random.nextInt(3)
            if (a == 0) {
                dut.flush #= true
                dut.stall #= false
            } else if (a == 1) {
                dut.flush #= false
                dut.stall #= true
            } else {
                dut.flush #= false
                dut.stall #= false
            }
            dut.In.randomize()
            dut.clockDomain.waitSampling()
        }
    }
}










