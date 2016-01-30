#include "hls_design_meta.h"
const Port_Property HLS_Design_Meta::port_props[]={
	Port_Property("s_axi_rm_AWVALID", 1, hls_in, -1, "", "", 1),
	Port_Property("s_axi_rm_AWREADY", 1, hls_out, -1, "", "", 1),
	Port_Property("s_axi_rm_AWADDR", 12, hls_in, -1, "", "", 1),
	Port_Property("s_axi_rm_WVALID", 1, hls_in, -1, "", "", 1),
	Port_Property("s_axi_rm_WREADY", 1, hls_out, -1, "", "", 1),
	Port_Property("s_axi_rm_WDATA", 32, hls_in, -1, "", "", 1),
	Port_Property("s_axi_rm_WSTRB", 4, hls_in, -1, "", "", 1),
	Port_Property("s_axi_rm_ARVALID", 1, hls_in, -1, "", "", 1),
	Port_Property("s_axi_rm_ARREADY", 1, hls_out, -1, "", "", 1),
	Port_Property("s_axi_rm_ARADDR", 12, hls_in, -1, "", "", 1),
	Port_Property("s_axi_rm_RVALID", 1, hls_out, -1, "", "", 1),
	Port_Property("s_axi_rm_RREADY", 1, hls_in, -1, "", "", 1),
	Port_Property("s_axi_rm_RDATA", 32, hls_out, -1, "", "", 1),
	Port_Property("s_axi_rm_RRESP", 2, hls_out, -1, "", "", 1),
	Port_Property("s_axi_rm_BVALID", 1, hls_out, -1, "", "", 1),
	Port_Property("s_axi_rm_BREADY", 1, hls_in, -1, "", "", 1),
	Port_Property("s_axi_rm_BRESP", 2, hls_out, -1, "", "", 1),
	Port_Property("ap_clk", 1, hls_in, -1, "", "", 1),
	Port_Property("ap_rst_n", 1, hls_in, -1, "", "", 1),
	Port_Property("interrupt", 1, hls_out, -1, "", "", 1),
};
const char* HLS_Design_Meta::dut_name = "targeted_function";
