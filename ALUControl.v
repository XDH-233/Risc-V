// Generator : SpinalHDL v1.4.0    git head : ecb5a80b713566f417ea3ea061f9969e73770a7f
// Date      : 13/07/2021, 09:19:32
// Component : ALUControl



module ALUControl (
  input      [1:0]    ALUop,
  input      [6:0]    funct7,
  input      [2:0]    funct3,
  output reg [3:0]    ALUCtrl 
);

  always @ (*) begin
    ALUCtrl = (4'b1111);
    if(((ALUop == (2'b00)) || (((ALUop == (2'b10)) && (funct7 == 7'h0)) && (funct7 == 7'h0))))begin
      ALUCtrl = (4'b0010);
    end
    if(((ALUop == (2'b01)) || (((ALUop == (2'b10)) && (funct7 == 7'h20)) && (funct3 == (3'b000)))))begin
      ALUCtrl = (4'b0110);
    end
    if((((ALUop == (2'b10)) && (funct3 == (3'b110))) && (funct7 == 7'h0)))begin
      ALUCtrl = (4'b0001);
    end
  end


endmodule
