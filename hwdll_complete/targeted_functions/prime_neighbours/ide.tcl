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
#	File Name:				./targeted_functions/prime_neighbours/ide.tcl																	#
#	Last Update:			01/12/2015																													#
#																																									#
###################################################################################
#	+	Input of ./targeted_functions/prime_neighbours/ide.tcl:																				#
#	-	./targeted_functions/prime_neighbours/verilogs/*.v																					#
#	-	./targeted_functions/template.dcp																											#
#	-	./targeted_functions/blank/impl.dcp																										#
###################################################################################
#	+	Output of ./targeted_functions/prime_neighbours/ide.tcl:																			#
#	-	./targeted_functions/prime_neighbours/synth.dcp																						#
#	-	./targeted_functions/prime_neighbours/impl.dcp																						#
#	-	./targeted_functions/prime_neighbours/bitstreams/blank_reconfigurable_partition_<00-15>_partial.bit			#
#	-	./sdcard/hwdll/library/prime_neighbours/rm_<00-15>.bin																			#
###################################################################################



###################################################################################
#	Script Settings:																																			#
###################################################################################
set name "prime_neighbours"

###################################################################################
#	Open the HLS project and generate the IP core:																							#
###################################################################################
puts [exec vivado_hls -f ./targeted_functions/$name/hls.tcl]

###################################################################################
#	Synthesize the IP core and write the synthesized checkpoint:																			#
###################################################################################
set verilogs [glob -dir ./targeted_functions/$name/verilogs *.v]
read_verilog $verilogs
synth_design -mode out_of_context -flatten_hierarchy rebuilt -top targeted_function -part xc7z020clg400-1
write_checkpoint -force ./targeted_functions/$name/synth.dcp
close_design
close_project

###################################################################################
#	Implement the synthesized IP core as reconfigurable modules and write the implemented checkpoint:				#
###################################################################################
open_checkpoint ./targeted_functions/template.dcp
set idx_list {00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15}
foreach idx $idx_list {
	read_checkpoint -cell top_i/reconfigurable_logic/reconfigurable_module_$idx ./targeted_functions/$name/synth.dcp
}
opt_design
place_design
route_design
write_checkpoint -force ./targeted_functions/$name/impl.dcp
close_design

###################################################################################
#	Verify the reconfigurable modules' compatibility and write their partial bitstreams:											#
###################################################################################
pr_verify ./targeted_functions/blank/impl.dcp ./targeted_functions/$name/impl.dcp
open_checkpoint ./targeted_functions/$name/impl.dcp
file delete -force ./targeted_functions/$name/bitstreams
file mkdir ./targeted_functions/$name/bitstreams
write_bitstream ./targeted_functions/$name/bitstreams/$name.bit
file delete ./targeted_functions/$name/bitstreams/$name.bit
close_design

###################################################################################
#	Write the reconfigurable modules' partial binaries:																						#
###################################################################################
file delete -force ./sdcard/hwdll/library/$name
file mkdir ./sdcard/hwdll/library/$name
foreach idx $idx_list {
	write_cfgmem -format BIN -size 16 -interface SMAPx32 -disablebitswap -loadbit "up 0x0 ./targeted_functions/$name/bitstreams/${name}_reconfigurable_partition_${idx}_partial.bit" ./sdcard/hwdll/library/$name/rm_$idx.bin
	file delete ./sdcard/hwdll/library/$name/rm_$idx.prm
}
