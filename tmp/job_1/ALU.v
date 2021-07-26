// Generator : SpinalHDL v1.4.0    git head : ecb5a80b713566f417ea3ea061f9969e73770a7f
// Date      : 13/07/2021, 19:57:08
// Component : singleCycle.ALU



module singleCycle.ALU (
  input      [1:0]    ALUop,
  input      [6:0]    funct7,
  input      [2:0]    funct3,
  input      [7:0]    data1,
  input      [7:0]    data2,
  output              Zero,
  output reg [7:0]    Result 
);
  wire       [7:0]    _zz_1_;
  reg        [3:0]    ALUCtrl;

  assign _zz_1_ = 8'h0;
  assign Zero = ($signed(Result) == $signed(_zz_1_));
  always @ (*) begin
    ALUCtrl = (4'b1111);
    if(((ALUop == (2'b00)) || (((ALUop == (2'b10)) && (funct7 == 7'h0)) && (funct7 == 7'h0))))begin
      ALUCtrl = (4'b0010);
    end
    if(((ALUop == (2'b01)) || (((ALUop == (2'b10)) && (funct7 == 7'h20)) && (funct3 == (3'b000)))))begin
      ALUCtrl = (4'b0110);
    end
    if((((ALUop == (2'b10)) && (funct3 == (3'b111))) && (funct7 == 7'h0)))begin
      ALUCtrl = (4'b0000);
    end
    if((((ALUop == (2'b10)) && (funct3 == (3'b110))) && (funct7 == 7'h0)))begin
      ALUCtrl = (4'b0001);
    end
  end

  always @ (*) begin
    case(ALUCtrl)
      4'b0000 : begin
        Result = (data1 & data2);
      end
      4'b0001 : begin
        Result = (data1 | data2);
      end
      4'b0010 : begin
        Result = ($signed(data1) + $signed(data2));
      end
      4'b0110 : begin
        Result = ($signed(data1) - $signed(data2));
      end
      default : begin
        Result = 8'h0;
      end
    endcase
  end


endmodule
