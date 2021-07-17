// Generator : SpinalHDL v1.4.0    git head : ecb5a80b713566f417ea3ea061f9969e73770a7f
// Date      : 16/07/2021, 23:06:34
// Component : RF



module RF (
  input      [4:0]    readReg1,
  input      [4:0]    readReg2,
  input      [4:0]    writeReg,
  input      [15:0]   writeData,
  output     [15:0]   readData1,
  output     [15:0]   readData2,
  input               RegWrite,
  input               clk,
  input               reset 
);
  reg        [15:0]   _zz_2_;
  reg        [15:0]   _zz_3_;
  reg        [15:0]   regs_0;
  reg        [15:0]   regs_1;
  reg        [15:0]   regs_2;
  reg        [15:0]   regs_3;
  reg        [15:0]   regs_4;
  reg        [15:0]   regs_5;
  reg        [15:0]   regs_6;
  reg        [15:0]   regs_7;
  reg        [15:0]   regs_8;
  reg        [15:0]   regs_9;
  reg        [15:0]   regs_10;
  reg        [15:0]   regs_11;
  reg        [15:0]   regs_12;
  reg        [15:0]   regs_13;
  reg        [15:0]   regs_14;
  reg        [15:0]   regs_15;
  reg        [15:0]   regs_16;
  reg        [15:0]   regs_17;
  reg        [15:0]   regs_18;
  reg        [15:0]   regs_19;
  reg        [15:0]   regs_20;
  reg        [15:0]   regs_21;
  reg        [15:0]   regs_22;
  reg        [15:0]   regs_23;
  reg        [15:0]   regs_24;
  reg        [15:0]   regs_25;
  reg        [15:0]   regs_26;
  reg        [15:0]   regs_27;
  reg        [15:0]   regs_28;
  reg        [15:0]   regs_29;
  reg        [15:0]   regs_30;
  reg        [15:0]   regs_31;
  wire       [31:0]   _zz_1_;

  always @(*) begin
    case(readReg1)
      5'b00000 : begin
        _zz_2_ = regs_0;
      end
      5'b00001 : begin
        _zz_2_ = regs_1;
      end
      5'b00010 : begin
        _zz_2_ = regs_2;
      end
      5'b00011 : begin
        _zz_2_ = regs_3;
      end
      5'b00100 : begin
        _zz_2_ = regs_4;
      end
      5'b00101 : begin
        _zz_2_ = regs_5;
      end
      5'b00110 : begin
        _zz_2_ = regs_6;
      end
      5'b00111 : begin
        _zz_2_ = regs_7;
      end
      5'b01000 : begin
        _zz_2_ = regs_8;
      end
      5'b01001 : begin
        _zz_2_ = regs_9;
      end
      5'b01010 : begin
        _zz_2_ = regs_10;
      end
      5'b01011 : begin
        _zz_2_ = regs_11;
      end
      5'b01100 : begin
        _zz_2_ = regs_12;
      end
      5'b01101 : begin
        _zz_2_ = regs_13;
      end
      5'b01110 : begin
        _zz_2_ = regs_14;
      end
      5'b01111 : begin
        _zz_2_ = regs_15;
      end
      5'b10000 : begin
        _zz_2_ = regs_16;
      end
      5'b10001 : begin
        _zz_2_ = regs_17;
      end
      5'b10010 : begin
        _zz_2_ = regs_18;
      end
      5'b10011 : begin
        _zz_2_ = regs_19;
      end
      5'b10100 : begin
        _zz_2_ = regs_20;
      end
      5'b10101 : begin
        _zz_2_ = regs_21;
      end
      5'b10110 : begin
        _zz_2_ = regs_22;
      end
      5'b10111 : begin
        _zz_2_ = regs_23;
      end
      5'b11000 : begin
        _zz_2_ = regs_24;
      end
      5'b11001 : begin
        _zz_2_ = regs_25;
      end
      5'b11010 : begin
        _zz_2_ = regs_26;
      end
      5'b11011 : begin
        _zz_2_ = regs_27;
      end
      5'b11100 : begin
        _zz_2_ = regs_28;
      end
      5'b11101 : begin
        _zz_2_ = regs_29;
      end
      5'b11110 : begin
        _zz_2_ = regs_30;
      end
      default : begin
        _zz_2_ = regs_31;
      end
    endcase
  end

  always @(*) begin
    case(readReg2)
      5'b00000 : begin
        _zz_3_ = regs_0;
      end
      5'b00001 : begin
        _zz_3_ = regs_1;
      end
      5'b00010 : begin
        _zz_3_ = regs_2;
      end
      5'b00011 : begin
        _zz_3_ = regs_3;
      end
      5'b00100 : begin
        _zz_3_ = regs_4;
      end
      5'b00101 : begin
        _zz_3_ = regs_5;
      end
      5'b00110 : begin
        _zz_3_ = regs_6;
      end
      5'b00111 : begin
        _zz_3_ = regs_7;
      end
      5'b01000 : begin
        _zz_3_ = regs_8;
      end
      5'b01001 : begin
        _zz_3_ = regs_9;
      end
      5'b01010 : begin
        _zz_3_ = regs_10;
      end
      5'b01011 : begin
        _zz_3_ = regs_11;
      end
      5'b01100 : begin
        _zz_3_ = regs_12;
      end
      5'b01101 : begin
        _zz_3_ = regs_13;
      end
      5'b01110 : begin
        _zz_3_ = regs_14;
      end
      5'b01111 : begin
        _zz_3_ = regs_15;
      end
      5'b10000 : begin
        _zz_3_ = regs_16;
      end
      5'b10001 : begin
        _zz_3_ = regs_17;
      end
      5'b10010 : begin
        _zz_3_ = regs_18;
      end
      5'b10011 : begin
        _zz_3_ = regs_19;
      end
      5'b10100 : begin
        _zz_3_ = regs_20;
      end
      5'b10101 : begin
        _zz_3_ = regs_21;
      end
      5'b10110 : begin
        _zz_3_ = regs_22;
      end
      5'b10111 : begin
        _zz_3_ = regs_23;
      end
      5'b11000 : begin
        _zz_3_ = regs_24;
      end
      5'b11001 : begin
        _zz_3_ = regs_25;
      end
      5'b11010 : begin
        _zz_3_ = regs_26;
      end
      5'b11011 : begin
        _zz_3_ = regs_27;
      end
      5'b11100 : begin
        _zz_3_ = regs_28;
      end
      5'b11101 : begin
        _zz_3_ = regs_29;
      end
      5'b11110 : begin
        _zz_3_ = regs_30;
      end
      default : begin
        _zz_3_ = regs_31;
      end
    endcase
  end

  assign _zz_1_ = ({31'd0,(1'b1)} <<< writeReg);
  assign readData1 = _zz_2_;
  assign readData2 = _zz_3_;
  always @ (posedge clk) begin
    if(reset) begin
      regs_0 <= 16'h0;
      regs_1 <= 16'h0;
      regs_2 <= 16'h0;
      regs_3 <= 16'h0;
      regs_4 <= 16'h0;
      regs_5 <= 16'h0;
      regs_6 <= 16'h0;
      regs_7 <= 16'h0;
      regs_8 <= 16'h0;
      regs_9 <= 16'h0;
      regs_10 <= 16'h0;
      regs_11 <= 16'h0;
      regs_12 <= 16'h0;
      regs_13 <= 16'h0;
      regs_14 <= 16'h0;
      regs_15 <= 16'h0;
      regs_16 <= 16'h0;
      regs_17 <= 16'h0;
      regs_18 <= 16'h0;
      regs_19 <= 16'h0;
      regs_20 <= 16'h0;
      regs_21 <= 16'h0;
      regs_22 <= 16'h0;
      regs_23 <= 16'h0;
      regs_24 <= 16'h0;
      regs_25 <= 16'h0;
      regs_26 <= 16'h0;
      regs_27 <= 16'h0;
      regs_28 <= 16'h0;
      regs_29 <= 16'h0;
      regs_30 <= 16'h0;
      regs_31 <= 16'h0;
    end else begin
      if(RegWrite)begin
        if(_zz_1_[0])begin
          regs_0 <= writeData;
        end
        if(_zz_1_[1])begin
          regs_1 <= writeData;
        end
        if(_zz_1_[2])begin
          regs_2 <= writeData;
        end
        if(_zz_1_[3])begin
          regs_3 <= writeData;
        end
        if(_zz_1_[4])begin
          regs_4 <= writeData;
        end
        if(_zz_1_[5])begin
          regs_5 <= writeData;
        end
        if(_zz_1_[6])begin
          regs_6 <= writeData;
        end
        if(_zz_1_[7])begin
          regs_7 <= writeData;
        end
        if(_zz_1_[8])begin
          regs_8 <= writeData;
        end
        if(_zz_1_[9])begin
          regs_9 <= writeData;
        end
        if(_zz_1_[10])begin
          regs_10 <= writeData;
        end
        if(_zz_1_[11])begin
          regs_11 <= writeData;
        end
        if(_zz_1_[12])begin
          regs_12 <= writeData;
        end
        if(_zz_1_[13])begin
          regs_13 <= writeData;
        end
        if(_zz_1_[14])begin
          regs_14 <= writeData;
        end
        if(_zz_1_[15])begin
          regs_15 <= writeData;
        end
        if(_zz_1_[16])begin
          regs_16 <= writeData;
        end
        if(_zz_1_[17])begin
          regs_17 <= writeData;
        end
        if(_zz_1_[18])begin
          regs_18 <= writeData;
        end
        if(_zz_1_[19])begin
          regs_19 <= writeData;
        end
        if(_zz_1_[20])begin
          regs_20 <= writeData;
        end
        if(_zz_1_[21])begin
          regs_21 <= writeData;
        end
        if(_zz_1_[22])begin
          regs_22 <= writeData;
        end
        if(_zz_1_[23])begin
          regs_23 <= writeData;
        end
        if(_zz_1_[24])begin
          regs_24 <= writeData;
        end
        if(_zz_1_[25])begin
          regs_25 <= writeData;
        end
        if(_zz_1_[26])begin
          regs_26 <= writeData;
        end
        if(_zz_1_[27])begin
          regs_27 <= writeData;
        end
        if(_zz_1_[28])begin
          regs_28 <= writeData;
        end
        if(_zz_1_[29])begin
          regs_29 <= writeData;
        end
        if(_zz_1_[30])begin
          regs_30 <= writeData;
        end
        if(_zz_1_[31])begin
          regs_31 <= writeData;
        end
      end
    end
  end


endmodule
