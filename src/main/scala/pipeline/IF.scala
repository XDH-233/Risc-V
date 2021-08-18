package pipeline


import spinal.core._
import spinal.core.sim._


case class instMem(width: Int = 32, depth: Int = 128) extends Component { // depth is the num of D-word
    require(isPow2(depth) && isPow2(width / 8), "depth is not pow(2)")
    val byteCount = width / 8 // => 4
    val io        = new Bundle {
        val address     = in UInt (log2Up(depth * byteCount) bits) // byte address
        val instruction = out Bits (width bits)
    }
    noIoPrefix()
    import Riscv._
    val arr = Array.fill(depth)(BigInt(0))

    val  inst = arr.map(n => B(n, width bits))
    val  mem  = Mem(Bits(width bits), initialContent = inst)
    io.instruction := mem.readAsync(io.address >> log2Up(byteCount))
}

