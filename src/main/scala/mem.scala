import spinal.core._
import spinal.sim._
import spinal.core.sim._
import spinal.lib._


import scala.collection.immutable._

case class instMem(width: Int=32, depth: Int=128) extends Component{
    require(isPow2(depth) && isPow2(width / 8), "depth is not pow(2)")
    val byteCount = width / 8   // 4
    val io = new Bundle{
        val address = in UInt(log2Up(depth * byteCount) bits)   // byte address
        val instruction = out Bits(width bits)
    }
    noIoPrefix()
    val content = for(i <- 0 until depth) yield  B(i, width bits)
    val mem = Mem(Bits(width bits), initialContent = content)
    io.instruction := mem.readAsync(io.address >> log2Up(byteCount))
}

object instMemSim extends App{
    SimConfig.withWave.compile(new instMem()).doSim{dut=>
        for(i <- 0 until 128){
            dut.io.address #= i * 4
            sleep(1)
        }
    }
}

case class dataMem(width: Int=64, depth: Int=1024) extends Component{
    require(isPow2(depth) && isPow2(width / 8), "Err depth or width")
    val byteCount = width / 8
    val io = new Bundle{
        val address = in UInt(log2Up(depth * byteCount) bits)
        val writeData = in Bits(width bits)
        val readData = out Bits(width bits)
        val memRead = in Bool()
        val memWrite = in Bool()
    }
    noIoPrefix()
    val mem = Mem(Bits(width bits), depth)
    when(io.memRead){
        io.readData := mem.readAsync(io.address >> log2Up(byteCount))
    }otherwise{
        io.readData := 0
    }
    mem.write(io.address >> log2Up(byteCount), io.writeData, io.memWrite)

}

object dataMemSim extends App{
    SimConfig.withWave.withConfig(SpinalConfig(
        defaultConfigForClockDomains = ClockDomainConfig(resetKind = SYNC, resetActiveLevel = HIGH),
        defaultClockDomainFrequency = FixedFrequency(100 MHz)
    )).compile(new dataMem(width = 16, 128)).doSim { dut =>
        dut.clockDomain.forkStimulus(10000)
        for(i <- 0 until 128){
            dut.io.address #= i * 2
            dut.io.memRead #= false
            dut.io.memWrite #= true
            dut.io.writeData #= i
            dut.clockDomain.waitSampling()
        }
        dut.io.memWrite #= false
        dut.clockDomain.waitSampling()
        for(i <- 0 until 128){
            dut.io.address #= i * 2
            dut.io.memRead #= true
            dut.io.memWrite #= false
            dut.io.writeData.randomize()
            dut.clockDomain.waitSampling()
        }
    }
}