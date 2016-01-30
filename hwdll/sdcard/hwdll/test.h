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
 * File Name:							test.h																										*
 * Last Update:						24/01/2016																							*
 *																																						*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef TEST_H_
#define TEST_H_



/************************************************************************************************************************	*/
/*                                                             Macro Definitions                                                             	*/
/************************************************************************************************************************	*/

/* Offset address of the BRAM.																											*/
#define BRAM_OFFSET	0x70002000
/* Number that is written to the BRAM.																								*/
#define BRAM_NUM		29081997
/* Number of hardware accelerators in the catalog file.																			*/
#define CAT_SIZE			10
/* Number of bytes in a kilobyte.																											*/
#define KILOBYTE			1024



/************************************************************************************************************************	*/
/*                                                     Targeted Function Prototypes                                                     	*/
/************************************************************************************************************************	*/

/**
 * dummy								Sets an array of 256 integers to zero.
 *
 * output_*:							0.
 */
int dummy (int* output_000, int* output_001, int* output_002, int* output_003, int* output_004, int* output_005, int* output_006, int* output_007, int* output_008, int* output_009, int* output_010, int* output_011, int* output_012, int* output_013, int* output_014, int* output_015, int* output_016, int* output_017, int* output_018, int* output_019, int* output_020, int* output_021, int* output_022, int* output_023, int* output_024, int* output_025, int* output_026, int* output_027, int* output_028, int* output_029, int* output_030, int* output_031, int* output_032, int* output_033, int* output_034, int* output_035, int* output_036, int* output_037, int* output_038, int* output_039, int* output_040, int* output_041, int* output_042, int* output_043, int* output_044, int* output_045, int* output_046, int* output_047, int* output_048, int* output_049, int* output_050, int* output_051, int* output_052, int* output_053, int* output_054, int* output_055, int* output_056, int* output_057, int* output_058, int* output_059, int* output_060, int* output_061, int* output_062, int* output_063, int* output_064, int* output_065, int* output_066, int* output_067, int* output_068, int* output_069, int* output_070, int* output_071, int* output_072, int* output_073, int* output_074, int* output_075, int* output_076, int* output_077, int* output_078, int* output_079, int* output_080, int* output_081, int* output_082, int* output_083, int* output_084, int* output_085, int* output_086, int* output_087, int* output_088, int* output_089, int* output_090, int* output_091, int* output_092, int* output_093, int* output_094, int* output_095, int* output_096, int* output_097, int* output_098, int* output_099, int* output_100, int* output_101, int* output_102, int* output_103, int* output_104, int* output_105, int* output_106, int* output_107, int* output_108, int* output_109, int* output_110, int* output_111, int* output_112, int* output_113, int* output_114, int* output_115, int* output_116, int* output_117, int* output_118, int* output_119, int* output_120, int* output_121, int* output_122, int* output_123, int* output_124, int* output_125, int* output_126, int* output_127, int* output_128, int* output_129, int* output_130, int* output_131, int* output_132, int* output_133, int* output_134, int* output_135, int* output_136, int* output_137, int* output_138, int* output_139, int* output_140, int* output_141, int* output_142, int* output_143, int* output_144, int* output_145, int* output_146, int* output_147, int* output_148, int* output_149, int* output_150, int* output_151, int* output_152, int* output_153, int* output_154, int* output_155, int* output_156, int* output_157, int* output_158, int* output_159, int* output_160, int* output_161, int* output_162, int* output_163, int* output_164, int* output_165, int* output_166, int* output_167, int* output_168, int* output_169, int* output_170, int* output_171, int* output_172, int* output_173, int* output_174, int* output_175, int* output_176, int* output_177, int* output_178, int* output_179, int* output_180, int* output_181, int* output_182, int* output_183, int* output_184, int* output_185, int* output_186, int* output_187, int* output_188, int* output_189, int* output_190, int* output_191, int* output_192, int* output_193, int* output_194, int* output_195, int* output_196, int* output_197, int* output_198, int* output_199, int* output_200, int* output_201, int* output_202, int* output_203, int* output_204, int* output_205, int* output_206, int* output_207, int* output_208, int* output_209, int* output_210, int* output_211, int* output_212, int* output_213, int* output_214, int* output_215, int* output_216, int* output_217, int* output_218, int* output_219, int* output_220, int* output_221, int* output_222, int* output_223, int* output_224, int* output_225, int* output_226, int* output_227, int* output_228, int* output_229, int* output_230, int* output_231, int* output_232, int* output_233, int* output_234, int* output_235, int* output_236, int* output_237, int* output_238, int* output_239, int* output_240, int* output_241, int* output_242, int* output_243, int* output_244, int* output_245, int* output_246, int* output_247, int* output_248, int* output_249, int* output_250, int* output_251, int* output_252, int* output_253, int* output_254, int* output_255);

