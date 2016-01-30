#pragma line 1 "./targeted_functions/numbers/targeted_function.c"
#pragma line 1 "./targeted_functions/numbers/targeted_function.c" 1
#pragma line 1 "<built-in>" 1
#pragma line 1 "<built-in>" 3
#pragma line 147 "<built-in>" 3
#pragma line 1 "<command line>" 1
#pragma empty_line
#pragma empty_line
#pragma empty_line
#pragma empty_line
#pragma empty_line
#pragma line 1 "E:/Xilinx_install_dir/15.4/Vivado_HLS/2015.4/common/technology/autopilot\\etc/autopilot_ssdm_op.h" 1
/* autopilot_ssdm_op.h*/
/*
#-  (c) Copyright 2011-2015 Xilinx, Inc. All rights reserved.
#-
#-  This file contains confidential and proprietary information
#-  of Xilinx, Inc. and is protected under U.S. and
#-  international copyright and other intellectual property
#-  laws.
#-
#-  DISCLAIMER
#-  This disclaimer is not a license and does not grant any
#-  rights to the materials distributed herewith. Except as
#-  otherwise provided in a valid license issued to you by
#-  Xilinx, and to the maximum extent permitted by applicable
#-  law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
#-  WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
#-  AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
#-  BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
#-  INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
#-  (2) Xilinx shall not be liable (whether in contract or tort,
#-  including negligence, or under any other theory of
#-  liability) for any loss or damage of any kind or nature
#-  related to, arising under or in connection with these
#-  materials, including for any direct, or any indirect,
#-  special, incidental, or consequential loss or damage
#-  (including loss of data, profits, goodwill, or any type of
#-  loss or damage suffered as a result of any action brought
#-  by a third party) even if such damage or loss was
#-  reasonably foreseeable or Xilinx had been advised of the
#-  possibility of the same.
#-
#-  CRITICAL APPLICATIONS
#-  Xilinx products are not designed or intended to be fail-
#-  safe, or for use in any application requiring fail-safe
#-  performance, such as life-support or safety devices or
#-  systems, Class III medical devices, nuclear facilities,
#-  applications related to the deployment of airbags, or any
#-  other applications that could lead to death, personal
#-  injury, or severe property or environmental damage
#-  (individually and collectively, "Critical
#-  Applications"). Customer assumes the sole risk and
#-  liability of any use of Xilinx products in Critical
#-  Applications, subject only to applicable laws and
#-  regulations governing limitations on product liability.
#-
#-  THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
#-  PART OF THIS FILE AT ALL TIMES. 
#- ************************************************************************
#pragma empty_line
 *
 * $Id$
 */
#pragma line 283 "E:/Xilinx_install_dir/15.4/Vivado_HLS/2015.4/common/technology/autopilot\\etc/autopilot_ssdm_op.h"
/*#define AP_SPEC_ATTR __attribute__ ((pure))*/
#pragma empty_line
#pragma empty_line
#pragma empty_line
    /****** SSDM Intrinsics: OPERATIONS ***/
    // Interface operations
    //typedef unsigned int __attribute__ ((bitwidth(1))) _uint1_;
    void _ssdm_op_IfRead() __attribute__ ((nothrow));
    void _ssdm_op_IfWrite() __attribute__ ((nothrow));
    //_uint1_ _ssdm_op_IfNbRead() SSDM_OP_ATTR;
    //_uint1_ _ssdm_op_IfNbWrite() SSDM_OP_ATTR;
    //_uint1_ _ssdm_op_IfCanRead() SSDM_OP_ATTR;
    //_uint1_ _ssdm_op_IfCanWrite() SSDM_OP_ATTR;
#pragma empty_line
    // Stream Intrinsics
    void _ssdm_StreamRead() __attribute__ ((nothrow));
    void _ssdm_StreamWrite() __attribute__ ((nothrow));
    //_uint1_  _ssdm_StreamNbRead() SSDM_OP_ATTR;
    //_uint1_  _ssdm_StreamNbWrite() SSDM_OP_ATTR;
    //_uint1_  _ssdm_StreamCanRead() SSDM_OP_ATTR;
    //_uint1_  _ssdm_StreamCanWrite() SSDM_OP_ATTR;
