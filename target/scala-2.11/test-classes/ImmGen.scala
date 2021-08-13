package singleCycle

import spinal.core._
import spinal.core.sim._


object Riscv3264{
    def funct7Range = 31 downto 25
    def rdRange = 11 downto 7
    def funct3Range = 14 downto 12
    def rs1Range = 19 downto 15
    def rs2Range = 24 downto 20
    def rs3Range = 31 downto 27
    def csrRange = 31 downto 20
    def opCode = 6 downto 0

    case class IMM(instruction  : Bits) extends Area{
        // immediates
        def i = instruction(31 downto 20)
        def h = instruction(31 downto 24)
        def s = instruction(31 downto 25) ## instruction(11 downto 7)
        def b = instruction(31) ## instruction(7) ## instruction(30 downto 25) ## instruction(11 downto 8)
        def u = instruction(31 downto 12) ## U"x000"
        def j = instruction(31) ## instruction(19 downto 12) ## instruction(20) ## instruction(30 downto 21)
        def z = instruction(19 downto 15)

        // sign-extend immediates
        def i_sext = B((19 downto 0) -> i(11)) ## i
        def h_sext = B((23 downto 0) -> h(7))  ## h
        def s_sext = B((19 downto 0) -> s(11)) ## s
        def b_sext = B((18 downto 0) -> b(11)) ## b ## False
        def j_sext = B((10 downto 0) -> j(19)) ## j ## False
    }
    // R type
    def ADD                = M"0000000----------000-----0110011"
    def SUB                = M"0100000----------000-----0110011"
    def OR                 = M"0000000----------110-----0110011"
    def AND                = M"0000000----------111-----0110011"

    // I type
    def LD                 = M"-----------------011-----0000011"

    // S type
    def SD                 = M"-----------------111-----0100011"

    // SB type
    def BEQ                = M"-----------------000-----1100011"

}
case class ImmGen() extends Component{
    val io = new Bundle{
        val instruction = in Bits(32 bits)
        val immGenOut = out SInt(64 bits)
    }
    noIoPrefix()
    switch(io.instruction){
        is(Riscv3264.LD){
            io.immGenOut := Riscv3264.IMM(io.instruction).i.asSInt.resize(64)
        }
        is(Riscv3264.SD){
            io.immGenOut := Riscv3264.IMM(io.instruction).s.asSInt.resize(64)
        }
        is(Riscv3264.BEQ){
            io.immGenOut := Riscv3264.IMM(io.instruction).b.asSInt.resize(64)
        }
        default{
            io.immGenOut := 0
        }
    }
}

object ImmGenSim extends App{
    SimConfig.withWave.compile(new ImmGen()).doSim{dut=>
        dut.io.instruction #= BigInt("2857740803")
        sleep(1)
    }
}