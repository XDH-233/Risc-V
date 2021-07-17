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
    val arr = Array.fill(depth)("0")
    arr(2) = "12419"        // ld   x1,  0(x0)
    arr(3) = "8401155"      // ld   x2,  8(x0)
    arr(4) = "16789891"     // ld   x3, 16(x0)
    arr(5) = "3211827"      // add  x4, x2, x3
    arr(6) = "1075970739"   // sub  x5, x5, x2
    arr(7) = "2257715"      // and  x6, x2, x4
    arr(8) = "2253747"      // or   x7, x2, x4
    arr(9) = "40923171"     // sd   x7, 32(x0)
    arr(10)= "33567747"     // ld   x8, 32(x0)
    arr(11)= "8620643"      // beq  x7, x8, 20
    arr(16) = "8619187"     // add  x9, x7, x8
    val inst = arr.map(n=>B(BigInt(n), width bits))
    val mem = Mem(Bits(width bits), initialContent = inst)
    io.instruction := mem.readAsync(io.address >> log2Up(byteCount))
}

object instMemSim extends App{
    SimConfig.withWave.compile(new instMem(32, 128)).doSim{dut=>
        for(i <- 0 until 128){
            dut.io.address #= i * 4
            sleep(1)
        }
    }
}

case class dataMem(width: Int=64, depth: Int=1024) extends Component{  // depth of data in the form of D-word
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
    val content = for(i <- 0 until depth) yield B(i, width bits)   // initial data
    val mem = Mem(Bits(width bits), initialContent = content)
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