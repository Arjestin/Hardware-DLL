// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2015.4
// Copyright (C) 2015 Xilinx Inc. All rights reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

(* CORE_GENERATION_INFO="targeted_function,hls_ip_2015_4,{HLS_INPUT_TYPE=c,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xc7z020clg400-1,HLS_INPUT_CLOCK=10.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=5.810000,HLS_SYN_LAT=0,HLS_SYN_TPT=none,HLS_SYN_MEM=0,HLS_SYN_DSP=0,HLS_SYN_FF=220,HLS_SYN_LUT=488}" *)

module targeted_function (
        s_axi_rm_AWVALID,
        s_axi_rm_AWREADY,
        s_axi_rm_AWADDR,
        s_axi_rm_WVALID,
        s_axi_rm_WREADY,
        s_axi_rm_WDATA,
        s_axi_rm_WSTRB,
        s_axi_rm_ARVALID,
        s_axi_rm_ARREADY,
        s_axi_rm_ARADDR,
        s_axi_rm_RVALID,
        s_axi_rm_RREADY,
        s_axi_rm_RDATA,
        s_axi_rm_RRESP,
        s_axi_rm_BVALID,
        s_axi_rm_BREADY,
        s_axi_rm_BRESP,
        ap_clk,
        ap_rst_n,
        interrupt
);

parameter    ap_const_logic_1 = 1'b1;
parameter    C_S_AXI_RM_DATA_WIDTH = 32;
parameter    ap_const_int64_8 = 8;
parameter    C_S_AXI_RM_ADDR_WIDTH = 12;
parameter    C_S_AXI_DATA_WIDTH = 32;
parameter    ap_const_logic_0 = 1'b0;
parameter    ap_const_lv32_1F = 32'b11111;
parameter    ap_const_lv32_0 = 32'b00000000000000000000000000000000;
parameter    ap_true = 1'b1;
parameter    C_S_AXI_RM_WSTRB_WIDTH = (C_S_AXI_RM_DATA_WIDTH / ap_const_int64_8);
parameter    C_S_AXI_WSTRB_WIDTH = (C_S_AXI_DATA_WIDTH / ap_const_int64_8);

input   s_axi_rm_AWVALID;
output   s_axi_rm_AWREADY;
input  [C_S_AXI_RM_ADDR_WIDTH - 1 : 0] s_axi_rm_AWADDR;
input   s_axi_rm_WVALID;
output   s_axi_rm_WREADY;
input  [C_S_AXI_RM_DATA_WIDTH - 1 : 0] s_axi_rm_WDATA;
input  [C_S_AXI_RM_WSTRB_WIDTH - 1 : 0] s_axi_rm_WSTRB;
input   s_axi_rm_ARVALID;
output   s_axi_rm_ARREADY;
input  [C_S_AXI_RM_ADDR_WIDTH - 1 : 0] s_axi_rm_ARADDR;
output   s_axi_rm_RVALID;
input   s_axi_rm_RREADY;
output  [C_S_AXI_RM_DATA_WIDTH - 1 : 0] s_axi_rm_RDATA;
output  [1:0] s_axi_rm_RRESP;
output   s_axi_rm_BVALID;
input   s_axi_rm_BREADY;
output  [1:0] s_axi_rm_BRESP;
input   ap_clk;
input   ap_rst_n;
output   interrupt;

wire    ap_start;
wire    ap_done;
wire    ap_idle;
wire    ap_ready;
wire   [31:0] input_000;
wire   [31:0] input_001;
wire   [31:0] output_000;
reg    output_000_ap_vld;
wire   [31:0] output_001;
reg    output_001_ap_vld;
wire   [31:0] ap_return;
reg    ap_rst_n_inv;
wire    targeted_function_rm_s_axi_U_ap_dummy_ce;
wire   [31:0] tmp_fu_65_p2;
wire   [0:0] tmp_1_fu_71_p3;
wire   [31:0] tmp_2_fu_79_p2;


targeted_function_rm_s_axi #(
    .C_S_AXI_ADDR_WIDTH( C_S_AXI_RM_ADDR_WIDTH ),
    .C_S_AXI_DATA_WIDTH( C_S_AXI_RM_DATA_WIDTH ))
targeted_function_rm_s_axi_U(
    .AWVALID( s_axi_rm_AWVALID ),
    .AWREADY( s_axi_rm_AWREADY ),
    .AWADDR( s_axi_rm_AWADDR ),
    .WVALID( s_axi_rm_WVALID ),
    .WREADY( s_axi_rm_WREADY ),
    .WDATA( s_axi_rm_WDATA ),
    .WSTRB( s_axi_rm_WSTRB ),
    .ARVALID( s_axi_rm_ARVALID ),
    .ARREADY( s_axi_rm_ARREADY ),
    .ARADDR( s_axi_rm_ARADDR ),
    .RVALID( s_axi_rm_RVALID ),
    .RREADY( s_axi_rm_RREADY ),
    .RDATA( s_axi_rm_RDATA ),
    .RRESP( s_axi_rm_RRESP ),
    .BVALID( s_axi_rm_BVALID ),
    .BREADY( s_axi_rm_BREADY ),
    .BRESP( s_axi_rm_BRESP ),
    .ACLK( ap_clk ),
    .ARESET( ap_rst_n_inv ),
    .ACLK_EN( targeted_function_rm_s_axi_U_ap_dummy_ce ),
    .ap_start( ap_start ),
    .interrupt( interrupt ),
    .ap_ready( ap_ready ),
    .ap_done( ap_done ),
    .ap_idle( ap_idle ),
    .ap_return( ap_return ),
    .input_000( input_000 ),
    .input_001( input_001 ),
    .output_000( output_000 ),
    .output_000_ap_vld( output_000_ap_vld ),
    .output_001( output_001 ),
    .output_001_ap_vld( output_001_ap_vld )
);



always @ (ap_start) begin
    if (~(ap_start == ap_const_logic_0)) begin
        output_000_ap_vld = ap_const_logic_1;
    end else begin
        output_000_ap_vld = ap_const_logic_0;
    end
end

always @ (ap_start) begin
    if (~(ap_start == ap_const_logic_0)) begin
        output_001_ap_vld = ap_const_logic_1;
    end else begin
        output_001_ap_vld = ap_const_logic_0;
    end
end

assign ap_done = ap_start;

assign ap_idle = ap_const_logic_1;

assign ap_ready = ap_start;

assign ap_return = ap_const_lv32_0;


always @ (ap_rst_n) begin
    ap_rst_n_inv = ~ap_rst_n;
end

assign output_000 = (input_001 + input_000);

assign output_001 = ((tmp_1_fu_71_p3[0:0] === 1'b1) ? tmp_2_fu_79_p2 : tmp_fu_65_p2);

assign targeted_function_rm_s_axi_U_ap_dummy_ce = ap_const_logic_1;

assign tmp_1_fu_71_p3 = tmp_fu_65_p2[ap_const_lv32_1F];

assign tmp_2_fu_79_p2 = (input_001 - input_000);

assign tmp_fu_65_p2 = (input_000 - input_001);


endmodule //targeted_function

