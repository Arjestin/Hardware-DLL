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
#	File Name:				./targeted_functions/build.tcl																							#
#	Last Update:			01/12/2015																													#
#																																									#
###################################################################################
#	+	Input of ./targeted_functions/build.tcl:																										#
#		+	Input of ./targeted_functions/prep.tcl:																									#
#		-	./sources/parallella_7020_headless.xpr.zip																							#
#		+	Input of ./targeted_functions/dummy/hls.tcl:																							#
#		-	./targeted_functions/dummy/targeted_function.c																					#
#		-	./targeted_functions/logo.png																												#
#	-	./sources/constraints																																#
###################################################################################
#	+	Output of ./targeted_functions/build.tcl:																									#
#		+	Output of ./targeted_functions/prep.tcl:																								#
#		-	./parallella_7020_headless_gpiose_elink2																								#
#	-	./sources/block_designs																															#
#	-	./sources/ip_cores																																	#
#	-	./sources/interfaces																																#
#		+	Output of ./targeted_functions/dummy/hls.tcl:																						#
#		-	./hls																																					#
#		-	./hls/dummy																																		#
#		-	./targeted_functions/dummy/verilogs																									#
#		-	./sources/ip_cores/targeted_function																									#
#	-	./ide																																						#
#	-	./targeted_functions/dummy/impl.dcp																										#
#	-	./targeted_functions/template.dcp																											#
#		+	Output of ./targeted_functions/blank/ide.tcl:																							#
#		-	./targeted_functions/blank/impl.dcp																									#
#		-	./targeted_functions/blank/bitstreams/blank.bit																					#
#		-	./targeted_functions/blank/bitstreams/blank_reconfigurable_partition_<00-15>_partial.bit						#
#		-	./sdcard/hwdll/library/blank/blank.bin																									#
#		-	./sdcard/hwdll/library/blank/rm_<00-15>.bin																						#
#		+	Output of ./targeted_functions/dummy/ide.tcl:																						#
#		-	./targeted_functions/dummy/bitstreams/dummy_reconfigurable_partition_<00-15>_partial.bit					#
#		-	./sdcard/hwdll/library/dummy/rm_<00-15>.bin																					#
###################################################################################



###################################################################################
#	Extract the parallella_7020_headless_gpiose_elink2 project and replace its missing IP core update files:			#
#	These files are replaced by incorrect versions, but it doesn't matter because they won't be used anyway.			#
###################################################################################
puts [exec vivado_hls -f ./targeted_functions/prep.tcl]

###################################################################################
#	Open the parallella_7020_headless_gpiose_elink2 project and upgrade its outdated IP cores:							#
###################################################################################
open_project ./parallella_7020_headless_gpiose_elink2/parallella_7020_headless_gpiose_elink2.xpr
update_compile_order -fileset sources_1
upgrade_ip [get_ips {*processing_system* *proc_sys_reset* *axi_protocol_converter* *axi_bram_ctrl* *blk_mem_gen* *util_vector_logic* *fifo*}]

###################################################################################
#	Set the block memory generators' mode to "BRAM Controller":																	#
###################################################################################
for {set i 0} {$i < 2} {incr i} {
	set_property -dict [list CONFIG.use_bram_block {BRAM_Controller} CONFIG.Enable_32bit_Address {true} CONFIG.Write_Depth_A {8192} CONFIG.Fill_Remaining_Memory_Locations {false} CONFIG.Remaining_Memory_Locations {0} CONFIG.Use_RSTA_Pin {true}] [get_bd_cells blk_mem_gen_$i]
}
save_bd_design

###################################################################################
#	Set the eLink configuration register's (eCfg) mi interface to "BRAM Controller":												#
###################################################################################
current_bd_design elink2_top
ipx::edit_ip_in_project -upgrade true -name ip_prj -dir ./parallella_7020_headless_gpiose_elink2/parallella_7020_headless_gpiose_elink2.ipdefs/src/ecfg/ip_prj ./parallella_7020_headless_gpiose_elink2/parallella_7020_headless_gpiose_elink2.ipdefs/src/ecfg/component.xml
update_compile_order -fileset sim_1
ipx::add_bus_parameter MASTER_TYPE [ipx::get_bus_interfaces mi -of_objects [ipx::current_core]]
set_property value BRAM_CTRL [ipx::get_bus_parameters MASTER_TYPE -of_objects [ipx::get_bus_interfaces mi -of_objects [ipx::current_core]]]
ipx::update_checksums [ipx::current_core]
ipx::save_core [ipx::current_core]
close_project

