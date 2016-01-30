###################################################################################
#																																									#
#								Bi-Semestrial Student Project (2014 – 2015)																		#
#								Parallel Systems Laboratory																							#
#								Electrical Engineering Department																					#
#								Technion – Israel Institute of Technology																			#
#																																									#
#	Title:						Hardware DLL																												#
#	Subject:					Real Time Partial Reconfiguration Management of FPGA by OS											#
#																																									#
#	Author:					Alon Reznik																													#
#	Supervisor:			Oz Shmueli																													#
#																																									#
#	File Name:				./sources/constraints/timing.xdc																						#
#	Last Update:			01/12/2015																													#
#																																									#
###################################################################################



###################################################################################
#	Timing Constraints:																																	#
###################################################################################
create_clock -period 3.333 -name RX_lclk_p -waveform {0.000 1.666} [get_ports RX_lclk_p]
set_false_path -from [get_clocks clk_fpga_0] -to [get_clocks cclk_p_src]
set_false_path -from [get_clocks clk_fpga_0] -to [get_clocks lclk_p_src]
set_false_path -from [get_clocks clk_fpga_0] -to [get_clocks eio_rx_0_rxlclk_p]
set_false_path -from [get_clocks eio_rx_0_rxlclk_p] -to [get_clocks clk_fpga_0]
