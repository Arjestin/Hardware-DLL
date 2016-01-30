# This script segment is generated automatically by AutoPilot

# clear list
if {${::AESL::PGuard_autoexp_gen}} {
    cg_default_interface_gen_dc_begin
    cg_default_interface_gen_bundle_begin
    AESL_LIB_XILADAPTER::native_axis_begin
}

set port_rm {
ap_start { }
ap_done { }
ap_ready { }
ap_idle { }
ap_return { 
	dir o
	width 32
	depth 1
	mode ap_ctrl_hs
	offset 16
	offset_end 0
}
input_000 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 24
	offset_end 31
}
input_001 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 32
	offset_end 39
}
output_000 { 
	dir O
	width 32
	depth 1
	mode ap_vld
	offset 40
	offset_end 47
}
output_001 { 
	dir O
	width 32
	depth 1
	mode ap_vld
	offset 48
	offset_end 55
}
}


# Native S_AXILite:
if {${::AESL::PGuard_simmodel_gen}} {
	if {[info proc ::AESL_LIB_XILADAPTER::s_axilite_gen] == "::AESL_LIB_XILADAPTER::s_axilite_gen"} {
		eval "::AESL_LIB_XILADAPTER::s_axilite_gen { \
			id 0 \
			corename targeted_function_rm_axilite \
			name targeted_function_rm_s_axi \
			ports {$port_rm} \
			op interface \
		} "
	} else {
		puts "@W \[IMPL-110\] Cannot find AXI Lite interface model in the library. Ignored generation of AXI Lite  interface for 'rm'"
	}
}

if {${::AESL::PGuard_rtl_comp_handler}} {
	::AP::rtl_comp_handler targeted_function_rm_s_axi
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id -1 \
    name ap_return \
    type ap_return \
    reset_level 0 \
    sync_rst true \
    corename ap_return \
    op interface \
    ports { ap_return { O 32 vector } } \
} "
}



# merge
if {${::AESL::PGuard_autoexp_gen}} {
    cg_default_interface_gen_dc_end
    cg_default_interface_gen_bundle_end
    AESL_LIB_XILADAPTER::native_axis_end
}