###################################################################################
#	Commit the changes to the eCfg IP core:																										#
###################################################################################
update_ip_catalog -rebuild -scan_changes
upgrade_ip [get_ips *eCfg*]

###################################################################################
#	Create the top block design and copy the elink2_top block design's content into it:										#
###################################################################################
current_bd_design elink2_top
set tmpCopyObjs [concat [get_bd_cells *] [get_bd_intf_ports *] [get_bd_ports {CCLK_P CCLK_N DSP_RESET_N GPIO_P GPIO_N I2C_SDA I2C_SCL}] [get_bd_intf_nets *] [get_bd_nets *]]
file delete -force ./sources/block_designs
file mkdir ./sources/block_designs
create_bd_design -dir ./sources/block_designs "top"
update_compile_order -fileset sources_1
copy_bd_objs -from_design elink2_top / $tmpCopyObjs
save_bd_design

###################################################################################
#	Close the parallella_7020_headless_gpiose_elink2 project:																				#
###################################################################################
for {set i 0} {$i < 3} {incr i} {
	close_bd_design [current_bd_design]
}
close_project

###################################################################################
#	Export the necessary IP cores and interfaces from the parallella_7020_headless_gpiose_elink2 project:				#
###################################################################################
set path "./parallella_7020_headless_gpiose_elink2/parallella_7020_headless_gpiose_elink2.ipdefs/src"
set src_list {"earb" "ecfg" "ecfg_split" "eclock" "edistrib" "eio_rx" "eio_tx" "emaxi" "emesh_split" "eproto_rx" "eproto_tx" "esaxi" "gpio" "i2c"}
set dst_list {"earb" "eCfg" "ecfg_split" "eclock" "edistrib" "eio_rx" "eio_tx" "emaxi" "emesh_split" "eproto_rx" "eproto_tx" "esaxi" "parallella_gpio_emio" "parallella_i2c"}
set dir_list {"hdl" "xgui"}
set ext_list {"v" "tcl"}
file delete -force ./sources/ip_cores
foreach src $src_list dst $dst_list {
	foreach dir $dir_list ext $ext_list {
		file mkdir ./sources/ip_cores/$dst/$dir
		foreach file [glob -dir $path/$src/$dir *.$ext] {
			file copy $file ./sources/ip_cores/$dst/$dir
		}
	}
	file copy $path/$src/component.xml ./sources/ip_cores/$dst/component.xml
}
file mkdir ./sources/ip_cores/esaxi/drivers/esaxi_v1_0/data
file copy $path/esaxi/drivers/esaxi_v1_0/data/esaxi.mdd ./sources/ip_cores/esaxi/drivers/esaxi_v1_0/data/esaxi.mdd
file copy $path/esaxi/drivers/esaxi_v1_0/data/esaxi.tcl ./sources/ip_cores/esaxi/drivers/esaxi_v1_0/data/esaxi.tcl
file mkdir ./sources/ip_cores/esaxi/drivers/esaxi_v1_0/src
file copy $path/esaxi/drivers/esaxi_v1_0/src/esaxi.h ./sources/ip_cores/esaxi/drivers/esaxi_v1_0/src/esaxi.h
file copy $path/esaxi/drivers/esaxi_v1_0/src/esaxi.c ./sources/ip_cores/esaxi/drivers/esaxi_v1_0/src/esaxi.c
file copy $path/esaxi/drivers/esaxi_v1_0/src/esaxi_selftest.c ./sources/ip_cores/esaxi/drivers/esaxi_v1_0/src/esaxi_selftest.c
file copy $path/esaxi/drivers/esaxi_v1_0/src/Makefile ./sources/ip_cores/esaxi/drivers/esaxi_v1_0/src/Makefile
file delete -force ./sources/interfaces
file mkdir ./sources/interfaces
foreach file [glob -dir $path/interfaces *.xml] {
	file copy $file ./sources/interfaces
}

###################################################################################
#	Create the HLS project and generate the dummy IP core:																				#
###################################################################################
puts [exec vivado_hls -f ./targeted_functions/dummy/hls.tcl]

