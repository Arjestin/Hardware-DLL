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
#	File Name:				./targeted_functions/dummy/hls.tcl																					#
#	Last Update:			01/12/2015																													#
#																																									#
###################################################################################
#	+	Input of ./targeted_functions/dummy/hls.tcl:																								#
#	-	./targeted_functions/dummy/targeted_function.c																						#
#	-	./targeted_functions/logo.png																													#
###################################################################################
#	+	Output of ./targeted_functions/dummy/hls.tcl:																							#
#	-	./hls																																						#
#	-	./hls/dummy																																			#
#	-	./targeted_functions/dummy/verilogs																										#
#	-	./sources/ip_cores/targeted_function																										#
###################################################################################



###################################################################################
#	Script Settings:																																			#
###################################################################################
set name "dummy"
set description "Dummy"
set io_types {"input" "output"}
set io_sizes {0 256}

###################################################################################
#	Create the HLS project and generate the IP core:																							#
###################################################################################
file delete -force ./hls
open_project hls
set_top targeted_function
add_files ./targeted_functions/$name/targeted_function.c
open_solution $name
set_part {xc7z020clg400-1}
create_clock -period 10 -name default
set_directive_interface -mode s_axilite -bundle rm "targeted_function"
foreach io_type $io_types io_size $io_sizes {
	for {set i 0} {$i < $io_size} {incr i} {
		if {$i < 10} {
			set_directive_interface -mode s_axilite -bundle rm "targeted_function" ${io_type}_00$i
		}
		if {$i > 9 && $i < 100} {
			set_directive_interface -mode s_axilite -bundle rm "targeted_function" ${io_type}_0$i
		}
		if {$i > 99} {
			set_directive_interface -mode s_axilite -bundle rm "targeted_function" ${io_type}_$i
		}
	}
}
csynth_design
export_design -format ip_catalog -description "$description Reconfigurable Module" -vendor "hwdll" -display_name "reconfigurable_module" -taxonomy "/Hardware_Accelerator"
close_solution
close_project

###################################################################################
#	Copy the Verilog files from the IP core to the targeted function's directory:													#
###################################################################################
file delete -force ./targeted_functions/$name/verilogs
file mkdir ./targeted_functions/$name/verilogs
foreach file [glob -dir ./hls/$name/impl/ip/hdl/verilog *.v] {
	file copy $file ./targeted_functions/$name/verilogs
}

###################################################################################
#	Extract the IP core's archive to the sources directory and replace its logo:														#
###################################################################################
file delete -force ./sources/ip_cores/targeted_function
puts [exec unzip ./hls/$name/impl/ip/hwdll_hls_targeted_function_1_0.zip -d ./sources/ip_cores/targeted_function]
file copy -force ./targeted_functions/logo.png ./sources/ip_cores/targeted_function/misc/logo.png
exit
