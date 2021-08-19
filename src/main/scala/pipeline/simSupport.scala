package pipeline

import spinal.core._
import spinal.sim._
import spinal.core.sim._
import spinal.lib._



object BigIntAndString{
    implicit class instRange(str: String){
        def funct7 = str.substring(0, 7)
        def rs2 = str.substring(7, 12)
        def rs1 = str.substring(12, 17)
        def funct3 = str.substring(17, 20)
        def rd = str.substring(20, 25)
        def opcode = str.substring(25, 32)
    }
    implicit class MaskedLiteralConv(m: MaskedLiteral){
        def ToString: String={
            m.toString().substring(2, 34)
        }
    }
    implicit class BigIntToBinary(num:BigInt){
        // 8-bit: 35: BigInt -> 100011: String, -128 -> 10000000: String
        def toBits(width: Int): String ={
            require(num >= - BigInt(2).pow(width - 1) && num <= BigInt(2).pow(width) - 1, "out of range")
            var res = ""
            val numWidth = num.bitLength
            if(num >= 0){
                for(i <- (0 until width).reverse){
                    if(i > numWidth - 1)
                        res = res + "0"
                    else if(num.testBit(i)){
                        res = res + "1"
                    }else{
                        res = res + "0"
                    }
                }

            }else{
                for(i <- (0 until width).reverse){
                    if(i > numWidth - 1)
                        res = res + "1"
                    else if(num.testBit(i))
                        res = res + "1"
                    else{
                        res = res + "0"
                    }
                }
            }
            return res
        }
        def SLL(width: Int, sham: Int) =  (num << sham) & BigInt((1l << width) - 1)
    }
    implicit class binStringToBigInt(bin: String){
        // "00100011": String -> 35: BigInt
        def UBSToBigInt: BigInt ={
            var num = BigInt(bin)
            if(num == BigInt(0)) {
                return BigInt(0)
            }else{
                var res = BigInt(0)
                var dig = 0
                while(num != 0){
                    res = res  + (num mod 10) * BigInt(2).pow(dig)
                    num = num / 10
                    dig = dig + 1
                }
                return res
            }
        }
        // "111111": String -> -1: BigInt
        def SBSToBigInt: BigInt = {
            if(bin.startsWith("0"))
                return bin.UBSToBigInt
            else{
                val length = bin.length
                val res = -(BigInt(2).pow(length - 1) - bin.substring(1, length).UBSToBigInt)
                return res
            }
        }
    }
}


object BitsSim{
    def main(args: Array[String]): Unit = {
        import INST._
        import Riscv._
        import BigIntAndString._

        println(INST(name = LD, Rd = x3, Rs1 = x0, Imm = 4000).toBits(32))
        println(BigInt(4000).toBits(12))

    }
    implicit class SignedBigInt(bt: Bits){
        def getSign: BigInt = {
            val width = bt.getWidth
            var num = bt.toBigInt
            if(num > BigInt(2).pow(width - 1) - 1){ // negtive
                return num - BigInt(2).pow(width)
            }
            return num
        }
        def assignSign(signedNum: BigInt)={
            val width = bt.getWidth
            require((signedNum <= BigInt(2).pow(width - 1) - 1 && signedNum >= -BigInt(2).pow(width - 1)), "out of range")
            if(signedNum >= 0)
                bt #= signedNum
            else{
                bt #= BigInt(2).pow(width) + signedNum
            }
        }
    }
}


object INST{
    import BigIntAndString._
    import Riscv._
    def apply(name: MaskedLiteral, Rd: BigInt = 0, Rs1: BigInt = 0, Rs2: BigInt = 0, Imm: BigInt = 0): BigInt ={

        val funct7: String = name.ToString.funct7
        val rs2   : String = Rs2.toBits(5)
        val rs1   : String = Rs1.toBits(5)
        val funct3: String = name.ToString.funct3
        val rd    : String = Rd.toBits(5)
        val opcode: String = name.ToString.opcode
        val imm            = Imm.toBits(12)
        val immUJ          = Imm.toBits(21).substring(0, 20)
        val immB           = Imm.toBits(13).substring(0, 12)
        if(isRType(opcode)){
            return (funct7 + rs2 + rs1 + funct3 + rd + opcode).UBSToBigInt
        }else if(isIType(opcode)){
            return (imm + rs1 + funct3 + rd + opcode).UBSToBigInt
        }else if(isSType(opcode)){
            return (imm.substring(0, 7) + rs2 + rs1 + funct3 + imm.substring(7, 12) + opcode).UBSToBigInt
        }else if(isBType(opcode)){
            return (immB.substring(0,1) + immB.substring(2, 8) + rs2 + rs1 + funct3 + immB.substring(8, 12) + immB.substring(1,2) + opcode).UBSToBigInt
        } else if(isJType(opcode)){
            return (immUJ.substring(0, 1) + immUJ.substring(10, 20) + immUJ.substring(9, 10) + immUJ.substring(1, 9) + rd + opcode).UBSToBigInt
        }else{ // U-Type
            //TODO to be revised
            return (immUJ.substring(0, 20) + rd + opcode).UBSToBigInt
        }
    }
    def x0:  BigInt = 0
    def x1:  BigInt = 1
    def x2:  BigInt = 2
    def x3:  BigInt = 3
    def x4:  BigInt = 4
    def x5:  BigInt = 5
    def x6:  BigInt = 6
    def x7:  BigInt = 7
    def x8:  BigInt = 8
    def x9:  BigInt = 9
    def x10: BigInt = 10
    def x11: BigInt = 11
    def x12: BigInt = 12
    def x13: BigInt = 13
    def x14: BigInt = 14
    def x15: BigInt = 15
    def x16: BigInt = 16
    def x17: BigInt = 17
    def x18: BigInt = 18
    def x19: BigInt = 19
    def x20: BigInt = 20
    def x21: BigInt = 21
    def x22: BigInt = 22
    def x23: BigInt = 23
    def x24: BigInt = 24
    def x25: BigInt = 25
    def x26: BigInt = 26
    def x27: BigInt = 27
    def x28: BigInt = 28
    def x29: BigInt = 29
    def x30: BigInt = 30
    def x32: BigInt = 31


}