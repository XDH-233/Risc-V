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
    import INST._

    val arr = Array.fill(depth)(BigInt(0))

    arr(0)  = INST(name = LD, Rd = x3, Rs1 = x0, Imm = 2048)
    arr(1)  = INST(name = LD, Rd = x9, Rs1 = x0, Imm = 88)
    arr(6)  = INST(name = SB, Rs1 = x0, Rs2 = x3, Imm = 88)
    arr(11)  = INST(name = LD, Rd = x9, Rs1 = x0, Imm = 88)


    val  inst = arr.map(n => B(n, width bits))
    val  mem  = Mem(Bits(width bits), initialContent = inst)
    io.instruction := mem.readAsync(io.address >> log2Up(byteCount))
}

