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
#	File Name:				./targeted_functions/numbers/hls.tcl																				#
#	Last Update:			01/12/2015																													#
#																																									#
###################################################################################
#	+	Input of ./targeted_functions/numbers/hls.tcl:																							#
#	-	./targeted_functions/numbers/targeted_function.c																					#
###################################################################################
#	+	Output of ./targeted_functions/numbers/hls.tcl:																						#
#	-	./hls/numbers																																		#
#	-	./targeted_functions/numbers/verilogs																									#
###################################################################################



###################################################################################
#	Script Settings:																																			#
###################################################################################
set name "numbers"
set description "Numbers"
set io_types {"input" "output"}
set io_sizes {0 256}

###################################################################################
#	Open the HLS project and generate the IP core:																							#
###################################################################################
open_project -reset hls
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
#	Replace the value of the C_S_AXI_RM_ADDR_WIDTH parameter with the dummy's:											#
#	NOTE: There is probably a better way to do it. And if there isn't, there should be.											#
###################################################################################
file rename ./targeted_functions/$name/verilogs/targeted_function.v ./targeted_functions/$name/verilogs/temp_targeted_function.v
set src_fd [open ./targeted_functions/$name/verilogs/temp_targeted_function.v r]
set dst_fd [open ./targeted_functions/$name/verilogs/targeted_function.v w]
while {![eof $src_fd]} {
	gets $src_fd line
	if {[eof $src_fd]} {
		break
	}
	set split_line [split $line]
	if {[lindex $split_line 0] == "parameter" && [lindex $split_line 4] == "C_S_AXI_RM_ADDR_WIDTH"} {
		set split_line [lreplace $split_line end end "12;"]
		set line [join $split_line]
	}
	puts $dst_fd $line
}
close $dst_fd
close $src_fd
file delete ./targeted_functions/$name/verilogs/temp_targeted_function.v
exit
