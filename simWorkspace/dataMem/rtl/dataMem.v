// Generator : SpinalHDL v1.4.0    git head : ecb5a80b713566f417ea3ea061f9969e73770a7f
// Date      : 15/07/2021, 12:57:17
// Component : dataMem



module dataMem (
  input      [7:0]    address,
  input      [15:0]   writeData,
  output reg [15:0]   readData,
  input               memRead,
  input               memWrite,
  input               clk,
  input               reset 
);
  wire       [15:0]   _zz_2_;
  wire       [6:0]    _zz_3_;
  wire       [6:0]    _zz_1_;
  reg [15:0] mem [0:127];

  assign _zz_3_ = (address >>> 1);
  assign _zz_2_ = mem[_zz_1_];
  always @ (posedge clk) begin
    if(memWrite) begin
      mem[_zz_3_] <= writeData;
    end
  end

  assign _zz_1_ = (address >>> 1);
  always @ (*) begin
    if(memRead)begin
      readData = _zz_2_;
    end else begin
      readData = 16'h0;
    end
  end


endmodule
