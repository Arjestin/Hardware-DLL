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
#	File Name:				./targeted_functions/prep.tcl																							#
#	Last Update:			01/12/2015																													#
#																																									#
###################################################################################
#	+	Input of ./targeted_functions/prep.tcl:																										#
#	-	./sources/parallella_7020_headless.xpr.zip																								#
###################################################################################
#	+	Output of ./targeted_functions/prep.tcl:																									#
#	-	./parallella_7020_headless_gpiose_elink2																									#
###################################################################################



###################################################################################
#	Extract the parallella_7020_headless_gpiose_elink2 project and replace its missing IP core update files:			#
#	These files are replaced by incorrect versions, but it doesn't matter because they won't be used anyway.			#
###################################################################################
file delete -force ./parallella_7020_headless_gpiose_elink2
puts [exec unzip ./sources/parallella_7020_headless.xpr.zip -d ./]
set path "./parallella_7020_headless_gpiose_elink2/parallella_7020_headless_gpiose_elink2.srcs/sources_1/bd/elink_testbench/ip"
set src_list {"elink_testbench_eCfg_0_0" "elink_testbench_eio_tx_0_2" "elink_testbench_elink_gold_0_0"}
set dst_list {"elink_testbench_eCfg_0_2" "elink_testbench_eio_tx_0_0" "elink_testbench_elink_gold_0_1"}
set ext_list {"upgrade_log" "xci" "xml"}
foreach src $src_list dst $dst_list {
	foreach ext $ext_list {
		file copy $path/$src/$src.$ext $path/$dst/$dst.$ext
	}
}
exit
