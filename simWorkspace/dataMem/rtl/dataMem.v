// Generator : SpinalHDL v1.4.0    git head : ecb5a80b713566f417ea3ea061f9969e73770a7f
// Date      : 16/07/2021, 23:31:47
// Component : singleCycle.dataMem



module singleCycle.dataMem (
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
  wire       [15:0]   content_0;
  wire       [15:0]   content_1;
  wire       [15:0]   content_2;
  wire       [15:0]   content_3;
  wire       [15:0]   content_4;
  wire       [15:0]   content_5;
  wire       [15:0]   content_6;
  wire       [15:0]   content_7;
  wire       [15:0]   content_8;
  wire       [15:0]   content_9;
  wire       [15:0]   content_10;
  wire       [15:0]   content_11;
  wire       [15:0]   content_12;
  wire       [15:0]   content_13;
  wire       [15:0]   content_14;
  wire       [15:0]   content_15;
  wire       [15:0]   content_16;
  wire       [15:0]   content_17;
  wire       [15:0]   content_18;
  wire       [15:0]   content_19;
  wire       [15:0]   content_20;
  wire       [15:0]   content_21;
  wire       [15:0]   content_22;
  wire       [15:0]   content_23;
  wire       [15:0]   content_24;
  wire       [15:0]   content_25;
  wire       [15:0]   content_26;
  wire       [15:0]   content_27;
  wire       [15:0]   content_28;
  wire       [15:0]   content_29;
  wire       [15:0]   content_30;
  wire       [15:0]   content_31;
  wire       [15:0]   content_32;
  wire       [15:0]   content_33;
  wire       [15:0]   content_34;
  wire       [15:0]   content_35;
  wire       [15:0]   content_36;
  wire       [15:0]   content_37;
  wire       [15:0]   content_38;
  wire       [15:0]   content_39;
  wire       [15:0]   content_40;
  wire       [15:0]   content_41;
  wire       [15:0]   content_42;
  wire       [15:0]   content_43;
  wire       [15:0]   content_44;
  wire       [15:0]   content_45;
  wire       [15:0]   content_46;
  wire       [15:0]   content_47;
  wire       [15:0]   content_48;
  wire       [15:0]   content_49;
  wire       [15:0]   content_50;
  wire       [15:0]   content_51;
  wire       [15:0]   content_52;
  wire       [15:0]   content_53;
  wire       [15:0]   content_54;
  wire       [15:0]   content_55;
  wire       [15:0]   content_56;
  wire       [15:0]   content_57;
  wire       [15:0]   content_58;
  wire       [15:0]   content_59;
  wire       [15:0]   content_60;
  wire       [15:0]   content_61;
  wire       [15:0]   content_62;
  wire       [15:0]   content_63;
  wire       [15:0]   content_64;
  wire       [15:0]   content_65;
  wire       [15:0]   content_66;
  wire       [15:0]   content_67;
  wire       [15:0]   content_68;
  wire       [15:0]   content_69;
  wire       [15:0]   content_70;
  wire       [15:0]   content_71;
  wire       [15:0]   content_72;
  wire       [15:0]   content_73;
  wire       [15:0]   content_74;
  wire       [15:0]   content_75;
  wire       [15:0]   content_76;
  wire       [15:0]   content_77;
  wire       [15:0]   content_78;
  wire       [15:0]   content_79;
  wire       [15:0]   content_80;
  wire       [15:0]   content_81;
  wire       [15:0]   content_82;
  wire       [15:0]   content_83;
  wire       [15:0]   content_84;
  wire       [15:0]   content_85;
  wire       [15:0]   content_86;
  wire       [15:0]   content_87;
  wire       [15:0]   content_88;
  wire       [15:0]   content_89;
  wire       [15:0]   content_90;
  wire       [15:0]   content_91;
  wire       [15:0]   content_92;
  wire       [15:0]   content_93;
  wire       [15:0]   content_94;
  wire       [15:0]   content_95;
  wire       [15:0]   content_96;
  wire       [15:0]   content_97;
  wire       [15:0]   content_98;
  wire       [15:0]   content_99;
  wire       [15:0]   content_100;
  wire       [15:0]   content_101;
  wire       [15:0]   content_102;
  wire       [15:0]   content_103;
  wire       [15:0]   content_104;
  wire       [15:0]   content_105;
  wire       [15:0]   content_106;
  wire       [15:0]   content_107;
  wire       [15:0]   content_108;
  wire       [15:0]   content_109;
  wire       [15:0]   content_110;
  wire       [15:0]   content_111;
  wire       [15:0]   content_112;
  wire       [15:0]   content_113;
  wire       [15:0]   content_114;
  wire       [15:0]   content_115;
  wire       [15:0]   content_116;
  wire       [15:0]   content_117;
  wire       [15:0]   content_118;
  wire       [15:0]   content_119;
  wire       [15:0]   content_120;
  wire       [15:0]   content_121;
  wire       [15:0]   content_122;
  wire       [15:0]   content_123;
  wire       [15:0]   content_124;
  wire       [15:0]   content_125;
  wire       [15:0]   content_126;
  wire       [15:0]   content_127;
  wire       [6:0]    _zz_1_;
  reg [15:0] mem [0:127];

  assign _zz_3_ = (address >>> 1);
  initial begin
    $readmemb("singleCycle.dataMem.v_toplevel_mem.bin",mem);
  end
  assign _zz_2_ = mem[_zz_1_];
  always @ (posedge clk) begin
    if(memWrite) begin
      mem[_zz_3_] <= writeData;
    end
  end

  assign content_0 = 16'h0;
  assign content_1 = 16'h0001;
  assign content_2 = 16'h0002;
  assign content_3 = 16'h0003;
  assign content_4 = 16'h0004;
  assign content_5 = 16'h0005;
  assign content_6 = 16'h0006;
  assign content_7 = 16'h0007;
  assign content_8 = 16'h0008;
  assign content_9 = 16'h0009;
  assign content_10 = 16'h000a;
  assign content_11 = 16'h000b;
  assign content_12 = 16'h000c;
  assign content_13 = 16'h000d;
  assign content_14 = 16'h000e;
  assign content_15 = 16'h000f;
  assign content_16 = 16'h0010;
  assign content_17 = 16'h0011;
  assign content_18 = 16'h0012;
  assign content_19 = 16'h0013;
  assign content_20 = 16'h0014;
  assign content_21 = 16'h0015;
  assign content_22 = 16'h0016;
  assign content_23 = 16'h0017;
  assign content_24 = 16'h0018;
  assign content_25 = 16'h0019;
  assign content_26 = 16'h001a;
  assign content_27 = 16'h001b;
  assign content_28 = 16'h001c;
  assign content_29 = 16'h001d;
  assign content_30 = 16'h001e;
  assign content_31 = 16'h001f;
  assign content_32 = 16'h0020;
  assign content_33 = 16'h0021;
  assign content_34 = 16'h0022;
  assign content_35 = 16'h0023;
  assign content_36 = 16'h0024;
  assign content_37 = 16'h0025;
  assign content_38 = 16'h0026;
  assign content_39 = 16'h0027;
  assign content_40 = 16'h0028;
  assign content_41 = 16'h0029;
  assign content_42 = 16'h002a;
  assign content_43 = 16'h002b;
  assign content_44 = 16'h002c;
  assign content_45 = 16'h002d;
  assign content_46 = 16'h002e;
  assign content_47 = 16'h002f;
  assign content_48 = 16'h0030;
  assign content_49 = 16'h0031;
  assign content_50 = 16'h0032;
  assign content_51 = 16'h0033;
  assign content_52 = 16'h0034;
  assign content_53 = 16'h0035;
  assign content_54 = 16'h0036;
  assign content_55 = 16'h0037;
  assign content_56 = 16'h0038;
  assign content_57 = 16'h0039;
  assign content_58 = 16'h003a;
  assign content_59 = 16'h003b;
  assign content_60 = 16'h003c;
  assign content_61 = 16'h003d;
  assign content_62 = 16'h003e;
  assign content_63 = 16'h003f;
  assign content_64 = 16'h0040;
  assign content_65 = 16'h0041;
  assign content_66 = 16'h0042;
  assign content_67 = 16'h0043;
  assign content_68 = 16'h0044;
  assign content_69 = 16'h0045;
  assign content_70 = 16'h0046;
  assign content_71 = 16'h0047;
  assign content_72 = 16'h0048;
  assign content_73 = 16'h0049;
  assign content_74 = 16'h004a;
  assign content_75 = 16'h004b;
  assign content_76 = 16'h004c;
  assign content_77 = 16'h004d;
  assign content_78 = 16'h004e;
  assign content_79 = 16'h004f;
  assign content_80 = 16'h0050;
  assign content_81 = 16'h0051;
  assign content_82 = 16'h0052;
  assign content_83 = 16'h0053;
  assign content_84 = 16'h0054;
  assign content_85 = 16'h0055;
  assign content_86 = 16'h0056;
  assign content_87 = 16'h0057;
  assign content_88 = 16'h0058;
  assign content_89 = 16'h0059;
  assign content_90 = 16'h005a;
  assign content_91 = 16'h005b;
  assign content_92 = 16'h005c;
  assign content_93 = 16'h005d;
  assign content_94 = 16'h005e;
  assign content_95 = 16'h005f;
  assign content_96 = 16'h0060;
  assign content_97 = 16'h0061;
  assign content_98 = 16'h0062;
  assign content_99 = 16'h0063;
  assign content_100 = 16'h0064;
  assign content_101 = 16'h0065;
  assign content_102 = 16'h0066;
  assign content_103 = 16'h0067;
  assign content_104 = 16'h0068;
  assign content_105 = 16'h0069;
  assign content_106 = 16'h006a;
  assign content_107 = 16'h006b;
  assign content_108 = 16'h006c;
  assign content_109 = 16'h006d;
  assign content_110 = 16'h006e;
  assign content_111 = 16'h006f;
  assign content_112 = 16'h0070;
  assign content_113 = 16'h0071;
  assign content_114 = 16'h0072;
  assign content_115 = 16'h0073;
  assign content_116 = 16'h0074;
  assign content_117 = 16'h0075;
  assign content_118 = 16'h0076;
  assign content_119 = 16'h0077;
  assign content_120 = 16'h0078;
  assign content_121 = 16'h0079;
  assign content_122 = 16'h007a;
  assign content_123 = 16'h007b;
  assign content_124 = 16'h007c;
  assign content_125 = 16'h007d;
  assign content_126 = 16'h007e;
  assign content_127 = 16'h007f;
  assign _zz_1_ = (address >>> 1);
  always @ (*) begin
    if(memRead)begin
      readData = _zz_2_;
    end else begin
      readData = 16'h0;
    end
  end


endmodule
