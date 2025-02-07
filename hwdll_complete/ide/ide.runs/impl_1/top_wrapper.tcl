proc start_step { step } {
  set stopFile ".stop.rst"
  if {[file isfile .stop.rst]} {
    puts ""
    puts "*** Halting run - EA reset detected ***"
    puts ""
    puts ""
    return -code error
  }
  set beginFile ".$step.begin.rst"
  set platform "$::tcl_platform(platform)"
  set user "$::tcl_platform(user)"
  set pid [pid]
  set host ""
  if { [string equal $platform unix] } {
    if { [info exist ::env(HOSTNAME)] } {
      set host $::env(HOSTNAME)
    }
  } else {
    if { [info exist ::env(COMPUTERNAME)] } {
      set host $::env(COMPUTERNAME)
    }
  }
  set ch [open $beginFile w]
  puts $ch "<?xml version=\"1.0\"?>"
  puts $ch "<ProcessHandle Version=\"1\" Minor=\"0\">"
  puts $ch "    <Process Command=\".planAhead.\" Owner=\"$user\" Host=\"$host\" Pid=\"$pid\">"
  puts $ch "    </Process>"
  puts $ch "</ProcessHandle>"
  close $ch
}

proc end_step { step } {
  set endFile ".$step.end.rst"
  set ch [open $endFile w]
  close $ch
}

proc step_failed { step } {
  set endFile ".$step.error.rst"
  set ch [open $endFile w]
  close $ch
}

set_msg_config -id {HDL 9-1061} -limit 100000
set_msg_config -id {HDL 9-1654} -limit 100000