#pragma empty_line
    // Misc
    void _ssdm_op_MemShiftRead() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_op_Wait() __attribute__ ((nothrow));
    void _ssdm_op_Poll() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_op_Return() __attribute__ ((nothrow));
#pragma empty_line
    /* SSDM Intrinsics: SPECIFICATIONS */
    void _ssdm_op_SpecSynModule() __attribute__ ((nothrow));
    void _ssdm_op_SpecTopModule() __attribute__ ((nothrow));
    void _ssdm_op_SpecProcessDecl() __attribute__ ((nothrow));
    void _ssdm_op_SpecProcessDef() __attribute__ ((nothrow));
    void _ssdm_op_SpecPort() __attribute__ ((nothrow));
    void _ssdm_op_SpecConnection() __attribute__ ((nothrow));
    void _ssdm_op_SpecChannel() __attribute__ ((nothrow));
    void _ssdm_op_SpecSensitive() __attribute__ ((nothrow));
    void _ssdm_op_SpecModuleInst() __attribute__ ((nothrow));
    void _ssdm_op_SpecPortMap() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_op_SpecReset() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_op_SpecPlatform() __attribute__ ((nothrow));
    void _ssdm_op_SpecClockDomain() __attribute__ ((nothrow));
    void _ssdm_op_SpecPowerDomain() __attribute__ ((nothrow));
#pragma empty_line
    int _ssdm_op_SpecRegionBegin() __attribute__ ((nothrow));
    int _ssdm_op_SpecRegionEnd() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_op_SpecLoopName() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_op_SpecLoopTripCount() __attribute__ ((nothrow));
#pragma empty_line
    int _ssdm_op_SpecStateBegin() __attribute__ ((nothrow));
    int _ssdm_op_SpecStateEnd() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_op_SpecInterface() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_op_SpecPipeline() __attribute__ ((nothrow));
    void _ssdm_op_SpecDataflowPipeline() __attribute__ ((nothrow));
#pragma empty_line
#pragma empty_line
    void _ssdm_op_SpecLatency() __attribute__ ((nothrow));
    void _ssdm_op_SpecParallel() __attribute__ ((nothrow));
    void _ssdm_op_SpecProtocol() __attribute__ ((nothrow));
    void _ssdm_op_SpecOccurrence() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_op_SpecResource() __attribute__ ((nothrow));
    void _ssdm_op_SpecResourceLimit() __attribute__ ((nothrow));
    void _ssdm_op_SpecCHCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecFUCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecIFCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecIPCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecKeepValue() __attribute__ ((nothrow));
    void _ssdm_op_SpecMemCore() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_op_SpecExt() __attribute__ ((nothrow));
    /*void* _ssdm_op_SpecProcess() SSDM_SPEC_ATTR;
    void* _ssdm_op_SpecEdge() SSDM_SPEC_ATTR; */
#pragma empty_line
    /* Presynthesis directive functions */
    void _ssdm_SpecArrayDimSize() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_RegionBegin() __attribute__ ((nothrow));
    void _ssdm_RegionEnd() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_Unroll() __attribute__ ((nothrow));
    void _ssdm_UnrollRegion() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_InlineAll() __attribute__ ((nothrow));
    void _ssdm_InlineLoop() __attribute__ ((nothrow));
    void _ssdm_Inline() __attribute__ ((nothrow));
    void _ssdm_InlineSelf() __attribute__ ((nothrow));
    void _ssdm_InlineRegion() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_SpecArrayMap() __attribute__ ((nothrow));
    void _ssdm_SpecArrayPartition() __attribute__ ((nothrow));
    void _ssdm_SpecArrayReshape() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_SpecStream() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_SpecExpr() __attribute__ ((nothrow));
    void _ssdm_SpecExprBalance() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_SpecDependence() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_SpecLoopMerge() __attribute__ ((nothrow));
    void _ssdm_SpecLoopFlatten() __attribute__ ((nothrow));
    void _ssdm_SpecLoopRewind() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_SpecFuncInstantiation() __attribute__ ((nothrow));
    void _ssdm_SpecFuncBuffer() __attribute__ ((nothrow));
    void _ssdm_SpecFuncExtract() __attribute__ ((nothrow));
    void _ssdm_SpecConstant() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_DataPack() __attribute__ ((nothrow));
    void _ssdm_SpecDataPack() __attribute__ ((nothrow));