/**
 * numbers							Sets an array of 256 integers to their respective indexes.
 *
 * output_*:							*.
 */
int numbers (int* output_000, int* output_001, int* output_002, int* output_003, int* output_004, int* output_005, int* output_006, int* output_007, int* output_008, int* output_009, int* output_010, int* output_011, int* output_012, int* output_013, int* output_014, int* output_015, int* output_016, int* output_017, int* output_018, int* output_019, int* output_020, int* output_021, int* output_022, int* output_023, int* output_024, int* output_025, int* output_026, int* output_027, int* output_028, int* output_029, int* output_030, int* output_031, int* output_032, int* output_033, int* output_034, int* output_035, int* output_036, int* output_037, int* output_038, int* output_039, int* output_040, int* output_041, int* output_042, int* output_043, int* output_044, int* output_045, int* output_046, int* output_047, int* output_048, int* output_049, int* output_050, int* output_051, int* output_052, int* output_053, int* output_054, int* output_055, int* output_056, int* output_057, int* output_058, int* output_059, int* output_060, int* output_061, int* output_062, int* output_063, int* output_064, int* output_065, int* output_066, int* output_067, int* output_068, int* output_069, int* output_070, int* output_071, int* output_072, int* output_073, int* output_074, int* output_075, int* output_076, int* output_077, int* output_078, int* output_079, int* output_080, int* output_081, int* output_082, int* output_083, int* output_084, int* output_085, int* output_086, int* output_087, int* output_088, int* output_089, int* output_090, int* output_091, int* output_092, int* output_093, int* output_094, int* output_095, int* output_096, int* output_097, int* output_098, int* output_099, int* output_100, int* output_101, int* output_102, int* output_103, int* output_104, int* output_105, int* output_106, int* output_107, int* output_108, int* output_109, int* output_110, int* output_111, int* output_112, int* output_113, int* output_114, int* output_115, int* output_116, int* output_117, int* output_118, int* output_119, int* output_120, int* output_121, int* output_122, int* output_123, int* output_124, int* output_125, int* output_126, int* output_127, int* output_128, int* output_129, int* output_130, int* output_131, int* output_132, int* output_133, int* output_134, int* output_135, int* output_136, int* output_137, int* output_138, int* output_139, int* output_140, int* output_141, int* output_142, int* output_143, int* output_144, int* output_145, int* output_146, int* output_147, int* output_148, int* output_149, int* output_150, int* output_151, int* output_152, int* output_153, int* output_154, int* output_155, int* output_156, int* output_157, int* output_158, int* output_159, int* output_160, int* output_161, int* output_162, int* output_163, int* output_164, int* output_165, int* output_166, int* output_167, int* output_168, int* output_169, int* output_170, int* output_171, int* output_172, int* output_173, int* output_174, int* output_175, int* output_176, int* output_177, int* output_178, int* output_179, int* output_180, int* output_181, int* output_182, int* output_183, int* output_184, int* output_185, int* output_186, int* output_187, int* output_188, int* output_189, int* output_190, int* output_191, int* output_192, int* output_193, int* output_194, int* output_195, int* output_196, int* output_197, int* output_198, int* output_199, int* output_200, int* output_201, int* output_202, int* output_203, int* output_204, int* output_205, int* output_206, int* output_207, int* output_208, int* output_209, int* output_210, int* output_211, int* output_212, int* output_213, int* output_214, int* output_215, int* output_216, int* output_217, int* output_218, int* output_219, int* output_220, int* output_221, int* output_222, int* output_223, int* output_224, int* output_225, int* output_226, int* output_227, int* output_228, int* output_229, int* output_230, int* output_231, int* output_232, int* output_233, int* output_234, int* output_235, int* output_236, int* output_237, int* output_238, int* output_239, int* output_240, int* output_241, int* output_242, int* output_243, int* output_244, int* output_245, int* output_246, int* output_247, int* output_248, int* output_249, int* output_250, int* output_251, int* output_252, int* output_253, int* output_254, int* output_255);

