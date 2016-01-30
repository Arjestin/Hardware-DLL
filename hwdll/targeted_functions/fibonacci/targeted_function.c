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
 * File Name:							./targeted_functions/fibonacci/targeted_function.c										*
 * Last Update:						01/12/2015																							*
 *																																						*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */



/**
 * output_000:						The Fibonacci term number input_000.
 */
int targeted_function (int input_000, int* output_000)
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
