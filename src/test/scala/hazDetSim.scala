import pipeline.hazardDet

import spinal.core._
import spinal.sim._
import spinal.core.sim._
import spinal.lib._

object hazardDetSim extends App{
    SimConfig.withWave.compile(new hazardDet()).doSim{dut=>
        for(i <- 0 until 100){
            dut.io.branch         #= false
            dut.io.ex2memRd       #= 2
            dut.io.ex2memRegWrite #= true
            dut.io.id2exMemRead   #= true
            dut.io.id2exRd        #= 3
            dut.io.id2exRegWrite  #= true
            dut.io.if2idRs2       #= 3
            dut.io.if2idRs1       #= 2
            sleep(1)
        }
    }
}