package pipeline

import spinal.core._
import spinal.sim._
import spinal.core.sim._
import spinal.lib._

case class dataMem(width: Int = 64, depth: Int = 1024) extends Component {
    require(isPow2(depth) && isPow2(width / 8), "Err depth or width")
    val byteCount = width / 8
    val io        = new Bundle {
        val address   = in UInt (log2Up(depth * byteCount) bits)
        val writeData = in Bits (width bits)
        val readData  = out Bits (width bits)
        val memRead   = in Bool()
        val memWrite  = in Bool()
    }
    noIoPrefix()
    val content = for (i <- 0 until depth) yield B(i, width bits) // initial data
    val mem     = Mem(Bits(width bits), initialContent = content)
    when(io.memRead) {
        io.readData := mem.readAsync(io.address >> log2Up(byteCount))
    } otherwise {
        io.readData := 0
    }
    mem.write(io.address >> log2Up(byteCount), io.writeData, io.memWrite)
}

