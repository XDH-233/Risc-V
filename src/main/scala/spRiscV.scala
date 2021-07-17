import spinal.core._
import spinal.sim._
import spinal.core.sim._
import spinal.lib._


class spRiscV(depthOfInst: Int, depthOfData: Int) extends Component{

    noIoPrefix()
    //---------------------- component------------------------------------------
    val PC = Reg(UInt(log2Up(depthOfInst * 4) bits)) init(0)
    val instructionMem = instMem(32, depthOfInst)
    val control = Control()
    val regFile = RF(64)
    val immGen= ImmGen()
    val dataMemory = dataMem(64, depthOfData)
    val ALU_ = ALU(64)

    // --------------------- connect --------------------
    //instruction mem i
    instructionMem.io.address := PC
    // control i
    control.io.opCode := instructionMem.io.instruction(Riscv3264.opCode)
    // reg file i
    regFile.io.readReg1 := instructionMem.io.instruction(Riscv3264.rs1Range).asUInt
    regFile.io.readReg2 := instructionMem.io.instruction(Riscv3264.rs2Range).asUInt
    regFile.io.writeReg := instructionMem.io.instruction(Riscv3264.rdRange).asUInt
    regFile.io.writeData := Mux(sel = control.io.MemtoReg, whenTrue = dataMemory.io.readData.asSInt, whenFalse = ALU_.io.Result)
    regFile.io.RegWrite := control.io.RegWrite
    // immGen i
    immGen.io.instruction := instructionMem.io.instruction
    // ALU in
    ALU_.io.data1 := regFile.io.readData1
    ALU_.io.data2 := Mux(sel = control.io.ALUSrc, whenTrue = immGen.io.immGenOut,whenFalse = regFile.io.readData2)
    ALU_.io.ALUop := control.io.ALUop
    ALU_.io.funct3 := instructionMem.io.instruction(Riscv3264.funct3Range)
    ALU_.io.funct7 := instructionMem.io.instruction(Riscv3264.funct7Range)
    // dataMem i
    dataMemory.io.address := ALU_.io.Result.asUInt.resized
    dataMemory.io.writeData := regFile.io.readData2.asBits
    dataMemory.io.memRead := control.io.MemRead
    dataMemory.io.memWrite := control.io.MemWrite

    // PC i
    PC := Mux(sel = control.io.Branch & ALU_.io.Zero, whenTrue = (immGen.io.immGenOut |<< U"1" + PC).asUInt.resized, whenFalse = PC + 4 )

}

object spRiscVRTL extends App{
    SpinalConfig(
        defaultConfigForClockDomains = ClockDomainConfig(resetKind = SYNC, resetActiveLevel = HIGH)
    ).generateVerilog(new spRiscV(128, 128))
}

object spRiscVSim extends App{
    SimConfig.withWave.withConfig(SpinalConfig(
        defaultConfigForClockDomains = ClockDomainConfig(resetKind = SYNC, resetActiveLevel = HIGH),
        defaultClockDomainFrequency = FixedFrequency(100 MHz)
    )).compile(new spRiscV(128, 128)).doSim { dut =>
        dut.clockDomain.forkStimulus(10000)
        dut.clockDomain.waitSampling(100)
    }
}

