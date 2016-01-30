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
 * File Name:							./targeted_functions/adder_subtractor/targeted_function.c							*
 * Last Update:						01/12/2015																							*
 *																																						*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */



/**
 * output_000:						The sum of input_000 and input_001.
 * output_001:						The absolute value of the difference between input_000 and input_001.
 */
int targeted_function (int input_000, int input_001, int* output_000, int* output_001)
{
	*output_000 = input_000 + input_001;
	*output_001 = input_000 - input_001 < 0 ? input_001 - input_000 : input_000 - input_001;
	return 0;
}
