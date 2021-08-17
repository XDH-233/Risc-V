import pipeline._

import spinal.core._
import spinal.sim._
import spinal.core.sim._
import spinal.lib._


object aluSimu extends App{
    import BitsSim._
    import BigIntAndString._

    implicit class aluSimFuct(dut: alu) {
        def init = {
            dut.io.data1.randomize()
            dut.io.data2.randomize()
        }

        def initShift={
            dut.io.data1.randomize()
            dut.io.data2 #= scala.util.Random.nextInt(dut.width + 1)
        }

        val UIntData1 = dut.io.data1.toBigInt
        val UIntData2 = dut.io.data2.toBigInt
        val UIntRes = dut.io.res.toBigInt

        val SIntData1 = dut.io.data1.getSign
        val SIntData2 = dut.io.data2.getSign
        val SIntRes = dut.io.res.getSign

        def disUInt = {
            printf("% 10d\n", dut.UIntData1)
            printf("% 10d\n", dut.UIntData2)
            println("----------------")
            printf("% 10d\n", dut.UIntRes)
        }

        def disSInt = {
            printf("% 10d\n", dut.SIntData1 )
            printf("% 10d\n", dut.SIntData2)
            println("-------------------")
            printf("% 10d\n", dut.SIntRes)
        }

        def disUIntBits = {
            printf("% 10d\n", dut.UIntData1)
            printf("% 10d\n", dut.UIntData2)
            println("-------------------")
            printf("% 10d\n", dut.UIntRes)
            println( dut.UIntData1.toBits(dut.width) )
            println( dut.UIntRes.toBits(dut.width))
        }

        def disSIntBits = {
            printf("% 10d\n", dut.SIntData1)
            printf("% 10d\n", dut.SIntData2)
            println("-------------------")
            printf("% 10d\n", dut.SIntRes)
            println(dut.SIntData1.toBits(dut.width) )
            println(dut.SIntRes.toBits(dut.width))
        }

        def disLogical = {
            printf("% 10d\n", dut.UIntData1)
            printf("% 10d\n", dut.UIntData2)
            println("-------------------")
            printf("% 10d\n", dut.UIntRes)
            println(dut.UIntData1.toBits(dut.width) )
            println(dut.UIntData2.toBits(dut.width))
            println("-------------------")
            println(dut.UIntRes.toBits(dut.width))
        }
    }
    SimConfig.withWave.compile(new alu(12)).doSim{dut=>
        for(i <- 0 until 100){
            dut.io.ALUop #= 4 //  scala.util.Random.nextInt(11)
            val op = dut.io.ALUop.toInt
            op match {
                // ALU_RAM
                case 0  => {
                    dut.init
                    println("---------------ALU_RAM------------------")
                    println(s"               *${i}*                  ")
                    dut.disUInt
                    if(dut.UIntData1 + dut.UIntData2 > BigInt(2).pow(dut.width) - 1){
                        println("overflow")
                    }else{
                        if(i != 0)
                            assert(dut.UIntData1 + dut.UIntData2 == dut.UIntRes)
                        else
                            println("")
                    }
                    println("-------------------------------------")
                }
                // ALU_ADD
                case 1  =>{
                    dut.init
                    println("---------------ALU_ADD------------------")
                    println(s"               *${i}*                  ")
                    dut.disSInt
                    if((dut.SIntData1> 0 &&  dut.SIntData2 > 0 && dut.SIntRes <= 0) || (dut.SIntData1 < 0 && dut.SIntData2 < 0 && dut.SIntRes >= 0)){
                        println("overflow")
                    }
                    else{
                        if(i != 0)
                            assert(dut.SIntData1 + dut.SIntData2 == dut.SIntRes)
                        else
                            println("")
                    }
                }
                // ALU_SUB
                case 10 =>{
                    dut.init
                    println("---------------ALU_SUB------------------")
                    println(s"               *${i}*                  ")
                    dut.disSInt
                    if((dut.SIntData1 >= 0 &&  dut.SIntData2 < 0 && dut.SIntRes <= 0) || (dut.SIntData1 < 0 && dut.SIntData2 > 0 && dut.SIntRes >= 0)){
                        println("overflow")
                    }
                    else{
                        if(i != 0)
                            assert(dut.SIntData1 - dut.SIntData2 == dut.SIntRes)
                        else
                            println("")
                    }
                }
                // ALU_SLT
                case 2  =>{
                    dut.init
                    println("---------------ALU_SLT------------------")
                    println(s"               *${i}*                  ")
                    dut.disSInt
                    assert(if(dut.SIntData1 < dut.SIntData2) dut.SIntRes == 1 else dut.SIntRes == 0)
                }
                // ALU_SLTU
                case 3  =>{
                    dut.init
                    println("---------------ALU_SLTU------------------")
                    println(s"               *${i}*                   ")
                    dut.disUInt
                    assert(if(dut.UIntData1 < dut.UIntData2) dut.SIntRes == 1 else dut.SIntRes == 0)
                }
                // ALU_SLL
                case 4  =>{
                    dut.initShift
//                    dut.io.data1 #= 1403
//                    dut.io.data2 #= 11
                    println("---------------ALU_SLL------------------")
                    println(s"               *${i}*                    ")
                    dut.disUIntBits
                    assert(dut.UIntData1.SLL(dut.width, dut.UIntData2.toInt)  == dut.UIntRes)
                }
                // ALU_SRL
                case 5  =>{
                    //dut.initShift
                    dut.io.data1 #= 1403
                    dut.io.data2 #= 11
                    println("---------------ALU_SRL------------------")
                    println(s"               *${i}*                    ")
                    dut.disUIntBits
                    assert((dut.UIntData1 >> dut.UIntData2.toInt) == dut.UIntRes)
                    // ">>" is designed for signed BigInt, but Bits.toBigInt is positive
                    // so we do not need to design a unsigned right shift for BigInt
                }
                // ALU_SRA
                case 6  =>{
                    dut.initShift
                    println("---------------ALU_SRA------------------")
                    println(s"               *${i}*                    ")
                    dut.disSIntBits
                    assert((dut.SIntData1 >> dut.UIntData2.toInt) == dut.SIntRes)
                }
                // ALU_XOR
                case 7  =>{
                    dut.init
                    println("---------------ALU_XOR------------------")
                    println(s"               *${i}*                    ")
                    dut.disLogical
                    assert((dut.UIntData1 ^ dut.UIntData2) == dut.UIntRes)
                }
                // ALU_OR
                case 8  =>{
                    dut.init
                    println("---------------ALU_OR------------------")
                    println(s"               *${i}*                    ")
                    dut.disLogical
                    assert((dut.UIntData1 | dut.UIntData2) == dut.UIntRes)
                }
                // ALU_AND
                case 9  =>{
                    dut.init
                    println("---------------ALU_AND------------------")
                    println(s"               *${i}*                    ")
                    dut.disLogical
                    assert((dut.UIntData1 & dut.UIntData2) == dut.UIntRes)
                }
                case _  => println("other")
            }
            sleep(1)
        }
    }
}