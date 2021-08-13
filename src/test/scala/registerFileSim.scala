import pipeline.registerFile

import spinal.core._
import spinal.sim._
import spinal.core.sim._
import spinal.lib._

object RF_RTL extends App{
    SpinalConfig(
        defaultConfigForClockDomains = ClockDomainConfig(resetKind = SYNC, resetActiveLevel = HIGH)
    ).generateVerilog(new registerFile(8))
}

object registerFileSim extends App{
    SimConfig.withWave.withConfig(SpinalConfig(
        defaultConfigForClockDomains = ClockDomainConfig(resetKind = SYNC, resetActiveLevel = HIGH),
        defaultClockDomainFrequency = FixedFrequency(100 MHz)
    )).compile(new registerFile(16)).doSim{ dut=>
        dut.clockDomain.forkStimulus(100)
        dut.clockDomain.waitSampling()
        for(i <- 0 until 32){
            dut.io.readReg1.randomize()
            dut.io.readReg2.randomize()
            dut.io.RegWrite #= true
            dut.io.writeData.randomize()
            dut.io.writeReg #= i
            dut.clockDomain.waitSampling()
        }
        for(i <- 0 until 50){
            dut.io.readReg1.randomize()
            dut.io.readReg2.randomize()
            dut.io.RegWrite.randomize()
            dut.io.writeData.randomize()
            dut.io.writeReg.randomize()
            dut.clockDomain.waitSampling()
        }
    }
}