###################################################################################
#	Create the IDE project and import its sources:																								#
###################################################################################
file delete -force ./ide
create_project ide ./ide -part xc7z020clg400-1
set_property simulator_language Verilog [current_project]
set_property ip_repo_paths {./sources/ip_cores ./sources/interfaces} [current_project]
update_ip_catalog
import_files -fileset constrs_1 ./sources/constraints
import_files ./sources/block_designs/top/top.bd
open_bd_design ./ide/ide.srcs/sources_1/bd/top/top.bd

###################################################################################
#	Add IP cores:																																				#
###################################################################################
set idx_list {00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15}
create_bd_cell -type ip -vlnv xilinx.com:ip:axi_interconnect:2.1 axi_interconnect_0
foreach idx $idx_list {
	create_bd_cell -type ip -vlnv hwdll:hls:targeted_function:1.0 reconfigurable_module_$idx
}
create_bd_cell -type ip -vlnv xilinx.com:ip:axi_bram_ctrl:4.0 axi_bram_ctrl_0
create_bd_cell -type ip -vlnv xilinx.com:ip:blk_mem_gen:8.3 blk_mem_gen_0

###################################################################################
#	Set IP core properties:																																#
###################################################################################
set_property -dict [list CONFIG.NUM_MI {18}] [get_bd_cells axi_interconnect_0]
set_property -dict [list CONFIG.PROTOCOL {AXI4LITE} CONFIG.ECC_TYPE {0}] [get_bd_cells axi_bram_ctrl_0]
set_property -dict [list CONFIG.Memory_Type {True_Dual_Port_RAM} CONFIG.Enable_B {Use_ENB_Pin} CONFIG.Use_RSTB_Pin {true} CONFIG.Port_B_Clock {100} CONFIG.Port_B_Write_Rate {50} CONFIG.Port_B_Enable_Rate {100}] [get_bd_cells blk_mem_gen_0]

###################################################################################
#	Disconnect netlist terminals:																														#
###################################################################################
delete_bd_objs [get_bd_intf_nets processing_system7_0_M_AXI_GP0]

###################################################################################
#	Connect netlist terminals:																															#
###################################################################################
set term_list {00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17}
connect_bd_net [get_bd_pins axi_interconnect_0/ACLK] [get_bd_pins proc_sys_reset_0/slowest_sync_clk]
connect_bd_net [get_bd_pins axi_interconnect_0/S00_ACLK] [get_bd_pins proc_sys_reset_0/slowest_sync_clk]
connect_bd_net [get_bd_pins axi_interconnect_0/S00_ARESETN] [get_bd_pins proc_sys_reset_0/peripheral_aresetn]
connect_bd_net [get_bd_pins axi_interconnect_0/ARESETN] [get_bd_pins proc_sys_reset_0/interconnect_aresetn]
foreach term $term_list {
	connect_bd_net [get_bd_pins axi_interconnect_0/M${term}_ACLK] [get_bd_pins proc_sys_reset_0/slowest_sync_clk]
	connect_bd_net [get_bd_pins axi_interconnect_0/M${term}_ARESETN] [get_bd_pins proc_sys_reset_0/peripheral_aresetn]
}
connect_bd_intf_net -boundary_type upper [get_bd_intf_pins axi_interconnect_0/S00_AXI] [get_bd_intf_pins processing_system7_0/M_AXI_GP0]
foreach idx $idx_list {
	connect_bd_net [get_bd_pins reconfigurable_module_$idx/ap_clk] [get_bd_pins proc_sys_reset_0/slowest_sync_clk]
	connect_bd_net [get_bd_pins reconfigurable_module_$idx/ap_rst_n] [get_bd_pins proc_sys_reset_0/peripheral_aresetn]
	connect_bd_intf_net [get_bd_intf_pins reconfigurable_module_$idx/s_axi_rm] -boundary_type upper [get_bd_intf_pins axi_interconnect_0/M${idx}_AXI]
}
connect_bd_net [get_bd_pins axi_bram_ctrl_0/s_axi_aclk] [get_bd_pins proc_sys_reset_0/slowest_sync_clk]
connect_bd_net [get_bd_pins axi_bram_ctrl_0/s_axi_aresetn] [get_bd_pins proc_sys_reset_0/peripheral_aresetn]
connect_bd_intf_net [get_bd_intf_pins axi_bram_ctrl_0/S_AXI] -boundary_type upper [get_bd_intf_pins axi_interconnect_0/M16_AXI]
connect_bd_intf_net [get_bd_intf_pins axi_bram_ctrl_0/BRAM_PORTA] [get_bd_intf_pins blk_mem_gen_0/BRAM_PORTA]
connect_bd_intf_net [get_bd_intf_pins axi_bram_ctrl_0/BRAM_PORTB] [get_bd_intf_pins blk_mem_gen_0/BRAM_PORTB]
connect_bd_intf_net [get_bd_intf_pins axi_protocol_converter_1/S_AXI] -boundary_type upper [get_bd_intf_pins axi_interconnect_0/M17_AXI]

