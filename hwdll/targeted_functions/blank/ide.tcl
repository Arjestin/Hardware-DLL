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
#	File Name:				./targeted_functions/blank/ide.tcl																					#
#	Last Update:			01/12/2015																													#
#																																									#
###################################################################################
#	+	Input of ./targeted_functions/blank/ide.tcl:																								#
#	-	./targeted_functions/template.dcp																											#
###################################################################################
#	+	Output of ./targeted_functions/blank/ide.tcl:																								#
#	-	./targeted_functions/blank/impl.dcp																										#
#	-	./targeted_functions/blank/bitstreams/blank.bit																						#
#	-	./targeted_functions/blank/bitstreams/blank_reconfigurable_partition_<00-15>_partial.bit							#
#	-	./sdcard/hwdll/library/blank/blank.bin																										#
#	-	./sdcard/hwdll/library/blank/rm_<00-15>.bin																							#
###################################################################################



###################################################################################
#	Script Settings:																																			#
###################################################################################
set name "blank"

###################################################################################
#	Buffer the reconfigurable modules' ports and implement the reconfigurable modules;									#
#	write the implemented checkpoint, the configuration's full bitstream,																#
#	and the reconfigurable modules' partial bitstreams:																						#
###################################################################################
open_checkpoint ./targeted_functions/template.dcp
set idx_list {00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15}
foreach idx $idx_list {
	update_design -buffer_ports -cell top_i/reconfigurable_logic/reconfigurable_module_$idx
}
place_design
route_design
write_checkpoint -force ./targeted_functions/$name/impl.dcp
file delete -force ./targeted_functions/$name/bitstreams
file mkdir ./targeted_functions/$name/bitstreams
write_bitstream ./targeted_functions/$name/bitstreams/$name.bit
close_design

###################################################################################
#	Write the configuration's full binary:																											#
###################################################################################
file delete -force ./sdcard/hwdll/library
file mkdir ./sdcard/hwdll/library/$name
write_cfgmem -format BIN -size 16 -interface SMAPx32 -disablebitswap -loadbit "up 0x0 ./targeted_functions/$name/bitstreams/$name.bit" ./sdcard/hwdll/library/$name/$name.bin
file delete ./sdcard/hwdll/library/$name/$name.prm

###################################################################################
#	Write the reconfigurable modules' partial binaries:																						#
###################################################################################
foreach idx $idx_list {
	write_cfgmem -format BIN -size 16 -interface SMAPx32 -disablebitswap -loadbit "up 0x0 ./targeted_functions/$name/bitstreams/${name}_reconfigurable_partition_${idx}_partial.bit" ./sdcard/hwdll/library/$name/rm_$idx.bin
	file delete ./sdcard/hwdll/library/$name/rm_$idx.prm
}
