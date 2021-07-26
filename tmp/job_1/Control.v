// Generator : SpinalHDL v1.4.0    git head : ecb5a80b713566f417ea3ea061f9969e73770a7f
// Date      : 13/07/2021, 15:00:01
// Component : singleCycle.Control



module singleCycle.Control (
  input      [6:0]    opCode,
  output reg          Branch,
  output reg          MemRead,
  output reg          MemtoReg,
  output reg [1:0]    ALUop,
  output reg          MemWrite,
  output reg          ALUSrc,
  output reg          RegWrite 
);

  always @ (*) begin
    case(opCode)
      7'b0110011 : begin
        ALUSrc = 1'b0;
      end
      7'b0000011 : begin
        ALUSrc = 1'b1;
      end
      7'b0100011 : begin
        ALUSrc = 1'b1;
      end
      7'b1100011 : begin
        ALUSrc = 1'b0;
      end
      default : begin
        ALUSrc = 1'b0;
      end
    endcase
  end

  always @ (*) begin
    case(opCode)
      7'b0110011 : begin
        MemtoReg = 1'b0;
      end
      7'b0000011 : begin
        MemtoReg = 1'b1;
      end
      7'b0100011 : begin
        MemtoReg = 1'b0;
      end
      7'b1100011 : begin
        MemtoReg = 1'b0;
      end
      default : begin
        MemtoReg = 1'b0;
      end
    endcase
  end

  always @ (*) begin
    case(opCode)
      7'b0110011 : begin
        RegWrite = 1'b1;
      end
      7'b0000011 : begin
        RegWrite = 1'b1;
      end
      7'b0100011 : begin
        RegWrite = 1'b0;
      end
      7'b1100011 : begin
        RegWrite = 1'b0;
      end
      default : begin
        RegWrite = 1'b0;
      end
    endcase
  end

  always @ (*) begin
    case(opCode)
      7'b0110011 : begin
        MemRead = 1'b0;
      end
      7'b0000011 : begin
        MemRead = 1'b1;
      end
      7'b0100011 : begin
        MemRead = 1'b0;
      end
      7'b1100011 : begin
        MemRead = 1'b0;
      end
      default : begin
        MemRead = 1'b0;
      end
    endcase
  end

  always @ (*) begin
    case(opCode)
      7'b0110011 : begin
        MemWrite = 1'b0;
      end
      7'b0000011 : begin
        MemWrite = 1'b0;
      end
      7'b0100011 : begin
        MemWrite = 1'b1;
      end
      7'b1100011 : begin
        MemWrite = 1'b0;
      end
      default : begin
        MemWrite = 1'b0;
      end
    endcase
  end

  always @ (*) begin
    case(opCode)
      7'b0110011 : begin
        Branch = 1'b0;
      end
      7'b0000011 : begin
        Branch = 1'b0;
      end
      7'b0100011 : begin
        Branch = 1'b0;
      end
      7'b1100011 : begin
        Branch = 1'b1;
      end
      default : begin
        Branch = 1'b0;
      end
    endcase
  end

  always @ (*) begin
    case(opCode)
      7'b0110011 : begin
        ALUop = (2'b10);
      end
      7'b0000011 : begin
        ALUop = (2'b00);
      end
      7'b0100011 : begin
        ALUop = (2'b00);
      end
      7'b1100011 : begin
        ALUop = (2'b01);
      end
      default : begin
        ALUop = (2'b11);
      end
    endcase
  end


endmodule