###################################################################################
#	Group IP cores:																																			#
###################################################################################
group_bd_cells static_logic [get_bd_cells {processing_system7_0 proc_sys_reset_0 axi_interconnect_0 axi_protocol_converter_* elink2 parallella_gpio_emio_0 parallella_i2c_0 axi_bram_ctrl_0 blk_mem_gen_0}]
group_bd_cells reconfigurable_logic [get_bd_cells reconfigurable_module_*]

###################################################################################
#	Assign addresses:																																		#
###################################################################################
create_bd_addr_seg -range 0x40000000 -offset 0x0 [get_bd_addr_spaces static_logic/elink2/emaxi_0/M00_AXI] [get_bd_addr_segs static_logic/processing_system7_0/S_AXI_HP1/HP1_DDR_LOWOCM] SEG_processing_system7_0_HP1_DDR_LOWOCM
set offset 0x40000000
foreach idx $idx_list {
	create_bd_addr_seg -range 0x1000 -offset $offset [get_bd_addr_spaces static_logic/processing_system7_0/Data] [get_bd_addr_segs reconfigurable_logic/reconfigurable_module_$idx/s_axi_rm/Reg] SEG_reconfigurable_module_${idx}_Reg
	incr offset 0x1000
}
create_bd_addr_seg -range 0x2000 -offset 0x70000000 [get_bd_addr_spaces static_logic/processing_system7_0/Data] [get_bd_addr_segs static_logic/elink2/axi_bram_ctrl_2/S_AXI/Mem0] SEG_axi_bram_ctrl_2_Mem0
create_bd_addr_seg -range 0x2000 -offset 0x70002000 [get_bd_addr_spaces static_logic/processing_system7_0/Data] [get_bd_addr_segs static_logic/axi_bram_ctrl_0/S_AXI/Mem0] SEG_axi_bram_ctrl_0_Mem0
create_bd_addr_seg -range 0x40000000 -offset 0x80000000 [get_bd_addr_spaces static_logic/processing_system7_0/Data] [get_bd_addr_segs static_logic/elink2/esaxi_0/S00_AXI/S00_AXI_mem] SEG_esaxi_0_S00_AXI_mem

###################################################################################
#	Finalize, synthesize, and implement the design; and write the implemented dummy configuration checkpoint:	#
###################################################################################
regenerate_bd_layout
validate_bd_design
make_wrapper -top [get_files ./ide/ide.srcs/sources_1/bd/top/top.bd]
add_files ./ide/ide.srcs/sources_1/bd/top/hdl/top_wrapper.v
update_compile_order -fileset sources_1
update_compile_order -fileset sim_1
save_bd_design
close_bd_design [current_bd_design]
launch_runs synth_1
wait_on_run synth_1
launch_runs impl_1
wait_on_run impl_1
open_run impl_1
write_checkpoint -force ./targeted_functions/dummy/impl.dcp

###################################################################################
#	Blank the reconfigurable partitions, lock the design, and write the Hardware DLL template checkpoint:				#
###################################################################################
foreach idx $idx_list {
	update_design -black_box -cell top_i/reconfigurable_logic/reconfigurable_module_$idx
}
lock_design -level routing
write_checkpoint -force ./targeted_functions/template.dcp
close_design
close_project

###################################################################################
#	Build the blank and dummy hardware accelerators:																						#
###################################################################################
source ./targeted_functions/blank/ide.tcl
source ./targeted_functions/dummy/ide.tcl
