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
#	File Name:				./sources/constraints/z7020_loc.xdc																					#
#	Last Update:			01/12/2015																													#
#																																									#
###################################################################################
#	Location constraints for Parallella-I board - 03/12/14 F. Huettig																		#
#	Updated to XDC format - 07/01/14 F. Huettig																								#
###################################################################################
#	This file defines pin locations and standards for Parallella-I, which are unique to Zynq 7020.							#
#	See the z70x0_loc.xdc file for the pins, which are common to Zynq 7010 and Zynq 7020.									#
###################################################################################
#	NOTE: The constraint files do not contain any IOSTANDARDS for e-link and gpio.											#
#	These IOSTANDARDS are located in their respective verilog files.																	#
###################################################################################



###################################################################################
#	Unique Zynq 7020 Pins:																																#
###################################################################################
set_property PACKAGE_PIN Y12 [get_ports {GPIO_P[12]}]
set_property PACKAGE_PIN Y13 [get_ports {GPIO_N[12]}]
set_property PACKAGE_PIN W11 [get_ports {GPIO_P[13]}]
set_property PACKAGE_PIN Y11 [get_ports {GPIO_N[13]}]
set_property PACKAGE_PIN V11 [get_ports {GPIO_P[14]}]
set_property PACKAGE_PIN V10 [get_ports {GPIO_N[14]}]
set_property PACKAGE_PIN T9 [get_ports {GPIO_P[15]}]
set_property PACKAGE_PIN U10 [get_ports {GPIO_N[15]}]
set_property PACKAGE_PIN W10 [get_ports {GPIO_P[16]}]
set_property PACKAGE_PIN W9 [get_ports {GPIO_N[16]}]
set_property PACKAGE_PIN U9 [get_ports {GPIO_P[17]}]
set_property PACKAGE_PIN U8 [get_ports {GPIO_N[17]}]
set_property PACKAGE_PIN V8 [get_ports {GPIO_P[18]}]
set_property PACKAGE_PIN W8 [get_ports {GPIO_N[18]}]
set_property PACKAGE_PIN Y9 [get_ports {GPIO_P[19]}]
set_property PACKAGE_PIN Y8 [get_ports {GPIO_N[19]}]
set_property PACKAGE_PIN Y7 [get_ports {GPIO_P[20]}]
set_property PACKAGE_PIN Y6 [get_ports {GPIO_N[20]}]
set_property PACKAGE_PIN U7 [get_ports {GPIO_P[21]}]
set_property PACKAGE_PIN V7 [get_ports {GPIO_N[21]}]
set_property PACKAGE_PIN V6 [get_ports {GPIO_P[22]}]
set_property PACKAGE_PIN W6 [get_ports {GPIO_N[22]}]
set_property PACKAGE_PIN T5 [get_ports {GPIO_P[23]}]
set_property PACKAGE_PIN U5 [get_ports {GPIO_N[23]}]
