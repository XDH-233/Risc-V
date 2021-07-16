import spinal.core._
import spinal.sim._
import spinal.core.sim._
import spinal.lib._

case class Control() extends Component {
    val io = new Bundle{
        val opCode = in Bits(7 bits)
        val Branch = out Bool()
        val MemRead = out Bool()
        val MemtoReg = out Bool()
        val ALUop = out Bits(2 bits)
        val MemWrite = out Bool()
        val ALUSrc = out Bool()
        val RegWrite = out Bool()
    }
    noIoPrefix()
    switch(io.opCode){
        // R type, add sub, and, or
        is(51){
            io.ALUSrc := False
            io.MemtoReg := False
            io.RegWrite := True
            io.MemRead := False
            io.MemWrite := False
            io.Branch := False
            io.ALUop := B"10"
        }

        // I type, ld
        is(3){
            io.ALUSrc := True
            io.MemtoReg := True
            io.RegWrite := True
            io.MemRead := True
            io.MemWrite := False
            io.Branch := False
            io.ALUop := B"00"
        }

        // S type, sd
        is(35){
            io.ALUSrc := True
            io.MemtoReg := False // x
            io.RegWrite := False
            io.MemRead := False
            io.MemWrite := True
            io.Branch := False
            io.ALUop := B"00"
        }

        // SB type, beq
        is(99){
            io.ALUSrc := False
            io.MemtoReg := False // x
            io.RegWrite := False
            io.MemRead := False
            io.MemWrite := False
            io.Branch := True
            io.ALUop := B"01"
        }
        default{   // any
            io.ALUSrc := False
            io.MemtoReg := False // x
            io.RegWrite := False
            io.MemRead := False
            io.MemWrite := False
            io.Branch := False
            io.ALUop := B"11"
        }
    }
}

object ControlRTL extends App{
    SpinalVerilog(new Control())
}

object ControlSim extends App{
    SimConfig.withWave.compile(new Control()).doSim{dut =>
        val arr = Array(51, 3, 35, 99)
        for(op <- arr){
            dut.io.opCode #= op
            sleep(1)
        }

    }
}