start_step init_design
set rc [catch {
  create_msg_db init_design.pb
  set_property design_mode GateLvl [current_fileset]
  set_property webtalk.parent_dir c:/xilinx/ide/ide.cache/wt [current_project]
  set_property parent.project_path c:/xilinx/ide/ide.xpr [current_project]
  set_property ip_repo_paths {
  c:/xilinx/ide/ide.cache/ip
  c:/xilinx/sources/ip_cores
  c:/xilinx/sources/interfaces
} [current_project]
  set_property ip_output_repo c:/xilinx/ide/ide.cache/ip [current_project]
  add_files -quiet c:/xilinx/ide/ide.runs/synth_1/top_wrapper.dcp
  add_files c:/xilinx/ide/ide.srcs/sources_1/bd/top/top.bmm
  set_property SCOPED_TO_REF top [get_files -all c:/xilinx/ide/ide.srcs/sources_1/bd/top/top.bmm]
  set_property SCOPED_TO_CELLS {} [get_files -all c:/xilinx/ide/ide.srcs/sources_1/bd/top/top.bmm]
  read_xdc -ref top_fifo_103x16_rdreq_0 -cells U0 c:/xilinx/ide/ide.srcs/sources_1/bd/top/ip/top_fifo_103x16_rdreq_0/top_fifo_103x16_rdreq_0/top_fifo_103x16_rdreq_0.xdc
  set_property processing_order EARLY [get_files c:/xilinx/ide/ide.srcs/sources_1/bd/top/ip/top_fifo_103x16_rdreq_0/top_fifo_103x16_rdreq_0/top_fifo_103x16_rdreq_0.xdc]
  read_xdc -ref top_fifo_103x16_rresp_0 -cells U0 c:/xilinx/ide/ide.srcs/sources_1/bd/top/ip/top_fifo_103x16_rresp_0/top_fifo_103x16_rresp_0/top_fifo_103x16_rresp_0.xdc
  set_property processing_order EARLY [get_files c:/xilinx/ide/ide.srcs/sources_1/bd/top/ip/top_fifo_103x16_rresp_0/top_fifo_103x16_rresp_0/top_fifo_103x16_rresp_0.xdc]
  read_xdc -ref top_fifo_103x16_write_0 -cells U0 c:/xilinx/ide/ide.srcs/sources_1/bd/top/ip/top_fifo_103x16_write_0/top_fifo_103x16_write_0/top_fifo_103x16_write_0.xdc
  set_property processing_order EARLY [get_files c:/xilinx/ide/ide.srcs/sources_1/bd/top/ip/top_fifo_103x16_write_0/top_fifo_103x16_write_0/top_fifo_103x16_write_0.xdc]
  read_xdc -ref top_fifo_103x32_rdreq_0 -cells U0 c:/xilinx/ide/ide.srcs/sources_1/bd/top/ip/top_fifo_103x32_rdreq_0/top_fifo_103x32_rdreq_0/top_fifo_103x32_rdreq_0.xdc
  set_property processing_order EARLY [get_files c:/xilinx/ide/ide.srcs/sources_1/bd/top/ip/top_fifo_103x32_rdreq_0/top_fifo_103x32_rdreq_0/top_fifo_103x32_rdreq_0.xdc]
  read_xdc -ref top_fifo_103x32_rresp_0 -cells U0 c:/xilinx/ide/ide.srcs/sources_1/bd/top/ip/top_fifo_103x32_rresp_0/top_fifo_103x32_rresp_0/top_fifo_103x32_rresp_0.xdc
  set_property processing_order EARLY [get_files c:/xilinx/ide/ide.srcs/sources_1/bd/top/ip/top_fifo_103x32_rresp_0/top_fifo_103x32_rresp_0/top_fifo_103x32_rresp_0.xdc]
  read_xdc -ref top_fifo_103x32_write_0 -cells U0 c:/xilinx/ide/ide.srcs/sources_1/bd/top/ip/top_fifo_103x32_write_0/top_fifo_103x32_write_0/top_fifo_103x32_write_0.xdc
  set_property processing_order EARLY [get_files c:/xilinx/ide/ide.srcs/sources_1/bd/top/ip/top_fifo_103x32_write_0/top_fifo_103x32_write_0/top_fifo_103x32_write_0.xdc]
  read_xdc -prop_thru_buffers -ref top_proc_sys_reset_0_0 c:/xilinx/ide/ide.srcs/sources_1/bd/top/ip/top_proc_sys_reset_0_0/top_proc_sys_reset_0_0_board.xdc
  set_property processing_order EARLY [get_files c:/xilinx/ide/ide.srcs/sources_1/bd/top/ip/top_proc_sys_reset_0_0/top_proc_sys_reset_0_0_board.xdc]
  read_xdc -ref top_proc_sys_reset_0_0 c:/xilinx/ide/ide.srcs/sources_1/bd/top/ip/top_proc_sys_reset_0_0/top_proc_sys_reset_0_0.xdc
  set_property processing_order EARLY [get_files c:/xilinx/ide/ide.srcs/sources_1/bd/top/ip/top_proc_sys_reset_0_0/top_proc_sys_reset_0_0.xdc]
  read_xdc -ref top_processing_system7_0_0 -cells inst c:/xilinx/ide/ide.srcs/sources_1/bd/top/ip/top_processing_system7_0_0/top_processing_system7_0_0.xdc
  set_property processing_order EARLY [get_files c:/xilinx/ide/ide.srcs/sources_1/bd/top/ip/top_processing_system7_0_0/top_processing_system7_0_0.xdc]
  read_xdc c:/xilinx/ide/ide.srcs/constrs_1/imports/constraints/z70x0_loc.xdc
  read_xdc c:/xilinx/ide/ide.srcs/constrs_1/imports/constraints/z7020_loc.xdc
  read_xdc c:/xilinx/ide/ide.srcs/constrs_1/imports/constraints/timing.xdc
  read_xdc c:/xilinx/ide/ide.srcs/constrs_1/imports/constraints/hwdll.xdc
  read_xdc -ref top_fifo_103x16_rdreq_0 -cells U0 c:/xilinx/ide/ide.srcs/sources_1/bd/top/ip/top_fifo_103x16_rdreq_0/top_fifo_103x16_rdreq_0/top_fifo_103x16_rdreq_0_clocks.xdc
  set_property processing_order LATE [get_files c:/xilinx/ide/ide.srcs/sources_1/bd/top/ip/top_fifo_103x16_rdreq_0/top_fifo_103x16_rdreq_0/top_fifo_103x16_rdreq_0_clocks.xdc]
  read_xdc -ref top_fifo_103x16_rresp_0 -cells U0 c:/xilinx/ide/ide.srcs/sources_1/bd/top/ip/top_fifo_103x16_rresp_0/top_fifo_103x16_rresp_0/top_fifo_103x16_rresp_0_clocks.xdc
  set_property processing_order LATE [get_files c:/xilinx/ide/ide.srcs/sources_1/bd/top/ip/top_fifo_103x16_rresp_0/top_fifo_103x16_rresp_0/top_fifo_103x16_rresp_0_clocks.xdc]
  read_xdc -ref top_fifo_103x16_write_0 -cells U0 c:/xilinx/ide/ide.srcs/sources_1/bd/top/ip/top_fifo_103x16_write_0/top_fifo_103x16_write_0/top_fifo_103x16_write_0_clocks.xdc
  set_property processing_order LATE [get_files c:/xilinx/ide/ide.srcs/sources_1/bd/top/ip/top_fifo_103x16_write_0/top_fifo_103x16_write_0/top_fifo_103x16_write_0_clocks.xdc]
  read_xdc -ref top_fifo_103x32_rdreq_0 -cells U0 c:/xilinx/ide/ide.srcs/sources_1/bd/top/ip/top_fifo_103x32_rdreq_0/top_fifo_103x32_rdreq_0/top_fifo_103x32_rdreq_0_clocks.xdc
  set_property processing_order LATE [get_files c:/xilinx/ide/ide.srcs/sources_1/bd/top/ip/top_fifo_103x32_rdreq_0/top_fifo_103x32_rdreq_0/top_fifo_103x32_rdreq_0_clocks.xdc]
  read_xdc -ref top_fifo_103x32_rresp_0 -cells U0 c:/xilinx/ide/ide.srcs/sources_1/bd/top/ip/top_fifo_103x32_rresp_0/top_fifo_103x32_rresp_0/top_fifo_103x32_rresp_0_clocks.xdc
  set_property processing_order LATE [get_files c:/xilinx/ide/ide.srcs/sources_1/bd/top/ip/top_fifo_103x32_rresp_0/top_fifo_103x32_rresp_0/top_fifo_103x32_rresp_0_clocks.xdc]
  read_xdc -ref top_fifo_103x32_write_0 -cells U0 c:/xilinx/ide/ide.srcs/sources_1/bd/top/ip/top_fifo_103x32_write_0/top_fifo_103x32_write_0/top_fifo_103x32_write_0_clocks.xdc
  set_property processing_order LATE [get_files c:/xilinx/ide/ide.srcs/sources_1/bd/top/ip/top_fifo_103x32_write_0/top_fifo_103x32_write_0/top_fifo_103x32_write_0_clocks.xdc]
  link_design -top top_wrapper -part xc7z020clg400-1
  close_msg_db -file init_design.pb
} RESULT]
if {$rc} {
  step_failed init_design
  return -code error $RESULT
} else {
  end_step init_design
}