/**
 * int_max								Sets an integer to its maximum value in the system.
 *
 * output_000:						The maximum value of an integer in the system.
 */
int int_max (int* output_000);

/**
 * adder_subtractor				Calculates the sum and difference of two given integers.
 *
 * output_000:						The sum of input_000 and input_001.
 * output_001:						The absolute value of the difference between input_000 and input_001.
 */
int adder_subtractor (int input_000, int input_001, int* output_000, int* output_001);

/**
 * multiplier							Calculates the product of two given integers.
 *
 * output_000:						The product of input_000 and input_001.
 */
int multiplier (int input_000, int input_001, int* output_000);

/**
 * factorial								Calculates the factorial of a given integer.
 *
 * output_000:						The factorial of input_000.
 */
int factorial (int input_000, int* output_000);

/**
 * bitwise_right_shift				Calculates the quotient by two of a given integer.
 *
 * output_000:						The quotient of input_000 divided by 2.
 */
int bitwise_right_shift (int input_000, int* output_000);

/**
 * gcd									Calculates the greatest common divisor of two given integers.
 *
 * output_000:						The greatest common divisor of input_000 and input_001.
 */
int gcd (int input_000, int input_001, int* output_000);

/**
 * fibonacci							Finds a Fibonacci number by a given index.
 *
 * output_000:						The Fibonacci term number input_000.
 */
int fibonacci (int input_000, int* output_000);

/**
 * prime									Finds a prime number by a given index.
 *
 * output_000:						The prime term number input_000.
 */
int prime (int input_000, int* output_000);

/**
 * prime_neighbours				Finds the immediate last and next prime numbers of a given integer.
 *
 * output_000:						The first prime number less than input_000.
 * output_001:						The first prime number greater than input_000.
 */
int prime_neighbours (int input_000, int* output_000, int* output_001);



/************************************************************************************************************************	*/
/*                                                        Test Function Prototypes                                                        	*/
/************************************************************************************************************************	*/

/**
 * Return value upon success:	true.
 * Return value upon failure:	false.
 */

/**
 * test_sys								Verifies that Hardware DLL runs on a 32-bit system.
 */
bool test_sys (void);

/**
 * test_bram							Creates an initialized Hardware DLL data structure.
 * 											Verifies that the BRAM is working correctly.
 * 											Destroys the initialized Hardware DLL data structure.
 */
bool test_bram (void);

/**
 * test_mono							Loads hardware accelerator 0 to a single reconfigurable partition (simple load).
 * 											Reads the loaded reconfigurable module's output.
 * 											Unloads hardware accelerator 0 from the reconfigurable partition (simple unload).
 */
bool test_mono (void);

/**
 * test_multi							Loads hardware accelerator 0 to a single reconfigurable partition (advanced load).
 * 											Reads the loaded reconfigurable module's output.
 * 											Unloads hardware accelerator 0 from the reconfigurable partition (advanced unload).
 */
bool test_multi (void);

/**
 * test_manual						Loads hardware accelerator 0 to all possible reconfigurable partitions (simple load - one by one).
 * 											Unloads hardware accelerator 0 from the reconfigurable partitions (simple unload - one by one).
 */
bool test_manual (void);

/**
 * test_auto							Loads hardware accelerator 0 to all possible reconfigurable partitions (advanced load - all at once).
 * 											Unloads hardware accelerator 0 from the reconfigurable partitions (advanced unload - all at once).
 */
bool test_auto (void);

/**
 * test_set								Loads a set of hardware accelerators (0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10) to reconfigurable partitions (advanced load - all at once).
 * 											Unloads the set of hardware accelerators from the reconfigurable partitions (advanced unload - all at once).
 */
bool test_set (void);

/**
 * test_list								Loads a list of hardware accelerators (3, 0, 4, 0, 2, 2, 2, 3, 4, 5, 0, 1, 1, 1, 0, 2) to reconfigurable partitions (advanced load - all at once).
 * 											Unloads the list of hardware accelerators from the reconfigurable partitions (advanced unload - all at once).
 */
bool test_list (void);



/************************************************************************************************************************	*/

#endif /* TEST_H_ */
