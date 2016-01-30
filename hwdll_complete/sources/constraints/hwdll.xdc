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
#	File Name:				./sources/constraints/hwdll.xdc																						#
#	Last Update:			01/12/2015																													#
#																																									#
###################################################################################
#	NOTE: The following commands are not supported in constraint files: for, foreach, unset.								#
###################################################################################



###################################################################################
#	Hardware DLL Constraints:																															#
###################################################################################
create_pblock reconfigurable_partition_00
create_pblock reconfigurable_partition_01
create_pblock reconfigurable_partition_02
create_pblock reconfigurable_partition_03
create_pblock reconfigurable_partition_04
create_pblock reconfigurable_partition_05
create_pblock reconfigurable_partition_06
create_pblock reconfigurable_partition_07
create_pblock reconfigurable_partition_08
create_pblock reconfigurable_partition_09
create_pblock reconfigurable_partition_10
create_pblock reconfigurable_partition_11
create_pblock reconfigurable_partition_12
create_pblock reconfigurable_partition_13
create_pblock reconfigurable_partition_14
create_pblock reconfigurable_partition_15
resize_pblock [get_pblocks reconfigurable_partition_00] -add {SLICE_X50Y100:SLICE_X67Y149 RAMB18_X3Y40:RAMB18_X3Y59 RAMB36_X3Y20:RAMB36_X3Y29}
resize_pblock [get_pblocks reconfigurable_partition_01] -add {SLICE_X80Y100:SLICE_X89Y149 RAMB18_X4Y40:RAMB18_X4Y59 RAMB36_X4Y20:RAMB36_X4Y29}
resize_pblock [get_pblocks reconfigurable_partition_02] -add {SLICE_X90Y100:SLICE_X101Y149 DSP48_X3Y40:DSP48_X3Y59}
resize_pblock [get_pblocks reconfigurable_partition_03] -add {SLICE_X102Y100:SLICE_X113Y149 DSP48_X4Y40:DSP48_X4Y59 RAMB18_X5Y40:RAMB18_X5Y59 RAMB36_X5Y20:RAMB36_X5Y29}
resize_pblock [get_pblocks reconfigurable_partition_04] -add {SLICE_X50Y50:SLICE_X67Y99 RAMB18_X3Y20:RAMB18_X3Y39 RAMB36_X3Y10:RAMB36_X3Y19}
resize_pblock [get_pblocks reconfigurable_partition_05] -add {SLICE_X80Y50:SLICE_X89Y99 RAMB18_X4Y20:RAMB18_X4Y39 RAMB36_X4Y10:RAMB36_X4Y19}
resize_pblock [get_pblocks reconfigurable_partition_06] -add {SLICE_X90Y50:SLICE_X101Y99 DSP48_X3Y20:DSP48_X3Y39}
resize_pblock [get_pblocks reconfigurable_partition_07] -add {SLICE_X102Y50:SLICE_X113Y99 DSP48_X4Y20:DSP48_X4Y39 RAMB18_X5Y20:RAMB18_X5Y39 RAMB36_X5Y10:RAMB36_X5Y19}
resize_pblock [get_pblocks reconfigurable_partition_08] -add {SLICE_X0Y0:SLICE_X11Y49 DSP48_X0Y0:DSP48_X0Y19 RAMB18_X0Y0:RAMB18_X0Y19 RAMB36_X0Y0:RAMB36_X0Y9}
resize_pblock [get_pblocks reconfigurable_partition_09] -add {SLICE_X12Y0:SLICE_X19Y49 DSP48_X1Y0:DSP48_X1Y19}
resize_pblock [get_pblocks reconfigurable_partition_10] -add {SLICE_X20Y0:SLICE_X31Y49 RAMB18_X1Y0:RAMB18_X1Y19 RAMB36_X1Y0:RAMB36_X1Y9}
resize_pblock [get_pblocks reconfigurable_partition_11] -add {SLICE_X32Y0:SLICE_X49Y49 DSP48_X2Y0:DSP48_X2Y19 RAMB18_X2Y0:RAMB18_X2Y19 RAMB36_X2Y0:RAMB36_X2Y9}
resize_pblock [get_pblocks reconfigurable_partition_12] -add {SLICE_X50Y0:SLICE_X67Y49 RAMB18_X3Y0:RAMB18_X3Y19 RAMB36_X3Y0:RAMB36_X3Y9}
resize_pblock [get_pblocks reconfigurable_partition_13] -add {SLICE_X68Y0:SLICE_X89Y49 RAMB18_X4Y0:RAMB18_X4Y19 RAMB36_X4Y0:RAMB36_X4Y9}
resize_pblock [get_pblocks reconfigurable_partition_14] -add {SLICE_X90Y0:SLICE_X101Y49 DSP48_X3Y0:DSP48_X3Y19}
resize_pblock [get_pblocks reconfigurable_partition_15] -add {SLICE_X102Y0:SLICE_X113Y49 DSP48_X4Y0:DSP48_X4Y19 RAMB18_X5Y0:RAMB18_X5Y19 RAMB36_X5Y0:RAMB36_X5Y9}
add_cells_to_pblock [get_pblocks reconfigurable_partition_00] [get_cells [list top_i/reconfigurable_logic/reconfigurable_module_00]]
add_cells_to_pblock [get_pblocks reconfigurable_partition_01] [get_cells [list top_i/reconfigurable_logic/reconfigurable_module_01]]
add_cells_to_pblock [get_pblocks reconfigurable_partition_02] [get_cells [list top_i/reconfigurable_logic/reconfigurable_module_02]]
add_cells_to_pblock [get_pblocks reconfigurable_partition_03] [get_cells [list top_i/reconfigurable_logic/reconfigurable_module_03]]
add_cells_to_pblock [get_pblocks reconfigurable_partition_04] [get_cells [list top_i/reconfigurable_logic/reconfigurable_module_04]]
add_cells_to_pblock [get_pblocks reconfigurable_partition_05] [get_cells [list top_i/reconfigurable_logic/reconfigurable_module_05]]
add_cells_to_pblock [get_pblocks reconfigurable_partition_06] [get_cells [list top_i/reconfigurable_logic/reconfigurable_module_06]]
add_cells_to_pblock [get_pblocks reconfigurable_partition_07] [get_cells [list top_i/reconfigurable_logic/reconfigurable_module_07]]
add_cells_to_pblock [get_pblocks reconfigurable_partition_08] [get_cells [list top_i/reconfigurable_logic/reconfigurable_module_08]]
add_cells_to_pblock [get_pblocks reconfigurable_partition_09] [get_cells [list top_i/reconfigurable_logic/reconfigurable_module_09]]
add_cells_to_pblock [get_pblocks reconfigurable_partition_10] [get_cells [list top_i/reconfigurable_logic/reconfigurable_module_10]]
add_cells_to_pblock [get_pblocks reconfigurable_partition_11] [get_cells [list top_i/reconfigurable_logic/reconfigurable_module_11]]
add_cells_to_pblock [get_pblocks reconfigurable_partition_12] [get_cells [list top_i/reconfigurable_logic/reconfigurable_module_12]]
add_cells_to_pblock [get_pblocks reconfigurable_partition_13] [get_cells [list top_i/reconfigurable_logic/reconfigurable_module_13]]
add_cells_to_pblock [get_pblocks reconfigurable_partition_14] [get_cells [list top_i/reconfigurable_logic/reconfigurable_module_14]]
add_cells_to_pblock [get_pblocks reconfigurable_partition_15] [get_cells [list top_i/reconfigurable_logic/reconfigurable_module_15]]
set_property RESET_AFTER_RECONFIG true [get_pblocks reconfigurable_partition_00]
set_property RESET_AFTER_RECONFIG true [get_pblocks reconfigurable_partition_01]
set_property RESET_AFTER_RECONFIG true [get_pblocks reconfigurable_partition_02]
set_property RESET_AFTER_RECONFIG true [get_pblocks reconfigurable_partition_03]
set_property RESET_AFTER_RECONFIG true [get_pblocks reconfigurable_partition_04]
set_property RESET_AFTER_RECONFIG true [get_pblocks reconfigurable_partition_05]
set_property RESET_AFTER_RECONFIG true [get_pblocks reconfigurable_partition_06]
set_property RESET_AFTER_RECONFIG true [get_pblocks reconfigurable_partition_07]
set_property RESET_AFTER_RECONFIG true [get_pblocks reconfigurable_partition_08]
set_property RESET_AFTER_RECONFIG true [get_pblocks reconfigurable_partition_09]
set_property RESET_AFTER_RECONFIG true [get_pblocks reconfigurable_partition_10]
set_property RESET_AFTER_RECONFIG true [get_pblocks reconfigurable_partition_11]
set_property RESET_AFTER_RECONFIG true [get_pblocks reconfigurable_partition_12]
set_property RESET_AFTER_RECONFIG true [get_pblocks reconfigurable_partition_13]
set_property RESET_AFTER_RECONFIG true [get_pblocks reconfigurable_partition_14]
set_property RESET_AFTER_RECONFIG true [get_pblocks reconfigurable_partition_15]
set_property SNAPPING_MODE ON [get_pblocks reconfigurable_partition_00]
set_property SNAPPING_MODE ON [get_pblocks reconfigurable_partition_01]
set_property SNAPPING_MODE ON [get_pblocks reconfigurable_partition_02]
set_property SNAPPING_MODE ON [get_pblocks reconfigurable_partition_03]
set_property SNAPPING_MODE ON [get_pblocks reconfigurable_partition_04]
set_property SNAPPING_MODE ON [get_pblocks reconfigurable_partition_05]
set_property SNAPPING_MODE ON [get_pblocks reconfigurable_partition_06]
set_property SNAPPING_MODE ON [get_pblocks reconfigurable_partition_07]
set_property SNAPPING_MODE ON [get_pblocks reconfigurable_partition_08]
set_property SNAPPING_MODE ON [get_pblocks reconfigurable_partition_09]
set_property SNAPPING_MODE ON [get_pblocks reconfigurable_partition_10]
set_property SNAPPING_MODE ON [get_pblocks reconfigurable_partition_11]
set_property SNAPPING_MODE ON [get_pblocks reconfigurable_partition_12]
set_property SNAPPING_MODE ON [get_pblocks reconfigurable_partition_13]
set_property SNAPPING_MODE ON [get_pblocks reconfigurable_partition_14]
set_property SNAPPING_MODE ON [get_pblocks reconfigurable_partition_15]
set_property HD.RECONFIGURABLE true [get_cells top_i/reconfigurable_logic/reconfigurable_module_00]
set_property HD.RECONFIGURABLE true [get_cells top_i/reconfigurable_logic/reconfigurable_module_01]
set_property HD.RECONFIGURABLE true [get_cells top_i/reconfigurable_logic/reconfigurable_module_02]
set_property HD.RECONFIGURABLE true [get_cells top_i/reconfigurable_logic/reconfigurable_module_03]
set_property HD.RECONFIGURABLE true [get_cells top_i/reconfigurable_logic/reconfigurable_module_04]
set_property HD.RECONFIGURABLE true [get_cells top_i/reconfigurable_logic/reconfigurable_module_05]
set_property HD.RECONFIGURABLE true [get_cells top_i/reconfigurable_logic/reconfigurable_module_06]
set_property HD.RECONFIGURABLE true [get_cells top_i/reconfigurable_logic/reconfigurable_module_07]
set_property HD.RECONFIGURABLE true [get_cells top_i/reconfigurable_logic/reconfigurable_module_08]
set_property HD.RECONFIGURABLE true [get_cells top_i/reconfigurable_logic/reconfigurable_module_09]
set_property HD.RECONFIGURABLE true [get_cells top_i/reconfigurable_logic/reconfigurable_module_10]
set_property HD.RECONFIGURABLE true [get_cells top_i/reconfigurable_logic/reconfigurable_module_11]
set_property HD.RECONFIGURABLE true [get_cells top_i/reconfigurable_logic/reconfigurable_module_12]
set_property HD.RECONFIGURABLE true [get_cells top_i/reconfigurable_logic/reconfigurable_module_13]
set_property HD.RECONFIGURABLE true [get_cells top_i/reconfigurable_logic/reconfigurable_module_14]
set_property HD.RECONFIGURABLE true [get_cells top_i/reconfigurable_logic/reconfigurable_module_15]