#pragma empty_line
    void _ssdm_op_SpecBitsMap() __attribute__ ((nothrow));
    void _ssdm_op_SpecLicense() __attribute__ ((nothrow));
#pragma empty_line
#pragma empty_line
/*#define _ssdm_op_WaitUntil(X) while (!(X)) _ssdm_op_Wait(1);
#define _ssdm_op_Delayed(X) X */
#pragma line 7 "<command line>" 2
#pragma line 1 "<built-in>" 2
#pragma line 1 "./targeted_functions/numbers/targeted_function.c" 2
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *																																						*
 * 											Bi-Semestrial Student Project (2014 – 2015)												*
 * 											Parallel Systems Laboratory																	*
 * 											Electrical Engineering Department															*
 * 											Technion – Israel Institute of Technology													*
 *																																						*
 * Title:									Hardware DLL																						*
 * Subject:								Real Time Partial Reconfiguration Management of FPGA by OS					*
 *																																						*
 * Author:								Alon Reznik																							*
 * Supervisor:							Oz Shmueli																							*
 *																																						*
 * File Name:							./targeted_functions/numbers/targeted_function.c										*
 * Last Update:						01/12/2015																							*
 *																																						*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#pragma empty_line
#pragma empty_line
#pragma empty_line
/**
 * output_*:							*.
 */
