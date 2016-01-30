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
 * File Name:							./targeted_functions/prime/targeted_function.c											*
 * Last Update:						01/12/2015																							*
 *																																						*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */



/**
 * output_000:						The prime term number input_000.
 */
int targeted_function (int input_000, int* output_000)
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
