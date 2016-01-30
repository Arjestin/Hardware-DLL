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
 * File Name:							test.c																										*
 * Last Update:						24/01/2016																							*
 *																																						*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include "hwdll.h"
#include "test.h"



/************************************************************************************************************************	*/
/*                                                             Macro Definitions                                                             	*/
/************************************************************************************************************************	*/

/**
 * TEST_ASSERT						Evaluates an expression.
 *
 * If the expression is false:		Writes a detailed error message to the dump file.
 * 											If given, destroys the Hardware DLL data structure.
 * 											Returns a negative Boolean.
 */
#define TEST_ASSERT(expression)\
	if (!(expression))\
	{\
		dump = fopen (DUMP_FILE, "a");\
		fprintf (dump, "\t\t\tFailed test function: %s. Line: %d. Assertion: %s.\n\n", __FUNCTION__, __LINE__, #expression);\
		fclose (dump);\
		hwdll_destroy ();\
		return false;\
	}

/**
 * TEST_RUN							Calls a test function.
 *
 * If the test function passes:	Writes a confirmation message to the standard output stream.
 * If the test function fails:		Writes the dump file's content to the standard output stream.
 */
#define TEST_RUN(function)\
	printf ("#\tRunning %-40s", #function":");\
	if (!function ())\
	{\
		printf ("[FAILED]\t\t\t\t#\n");\
		failed = true;\
	}\
	else\
	{\
		printf ("[  OK  ]\t\t\t\t#\n");\
	}



/************************************************************************************************************************	*/
/*                                                             Targeted Functions                                                            	*/
/************************************************************************************************************************	*/

int dummy (int* output_000, int* output_001, int* output_002, int* output_003, int* output_004, int* output_005, int* output_006, int* output_007, int* output_008, int* output_009, int* output_010, int* output_011, int* output_012, int* output_013, int* output_014, int* output_015, int* output_016, int* output_017, int* output_018, int* output_019, int* output_020, int* output_021, int* output_022, int* output_023, int* output_024, int* output_025, int* output_026, int* output_027, int* output_028, int* output_029, int* output_030, int* output_031, int* output_032, int* output_033, int* output_034, int* output_035, int* output_036, int* output_037, int* output_038, int* output_039, int* output_040, int* output_041, int* output_042, int* output_043, int* output_044, int* output_045, int* output_046, int* output_047, int* output_048, int* output_049, int* output_050, int* output_051, int* output_052, int* output_053, int* output_054, int* output_055, int* output_056, int* output_057, int* output_058, int* output_059, int* output_060, int* output_061, int* output_062, int* output_063, int* output_064, int* output_065, int* output_066, int* output_067, int* output_068, int* output_069, int* output_070, int* output_071, int* output_072, int* output_073, int* output_074, int* output_075, int* output_076, int* output_077, int* output_078, int* output_079, int* output_080, int* output_081, int* output_082, int* output_083, int* output_084, int* output_085, int* output_086, int* output_087, int* output_088, int* output_089, int* output_090, int* output_091, int* output_092, int* output_093, int* output_094, int* output_095, int* output_096, int* output_097, int* output_098, int* output_099, int* output_100, int* output_101, int* output_102, int* output_103, int* output_104, int* output_105, int* output_106, int* output_107, int* output_108, int* output_109, int* output_110, int* output_111, int* output_112, int* output_113, int* output_114, int* output_115, int* output_116, int* output_117, int* output_118, int* output_119, int* output_120, int* output_121, int* output_122, int* output_123, int* output_124, int* output_125, int* output_126, int* output_127, int* output_128, int* output_129, int* output_130, int* output_131, int* output_132, int* output_133, int* output_134, int* output_135, int* output_136, int* output_137, int* output_138, int* output_139, int* output_140, int* output_141, int* output_142, int* output_143, int* output_144, int* output_145, int* output_146, int* output_147, int* output_148, int* output_149, int* output_150, int* output_151, int* output_152, int* output_153, int* output_154, int* output_155, int* output_156, int* output_157, int* output_158, int* output_159, int* output_160, int* output_161, int* output_162, int* output_163, int* output_164, int* output_165, int* output_166, int* output_167, int* output_168, int* output_169, int* output_170, int* output_171, int* output_172, int* output_173, int* output_174, int* output_175, int* output_176, int* output_177, int* output_178, int* output_179, int* output_180, int* output_181, int* output_182, int* output_183, int* output_184, int* output_185, int* output_186, int* output_187, int* output_188, int* output_189, int* output_190, int* output_191, int* output_192, int* output_193, int* output_194, int* output_195, int* output_196, int* output_197, int* output_198, int* output_199, int* output_200, int* output_201, int* output_202, int* output_203, int* output_204, int* output_205, int* output_206, int* output_207, int* output_208, int* output_209, int* output_210, int* output_211, int* output_212, int* output_213, int* output_214, int* output_215, int* output_216, int* output_217, int* output_218, int* output_219, int* output_220, int* output_221, int* output_222, int* output_223, int* output_224, int* output_225, int* output_226, int* output_227, int* output_228, int* output_229, int* output_230, int* output_231, int* output_232, int* output_233, int* output_234, int* output_235, int* output_236, int* output_237, int* output_238, int* output_239, int* output_240, int* output_241, int* output_242, int* output_243, int* output_244, int* output_245, int* output_246, int* output_247, int* output_248, int* output_249, int* output_250, int* output_251, int* output_252, int* output_253, int* output_254, int* output_255)
{
	*output_000 = 0;
	*output_001 = 0;
	*output_002 = 0;
	*output_003 = 0;
	*output_004 = 0;
	*output_005 = 0;
	*output_006 = 0;
	*output_007 = 0;
	*output_008 = 0;
	*output_009 = 0;
	*output_010 = 0;
	*output_011 = 0;
	*output_012 = 0;
	*output_013 = 0;
	*output_014 = 0;
	*output_015 = 0;
	*output_016 = 0;
	*output_017 = 0;
	*output_018 = 0;
	*output_019 = 0;
	*output_020 = 0;
	*output_021 = 0;
	*output_022 = 0;
	*output_023 = 0;
	*output_024 = 0;
	*output_025 = 0;
	*output_026 = 0;
	*output_027 = 0;
	*output_028 = 0;
	*output_029 = 0;
	*output_030 = 0;
	*output_031 = 0;
	*output_032 = 0;
	*output_033 = 0;
	*output_034 = 0;
	*output_035 = 0;
	*output_036 = 0;
	*output_037 = 0;
	*output_038 = 0;
	*output_039 = 0;
	*output_040 = 0;
	*output_041 = 0;
	*output_042 = 0;
	*output_043 = 0;
	*output_044 = 0;
	*output_045 = 0;
	*output_046 = 0;
	*output_047 = 0;
	*output_048 = 0;
	*output_049 = 0;
	*output_050 = 0;
	*output_051 = 0;
	*output_052 = 0;
	*output_053 = 0;
	*output_054 = 0;
	*output_055 = 0;
	*output_056 = 0;
	*output_057 = 0;
	*output_058 = 0;
	*output_059 = 0;
	*output_060 = 0;
	*output_061 = 0;
	*output_062 = 0;
	*output_063 = 0;
	*output_064 = 0;
	*output_065 = 0;
	*output_066 = 0;
	*output_067 = 0;
	*output_068 = 0;
	*output_069 = 0;
	*output_070 = 0;
	*output_071 = 0;
	*output_072 = 0;
	*output_073 = 0;
	*output_074 = 0;
	*output_075 = 0;
	*output_076 = 0;
	*output_077 = 0;
	*output_078 = 0;
	*output_079 = 0;
	*output_080 = 0;
	*output_081 = 0;
	*output_082 = 0;
	*output_083 = 0;
	*output_084 = 0;
	*output_085 = 0;
	*output_086 = 0;
	*output_087 = 0;
	*output_088 = 0;
	*output_089 = 0;
	*output_090 = 0;
	*output_091 = 0;
	*output_092 = 0;
	*output_093 = 0;
	*output_094 = 0;
	*output_095 = 0;
	*output_096 = 0;
	*output_097 = 0;
	*output_098 = 0;
	*output_099 = 0;
	*output_100 = 0;
	*output_101 = 0;
	*output_102 = 0;
	*output_103 = 0;
	*output_104 = 0;
	*output_105 = 0;
	*output_106 = 0;
	*output_107 = 0;
	*output_108 = 0;
	*output_109 = 0;
	*output_110 = 0;
	*output_111 = 0;
	*output_112 = 0;
	*output_113 = 0;
	*output_114 = 0;
	*output_115 = 0;
	*output_116 = 0;
	*output_117 = 0;
	*output_118 = 0;
	*output_119 = 0;
	*output_120 = 0;
	*output_121 = 0;
	*output_122 = 0;
	*output_123 = 0;
	*output_124 = 0;
	*output_125 = 0;
	*output_126 = 0;
	*output_127 = 0;
	*output_128 = 0;
	*output_129 = 0;
	*output_130 = 0;
	*output_131 = 0;
	*output_132 = 0;
	*output_133 = 0;
	*output_134 = 0;
	*output_135 = 0;
	*output_136 = 0;
	*output_137 = 0;
	*output_138 = 0;
	*output_139 = 0;
	*output_140 = 0;
	*output_141 = 0;
	*output_142 = 0;
	*output_143 = 0;
	*output_144 = 0;
	*output_145 = 0;
	*output_146 = 0;
	*output_147 = 0;
	*output_148 = 0;
	*output_149 = 0;
	*output_150 = 0;
	*output_151 = 0;
	*output_152 = 0;
	*output_153 = 0;
	*output_154 = 0;
	*output_155 = 0;
	*output_156 = 0;
	*output_157 = 0;
	*output_158 = 0;
	*output_159 = 0;
	*output_160 = 0;
	*output_161 = 0;
	*output_162 = 0;
	*output_163 = 0;
	*output_164 = 0;
	*output_165 = 0;
	*output_166 = 0;
	*output_167 = 0;
	*output_168 = 0;
	*output_169 = 0;
	*output_170 = 0;
	*output_171 = 0;
	*output_172 = 0;
	*output_173 = 0;
	*output_174 = 0;
	*output_175 = 0;
	*output_176 = 0;
	*output_177 = 0;
	*output_178 = 0;
	*output_179 = 0;
	*output_180 = 0;
	*output_181 = 0;
	*output_182 = 0;
	*output_183 = 0;
	*output_184 = 0;
	*output_185 = 0;
	*output_186 = 0;
	*output_187 = 0;
	*output_188 = 0;
	*output_189 = 0;
	*output_190 = 0;
	*output_191 = 0;
	*output_192 = 0;
	*output_193 = 0;
	*output_194 = 0;
	*output_195 = 0;
	*output_196 = 0;
	*output_197 = 0;
	*output_198 = 0;
	*output_199 = 0;
	*output_200 = 0;
	*output_201 = 0;
	*output_202 = 0;
	*output_203 = 0;
	*output_204 = 0;
	*output_205 = 0;
	*output_206 = 0;
	*output_207 = 0;
	*output_208 = 0;
	*output_209 = 0;
	*output_210 = 0;
	*output_211 = 0;
	*output_212 = 0;
	*output_213 = 0;
	*output_214 = 0;
	*output_215 = 0;
	*output_216 = 0;
	*output_217 = 0;
	*output_218 = 0;
	*output_219 = 0;
	*output_220 = 0;
	*output_221 = 0;
	*output_222 = 0;
	*output_223 = 0;
	*output_224 = 0;
	*output_225 = 0;
	*output_226 = 0;
	*output_227 = 0;
	*output_228 = 0;
	*output_229 = 0;
	*output_230 = 0;
	*output_231 = 0;
	*output_232 = 0;
	*output_233 = 0;
	*output_234 = 0;
	*output_235 = 0;
	*output_236 = 0;
	*output_237 = 0;
	*output_238 = 0;
	*output_239 = 0;
	*output_240 = 0;
	*output_241 = 0;
	*output_242 = 0;
	*output_243 = 0;
	*output_244 = 0;
	*output_245 = 0;
	*output_246 = 0;
	*output_247 = 0;
	*output_248 = 0;
	*output_249 = 0;
	*output_250 = 0;
	*output_251 = 0;
	*output_252 = 0;
	*output_253 = 0;
	*output_254 = 0;
	*output_255 = 0;
	return 0;
}

int numbers (int* output_000, int* output_001, int* output_002, int* output_003, int* output_004, int* output_005, int* output_006, int* output_007, int* output_008, int* output_009, int* output_010, int* output_011, int* output_012, int* output_013, int* output_014, int* output_015, int* output_016, int* output_017, int* output_018, int* output_019, int* output_020, int* output_021, int* output_022, int* output_023, int* output_024, int* output_025, int* output_026, int* output_027, int* output_028, int* output_029, int* output_030, int* output_031, int* output_032, int* output_033, int* output_034, int* output_035, int* output_036, int* output_037, int* output_038, int* output_039, int* output_040, int* output_041, int* output_042, int* output_043, int* output_044, int* output_045, int* output_046, int* output_047, int* output_048, int* output_049, int* output_050, int* output_051, int* output_052, int* output_053, int* output_054, int* output_055, int* output_056, int* output_057, int* output_058, int* output_059, int* output_060, int* output_061, int* output_062, int* output_063, int* output_064, int* output_065, int* output_066, int* output_067, int* output_068, int* output_069, int* output_070, int* output_071, int* output_072, int* output_073, int* output_074, int* output_075, int* output_076, int* output_077, int* output_078, int* output_079, int* output_080, int* output_081, int* output_082, int* output_083, int* output_084, int* output_085, int* output_086, int* output_087, int* output_088, int* output_089, int* output_090, int* output_091, int* output_092, int* output_093, int* output_094, int* output_095, int* output_096, int* output_097, int* output_098, int* output_099, int* output_100, int* output_101, int* output_102, int* output_103, int* output_104, int* output_105, int* output_106, int* output_107, int* output_108, int* output_109, int* output_110, int* output_111, int* output_112, int* output_113, int* output_114, int* output_115, int* output_116, int* output_117, int* output_118, int* output_119, int* output_120, int* output_121, int* output_122, int* output_123, int* output_124, int* output_125, int* output_126, int* output_127, int* output_128, int* output_129, int* output_130, int* output_131, int* output_132, int* output_133, int* output_134, int* output_135, int* output_136, int* output_137, int* output_138, int* output_139, int* output_140, int* output_141, int* output_142, int* output_143, int* output_144, int* output_145, int* output_146, int* output_147, int* output_148, int* output_149, int* output_150, int* output_151, int* output_152, int* output_153, int* output_154, int* output_155, int* output_156, int* output_157, int* output_158, int* output_159, int* output_160, int* output_161, int* output_162, int* output_163, int* output_164, int* output_165, int* output_166, int* output_167, int* output_168, int* output_169, int* output_170, int* output_171, int* output_172, int* output_173, int* output_174, int* output_175, int* output_176, int* output_177, int* output_178, int* output_179, int* output_180, int* output_181, int* output_182, int* output_183, int* output_184, int* output_185, int* output_186, int* output_187, int* output_188, int* output_189, int* output_190, int* output_191, int* output_192, int* output_193, int* output_194, int* output_195, int* output_196, int* output_197, int* output_198, int* output_199, int* output_200, int* output_201, int* output_202, int* output_203, int* output_204, int* output_205, int* output_206, int* output_207, int* output_208, int* output_209, int* output_210, int* output_211, int* output_212, int* output_213, int* output_214, int* output_215, int* output_216, int* output_217, int* output_218, int* output_219, int* output_220, int* output_221, int* output_222, int* output_223, int* output_224, int* output_225, int* output_226, int* output_227, int* output_228, int* output_229, int* output_230, int* output_231, int* output_232, int* output_233, int* output_234, int* output_235, int* output_236, int* output_237, int* output_238, int* output_239, int* output_240, int* output_241, int* output_242, int* output_243, int* output_244, int* output_245, int* output_246, int* output_247, int* output_248, int* output_249, int* output_250, int* output_251, int* output_252, int* output_253, int* output_254, int* output_255)
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

int int_max (int* output_000)
{
	*output_000 = INT_MAX;
	return 0;
}

int adder_subtractor (int input_000, int input_001, int* output_000, int* output_001)
{
	*output_000 = input_000 + input_001;
	*output_001 = input_000 - input_001 < 0 ? input_001 - input_000 : input_000 - input_001;
	return 0;
}

int multiplier (int input_000, int input_001, int* output_000)
{
	*output_000 = input_000 * input_001;
	return 0;
}

int factorial (int input_000, int* output_000)
{
	int i = 0;
	if (input_000 < 0 || input_000 > 12)
	{
		*output_000 = -1;
		return -1;
	}
	*output_000 = 1;
	for (i = 2; i <= input_000; i++)
	{
		*output_000 *= i;
	}
	return 0;
}

int bitwise_right_shift (int input_000, int* output_000)
{
	*output_000 = input_000 >> 1;
	return 0;
}

int gcd (int input_000, int input_001, int* output_000)
{
	if (input_000 == 0 && input_001 == 0)
	{
		*output_000 = -1;
		return -1;
	}
	if (input_000 == 0)
	{
		*output_000 = input_001 < 0 ? -input_001 : input_001;
		return 0;
	}
	while (input_001 != 0)
	{
		*output_000 = input_000;
		input_000 = input_001;
		input_001 = *output_000 % input_001;
	}
	*output_000 = input_000 < 0 ? -input_000 : input_000;
	return 0;
}

int fibonacci (int input_000, int* output_000)
{
	int i = 0, first = 0, second = 1;
	if (input_000 < 0 || input_000 > 46)
	{
		*output_000 = -1;
		return -1;
	}
	if (input_000 < 2)
	{
		*output_000 = input_000;
		return 0;
	}
	for (i = 1; i < input_000; i++)
	{
		*output_000 = first + second;
		first = second;
		second = *output_000;
	}
	return 0;
}

int prime (int input_000, int* output_000)
{
	int i = 0, j = 0, ctr = 3;
	if (input_000 < 1 || input_000 > 105097565)
	{
		*output_000 = -1;
		return -1;
	}
	*output_000 = 2;
	for (i = 2; i <= input_000;)
	{
		for (j = 2; j <= ctr - 1; j++)
		{
			if (ctr % j == 0)
			{
				break;
			}
		}
		if (ctr == j)
		{
			*output_000 = ctr;
			i++;
		}
		ctr++;
	}
	return 0;
}

int prime_neighbours (int input_000, int* output_000, int* output_001)
{
	int i = 0, flag_0 = 0, flag_1 = 0, retval = 0;
	*output_000 = input_000;
	*output_001 = input_000;
	if (input_000 < 2)
	{
		*output_000 = -1;
		*output_001 = 2;
		flag_0 = 1;
		flag_1 = 1;
		retval = -1;
	}
	if (input_000 == 2)
	{
		*output_000 = -1;
		*output_001 = 3;
		flag_0 = 1;
		flag_1 = 1;
		retval = -1;
	}
	if (input_000 == INT_MAX)
	{
		*output_001 = -1;
		flag_1 = 1;
		retval = -1;
	}
	while (flag_0 != 1)
	{
		--*output_000;
		flag_0 = 1;
		for (i = 2; i <= *output_000 / 2; i++)
		{
			if (*output_000 % i == 0)
			{
				flag_0 = 0;
				break;
			}
		}
	}
	while (flag_1 != 1)
	{
		++*output_001;
		flag_1 = 1;
		for (i = 2; i <= *output_001 / 2; i++)
		{
			if (*output_001 % i == 0)
			{
				flag_1 = 0;
				break;
			}
		}
	}
	return retval;
}



/************************************************************************************************************************	*/
/*                                                                Test Functions                                                                	*/
/************************************************************************************************************************	*/

bool test_sys (void)
{
	FILE* dump = NULL;
	int* ptr = NULL;
	int int_min = -pow (2, 31);
	int int_max = pow (2, 31) - 1;
	TEST_ASSERT (CHAR_BIT == 8);
	TEST_ASSERT (CHAR_BIT * sizeof (*ptr) == 32);
	TEST_ASSERT (CHAR_BIT * sizeof (ptr) == 32);
	TEST_ASSERT (INT_MIN == -2147483647 - 1);
	TEST_ASSERT (INT_MIN == int_min);
	TEST_ASSERT (INT_MAX == 2147483647);
	TEST_ASSERT (INT_MAX == int_max);
	return true;
}

bool test_bram (void)
{
	FILE* dump = NULL;
	TEST_ASSERT (!hwdll_create ());
	int mem_fd = -1;
	int page_size = 0, page_addr = 0, page_offset = 0;
	void* mem = MAP_FAILED;
	mem_fd = open (MEM_FILE, O_RDWR);
	TEST_ASSERT (mem_fd > -1);
	page_size = sysconf (_SC_PAGESIZE);
	TEST_ASSERT (page_size == 4 * KILOBYTE);
	page_addr = (BRAM_OFFSET & (~(page_size - 1)));
	TEST_ASSERT (page_addr == 0x70002000);
	page_offset = BRAM_OFFSET - page_addr;
	TEST_ASSERT (page_offset == 0x0);
	mem = mmap (NULL, page_size, PROT_READ | PROT_WRITE, MAP_SHARED, mem_fd, page_addr);
	TEST_ASSERT (mem != MAP_FAILED);
	*(volatile int*) (mem + page_offset) = 0;
	TEST_ASSERT (*(volatile int*) (mem + page_offset) == 0);
	*(volatile int*) (mem + page_offset) = BRAM_NUM;
	TEST_ASSERT (*(volatile int*) (mem + page_offset) == BRAM_NUM);
	munmap (mem, page_size);
	close (mem_fd);
	hwdll_destroy ();
	return true;
}

bool test_mono (void)
{
	FILE* dump = NULL;
	hwdll_create ();
	int sw_retval = -2, hw_retval = -2;
	int sw_out_list[256] = {-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2};
	int hw_out_list[256] = {-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2};
	int idx = hwdll_load (0);
	TEST_ASSERT (idx == 0);
	sw_retval = dummy (&sw_out_list[0], &sw_out_list[1], &sw_out_list[2], &sw_out_list[3], &sw_out_list[4], &sw_out_list[5], &sw_out_list[6], &sw_out_list[7], &sw_out_list[8], &sw_out_list[9], &sw_out_list[10], &sw_out_list[11], &sw_out_list[12], &sw_out_list[13], &sw_out_list[14], &sw_out_list[15], &sw_out_list[16], &sw_out_list[17], &sw_out_list[18], &sw_out_list[19], &sw_out_list[20], &sw_out_list[21], &sw_out_list[22], &sw_out_list[23], &sw_out_list[24], &sw_out_list[25], &sw_out_list[26], &sw_out_list[27], &sw_out_list[28], &sw_out_list[29], &sw_out_list[30], &sw_out_list[31], &sw_out_list[32], &sw_out_list[33], &sw_out_list[34], &sw_out_list[35], &sw_out_list[36], &sw_out_list[37], &sw_out_list[38], &sw_out_list[39], &sw_out_list[40], &sw_out_list[41], &sw_out_list[42], &sw_out_list[43], &sw_out_list[44], &sw_out_list[45], &sw_out_list[46], &sw_out_list[47], &sw_out_list[48], &sw_out_list[49], &sw_out_list[50], &sw_out_list[51], &sw_out_list[52], &sw_out_list[53], &sw_out_list[54], &sw_out_list[55], &sw_out_list[56], &sw_out_list[57], &sw_out_list[58], &sw_out_list[59], &sw_out_list[60], &sw_out_list[61], &sw_out_list[62], &sw_out_list[63], &sw_out_list[64], &sw_out_list[65], &sw_out_list[66], &sw_out_list[67], &sw_out_list[68], &sw_out_list[69], &sw_out_list[70], &sw_out_list[71], &sw_out_list[72], &sw_out_list[73], &sw_out_list[74], &sw_out_list[75], &sw_out_list[76], &sw_out_list[77], &sw_out_list[78], &sw_out_list[79], &sw_out_list[80], &sw_out_list[81], &sw_out_list[82], &sw_out_list[83], &sw_out_list[84], &sw_out_list[85], &sw_out_list[86], &sw_out_list[87], &sw_out_list[88], &sw_out_list[89], &sw_out_list[90], &sw_out_list[91], &sw_out_list[92], &sw_out_list[93], &sw_out_list[94], &sw_out_list[95], &sw_out_list[96], &sw_out_list[97], &sw_out_list[98], &sw_out_list[99], &sw_out_list[100], &sw_out_list[101], &sw_out_list[102], &sw_out_list[103], &sw_out_list[104], &sw_out_list[105], &sw_out_list[106], &sw_out_list[107], &sw_out_list[108], &sw_out_list[109], &sw_out_list[110], &sw_out_list[111], &sw_out_list[112], &sw_out_list[113], &sw_out_list[114], &sw_out_list[115], &sw_out_list[116], &sw_out_list[117], &sw_out_list[118], &sw_out_list[119], &sw_out_list[120], &sw_out_list[121], &sw_out_list[122], &sw_out_list[123], &sw_out_list[124], &sw_out_list[125], &sw_out_list[126], &sw_out_list[127], &sw_out_list[128], &sw_out_list[129], &sw_out_list[130], &sw_out_list[131], &sw_out_list[132], &sw_out_list[133], &sw_out_list[134], &sw_out_list[135], &sw_out_list[136], &sw_out_list[137], &sw_out_list[138], &sw_out_list[139], &sw_out_list[140], &sw_out_list[141], &sw_out_list[142], &sw_out_list[143], &sw_out_list[144], &sw_out_list[145], &sw_out_list[146], &sw_out_list[147], &sw_out_list[148], &sw_out_list[149], &sw_out_list[150], &sw_out_list[151], &sw_out_list[152], &sw_out_list[153], &sw_out_list[154], &sw_out_list[155], &sw_out_list[156], &sw_out_list[157], &sw_out_list[158], &sw_out_list[159], &sw_out_list[160], &sw_out_list[161], &sw_out_list[162], &sw_out_list[163], &sw_out_list[164], &sw_out_list[165], &sw_out_list[166], &sw_out_list[167], &sw_out_list[168], &sw_out_list[169], &sw_out_list[170], &sw_out_list[171], &sw_out_list[172], &sw_out_list[173], &sw_out_list[174], &sw_out_list[175], &sw_out_list[176], &sw_out_list[177], &sw_out_list[178], &sw_out_list[179], &sw_out_list[180], &sw_out_list[181], &sw_out_list[182], &sw_out_list[183], &sw_out_list[184], &sw_out_list[185], &sw_out_list[186], &sw_out_list[187], &sw_out_list[188], &sw_out_list[189], &sw_out_list[190], &sw_out_list[191], &sw_out_list[192], &sw_out_list[193], &sw_out_list[194], &sw_out_list[195], &sw_out_list[196], &sw_out_list[197], &sw_out_list[198], &sw_out_list[199], &sw_out_list[200], &sw_out_list[201], &sw_out_list[202], &sw_out_list[203], &sw_out_list[204], &sw_out_list[205], &sw_out_list[206], &sw_out_list[207], &sw_out_list[208], &sw_out_list[209], &sw_out_list[210], &sw_out_list[211], &sw_out_list[212], &sw_out_list[213], &sw_out_list[214], &sw_out_list[215], &sw_out_list[216], &sw_out_list[217], &sw_out_list[218], &sw_out_list[219], &sw_out_list[220], &sw_out_list[221], &sw_out_list[222], &sw_out_list[223], &sw_out_list[224], &sw_out_list[225], &sw_out_list[226], &sw_out_list[227], &sw_out_list[228], &sw_out_list[229], &sw_out_list[230], &sw_out_list[231], &sw_out_list[232], &sw_out_list[233], &sw_out_list[234], &sw_out_list[235], &sw_out_list[236], &sw_out_list[237], &sw_out_list[238], &sw_out_list[239], &sw_out_list[240], &sw_out_list[241], &sw_out_list[242], &sw_out_list[243], &sw_out_list[244], &sw_out_list[245], &sw_out_list[246], &sw_out_list[247], &sw_out_list[248], &sw_out_list[249], &sw_out_list[250], &sw_out_list[251], &sw_out_list[252], &sw_out_list[253], &sw_out_list[254], &sw_out_list[255]);
	hw_retval = hwdll_read (idx, hw_out_list);
	TEST_ASSERT (sw_retval == 0 && hw_retval == 256 && sw_out_list[0] == hw_out_list[0] && sw_out_list[1] == hw_out_list[1] && sw_out_list[2] == hw_out_list[2] && sw_out_list[3] == hw_out_list[3] && sw_out_list[4] == hw_out_list[4] && sw_out_list[5] == hw_out_list[5] && sw_out_list[6] == hw_out_list[6] && sw_out_list[7] == hw_out_list[7] && sw_out_list[8] == hw_out_list[8] && sw_out_list[9] == hw_out_list[9] && sw_out_list[10] == hw_out_list[10] && sw_out_list[11] == hw_out_list[11] && sw_out_list[12] == hw_out_list[12] && sw_out_list[13] == hw_out_list[13] && sw_out_list[14] == hw_out_list[14] && sw_out_list[15] == hw_out_list[15] && sw_out_list[16] == hw_out_list[16] && sw_out_list[17] == hw_out_list[17] && sw_out_list[18] == hw_out_list[18] && sw_out_list[19] == hw_out_list[19] && sw_out_list[20] == hw_out_list[20] && sw_out_list[21] == hw_out_list[21] && sw_out_list[22] == hw_out_list[22] && sw_out_list[23] == hw_out_list[23] && sw_out_list[24] == hw_out_list[24] && sw_out_list[25] == hw_out_list[25] && sw_out_list[26] == hw_out_list[26] && sw_out_list[27] == hw_out_list[27] && sw_out_list[28] == hw_out_list[28] && sw_out_list[29] == hw_out_list[29] && sw_out_list[30] == hw_out_list[30] && sw_out_list[31] == hw_out_list[31] && sw_out_list[32] == hw_out_list[32] && sw_out_list[33] == hw_out_list[33] && sw_out_list[34] == hw_out_list[34] && sw_out_list[35] == hw_out_list[35] && sw_out_list[36] == hw_out_list[36] && sw_out_list[37] == hw_out_list[37] && sw_out_list[38] == hw_out_list[38] && sw_out_list[39] == hw_out_list[39] && sw_out_list[40] == hw_out_list[40] && sw_out_list[41] == hw_out_list[41] && sw_out_list[42] == hw_out_list[42] && sw_out_list[43] == hw_out_list[43] && sw_out_list[44] == hw_out_list[44] && sw_out_list[45] == hw_out_list[45] && sw_out_list[46] == hw_out_list[46] && sw_out_list[47] == hw_out_list[47] && sw_out_list[48] == hw_out_list[48] && sw_out_list[49] == hw_out_list[49] && sw_out_list[50] == hw_out_list[50] && sw_out_list[51] == hw_out_list[51] && sw_out_list[52] == hw_out_list[52] && sw_out_list[53] == hw_out_list[53] && sw_out_list[54] == hw_out_list[54] && sw_out_list[55] == hw_out_list[55] && sw_out_list[56] == hw_out_list[56] && sw_out_list[57] == hw_out_list[57] && sw_out_list[58] == hw_out_list[58] && sw_out_list[59] == hw_out_list[59] && sw_out_list[60] == hw_out_list[60] && sw_out_list[61] == hw_out_list[61] && sw_out_list[62] == hw_out_list[62] && sw_out_list[63] == hw_out_list[63] && sw_out_list[64] == hw_out_list[64] && sw_out_list[65] == hw_out_list[65] && sw_out_list[66] == hw_out_list[66] && sw_out_list[67] == hw_out_list[67] && sw_out_list[68] == hw_out_list[68] && sw_out_list[69] == hw_out_list[69] && sw_out_list[70] == hw_out_list[70] && sw_out_list[71] == hw_out_list[71] && sw_out_list[72] == hw_out_list[72] && sw_out_list[73] == hw_out_list[73] && sw_out_list[74] == hw_out_list[74] && sw_out_list[75] == hw_out_list[75] && sw_out_list[76] == hw_out_list[76] && sw_out_list[77] == hw_out_list[77] && sw_out_list[78] == hw_out_list[78] && sw_out_list[79] == hw_out_list[79] && sw_out_list[80] == hw_out_list[80] && sw_out_list[81] == hw_out_list[81] && sw_out_list[82] == hw_out_list[82] && sw_out_list[83] == hw_out_list[83] && sw_out_list[84] == hw_out_list[84] && sw_out_list[85] == hw_out_list[85] && sw_out_list[86] == hw_out_list[86] && sw_out_list[87] == hw_out_list[87] && sw_out_list[88] == hw_out_list[88] && sw_out_list[89] == hw_out_list[89] && sw_out_list[90] == hw_out_list[90] && sw_out_list[91] == hw_out_list[91] && sw_out_list[92] == hw_out_list[92] && sw_out_list[93] == hw_out_list[93] && sw_out_list[94] == hw_out_list[94] && sw_out_list[95] == hw_out_list[95] && sw_out_list[96] == hw_out_list[96] && sw_out_list[97] == hw_out_list[97] && sw_out_list[98] == hw_out_list[98] && sw_out_list[99] == hw_out_list[99] && sw_out_list[100] == hw_out_list[100] && sw_out_list[101] == hw_out_list[101] && sw_out_list[102] == hw_out_list[102] && sw_out_list[103] == hw_out_list[103] && sw_out_list[104] == hw_out_list[104] && sw_out_list[105] == hw_out_list[105] && sw_out_list[106] == hw_out_list[106] && sw_out_list[107] == hw_out_list[107] && sw_out_list[108] == hw_out_list[108] && sw_out_list[109] == hw_out_list[109] && sw_out_list[110] == hw_out_list[110] && sw_out_list[111] == hw_out_list[111] && sw_out_list[112] == hw_out_list[112] && sw_out_list[113] == hw_out_list[113] && sw_out_list[114] == hw_out_list[114] && sw_out_list[115] == hw_out_list[115] && sw_out_list[116] == hw_out_list[116] && sw_out_list[117] == hw_out_list[117] && sw_out_list[118] == hw_out_list[118] && sw_out_list[119] == hw_out_list[119] && sw_out_list[120] == hw_out_list[120] && sw_out_list[121] == hw_out_list[121] && sw_out_list[122] == hw_out_list[122] && sw_out_list[123] == hw_out_list[123] && sw_out_list[124] == hw_out_list[124] && sw_out_list[125] == hw_out_list[125] && sw_out_list[126] == hw_out_list[126] && sw_out_list[127] == hw_out_list[127] && sw_out_list[128] == hw_out_list[128] && sw_out_list[129] == hw_out_list[129] && sw_out_list[130] == hw_out_list[130] && sw_out_list[131] == hw_out_list[131] && sw_out_list[132] == hw_out_list[132] && sw_out_list[133] == hw_out_list[133] && sw_out_list[134] == hw_out_list[134] && sw_out_list[135] == hw_out_list[135] && sw_out_list[136] == hw_out_list[136] && sw_out_list[137] == hw_out_list[137] && sw_out_list[138] == hw_out_list[138] && sw_out_list[139] == hw_out_list[139] && sw_out_list[140] == hw_out_list[140] && sw_out_list[141] == hw_out_list[141] && sw_out_list[142] == hw_out_list[142] && sw_out_list[143] == hw_out_list[143] && sw_out_list[144] == hw_out_list[144] && sw_out_list[145] == hw_out_list[145] && sw_out_list[146] == hw_out_list[146] && sw_out_list[147] == hw_out_list[147] && sw_out_list[148] == hw_out_list[148] && sw_out_list[149] == hw_out_list[149] && sw_out_list[150] == hw_out_list[150] && sw_out_list[151] == hw_out_list[151] && sw_out_list[152] == hw_out_list[152] && sw_out_list[153] == hw_out_list[153] && sw_out_list[154] == hw_out_list[154] && sw_out_list[155] == hw_out_list[155] && sw_out_list[156] == hw_out_list[156] && sw_out_list[157] == hw_out_list[157] && sw_out_list[158] == hw_out_list[158] && sw_out_list[159] == hw_out_list[159] && sw_out_list[160] == hw_out_list[160] && sw_out_list[161] == hw_out_list[161] && sw_out_list[162] == hw_out_list[162] && sw_out_list[163] == hw_out_list[163] && sw_out_list[164] == hw_out_list[164] && sw_out_list[165] == hw_out_list[165] && sw_out_list[166] == hw_out_list[166] && sw_out_list[167] == hw_out_list[167] && sw_out_list[168] == hw_out_list[168] && sw_out_list[169] == hw_out_list[169] && sw_out_list[170] == hw_out_list[170] && sw_out_list[171] == hw_out_list[171] && sw_out_list[172] == hw_out_list[172] && sw_out_list[173] == hw_out_list[173] && sw_out_list[174] == hw_out_list[174] && sw_out_list[175] == hw_out_list[175] && sw_out_list[176] == hw_out_list[176] && sw_out_list[177] == hw_out_list[177] && sw_out_list[178] == hw_out_list[178] && sw_out_list[179] == hw_out_list[179] && sw_out_list[180] == hw_out_list[180] && sw_out_list[181] == hw_out_list[181] && sw_out_list[182] == hw_out_list[182] && sw_out_list[183] == hw_out_list[183] && sw_out_list[184] == hw_out_list[184] && sw_out_list[185] == hw_out_list[185] && sw_out_list[186] == hw_out_list[186] && sw_out_list[187] == hw_out_list[187] && sw_out_list[188] == hw_out_list[188] && sw_out_list[189] == hw_out_list[189] && sw_out_list[190] == hw_out_list[190] && sw_out_list[191] == hw_out_list[191] && sw_out_list[192] == hw_out_list[192] && sw_out_list[193] == hw_out_list[193] && sw_out_list[194] == hw_out_list[194] && sw_out_list[195] == hw_out_list[195] && sw_out_list[196] == hw_out_list[196] && sw_out_list[197] == hw_out_list[197] && sw_out_list[198] == hw_out_list[198] && sw_out_list[199] == hw_out_list[199] && sw_out_list[200] == hw_out_list[200] && sw_out_list[201] == hw_out_list[201] && sw_out_list[202] == hw_out_list[202] && sw_out_list[203] == hw_out_list[203] && sw_out_list[204] == hw_out_list[204] && sw_out_list[205] == hw_out_list[205] && sw_out_list[206] == hw_out_list[206] && sw_out_list[207] == hw_out_list[207] && sw_out_list[208] == hw_out_list[208] && sw_out_list[209] == hw_out_list[209] && sw_out_list[210] == hw_out_list[210] && sw_out_list[211] == hw_out_list[211] && sw_out_list[212] == hw_out_list[212] && sw_out_list[213] == hw_out_list[213] && sw_out_list[214] == hw_out_list[214] && sw_out_list[215] == hw_out_list[215] && sw_out_list[216] == hw_out_list[216] && sw_out_list[217] == hw_out_list[217] && sw_out_list[218] == hw_out_list[218] && sw_out_list[219] == hw_out_list[219] && sw_out_list[220] == hw_out_list[220] && sw_out_list[221] == hw_out_list[221] && sw_out_list[222] == hw_out_list[222] && sw_out_list[223] == hw_out_list[223] && sw_out_list[224] == hw_out_list[224] && sw_out_list[225] == hw_out_list[225] && sw_out_list[226] == hw_out_list[226] && sw_out_list[227] == hw_out_list[227] && sw_out_list[228] == hw_out_list[228] && sw_out_list[229] == hw_out_list[229] && sw_out_list[230] == hw_out_list[230] && sw_out_list[231] == hw_out_list[231] && sw_out_list[232] == hw_out_list[232] && sw_out_list[233] == hw_out_list[233] && sw_out_list[234] == hw_out_list[234] && sw_out_list[235] == hw_out_list[235] && sw_out_list[236] == hw_out_list[236] && sw_out_list[237] == hw_out_list[237] && sw_out_list[238] == hw_out_list[238] && sw_out_list[239] == hw_out_list[239] && sw_out_list[240] == hw_out_list[240] && sw_out_list[241] == hw_out_list[241] && sw_out_list[242] == hw_out_list[242] && sw_out_list[243] == hw_out_list[243] && sw_out_list[244] == hw_out_list[244] && sw_out_list[245] == hw_out_list[245] && sw_out_list[246] == hw_out_list[246] && sw_out_list[247] == hw_out_list[247] && sw_out_list[248] == hw_out_list[248] && sw_out_list[249] == hw_out_list[249] && sw_out_list[250] == hw_out_list[250] && sw_out_list[251] == hw_out_list[251] && sw_out_list[252] == hw_out_list[252] && sw_out_list[253] == hw_out_list[253] && sw_out_list[254] == hw_out_list[254] && sw_out_list[255] == hw_out_list[255]);
	hwdll_unload (idx, false);
	hwdll_destroy ();
	return true;
}

bool test_multi (void)
{
	FILE* dump = NULL;
	hwdll_create ();
	int sw_retval = -2, hw_retval = -2;
	int sw_out_list[256] = {-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2};
	int hw_out_list[256] = {-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2};
	int id = 0, idx = -2;
	hw_retval = hwdll_load_list (&id, &idx, 1);
	TEST_ASSERT (hw_retval == 0 && idx == 0);
	sw_retval = dummy (&sw_out_list[0], &sw_out_list[1], &sw_out_list[2], &sw_out_list[3], &sw_out_list[4], &sw_out_list[5], &sw_out_list[6], &sw_out_list[7], &sw_out_list[8], &sw_out_list[9], &sw_out_list[10], &sw_out_list[11], &sw_out_list[12], &sw_out_list[13], &sw_out_list[14], &sw_out_list[15], &sw_out_list[16], &sw_out_list[17], &sw_out_list[18], &sw_out_list[19], &sw_out_list[20], &sw_out_list[21], &sw_out_list[22], &sw_out_list[23], &sw_out_list[24], &sw_out_list[25], &sw_out_list[26], &sw_out_list[27], &sw_out_list[28], &sw_out_list[29], &sw_out_list[30], &sw_out_list[31], &sw_out_list[32], &sw_out_list[33], &sw_out_list[34], &sw_out_list[35], &sw_out_list[36], &sw_out_list[37], &sw_out_list[38], &sw_out_list[39], &sw_out_list[40], &sw_out_list[41], &sw_out_list[42], &sw_out_list[43], &sw_out_list[44], &sw_out_list[45], &sw_out_list[46], &sw_out_list[47], &sw_out_list[48], &sw_out_list[49], &sw_out_list[50], &sw_out_list[51], &sw_out_list[52], &sw_out_list[53], &sw_out_list[54], &sw_out_list[55], &sw_out_list[56], &sw_out_list[57], &sw_out_list[58], &sw_out_list[59], &sw_out_list[60], &sw_out_list[61], &sw_out_list[62], &sw_out_list[63], &sw_out_list[64], &sw_out_list[65], &sw_out_list[66], &sw_out_list[67], &sw_out_list[68], &sw_out_list[69], &sw_out_list[70], &sw_out_list[71], &sw_out_list[72], &sw_out_list[73], &sw_out_list[74], &sw_out_list[75], &sw_out_list[76], &sw_out_list[77], &sw_out_list[78], &sw_out_list[79], &sw_out_list[80], &sw_out_list[81], &sw_out_list[82], &sw_out_list[83], &sw_out_list[84], &sw_out_list[85], &sw_out_list[86], &sw_out_list[87], &sw_out_list[88], &sw_out_list[89], &sw_out_list[90], &sw_out_list[91], &sw_out_list[92], &sw_out_list[93], &sw_out_list[94], &sw_out_list[95], &sw_out_list[96], &sw_out_list[97], &sw_out_list[98], &sw_out_list[99], &sw_out_list[100], &sw_out_list[101], &sw_out_list[102], &sw_out_list[103], &sw_out_list[104], &sw_out_list[105], &sw_out_list[106], &sw_out_list[107], &sw_out_list[108], &sw_out_list[109], &sw_out_list[110], &sw_out_list[111], &sw_out_list[112], &sw_out_list[113], &sw_out_list[114], &sw_out_list[115], &sw_out_list[116], &sw_out_list[117], &sw_out_list[118], &sw_out_list[119], &sw_out_list[120], &sw_out_list[121], &sw_out_list[122], &sw_out_list[123], &sw_out_list[124], &sw_out_list[125], &sw_out_list[126], &sw_out_list[127], &sw_out_list[128], &sw_out_list[129], &sw_out_list[130], &sw_out_list[131], &sw_out_list[132], &sw_out_list[133], &sw_out_list[134], &sw_out_list[135], &sw_out_list[136], &sw_out_list[137], &sw_out_list[138], &sw_out_list[139], &sw_out_list[140], &sw_out_list[141], &sw_out_list[142], &sw_out_list[143], &sw_out_list[144], &sw_out_list[145], &sw_out_list[146], &sw_out_list[147], &sw_out_list[148], &sw_out_list[149], &sw_out_list[150], &sw_out_list[151], &sw_out_list[152], &sw_out_list[153], &sw_out_list[154], &sw_out_list[155], &sw_out_list[156], &sw_out_list[157], &sw_out_list[158], &sw_out_list[159], &sw_out_list[160], &sw_out_list[161], &sw_out_list[162], &sw_out_list[163], &sw_out_list[164], &sw_out_list[165], &sw_out_list[166], &sw_out_list[167], &sw_out_list[168], &sw_out_list[169], &sw_out_list[170], &sw_out_list[171], &sw_out_list[172], &sw_out_list[173], &sw_out_list[174], &sw_out_list[175], &sw_out_list[176], &sw_out_list[177], &sw_out_list[178], &sw_out_list[179], &sw_out_list[180], &sw_out_list[181], &sw_out_list[182], &sw_out_list[183], &sw_out_list[184], &sw_out_list[185], &sw_out_list[186], &sw_out_list[187], &sw_out_list[188], &sw_out_list[189], &sw_out_list[190], &sw_out_list[191], &sw_out_list[192], &sw_out_list[193], &sw_out_list[194], &sw_out_list[195], &sw_out_list[196], &sw_out_list[197], &sw_out_list[198], &sw_out_list[199], &sw_out_list[200], &sw_out_list[201], &sw_out_list[202], &sw_out_list[203], &sw_out_list[204], &sw_out_list[205], &sw_out_list[206], &sw_out_list[207], &sw_out_list[208], &sw_out_list[209], &sw_out_list[210], &sw_out_list[211], &sw_out_list[212], &sw_out_list[213], &sw_out_list[214], &sw_out_list[215], &sw_out_list[216], &sw_out_list[217], &sw_out_list[218], &sw_out_list[219], &sw_out_list[220], &sw_out_list[221], &sw_out_list[222], &sw_out_list[223], &sw_out_list[224], &sw_out_list[225], &sw_out_list[226], &sw_out_list[227], &sw_out_list[228], &sw_out_list[229], &sw_out_list[230], &sw_out_list[231], &sw_out_list[232], &sw_out_list[233], &sw_out_list[234], &sw_out_list[235], &sw_out_list[236], &sw_out_list[237], &sw_out_list[238], &sw_out_list[239], &sw_out_list[240], &sw_out_list[241], &sw_out_list[242], &sw_out_list[243], &sw_out_list[244], &sw_out_list[245], &sw_out_list[246], &sw_out_list[247], &sw_out_list[248], &sw_out_list[249], &sw_out_list[250], &sw_out_list[251], &sw_out_list[252], &sw_out_list[253], &sw_out_list[254], &sw_out_list[255]);
	hw_retval = hwdll_read (idx, hw_out_list);
	TEST_ASSERT (sw_retval == 0 && hw_retval == 256 && sw_out_list[0] == hw_out_list[0] && sw_out_list[1] == hw_out_list[1] && sw_out_list[2] == hw_out_list[2] && sw_out_list[3] == hw_out_list[3] && sw_out_list[4] == hw_out_list[4] && sw_out_list[5] == hw_out_list[5] && sw_out_list[6] == hw_out_list[6] && sw_out_list[7] == hw_out_list[7] && sw_out_list[8] == hw_out_list[8] && sw_out_list[9] == hw_out_list[9] && sw_out_list[10] == hw_out_list[10] && sw_out_list[11] == hw_out_list[11] && sw_out_list[12] == hw_out_list[12] && sw_out_list[13] == hw_out_list[13] && sw_out_list[14] == hw_out_list[14] && sw_out_list[15] == hw_out_list[15] && sw_out_list[16] == hw_out_list[16] && sw_out_list[17] == hw_out_list[17] && sw_out_list[18] == hw_out_list[18] && sw_out_list[19] == hw_out_list[19] && sw_out_list[20] == hw_out_list[20] && sw_out_list[21] == hw_out_list[21] && sw_out_list[22] == hw_out_list[22] && sw_out_list[23] == hw_out_list[23] && sw_out_list[24] == hw_out_list[24] && sw_out_list[25] == hw_out_list[25] && sw_out_list[26] == hw_out_list[26] && sw_out_list[27] == hw_out_list[27] && sw_out_list[28] == hw_out_list[28] && sw_out_list[29] == hw_out_list[29] && sw_out_list[30] == hw_out_list[30] && sw_out_list[31] == hw_out_list[31] && sw_out_list[32] == hw_out_list[32] && sw_out_list[33] == hw_out_list[33] && sw_out_list[34] == hw_out_list[34] && sw_out_list[35] == hw_out_list[35] && sw_out_list[36] == hw_out_list[36] && sw_out_list[37] == hw_out_list[37] && sw_out_list[38] == hw_out_list[38] && sw_out_list[39] == hw_out_list[39] && sw_out_list[40] == hw_out_list[40] && sw_out_list[41] == hw_out_list[41] && sw_out_list[42] == hw_out_list[42] && sw_out_list[43] == hw_out_list[43] && sw_out_list[44] == hw_out_list[44] && sw_out_list[45] == hw_out_list[45] && sw_out_list[46] == hw_out_list[46] && sw_out_list[47] == hw_out_list[47] && sw_out_list[48] == hw_out_list[48] && sw_out_list[49] == hw_out_list[49] && sw_out_list[50] == hw_out_list[50] && sw_out_list[51] == hw_out_list[51] && sw_out_list[52] == hw_out_list[52] && sw_out_list[53] == hw_out_list[53] && sw_out_list[54] == hw_out_list[54] && sw_out_list[55] == hw_out_list[55] && sw_out_list[56] == hw_out_list[56] && sw_out_list[57] == hw_out_list[57] && sw_out_list[58] == hw_out_list[58] && sw_out_list[59] == hw_out_list[59] && sw_out_list[60] == hw_out_list[60] && sw_out_list[61] == hw_out_list[61] && sw_out_list[62] == hw_out_list[62] && sw_out_list[63] == hw_out_list[63] && sw_out_list[64] == hw_out_list[64] && sw_out_list[65] == hw_out_list[65] && sw_out_list[66] == hw_out_list[66] && sw_out_list[67] == hw_out_list[67] && sw_out_list[68] == hw_out_list[68] && sw_out_list[69] == hw_out_list[69] && sw_out_list[70] == hw_out_list[70] && sw_out_list[71] == hw_out_list[71] && sw_out_list[72] == hw_out_list[72] && sw_out_list[73] == hw_out_list[73] && sw_out_list[74] == hw_out_list[74] && sw_out_list[75] == hw_out_list[75] && sw_out_list[76] == hw_out_list[76] && sw_out_list[77] == hw_out_list[77] && sw_out_list[78] == hw_out_list[78] && sw_out_list[79] == hw_out_list[79] && sw_out_list[80] == hw_out_list[80] && sw_out_list[81] == hw_out_list[81] && sw_out_list[82] == hw_out_list[82] && sw_out_list[83] == hw_out_list[83] && sw_out_list[84] == hw_out_list[84] && sw_out_list[85] == hw_out_list[85] && sw_out_list[86] == hw_out_list[86] && sw_out_list[87] == hw_out_list[87] && sw_out_list[88] == hw_out_list[88] && sw_out_list[89] == hw_out_list[89] && sw_out_list[90] == hw_out_list[90] && sw_out_list[91] == hw_out_list[91] && sw_out_list[92] == hw_out_list[92] && sw_out_list[93] == hw_out_list[93] && sw_out_list[94] == hw_out_list[94] && sw_out_list[95] == hw_out_list[95] && sw_out_list[96] == hw_out_list[96] && sw_out_list[97] == hw_out_list[97] && sw_out_list[98] == hw_out_list[98] && sw_out_list[99] == hw_out_list[99] && sw_out_list[100] == hw_out_list[100] && sw_out_list[101] == hw_out_list[101] && sw_out_list[102] == hw_out_list[102] && sw_out_list[103] == hw_out_list[103] && sw_out_list[104] == hw_out_list[104] && sw_out_list[105] == hw_out_list[105] && sw_out_list[106] == hw_out_list[106] && sw_out_list[107] == hw_out_list[107] && sw_out_list[108] == hw_out_list[108] && sw_out_list[109] == hw_out_list[109] && sw_out_list[110] == hw_out_list[110] && sw_out_list[111] == hw_out_list[111] && sw_out_list[112] == hw_out_list[112] && sw_out_list[113] == hw_out_list[113] && sw_out_list[114] == hw_out_list[114] && sw_out_list[115] == hw_out_list[115] && sw_out_list[116] == hw_out_list[116] && sw_out_list[117] == hw_out_list[117] && sw_out_list[118] == hw_out_list[118] && sw_out_list[119] == hw_out_list[119] && sw_out_list[120] == hw_out_list[120] && sw_out_list[121] == hw_out_list[121] && sw_out_list[122] == hw_out_list[122] && sw_out_list[123] == hw_out_list[123] && sw_out_list[124] == hw_out_list[124] && sw_out_list[125] == hw_out_list[125] && sw_out_list[126] == hw_out_list[126] && sw_out_list[127] == hw_out_list[127] && sw_out_list[128] == hw_out_list[128] && sw_out_list[129] == hw_out_list[129] && sw_out_list[130] == hw_out_list[130] && sw_out_list[131] == hw_out_list[131] && sw_out_list[132] == hw_out_list[132] && sw_out_list[133] == hw_out_list[133] && sw_out_list[134] == hw_out_list[134] && sw_out_list[135] == hw_out_list[135] && sw_out_list[136] == hw_out_list[136] && sw_out_list[137] == hw_out_list[137] && sw_out_list[138] == hw_out_list[138] && sw_out_list[139] == hw_out_list[139] && sw_out_list[140] == hw_out_list[140] && sw_out_list[141] == hw_out_list[141] && sw_out_list[142] == hw_out_list[142] && sw_out_list[143] == hw_out_list[143] && sw_out_list[144] == hw_out_list[144] && sw_out_list[145] == hw_out_list[145] && sw_out_list[146] == hw_out_list[146] && sw_out_list[147] == hw_out_list[147] && sw_out_list[148] == hw_out_list[148] && sw_out_list[149] == hw_out_list[149] && sw_out_list[150] == hw_out_list[150] && sw_out_list[151] == hw_out_list[151] && sw_out_list[152] == hw_out_list[152] && sw_out_list[153] == hw_out_list[153] && sw_out_list[154] == hw_out_list[154] && sw_out_list[155] == hw_out_list[155] && sw_out_list[156] == hw_out_list[156] && sw_out_list[157] == hw_out_list[157] && sw_out_list[158] == hw_out_list[158] && sw_out_list[159] == hw_out_list[159] && sw_out_list[160] == hw_out_list[160] && sw_out_list[161] == hw_out_list[161] && sw_out_list[162] == hw_out_list[162] && sw_out_list[163] == hw_out_list[163] && sw_out_list[164] == hw_out_list[164] && sw_out_list[165] == hw_out_list[165] && sw_out_list[166] == hw_out_list[166] && sw_out_list[167] == hw_out_list[167] && sw_out_list[168] == hw_out_list[168] && sw_out_list[169] == hw_out_list[169] && sw_out_list[170] == hw_out_list[170] && sw_out_list[171] == hw_out_list[171] && sw_out_list[172] == hw_out_list[172] && sw_out_list[173] == hw_out_list[173] && sw_out_list[174] == hw_out_list[174] && sw_out_list[175] == hw_out_list[175] && sw_out_list[176] == hw_out_list[176] && sw_out_list[177] == hw_out_list[177] && sw_out_list[178] == hw_out_list[178] && sw_out_list[179] == hw_out_list[179] && sw_out_list[180] == hw_out_list[180] && sw_out_list[181] == hw_out_list[181] && sw_out_list[182] == hw_out_list[182] && sw_out_list[183] == hw_out_list[183] && sw_out_list[184] == hw_out_list[184] && sw_out_list[185] == hw_out_list[185] && sw_out_list[186] == hw_out_list[186] && sw_out_list[187] == hw_out_list[187] && sw_out_list[188] == hw_out_list[188] && sw_out_list[189] == hw_out_list[189] && sw_out_list[190] == hw_out_list[190] && sw_out_list[191] == hw_out_list[191] && sw_out_list[192] == hw_out_list[192] && sw_out_list[193] == hw_out_list[193] && sw_out_list[194] == hw_out_list[194] && sw_out_list[195] == hw_out_list[195] && sw_out_list[196] == hw_out_list[196] && sw_out_list[197] == hw_out_list[197] && sw_out_list[198] == hw_out_list[198] && sw_out_list[199] == hw_out_list[199] && sw_out_list[200] == hw_out_list[200] && sw_out_list[201] == hw_out_list[201] && sw_out_list[202] == hw_out_list[202] && sw_out_list[203] == hw_out_list[203] && sw_out_list[204] == hw_out_list[204] && sw_out_list[205] == hw_out_list[205] && sw_out_list[206] == hw_out_list[206] && sw_out_list[207] == hw_out_list[207] && sw_out_list[208] == hw_out_list[208] && sw_out_list[209] == hw_out_list[209] && sw_out_list[210] == hw_out_list[210] && sw_out_list[211] == hw_out_list[211] && sw_out_list[212] == hw_out_list[212] && sw_out_list[213] == hw_out_list[213] && sw_out_list[214] == hw_out_list[214] && sw_out_list[215] == hw_out_list[215] && sw_out_list[216] == hw_out_list[216] && sw_out_list[217] == hw_out_list[217] && sw_out_list[218] == hw_out_list[218] && sw_out_list[219] == hw_out_list[219] && sw_out_list[220] == hw_out_list[220] && sw_out_list[221] == hw_out_list[221] && sw_out_list[222] == hw_out_list[222] && sw_out_list[223] == hw_out_list[223] && sw_out_list[224] == hw_out_list[224] && sw_out_list[225] == hw_out_list[225] && sw_out_list[226] == hw_out_list[226] && sw_out_list[227] == hw_out_list[227] && sw_out_list[228] == hw_out_list[228] && sw_out_list[229] == hw_out_list[229] && sw_out_list[230] == hw_out_list[230] && sw_out_list[231] == hw_out_list[231] && sw_out_list[232] == hw_out_list[232] && sw_out_list[233] == hw_out_list[233] && sw_out_list[234] == hw_out_list[234] && sw_out_list[235] == hw_out_list[235] && sw_out_list[236] == hw_out_list[236] && sw_out_list[237] == hw_out_list[237] && sw_out_list[238] == hw_out_list[238] && sw_out_list[239] == hw_out_list[239] && sw_out_list[240] == hw_out_list[240] && sw_out_list[241] == hw_out_list[241] && sw_out_list[242] == hw_out_list[242] && sw_out_list[243] == hw_out_list[243] && sw_out_list[244] == hw_out_list[244] && sw_out_list[245] == hw_out_list[245] && sw_out_list[246] == hw_out_list[246] && sw_out_list[247] == hw_out_list[247] && sw_out_list[248] == hw_out_list[248] && sw_out_list[249] == hw_out_list[249] && sw_out_list[250] == hw_out_list[250] && sw_out_list[251] == hw_out_list[251] && sw_out_list[252] == hw_out_list[252] && sw_out_list[253] == hw_out_list[253] && sw_out_list[254] == hw_out_list[254] && sw_out_list[255] == hw_out_list[255]);
	hwdll_unload_list (&idx, 1, false);
	hwdll_destroy ();
	return true;
}

bool test_manual (void)
{
	FILE* dump = NULL;
	hwdll_create ();
	int i = 0;
	int sw_retval = -2, hw_retval = -2;
	int sw_out_list[256] = {-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2};
	int hw_out_list[256] = {-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2};
	int idx_list[RP_LIST_SIZE] = {-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2};
	for (i = 0; i < RP_LIST_SIZE; i++)
	{
		idx_list[i] = hwdll_load (0);
	}
	TEST_ASSERT (idx_list[0] == 0 && idx_list[1] == 1 && idx_list[2] == 4 && idx_list[3] == 5 && idx_list[4] == 9 && idx_list[5] == 10 && idx_list[6] == 12 && idx_list[7] == 13 && idx_list[8] == 2 && idx_list[9] == 3 && idx_list[10] == 6 && idx_list[11] == 7 && idx_list[12] == 8 && idx_list[13] == 11 && idx_list[14] == 14 && idx_list[15] == 15);
	sw_retval = dummy (&sw_out_list[0], &sw_out_list[1], &sw_out_list[2], &sw_out_list[3], &sw_out_list[4], &sw_out_list[5], &sw_out_list[6], &sw_out_list[7], &sw_out_list[8], &sw_out_list[9], &sw_out_list[10], &sw_out_list[11], &sw_out_list[12], &sw_out_list[13], &sw_out_list[14], &sw_out_list[15], &sw_out_list[16], &sw_out_list[17], &sw_out_list[18], &sw_out_list[19], &sw_out_list[20], &sw_out_list[21], &sw_out_list[22], &sw_out_list[23], &sw_out_list[24], &sw_out_list[25], &sw_out_list[26], &sw_out_list[27], &sw_out_list[28], &sw_out_list[29], &sw_out_list[30], &sw_out_list[31], &sw_out_list[32], &sw_out_list[33], &sw_out_list[34], &sw_out_list[35], &sw_out_list[36], &sw_out_list[37], &sw_out_list[38], &sw_out_list[39], &sw_out_list[40], &sw_out_list[41], &sw_out_list[42], &sw_out_list[43], &sw_out_list[44], &sw_out_list[45], &sw_out_list[46], &sw_out_list[47], &sw_out_list[48], &sw_out_list[49], &sw_out_list[50], &sw_out_list[51], &sw_out_list[52], &sw_out_list[53], &sw_out_list[54], &sw_out_list[55], &sw_out_list[56], &sw_out_list[57], &sw_out_list[58], &sw_out_list[59], &sw_out_list[60], &sw_out_list[61], &sw_out_list[62], &sw_out_list[63], &sw_out_list[64], &sw_out_list[65], &sw_out_list[66], &sw_out_list[67], &sw_out_list[68], &sw_out_list[69], &sw_out_list[70], &sw_out_list[71], &sw_out_list[72], &sw_out_list[73], &sw_out_list[74], &sw_out_list[75], &sw_out_list[76], &sw_out_list[77], &sw_out_list[78], &sw_out_list[79], &sw_out_list[80], &sw_out_list[81], &sw_out_list[82], &sw_out_list[83], &sw_out_list[84], &sw_out_list[85], &sw_out_list[86], &sw_out_list[87], &sw_out_list[88], &sw_out_list[89], &sw_out_list[90], &sw_out_list[91], &sw_out_list[92], &sw_out_list[93], &sw_out_list[94], &sw_out_list[95], &sw_out_list[96], &sw_out_list[97], &sw_out_list[98], &sw_out_list[99], &sw_out_list[100], &sw_out_list[101], &sw_out_list[102], &sw_out_list[103], &sw_out_list[104], &sw_out_list[105], &sw_out_list[106], &sw_out_list[107], &sw_out_list[108], &sw_out_list[109], &sw_out_list[110], &sw_out_list[111], &sw_out_list[112], &sw_out_list[113], &sw_out_list[114], &sw_out_list[115], &sw_out_list[116], &sw_out_list[117], &sw_out_list[118], &sw_out_list[119], &sw_out_list[120], &sw_out_list[121], &sw_out_list[122], &sw_out_list[123], &sw_out_list[124], &sw_out_list[125], &sw_out_list[126], &sw_out_list[127], &sw_out_list[128], &sw_out_list[129], &sw_out_list[130], &sw_out_list[131], &sw_out_list[132], &sw_out_list[133], &sw_out_list[134], &sw_out_list[135], &sw_out_list[136], &sw_out_list[137], &sw_out_list[138], &sw_out_list[139], &sw_out_list[140], &sw_out_list[141], &sw_out_list[142], &sw_out_list[143], &sw_out_list[144], &sw_out_list[145], &sw_out_list[146], &sw_out_list[147], &sw_out_list[148], &sw_out_list[149], &sw_out_list[150], &sw_out_list[151], &sw_out_list[152], &sw_out_list[153], &sw_out_list[154], &sw_out_list[155], &sw_out_list[156], &sw_out_list[157], &sw_out_list[158], &sw_out_list[159], &sw_out_list[160], &sw_out_list[161], &sw_out_list[162], &sw_out_list[163], &sw_out_list[164], &sw_out_list[165], &sw_out_list[166], &sw_out_list[167], &sw_out_list[168], &sw_out_list[169], &sw_out_list[170], &sw_out_list[171], &sw_out_list[172], &sw_out_list[173], &sw_out_list[174], &sw_out_list[175], &sw_out_list[176], &sw_out_list[177], &sw_out_list[178], &sw_out_list[179], &sw_out_list[180], &sw_out_list[181], &sw_out_list[182], &sw_out_list[183], &sw_out_list[184], &sw_out_list[185], &sw_out_list[186], &sw_out_list[187], &sw_out_list[188], &sw_out_list[189], &sw_out_list[190], &sw_out_list[191], &sw_out_list[192], &sw_out_list[193], &sw_out_list[194], &sw_out_list[195], &sw_out_list[196], &sw_out_list[197], &sw_out_list[198], &sw_out_list[199], &sw_out_list[200], &sw_out_list[201], &sw_out_list[202], &sw_out_list[203], &sw_out_list[204], &sw_out_list[205], &sw_out_list[206], &sw_out_list[207], &sw_out_list[208], &sw_out_list[209], &sw_out_list[210], &sw_out_list[211], &sw_out_list[212], &sw_out_list[213], &sw_out_list[214], &sw_out_list[215], &sw_out_list[216], &sw_out_list[217], &sw_out_list[218], &sw_out_list[219], &sw_out_list[220], &sw_out_list[221], &sw_out_list[222], &sw_out_list[223], &sw_out_list[224], &sw_out_list[225], &sw_out_list[226], &sw_out_list[227], &sw_out_list[228], &sw_out_list[229], &sw_out_list[230], &sw_out_list[231], &sw_out_list[232], &sw_out_list[233], &sw_out_list[234], &sw_out_list[235], &sw_out_list[236], &sw_out_list[237], &sw_out_list[238], &sw_out_list[239], &sw_out_list[240], &sw_out_list[241], &sw_out_list[242], &sw_out_list[243], &sw_out_list[244], &sw_out_list[245], &sw_out_list[246], &sw_out_list[247], &sw_out_list[248], &sw_out_list[249], &sw_out_list[250], &sw_out_list[251], &sw_out_list[252], &sw_out_list[253], &sw_out_list[254], &sw_out_list[255]);
	TEST_ASSERT (sw_retval == 0);
	for (i = 0; i < RP_LIST_SIZE; i++)
	{
		hw_retval = hwdll_read (idx_list[i], hw_out_list);
		TEST_ASSERT (hw_retval == 256 && sw_out_list[0] == hw_out_list[0] && sw_out_list[1] == hw_out_list[1] && sw_out_list[2] == hw_out_list[2] && sw_out_list[3] == hw_out_list[3] && sw_out_list[4] == hw_out_list[4] && sw_out_list[5] == hw_out_list[5] && sw_out_list[6] == hw_out_list[6] && sw_out_list[7] == hw_out_list[7] && sw_out_list[8] == hw_out_list[8] && sw_out_list[9] == hw_out_list[9] && sw_out_list[10] == hw_out_list[10] && sw_out_list[11] == hw_out_list[11] && sw_out_list[12] == hw_out_list[12] && sw_out_list[13] == hw_out_list[13] && sw_out_list[14] == hw_out_list[14] && sw_out_list[15] == hw_out_list[15] && sw_out_list[16] == hw_out_list[16] && sw_out_list[17] == hw_out_list[17] && sw_out_list[18] == hw_out_list[18] && sw_out_list[19] == hw_out_list[19] && sw_out_list[20] == hw_out_list[20] && sw_out_list[21] == hw_out_list[21] && sw_out_list[22] == hw_out_list[22] && sw_out_list[23] == hw_out_list[23] && sw_out_list[24] == hw_out_list[24] && sw_out_list[25] == hw_out_list[25] && sw_out_list[26] == hw_out_list[26] && sw_out_list[27] == hw_out_list[27] && sw_out_list[28] == hw_out_list[28] && sw_out_list[29] == hw_out_list[29] && sw_out_list[30] == hw_out_list[30] && sw_out_list[31] == hw_out_list[31] && sw_out_list[32] == hw_out_list[32] && sw_out_list[33] == hw_out_list[33] && sw_out_list[34] == hw_out_list[34] && sw_out_list[35] == hw_out_list[35] && sw_out_list[36] == hw_out_list[36] && sw_out_list[37] == hw_out_list[37] && sw_out_list[38] == hw_out_list[38] && sw_out_list[39] == hw_out_list[39] && sw_out_list[40] == hw_out_list[40] && sw_out_list[41] == hw_out_list[41] && sw_out_list[42] == hw_out_list[42] && sw_out_list[43] == hw_out_list[43] && sw_out_list[44] == hw_out_list[44] && sw_out_list[45] == hw_out_list[45] && sw_out_list[46] == hw_out_list[46] && sw_out_list[47] == hw_out_list[47] && sw_out_list[48] == hw_out_list[48] && sw_out_list[49] == hw_out_list[49] && sw_out_list[50] == hw_out_list[50] && sw_out_list[51] == hw_out_list[51] && sw_out_list[52] == hw_out_list[52] && sw_out_list[53] == hw_out_list[53] && sw_out_list[54] == hw_out_list[54] && sw_out_list[55] == hw_out_list[55] && sw_out_list[56] == hw_out_list[56] && sw_out_list[57] == hw_out_list[57] && sw_out_list[58] == hw_out_list[58] && sw_out_list[59] == hw_out_list[59] && sw_out_list[60] == hw_out_list[60] && sw_out_list[61] == hw_out_list[61] && sw_out_list[62] == hw_out_list[62] && sw_out_list[63] == hw_out_list[63] && sw_out_list[64] == hw_out_list[64] && sw_out_list[65] == hw_out_list[65] && sw_out_list[66] == hw_out_list[66] && sw_out_list[67] == hw_out_list[67] && sw_out_list[68] == hw_out_list[68] && sw_out_list[69] == hw_out_list[69] && sw_out_list[70] == hw_out_list[70] && sw_out_list[71] == hw_out_list[71] && sw_out_list[72] == hw_out_list[72] && sw_out_list[73] == hw_out_list[73] && sw_out_list[74] == hw_out_list[74] && sw_out_list[75] == hw_out_list[75] && sw_out_list[76] == hw_out_list[76] && sw_out_list[77] == hw_out_list[77] && sw_out_list[78] == hw_out_list[78] && sw_out_list[79] == hw_out_list[79] && sw_out_list[80] == hw_out_list[80] && sw_out_list[81] == hw_out_list[81] && sw_out_list[82] == hw_out_list[82] && sw_out_list[83] == hw_out_list[83] && sw_out_list[84] == hw_out_list[84] && sw_out_list[85] == hw_out_list[85] && sw_out_list[86] == hw_out_list[86] && sw_out_list[87] == hw_out_list[87] && sw_out_list[88] == hw_out_list[88] && sw_out_list[89] == hw_out_list[89] && sw_out_list[90] == hw_out_list[90] && sw_out_list[91] == hw_out_list[91] && sw_out_list[92] == hw_out_list[92] && sw_out_list[93] == hw_out_list[93] && sw_out_list[94] == hw_out_list[94] && sw_out_list[95] == hw_out_list[95] && sw_out_list[96] == hw_out_list[96] && sw_out_list[97] == hw_out_list[97] && sw_out_list[98] == hw_out_list[98] && sw_out_list[99] == hw_out_list[99] && sw_out_list[100] == hw_out_list[100] && sw_out_list[101] == hw_out_list[101] && sw_out_list[102] == hw_out_list[102] && sw_out_list[103] == hw_out_list[103] && sw_out_list[104] == hw_out_list[104] && sw_out_list[105] == hw_out_list[105] && sw_out_list[106] == hw_out_list[106] && sw_out_list[107] == hw_out_list[107] && sw_out_list[108] == hw_out_list[108] && sw_out_list[109] == hw_out_list[109] && sw_out_list[110] == hw_out_list[110] && sw_out_list[111] == hw_out_list[111] && sw_out_list[112] == hw_out_list[112] && sw_out_list[113] == hw_out_list[113] && sw_out_list[114] == hw_out_list[114] && sw_out_list[115] == hw_out_list[115] && sw_out_list[116] == hw_out_list[116] && sw_out_list[117] == hw_out_list[117] && sw_out_list[118] == hw_out_list[118] && sw_out_list[119] == hw_out_list[119] && sw_out_list[120] == hw_out_list[120] && sw_out_list[121] == hw_out_list[121] && sw_out_list[122] == hw_out_list[122] && sw_out_list[123] == hw_out_list[123] && sw_out_list[124] == hw_out_list[124] && sw_out_list[125] == hw_out_list[125] && sw_out_list[126] == hw_out_list[126] && sw_out_list[127] == hw_out_list[127] && sw_out_list[128] == hw_out_list[128] && sw_out_list[129] == hw_out_list[129] && sw_out_list[130] == hw_out_list[130] && sw_out_list[131] == hw_out_list[131] && sw_out_list[132] == hw_out_list[132] && sw_out_list[133] == hw_out_list[133] && sw_out_list[134] == hw_out_list[134] && sw_out_list[135] == hw_out_list[135] && sw_out_list[136] == hw_out_list[136] && sw_out_list[137] == hw_out_list[137] && sw_out_list[138] == hw_out_list[138] && sw_out_list[139] == hw_out_list[139] && sw_out_list[140] == hw_out_list[140] && sw_out_list[141] == hw_out_list[141] && sw_out_list[142] == hw_out_list[142] && sw_out_list[143] == hw_out_list[143] && sw_out_list[144] == hw_out_list[144] && sw_out_list[145] == hw_out_list[145] && sw_out_list[146] == hw_out_list[146] && sw_out_list[147] == hw_out_list[147] && sw_out_list[148] == hw_out_list[148] && sw_out_list[149] == hw_out_list[149] && sw_out_list[150] == hw_out_list[150] && sw_out_list[151] == hw_out_list[151] && sw_out_list[152] == hw_out_list[152] && sw_out_list[153] == hw_out_list[153] && sw_out_list[154] == hw_out_list[154] && sw_out_list[155] == hw_out_list[155] && sw_out_list[156] == hw_out_list[156] && sw_out_list[157] == hw_out_list[157] && sw_out_list[158] == hw_out_list[158] && sw_out_list[159] == hw_out_list[159] && sw_out_list[160] == hw_out_list[160] && sw_out_list[161] == hw_out_list[161] && sw_out_list[162] == hw_out_list[162] && sw_out_list[163] == hw_out_list[163] && sw_out_list[164] == hw_out_list[164] && sw_out_list[165] == hw_out_list[165] && sw_out_list[166] == hw_out_list[166] && sw_out_list[167] == hw_out_list[167] && sw_out_list[168] == hw_out_list[168] && sw_out_list[169] == hw_out_list[169] && sw_out_list[170] == hw_out_list[170] && sw_out_list[171] == hw_out_list[171] && sw_out_list[172] == hw_out_list[172] && sw_out_list[173] == hw_out_list[173] && sw_out_list[174] == hw_out_list[174] && sw_out_list[175] == hw_out_list[175] && sw_out_list[176] == hw_out_list[176] && sw_out_list[177] == hw_out_list[177] && sw_out_list[178] == hw_out_list[178] && sw_out_list[179] == hw_out_list[179] && sw_out_list[180] == hw_out_list[180] && sw_out_list[181] == hw_out_list[181] && sw_out_list[182] == hw_out_list[182] && sw_out_list[183] == hw_out_list[183] && sw_out_list[184] == hw_out_list[184] && sw_out_list[185] == hw_out_list[185] && sw_out_list[186] == hw_out_list[186] && sw_out_list[187] == hw_out_list[187] && sw_out_list[188] == hw_out_list[188] && sw_out_list[189] == hw_out_list[189] && sw_out_list[190] == hw_out_list[190] && sw_out_list[191] == hw_out_list[191] && sw_out_list[192] == hw_out_list[192] && sw_out_list[193] == hw_out_list[193] && sw_out_list[194] == hw_out_list[194] && sw_out_list[195] == hw_out_list[195] && sw_out_list[196] == hw_out_list[196] && sw_out_list[197] == hw_out_list[197] && sw_out_list[198] == hw_out_list[198] && sw_out_list[199] == hw_out_list[199] && sw_out_list[200] == hw_out_list[200] && sw_out_list[201] == hw_out_list[201] && sw_out_list[202] == hw_out_list[202] && sw_out_list[203] == hw_out_list[203] && sw_out_list[204] == hw_out_list[204] && sw_out_list[205] == hw_out_list[205] && sw_out_list[206] == hw_out_list[206] && sw_out_list[207] == hw_out_list[207] && sw_out_list[208] == hw_out_list[208] && sw_out_list[209] == hw_out_list[209] && sw_out_list[210] == hw_out_list[210] && sw_out_list[211] == hw_out_list[211] && sw_out_list[212] == hw_out_list[212] && sw_out_list[213] == hw_out_list[213] && sw_out_list[214] == hw_out_list[214] && sw_out_list[215] == hw_out_list[215] && sw_out_list[216] == hw_out_list[216] && sw_out_list[217] == hw_out_list[217] && sw_out_list[218] == hw_out_list[218] && sw_out_list[219] == hw_out_list[219] && sw_out_list[220] == hw_out_list[220] && sw_out_list[221] == hw_out_list[221] && sw_out_list[222] == hw_out_list[222] && sw_out_list[223] == hw_out_list[223] && sw_out_list[224] == hw_out_list[224] && sw_out_list[225] == hw_out_list[225] && sw_out_list[226] == hw_out_list[226] && sw_out_list[227] == hw_out_list[227] && sw_out_list[228] == hw_out_list[228] && sw_out_list[229] == hw_out_list[229] && sw_out_list[230] == hw_out_list[230] && sw_out_list[231] == hw_out_list[231] && sw_out_list[232] == hw_out_list[232] && sw_out_list[233] == hw_out_list[233] && sw_out_list[234] == hw_out_list[234] && sw_out_list[235] == hw_out_list[235] && sw_out_list[236] == hw_out_list[236] && sw_out_list[237] == hw_out_list[237] && sw_out_list[238] == hw_out_list[238] && sw_out_list[239] == hw_out_list[239] && sw_out_list[240] == hw_out_list[240] && sw_out_list[241] == hw_out_list[241] && sw_out_list[242] == hw_out_list[242] && sw_out_list[243] == hw_out_list[243] && sw_out_list[244] == hw_out_list[244] && sw_out_list[245] == hw_out_list[245] && sw_out_list[246] == hw_out_list[246] && sw_out_list[247] == hw_out_list[247] && sw_out_list[248] == hw_out_list[248] && sw_out_list[249] == hw_out_list[249] && sw_out_list[250] == hw_out_list[250] && sw_out_list[251] == hw_out_list[251] && sw_out_list[252] == hw_out_list[252] && sw_out_list[253] == hw_out_list[253] && sw_out_list[254] == hw_out_list[254] && sw_out_list[255] == hw_out_list[255]);
	}
	for (i = 0; i < RP_LIST_SIZE; i++)
	{
		hwdll_unload (idx_list[i], false);
	}
	hwdll_destroy ();
	return true;
}

bool test_auto (void)
{
	FILE* dump = NULL;
	hwdll_create ();
	int i = 0;
	int sw_retval = -2, hw_retval = -2;
	int sw_out_list[256] = {-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2};
	int hw_out_list[256] = {-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2};
	int id_list[RP_LIST_SIZE] = {0};
	int idx_list[RP_LIST_SIZE] = {-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2};
	hw_retval = hwdll_load_list (id_list, idx_list, RP_LIST_SIZE);
	TEST_ASSERT (idx_list[0] == 0 && idx_list[1] == 1 && idx_list[2] == 4 && idx_list[3] == 5 && idx_list[4] == 9 && idx_list[5] == 10 && idx_list[6] == 12 && idx_list[7] == 13 && idx_list[8] == 2 && idx_list[9] == 3 && idx_list[10] == 6 && idx_list[11] == 7 && idx_list[12] == 8 && idx_list[13] == 11 && idx_list[14] == 14 && idx_list[15] == 15);
	sw_retval = dummy (&sw_out_list[0], &sw_out_list[1], &sw_out_list[2], &sw_out_list[3], &sw_out_list[4], &sw_out_list[5], &sw_out_list[6], &sw_out_list[7], &sw_out_list[8], &sw_out_list[9], &sw_out_list[10], &sw_out_list[11], &sw_out_list[12], &sw_out_list[13], &sw_out_list[14], &sw_out_list[15], &sw_out_list[16], &sw_out_list[17], &sw_out_list[18], &sw_out_list[19], &sw_out_list[20], &sw_out_list[21], &sw_out_list[22], &sw_out_list[23], &sw_out_list[24], &sw_out_list[25], &sw_out_list[26], &sw_out_list[27], &sw_out_list[28], &sw_out_list[29], &sw_out_list[30], &sw_out_list[31], &sw_out_list[32], &sw_out_list[33], &sw_out_list[34], &sw_out_list[35], &sw_out_list[36], &sw_out_list[37], &sw_out_list[38], &sw_out_list[39], &sw_out_list[40], &sw_out_list[41], &sw_out_list[42], &sw_out_list[43], &sw_out_list[44], &sw_out_list[45], &sw_out_list[46], &sw_out_list[47], &sw_out_list[48], &sw_out_list[49], &sw_out_list[50], &sw_out_list[51], &sw_out_list[52], &sw_out_list[53], &sw_out_list[54], &sw_out_list[55], &sw_out_list[56], &sw_out_list[57], &sw_out_list[58], &sw_out_list[59], &sw_out_list[60], &sw_out_list[61], &sw_out_list[62], &sw_out_list[63], &sw_out_list[64], &sw_out_list[65], &sw_out_list[66], &sw_out_list[67], &sw_out_list[68], &sw_out_list[69], &sw_out_list[70], &sw_out_list[71], &sw_out_list[72], &sw_out_list[73], &sw_out_list[74], &sw_out_list[75], &sw_out_list[76], &sw_out_list[77], &sw_out_list[78], &sw_out_list[79], &sw_out_list[80], &sw_out_list[81], &sw_out_list[82], &sw_out_list[83], &sw_out_list[84], &sw_out_list[85], &sw_out_list[86], &sw_out_list[87], &sw_out_list[88], &sw_out_list[89], &sw_out_list[90], &sw_out_list[91], &sw_out_list[92], &sw_out_list[93], &sw_out_list[94], &sw_out_list[95], &sw_out_list[96], &sw_out_list[97], &sw_out_list[98], &sw_out_list[99], &sw_out_list[100], &sw_out_list[101], &sw_out_list[102], &sw_out_list[103], &sw_out_list[104], &sw_out_list[105], &sw_out_list[106], &sw_out_list[107], &sw_out_list[108], &sw_out_list[109], &sw_out_list[110], &sw_out_list[111], &sw_out_list[112], &sw_out_list[113], &sw_out_list[114], &sw_out_list[115], &sw_out_list[116], &sw_out_list[117], &sw_out_list[118], &sw_out_list[119], &sw_out_list[120], &sw_out_list[121], &sw_out_list[122], &sw_out_list[123], &sw_out_list[124], &sw_out_list[125], &sw_out_list[126], &sw_out_list[127], &sw_out_list[128], &sw_out_list[129], &sw_out_list[130], &sw_out_list[131], &sw_out_list[132], &sw_out_list[133], &sw_out_list[134], &sw_out_list[135], &sw_out_list[136], &sw_out_list[137], &sw_out_list[138], &sw_out_list[139], &sw_out_list[140], &sw_out_list[141], &sw_out_list[142], &sw_out_list[143], &sw_out_list[144], &sw_out_list[145], &sw_out_list[146], &sw_out_list[147], &sw_out_list[148], &sw_out_list[149], &sw_out_list[150], &sw_out_list[151], &sw_out_list[152], &sw_out_list[153], &sw_out_list[154], &sw_out_list[155], &sw_out_list[156], &sw_out_list[157], &sw_out_list[158], &sw_out_list[159], &sw_out_list[160], &sw_out_list[161], &sw_out_list[162], &sw_out_list[163], &sw_out_list[164], &sw_out_list[165], &sw_out_list[166], &sw_out_list[167], &sw_out_list[168], &sw_out_list[169], &sw_out_list[170], &sw_out_list[171], &sw_out_list[172], &sw_out_list[173], &sw_out_list[174], &sw_out_list[175], &sw_out_list[176], &sw_out_list[177], &sw_out_list[178], &sw_out_list[179], &sw_out_list[180], &sw_out_list[181], &sw_out_list[182], &sw_out_list[183], &sw_out_list[184], &sw_out_list[185], &sw_out_list[186], &sw_out_list[187], &sw_out_list[188], &sw_out_list[189], &sw_out_list[190], &sw_out_list[191], &sw_out_list[192], &sw_out_list[193], &sw_out_list[194], &sw_out_list[195], &sw_out_list[196], &sw_out_list[197], &sw_out_list[198], &sw_out_list[199], &sw_out_list[200], &sw_out_list[201], &sw_out_list[202], &sw_out_list[203], &sw_out_list[204], &sw_out_list[205], &sw_out_list[206], &sw_out_list[207], &sw_out_list[208], &sw_out_list[209], &sw_out_list[210], &sw_out_list[211], &sw_out_list[212], &sw_out_list[213], &sw_out_list[214], &sw_out_list[215], &sw_out_list[216], &sw_out_list[217], &sw_out_list[218], &sw_out_list[219], &sw_out_list[220], &sw_out_list[221], &sw_out_list[222], &sw_out_list[223], &sw_out_list[224], &sw_out_list[225], &sw_out_list[226], &sw_out_list[227], &sw_out_list[228], &sw_out_list[229], &sw_out_list[230], &sw_out_list[231], &sw_out_list[232], &sw_out_list[233], &sw_out_list[234], &sw_out_list[235], &sw_out_list[236], &sw_out_list[237], &sw_out_list[238], &sw_out_list[239], &sw_out_list[240], &sw_out_list[241], &sw_out_list[242], &sw_out_list[243], &sw_out_list[244], &sw_out_list[245], &sw_out_list[246], &sw_out_list[247], &sw_out_list[248], &sw_out_list[249], &sw_out_list[250], &sw_out_list[251], &sw_out_list[252], &sw_out_list[253], &sw_out_list[254], &sw_out_list[255]);
	TEST_ASSERT (sw_retval == 0);
	for (i = 0; i < RP_LIST_SIZE; i++)
	{
		hw_retval = hwdll_read (idx_list[i], hw_out_list);
		TEST_ASSERT (hw_retval == 256 && sw_out_list[0] == hw_out_list[0] && sw_out_list[1] == hw_out_list[1] && sw_out_list[2] == hw_out_list[2] && sw_out_list[3] == hw_out_list[3] && sw_out_list[4] == hw_out_list[4] && sw_out_list[5] == hw_out_list[5] && sw_out_list[6] == hw_out_list[6] && sw_out_list[7] == hw_out_list[7] && sw_out_list[8] == hw_out_list[8] && sw_out_list[9] == hw_out_list[9] && sw_out_list[10] == hw_out_list[10] && sw_out_list[11] == hw_out_list[11] && sw_out_list[12] == hw_out_list[12] && sw_out_list[13] == hw_out_list[13] && sw_out_list[14] == hw_out_list[14] && sw_out_list[15] == hw_out_list[15] && sw_out_list[16] == hw_out_list[16] && sw_out_list[17] == hw_out_list[17] && sw_out_list[18] == hw_out_list[18] && sw_out_list[19] == hw_out_list[19] && sw_out_list[20] == hw_out_list[20] && sw_out_list[21] == hw_out_list[21] && sw_out_list[22] == hw_out_list[22] && sw_out_list[23] == hw_out_list[23] && sw_out_list[24] == hw_out_list[24] && sw_out_list[25] == hw_out_list[25] && sw_out_list[26] == hw_out_list[26] && sw_out_list[27] == hw_out_list[27] && sw_out_list[28] == hw_out_list[28] && sw_out_list[29] == hw_out_list[29] && sw_out_list[30] == hw_out_list[30] && sw_out_list[31] == hw_out_list[31] && sw_out_list[32] == hw_out_list[32] && sw_out_list[33] == hw_out_list[33] && sw_out_list[34] == hw_out_list[34] && sw_out_list[35] == hw_out_list[35] && sw_out_list[36] == hw_out_list[36] && sw_out_list[37] == hw_out_list[37] && sw_out_list[38] == hw_out_list[38] && sw_out_list[39] == hw_out_list[39] && sw_out_list[40] == hw_out_list[40] && sw_out_list[41] == hw_out_list[41] && sw_out_list[42] == hw_out_list[42] && sw_out_list[43] == hw_out_list[43] && sw_out_list[44] == hw_out_list[44] && sw_out_list[45] == hw_out_list[45] && sw_out_list[46] == hw_out_list[46] && sw_out_list[47] == hw_out_list[47] && sw_out_list[48] == hw_out_list[48] && sw_out_list[49] == hw_out_list[49] && sw_out_list[50] == hw_out_list[50] && sw_out_list[51] == hw_out_list[51] && sw_out_list[52] == hw_out_list[52] && sw_out_list[53] == hw_out_list[53] && sw_out_list[54] == hw_out_list[54] && sw_out_list[55] == hw_out_list[55] && sw_out_list[56] == hw_out_list[56] && sw_out_list[57] == hw_out_list[57] && sw_out_list[58] == hw_out_list[58] && sw_out_list[59] == hw_out_list[59] && sw_out_list[60] == hw_out_list[60] && sw_out_list[61] == hw_out_list[61] && sw_out_list[62] == hw_out_list[62] && sw_out_list[63] == hw_out_list[63] && sw_out_list[64] == hw_out_list[64] && sw_out_list[65] == hw_out_list[65] && sw_out_list[66] == hw_out_list[66] && sw_out_list[67] == hw_out_list[67] && sw_out_list[68] == hw_out_list[68] && sw_out_list[69] == hw_out_list[69] && sw_out_list[70] == hw_out_list[70] && sw_out_list[71] == hw_out_list[71] && sw_out_list[72] == hw_out_list[72] && sw_out_list[73] == hw_out_list[73] && sw_out_list[74] == hw_out_list[74] && sw_out_list[75] == hw_out_list[75] && sw_out_list[76] == hw_out_list[76] && sw_out_list[77] == hw_out_list[77] && sw_out_list[78] == hw_out_list[78] && sw_out_list[79] == hw_out_list[79] && sw_out_list[80] == hw_out_list[80] && sw_out_list[81] == hw_out_list[81] && sw_out_list[82] == hw_out_list[82] && sw_out_list[83] == hw_out_list[83] && sw_out_list[84] == hw_out_list[84] && sw_out_list[85] == hw_out_list[85] && sw_out_list[86] == hw_out_list[86] && sw_out_list[87] == hw_out_list[87] && sw_out_list[88] == hw_out_list[88] && sw_out_list[89] == hw_out_list[89] && sw_out_list[90] == hw_out_list[90] && sw_out_list[91] == hw_out_list[91] && sw_out_list[92] == hw_out_list[92] && sw_out_list[93] == hw_out_list[93] && sw_out_list[94] == hw_out_list[94] && sw_out_list[95] == hw_out_list[95] && sw_out_list[96] == hw_out_list[96] && sw_out_list[97] == hw_out_list[97] && sw_out_list[98] == hw_out_list[98] && sw_out_list[99] == hw_out_list[99] && sw_out_list[100] == hw_out_list[100] && sw_out_list[101] == hw_out_list[101] && sw_out_list[102] == hw_out_list[102] && sw_out_list[103] == hw_out_list[103] && sw_out_list[104] == hw_out_list[104] && sw_out_list[105] == hw_out_list[105] && sw_out_list[106] == hw_out_list[106] && sw_out_list[107] == hw_out_list[107] && sw_out_list[108] == hw_out_list[108] && sw_out_list[109] == hw_out_list[109] && sw_out_list[110] == hw_out_list[110] && sw_out_list[111] == hw_out_list[111] && sw_out_list[112] == hw_out_list[112] && sw_out_list[113] == hw_out_list[113] && sw_out_list[114] == hw_out_list[114] && sw_out_list[115] == hw_out_list[115] && sw_out_list[116] == hw_out_list[116] && sw_out_list[117] == hw_out_list[117] && sw_out_list[118] == hw_out_list[118] && sw_out_list[119] == hw_out_list[119] && sw_out_list[120] == hw_out_list[120] && sw_out_list[121] == hw_out_list[121] && sw_out_list[122] == hw_out_list[122] && sw_out_list[123] == hw_out_list[123] && sw_out_list[124] == hw_out_list[124] && sw_out_list[125] == hw_out_list[125] && sw_out_list[126] == hw_out_list[126] && sw_out_list[127] == hw_out_list[127] && sw_out_list[128] == hw_out_list[128] && sw_out_list[129] == hw_out_list[129] && sw_out_list[130] == hw_out_list[130] && sw_out_list[131] == hw_out_list[131] && sw_out_list[132] == hw_out_list[132] && sw_out_list[133] == hw_out_list[133] && sw_out_list[134] == hw_out_list[134] && sw_out_list[135] == hw_out_list[135] && sw_out_list[136] == hw_out_list[136] && sw_out_list[137] == hw_out_list[137] && sw_out_list[138] == hw_out_list[138] && sw_out_list[139] == hw_out_list[139] && sw_out_list[140] == hw_out_list[140] && sw_out_list[141] == hw_out_list[141] && sw_out_list[142] == hw_out_list[142] && sw_out_list[143] == hw_out_list[143] && sw_out_list[144] == hw_out_list[144] && sw_out_list[145] == hw_out_list[145] && sw_out_list[146] == hw_out_list[146] && sw_out_list[147] == hw_out_list[147] && sw_out_list[148] == hw_out_list[148] && sw_out_list[149] == hw_out_list[149] && sw_out_list[150] == hw_out_list[150] && sw_out_list[151] == hw_out_list[151] && sw_out_list[152] == hw_out_list[152] && sw_out_list[153] == hw_out_list[153] && sw_out_list[154] == hw_out_list[154] && sw_out_list[155] == hw_out_list[155] && sw_out_list[156] == hw_out_list[156] && sw_out_list[157] == hw_out_list[157] && sw_out_list[158] == hw_out_list[158] && sw_out_list[159] == hw_out_list[159] && sw_out_list[160] == hw_out_list[160] && sw_out_list[161] == hw_out_list[161] && sw_out_list[162] == hw_out_list[162] && sw_out_list[163] == hw_out_list[163] && sw_out_list[164] == hw_out_list[164] && sw_out_list[165] == hw_out_list[165] && sw_out_list[166] == hw_out_list[166] && sw_out_list[167] == hw_out_list[167] && sw_out_list[168] == hw_out_list[168] && sw_out_list[169] == hw_out_list[169] && sw_out_list[170] == hw_out_list[170] && sw_out_list[171] == hw_out_list[171] && sw_out_list[172] == hw_out_list[172] && sw_out_list[173] == hw_out_list[173] && sw_out_list[174] == hw_out_list[174] && sw_out_list[175] == hw_out_list[175] && sw_out_list[176] == hw_out_list[176] && sw_out_list[177] == hw_out_list[177] && sw_out_list[178] == hw_out_list[178] && sw_out_list[179] == hw_out_list[179] && sw_out_list[180] == hw_out_list[180] && sw_out_list[181] == hw_out_list[181] && sw_out_list[182] == hw_out_list[182] && sw_out_list[183] == hw_out_list[183] && sw_out_list[184] == hw_out_list[184] && sw_out_list[185] == hw_out_list[185] && sw_out_list[186] == hw_out_list[186] && sw_out_list[187] == hw_out_list[187] && sw_out_list[188] == hw_out_list[188] && sw_out_list[189] == hw_out_list[189] && sw_out_list[190] == hw_out_list[190] && sw_out_list[191] == hw_out_list[191] && sw_out_list[192] == hw_out_list[192] && sw_out_list[193] == hw_out_list[193] && sw_out_list[194] == hw_out_list[194] && sw_out_list[195] == hw_out_list[195] && sw_out_list[196] == hw_out_list[196] && sw_out_list[197] == hw_out_list[197] && sw_out_list[198] == hw_out_list[198] && sw_out_list[199] == hw_out_list[199] && sw_out_list[200] == hw_out_list[200] && sw_out_list[201] == hw_out_list[201] && sw_out_list[202] == hw_out_list[202] && sw_out_list[203] == hw_out_list[203] && sw_out_list[204] == hw_out_list[204] && sw_out_list[205] == hw_out_list[205] && sw_out_list[206] == hw_out_list[206] && sw_out_list[207] == hw_out_list[207] && sw_out_list[208] == hw_out_list[208] && sw_out_list[209] == hw_out_list[209] && sw_out_list[210] == hw_out_list[210] && sw_out_list[211] == hw_out_list[211] && sw_out_list[212] == hw_out_list[212] && sw_out_list[213] == hw_out_list[213] && sw_out_list[214] == hw_out_list[214] && sw_out_list[215] == hw_out_list[215] && sw_out_list[216] == hw_out_list[216] && sw_out_list[217] == hw_out_list[217] && sw_out_list[218] == hw_out_list[218] && sw_out_list[219] == hw_out_list[219] && sw_out_list[220] == hw_out_list[220] && sw_out_list[221] == hw_out_list[221] && sw_out_list[222] == hw_out_list[222] && sw_out_list[223] == hw_out_list[223] && sw_out_list[224] == hw_out_list[224] && sw_out_list[225] == hw_out_list[225] && sw_out_list[226] == hw_out_list[226] && sw_out_list[227] == hw_out_list[227] && sw_out_list[228] == hw_out_list[228] && sw_out_list[229] == hw_out_list[229] && sw_out_list[230] == hw_out_list[230] && sw_out_list[231] == hw_out_list[231] && sw_out_list[232] == hw_out_list[232] && sw_out_list[233] == hw_out_list[233] && sw_out_list[234] == hw_out_list[234] && sw_out_list[235] == hw_out_list[235] && sw_out_list[236] == hw_out_list[236] && sw_out_list[237] == hw_out_list[237] && sw_out_list[238] == hw_out_list[238] && sw_out_list[239] == hw_out_list[239] && sw_out_list[240] == hw_out_list[240] && sw_out_list[241] == hw_out_list[241] && sw_out_list[242] == hw_out_list[242] && sw_out_list[243] == hw_out_list[243] && sw_out_list[244] == hw_out_list[244] && sw_out_list[245] == hw_out_list[245] && sw_out_list[246] == hw_out_list[246] && sw_out_list[247] == hw_out_list[247] && sw_out_list[248] == hw_out_list[248] && sw_out_list[249] == hw_out_list[249] && sw_out_list[250] == hw_out_list[250] && sw_out_list[251] == hw_out_list[251] && sw_out_list[252] == hw_out_list[252] && sw_out_list[253] == hw_out_list[253] && sw_out_list[254] == hw_out_list[254] && sw_out_list[255] == hw_out_list[255]);
	}
	hwdll_unload_list (idx_list, RP_LIST_SIZE, false);
	hwdll_destroy ();
	return true;
}

bool test_set (void)
{
	FILE* dump = NULL;
	hwdll_create ();
	int i = 0;
	int sw_retval = -2, hw_retval = -2;
	int in_list[2] = {0};
	int sw_out_list[256] = {-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2};
	int hw_out_list[256] = {-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2};
	int id_list[CAT_SIZE] = {0};
	int idx_list[CAT_SIZE] = {0};
	for (i = 0; i < CAT_SIZE; i++)
	{
		id_list[i] = i;
		idx_list[i] = -2;
	}
	hw_retval = hwdll_load_list (id_list, idx_list, CAT_SIZE);
	TEST_ASSERT (idx_list[0] == 3 && idx_list[1] == 13 && idx_list[2] == 12 && idx_list[3] == 10 && idx_list[4] == 2 && idx_list[5] == 5 && idx_list[6] == 4 && idx_list[7] == 1 && idx_list[8] == 0 && idx_list[9] == 9);
	in_list[0] = 2;
	in_list[1] = 3;
	i = 0; /* Evaluate Dummy																												*/
	sw_retval = dummy (&sw_out_list[0], &sw_out_list[1], &sw_out_list[2], &sw_out_list[3], &sw_out_list[4], &sw_out_list[5], &sw_out_list[6], &sw_out_list[7], &sw_out_list[8], &sw_out_list[9], &sw_out_list[10], &sw_out_list[11], &sw_out_list[12], &sw_out_list[13], &sw_out_list[14], &sw_out_list[15], &sw_out_list[16], &sw_out_list[17], &sw_out_list[18], &sw_out_list[19], &sw_out_list[20], &sw_out_list[21], &sw_out_list[22], &sw_out_list[23], &sw_out_list[24], &sw_out_list[25], &sw_out_list[26], &sw_out_list[27], &sw_out_list[28], &sw_out_list[29], &sw_out_list[30], &sw_out_list[31], &sw_out_list[32], &sw_out_list[33], &sw_out_list[34], &sw_out_list[35], &sw_out_list[36], &sw_out_list[37], &sw_out_list[38], &sw_out_list[39], &sw_out_list[40], &sw_out_list[41], &sw_out_list[42], &sw_out_list[43], &sw_out_list[44], &sw_out_list[45], &sw_out_list[46], &sw_out_list[47], &sw_out_list[48], &sw_out_list[49], &sw_out_list[50], &sw_out_list[51], &sw_out_list[52], &sw_out_list[53], &sw_out_list[54], &sw_out_list[55], &sw_out_list[56], &sw_out_list[57], &sw_out_list[58], &sw_out_list[59], &sw_out_list[60], &sw_out_list[61], &sw_out_list[62], &sw_out_list[63], &sw_out_list[64], &sw_out_list[65], &sw_out_list[66], &sw_out_list[67], &sw_out_list[68], &sw_out_list[69], &sw_out_list[70], &sw_out_list[71], &sw_out_list[72], &sw_out_list[73], &sw_out_list[74], &sw_out_list[75], &sw_out_list[76], &sw_out_list[77], &sw_out_list[78], &sw_out_list[79], &sw_out_list[80], &sw_out_list[81], &sw_out_list[82], &sw_out_list[83], &sw_out_list[84], &sw_out_list[85], &sw_out_list[86], &sw_out_list[87], &sw_out_list[88], &sw_out_list[89], &sw_out_list[90], &sw_out_list[91], &sw_out_list[92], &sw_out_list[93], &sw_out_list[94], &sw_out_list[95], &sw_out_list[96], &sw_out_list[97], &sw_out_list[98], &sw_out_list[99], &sw_out_list[100], &sw_out_list[101], &sw_out_list[102], &sw_out_list[103], &sw_out_list[104], &sw_out_list[105], &sw_out_list[106], &sw_out_list[107], &sw_out_list[108], &sw_out_list[109], &sw_out_list[110], &sw_out_list[111], &sw_out_list[112], &sw_out_list[113], &sw_out_list[114], &sw_out_list[115], &sw_out_list[116], &sw_out_list[117], &sw_out_list[118], &sw_out_list[119], &sw_out_list[120], &sw_out_list[121], &sw_out_list[122], &sw_out_list[123], &sw_out_list[124], &sw_out_list[125], &sw_out_list[126], &sw_out_list[127], &sw_out_list[128], &sw_out_list[129], &sw_out_list[130], &sw_out_list[131], &sw_out_list[132], &sw_out_list[133], &sw_out_list[134], &sw_out_list[135], &sw_out_list[136], &sw_out_list[137], &sw_out_list[138], &sw_out_list[139], &sw_out_list[140], &sw_out_list[141], &sw_out_list[142], &sw_out_list[143], &sw_out_list[144], &sw_out_list[145], &sw_out_list[146], &sw_out_list[147], &sw_out_list[148], &sw_out_list[149], &sw_out_list[150], &sw_out_list[151], &sw_out_list[152], &sw_out_list[153], &sw_out_list[154], &sw_out_list[155], &sw_out_list[156], &sw_out_list[157], &sw_out_list[158], &sw_out_list[159], &sw_out_list[160], &sw_out_list[161], &sw_out_list[162], &sw_out_list[163], &sw_out_list[164], &sw_out_list[165], &sw_out_list[166], &sw_out_list[167], &sw_out_list[168], &sw_out_list[169], &sw_out_list[170], &sw_out_list[171], &sw_out_list[172], &sw_out_list[173], &sw_out_list[174], &sw_out_list[175], &sw_out_list[176], &sw_out_list[177], &sw_out_list[178], &sw_out_list[179], &sw_out_list[180], &sw_out_list[181], &sw_out_list[182], &sw_out_list[183], &sw_out_list[184], &sw_out_list[185], &sw_out_list[186], &sw_out_list[187], &sw_out_list[188], &sw_out_list[189], &sw_out_list[190], &sw_out_list[191], &sw_out_list[192], &sw_out_list[193], &sw_out_list[194], &sw_out_list[195], &sw_out_list[196], &sw_out_list[197], &sw_out_list[198], &sw_out_list[199], &sw_out_list[200], &sw_out_list[201], &sw_out_list[202], &sw_out_list[203], &sw_out_list[204], &sw_out_list[205], &sw_out_list[206], &sw_out_list[207], &sw_out_list[208], &sw_out_list[209], &sw_out_list[210], &sw_out_list[211], &sw_out_list[212], &sw_out_list[213], &sw_out_list[214], &sw_out_list[215], &sw_out_list[216], &sw_out_list[217], &sw_out_list[218], &sw_out_list[219], &sw_out_list[220], &sw_out_list[221], &sw_out_list[222], &sw_out_list[223], &sw_out_list[224], &sw_out_list[225], &sw_out_list[226], &sw_out_list[227], &sw_out_list[228], &sw_out_list[229], &sw_out_list[230], &sw_out_list[231], &sw_out_list[232], &sw_out_list[233], &sw_out_list[234], &sw_out_list[235], &sw_out_list[236], &sw_out_list[237], &sw_out_list[238], &sw_out_list[239], &sw_out_list[240], &sw_out_list[241], &sw_out_list[242], &sw_out_list[243], &sw_out_list[244], &sw_out_list[245], &sw_out_list[246], &sw_out_list[247], &sw_out_list[248], &sw_out_list[249], &sw_out_list[250], &sw_out_list[251], &sw_out_list[252], &sw_out_list[253], &sw_out_list[254], &sw_out_list[255]);
	TEST_ASSERT (sw_retval == 0);
	while (hwdll_probe (idx_list[i])) {}
	hw_retval = hwdll_read (idx_list[i], hw_out_list);
	TEST_ASSERT (hw_retval == 256 && sw_out_list[0] == hw_out_list[0] && sw_out_list[1] == hw_out_list[1] && sw_out_list[2] == hw_out_list[2] && sw_out_list[3] == hw_out_list[3] && sw_out_list[4] == hw_out_list[4] && sw_out_list[5] == hw_out_list[5] && sw_out_list[6] == hw_out_list[6] && sw_out_list[7] == hw_out_list[7] && sw_out_list[8] == hw_out_list[8] && sw_out_list[9] == hw_out_list[9] && sw_out_list[10] == hw_out_list[10] && sw_out_list[11] == hw_out_list[11] && sw_out_list[12] == hw_out_list[12] && sw_out_list[13] == hw_out_list[13] && sw_out_list[14] == hw_out_list[14] && sw_out_list[15] == hw_out_list[15] && sw_out_list[16] == hw_out_list[16] && sw_out_list[17] == hw_out_list[17] && sw_out_list[18] == hw_out_list[18] && sw_out_list[19] == hw_out_list[19] && sw_out_list[20] == hw_out_list[20] && sw_out_list[21] == hw_out_list[21] && sw_out_list[22] == hw_out_list[22] && sw_out_list[23] == hw_out_list[23] && sw_out_list[24] == hw_out_list[24] && sw_out_list[25] == hw_out_list[25] && sw_out_list[26] == hw_out_list[26] && sw_out_list[27] == hw_out_list[27] && sw_out_list[28] == hw_out_list[28] && sw_out_list[29] == hw_out_list[29] && sw_out_list[30] == hw_out_list[30] && sw_out_list[31] == hw_out_list[31] && sw_out_list[32] == hw_out_list[32] && sw_out_list[33] == hw_out_list[33] && sw_out_list[34] == hw_out_list[34] && sw_out_list[35] == hw_out_list[35] && sw_out_list[36] == hw_out_list[36] && sw_out_list[37] == hw_out_list[37] && sw_out_list[38] == hw_out_list[38] && sw_out_list[39] == hw_out_list[39] && sw_out_list[40] == hw_out_list[40] && sw_out_list[41] == hw_out_list[41] && sw_out_list[42] == hw_out_list[42] && sw_out_list[43] == hw_out_list[43] && sw_out_list[44] == hw_out_list[44] && sw_out_list[45] == hw_out_list[45] && sw_out_list[46] == hw_out_list[46] && sw_out_list[47] == hw_out_list[47] && sw_out_list[48] == hw_out_list[48] && sw_out_list[49] == hw_out_list[49] && sw_out_list[50] == hw_out_list[50] && sw_out_list[51] == hw_out_list[51] && sw_out_list[52] == hw_out_list[52] && sw_out_list[53] == hw_out_list[53] && sw_out_list[54] == hw_out_list[54] && sw_out_list[55] == hw_out_list[55] && sw_out_list[56] == hw_out_list[56] && sw_out_list[57] == hw_out_list[57] && sw_out_list[58] == hw_out_list[58] && sw_out_list[59] == hw_out_list[59] && sw_out_list[60] == hw_out_list[60] && sw_out_list[61] == hw_out_list[61] && sw_out_list[62] == hw_out_list[62] && sw_out_list[63] == hw_out_list[63] && sw_out_list[64] == hw_out_list[64] && sw_out_list[65] == hw_out_list[65] && sw_out_list[66] == hw_out_list[66] && sw_out_list[67] == hw_out_list[67] && sw_out_list[68] == hw_out_list[68] && sw_out_list[69] == hw_out_list[69] && sw_out_list[70] == hw_out_list[70] && sw_out_list[71] == hw_out_list[71] && sw_out_list[72] == hw_out_list[72] && sw_out_list[73] == hw_out_list[73] && sw_out_list[74] == hw_out_list[74] && sw_out_list[75] == hw_out_list[75] && sw_out_list[76] == hw_out_list[76] && sw_out_list[77] == hw_out_list[77] && sw_out_list[78] == hw_out_list[78] && sw_out_list[79] == hw_out_list[79] && sw_out_list[80] == hw_out_list[80] && sw_out_list[81] == hw_out_list[81] && sw_out_list[82] == hw_out_list[82] && sw_out_list[83] == hw_out_list[83] && sw_out_list[84] == hw_out_list[84] && sw_out_list[85] == hw_out_list[85] && sw_out_list[86] == hw_out_list[86] && sw_out_list[87] == hw_out_list[87] && sw_out_list[88] == hw_out_list[88] && sw_out_list[89] == hw_out_list[89] && sw_out_list[90] == hw_out_list[90] && sw_out_list[91] == hw_out_list[91] && sw_out_list[92] == hw_out_list[92] && sw_out_list[93] == hw_out_list[93] && sw_out_list[94] == hw_out_list[94] && sw_out_list[95] == hw_out_list[95] && sw_out_list[96] == hw_out_list[96] && sw_out_list[97] == hw_out_list[97] && sw_out_list[98] == hw_out_list[98] && sw_out_list[99] == hw_out_list[99] && sw_out_list[100] == hw_out_list[100] && sw_out_list[101] == hw_out_list[101] && sw_out_list[102] == hw_out_list[102] && sw_out_list[103] == hw_out_list[103] && sw_out_list[104] == hw_out_list[104] && sw_out_list[105] == hw_out_list[105] && sw_out_list[106] == hw_out_list[106] && sw_out_list[107] == hw_out_list[107] && sw_out_list[108] == hw_out_list[108] && sw_out_list[109] == hw_out_list[109] && sw_out_list[110] == hw_out_list[110] && sw_out_list[111] == hw_out_list[111] && sw_out_list[112] == hw_out_list[112] && sw_out_list[113] == hw_out_list[113] && sw_out_list[114] == hw_out_list[114] && sw_out_list[115] == hw_out_list[115] && sw_out_list[116] == hw_out_list[116] && sw_out_list[117] == hw_out_list[117] && sw_out_list[118] == hw_out_list[118] && sw_out_list[119] == hw_out_list[119] && sw_out_list[120] == hw_out_list[120] && sw_out_list[121] == hw_out_list[121] && sw_out_list[122] == hw_out_list[122] && sw_out_list[123] == hw_out_list[123] && sw_out_list[124] == hw_out_list[124] && sw_out_list[125] == hw_out_list[125] && sw_out_list[126] == hw_out_list[126] && sw_out_list[127] == hw_out_list[127] && sw_out_list[128] == hw_out_list[128] && sw_out_list[129] == hw_out_list[129] && sw_out_list[130] == hw_out_list[130] && sw_out_list[131] == hw_out_list[131] && sw_out_list[132] == hw_out_list[132] && sw_out_list[133] == hw_out_list[133] && sw_out_list[134] == hw_out_list[134] && sw_out_list[135] == hw_out_list[135] && sw_out_list[136] == hw_out_list[136] && sw_out_list[137] == hw_out_list[137] && sw_out_list[138] == hw_out_list[138] && sw_out_list[139] == hw_out_list[139] && sw_out_list[140] == hw_out_list[140] && sw_out_list[141] == hw_out_list[141] && sw_out_list[142] == hw_out_list[142] && sw_out_list[143] == hw_out_list[143] && sw_out_list[144] == hw_out_list[144] && sw_out_list[145] == hw_out_list[145] && sw_out_list[146] == hw_out_list[146] && sw_out_list[147] == hw_out_list[147] && sw_out_list[148] == hw_out_list[148] && sw_out_list[149] == hw_out_list[149] && sw_out_list[150] == hw_out_list[150] && sw_out_list[151] == hw_out_list[151] && sw_out_list[152] == hw_out_list[152] && sw_out_list[153] == hw_out_list[153] && sw_out_list[154] == hw_out_list[154] && sw_out_list[155] == hw_out_list[155] && sw_out_list[156] == hw_out_list[156] && sw_out_list[157] == hw_out_list[157] && sw_out_list[158] == hw_out_list[158] && sw_out_list[159] == hw_out_list[159] && sw_out_list[160] == hw_out_list[160] && sw_out_list[161] == hw_out_list[161] && sw_out_list[162] == hw_out_list[162] && sw_out_list[163] == hw_out_list[163] && sw_out_list[164] == hw_out_list[164] && sw_out_list[165] == hw_out_list[165] && sw_out_list[166] == hw_out_list[166] && sw_out_list[167] == hw_out_list[167] && sw_out_list[168] == hw_out_list[168] && sw_out_list[169] == hw_out_list[169] && sw_out_list[170] == hw_out_list[170] && sw_out_list[171] == hw_out_list[171] && sw_out_list[172] == hw_out_list[172] && sw_out_list[173] == hw_out_list[173] && sw_out_list[174] == hw_out_list[174] && sw_out_list[175] == hw_out_list[175] && sw_out_list[176] == hw_out_list[176] && sw_out_list[177] == hw_out_list[177] && sw_out_list[178] == hw_out_list[178] && sw_out_list[179] == hw_out_list[179] && sw_out_list[180] == hw_out_list[180] && sw_out_list[181] == hw_out_list[181] && sw_out_list[182] == hw_out_list[182] && sw_out_list[183] == hw_out_list[183] && sw_out_list[184] == hw_out_list[184] && sw_out_list[185] == hw_out_list[185] && sw_out_list[186] == hw_out_list[186] && sw_out_list[187] == hw_out_list[187] && sw_out_list[188] == hw_out_list[188] && sw_out_list[189] == hw_out_list[189] && sw_out_list[190] == hw_out_list[190] && sw_out_list[191] == hw_out_list[191] && sw_out_list[192] == hw_out_list[192] && sw_out_list[193] == hw_out_list[193] && sw_out_list[194] == hw_out_list[194] && sw_out_list[195] == hw_out_list[195] && sw_out_list[196] == hw_out_list[196] && sw_out_list[197] == hw_out_list[197] && sw_out_list[198] == hw_out_list[198] && sw_out_list[199] == hw_out_list[199] && sw_out_list[200] == hw_out_list[200] && sw_out_list[201] == hw_out_list[201] && sw_out_list[202] == hw_out_list[202] && sw_out_list[203] == hw_out_list[203] && sw_out_list[204] == hw_out_list[204] && sw_out_list[205] == hw_out_list[205] && sw_out_list[206] == hw_out_list[206] && sw_out_list[207] == hw_out_list[207] && sw_out_list[208] == hw_out_list[208] && sw_out_list[209] == hw_out_list[209] && sw_out_list[210] == hw_out_list[210] && sw_out_list[211] == hw_out_list[211] && sw_out_list[212] == hw_out_list[212] && sw_out_list[213] == hw_out_list[213] && sw_out_list[214] == hw_out_list[214] && sw_out_list[215] == hw_out_list[215] && sw_out_list[216] == hw_out_list[216] && sw_out_list[217] == hw_out_list[217] && sw_out_list[218] == hw_out_list[218] && sw_out_list[219] == hw_out_list[219] && sw_out_list[220] == hw_out_list[220] && sw_out_list[221] == hw_out_list[221] && sw_out_list[222] == hw_out_list[222] && sw_out_list[223] == hw_out_list[223] && sw_out_list[224] == hw_out_list[224] && sw_out_list[225] == hw_out_list[225] && sw_out_list[226] == hw_out_list[226] && sw_out_list[227] == hw_out_list[227] && sw_out_list[228] == hw_out_list[228] && sw_out_list[229] == hw_out_list[229] && sw_out_list[230] == hw_out_list[230] && sw_out_list[231] == hw_out_list[231] && sw_out_list[232] == hw_out_list[232] && sw_out_list[233] == hw_out_list[233] && sw_out_list[234] == hw_out_list[234] && sw_out_list[235] == hw_out_list[235] && sw_out_list[236] == hw_out_list[236] && sw_out_list[237] == hw_out_list[237] && sw_out_list[238] == hw_out_list[238] && sw_out_list[239] == hw_out_list[239] && sw_out_list[240] == hw_out_list[240] && sw_out_list[241] == hw_out_list[241] && sw_out_list[242] == hw_out_list[242] && sw_out_list[243] == hw_out_list[243] && sw_out_list[244] == hw_out_list[244] && sw_out_list[245] == hw_out_list[245] && sw_out_list[246] == hw_out_list[246] && sw_out_list[247] == hw_out_list[247] && sw_out_list[248] == hw_out_list[248] && sw_out_list[249] == hw_out_list[249] && sw_out_list[250] == hw_out_list[250] && sw_out_list[251] == hw_out_list[251] && sw_out_list[252] == hw_out_list[252] && sw_out_list[253] == hw_out_list[253] && sw_out_list[254] == hw_out_list[254] && sw_out_list[255] == hw_out_list[255]);
	i = 1; /* Evaluate Numbers																												*/
	sw_retval = numbers (&sw_out_list[0], &sw_out_list[1], &sw_out_list[2], &sw_out_list[3], &sw_out_list[4], &sw_out_list[5], &sw_out_list[6], &sw_out_list[7], &sw_out_list[8], &sw_out_list[9], &sw_out_list[10], &sw_out_list[11], &sw_out_list[12], &sw_out_list[13], &sw_out_list[14], &sw_out_list[15], &sw_out_list[16], &sw_out_list[17], &sw_out_list[18], &sw_out_list[19], &sw_out_list[20], &sw_out_list[21], &sw_out_list[22], &sw_out_list[23], &sw_out_list[24], &sw_out_list[25], &sw_out_list[26], &sw_out_list[27], &sw_out_list[28], &sw_out_list[29], &sw_out_list[30], &sw_out_list[31], &sw_out_list[32], &sw_out_list[33], &sw_out_list[34], &sw_out_list[35], &sw_out_list[36], &sw_out_list[37], &sw_out_list[38], &sw_out_list[39], &sw_out_list[40], &sw_out_list[41], &sw_out_list[42], &sw_out_list[43], &sw_out_list[44], &sw_out_list[45], &sw_out_list[46], &sw_out_list[47], &sw_out_list[48], &sw_out_list[49], &sw_out_list[50], &sw_out_list[51], &sw_out_list[52], &sw_out_list[53], &sw_out_list[54], &sw_out_list[55], &sw_out_list[56], &sw_out_list[57], &sw_out_list[58], &sw_out_list[59], &sw_out_list[60], &sw_out_list[61], &sw_out_list[62], &sw_out_list[63], &sw_out_list[64], &sw_out_list[65], &sw_out_list[66], &sw_out_list[67], &sw_out_list[68], &sw_out_list[69], &sw_out_list[70], &sw_out_list[71], &sw_out_list[72], &sw_out_list[73], &sw_out_list[74], &sw_out_list[75], &sw_out_list[76], &sw_out_list[77], &sw_out_list[78], &sw_out_list[79], &sw_out_list[80], &sw_out_list[81], &sw_out_list[82], &sw_out_list[83], &sw_out_list[84], &sw_out_list[85], &sw_out_list[86], &sw_out_list[87], &sw_out_list[88], &sw_out_list[89], &sw_out_list[90], &sw_out_list[91], &sw_out_list[92], &sw_out_list[93], &sw_out_list[94], &sw_out_list[95], &sw_out_list[96], &sw_out_list[97], &sw_out_list[98], &sw_out_list[99], &sw_out_list[100], &sw_out_list[101], &sw_out_list[102], &sw_out_list[103], &sw_out_list[104], &sw_out_list[105], &sw_out_list[106], &sw_out_list[107], &sw_out_list[108], &sw_out_list[109], &sw_out_list[110], &sw_out_list[111], &sw_out_list[112], &sw_out_list[113], &sw_out_list[114], &sw_out_list[115], &sw_out_list[116], &sw_out_list[117], &sw_out_list[118], &sw_out_list[119], &sw_out_list[120], &sw_out_list[121], &sw_out_list[122], &sw_out_list[123], &sw_out_list[124], &sw_out_list[125], &sw_out_list[126], &sw_out_list[127], &sw_out_list[128], &sw_out_list[129], &sw_out_list[130], &sw_out_list[131], &sw_out_list[132], &sw_out_list[133], &sw_out_list[134], &sw_out_list[135], &sw_out_list[136], &sw_out_list[137], &sw_out_list[138], &sw_out_list[139], &sw_out_list[140], &sw_out_list[141], &sw_out_list[142], &sw_out_list[143], &sw_out_list[144], &sw_out_list[145], &sw_out_list[146], &sw_out_list[147], &sw_out_list[148], &sw_out_list[149], &sw_out_list[150], &sw_out_list[151], &sw_out_list[152], &sw_out_list[153], &sw_out_list[154], &sw_out_list[155], &sw_out_list[156], &sw_out_list[157], &sw_out_list[158], &sw_out_list[159], &sw_out_list[160], &sw_out_list[161], &sw_out_list[162], &sw_out_list[163], &sw_out_list[164], &sw_out_list[165], &sw_out_list[166], &sw_out_list[167], &sw_out_list[168], &sw_out_list[169], &sw_out_list[170], &sw_out_list[171], &sw_out_list[172], &sw_out_list[173], &sw_out_list[174], &sw_out_list[175], &sw_out_list[176], &sw_out_list[177], &sw_out_list[178], &sw_out_list[179], &sw_out_list[180], &sw_out_list[181], &sw_out_list[182], &sw_out_list[183], &sw_out_list[184], &sw_out_list[185], &sw_out_list[186], &sw_out_list[187], &sw_out_list[188], &sw_out_list[189], &sw_out_list[190], &sw_out_list[191], &sw_out_list[192], &sw_out_list[193], &sw_out_list[194], &sw_out_list[195], &sw_out_list[196], &sw_out_list[197], &sw_out_list[198], &sw_out_list[199], &sw_out_list[200], &sw_out_list[201], &sw_out_list[202], &sw_out_list[203], &sw_out_list[204], &sw_out_list[205], &sw_out_list[206], &sw_out_list[207], &sw_out_list[208], &sw_out_list[209], &sw_out_list[210], &sw_out_list[211], &sw_out_list[212], &sw_out_list[213], &sw_out_list[214], &sw_out_list[215], &sw_out_list[216], &sw_out_list[217], &sw_out_list[218], &sw_out_list[219], &sw_out_list[220], &sw_out_list[221], &sw_out_list[222], &sw_out_list[223], &sw_out_list[224], &sw_out_list[225], &sw_out_list[226], &sw_out_list[227], &sw_out_list[228], &sw_out_list[229], &sw_out_list[230], &sw_out_list[231], &sw_out_list[232], &sw_out_list[233], &sw_out_list[234], &sw_out_list[235], &sw_out_list[236], &sw_out_list[237], &sw_out_list[238], &sw_out_list[239], &sw_out_list[240], &sw_out_list[241], &sw_out_list[242], &sw_out_list[243], &sw_out_list[244], &sw_out_list[245], &sw_out_list[246], &sw_out_list[247], &sw_out_list[248], &sw_out_list[249], &sw_out_list[250], &sw_out_list[251], &sw_out_list[252], &sw_out_list[253], &sw_out_list[254], &sw_out_list[255]);
	TEST_ASSERT (sw_retval == 0);
	while (hwdll_probe (idx_list[i])) {}
	hw_retval = hwdll_read (idx_list[i], hw_out_list);
	TEST_ASSERT (hw_retval == 256 && sw_out_list[0] == hw_out_list[0] && sw_out_list[1] == hw_out_list[1] && sw_out_list[2] == hw_out_list[2] && sw_out_list[3] == hw_out_list[3] && sw_out_list[4] == hw_out_list[4] && sw_out_list[5] == hw_out_list[5] && sw_out_list[6] == hw_out_list[6] && sw_out_list[7] == hw_out_list[7] && sw_out_list[8] == hw_out_list[8] && sw_out_list[9] == hw_out_list[9] && sw_out_list[10] == hw_out_list[10] && sw_out_list[11] == hw_out_list[11] && sw_out_list[12] == hw_out_list[12] && sw_out_list[13] == hw_out_list[13] && sw_out_list[14] == hw_out_list[14] && sw_out_list[15] == hw_out_list[15] && sw_out_list[16] == hw_out_list[16] && sw_out_list[17] == hw_out_list[17] && sw_out_list[18] == hw_out_list[18] && sw_out_list[19] == hw_out_list[19] && sw_out_list[20] == hw_out_list[20] && sw_out_list[21] == hw_out_list[21] && sw_out_list[22] == hw_out_list[22] && sw_out_list[23] == hw_out_list[23] && sw_out_list[24] == hw_out_list[24] && sw_out_list[25] == hw_out_list[25] && sw_out_list[26] == hw_out_list[26] && sw_out_list[27] == hw_out_list[27] && sw_out_list[28] == hw_out_list[28] && sw_out_list[29] == hw_out_list[29] && sw_out_list[30] == hw_out_list[30] && sw_out_list[31] == hw_out_list[31] && sw_out_list[32] == hw_out_list[32] && sw_out_list[33] == hw_out_list[33] && sw_out_list[34] == hw_out_list[34] && sw_out_list[35] == hw_out_list[35] && sw_out_list[36] == hw_out_list[36] && sw_out_list[37] == hw_out_list[37] && sw_out_list[38] == hw_out_list[38] && sw_out_list[39] == hw_out_list[39] && sw_out_list[40] == hw_out_list[40] && sw_out_list[41] == hw_out_list[41] && sw_out_list[42] == hw_out_list[42] && sw_out_list[43] == hw_out_list[43] && sw_out_list[44] == hw_out_list[44] && sw_out_list[45] == hw_out_list[45] && sw_out_list[46] == hw_out_list[46] && sw_out_list[47] == hw_out_list[47] && sw_out_list[48] == hw_out_list[48] && sw_out_list[49] == hw_out_list[49] && sw_out_list[50] == hw_out_list[50] && sw_out_list[51] == hw_out_list[51] && sw_out_list[52] == hw_out_list[52] && sw_out_list[53] == hw_out_list[53] && sw_out_list[54] == hw_out_list[54] && sw_out_list[55] == hw_out_list[55] && sw_out_list[56] == hw_out_list[56] && sw_out_list[57] == hw_out_list[57] && sw_out_list[58] == hw_out_list[58] && sw_out_list[59] == hw_out_list[59] && sw_out_list[60] == hw_out_list[60] && sw_out_list[61] == hw_out_list[61] && sw_out_list[62] == hw_out_list[62] && sw_out_list[63] == hw_out_list[63] && sw_out_list[64] == hw_out_list[64] && sw_out_list[65] == hw_out_list[65] && sw_out_list[66] == hw_out_list[66] && sw_out_list[67] == hw_out_list[67] && sw_out_list[68] == hw_out_list[68] && sw_out_list[69] == hw_out_list[69] && sw_out_list[70] == hw_out_list[70] && sw_out_list[71] == hw_out_list[71] && sw_out_list[72] == hw_out_list[72] && sw_out_list[73] == hw_out_list[73] && sw_out_list[74] == hw_out_list[74] && sw_out_list[75] == hw_out_list[75] && sw_out_list[76] == hw_out_list[76] && sw_out_list[77] == hw_out_list[77] && sw_out_list[78] == hw_out_list[78] && sw_out_list[79] == hw_out_list[79] && sw_out_list[80] == hw_out_list[80] && sw_out_list[81] == hw_out_list[81] && sw_out_list[82] == hw_out_list[82] && sw_out_list[83] == hw_out_list[83] && sw_out_list[84] == hw_out_list[84] && sw_out_list[85] == hw_out_list[85] && sw_out_list[86] == hw_out_list[86] && sw_out_list[87] == hw_out_list[87] && sw_out_list[88] == hw_out_list[88] && sw_out_list[89] == hw_out_list[89] && sw_out_list[90] == hw_out_list[90] && sw_out_list[91] == hw_out_list[91] && sw_out_list[92] == hw_out_list[92] && sw_out_list[93] == hw_out_list[93] && sw_out_list[94] == hw_out_list[94] && sw_out_list[95] == hw_out_list[95] && sw_out_list[96] == hw_out_list[96] && sw_out_list[97] == hw_out_list[97] && sw_out_list[98] == hw_out_list[98] && sw_out_list[99] == hw_out_list[99] && sw_out_list[100] == hw_out_list[100] && sw_out_list[101] == hw_out_list[101] && sw_out_list[102] == hw_out_list[102] && sw_out_list[103] == hw_out_list[103] && sw_out_list[104] == hw_out_list[104] && sw_out_list[105] == hw_out_list[105] && sw_out_list[106] == hw_out_list[106] && sw_out_list[107] == hw_out_list[107] && sw_out_list[108] == hw_out_list[108] && sw_out_list[109] == hw_out_list[109] && sw_out_list[110] == hw_out_list[110] && sw_out_list[111] == hw_out_list[111] && sw_out_list[112] == hw_out_list[112] && sw_out_list[113] == hw_out_list[113] && sw_out_list[114] == hw_out_list[114] && sw_out_list[115] == hw_out_list[115] && sw_out_list[116] == hw_out_list[116] && sw_out_list[117] == hw_out_list[117] && sw_out_list[118] == hw_out_list[118] && sw_out_list[119] == hw_out_list[119] && sw_out_list[120] == hw_out_list[120] && sw_out_list[121] == hw_out_list[121] && sw_out_list[122] == hw_out_list[122] && sw_out_list[123] == hw_out_list[123] && sw_out_list[124] == hw_out_list[124] && sw_out_list[125] == hw_out_list[125] && sw_out_list[126] == hw_out_list[126] && sw_out_list[127] == hw_out_list[127] && sw_out_list[128] == hw_out_list[128] && sw_out_list[129] == hw_out_list[129] && sw_out_list[130] == hw_out_list[130] && sw_out_list[131] == hw_out_list[131] && sw_out_list[132] == hw_out_list[132] && sw_out_list[133] == hw_out_list[133] && sw_out_list[134] == hw_out_list[134] && sw_out_list[135] == hw_out_list[135] && sw_out_list[136] == hw_out_list[136] && sw_out_list[137] == hw_out_list[137] && sw_out_list[138] == hw_out_list[138] && sw_out_list[139] == hw_out_list[139] && sw_out_list[140] == hw_out_list[140] && sw_out_list[141] == hw_out_list[141] && sw_out_list[142] == hw_out_list[142] && sw_out_list[143] == hw_out_list[143] && sw_out_list[144] == hw_out_list[144] && sw_out_list[145] == hw_out_list[145] && sw_out_list[146] == hw_out_list[146] && sw_out_list[147] == hw_out_list[147] && sw_out_list[148] == hw_out_list[148] && sw_out_list[149] == hw_out_list[149] && sw_out_list[150] == hw_out_list[150] && sw_out_list[151] == hw_out_list[151] && sw_out_list[152] == hw_out_list[152] && sw_out_list[153] == hw_out_list[153] && sw_out_list[154] == hw_out_list[154] && sw_out_list[155] == hw_out_list[155] && sw_out_list[156] == hw_out_list[156] && sw_out_list[157] == hw_out_list[157] && sw_out_list[158] == hw_out_list[158] && sw_out_list[159] == hw_out_list[159] && sw_out_list[160] == hw_out_list[160] && sw_out_list[161] == hw_out_list[161] && sw_out_list[162] == hw_out_list[162] && sw_out_list[163] == hw_out_list[163] && sw_out_list[164] == hw_out_list[164] && sw_out_list[165] == hw_out_list[165] && sw_out_list[166] == hw_out_list[166] && sw_out_list[167] == hw_out_list[167] && sw_out_list[168] == hw_out_list[168] && sw_out_list[169] == hw_out_list[169] && sw_out_list[170] == hw_out_list[170] && sw_out_list[171] == hw_out_list[171] && sw_out_list[172] == hw_out_list[172] && sw_out_list[173] == hw_out_list[173] && sw_out_list[174] == hw_out_list[174] && sw_out_list[175] == hw_out_list[175] && sw_out_list[176] == hw_out_list[176] && sw_out_list[177] == hw_out_list[177] && sw_out_list[178] == hw_out_list[178] && sw_out_list[179] == hw_out_list[179] && sw_out_list[180] == hw_out_list[180] && sw_out_list[181] == hw_out_list[181] && sw_out_list[182] == hw_out_list[182] && sw_out_list[183] == hw_out_list[183] && sw_out_list[184] == hw_out_list[184] && sw_out_list[185] == hw_out_list[185] && sw_out_list[186] == hw_out_list[186] && sw_out_list[187] == hw_out_list[187] && sw_out_list[188] == hw_out_list[188] && sw_out_list[189] == hw_out_list[189] && sw_out_list[190] == hw_out_list[190] && sw_out_list[191] == hw_out_list[191] && sw_out_list[192] == hw_out_list[192] && sw_out_list[193] == hw_out_list[193] && sw_out_list[194] == hw_out_list[194] && sw_out_list[195] == hw_out_list[195] && sw_out_list[196] == hw_out_list[196] && sw_out_list[197] == hw_out_list[197] && sw_out_list[198] == hw_out_list[198] && sw_out_list[199] == hw_out_list[199] && sw_out_list[200] == hw_out_list[200] && sw_out_list[201] == hw_out_list[201] && sw_out_list[202] == hw_out_list[202] && sw_out_list[203] == hw_out_list[203] && sw_out_list[204] == hw_out_list[204] && sw_out_list[205] == hw_out_list[205] && sw_out_list[206] == hw_out_list[206] && sw_out_list[207] == hw_out_list[207] && sw_out_list[208] == hw_out_list[208] && sw_out_list[209] == hw_out_list[209] && sw_out_list[210] == hw_out_list[210] && sw_out_list[211] == hw_out_list[211] && sw_out_list[212] == hw_out_list[212] && sw_out_list[213] == hw_out_list[213] && sw_out_list[214] == hw_out_list[214] && sw_out_list[215] == hw_out_list[215] && sw_out_list[216] == hw_out_list[216] && sw_out_list[217] == hw_out_list[217] && sw_out_list[218] == hw_out_list[218] && sw_out_list[219] == hw_out_list[219] && sw_out_list[220] == hw_out_list[220] && sw_out_list[221] == hw_out_list[221] && sw_out_list[222] == hw_out_list[222] && sw_out_list[223] == hw_out_list[223] && sw_out_list[224] == hw_out_list[224] && sw_out_list[225] == hw_out_list[225] && sw_out_list[226] == hw_out_list[226] && sw_out_list[227] == hw_out_list[227] && sw_out_list[228] == hw_out_list[228] && sw_out_list[229] == hw_out_list[229] && sw_out_list[230] == hw_out_list[230] && sw_out_list[231] == hw_out_list[231] && sw_out_list[232] == hw_out_list[232] && sw_out_list[233] == hw_out_list[233] && sw_out_list[234] == hw_out_list[234] && sw_out_list[235] == hw_out_list[235] && sw_out_list[236] == hw_out_list[236] && sw_out_list[237] == hw_out_list[237] && sw_out_list[238] == hw_out_list[238] && sw_out_list[239] == hw_out_list[239] && sw_out_list[240] == hw_out_list[240] && sw_out_list[241] == hw_out_list[241] && sw_out_list[242] == hw_out_list[242] && sw_out_list[243] == hw_out_list[243] && sw_out_list[244] == hw_out_list[244] && sw_out_list[245] == hw_out_list[245] && sw_out_list[246] == hw_out_list[246] && sw_out_list[247] == hw_out_list[247] && sw_out_list[248] == hw_out_list[248] && sw_out_list[249] == hw_out_list[249] && sw_out_list[250] == hw_out_list[250] && sw_out_list[251] == hw_out_list[251] && sw_out_list[252] == hw_out_list[252] && sw_out_list[253] == hw_out_list[253] && sw_out_list[254] == hw_out_list[254] && sw_out_list[255] == hw_out_list[255]);
	i = 2; /* Evaluate Int Max																													*/
	sw_retval = int_max (&sw_out_list[0]);
	TEST_ASSERT (sw_retval == 0);
	while (hwdll_probe (idx_list[i])) {}
	hw_retval = hwdll_read (idx_list[i], hw_out_list);
	TEST_ASSERT (hw_retval == 1 && sw_out_list[0] == hw_out_list[0]);
	i = 3; /* Evaluate Adder Subtractor																									*/
	sw_retval = adder_subtractor (in_list[0], in_list[1], &sw_out_list[0], &sw_out_list[1]);
	TEST_ASSERT (sw_retval == 0);
	hw_retval = hwdll_write (idx_list[i], in_list);
	TEST_ASSERT (hw_retval == 2);
	while (hwdll_probe (idx_list[i])) {}
	hw_retval = hwdll_read (idx_list[i], hw_out_list);
	TEST_ASSERT (hw_retval == 2 && sw_out_list[0] == hw_out_list[0] && sw_out_list[1] == hw_out_list[1]);
	i = 4; /* Evaluate Multiplier																												*/
	sw_retval = multiplier (in_list[0], in_list[1], &sw_out_list[0]);
	TEST_ASSERT (sw_retval == 0);
	hw_retval = hwdll_write (idx_list[i], in_list);
	TEST_ASSERT (hw_retval == 2);
	while (hwdll_probe (idx_list[i])) {}
	hw_retval = hwdll_read (idx_list[i], hw_out_list);
	TEST_ASSERT (hw_retval == 1 && sw_out_list[0] == hw_out_list[0]);
	i = 5; /* Evaluate Bitwise Right Shift																									*/
	sw_retval = bitwise_right_shift (in_list[0], &sw_out_list[0]);
	TEST_ASSERT (sw_retval == 0);
	hw_retval = hwdll_write (idx_list[i], in_list);
	TEST_ASSERT (hw_retval == 1);
	while (hwdll_probe (idx_list[i])) {}
	hw_retval = hwdll_read (idx_list[i], hw_out_list);
	TEST_ASSERT (hw_retval == 1 && sw_out_list[0] == hw_out_list[0]);
	i = 6; /* Evaluate Greatest Common Divisor																						*/
	sw_retval = gcd (in_list[0], in_list[1], &sw_out_list[0]);
	TEST_ASSERT (sw_retval == 0);
	hw_retval = hwdll_write (idx_list[i], in_list);
	TEST_ASSERT (hw_retval == 2);
	while (hwdll_probe (idx_list[i])) {}
	hw_retval = hwdll_read (idx_list[i], hw_out_list);
	TEST_ASSERT (hw_retval == 1 && sw_out_list[0] == hw_out_list[0]);
	i = 7; /* Evaluate Fibonacci																												*/
	sw_retval = fibonacci (in_list[0], &sw_out_list[0]);
	TEST_ASSERT (sw_retval == 0);
	hw_retval = hwdll_write (idx_list[i], in_list);
	TEST_ASSERT (hw_retval == 1);
	while (hwdll_probe (idx_list[i])) {}
	hw_retval = hwdll_read (idx_list[i], hw_out_list);
	TEST_ASSERT (hw_retval == 1 && sw_out_list[0] == hw_out_list[0]);
	i = 8; /* Evaluate Prime																													*/
	sw_retval = prime (in_list[0], &sw_out_list[0]);
	TEST_ASSERT (sw_retval == 0);
	hw_retval = hwdll_write (idx_list[i], in_list);
	TEST_ASSERT (hw_retval == 1);
	while (hwdll_probe (idx_list[i])) {}
	hw_retval = hwdll_read (idx_list[i], hw_out_list);
	TEST_ASSERT (hw_retval == 1 && sw_out_list[0] == hw_out_list[0]);
	i = 9; /* Evaluate Prime Neighbours																									*/
	sw_retval = prime_neighbours (in_list[0], &sw_out_list[0], &sw_out_list[1]);
	TEST_ASSERT (sw_retval == -1);
	hw_retval = hwdll_write (idx_list[i], in_list);
	TEST_ASSERT (hw_retval == 1);
	while (hwdll_probe (idx_list[i])) {}
	hw_retval = hwdll_read (idx_list[i], hw_out_list);
	TEST_ASSERT (hw_retval == 2 && sw_out_list[0] == hw_out_list[0] && sw_out_list[1] == hw_out_list[1]);
	in_list[0] = 64;
	in_list[1] = 16;
	i = 0; /* Reevaluate Dummy																												*/
	sw_retval = dummy (&sw_out_list[0], &sw_out_list[1], &sw_out_list[2], &sw_out_list[3], &sw_out_list[4], &sw_out_list[5], &sw_out_list[6], &sw_out_list[7], &sw_out_list[8], &sw_out_list[9], &sw_out_list[10], &sw_out_list[11], &sw_out_list[12], &sw_out_list[13], &sw_out_list[14], &sw_out_list[15], &sw_out_list[16], &sw_out_list[17], &sw_out_list[18], &sw_out_list[19], &sw_out_list[20], &sw_out_list[21], &sw_out_list[22], &sw_out_list[23], &sw_out_list[24], &sw_out_list[25], &sw_out_list[26], &sw_out_list[27], &sw_out_list[28], &sw_out_list[29], &sw_out_list[30], &sw_out_list[31], &sw_out_list[32], &sw_out_list[33], &sw_out_list[34], &sw_out_list[35], &sw_out_list[36], &sw_out_list[37], &sw_out_list[38], &sw_out_list[39], &sw_out_list[40], &sw_out_list[41], &sw_out_list[42], &sw_out_list[43], &sw_out_list[44], &sw_out_list[45], &sw_out_list[46], &sw_out_list[47], &sw_out_list[48], &sw_out_list[49], &sw_out_list[50], &sw_out_list[51], &sw_out_list[52], &sw_out_list[53], &sw_out_list[54], &sw_out_list[55], &sw_out_list[56], &sw_out_list[57], &sw_out_list[58], &sw_out_list[59], &sw_out_list[60], &sw_out_list[61], &sw_out_list[62], &sw_out_list[63], &sw_out_list[64], &sw_out_list[65], &sw_out_list[66], &sw_out_list[67], &sw_out_list[68], &sw_out_list[69], &sw_out_list[70], &sw_out_list[71], &sw_out_list[72], &sw_out_list[73], &sw_out_list[74], &sw_out_list[75], &sw_out_list[76], &sw_out_list[77], &sw_out_list[78], &sw_out_list[79], &sw_out_list[80], &sw_out_list[81], &sw_out_list[82], &sw_out_list[83], &sw_out_list[84], &sw_out_list[85], &sw_out_list[86], &sw_out_list[87], &sw_out_list[88], &sw_out_list[89], &sw_out_list[90], &sw_out_list[91], &sw_out_list[92], &sw_out_list[93], &sw_out_list[94], &sw_out_list[95], &sw_out_list[96], &sw_out_list[97], &sw_out_list[98], &sw_out_list[99], &sw_out_list[100], &sw_out_list[101], &sw_out_list[102], &sw_out_list[103], &sw_out_list[104], &sw_out_list[105], &sw_out_list[106], &sw_out_list[107], &sw_out_list[108], &sw_out_list[109], &sw_out_list[110], &sw_out_list[111], &sw_out_list[112], &sw_out_list[113], &sw_out_list[114], &sw_out_list[115], &sw_out_list[116], &sw_out_list[117], &sw_out_list[118], &sw_out_list[119], &sw_out_list[120], &sw_out_list[121], &sw_out_list[122], &sw_out_list[123], &sw_out_list[124], &sw_out_list[125], &sw_out_list[126], &sw_out_list[127], &sw_out_list[128], &sw_out_list[129], &sw_out_list[130], &sw_out_list[131], &sw_out_list[132], &sw_out_list[133], &sw_out_list[134], &sw_out_list[135], &sw_out_list[136], &sw_out_list[137], &sw_out_list[138], &sw_out_list[139], &sw_out_list[140], &sw_out_list[141], &sw_out_list[142], &sw_out_list[143], &sw_out_list[144], &sw_out_list[145], &sw_out_list[146], &sw_out_list[147], &sw_out_list[148], &sw_out_list[149], &sw_out_list[150], &sw_out_list[151], &sw_out_list[152], &sw_out_list[153], &sw_out_list[154], &sw_out_list[155], &sw_out_list[156], &sw_out_list[157], &sw_out_list[158], &sw_out_list[159], &sw_out_list[160], &sw_out_list[161], &sw_out_list[162], &sw_out_list[163], &sw_out_list[164], &sw_out_list[165], &sw_out_list[166], &sw_out_list[167], &sw_out_list[168], &sw_out_list[169], &sw_out_list[170], &sw_out_list[171], &sw_out_list[172], &sw_out_list[173], &sw_out_list[174], &sw_out_list[175], &sw_out_list[176], &sw_out_list[177], &sw_out_list[178], &sw_out_list[179], &sw_out_list[180], &sw_out_list[181], &sw_out_list[182], &sw_out_list[183], &sw_out_list[184], &sw_out_list[185], &sw_out_list[186], &sw_out_list[187], &sw_out_list[188], &sw_out_list[189], &sw_out_list[190], &sw_out_list[191], &sw_out_list[192], &sw_out_list[193], &sw_out_list[194], &sw_out_list[195], &sw_out_list[196], &sw_out_list[197], &sw_out_list[198], &sw_out_list[199], &sw_out_list[200], &sw_out_list[201], &sw_out_list[202], &sw_out_list[203], &sw_out_list[204], &sw_out_list[205], &sw_out_list[206], &sw_out_list[207], &sw_out_list[208], &sw_out_list[209], &sw_out_list[210], &sw_out_list[211], &sw_out_list[212], &sw_out_list[213], &sw_out_list[214], &sw_out_list[215], &sw_out_list[216], &sw_out_list[217], &sw_out_list[218], &sw_out_list[219], &sw_out_list[220], &sw_out_list[221], &sw_out_list[222], &sw_out_list[223], &sw_out_list[224], &sw_out_list[225], &sw_out_list[226], &sw_out_list[227], &sw_out_list[228], &sw_out_list[229], &sw_out_list[230], &sw_out_list[231], &sw_out_list[232], &sw_out_list[233], &sw_out_list[234], &sw_out_list[235], &sw_out_list[236], &sw_out_list[237], &sw_out_list[238], &sw_out_list[239], &sw_out_list[240], &sw_out_list[241], &sw_out_list[242], &sw_out_list[243], &sw_out_list[244], &sw_out_list[245], &sw_out_list[246], &sw_out_list[247], &sw_out_list[248], &sw_out_list[249], &sw_out_list[250], &sw_out_list[251], &sw_out_list[252], &sw_out_list[253], &sw_out_list[254], &sw_out_list[255]);
	TEST_ASSERT (sw_retval == 0);
	hw_retval = hwdll_write (idx_list[i], in_list);
	TEST_ASSERT (hw_retval == 0);
	while (hwdll_probe (idx_list[i])) {}
	hw_retval = hwdll_read (idx_list[i], hw_out_list);
	TEST_ASSERT (hw_retval == 256 && sw_out_list[0] == hw_out_list[0] && sw_out_list[1] == hw_out_list[1] && sw_out_list[2] == hw_out_list[2] && sw_out_list[3] == hw_out_list[3] && sw_out_list[4] == hw_out_list[4] && sw_out_list[5] == hw_out_list[5] && sw_out_list[6] == hw_out_list[6] && sw_out_list[7] == hw_out_list[7] && sw_out_list[8] == hw_out_list[8] && sw_out_list[9] == hw_out_list[9] && sw_out_list[10] == hw_out_list[10] && sw_out_list[11] == hw_out_list[11] && sw_out_list[12] == hw_out_list[12] && sw_out_list[13] == hw_out_list[13] && sw_out_list[14] == hw_out_list[14] && sw_out_list[15] == hw_out_list[15] && sw_out_list[16] == hw_out_list[16] && sw_out_list[17] == hw_out_list[17] && sw_out_list[18] == hw_out_list[18] && sw_out_list[19] == hw_out_list[19] && sw_out_list[20] == hw_out_list[20] && sw_out_list[21] == hw_out_list[21] && sw_out_list[22] == hw_out_list[22] && sw_out_list[23] == hw_out_list[23] && sw_out_list[24] == hw_out_list[24] && sw_out_list[25] == hw_out_list[25] && sw_out_list[26] == hw_out_list[26] && sw_out_list[27] == hw_out_list[27] && sw_out_list[28] == hw_out_list[28] && sw_out_list[29] == hw_out_list[29] && sw_out_list[30] == hw_out_list[30] && sw_out_list[31] == hw_out_list[31] && sw_out_list[32] == hw_out_list[32] && sw_out_list[33] == hw_out_list[33] && sw_out_list[34] == hw_out_list[34] && sw_out_list[35] == hw_out_list[35] && sw_out_list[36] == hw_out_list[36] && sw_out_list[37] == hw_out_list[37] && sw_out_list[38] == hw_out_list[38] && sw_out_list[39] == hw_out_list[39] && sw_out_list[40] == hw_out_list[40] && sw_out_list[41] == hw_out_list[41] && sw_out_list[42] == hw_out_list[42] && sw_out_list[43] == hw_out_list[43] && sw_out_list[44] == hw_out_list[44] && sw_out_list[45] == hw_out_list[45] && sw_out_list[46] == hw_out_list[46] && sw_out_list[47] == hw_out_list[47] && sw_out_list[48] == hw_out_list[48] && sw_out_list[49] == hw_out_list[49] && sw_out_list[50] == hw_out_list[50] && sw_out_list[51] == hw_out_list[51] && sw_out_list[52] == hw_out_list[52] && sw_out_list[53] == hw_out_list[53] && sw_out_list[54] == hw_out_list[54] && sw_out_list[55] == hw_out_list[55] && sw_out_list[56] == hw_out_list[56] && sw_out_list[57] == hw_out_list[57] && sw_out_list[58] == hw_out_list[58] && sw_out_list[59] == hw_out_list[59] && sw_out_list[60] == hw_out_list[60] && sw_out_list[61] == hw_out_list[61] && sw_out_list[62] == hw_out_list[62] && sw_out_list[63] == hw_out_list[63] && sw_out_list[64] == hw_out_list[64] && sw_out_list[65] == hw_out_list[65] && sw_out_list[66] == hw_out_list[66] && sw_out_list[67] == hw_out_list[67] && sw_out_list[68] == hw_out_list[68] && sw_out_list[69] == hw_out_list[69] && sw_out_list[70] == hw_out_list[70] && sw_out_list[71] == hw_out_list[71] && sw_out_list[72] == hw_out_list[72] && sw_out_list[73] == hw_out_list[73] && sw_out_list[74] == hw_out_list[74] && sw_out_list[75] == hw_out_list[75] && sw_out_list[76] == hw_out_list[76] && sw_out_list[77] == hw_out_list[77] && sw_out_list[78] == hw_out_list[78] && sw_out_list[79] == hw_out_list[79] && sw_out_list[80] == hw_out_list[80] && sw_out_list[81] == hw_out_list[81] && sw_out_list[82] == hw_out_list[82] && sw_out_list[83] == hw_out_list[83] && sw_out_list[84] == hw_out_list[84] && sw_out_list[85] == hw_out_list[85] && sw_out_list[86] == hw_out_list[86] && sw_out_list[87] == hw_out_list[87] && sw_out_list[88] == hw_out_list[88] && sw_out_list[89] == hw_out_list[89] && sw_out_list[90] == hw_out_list[90] && sw_out_list[91] == hw_out_list[91] && sw_out_list[92] == hw_out_list[92] && sw_out_list[93] == hw_out_list[93] && sw_out_list[94] == hw_out_list[94] && sw_out_list[95] == hw_out_list[95] && sw_out_list[96] == hw_out_list[96] && sw_out_list[97] == hw_out_list[97] && sw_out_list[98] == hw_out_list[98] && sw_out_list[99] == hw_out_list[99] && sw_out_list[100] == hw_out_list[100] && sw_out_list[101] == hw_out_list[101] && sw_out_list[102] == hw_out_list[102] && sw_out_list[103] == hw_out_list[103] && sw_out_list[104] == hw_out_list[104] && sw_out_list[105] == hw_out_list[105] && sw_out_list[106] == hw_out_list[106] && sw_out_list[107] == hw_out_list[107] && sw_out_list[108] == hw_out_list[108] && sw_out_list[109] == hw_out_list[109] && sw_out_list[110] == hw_out_list[110] && sw_out_list[111] == hw_out_list[111] && sw_out_list[112] == hw_out_list[112] && sw_out_list[113] == hw_out_list[113] && sw_out_list[114] == hw_out_list[114] && sw_out_list[115] == hw_out_list[115] && sw_out_list[116] == hw_out_list[116] && sw_out_list[117] == hw_out_list[117] && sw_out_list[118] == hw_out_list[118] && sw_out_list[119] == hw_out_list[119] && sw_out_list[120] == hw_out_list[120] && sw_out_list[121] == hw_out_list[121] && sw_out_list[122] == hw_out_list[122] && sw_out_list[123] == hw_out_list[123] && sw_out_list[124] == hw_out_list[124] && sw_out_list[125] == hw_out_list[125] && sw_out_list[126] == hw_out_list[126] && sw_out_list[127] == hw_out_list[127] && sw_out_list[128] == hw_out_list[128] && sw_out_list[129] == hw_out_list[129] && sw_out_list[130] == hw_out_list[130] && sw_out_list[131] == hw_out_list[131] && sw_out_list[132] == hw_out_list[132] && sw_out_list[133] == hw_out_list[133] && sw_out_list[134] == hw_out_list[134] && sw_out_list[135] == hw_out_list[135] && sw_out_list[136] == hw_out_list[136] && sw_out_list[137] == hw_out_list[137] && sw_out_list[138] == hw_out_list[138] && sw_out_list[139] == hw_out_list[139] && sw_out_list[140] == hw_out_list[140] && sw_out_list[141] == hw_out_list[141] && sw_out_list[142] == hw_out_list[142] && sw_out_list[143] == hw_out_list[143] && sw_out_list[144] == hw_out_list[144] && sw_out_list[145] == hw_out_list[145] && sw_out_list[146] == hw_out_list[146] && sw_out_list[147] == hw_out_list[147] && sw_out_list[148] == hw_out_list[148] && sw_out_list[149] == hw_out_list[149] && sw_out_list[150] == hw_out_list[150] && sw_out_list[151] == hw_out_list[151] && sw_out_list[152] == hw_out_list[152] && sw_out_list[153] == hw_out_list[153] && sw_out_list[154] == hw_out_list[154] && sw_out_list[155] == hw_out_list[155] && sw_out_list[156] == hw_out_list[156] && sw_out_list[157] == hw_out_list[157] && sw_out_list[158] == hw_out_list[158] && sw_out_list[159] == hw_out_list[159] && sw_out_list[160] == hw_out_list[160] && sw_out_list[161] == hw_out_list[161] && sw_out_list[162] == hw_out_list[162] && sw_out_list[163] == hw_out_list[163] && sw_out_list[164] == hw_out_list[164] && sw_out_list[165] == hw_out_list[165] && sw_out_list[166] == hw_out_list[166] && sw_out_list[167] == hw_out_list[167] && sw_out_list[168] == hw_out_list[168] && sw_out_list[169] == hw_out_list[169] && sw_out_list[170] == hw_out_list[170] && sw_out_list[171] == hw_out_list[171] && sw_out_list[172] == hw_out_list[172] && sw_out_list[173] == hw_out_list[173] && sw_out_list[174] == hw_out_list[174] && sw_out_list[175] == hw_out_list[175] && sw_out_list[176] == hw_out_list[176] && sw_out_list[177] == hw_out_list[177] && sw_out_list[178] == hw_out_list[178] && sw_out_list[179] == hw_out_list[179] && sw_out_list[180] == hw_out_list[180] && sw_out_list[181] == hw_out_list[181] && sw_out_list[182] == hw_out_list[182] && sw_out_list[183] == hw_out_list[183] && sw_out_list[184] == hw_out_list[184] && sw_out_list[185] == hw_out_list[185] && sw_out_list[186] == hw_out_list[186] && sw_out_list[187] == hw_out_list[187] && sw_out_list[188] == hw_out_list[188] && sw_out_list[189] == hw_out_list[189] && sw_out_list[190] == hw_out_list[190] && sw_out_list[191] == hw_out_list[191] && sw_out_list[192] == hw_out_list[192] && sw_out_list[193] == hw_out_list[193] && sw_out_list[194] == hw_out_list[194] && sw_out_list[195] == hw_out_list[195] && sw_out_list[196] == hw_out_list[196] && sw_out_list[197] == hw_out_list[197] && sw_out_list[198] == hw_out_list[198] && sw_out_list[199] == hw_out_list[199] && sw_out_list[200] == hw_out_list[200] && sw_out_list[201] == hw_out_list[201] && sw_out_list[202] == hw_out_list[202] && sw_out_list[203] == hw_out_list[203] && sw_out_list[204] == hw_out_list[204] && sw_out_list[205] == hw_out_list[205] && sw_out_list[206] == hw_out_list[206] && sw_out_list[207] == hw_out_list[207] && sw_out_list[208] == hw_out_list[208] && sw_out_list[209] == hw_out_list[209] && sw_out_list[210] == hw_out_list[210] && sw_out_list[211] == hw_out_list[211] && sw_out_list[212] == hw_out_list[212] && sw_out_list[213] == hw_out_list[213] && sw_out_list[214] == hw_out_list[214] && sw_out_list[215] == hw_out_list[215] && sw_out_list[216] == hw_out_list[216] && sw_out_list[217] == hw_out_list[217] && sw_out_list[218] == hw_out_list[218] && sw_out_list[219] == hw_out_list[219] && sw_out_list[220] == hw_out_list[220] && sw_out_list[221] == hw_out_list[221] && sw_out_list[222] == hw_out_list[222] && sw_out_list[223] == hw_out_list[223] && sw_out_list[224] == hw_out_list[224] && sw_out_list[225] == hw_out_list[225] && sw_out_list[226] == hw_out_list[226] && sw_out_list[227] == hw_out_list[227] && sw_out_list[228] == hw_out_list[228] && sw_out_list[229] == hw_out_list[229] && sw_out_list[230] == hw_out_list[230] && sw_out_list[231] == hw_out_list[231] && sw_out_list[232] == hw_out_list[232] && sw_out_list[233] == hw_out_list[233] && sw_out_list[234] == hw_out_list[234] && sw_out_list[235] == hw_out_list[235] && sw_out_list[236] == hw_out_list[236] && sw_out_list[237] == hw_out_list[237] && sw_out_list[238] == hw_out_list[238] && sw_out_list[239] == hw_out_list[239] && sw_out_list[240] == hw_out_list[240] && sw_out_list[241] == hw_out_list[241] && sw_out_list[242] == hw_out_list[242] && sw_out_list[243] == hw_out_list[243] && sw_out_list[244] == hw_out_list[244] && sw_out_list[245] == hw_out_list[245] && sw_out_list[246] == hw_out_list[246] && sw_out_list[247] == hw_out_list[247] && sw_out_list[248] == hw_out_list[248] && sw_out_list[249] == hw_out_list[249] && sw_out_list[250] == hw_out_list[250] && sw_out_list[251] == hw_out_list[251] && sw_out_list[252] == hw_out_list[252] && sw_out_list[253] == hw_out_list[253] && sw_out_list[254] == hw_out_list[254] && sw_out_list[255] == hw_out_list[255]);
	i = 1; /* Reevaluate Numbers																											*/
	sw_retval = numbers (&sw_out_list[0], &sw_out_list[1], &sw_out_list[2], &sw_out_list[3], &sw_out_list[4], &sw_out_list[5], &sw_out_list[6], &sw_out_list[7], &sw_out_list[8], &sw_out_list[9], &sw_out_list[10], &sw_out_list[11], &sw_out_list[12], &sw_out_list[13], &sw_out_list[14], &sw_out_list[15], &sw_out_list[16], &sw_out_list[17], &sw_out_list[18], &sw_out_list[19], &sw_out_list[20], &sw_out_list[21], &sw_out_list[22], &sw_out_list[23], &sw_out_list[24], &sw_out_list[25], &sw_out_list[26], &sw_out_list[27], &sw_out_list[28], &sw_out_list[29], &sw_out_list[30], &sw_out_list[31], &sw_out_list[32], &sw_out_list[33], &sw_out_list[34], &sw_out_list[35], &sw_out_list[36], &sw_out_list[37], &sw_out_list[38], &sw_out_list[39], &sw_out_list[40], &sw_out_list[41], &sw_out_list[42], &sw_out_list[43], &sw_out_list[44], &sw_out_list[45], &sw_out_list[46], &sw_out_list[47], &sw_out_list[48], &sw_out_list[49], &sw_out_list[50], &sw_out_list[51], &sw_out_list[52], &sw_out_list[53], &sw_out_list[54], &sw_out_list[55], &sw_out_list[56], &sw_out_list[57], &sw_out_list[58], &sw_out_list[59], &sw_out_list[60], &sw_out_list[61], &sw_out_list[62], &sw_out_list[63], &sw_out_list[64], &sw_out_list[65], &sw_out_list[66], &sw_out_list[67], &sw_out_list[68], &sw_out_list[69], &sw_out_list[70], &sw_out_list[71], &sw_out_list[72], &sw_out_list[73], &sw_out_list[74], &sw_out_list[75], &sw_out_list[76], &sw_out_list[77], &sw_out_list[78], &sw_out_list[79], &sw_out_list[80], &sw_out_list[81], &sw_out_list[82], &sw_out_list[83], &sw_out_list[84], &sw_out_list[85], &sw_out_list[86], &sw_out_list[87], &sw_out_list[88], &sw_out_list[89], &sw_out_list[90], &sw_out_list[91], &sw_out_list[92], &sw_out_list[93], &sw_out_list[94], &sw_out_list[95], &sw_out_list[96], &sw_out_list[97], &sw_out_list[98], &sw_out_list[99], &sw_out_list[100], &sw_out_list[101], &sw_out_list[102], &sw_out_list[103], &sw_out_list[104], &sw_out_list[105], &sw_out_list[106], &sw_out_list[107], &sw_out_list[108], &sw_out_list[109], &sw_out_list[110], &sw_out_list[111], &sw_out_list[112], &sw_out_list[113], &sw_out_list[114], &sw_out_list[115], &sw_out_list[116], &sw_out_list[117], &sw_out_list[118], &sw_out_list[119], &sw_out_list[120], &sw_out_list[121], &sw_out_list[122], &sw_out_list[123], &sw_out_list[124], &sw_out_list[125], &sw_out_list[126], &sw_out_list[127], &sw_out_list[128], &sw_out_list[129], &sw_out_list[130], &sw_out_list[131], &sw_out_list[132], &sw_out_list[133], &sw_out_list[134], &sw_out_list[135], &sw_out_list[136], &sw_out_list[137], &sw_out_list[138], &sw_out_list[139], &sw_out_list[140], &sw_out_list[141], &sw_out_list[142], &sw_out_list[143], &sw_out_list[144], &sw_out_list[145], &sw_out_list[146], &sw_out_list[147], &sw_out_list[148], &sw_out_list[149], &sw_out_list[150], &sw_out_list[151], &sw_out_list[152], &sw_out_list[153], &sw_out_list[154], &sw_out_list[155], &sw_out_list[156], &sw_out_list[157], &sw_out_list[158], &sw_out_list[159], &sw_out_list[160], &sw_out_list[161], &sw_out_list[162], &sw_out_list[163], &sw_out_list[164], &sw_out_list[165], &sw_out_list[166], &sw_out_list[167], &sw_out_list[168], &sw_out_list[169], &sw_out_list[170], &sw_out_list[171], &sw_out_list[172], &sw_out_list[173], &sw_out_list[174], &sw_out_list[175], &sw_out_list[176], &sw_out_list[177], &sw_out_list[178], &sw_out_list[179], &sw_out_list[180], &sw_out_list[181], &sw_out_list[182], &sw_out_list[183], &sw_out_list[184], &sw_out_list[185], &sw_out_list[186], &sw_out_list[187], &sw_out_list[188], &sw_out_list[189], &sw_out_list[190], &sw_out_list[191], &sw_out_list[192], &sw_out_list[193], &sw_out_list[194], &sw_out_list[195], &sw_out_list[196], &sw_out_list[197], &sw_out_list[198], &sw_out_list[199], &sw_out_list[200], &sw_out_list[201], &sw_out_list[202], &sw_out_list[203], &sw_out_list[204], &sw_out_list[205], &sw_out_list[206], &sw_out_list[207], &sw_out_list[208], &sw_out_list[209], &sw_out_list[210], &sw_out_list[211], &sw_out_list[212], &sw_out_list[213], &sw_out_list[214], &sw_out_list[215], &sw_out_list[216], &sw_out_list[217], &sw_out_list[218], &sw_out_list[219], &sw_out_list[220], &sw_out_list[221], &sw_out_list[222], &sw_out_list[223], &sw_out_list[224], &sw_out_list[225], &sw_out_list[226], &sw_out_list[227], &sw_out_list[228], &sw_out_list[229], &sw_out_list[230], &sw_out_list[231], &sw_out_list[232], &sw_out_list[233], &sw_out_list[234], &sw_out_list[235], &sw_out_list[236], &sw_out_list[237], &sw_out_list[238], &sw_out_list[239], &sw_out_list[240], &sw_out_list[241], &sw_out_list[242], &sw_out_list[243], &sw_out_list[244], &sw_out_list[245], &sw_out_list[246], &sw_out_list[247], &sw_out_list[248], &sw_out_list[249], &sw_out_list[250], &sw_out_list[251], &sw_out_list[252], &sw_out_list[253], &sw_out_list[254], &sw_out_list[255]);
	TEST_ASSERT (sw_retval == 0);
	hw_retval = hwdll_write (idx_list[i], in_list);
	TEST_ASSERT (hw_retval == 0);
	while (hwdll_probe (idx_list[i])) {}
	hw_retval = hwdll_read (idx_list[i], hw_out_list);
	TEST_ASSERT (hw_retval == 256 && sw_out_list[0] == hw_out_list[0] && sw_out_list[1] == hw_out_list[1] && sw_out_list[2] == hw_out_list[2] && sw_out_list[3] == hw_out_list[3] && sw_out_list[4] == hw_out_list[4] && sw_out_list[5] == hw_out_list[5] && sw_out_list[6] == hw_out_list[6] && sw_out_list[7] == hw_out_list[7] && sw_out_list[8] == hw_out_list[8] && sw_out_list[9] == hw_out_list[9] && sw_out_list[10] == hw_out_list[10] && sw_out_list[11] == hw_out_list[11] && sw_out_list[12] == hw_out_list[12] && sw_out_list[13] == hw_out_list[13] && sw_out_list[14] == hw_out_list[14] && sw_out_list[15] == hw_out_list[15] && sw_out_list[16] == hw_out_list[16] && sw_out_list[17] == hw_out_list[17] && sw_out_list[18] == hw_out_list[18] && sw_out_list[19] == hw_out_list[19] && sw_out_list[20] == hw_out_list[20] && sw_out_list[21] == hw_out_list[21] && sw_out_list[22] == hw_out_list[22] && sw_out_list[23] == hw_out_list[23] && sw_out_list[24] == hw_out_list[24] && sw_out_list[25] == hw_out_list[25] && sw_out_list[26] == hw_out_list[26] && sw_out_list[27] == hw_out_list[27] && sw_out_list[28] == hw_out_list[28] && sw_out_list[29] == hw_out_list[29] && sw_out_list[30] == hw_out_list[30] && sw_out_list[31] == hw_out_list[31] && sw_out_list[32] == hw_out_list[32] && sw_out_list[33] == hw_out_list[33] && sw_out_list[34] == hw_out_list[34] && sw_out_list[35] == hw_out_list[35] && sw_out_list[36] == hw_out_list[36] && sw_out_list[37] == hw_out_list[37] && sw_out_list[38] == hw_out_list[38] && sw_out_list[39] == hw_out_list[39] && sw_out_list[40] == hw_out_list[40] && sw_out_list[41] == hw_out_list[41] && sw_out_list[42] == hw_out_list[42] && sw_out_list[43] == hw_out_list[43] && sw_out_list[44] == hw_out_list[44] && sw_out_list[45] == hw_out_list[45] && sw_out_list[46] == hw_out_list[46] && sw_out_list[47] == hw_out_list[47] && sw_out_list[48] == hw_out_list[48] && sw_out_list[49] == hw_out_list[49] && sw_out_list[50] == hw_out_list[50] && sw_out_list[51] == hw_out_list[51] && sw_out_list[52] == hw_out_list[52] && sw_out_list[53] == hw_out_list[53] && sw_out_list[54] == hw_out_list[54] && sw_out_list[55] == hw_out_list[55] && sw_out_list[56] == hw_out_list[56] && sw_out_list[57] == hw_out_list[57] && sw_out_list[58] == hw_out_list[58] && sw_out_list[59] == hw_out_list[59] && sw_out_list[60] == hw_out_list[60] && sw_out_list[61] == hw_out_list[61] && sw_out_list[62] == hw_out_list[62] && sw_out_list[63] == hw_out_list[63] && sw_out_list[64] == hw_out_list[64] && sw_out_list[65] == hw_out_list[65] && sw_out_list[66] == hw_out_list[66] && sw_out_list[67] == hw_out_list[67] && sw_out_list[68] == hw_out_list[68] && sw_out_list[69] == hw_out_list[69] && sw_out_list[70] == hw_out_list[70] && sw_out_list[71] == hw_out_list[71] && sw_out_list[72] == hw_out_list[72] && sw_out_list[73] == hw_out_list[73] && sw_out_list[74] == hw_out_list[74] && sw_out_list[75] == hw_out_list[75] && sw_out_list[76] == hw_out_list[76] && sw_out_list[77] == hw_out_list[77] && sw_out_list[78] == hw_out_list[78] && sw_out_list[79] == hw_out_list[79] && sw_out_list[80] == hw_out_list[80] && sw_out_list[81] == hw_out_list[81] && sw_out_list[82] == hw_out_list[82] && sw_out_list[83] == hw_out_list[83] && sw_out_list[84] == hw_out_list[84] && sw_out_list[85] == hw_out_list[85] && sw_out_list[86] == hw_out_list[86] && sw_out_list[87] == hw_out_list[87] && sw_out_list[88] == hw_out_list[88] && sw_out_list[89] == hw_out_list[89] && sw_out_list[90] == hw_out_list[90] && sw_out_list[91] == hw_out_list[91] && sw_out_list[92] == hw_out_list[92] && sw_out_list[93] == hw_out_list[93] && sw_out_list[94] == hw_out_list[94] && sw_out_list[95] == hw_out_list[95] && sw_out_list[96] == hw_out_list[96] && sw_out_list[97] == hw_out_list[97] && sw_out_list[98] == hw_out_list[98] && sw_out_list[99] == hw_out_list[99] && sw_out_list[100] == hw_out_list[100] && sw_out_list[101] == hw_out_list[101] && sw_out_list[102] == hw_out_list[102] && sw_out_list[103] == hw_out_list[103] && sw_out_list[104] == hw_out_list[104] && sw_out_list[105] == hw_out_list[105] && sw_out_list[106] == hw_out_list[106] && sw_out_list[107] == hw_out_list[107] && sw_out_list[108] == hw_out_list[108] && sw_out_list[109] == hw_out_list[109] && sw_out_list[110] == hw_out_list[110] && sw_out_list[111] == hw_out_list[111] && sw_out_list[112] == hw_out_list[112] && sw_out_list[113] == hw_out_list[113] && sw_out_list[114] == hw_out_list[114] && sw_out_list[115] == hw_out_list[115] && sw_out_list[116] == hw_out_list[116] && sw_out_list[117] == hw_out_list[117] && sw_out_list[118] == hw_out_list[118] && sw_out_list[119] == hw_out_list[119] && sw_out_list[120] == hw_out_list[120] && sw_out_list[121] == hw_out_list[121] && sw_out_list[122] == hw_out_list[122] && sw_out_list[123] == hw_out_list[123] && sw_out_list[124] == hw_out_list[124] && sw_out_list[125] == hw_out_list[125] && sw_out_list[126] == hw_out_list[126] && sw_out_list[127] == hw_out_list[127] && sw_out_list[128] == hw_out_list[128] && sw_out_list[129] == hw_out_list[129] && sw_out_list[130] == hw_out_list[130] && sw_out_list[131] == hw_out_list[131] && sw_out_list[132] == hw_out_list[132] && sw_out_list[133] == hw_out_list[133] && sw_out_list[134] == hw_out_list[134] && sw_out_list[135] == hw_out_list[135] && sw_out_list[136] == hw_out_list[136] && sw_out_list[137] == hw_out_list[137] && sw_out_list[138] == hw_out_list[138] && sw_out_list[139] == hw_out_list[139] && sw_out_list[140] == hw_out_list[140] && sw_out_list[141] == hw_out_list[141] && sw_out_list[142] == hw_out_list[142] && sw_out_list[143] == hw_out_list[143] && sw_out_list[144] == hw_out_list[144] && sw_out_list[145] == hw_out_list[145] && sw_out_list[146] == hw_out_list[146] && sw_out_list[147] == hw_out_list[147] && sw_out_list[148] == hw_out_list[148] && sw_out_list[149] == hw_out_list[149] && sw_out_list[150] == hw_out_list[150] && sw_out_list[151] == hw_out_list[151] && sw_out_list[152] == hw_out_list[152] && sw_out_list[153] == hw_out_list[153] && sw_out_list[154] == hw_out_list[154] && sw_out_list[155] == hw_out_list[155] && sw_out_list[156] == hw_out_list[156] && sw_out_list[157] == hw_out_list[157] && sw_out_list[158] == hw_out_list[158] && sw_out_list[159] == hw_out_list[159] && sw_out_list[160] == hw_out_list[160] && sw_out_list[161] == hw_out_list[161] && sw_out_list[162] == hw_out_list[162] && sw_out_list[163] == hw_out_list[163] && sw_out_list[164] == hw_out_list[164] && sw_out_list[165] == hw_out_list[165] && sw_out_list[166] == hw_out_list[166] && sw_out_list[167] == hw_out_list[167] && sw_out_list[168] == hw_out_list[168] && sw_out_list[169] == hw_out_list[169] && sw_out_list[170] == hw_out_list[170] && sw_out_list[171] == hw_out_list[171] && sw_out_list[172] == hw_out_list[172] && sw_out_list[173] == hw_out_list[173] && sw_out_list[174] == hw_out_list[174] && sw_out_list[175] == hw_out_list[175] && sw_out_list[176] == hw_out_list[176] && sw_out_list[177] == hw_out_list[177] && sw_out_list[178] == hw_out_list[178] && sw_out_list[179] == hw_out_list[179] && sw_out_list[180] == hw_out_list[180] && sw_out_list[181] == hw_out_list[181] && sw_out_list[182] == hw_out_list[182] && sw_out_list[183] == hw_out_list[183] && sw_out_list[184] == hw_out_list[184] && sw_out_list[185] == hw_out_list[185] && sw_out_list[186] == hw_out_list[186] && sw_out_list[187] == hw_out_list[187] && sw_out_list[188] == hw_out_list[188] && sw_out_list[189] == hw_out_list[189] && sw_out_list[190] == hw_out_list[190] && sw_out_list[191] == hw_out_list[191] && sw_out_list[192] == hw_out_list[192] && sw_out_list[193] == hw_out_list[193] && sw_out_list[194] == hw_out_list[194] && sw_out_list[195] == hw_out_list[195] && sw_out_list[196] == hw_out_list[196] && sw_out_list[197] == hw_out_list[197] && sw_out_list[198] == hw_out_list[198] && sw_out_list[199] == hw_out_list[199] && sw_out_list[200] == hw_out_list[200] && sw_out_list[201] == hw_out_list[201] && sw_out_list[202] == hw_out_list[202] && sw_out_list[203] == hw_out_list[203] && sw_out_list[204] == hw_out_list[204] && sw_out_list[205] == hw_out_list[205] && sw_out_list[206] == hw_out_list[206] && sw_out_list[207] == hw_out_list[207] && sw_out_list[208] == hw_out_list[208] && sw_out_list[209] == hw_out_list[209] && sw_out_list[210] == hw_out_list[210] && sw_out_list[211] == hw_out_list[211] && sw_out_list[212] == hw_out_list[212] && sw_out_list[213] == hw_out_list[213] && sw_out_list[214] == hw_out_list[214] && sw_out_list[215] == hw_out_list[215] && sw_out_list[216] == hw_out_list[216] && sw_out_list[217] == hw_out_list[217] && sw_out_list[218] == hw_out_list[218] && sw_out_list[219] == hw_out_list[219] && sw_out_list[220] == hw_out_list[220] && sw_out_list[221] == hw_out_list[221] && sw_out_list[222] == hw_out_list[222] && sw_out_list[223] == hw_out_list[223] && sw_out_list[224] == hw_out_list[224] && sw_out_list[225] == hw_out_list[225] && sw_out_list[226] == hw_out_list[226] && sw_out_list[227] == hw_out_list[227] && sw_out_list[228] == hw_out_list[228] && sw_out_list[229] == hw_out_list[229] && sw_out_list[230] == hw_out_list[230] && sw_out_list[231] == hw_out_list[231] && sw_out_list[232] == hw_out_list[232] && sw_out_list[233] == hw_out_list[233] && sw_out_list[234] == hw_out_list[234] && sw_out_list[235] == hw_out_list[235] && sw_out_list[236] == hw_out_list[236] && sw_out_list[237] == hw_out_list[237] && sw_out_list[238] == hw_out_list[238] && sw_out_list[239] == hw_out_list[239] && sw_out_list[240] == hw_out_list[240] && sw_out_list[241] == hw_out_list[241] && sw_out_list[242] == hw_out_list[242] && sw_out_list[243] == hw_out_list[243] && sw_out_list[244] == hw_out_list[244] && sw_out_list[245] == hw_out_list[245] && sw_out_list[246] == hw_out_list[246] && sw_out_list[247] == hw_out_list[247] && sw_out_list[248] == hw_out_list[248] && sw_out_list[249] == hw_out_list[249] && sw_out_list[250] == hw_out_list[250] && sw_out_list[251] == hw_out_list[251] && sw_out_list[252] == hw_out_list[252] && sw_out_list[253] == hw_out_list[253] && sw_out_list[254] == hw_out_list[254] && sw_out_list[255] == hw_out_list[255]);
	i = 2; /* Reevaluate Int Max																												*/
	sw_retval = int_max (&sw_out_list[0]);
	TEST_ASSERT (sw_retval == 0);
	hw_retval = hwdll_write (idx_list[i], in_list);
	TEST_ASSERT (hw_retval == 0);
	while (hwdll_probe (idx_list[i])) {}
	hw_retval = hwdll_read (idx_list[i], hw_out_list);
	TEST_ASSERT (hw_retval == 1 && sw_out_list[0] == hw_out_list[0]);
	i = 3; /* Reevaluate Adder Subtractor																								*/
	sw_retval = adder_subtractor (in_list[0], in_list[1], &sw_out_list[0], &sw_out_list[1]);
	TEST_ASSERT (sw_retval == 0);
	hw_retval = hwdll_write (idx_list[i], in_list);
	TEST_ASSERT (hw_retval == 2);
	while (hwdll_probe (idx_list[i])) {}
	hw_retval = hwdll_read (idx_list[i], hw_out_list);
	TEST_ASSERT (hw_retval == 2 && sw_out_list[0] == hw_out_list[0] && sw_out_list[1] == hw_out_list[1]);
	i = 4; /* Reevaluate Multiplier																											*/
	sw_retval = multiplier (in_list[0], in_list[1], &sw_out_list[0]);
	TEST_ASSERT (sw_retval == 0);
	hw_retval = hwdll_write (idx_list[i], in_list);
	TEST_ASSERT (hw_retval == 2);
	while (hwdll_probe (idx_list[i])) {}
	hw_retval = hwdll_read (idx_list[i], hw_out_list);
	TEST_ASSERT (hw_retval == 1 && sw_out_list[0] == hw_out_list[0]);
	i = 5; /* Reevaluate Bitwise Right Shift																								*/
	sw_retval = bitwise_right_shift (in_list[0], &sw_out_list[0]);
	TEST_ASSERT (sw_retval == 0);
	hw_retval = hwdll_write (idx_list[i], in_list);
	TEST_ASSERT (hw_retval == 1);
	while (hwdll_probe (idx_list[i])) {}
	hw_retval = hwdll_read (idx_list[i], hw_out_list);
	TEST_ASSERT (hw_retval == 1 && sw_out_list[0] == hw_out_list[0]);
	i = 6; /* Reevaluate Greatest Common Divisor																					*/
	sw_retval = gcd (in_list[0], in_list[1], &sw_out_list[0]);
	TEST_ASSERT (sw_retval == 0);
	hw_retval = hwdll_write (idx_list[i], in_list);
	TEST_ASSERT (hw_retval == 2);
	while (hwdll_probe (idx_list[i])) {}
	hw_retval = hwdll_read (idx_list[i], hw_out_list);
	TEST_ASSERT (hw_retval == 1 && sw_out_list[0] == hw_out_list[0]);
	i = 7; /* Reevaluate Fibonacci																											*/
	sw_retval = fibonacci (in_list[0], &sw_out_list[0]);
	TEST_ASSERT (sw_retval == -1);
	hw_retval = hwdll_write (idx_list[i], in_list);
	TEST_ASSERT (hw_retval == 1);
	while (hwdll_probe (idx_list[i])) {}
	hw_retval = hwdll_read (idx_list[i], hw_out_list);
	TEST_ASSERT (hw_retval == 1 && sw_out_list[0] == hw_out_list[0]);
	i = 8; /* Reevaluate Prime																												*/
	sw_retval = prime (in_list[0], &sw_out_list[0]);
	TEST_ASSERT (sw_retval == 0);
	hw_retval = hwdll_write (idx_list[i], in_list);
	TEST_ASSERT (hw_retval == 1);
	while (hwdll_probe (idx_list[i])) {}
	hw_retval = hwdll_read (idx_list[i], hw_out_list);
	TEST_ASSERT (hw_retval == 1 && sw_out_list[0] == hw_out_list[0]);
	i = 9; /* Reevaluate Prime Neighbours																								*/
	sw_retval = prime_neighbours (in_list[0], &sw_out_list[0], &sw_out_list[1]);
	TEST_ASSERT (sw_retval == 0);
	hw_retval = hwdll_write (idx_list[i], in_list);
	TEST_ASSERT (hw_retval == 1);
	while (hwdll_probe (idx_list[i])) {}
	hw_retval = hwdll_read (idx_list[i], hw_out_list);
	TEST_ASSERT (hw_retval == 2 && sw_out_list[0] == hw_out_list[0] && sw_out_list[1] == hw_out_list[1]);
	hwdll_unload_list (idx_list, CAT_SIZE, false);
	hwdll_destroy ();
	return true;
}

bool test_list (void)
{
	FILE* dump = NULL;
	hwdll_create ();
	int i = 0;
	int sw_retval = -2, hw_retval = -2;
	int in_list[2] = {0};
	int sw_out_list[256] = {-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2};
	int hw_out_list[256] = {-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2};
	int id_list[RP_LIST_SIZE] = {8, 7, 8, 7, 7, 2, 2, 6, 4, 5, 3, 1, 1, 1, 6, 6};
	int idx_list[RP_LIST_SIZE] = {-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2};
	hw_retval = hwdll_load_list (id_list, idx_list, RP_LIST_SIZE);
	TEST_ASSERT (idx_list[0] == 11 && idx_list[1] == 7 && idx_list[2] == 15 && idx_list[3] == 8 && idx_list[4] == 14 && idx_list[5] == 3 && idx_list[6] == 6 && idx_list[7] == 0 && idx_list[8] == 2 && idx_list[9] == 10 && idx_list[10] == 9 && idx_list[11] == 1 && idx_list[12] == 4 && idx_list[13] == 5 && idx_list[14] == 12 && idx_list[15] == 13);
	in_list[0] = 27;
	in_list[1] = 39;
	i = 0; /* Evaluate Prime																													*/
	sw_retval = prime (in_list[0], &sw_out_list[0]);
	TEST_ASSERT (sw_retval == 0);
	hw_retval = hwdll_write (idx_list[i], in_list);
	TEST_ASSERT (hw_retval == 1);
	hw_retval = hwdll_read (idx_list[i], hw_out_list);
	TEST_ASSERT (hw_retval == 1 && sw_out_list[0] == hw_out_list[0]);
	i = 1; /* Evaluate Fibonacci																												*/
	sw_retval = fibonacci (in_list[0], &sw_out_list[0]);
	TEST_ASSERT (sw_retval == 0);
	hw_retval = hwdll_write (idx_list[i], in_list);
	TEST_ASSERT (hw_retval == 1);
	hw_retval = hwdll_read (idx_list[i], hw_out_list);
	TEST_ASSERT (hw_retval == 1 && sw_out_list[0] == hw_out_list[0]);
	i = 2; /* Evaluate Prime																													*/
	sw_retval = prime (in_list[0], &sw_out_list[0]);
	TEST_ASSERT (sw_retval == 0);
	hw_retval = hwdll_write (idx_list[i], in_list);
	TEST_ASSERT (hw_retval == 1);
	hw_retval = hwdll_read (idx_list[i], hw_out_list);
	TEST_ASSERT (hw_retval == 1 && sw_out_list[0] == hw_out_list[0]);
	i = 3; /* Evaluate Fibonacci																												*/
	sw_retval = fibonacci (in_list[0], &sw_out_list[0]);
	TEST_ASSERT (sw_retval == 0);
	hw_retval = hwdll_write (idx_list[i], in_list);
	TEST_ASSERT (hw_retval == 1);
	hw_retval = hwdll_read (idx_list[i], hw_out_list);
	TEST_ASSERT (hw_retval == 1 && sw_out_list[0] == hw_out_list[0]);
	i = 4; /* Evaluate Fibonacci																												*/
	sw_retval = fibonacci (in_list[0], &sw_out_list[0]);
	TEST_ASSERT (sw_retval == 0);
	hw_retval = hwdll_write (idx_list[i], in_list);
	TEST_ASSERT (hw_retval == 1);
	hw_retval = hwdll_read (idx_list[i], hw_out_list);
	TEST_ASSERT (hw_retval == 1 && sw_out_list[0] == hw_out_list[0]);
	i = 5; /* Evaluate Int Max																													*/
	sw_retval = int_max (&sw_out_list[0]);
	TEST_ASSERT (sw_retval == 0);
	hw_retval = hwdll_read (idx_list[i], hw_out_list);
	TEST_ASSERT (hw_retval == 1 && sw_out_list[0] == hw_out_list[0]);
	i = 6; /* Evaluate Int Max																													*/
	sw_retval = int_max (&sw_out_list[0]);
	TEST_ASSERT (sw_retval == 0);
	hw_retval = hwdll_read (idx_list[i], hw_out_list);
	TEST_ASSERT (hw_retval == 1 && sw_out_list[0] == hw_out_list[0]);
	i = 7; /* Evaluate Greatest Common Divisor																						*/
	sw_retval = gcd (in_list[0], in_list[1], &sw_out_list[0]);
	TEST_ASSERT (sw_retval == 0);
	hw_retval = hwdll_write (idx_list[i], in_list);
	TEST_ASSERT (hw_retval == 2);
	hw_retval = hwdll_read (idx_list[i], hw_out_list);
	TEST_ASSERT (hw_retval == 1 && sw_out_list[0] == hw_out_list[0]);
	i = 8; /* Evaluate Multiplier																												*/
	sw_retval = multiplier (in_list[0], in_list[1], &sw_out_list[0]);
	TEST_ASSERT (sw_retval == 0);
	hw_retval = hwdll_write (idx_list[i], in_list);
	TEST_ASSERT (hw_retval == 2);
	hw_retval = hwdll_read (idx_list[i], hw_out_list);
	TEST_ASSERT (hw_retval == 1 && sw_out_list[0] == hw_out_list[0]);
	i = 9; /* Evaluate Bitwise Right Shift																									*/
	sw_retval = bitwise_right_shift (in_list[0], &sw_out_list[0]);
	TEST_ASSERT (sw_retval == 0);
	hw_retval = hwdll_write (idx_list[i], in_list);
	TEST_ASSERT (hw_retval == 1);
	hw_retval = hwdll_read (idx_list[i], hw_out_list);
	TEST_ASSERT (hw_retval == 1 && sw_out_list[0] == hw_out_list[0]);
	i = 10; /* Evaluate Adder Subtractor																								*/
	sw_retval = adder_subtractor (in_list[0], in_list[1], &sw_out_list[0], &sw_out_list[1]);
	TEST_ASSERT (sw_retval == 0);
	hw_retval = hwdll_write (idx_list[i], in_list);
	TEST_ASSERT (hw_retval == 2);
	hw_retval = hwdll_read (idx_list[i], hw_out_list);
	TEST_ASSERT (hw_retval == 2 && sw_out_list[0] == hw_out_list[0] && sw_out_list[1] == hw_out_list[1]);
	i = 11; /* Evaluate Numbers																											*/
	sw_retval = numbers (&sw_out_list[0], &sw_out_list[1], &sw_out_list[2], &sw_out_list[3], &sw_out_list[4], &sw_out_list[5], &sw_out_list[6], &sw_out_list[7], &sw_out_list[8], &sw_out_list[9], &sw_out_list[10], &sw_out_list[11], &sw_out_list[12], &sw_out_list[13], &sw_out_list[14], &sw_out_list[15], &sw_out_list[16], &sw_out_list[17], &sw_out_list[18], &sw_out_list[19], &sw_out_list[20], &sw_out_list[21], &sw_out_list[22], &sw_out_list[23], &sw_out_list[24], &sw_out_list[25], &sw_out_list[26], &sw_out_list[27], &sw_out_list[28], &sw_out_list[29], &sw_out_list[30], &sw_out_list[31], &sw_out_list[32], &sw_out_list[33], &sw_out_list[34], &sw_out_list[35], &sw_out_list[36], &sw_out_list[37], &sw_out_list[38], &sw_out_list[39], &sw_out_list[40], &sw_out_list[41], &sw_out_list[42], &sw_out_list[43], &sw_out_list[44], &sw_out_list[45], &sw_out_list[46], &sw_out_list[47], &sw_out_list[48], &sw_out_list[49], &sw_out_list[50], &sw_out_list[51], &sw_out_list[52], &sw_out_list[53], &sw_out_list[54], &sw_out_list[55], &sw_out_list[56], &sw_out_list[57], &sw_out_list[58], &sw_out_list[59], &sw_out_list[60], &sw_out_list[61], &sw_out_list[62], &sw_out_list[63], &sw_out_list[64], &sw_out_list[65], &sw_out_list[66], &sw_out_list[67], &sw_out_list[68], &sw_out_list[69], &sw_out_list[70], &sw_out_list[71], &sw_out_list[72], &sw_out_list[73], &sw_out_list[74], &sw_out_list[75], &sw_out_list[76], &sw_out_list[77], &sw_out_list[78], &sw_out_list[79], &sw_out_list[80], &sw_out_list[81], &sw_out_list[82], &sw_out_list[83], &sw_out_list[84], &sw_out_list[85], &sw_out_list[86], &sw_out_list[87], &sw_out_list[88], &sw_out_list[89], &sw_out_list[90], &sw_out_list[91], &sw_out_list[92], &sw_out_list[93], &sw_out_list[94], &sw_out_list[95], &sw_out_list[96], &sw_out_list[97], &sw_out_list[98], &sw_out_list[99], &sw_out_list[100], &sw_out_list[101], &sw_out_list[102], &sw_out_list[103], &sw_out_list[104], &sw_out_list[105], &sw_out_list[106], &sw_out_list[107], &sw_out_list[108], &sw_out_list[109], &sw_out_list[110], &sw_out_list[111], &sw_out_list[112], &sw_out_list[113], &sw_out_list[114], &sw_out_list[115], &sw_out_list[116], &sw_out_list[117], &sw_out_list[118], &sw_out_list[119], &sw_out_list[120], &sw_out_list[121], &sw_out_list[122], &sw_out_list[123], &sw_out_list[124], &sw_out_list[125], &sw_out_list[126], &sw_out_list[127], &sw_out_list[128], &sw_out_list[129], &sw_out_list[130], &sw_out_list[131], &sw_out_list[132], &sw_out_list[133], &sw_out_list[134], &sw_out_list[135], &sw_out_list[136], &sw_out_list[137], &sw_out_list[138], &sw_out_list[139], &sw_out_list[140], &sw_out_list[141], &sw_out_list[142], &sw_out_list[143], &sw_out_list[144], &sw_out_list[145], &sw_out_list[146], &sw_out_list[147], &sw_out_list[148], &sw_out_list[149], &sw_out_list[150], &sw_out_list[151], &sw_out_list[152], &sw_out_list[153], &sw_out_list[154], &sw_out_list[155], &sw_out_list[156], &sw_out_list[157], &sw_out_list[158], &sw_out_list[159], &sw_out_list[160], &sw_out_list[161], &sw_out_list[162], &sw_out_list[163], &sw_out_list[164], &sw_out_list[165], &sw_out_list[166], &sw_out_list[167], &sw_out_list[168], &sw_out_list[169], &sw_out_list[170], &sw_out_list[171], &sw_out_list[172], &sw_out_list[173], &sw_out_list[174], &sw_out_list[175], &sw_out_list[176], &sw_out_list[177], &sw_out_list[178], &sw_out_list[179], &sw_out_list[180], &sw_out_list[181], &sw_out_list[182], &sw_out_list[183], &sw_out_list[184], &sw_out_list[185], &sw_out_list[186], &sw_out_list[187], &sw_out_list[188], &sw_out_list[189], &sw_out_list[190], &sw_out_list[191], &sw_out_list[192], &sw_out_list[193], &sw_out_list[194], &sw_out_list[195], &sw_out_list[196], &sw_out_list[197], &sw_out_list[198], &sw_out_list[199], &sw_out_list[200], &sw_out_list[201], &sw_out_list[202], &sw_out_list[203], &sw_out_list[204], &sw_out_list[205], &sw_out_list[206], &sw_out_list[207], &sw_out_list[208], &sw_out_list[209], &sw_out_list[210], &sw_out_list[211], &sw_out_list[212], &sw_out_list[213], &sw_out_list[214], &sw_out_list[215], &sw_out_list[216], &sw_out_list[217], &sw_out_list[218], &sw_out_list[219], &sw_out_list[220], &sw_out_list[221], &sw_out_list[222], &sw_out_list[223], &sw_out_list[224], &sw_out_list[225], &sw_out_list[226], &sw_out_list[227], &sw_out_list[228], &sw_out_list[229], &sw_out_list[230], &sw_out_list[231], &sw_out_list[232], &sw_out_list[233], &sw_out_list[234], &sw_out_list[235], &sw_out_list[236], &sw_out_list[237], &sw_out_list[238], &sw_out_list[239], &sw_out_list[240], &sw_out_list[241], &sw_out_list[242], &sw_out_list[243], &sw_out_list[244], &sw_out_list[245], &sw_out_list[246], &sw_out_list[247], &sw_out_list[248], &sw_out_list[249], &sw_out_list[250], &sw_out_list[251], &sw_out_list[252], &sw_out_list[253], &sw_out_list[254], &sw_out_list[255]);
	TEST_ASSERT (sw_retval == 0);
	hw_retval = hwdll_read (idx_list[i], hw_out_list);
	TEST_ASSERT (hw_retval == 256 && sw_out_list[0] == hw_out_list[0] && sw_out_list[1] == hw_out_list[1] && sw_out_list[2] == hw_out_list[2] && sw_out_list[3] == hw_out_list[3] && sw_out_list[4] == hw_out_list[4] && sw_out_list[5] == hw_out_list[5] && sw_out_list[6] == hw_out_list[6] && sw_out_list[7] == hw_out_list[7] && sw_out_list[8] == hw_out_list[8] && sw_out_list[9] == hw_out_list[9] && sw_out_list[10] == hw_out_list[10] && sw_out_list[11] == hw_out_list[11] && sw_out_list[12] == hw_out_list[12] && sw_out_list[13] == hw_out_list[13] && sw_out_list[14] == hw_out_list[14] && sw_out_list[15] == hw_out_list[15] && sw_out_list[16] == hw_out_list[16] && sw_out_list[17] == hw_out_list[17] && sw_out_list[18] == hw_out_list[18] && sw_out_list[19] == hw_out_list[19] && sw_out_list[20] == hw_out_list[20] && sw_out_list[21] == hw_out_list[21] && sw_out_list[22] == hw_out_list[22] && sw_out_list[23] == hw_out_list[23] && sw_out_list[24] == hw_out_list[24] && sw_out_list[25] == hw_out_list[25] && sw_out_list[26] == hw_out_list[26] && sw_out_list[27] == hw_out_list[27] && sw_out_list[28] == hw_out_list[28] && sw_out_list[29] == hw_out_list[29] && sw_out_list[30] == hw_out_list[30] && sw_out_list[31] == hw_out_list[31] && sw_out_list[32] == hw_out_list[32] && sw_out_list[33] == hw_out_list[33] && sw_out_list[34] == hw_out_list[34] && sw_out_list[35] == hw_out_list[35] && sw_out_list[36] == hw_out_list[36] && sw_out_list[37] == hw_out_list[37] && sw_out_list[38] == hw_out_list[38] && sw_out_list[39] == hw_out_list[39] && sw_out_list[40] == hw_out_list[40] && sw_out_list[41] == hw_out_list[41] && sw_out_list[42] == hw_out_list[42] && sw_out_list[43] == hw_out_list[43] && sw_out_list[44] == hw_out_list[44] && sw_out_list[45] == hw_out_list[45] && sw_out_list[46] == hw_out_list[46] && sw_out_list[47] == hw_out_list[47] && sw_out_list[48] == hw_out_list[48] && sw_out_list[49] == hw_out_list[49] && sw_out_list[50] == hw_out_list[50] && sw_out_list[51] == hw_out_list[51] && sw_out_list[52] == hw_out_list[52] && sw_out_list[53] == hw_out_list[53] && sw_out_list[54] == hw_out_list[54] && sw_out_list[55] == hw_out_list[55] && sw_out_list[56] == hw_out_list[56] && sw_out_list[57] == hw_out_list[57] && sw_out_list[58] == hw_out_list[58] && sw_out_list[59] == hw_out_list[59] && sw_out_list[60] == hw_out_list[60] && sw_out_list[61] == hw_out_list[61] && sw_out_list[62] == hw_out_list[62] && sw_out_list[63] == hw_out_list[63] && sw_out_list[64] == hw_out_list[64] && sw_out_list[65] == hw_out_list[65] && sw_out_list[66] == hw_out_list[66] && sw_out_list[67] == hw_out_list[67] && sw_out_list[68] == hw_out_list[68] && sw_out_list[69] == hw_out_list[69] && sw_out_list[70] == hw_out_list[70] && sw_out_list[71] == hw_out_list[71] && sw_out_list[72] == hw_out_list[72] && sw_out_list[73] == hw_out_list[73] && sw_out_list[74] == hw_out_list[74] && sw_out_list[75] == hw_out_list[75] && sw_out_list[76] == hw_out_list[76] && sw_out_list[77] == hw_out_list[77] && sw_out_list[78] == hw_out_list[78] && sw_out_list[79] == hw_out_list[79] && sw_out_list[80] == hw_out_list[80] && sw_out_list[81] == hw_out_list[81] && sw_out_list[82] == hw_out_list[82] && sw_out_list[83] == hw_out_list[83] && sw_out_list[84] == hw_out_list[84] && sw_out_list[85] == hw_out_list[85] && sw_out_list[86] == hw_out_list[86] && sw_out_list[87] == hw_out_list[87] && sw_out_list[88] == hw_out_list[88] && sw_out_list[89] == hw_out_list[89] && sw_out_list[90] == hw_out_list[90] && sw_out_list[91] == hw_out_list[91] && sw_out_list[92] == hw_out_list[92] && sw_out_list[93] == hw_out_list[93] && sw_out_list[94] == hw_out_list[94] && sw_out_list[95] == hw_out_list[95] && sw_out_list[96] == hw_out_list[96] && sw_out_list[97] == hw_out_list[97] && sw_out_list[98] == hw_out_list[98] && sw_out_list[99] == hw_out_list[99] && sw_out_list[100] == hw_out_list[100] && sw_out_list[101] == hw_out_list[101] && sw_out_list[102] == hw_out_list[102] && sw_out_list[103] == hw_out_list[103] && sw_out_list[104] == hw_out_list[104] && sw_out_list[105] == hw_out_list[105] && sw_out_list[106] == hw_out_list[106] && sw_out_list[107] == hw_out_list[107] && sw_out_list[108] == hw_out_list[108] && sw_out_list[109] == hw_out_list[109] && sw_out_list[110] == hw_out_list[110] && sw_out_list[111] == hw_out_list[111] && sw_out_list[112] == hw_out_list[112] && sw_out_list[113] == hw_out_list[113] && sw_out_list[114] == hw_out_list[114] && sw_out_list[115] == hw_out_list[115] && sw_out_list[116] == hw_out_list[116] && sw_out_list[117] == hw_out_list[117] && sw_out_list[118] == hw_out_list[118] && sw_out_list[119] == hw_out_list[119] && sw_out_list[120] == hw_out_list[120] && sw_out_list[121] == hw_out_list[121] && sw_out_list[122] == hw_out_list[122] && sw_out_list[123] == hw_out_list[123] && sw_out_list[124] == hw_out_list[124] && sw_out_list[125] == hw_out_list[125] && sw_out_list[126] == hw_out_list[126] && sw_out_list[127] == hw_out_list[127] && sw_out_list[128] == hw_out_list[128] && sw_out_list[129] == hw_out_list[129] && sw_out_list[130] == hw_out_list[130] && sw_out_list[131] == hw_out_list[131] && sw_out_list[132] == hw_out_list[132] && sw_out_list[133] == hw_out_list[133] && sw_out_list[134] == hw_out_list[134] && sw_out_list[135] == hw_out_list[135] && sw_out_list[136] == hw_out_list[136] && sw_out_list[137] == hw_out_list[137] && sw_out_list[138] == hw_out_list[138] && sw_out_list[139] == hw_out_list[139] && sw_out_list[140] == hw_out_list[140] && sw_out_list[141] == hw_out_list[141] && sw_out_list[142] == hw_out_list[142] && sw_out_list[143] == hw_out_list[143] && sw_out_list[144] == hw_out_list[144] && sw_out_list[145] == hw_out_list[145] && sw_out_list[146] == hw_out_list[146] && sw_out_list[147] == hw_out_list[147] && sw_out_list[148] == hw_out_list[148] && sw_out_list[149] == hw_out_list[149] && sw_out_list[150] == hw_out_list[150] && sw_out_list[151] == hw_out_list[151] && sw_out_list[152] == hw_out_list[152] && sw_out_list[153] == hw_out_list[153] && sw_out_list[154] == hw_out_list[154] && sw_out_list[155] == hw_out_list[155] && sw_out_list[156] == hw_out_list[156] && sw_out_list[157] == hw_out_list[157] && sw_out_list[158] == hw_out_list[158] && sw_out_list[159] == hw_out_list[159] && sw_out_list[160] == hw_out_list[160] && sw_out_list[161] == hw_out_list[161] && sw_out_list[162] == hw_out_list[162] && sw_out_list[163] == hw_out_list[163] && sw_out_list[164] == hw_out_list[164] && sw_out_list[165] == hw_out_list[165] && sw_out_list[166] == hw_out_list[166] && sw_out_list[167] == hw_out_list[167] && sw_out_list[168] == hw_out_list[168] && sw_out_list[169] == hw_out_list[169] && sw_out_list[170] == hw_out_list[170] && sw_out_list[171] == hw_out_list[171] && sw_out_list[172] == hw_out_list[172] && sw_out_list[173] == hw_out_list[173] && sw_out_list[174] == hw_out_list[174] && sw_out_list[175] == hw_out_list[175] && sw_out_list[176] == hw_out_list[176] && sw_out_list[177] == hw_out_list[177] && sw_out_list[178] == hw_out_list[178] && sw_out_list[179] == hw_out_list[179] && sw_out_list[180] == hw_out_list[180] && sw_out_list[181] == hw_out_list[181] && sw_out_list[182] == hw_out_list[182] && sw_out_list[183] == hw_out_list[183] && sw_out_list[184] == hw_out_list[184] && sw_out_list[185] == hw_out_list[185] && sw_out_list[186] == hw_out_list[186] && sw_out_list[187] == hw_out_list[187] && sw_out_list[188] == hw_out_list[188] && sw_out_list[189] == hw_out_list[189] && sw_out_list[190] == hw_out_list[190] && sw_out_list[191] == hw_out_list[191] && sw_out_list[192] == hw_out_list[192] && sw_out_list[193] == hw_out_list[193] && sw_out_list[194] == hw_out_list[194] && sw_out_list[195] == hw_out_list[195] && sw_out_list[196] == hw_out_list[196] && sw_out_list[197] == hw_out_list[197] && sw_out_list[198] == hw_out_list[198] && sw_out_list[199] == hw_out_list[199] && sw_out_list[200] == hw_out_list[200] && sw_out_list[201] == hw_out_list[201] && sw_out_list[202] == hw_out_list[202] && sw_out_list[203] == hw_out_list[203] && sw_out_list[204] == hw_out_list[204] && sw_out_list[205] == hw_out_list[205] && sw_out_list[206] == hw_out_list[206] && sw_out_list[207] == hw_out_list[207] && sw_out_list[208] == hw_out_list[208] && sw_out_list[209] == hw_out_list[209] && sw_out_list[210] == hw_out_list[210] && sw_out_list[211] == hw_out_list[211] && sw_out_list[212] == hw_out_list[212] && sw_out_list[213] == hw_out_list[213] && sw_out_list[214] == hw_out_list[214] && sw_out_list[215] == hw_out_list[215] && sw_out_list[216] == hw_out_list[216] && sw_out_list[217] == hw_out_list[217] && sw_out_list[218] == hw_out_list[218] && sw_out_list[219] == hw_out_list[219] && sw_out_list[220] == hw_out_list[220] && sw_out_list[221] == hw_out_list[221] && sw_out_list[222] == hw_out_list[222] && sw_out_list[223] == hw_out_list[223] && sw_out_list[224] == hw_out_list[224] && sw_out_list[225] == hw_out_list[225] && sw_out_list[226] == hw_out_list[226] && sw_out_list[227] == hw_out_list[227] && sw_out_list[228] == hw_out_list[228] && sw_out_list[229] == hw_out_list[229] && sw_out_list[230] == hw_out_list[230] && sw_out_list[231] == hw_out_list[231] && sw_out_list[232] == hw_out_list[232] && sw_out_list[233] == hw_out_list[233] && sw_out_list[234] == hw_out_list[234] && sw_out_list[235] == hw_out_list[235] && sw_out_list[236] == hw_out_list[236] && sw_out_list[237] == hw_out_list[237] && sw_out_list[238] == hw_out_list[238] && sw_out_list[239] == hw_out_list[239] && sw_out_list[240] == hw_out_list[240] && sw_out_list[241] == hw_out_list[241] && sw_out_list[242] == hw_out_list[242] && sw_out_list[243] == hw_out_list[243] && sw_out_list[244] == hw_out_list[244] && sw_out_list[245] == hw_out_list[245] && sw_out_list[246] == hw_out_list[246] && sw_out_list[247] == hw_out_list[247] && sw_out_list[248] == hw_out_list[248] && sw_out_list[249] == hw_out_list[249] && sw_out_list[250] == hw_out_list[250] && sw_out_list[251] == hw_out_list[251] && sw_out_list[252] == hw_out_list[252] && sw_out_list[253] == hw_out_list[253] && sw_out_list[254] == hw_out_list[254] && sw_out_list[255] == hw_out_list[255]);
	i = 12; /* Evaluate Numbers																											*/
	sw_retval = numbers (&sw_out_list[0], &sw_out_list[1], &sw_out_list[2], &sw_out_list[3], &sw_out_list[4], &sw_out_list[5], &sw_out_list[6], &sw_out_list[7], &sw_out_list[8], &sw_out_list[9], &sw_out_list[10], &sw_out_list[11], &sw_out_list[12], &sw_out_list[13], &sw_out_list[14], &sw_out_list[15], &sw_out_list[16], &sw_out_list[17], &sw_out_list[18], &sw_out_list[19], &sw_out_list[20], &sw_out_list[21], &sw_out_list[22], &sw_out_list[23], &sw_out_list[24], &sw_out_list[25], &sw_out_list[26], &sw_out_list[27], &sw_out_list[28], &sw_out_list[29], &sw_out_list[30], &sw_out_list[31], &sw_out_list[32], &sw_out_list[33], &sw_out_list[34], &sw_out_list[35], &sw_out_list[36], &sw_out_list[37], &sw_out_list[38], &sw_out_list[39], &sw_out_list[40], &sw_out_list[41], &sw_out_list[42], &sw_out_list[43], &sw_out_list[44], &sw_out_list[45], &sw_out_list[46], &sw_out_list[47], &sw_out_list[48], &sw_out_list[49], &sw_out_list[50], &sw_out_list[51], &sw_out_list[52], &sw_out_list[53], &sw_out_list[54], &sw_out_list[55], &sw_out_list[56], &sw_out_list[57], &sw_out_list[58], &sw_out_list[59], &sw_out_list[60], &sw_out_list[61], &sw_out_list[62], &sw_out_list[63], &sw_out_list[64], &sw_out_list[65], &sw_out_list[66], &sw_out_list[67], &sw_out_list[68], &sw_out_list[69], &sw_out_list[70], &sw_out_list[71], &sw_out_list[72], &sw_out_list[73], &sw_out_list[74], &sw_out_list[75], &sw_out_list[76], &sw_out_list[77], &sw_out_list[78], &sw_out_list[79], &sw_out_list[80], &sw_out_list[81], &sw_out_list[82], &sw_out_list[83], &sw_out_list[84], &sw_out_list[85], &sw_out_list[86], &sw_out_list[87], &sw_out_list[88], &sw_out_list[89], &sw_out_list[90], &sw_out_list[91], &sw_out_list[92], &sw_out_list[93], &sw_out_list[94], &sw_out_list[95], &sw_out_list[96], &sw_out_list[97], &sw_out_list[98], &sw_out_list[99], &sw_out_list[100], &sw_out_list[101], &sw_out_list[102], &sw_out_list[103], &sw_out_list[104], &sw_out_list[105], &sw_out_list[106], &sw_out_list[107], &sw_out_list[108], &sw_out_list[109], &sw_out_list[110], &sw_out_list[111], &sw_out_list[112], &sw_out_list[113], &sw_out_list[114], &sw_out_list[115], &sw_out_list[116], &sw_out_list[117], &sw_out_list[118], &sw_out_list[119], &sw_out_list[120], &sw_out_list[121], &sw_out_list[122], &sw_out_list[123], &sw_out_list[124], &sw_out_list[125], &sw_out_list[126], &sw_out_list[127], &sw_out_list[128], &sw_out_list[129], &sw_out_list[130], &sw_out_list[131], &sw_out_list[132], &sw_out_list[133], &sw_out_list[134], &sw_out_list[135], &sw_out_list[136], &sw_out_list[137], &sw_out_list[138], &sw_out_list[139], &sw_out_list[140], &sw_out_list[141], &sw_out_list[142], &sw_out_list[143], &sw_out_list[144], &sw_out_list[145], &sw_out_list[146], &sw_out_list[147], &sw_out_list[148], &sw_out_list[149], &sw_out_list[150], &sw_out_list[151], &sw_out_list[152], &sw_out_list[153], &sw_out_list[154], &sw_out_list[155], &sw_out_list[156], &sw_out_list[157], &sw_out_list[158], &sw_out_list[159], &sw_out_list[160], &sw_out_list[161], &sw_out_list[162], &sw_out_list[163], &sw_out_list[164], &sw_out_list[165], &sw_out_list[166], &sw_out_list[167], &sw_out_list[168], &sw_out_list[169], &sw_out_list[170], &sw_out_list[171], &sw_out_list[172], &sw_out_list[173], &sw_out_list[174], &sw_out_list[175], &sw_out_list[176], &sw_out_list[177], &sw_out_list[178], &sw_out_list[179], &sw_out_list[180], &sw_out_list[181], &sw_out_list[182], &sw_out_list[183], &sw_out_list[184], &sw_out_list[185], &sw_out_list[186], &sw_out_list[187], &sw_out_list[188], &sw_out_list[189], &sw_out_list[190], &sw_out_list[191], &sw_out_list[192], &sw_out_list[193], &sw_out_list[194], &sw_out_list[195], &sw_out_list[196], &sw_out_list[197], &sw_out_list[198], &sw_out_list[199], &sw_out_list[200], &sw_out_list[201], &sw_out_list[202], &sw_out_list[203], &sw_out_list[204], &sw_out_list[205], &sw_out_list[206], &sw_out_list[207], &sw_out_list[208], &sw_out_list[209], &sw_out_list[210], &sw_out_list[211], &sw_out_list[212], &sw_out_list[213], &sw_out_list[214], &sw_out_list[215], &sw_out_list[216], &sw_out_list[217], &sw_out_list[218], &sw_out_list[219], &sw_out_list[220], &sw_out_list[221], &sw_out_list[222], &sw_out_list[223], &sw_out_list[224], &sw_out_list[225], &sw_out_list[226], &sw_out_list[227], &sw_out_list[228], &sw_out_list[229], &sw_out_list[230], &sw_out_list[231], &sw_out_list[232], &sw_out_list[233], &sw_out_list[234], &sw_out_list[235], &sw_out_list[236], &sw_out_list[237], &sw_out_list[238], &sw_out_list[239], &sw_out_list[240], &sw_out_list[241], &sw_out_list[242], &sw_out_list[243], &sw_out_list[244], &sw_out_list[245], &sw_out_list[246], &sw_out_list[247], &sw_out_list[248], &sw_out_list[249], &sw_out_list[250], &sw_out_list[251], &sw_out_list[252], &sw_out_list[253], &sw_out_list[254], &sw_out_list[255]);
	TEST_ASSERT (sw_retval == 0);
	hw_retval = hwdll_read (idx_list[i], hw_out_list);
	TEST_ASSERT (hw_retval == 256 && sw_out_list[0] == hw_out_list[0] && sw_out_list[1] == hw_out_list[1] && sw_out_list[2] == hw_out_list[2] && sw_out_list[3] == hw_out_list[3] && sw_out_list[4] == hw_out_list[4] && sw_out_list[5] == hw_out_list[5] && sw_out_list[6] == hw_out_list[6] && sw_out_list[7] == hw_out_list[7] && sw_out_list[8] == hw_out_list[8] && sw_out_list[9] == hw_out_list[9] && sw_out_list[10] == hw_out_list[10] && sw_out_list[11] == hw_out_list[11] && sw_out_list[12] == hw_out_list[12] && sw_out_list[13] == hw_out_list[13] && sw_out_list[14] == hw_out_list[14] && sw_out_list[15] == hw_out_list[15] && sw_out_list[16] == hw_out_list[16] && sw_out_list[17] == hw_out_list[17] && sw_out_list[18] == hw_out_list[18] && sw_out_list[19] == hw_out_list[19] && sw_out_list[20] == hw_out_list[20] && sw_out_list[21] == hw_out_list[21] && sw_out_list[22] == hw_out_list[22] && sw_out_list[23] == hw_out_list[23] && sw_out_list[24] == hw_out_list[24] && sw_out_list[25] == hw_out_list[25] && sw_out_list[26] == hw_out_list[26] && sw_out_list[27] == hw_out_list[27] && sw_out_list[28] == hw_out_list[28] && sw_out_list[29] == hw_out_list[29] && sw_out_list[30] == hw_out_list[30] && sw_out_list[31] == hw_out_list[31] && sw_out_list[32] == hw_out_list[32] && sw_out_list[33] == hw_out_list[33] && sw_out_list[34] == hw_out_list[34] && sw_out_list[35] == hw_out_list[35] && sw_out_list[36] == hw_out_list[36] && sw_out_list[37] == hw_out_list[37] && sw_out_list[38] == hw_out_list[38] && sw_out_list[39] == hw_out_list[39] && sw_out_list[40] == hw_out_list[40] && sw_out_list[41] == hw_out_list[41] && sw_out_list[42] == hw_out_list[42] && sw_out_list[43] == hw_out_list[43] && sw_out_list[44] == hw_out_list[44] && sw_out_list[45] == hw_out_list[45] && sw_out_list[46] == hw_out_list[46] && sw_out_list[47] == hw_out_list[47] && sw_out_list[48] == hw_out_list[48] && sw_out_list[49] == hw_out_list[49] && sw_out_list[50] == hw_out_list[50] && sw_out_list[51] == hw_out_list[51] && sw_out_list[52] == hw_out_list[52] && sw_out_list[53] == hw_out_list[53] && sw_out_list[54] == hw_out_list[54] && sw_out_list[55] == hw_out_list[55] && sw_out_list[56] == hw_out_list[56] && sw_out_list[57] == hw_out_list[57] && sw_out_list[58] == hw_out_list[58] && sw_out_list[59] == hw_out_list[59] && sw_out_list[60] == hw_out_list[60] && sw_out_list[61] == hw_out_list[61] && sw_out_list[62] == hw_out_list[62] && sw_out_list[63] == hw_out_list[63] && sw_out_list[64] == hw_out_list[64] && sw_out_list[65] == hw_out_list[65] && sw_out_list[66] == hw_out_list[66] && sw_out_list[67] == hw_out_list[67] && sw_out_list[68] == hw_out_list[68] && sw_out_list[69] == hw_out_list[69] && sw_out_list[70] == hw_out_list[70] && sw_out_list[71] == hw_out_list[71] && sw_out_list[72] == hw_out_list[72] && sw_out_list[73] == hw_out_list[73] && sw_out_list[74] == hw_out_list[74] && sw_out_list[75] == hw_out_list[75] && sw_out_list[76] == hw_out_list[76] && sw_out_list[77] == hw_out_list[77] && sw_out_list[78] == hw_out_list[78] && sw_out_list[79] == hw_out_list[79] && sw_out_list[80] == hw_out_list[80] && sw_out_list[81] == hw_out_list[81] && sw_out_list[82] == hw_out_list[82] && sw_out_list[83] == hw_out_list[83] && sw_out_list[84] == hw_out_list[84] && sw_out_list[85] == hw_out_list[85] && sw_out_list[86] == hw_out_list[86] && sw_out_list[87] == hw_out_list[87] && sw_out_list[88] == hw_out_list[88] && sw_out_list[89] == hw_out_list[89] && sw_out_list[90] == hw_out_list[90] && sw_out_list[91] == hw_out_list[91] && sw_out_list[92] == hw_out_list[92] && sw_out_list[93] == hw_out_list[93] && sw_out_list[94] == hw_out_list[94] && sw_out_list[95] == hw_out_list[95] && sw_out_list[96] == hw_out_list[96] && sw_out_list[97] == hw_out_list[97] && sw_out_list[98] == hw_out_list[98] && sw_out_list[99] == hw_out_list[99] && sw_out_list[100] == hw_out_list[100] && sw_out_list[101] == hw_out_list[101] && sw_out_list[102] == hw_out_list[102] && sw_out_list[103] == hw_out_list[103] && sw_out_list[104] == hw_out_list[104] && sw_out_list[105] == hw_out_list[105] && sw_out_list[106] == hw_out_list[106] && sw_out_list[107] == hw_out_list[107] && sw_out_list[108] == hw_out_list[108] && sw_out_list[109] == hw_out_list[109] && sw_out_list[110] == hw_out_list[110] && sw_out_list[111] == hw_out_list[111] && sw_out_list[112] == hw_out_list[112] && sw_out_list[113] == hw_out_list[113] && sw_out_list[114] == hw_out_list[114] && sw_out_list[115] == hw_out_list[115] && sw_out_list[116] == hw_out_list[116] && sw_out_list[117] == hw_out_list[117] && sw_out_list[118] == hw_out_list[118] && sw_out_list[119] == hw_out_list[119] && sw_out_list[120] == hw_out_list[120] && sw_out_list[121] == hw_out_list[121] && sw_out_list[122] == hw_out_list[122] && sw_out_list[123] == hw_out_list[123] && sw_out_list[124] == hw_out_list[124] && sw_out_list[125] == hw_out_list[125] && sw_out_list[126] == hw_out_list[126] && sw_out_list[127] == hw_out_list[127] && sw_out_list[128] == hw_out_list[128] && sw_out_list[129] == hw_out_list[129] && sw_out_list[130] == hw_out_list[130] && sw_out_list[131] == hw_out_list[131] && sw_out_list[132] == hw_out_list[132] && sw_out_list[133] == hw_out_list[133] && sw_out_list[134] == hw_out_list[134] && sw_out_list[135] == hw_out_list[135] && sw_out_list[136] == hw_out_list[136] && sw_out_list[137] == hw_out_list[137] && sw_out_list[138] == hw_out_list[138] && sw_out_list[139] == hw_out_list[139] && sw_out_list[140] == hw_out_list[140] && sw_out_list[141] == hw_out_list[141] && sw_out_list[142] == hw_out_list[142] && sw_out_list[143] == hw_out_list[143] && sw_out_list[144] == hw_out_list[144] && sw_out_list[145] == hw_out_list[145] && sw_out_list[146] == hw_out_list[146] && sw_out_list[147] == hw_out_list[147] && sw_out_list[148] == hw_out_list[148] && sw_out_list[149] == hw_out_list[149] && sw_out_list[150] == hw_out_list[150] && sw_out_list[151] == hw_out_list[151] && sw_out_list[152] == hw_out_list[152] && sw_out_list[153] == hw_out_list[153] && sw_out_list[154] == hw_out_list[154] && sw_out_list[155] == hw_out_list[155] && sw_out_list[156] == hw_out_list[156] && sw_out_list[157] == hw_out_list[157] && sw_out_list[158] == hw_out_list[158] && sw_out_list[159] == hw_out_list[159] && sw_out_list[160] == hw_out_list[160] && sw_out_list[161] == hw_out_list[161] && sw_out_list[162] == hw_out_list[162] && sw_out_list[163] == hw_out_list[163] && sw_out_list[164] == hw_out_list[164] && sw_out_list[165] == hw_out_list[165] && sw_out_list[166] == hw_out_list[166] && sw_out_list[167] == hw_out_list[167] && sw_out_list[168] == hw_out_list[168] && sw_out_list[169] == hw_out_list[169] && sw_out_list[170] == hw_out_list[170] && sw_out_list[171] == hw_out_list[171] && sw_out_list[172] == hw_out_list[172] && sw_out_list[173] == hw_out_list[173] && sw_out_list[174] == hw_out_list[174] && sw_out_list[175] == hw_out_list[175] && sw_out_list[176] == hw_out_list[176] && sw_out_list[177] == hw_out_list[177] && sw_out_list[178] == hw_out_list[178] && sw_out_list[179] == hw_out_list[179] && sw_out_list[180] == hw_out_list[180] && sw_out_list[181] == hw_out_list[181] && sw_out_list[182] == hw_out_list[182] && sw_out_list[183] == hw_out_list[183] && sw_out_list[184] == hw_out_list[184] && sw_out_list[185] == hw_out_list[185] && sw_out_list[186] == hw_out_list[186] && sw_out_list[187] == hw_out_list[187] && sw_out_list[188] == hw_out_list[188] && sw_out_list[189] == hw_out_list[189] && sw_out_list[190] == hw_out_list[190] && sw_out_list[191] == hw_out_list[191] && sw_out_list[192] == hw_out_list[192] && sw_out_list[193] == hw_out_list[193] && sw_out_list[194] == hw_out_list[194] && sw_out_list[195] == hw_out_list[195] && sw_out_list[196] == hw_out_list[196] && sw_out_list[197] == hw_out_list[197] && sw_out_list[198] == hw_out_list[198] && sw_out_list[199] == hw_out_list[199] && sw_out_list[200] == hw_out_list[200] && sw_out_list[201] == hw_out_list[201] && sw_out_list[202] == hw_out_list[202] && sw_out_list[203] == hw_out_list[203] && sw_out_list[204] == hw_out_list[204] && sw_out_list[205] == hw_out_list[205] && sw_out_list[206] == hw_out_list[206] && sw_out_list[207] == hw_out_list[207] && sw_out_list[208] == hw_out_list[208] && sw_out_list[209] == hw_out_list[209] && sw_out_list[210] == hw_out_list[210] && sw_out_list[211] == hw_out_list[211] && sw_out_list[212] == hw_out_list[212] && sw_out_list[213] == hw_out_list[213] && sw_out_list[214] == hw_out_list[214] && sw_out_list[215] == hw_out_list[215] && sw_out_list[216] == hw_out_list[216] && sw_out_list[217] == hw_out_list[217] && sw_out_list[218] == hw_out_list[218] && sw_out_list[219] == hw_out_list[219] && sw_out_list[220] == hw_out_list[220] && sw_out_list[221] == hw_out_list[221] && sw_out_list[222] == hw_out_list[222] && sw_out_list[223] == hw_out_list[223] && sw_out_list[224] == hw_out_list[224] && sw_out_list[225] == hw_out_list[225] && sw_out_list[226] == hw_out_list[226] && sw_out_list[227] == hw_out_list[227] && sw_out_list[228] == hw_out_list[228] && sw_out_list[229] == hw_out_list[229] && sw_out_list[230] == hw_out_list[230] && sw_out_list[231] == hw_out_list[231] && sw_out_list[232] == hw_out_list[232] && sw_out_list[233] == hw_out_list[233] && sw_out_list[234] == hw_out_list[234] && sw_out_list[235] == hw_out_list[235] && sw_out_list[236] == hw_out_list[236] && sw_out_list[237] == hw_out_list[237] && sw_out_list[238] == hw_out_list[238] && sw_out_list[239] == hw_out_list[239] && sw_out_list[240] == hw_out_list[240] && sw_out_list[241] == hw_out_list[241] && sw_out_list[242] == hw_out_list[242] && sw_out_list[243] == hw_out_list[243] && sw_out_list[244] == hw_out_list[244] && sw_out_list[245] == hw_out_list[245] && sw_out_list[246] == hw_out_list[246] && sw_out_list[247] == hw_out_list[247] && sw_out_list[248] == hw_out_list[248] && sw_out_list[249] == hw_out_list[249] && sw_out_list[250] == hw_out_list[250] && sw_out_list[251] == hw_out_list[251] && sw_out_list[252] == hw_out_list[252] && sw_out_list[253] == hw_out_list[253] && sw_out_list[254] == hw_out_list[254] && sw_out_list[255] == hw_out_list[255]);
	i = 13; /* Evaluate Numbers																											*/
	sw_retval = numbers (&sw_out_list[0], &sw_out_list[1], &sw_out_list[2], &sw_out_list[3], &sw_out_list[4], &sw_out_list[5], &sw_out_list[6], &sw_out_list[7], &sw_out_list[8], &sw_out_list[9], &sw_out_list[10], &sw_out_list[11], &sw_out_list[12], &sw_out_list[13], &sw_out_list[14], &sw_out_list[15], &sw_out_list[16], &sw_out_list[17], &sw_out_list[18], &sw_out_list[19], &sw_out_list[20], &sw_out_list[21], &sw_out_list[22], &sw_out_list[23], &sw_out_list[24], &sw_out_list[25], &sw_out_list[26], &sw_out_list[27], &sw_out_list[28], &sw_out_list[29], &sw_out_list[30], &sw_out_list[31], &sw_out_list[32], &sw_out_list[33], &sw_out_list[34], &sw_out_list[35], &sw_out_list[36], &sw_out_list[37], &sw_out_list[38], &sw_out_list[39], &sw_out_list[40], &sw_out_list[41], &sw_out_list[42], &sw_out_list[43], &sw_out_list[44], &sw_out_list[45], &sw_out_list[46], &sw_out_list[47], &sw_out_list[48], &sw_out_list[49], &sw_out_list[50], &sw_out_list[51], &sw_out_list[52], &sw_out_list[53], &sw_out_list[54], &sw_out_list[55], &sw_out_list[56], &sw_out_list[57], &sw_out_list[58], &sw_out_list[59], &sw_out_list[60], &sw_out_list[61], &sw_out_list[62], &sw_out_list[63], &sw_out_list[64], &sw_out_list[65], &sw_out_list[66], &sw_out_list[67], &sw_out_list[68], &sw_out_list[69], &sw_out_list[70], &sw_out_list[71], &sw_out_list[72], &sw_out_list[73], &sw_out_list[74], &sw_out_list[75], &sw_out_list[76], &sw_out_list[77], &sw_out_list[78], &sw_out_list[79], &sw_out_list[80], &sw_out_list[81], &sw_out_list[82], &sw_out_list[83], &sw_out_list[84], &sw_out_list[85], &sw_out_list[86], &sw_out_list[87], &sw_out_list[88], &sw_out_list[89], &sw_out_list[90], &sw_out_list[91], &sw_out_list[92], &sw_out_list[93], &sw_out_list[94], &sw_out_list[95], &sw_out_list[96], &sw_out_list[97], &sw_out_list[98], &sw_out_list[99], &sw_out_list[100], &sw_out_list[101], &sw_out_list[102], &sw_out_list[103], &sw_out_list[104], &sw_out_list[105], &sw_out_list[106], &sw_out_list[107], &sw_out_list[108], &sw_out_list[109], &sw_out_list[110], &sw_out_list[111], &sw_out_list[112], &sw_out_list[113], &sw_out_list[114], &sw_out_list[115], &sw_out_list[116], &sw_out_list[117], &sw_out_list[118], &sw_out_list[119], &sw_out_list[120], &sw_out_list[121], &sw_out_list[122], &sw_out_list[123], &sw_out_list[124], &sw_out_list[125], &sw_out_list[126], &sw_out_list[127], &sw_out_list[128], &sw_out_list[129], &sw_out_list[130], &sw_out_list[131], &sw_out_list[132], &sw_out_list[133], &sw_out_list[134], &sw_out_list[135], &sw_out_list[136], &sw_out_list[137], &sw_out_list[138], &sw_out_list[139], &sw_out_list[140], &sw_out_list[141], &sw_out_list[142], &sw_out_list[143], &sw_out_list[144], &sw_out_list[145], &sw_out_list[146], &sw_out_list[147], &sw_out_list[148], &sw_out_list[149], &sw_out_list[150], &sw_out_list[151], &sw_out_list[152], &sw_out_list[153], &sw_out_list[154], &sw_out_list[155], &sw_out_list[156], &sw_out_list[157], &sw_out_list[158], &sw_out_list[159], &sw_out_list[160], &sw_out_list[161], &sw_out_list[162], &sw_out_list[163], &sw_out_list[164], &sw_out_list[165], &sw_out_list[166], &sw_out_list[167], &sw_out_list[168], &sw_out_list[169], &sw_out_list[170], &sw_out_list[171], &sw_out_list[172], &sw_out_list[173], &sw_out_list[174], &sw_out_list[175], &sw_out_list[176], &sw_out_list[177], &sw_out_list[178], &sw_out_list[179], &sw_out_list[180], &sw_out_list[181], &sw_out_list[182], &sw_out_list[183], &sw_out_list[184], &sw_out_list[185], &sw_out_list[186], &sw_out_list[187], &sw_out_list[188], &sw_out_list[189], &sw_out_list[190], &sw_out_list[191], &sw_out_list[192], &sw_out_list[193], &sw_out_list[194], &sw_out_list[195], &sw_out_list[196], &sw_out_list[197], &sw_out_list[198], &sw_out_list[199], &sw_out_list[200], &sw_out_list[201], &sw_out_list[202], &sw_out_list[203], &sw_out_list[204], &sw_out_list[205], &sw_out_list[206], &sw_out_list[207], &sw_out_list[208], &sw_out_list[209], &sw_out_list[210], &sw_out_list[211], &sw_out_list[212], &sw_out_list[213], &sw_out_list[214], &sw_out_list[215], &sw_out_list[216], &sw_out_list[217], &sw_out_list[218], &sw_out_list[219], &sw_out_list[220], &sw_out_list[221], &sw_out_list[222], &sw_out_list[223], &sw_out_list[224], &sw_out_list[225], &sw_out_list[226], &sw_out_list[227], &sw_out_list[228], &sw_out_list[229], &sw_out_list[230], &sw_out_list[231], &sw_out_list[232], &sw_out_list[233], &sw_out_list[234], &sw_out_list[235], &sw_out_list[236], &sw_out_list[237], &sw_out_list[238], &sw_out_list[239], &sw_out_list[240], &sw_out_list[241], &sw_out_list[242], &sw_out_list[243], &sw_out_list[244], &sw_out_list[245], &sw_out_list[246], &sw_out_list[247], &sw_out_list[248], &sw_out_list[249], &sw_out_list[250], &sw_out_list[251], &sw_out_list[252], &sw_out_list[253], &sw_out_list[254], &sw_out_list[255]);
	TEST_ASSERT (sw_retval == 0);
	hw_retval = hwdll_read (idx_list[i], hw_out_list);
	TEST_ASSERT (hw_retval == 256 && sw_out_list[0] == hw_out_list[0] && sw_out_list[1] == hw_out_list[1] && sw_out_list[2] == hw_out_list[2] && sw_out_list[3] == hw_out_list[3] && sw_out_list[4] == hw_out_list[4] && sw_out_list[5] == hw_out_list[5] && sw_out_list[6] == hw_out_list[6] && sw_out_list[7] == hw_out_list[7] && sw_out_list[8] == hw_out_list[8] && sw_out_list[9] == hw_out_list[9] && sw_out_list[10] == hw_out_list[10] && sw_out_list[11] == hw_out_list[11] && sw_out_list[12] == hw_out_list[12] && sw_out_list[13] == hw_out_list[13] && sw_out_list[14] == hw_out_list[14] && sw_out_list[15] == hw_out_list[15] && sw_out_list[16] == hw_out_list[16] && sw_out_list[17] == hw_out_list[17] && sw_out_list[18] == hw_out_list[18] && sw_out_list[19] == hw_out_list[19] && sw_out_list[20] == hw_out_list[20] && sw_out_list[21] == hw_out_list[21] && sw_out_list[22] == hw_out_list[22] && sw_out_list[23] == hw_out_list[23] && sw_out_list[24] == hw_out_list[24] && sw_out_list[25] == hw_out_list[25] && sw_out_list[26] == hw_out_list[26] && sw_out_list[27] == hw_out_list[27] && sw_out_list[28] == hw_out_list[28] && sw_out_list[29] == hw_out_list[29] && sw_out_list[30] == hw_out_list[30] && sw_out_list[31] == hw_out_list[31] && sw_out_list[32] == hw_out_list[32] && sw_out_list[33] == hw_out_list[33] && sw_out_list[34] == hw_out_list[34] && sw_out_list[35] == hw_out_list[35] && sw_out_list[36] == hw_out_list[36] && sw_out_list[37] == hw_out_list[37] && sw_out_list[38] == hw_out_list[38] && sw_out_list[39] == hw_out_list[39] && sw_out_list[40] == hw_out_list[40] && sw_out_list[41] == hw_out_list[41] && sw_out_list[42] == hw_out_list[42] && sw_out_list[43] == hw_out_list[43] && sw_out_list[44] == hw_out_list[44] && sw_out_list[45] == hw_out_list[45] && sw_out_list[46] == hw_out_list[46] && sw_out_list[47] == hw_out_list[47] && sw_out_list[48] == hw_out_list[48] && sw_out_list[49] == hw_out_list[49] && sw_out_list[50] == hw_out_list[50] && sw_out_list[51] == hw_out_list[51] && sw_out_list[52] == hw_out_list[52] && sw_out_list[53] == hw_out_list[53] && sw_out_list[54] == hw_out_list[54] && sw_out_list[55] == hw_out_list[55] && sw_out_list[56] == hw_out_list[56] && sw_out_list[57] == hw_out_list[57] && sw_out_list[58] == hw_out_list[58] && sw_out_list[59] == hw_out_list[59] && sw_out_list[60] == hw_out_list[60] && sw_out_list[61] == hw_out_list[61] && sw_out_list[62] == hw_out_list[62] && sw_out_list[63] == hw_out_list[63] && sw_out_list[64] == hw_out_list[64] && sw_out_list[65] == hw_out_list[65] && sw_out_list[66] == hw_out_list[66] && sw_out_list[67] == hw_out_list[67] && sw_out_list[68] == hw_out_list[68] && sw_out_list[69] == hw_out_list[69] && sw_out_list[70] == hw_out_list[70] && sw_out_list[71] == hw_out_list[71] && sw_out_list[72] == hw_out_list[72] && sw_out_list[73] == hw_out_list[73] && sw_out_list[74] == hw_out_list[74] && sw_out_list[75] == hw_out_list[75] && sw_out_list[76] == hw_out_list[76] && sw_out_list[77] == hw_out_list[77] && sw_out_list[78] == hw_out_list[78] && sw_out_list[79] == hw_out_list[79] && sw_out_list[80] == hw_out_list[80] && sw_out_list[81] == hw_out_list[81] && sw_out_list[82] == hw_out_list[82] && sw_out_list[83] == hw_out_list[83] && sw_out_list[84] == hw_out_list[84] && sw_out_list[85] == hw_out_list[85] && sw_out_list[86] == hw_out_list[86] && sw_out_list[87] == hw_out_list[87] && sw_out_list[88] == hw_out_list[88] && sw_out_list[89] == hw_out_list[89] && sw_out_list[90] == hw_out_list[90] && sw_out_list[91] == hw_out_list[91] && sw_out_list[92] == hw_out_list[92] && sw_out_list[93] == hw_out_list[93] && sw_out_list[94] == hw_out_list[94] && sw_out_list[95] == hw_out_list[95] && sw_out_list[96] == hw_out_list[96] && sw_out_list[97] == hw_out_list[97] && sw_out_list[98] == hw_out_list[98] && sw_out_list[99] == hw_out_list[99] && sw_out_list[100] == hw_out_list[100] && sw_out_list[101] == hw_out_list[101] && sw_out_list[102] == hw_out_list[102] && sw_out_list[103] == hw_out_list[103] && sw_out_list[104] == hw_out_list[104] && sw_out_list[105] == hw_out_list[105] && sw_out_list[106] == hw_out_list[106] && sw_out_list[107] == hw_out_list[107] && sw_out_list[108] == hw_out_list[108] && sw_out_list[109] == hw_out_list[109] && sw_out_list[110] == hw_out_list[110] && sw_out_list[111] == hw_out_list[111] && sw_out_list[112] == hw_out_list[112] && sw_out_list[113] == hw_out_list[113] && sw_out_list[114] == hw_out_list[114] && sw_out_list[115] == hw_out_list[115] && sw_out_list[116] == hw_out_list[116] && sw_out_list[117] == hw_out_list[117] && sw_out_list[118] == hw_out_list[118] && sw_out_list[119] == hw_out_list[119] && sw_out_list[120] == hw_out_list[120] && sw_out_list[121] == hw_out_list[121] && sw_out_list[122] == hw_out_list[122] && sw_out_list[123] == hw_out_list[123] && sw_out_list[124] == hw_out_list[124] && sw_out_list[125] == hw_out_list[125] && sw_out_list[126] == hw_out_list[126] && sw_out_list[127] == hw_out_list[127] && sw_out_list[128] == hw_out_list[128] && sw_out_list[129] == hw_out_list[129] && sw_out_list[130] == hw_out_list[130] && sw_out_list[131] == hw_out_list[131] && sw_out_list[132] == hw_out_list[132] && sw_out_list[133] == hw_out_list[133] && sw_out_list[134] == hw_out_list[134] && sw_out_list[135] == hw_out_list[135] && sw_out_list[136] == hw_out_list[136] && sw_out_list[137] == hw_out_list[137] && sw_out_list[138] == hw_out_list[138] && sw_out_list[139] == hw_out_list[139] && sw_out_list[140] == hw_out_list[140] && sw_out_list[141] == hw_out_list[141] && sw_out_list[142] == hw_out_list[142] && sw_out_list[143] == hw_out_list[143] && sw_out_list[144] == hw_out_list[144] && sw_out_list[145] == hw_out_list[145] && sw_out_list[146] == hw_out_list[146] && sw_out_list[147] == hw_out_list[147] && sw_out_list[148] == hw_out_list[148] && sw_out_list[149] == hw_out_list[149] && sw_out_list[150] == hw_out_list[150] && sw_out_list[151] == hw_out_list[151] && sw_out_list[152] == hw_out_list[152] && sw_out_list[153] == hw_out_list[153] && sw_out_list[154] == hw_out_list[154] && sw_out_list[155] == hw_out_list[155] && sw_out_list[156] == hw_out_list[156] && sw_out_list[157] == hw_out_list[157] && sw_out_list[158] == hw_out_list[158] && sw_out_list[159] == hw_out_list[159] && sw_out_list[160] == hw_out_list[160] && sw_out_list[161] == hw_out_list[161] && sw_out_list[162] == hw_out_list[162] && sw_out_list[163] == hw_out_list[163] && sw_out_list[164] == hw_out_list[164] && sw_out_list[165] == hw_out_list[165] && sw_out_list[166] == hw_out_list[166] && sw_out_list[167] == hw_out_list[167] && sw_out_list[168] == hw_out_list[168] && sw_out_list[169] == hw_out_list[169] && sw_out_list[170] == hw_out_list[170] && sw_out_list[171] == hw_out_list[171] && sw_out_list[172] == hw_out_list[172] && sw_out_list[173] == hw_out_list[173] && sw_out_list[174] == hw_out_list[174] && sw_out_list[175] == hw_out_list[175] && sw_out_list[176] == hw_out_list[176] && sw_out_list[177] == hw_out_list[177] && sw_out_list[178] == hw_out_list[178] && sw_out_list[179] == hw_out_list[179] && sw_out_list[180] == hw_out_list[180] && sw_out_list[181] == hw_out_list[181] && sw_out_list[182] == hw_out_list[182] && sw_out_list[183] == hw_out_list[183] && sw_out_list[184] == hw_out_list[184] && sw_out_list[185] == hw_out_list[185] && sw_out_list[186] == hw_out_list[186] && sw_out_list[187] == hw_out_list[187] && sw_out_list[188] == hw_out_list[188] && sw_out_list[189] == hw_out_list[189] && sw_out_list[190] == hw_out_list[190] && sw_out_list[191] == hw_out_list[191] && sw_out_list[192] == hw_out_list[192] && sw_out_list[193] == hw_out_list[193] && sw_out_list[194] == hw_out_list[194] && sw_out_list[195] == hw_out_list[195] && sw_out_list[196] == hw_out_list[196] && sw_out_list[197] == hw_out_list[197] && sw_out_list[198] == hw_out_list[198] && sw_out_list[199] == hw_out_list[199] && sw_out_list[200] == hw_out_list[200] && sw_out_list[201] == hw_out_list[201] && sw_out_list[202] == hw_out_list[202] && sw_out_list[203] == hw_out_list[203] && sw_out_list[204] == hw_out_list[204] && sw_out_list[205] == hw_out_list[205] && sw_out_list[206] == hw_out_list[206] && sw_out_list[207] == hw_out_list[207] && sw_out_list[208] == hw_out_list[208] && sw_out_list[209] == hw_out_list[209] && sw_out_list[210] == hw_out_list[210] && sw_out_list[211] == hw_out_list[211] && sw_out_list[212] == hw_out_list[212] && sw_out_list[213] == hw_out_list[213] && sw_out_list[214] == hw_out_list[214] && sw_out_list[215] == hw_out_list[215] && sw_out_list[216] == hw_out_list[216] && sw_out_list[217] == hw_out_list[217] && sw_out_list[218] == hw_out_list[218] && sw_out_list[219] == hw_out_list[219] && sw_out_list[220] == hw_out_list[220] && sw_out_list[221] == hw_out_list[221] && sw_out_list[222] == hw_out_list[222] && sw_out_list[223] == hw_out_list[223] && sw_out_list[224] == hw_out_list[224] && sw_out_list[225] == hw_out_list[225] && sw_out_list[226] == hw_out_list[226] && sw_out_list[227] == hw_out_list[227] && sw_out_list[228] == hw_out_list[228] && sw_out_list[229] == hw_out_list[229] && sw_out_list[230] == hw_out_list[230] && sw_out_list[231] == hw_out_list[231] && sw_out_list[232] == hw_out_list[232] && sw_out_list[233] == hw_out_list[233] && sw_out_list[234] == hw_out_list[234] && sw_out_list[235] == hw_out_list[235] && sw_out_list[236] == hw_out_list[236] && sw_out_list[237] == hw_out_list[237] && sw_out_list[238] == hw_out_list[238] && sw_out_list[239] == hw_out_list[239] && sw_out_list[240] == hw_out_list[240] && sw_out_list[241] == hw_out_list[241] && sw_out_list[242] == hw_out_list[242] && sw_out_list[243] == hw_out_list[243] && sw_out_list[244] == hw_out_list[244] && sw_out_list[245] == hw_out_list[245] && sw_out_list[246] == hw_out_list[246] && sw_out_list[247] == hw_out_list[247] && sw_out_list[248] == hw_out_list[248] && sw_out_list[249] == hw_out_list[249] && sw_out_list[250] == hw_out_list[250] && sw_out_list[251] == hw_out_list[251] && sw_out_list[252] == hw_out_list[252] && sw_out_list[253] == hw_out_list[253] && sw_out_list[254] == hw_out_list[254] && sw_out_list[255] == hw_out_list[255]);
	i = 14; /* Evaluate Greatest Common Divisor																					*/
	sw_retval = gcd (in_list[0], in_list[1], &sw_out_list[0]);
	TEST_ASSERT (sw_retval == 0);
	hw_retval = hwdll_write (idx_list[i], in_list);
	TEST_ASSERT (hw_retval == 2);
	hw_retval = hwdll_read (idx_list[i], hw_out_list);
	TEST_ASSERT (hw_retval == 1 && sw_out_list[0] == hw_out_list[0]);
	i = 15; /* Evaluate Greatest Common Divisor																					*/
	sw_retval = gcd (in_list[0], in_list[1], &sw_out_list[0]);
	TEST_ASSERT (sw_retval == 0);
	hw_retval = hwdll_write (idx_list[i], in_list);
	TEST_ASSERT (hw_retval == 2);
	hw_retval = hwdll_read (idx_list[i], hw_out_list);
	TEST_ASSERT (hw_retval == 1 && sw_out_list[0] == hw_out_list[0]);
	hwdll_unload_list (idx_list, RP_LIST_SIZE, false);
	hwdll_destroy ();
	return true;
}



/************************************************************************************************************************	*/
/*                                                                 Main Function                                                                	*/
/************************************************************************************************************************	*/

int main (void)
{
	FILE* dump = NULL;
	bool failed = false;
	char line[STR_MAX] = "";
	char* parse_line = NULL;
	system ("clear");
	printf ("#################################################################################################\n");
	printf ("#\t\t\t\t\t\t\t\t\t\t\t\t#\n");
	printf ("#\t\t\t\tBi-Semestrial Student Project (2014 – 2015)\t\t\t#\n");
	printf ("#\t\t\t\tParallel Systems Laboratory\t\t\t\t\t#\n");
	printf ("#\t\t\t\tElectrical Engineering Department\t\t\t\t#\n");
	printf ("#\t\t\t\tTechnion – Israel Institute of Technology\t\t\t#\n");
	printf ("#\t\t\t\t\t\t\t\t\t\t\t\t#\n");
	printf ("#\tTitle:\t\t\tHardware DLL\t\t\t\t\t\t\t#\n");
	printf ("#\tSubject:\t\tReal Time Partial Reconfiguration Management of FPGA by OS\t#\n");
	printf ("#\t\t\t\t\t\t\t\t\t\t\t\t#\n");
	printf ("#\tAuthor:\t\t\tAlon Reznik\t\t\t\t\t\t\t#\n");
	printf ("#\tSupervisor:\t\tOz Shmueli\t\t\t\t\t\t\t#\n");
	printf ("#\t\t\t\t\t\t\t\t\t\t\t\t#\n");
	printf ("#\tLast Update:\t\t24/01/2016\t\t\t\t\t\t\t#\n");
	printf ("#\t\t\t\t\t\t\t\t\t\t\t\t#\n");
	printf ("#################################################################################################\n\n");
	printf ("#################################################################################################\n");
	printf ("#\t\t\t\t\t\t\t\t\t\t\t\t#\n");
	TEST_RUN (test_sys);
	TEST_RUN (test_bram);
	TEST_RUN (test_mono);
	TEST_RUN (test_multi);
	TEST_RUN (test_manual);
	TEST_RUN (test_auto);
	TEST_RUN (test_set);
	TEST_RUN (test_list);
	printf ("#–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––#\n");
	printf ("#\tHardware DLL Self-Test:\t\t\t\t%s\t\t\t\t#\n", failed ? "[FAILED]" : "[  OK  ]");
	printf ("#\t\t\t\t\t\t\t\t\t\t\t\t#\n");
	printf ("#################################################################################################\n");
	if (failed)
	{
		dump = fopen (DUMP_FILE, "r");
		printf ("\n");
		while (fgets (line, STR_MAX, dump))
		{
			parse_line = line;
			if (*parse_line == '\t')
			{
				parse_line++;
			}
			printf (parse_line);
		}
		fclose (dump);
	}
	return EXIT_SUCCESS;
}



/************************************************************************************************************************	*/