start_step opt_design
set rc [catch {
  create_msg_db opt_design.pb
  catch {write_debug_probes -quiet -force debug_nets}
  opt_design 
  write_checkpoint -force top_wrapper_opt.dcp
  report_drc -file top_wrapper_drc_opted.rpt
  close_msg_db -file opt_design.pb
} RESULT]
if {$rc} {
  step_failed opt_design
  return -code error $RESULT
} else {
  end_step opt_design
}

start_step place_design
set rc [catch {
  create_msg_db place_design.pb
  catch {write_hwdef -file top_wrapper.hwdef}
  place_design 
  write_checkpoint -force top_wrapper_placed.dcp
  report_io -file top_wrapper_io_placed.rpt
  report_utilization -file top_wrapper_utilization_placed.rpt -pb top_wrapper_utilization_placed.pb
  report_control_sets -verbose -file top_wrapper_control_sets_placed.rpt
  close_msg_db -file place_design.pb
} RESULT]
if {$rc} {
  step_failed place_design
  return -code error $RESULT
} else {
  end_step place_design
}

start_step route_design
set rc [catch {
  create_msg_db route_design.pb
  route_design 
  write_checkpoint -force top_wrapper_routed.dcp
  report_drc -file top_wrapper_drc_routed.rpt -pb top_wrapper_drc_routed.pb
  report_timing_summary -warn_on_violation -max_paths 10 -file top_wrapper_timing_summary_routed.rpt -rpx top_wrapper_timing_summary_routed.rpx
  report_power -file top_wrapper_power_routed.rpt -pb top_wrapper_power_summary_routed.pb
  report_route_status -file top_wrapper_route_status.rpt -pb top_wrapper_route_status.pb
  report_clock_utilization -file top_wrapper_clock_utilization_routed.rpt
  close_msg_db -file route_design.pb
} RESULT]
if {$rc} {
  step_failed route_design
  return -code error $RESULT
} else {
  end_step route_design
}

