import pipeline.dataMem

import spinal.core._
import spinal.sim._
import spinal.core.sim._
import spinal.lib._

object dataMemSim extends App {
    SimConfig.withWave.withConfig(SpinalConfig(
        defaultConfigForClockDomains = ClockDomainConfig(resetKind = SYNC, resetActiveLevel = HIGH),
        defaultClockDomainFrequency = FixedFrequency(100 MHz)
    )).compile(new dataMem(width = 16, 128)).doSim { dut =>
        dut.clockDomain.forkStimulus(10000)
        for (i <- 0 until 128) {
            dut.io.address #= i * 2
            dut.io.memRead #= false
            dut.io.memWrite #= true
            dut.io.writeData #= i
            dut.clockDomain.waitSampling()
        }
        dut.io.memWrite #= false
        dut.clockDomain.waitSampling()
        for (i <- 0 until 128) {
            dut.io.address #= i * 2
            dut.io.memRead #= true
            dut.io.memWrite #= false
            dut.io.writeData.randomize()
            dut.clockDomain.waitSampling()
        }
    }
}