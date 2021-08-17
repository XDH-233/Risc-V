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
//    arr(2)  = "12419"                 // ld   x1,  0(x0)
//    arr(3)  = "8401155"               // ld   x2,  8(x0)
//    arr(4)  = "16789891"              // ld   x3, 16(x0)
//    arr(5)  = "3211827"               // add  x4, x2, x3
//    arr(6)  = "1075970739"            // sub  x5, x4, x2
//    arr(7)  = "4289331"               // and  x6, x2, x4
//    arr(8)  = "2253747"               // or   x7, x2, x4
//    arr(9)  = "40906787"              // sd   x7, 32(x0)
//    arr(10) = "33567747"              // ld   x8, 32(x0)
//    arr(11) = "8620643"               // beq  x7, x8, 20
//    arr(16) = "8619187"               // add  x9, x7, x8
    arr(4) = INST(name = LD, Rd = 8, Rs1 = 0, Imm = 32)
    arr(5) = INST(name = LD, Rd = 4, Rs1 = 0, Imm = 48)


    val  inst = arr.map(n => B(n, width bits))
    val  mem  = Mem(Bits(width bits), initialContent = inst)
    io.instruction := mem.readAsync(io.address >> log2Up(byteCount))
}

