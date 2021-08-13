import pipeline._


import spinal.core._
import spinal.sim._
import spinal.core.sim._
import spinal.lib._


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