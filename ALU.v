// Generator : SpinalHDL v1.4.0    git head : ecb5a80b713566f417ea3ea061f9969e73770a7f
// Date      : 12/07/2021, 23:10:45
// Component : ALU



module ALU (
  input      [63:0]   data1,
  input      [63:0]   data2,
  input      [3:0]    ALUCtrl,
  output              Zero,
  output reg [63:0]   Result 
);
  wire       [63:0]   _zz_1_;

  assign _zz_1_ = 64'h0;
  assign Zero = ($signed(Result) == $signed(_zz_1_));
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
        Result = 64'h0;
      end
    endcase
  end


endmodule
