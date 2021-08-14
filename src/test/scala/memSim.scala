import pipeline.dataMem

import spinal.core._
import spinal.sim._
import spinal.core.sim._
import spinal.lib._


object dataMemSimu extends App{
    SimConfig.withWave.withConfig(SpinalConfig(
        defaultConfigForClockDomains = ClockDomainConfig(resetKind = SYNC, resetActiveLevel = HIGH),
        defaultClockDomainFrequency = FixedFrequency(100 MHz)
    )).compile(new dataMem(64, 1024)).doSim { dut =>
        dut.clockDomain.forkStimulus(10000)
        for(i <- 0 until 200){
            dut.io.address #= i
            dut.io.memWrite #= false
            dut.io.memRead #= true
            dut.io.writeData.randomize()
            dut.clockDomain.waitSampling()
        }
    }
}