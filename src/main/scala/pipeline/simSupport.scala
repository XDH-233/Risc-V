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
        println(INST(name = Riscv.ADD, Rd = 4, Rs1 = 2, Rs2 = 3))

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
        val immUJ           = Imm.toBits(20)
        if(isRType(opcode)){
            return (funct7 + rs2 + rs1 + funct3 + rd + opcode).UBSToBigInt
        }else if(isIType(opcode)){
            return (imm + rs1 + funct3 + rd + opcode).UBSToBigInt
        }else if(isSType(opcode)){
            return (imm.substring(0, 7) + rs2 + rs1 + funct3 + imm.substring(7, 12) + opcode).UBSToBigInt
        }else if(isBType(opcode)){
            return (imm.substring(0,1) + imm.substring(2, 8) + rs2 + rs1 + funct3 + imm.substring(8, 12) + imm.substring(1,2) + opcode).UBSToBigInt
        } else if(isJType(opcode)){
            //TODO tobe revised
            return (immUJ.substring(0, 1) + immUJ.substring(10, 20) + immUJ.substring(9, 10) + immUJ.substring(1, 9) + rd + opcode).UBSToBigInt
        }else{ // U-Type
            //TODO to be revised
            return (immUJ.substring(0, 20) + rd + opcode).UBSToBigInt
        }
    }


//
//    //------------------------------I-Type-------------------------------------------
//    def apply(name: MaskedLiteral, Rd: BigInt, Imm: BigInt, Rs1: BigInt):BigInt={
//        val imm   : String = Imm.toBits(12)
//        val rs1            = Rs1.toBits(5)
//        val funct3         = name.ToString.funct3
//        val rd    : String = Rd.toBits(5)
//        val opcode: String = name.ToString.opcode
//        return (imm + rs1 + funct3 + rd + opcode).UBSToBigInt
//    }
//
//    //-------------------------------S-Type------------------------------------------
//    def apply(name:MaskedLiteral, Rs2:BigInt, Imm: BigInt, Rs1: BigInt): BigInt={
//        val imm   : String = Imm.toBits(12)
//        val rs2            = Rs2.toBits(5)
//        val rs1   : String = Rs1.toBits(5)
//        val funct3: String = name.ToString.funct3
//        val opcode: String = name.ToString.opcode
//        return (imm.substring(0, 7) + rs2 + rs1 + funct3 + imm.substring(7, 12) + opcode).UBSToBigInt
//    }
//
//    //-------------------------------B-type------------------------------------------------
//    def apply(name: MaskedLiteral, Rs1: BigInt, Rs2: BigInt, Imm: BigInt) :BigInt={
//        val imm   : String = Imm.toBits(13).substring(0, 12)
//        val rs2             = Rs2.toBits(5)
//        val rs1   : String = Rs1.toBits(5)
//        val funct3: String = name.ToString.funct3
//        val opcode: String = name.ToString.opcode
//        return (imm.substring(0,1) + imm.substring(2, 8) + rs2 + rs1 + funct3 + imm.substring(8, 12) + imm.substring(1,2) + opcode).UBSToBigInt
//    }

}