int targeted_function (int* output_000, int* output_001, int* output_002, int* output_003, int* output_004, int* output_005, int* output_006, int* output_007, int* output_008, int* output_009, int* output_010, int* output_011, int* output_012, int* output_013, int* output_014, int* output_015, int* output_016, int* output_017, int* output_018, int* output_019, int* output_020, int* output_021, int* output_022, int* output_023, int* output_024, int* output_025, int* output_026, int* output_027, int* output_028, int* output_029, int* output_030, int* output_031, int* output_032, int* output_033, int* output_034, int* output_035, int* output_036, int* output_037, int* output_038, int* output_039, int* output_040, int* output_041, int* output_042, int* output_043, int* output_044, int* output_045, int* output_046, int* output_047, int* output_048, int* output_049, int* output_050, int* output_051, int* output_052, int* output_053, int* output_054, int* output_055, int* output_056, int* output_057, int* output_058, int* output_059, int* output_060, int* output_061, int* output_062, int* output_063, int* output_064, int* output_065, int* output_066, int* output_067, int* output_068, int* output_069, int* output_070, int* output_071, int* output_072, int* output_073, int* output_074, int* output_075, int* output_076, int* output_077, int* output_078, int* output_079, int* output_080, int* output_081, int* output_082, int* output_083, int* output_084, int* output_085, int* output_086, int* output_087, int* output_088, int* output_089, int* output_090, int* output_091, int* output_092, int* output_093, int* output_094, int* output_095, int* output_096, int* output_097, int* output_098, int* output_099, int* output_100, int* output_101, int* output_102, int* output_103, int* output_104, int* output_105, int* output_106, int* output_107, int* output_108, int* output_109, int* output_110, int* output_111, int* output_112, int* output_113, int* output_114, int* output_115, int* output_116, int* output_117, int* output_118, int* output_119, int* output_120, int* output_121, int* output_122, int* output_123, int* output_124, int* output_125, int* output_126, int* output_127, int* output_128, int* output_129, int* output_130, int* output_131, int* output_132, int* output_133, int* output_134, int* output_135, int* output_136, int* output_137, int* output_138, int* output_139, int* output_140, int* output_141, int* output_142, int* output_143, int* output_144, int* output_145, int* output_146, int* output_147, int* output_148, int* output_149, int* output_150, int* output_151, int* output_152, int* output_153, int* output_154, int* output_155, int* output_156, int* output_157, int* output_158, int* output_159, int* output_160, int* output_161, int* output_162, int* output_163, int* output_164, int* output_165, int* output_166, int* output_167, int* output_168, int* output_169, int* output_170, int* output_171, int* output_172, int* output_173, int* output_174, int* output_175, int* output_176, int* output_177, int* output_178, int* output_179, int* output_180, int* output_181, int* output_182, int* output_183, int* output_184, int* output_185, int* output_186, int* output_187, int* output_188, int* output_189, int* output_190, int* output_191, int* output_192, int* output_193, int* output_194, int* output_195, int* output_196, int* output_197, int* output_198, int* output_199, int* output_200, int* output_201, int* output_202, int* output_203, int* output_204, int* output_205, int* output_206, int* output_207, int* output_208, int* output_209, int* output_210, int* output_211, int* output_212, int* output_213, int* output_214, int* output_215, int* output_216, int* output_217, int* output_218, int* output_219, int* output_220, int* output_221, int* output_222, int* output_223, int* output_224, int* output_225, int* output_226, int* output_227, int* output_228, int* output_229, int* output_230, int* output_231, int* output_232, int* output_233, int* output_234, int* output_235, int* output_236, int* output_237, int* output_238, int* output_239, int* output_240, int* output_241, int* output_242, int* output_243, int* output_244, int* output_245, int* output_246, int* output_247, int* output_248, int* output_249, int* output_250, int* output_251, int* output_252, int* output_253, int* output_254, int* output_255)
{
 *output_000 = 0;
 *output_001 = 1;
 *output_002 = 2;
 *output_003 = 3;
 *output_004 = 4;
 *output_005 = 5;
 *output_006 = 6;
 *output_007 = 7;
 *output_008 = 8;
 *output_009 = 9;
 *output_010 = 10;
 *output_011 = 11;
 *output_012 = 12;
 *output_013 = 13;
 *output_014 = 14;
 *output_015 = 15;
 *output_016 = 16;
 *output_017 = 17;
 *output_018 = 18;
 *output_019 = 19;
 *output_020 = 20;
 *output_021 = 21;
 *output_022 = 22;
 *output_023 = 23;
 *output_024 = 24;
 *output_025 = 25;
 *output_026 = 26;
 *output_027 = 27;
 *output_028 = 28;
 *output_029 = 29;
 *output_030 = 30;
 *output_031 = 31;
 *output_032 = 32;
 *output_033 = 33;
 *output_034 = 34;
 *output_035 = 35;
 *output_036 = 36;
 *output_037 = 37;
 *output_038 = 38;
 *output_039 = 39;
 *output_040 = 40;
 *output_041 = 41;
 *output_042 = 42;
 *output_043 = 43;
 *output_044 = 44;
 *output_045 = 45;
 *output_046 = 46;
 *output_047 = 47;
 *output_048 = 48;
 *output_049 = 49;
 *output_050 = 50;
 *output_051 = 51;
 *output_052 = 52;
 *output_053 = 53;
 *output_054 = 54;
 *output_055 = 55;
 *output_056 = 56;
 *output_057 = 57;
 *output_058 = 58;
 *output_059 = 59;
 *output_060 = 60;
 *output_061 = 61;
 *output_062 = 62;
 *output_063 = 63;
 *output_064 = 64;
 *output_065 = 65;
 *output_066 = 66;
 *output_067 = 67;
 *output_068 = 68;
 *output_069 = 69;
 *output_070 = 70;
 *output_071 = 71;
 *output_072 = 72;
 *output_073 = 73;
 *output_074 = 74;
 *output_075 = 75;
 *output_076 = 76;
 *output_077 = 77;
 *output_078 = 78;
 *output_079 = 79;
 *output_080 = 80;
 *output_081 = 81;
 *output_082 = 82;
 *output_083 = 83;
 *output_084 = 84;
 *output_085 = 85;
 *output_086 = 86;
 *output_087 = 87;
 *output_088 = 88;
 *output_089 = 89;
 *output_090 = 90;
 *output_091 = 91;
 *output_092 = 92;
 *output_093 = 93;
 *output_094 = 94;
 *output_095 = 95;
 *output_096 = 96;
 *output_097 = 97;
 *output_098 = 98;
 *output_099 = 99;
 *output_100 = 100;
 *output_101 = 101;
 *output_102 = 102;
 *output_103 = 103;
 *output_104 = 104;
 *output_105 = 105;
 *output_106 = 106;
 *output_107 = 107;
 *output_108 = 108;
 *output_109 = 109;
 *output_110 = 110;
 *output_111 = 111;
 *output_112 = 112;
 *output_113 = 113;
 *output_114 = 114;
 *output_115 = 115;
 *output_116 = 116;
 *output_117 = 117;
 *output_118 = 118;
 *output_119 = 119;
 *output_120 = 120;
 *output_121 = 121;
 *output_122 = 122;
 *output_123 = 123;
 *output_124 = 124;
 *output_125 = 125;
 *output_126 = 126;
 *output_127 = 127;
 *output_128 = 128;
 *output_129 = 129;
 *output_130 = 130;
 *output_131 = 131;
 *output_132 = 132;
 *output_133 = 133;
 *output_134 = 134;
 *output_135 = 135;
 *output_136 = 136;
 *output_137 = 137;
 *output_138 = 138;
 *output_139 = 139;
 *output_140 = 140;
 *output_141 = 141;
 *output_142 = 142;
 *output_143 = 143;
 *output_144 = 144;
 *output_145 = 145;
 *output_146 = 146;
 *output_147 = 147;
 *output_148 = 148;
 *output_149 = 149;
 *output_150 = 150;
 *output_151 = 151;
 *output_152 = 152;
 *output_153 = 153;
 *output_154 = 154;
 *output_155 = 155;
 *output_156 = 156;
 *output_157 = 157;
 *output_158 = 158;
 *output_159 = 159;
 *output_160 = 160;
 *output_161 = 161;
 *output_162 = 162;
 *output_163 = 163;
 *output_164 = 164;
 *output_165 = 165;
 *output_166 = 166;
 *output_167 = 167;
 *output_168 = 168;
 *output_169 = 169;
 *output_170 = 170;
 *output_171 = 171;
 *output_172 = 172;
 *output_173 = 173;
 *output_174 = 174;
 *output_175 = 175;
 *output_176 = 176;
 *output_177 = 177;
 *output_178 = 178;
 *output_179 = 179;
 *output_180 = 180;
 *output_181 = 181;
 *output_182 = 182;
 *output_183 = 183;
 *output_184 = 184;
 *output_185 = 185;
 *output_186 = 186;
 *output_187 = 187;
 *output_188 = 188;
 *output_189 = 189;
 *output_190 = 190;
 *output_191 = 191;
 *output_192 = 192;
 *output_193 = 193;
 *output_194 = 194;
 *output_195 = 195;
 *output_196 = 196;
 *output_197 = 197;
 *output_198 = 198;
 *output_199 = 199;
 *output_200 = 200;
 *output_201 = 201;
 *output_202 = 202;
 *output_203 = 203;
 *output_204 = 204;
 *output_205 = 205;
 *output_206 = 206;
 *output_207 = 207;
 *output_208 = 208;
 *output_209 = 209;
 *output_210 = 210;
 *output_211 = 211;
 *output_212 = 212;
 *output_213 = 213;
 *output_214 = 214;
 *output_215 = 215;
 *output_216 = 216;
 *output_217 = 217;
 *output_218 = 218;
 *output_219 = 219;
 *output_220 = 220;
 *output_221 = 221;
 *output_222 = 222;
 *output_223 = 223;
 *output_224 = 224;
 *output_225 = 225;
 *output_226 = 226;
 *output_227 = 227;
 *output_228 = 228;
 *output_229 = 229;
 *output_230 = 230;
 *output_231 = 231;
 *output_232 = 232;
 *output_233 = 233;
 *output_234 = 234;
 *output_235 = 235;
 *output_236 = 236;
 *output_237 = 237;
 *output_238 = 238;
 *output_239 = 239;
 *output_240 = 240;
 *output_241 = 241;
 *output_242 = 242;
 *output_243 = 243;
 *output_244 = 244;
 *output_245 = 245;
 *output_246 = 246;
 *output_247 = 247;
 *output_248 = 248;
 *output_249 = 249;
 *output_250 = 250;
 *output_251 = 251;
 *output_252 = 252;
 *output_253 = 253;
 *output_254 = 254;
 *output_255 = 255;
 return 0;
}
