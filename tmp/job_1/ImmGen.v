// Generator : SpinalHDL v1.4.0    git head : ecb5a80b713566f417ea3ea061f9969e73770a7f
// Date      : 13/07/2021, 23:56:24
// Component : singleCycle.ImmGen



module singleCycle.ImmGen (
  input      [31:0]   io_instruction,
  output reg [63:0]   io_immGenOut 
);
  wire       [11:0]   _zz_1_;
  wire       [11:0]   _zz_2_;
  wire       [11:0]   _zz_3_;

  assign _zz_1_ = io_instruction[31 : 20];
  assign _zz_2_ = {io_instruction[31 : 25],io_instruction[11 : 7]};
  assign _zz_3_ = {{{io_instruction[31],io_instruction[7]},io_instruction[30 : 25]},io_instruction[11 : 8]};
  always @ (*) begin
    if((((io_instruction & 32'h0000007f) == 32'h00000003))) begin
        io_immGenOut = {{52{_zz_1_[11]}}, _zz_1_};
    end else if((((io_instruction & 32'h0000007f) == 32'h00000023))) begin
        io_immGenOut = {{52{_zz_2_[11]}}, _zz_2_};
    end else if((((io_instruction & 32'h0000007f) == 32'h00000063))) begin
        io_immGenOut = {{52{_zz_3_[11]}}, _zz_3_};
    end else begin
        io_immGenOut = 64'h0;
    end
  end


endmodule
