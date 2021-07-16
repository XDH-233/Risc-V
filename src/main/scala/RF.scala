import spinal.core._
import spinal.sim._
import spinal.core.sim._
import spinal.lib._

case class RF(width: Int=64) extends Component{
    val io = new Bundle{
        val readReg1, readReg2, writeReg = in UInt(5 bits)
        val writeData = in SInt(width bits)
        val readData1, readData2 = out SInt(width bits)
        val RegWrite = in Bool()
    }
    noIoPrefix()
    val regs = Vec(Reg(SInt(width bits)) init(0), 32)
    regs.foreach(data=>data)
    when(io.RegWrite){
        regs.access(io.writeReg) := io.writeData
    }

    io.readData1 := regs.read(io.readReg1)
    io.readData2 := regs.read(io.readReg2)
}

object RF_RTL extends App{
    SpinalConfig(
        defaultConfigForClockDomains = ClockDomainConfig(resetKind = SYNC, resetActiveLevel = HIGH)
    ).generateVerilog(new RF(8))
}

object RF_Sim extends App{
    SimConfig.withWave.withConfig(SpinalConfig(
        defaultConfigForClockDomains = ClockDomainConfig(resetKind = SYNC, resetActiveLevel = HIGH),
        defaultClockDomainFrequency = FixedFrequency(100 MHz)
    )).compile(new RF(16)).doSim{dut=>
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