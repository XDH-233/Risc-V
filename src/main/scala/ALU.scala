import spinal.core._
import spinal.sim._
import spinal.core.sim._
import spinal.lib._

case class ALU(width: Int) extends Component{
    val io = new Bundle{
        val ALUop = in Bits(2 bits)
        val funct7 = in Bits(7 bits)
        val funct3 = in Bits(3 bits)

        val data1 = in SInt(width bits)
        val data2 = in SInt(width bits)
        val Zero = out Bool()
        val Result = out SInt(width bits)
    }
    noIoPrefix()
    io.Zero := io.Result === 0
    val ALUCtrl = Bits(4 bits)
    val control = new Area{
        ALUCtrl := B"1111" // illegal
        when((io.ALUop === B"00" &&(io.funct3 === B"011" || io.funct3 === B"111")) || (io.ALUop === B"10" && io.funct7 === 0 && io.funct7 === 0) ){
            ALUCtrl := B"0010" //add
        }
        when(io.ALUop === B"01" ||(io.ALUop ===B"10" && io.funct7 === B"0100000" && io.funct3 === B"000")){
            ALUCtrl := B"0110" // sub
        }
        when(io.ALUop === B"10" && io.funct3 === B"111" && io.funct7 === 0){
            ALUCtrl := B"0000" //and
        }
        when(io.ALUop === B"10" && io.funct3 === B"110" && io.funct7 === 0){
            ALUCtrl := B"0001" // or
        }
    }

    // ALU
    switch(ALUCtrl){
        is(B"0000"){
            io.Result := io.data1 & io.data2
        }
        is(B"0001"){
            io.Result := io.data1 | io.data2
        }
        is(B"0010"){
            io.Result := io.data1 + io.data2
        }
        is(B"0110"){
            io.Result := io.data1 - io.data2
        }
        default{
            io.Result.clearAll()
        }
    }

    def toBinaryString(num: Int): String ={
        if(num < 0){
            return num.toBinaryString.substring(32 - width, 32)
        }
        else{
            return (("0" * (width - num.toBinaryString.length)) + num.toBinaryString)
        }
    }
}





object ALUsim extends App{
    SimConfig.withWave.compile(new ALU(8)).doSim{ dut=>
        for(i <- 1 to 10){
            dut.io.ALUop #= 0
            dut.io.data1.randomize()
            dut.io.data2.randomize()
            sleep(1)
            printf("add\t%-10d%-10d%-10d\n", dut.io.data1.toInt, dut.io.data2.toInt, dut.io.Result.toInt)
            sleep(1)  // add

            dut.io.ALUop #= 1
            dut.io.data1.randomize()
            dut.io.data2.randomize()
            sleep(1)
            printf("sub\t%-10d%-10d%-10d\n", dut.io.data1.toInt, dut.io.data2.toInt, dut.io.Result.toInt)
            sleep(1)   // sub

            dut.io.ALUop #= 2
            dut.io.funct7 #= 0
            dut.io.funct3 #= 0
            dut.io.data1.randomize()
            dut.io.data2.randomize()
            sleep(1)
            printf("add\t%-10d%-10d%-10d\n", dut.io.data1.toInt, dut.io.data2.toInt, dut.io.Result.toInt)
            sleep(1)  // add

            dut.io.ALUop #= 2
            dut.io.funct7 #= 32
            dut.io.funct3 #= 0
            dut.io.data1.randomize()
            dut.io.data2.randomize()
            sleep(1)
            printf("sub\t%-10d%-10d%-10d\n", dut.io.data1.toInt, dut.io.data2.toInt, dut.io.Result.toInt)
            sleep(1) // sub

            dut.io.ALUop #= 2
            dut.io.funct7 #= 0
            dut.io.funct3 #= 7
            dut.io.data1.randomize()
            dut.io.data2.randomize()
            sleep(1)
            printf("and\t%08d\n", dut.toBinaryString(dut.io.data1.toInt).toInt)
            printf("   \t%08d\n", dut.toBinaryString(dut.io.data2.toInt).toInt)
            printf("   \t%08d\n", dut.toBinaryString(dut.io.Result.toInt).toInt)
            printf("\n")
            sleep(1) // and

            dut.io.ALUop #= 2
            dut.io.funct7 #= 0
            dut.io.funct3 #= 6
            dut.io.data1.randomize()
            dut.io.data2.randomize()
            sleep(1)
            printf("or \t%08d\n", dut.toBinaryString(dut.io.data1.toInt).toInt)
            printf("   \t%08d\n", dut.toBinaryString(dut.io.data2.toInt).toInt)
            printf("   \t%08d\n", dut.toBinaryString(dut.io.Result.toInt).toInt)
            sleep(1) // or
            printf("------------------------------------\n")
        }

    }
}