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
 * File Name:							./targeted_functions/prime_neighbours/targeted_function.c						*
 * Last Update:						01/12/2015																							*
 *																																						*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <limits.h>

#ifndef INT_MAX
#define INT_MAX			0x7FFFFFFF
#endif



/**
 * output_000:						The first prime number less than input_000.
 * output_001:						The first prime number greater than input_000.
 */
int targeted_function (int input_000, int* output_000, int* output_001)
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
