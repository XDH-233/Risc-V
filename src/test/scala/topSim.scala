import pipeline._
import BigIntAndString._


import spinal.core._
import spinal.sim._
import spinal.core.sim._
import spinal.lib._


object topRTL extends App{
    SpinalConfig(
        defaultConfigForClockDomains = ClockDomainConfig(resetKind = SYNC, resetActiveLevel = HIGH)
    ).generateVerilog(new top())
}


object topSim extends App{
    SimConfig.withWave.withConfig(SpinalConfig(
        defaultConfigForClockDomains = ClockDomainConfig(resetKind = SYNC, resetActiveLevel = HIGH),
        defaultClockDomainFrequency = FixedFrequency(100 MHz)
    )).compile(new top()).doSim { dut =>
        dut.clockDomain.forkStimulus(10000)
        for(i <- 0 until 30){
            dut.clockDomain.waitSampling()
        }
    }
}

