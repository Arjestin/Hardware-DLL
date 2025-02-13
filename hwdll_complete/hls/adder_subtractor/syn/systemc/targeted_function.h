// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2015.4
// Copyright (C) 2015 Xilinx Inc. All rights reserved.
// 
// ===========================================================

#ifndef _targeted_function_HH_
#define _targeted_function_HH_

#include "systemc.h"
#include "AESL_pkg.h"

#include "targeted_function_rm_s_axi.h"

namespace ap_rtl {

template<unsigned int C_S_AXI_RM_ADDR_WIDTH = 6,
         unsigned int C_S_AXI_RM_DATA_WIDTH = 32>
struct targeted_function : public sc_module {
    // Port declarations 20
    sc_in< sc_logic > s_axi_rm_AWVALID;
    sc_out< sc_logic > s_axi_rm_AWREADY;
    sc_in< sc_uint<C_S_AXI_RM_ADDR_WIDTH> > s_axi_rm_AWADDR;
    sc_in< sc_logic > s_axi_rm_WVALID;
    sc_out< sc_logic > s_axi_rm_WREADY;
    sc_in< sc_uint<C_S_AXI_RM_DATA_WIDTH> > s_axi_rm_WDATA;
    sc_in< sc_uint<C_S_AXI_RM_DATA_WIDTH/8> > s_axi_rm_WSTRB;
    sc_in< sc_logic > s_axi_rm_ARVALID;
    sc_out< sc_logic > s_axi_rm_ARREADY;
    sc_in< sc_uint<C_S_AXI_RM_ADDR_WIDTH> > s_axi_rm_ARADDR;
    sc_out< sc_logic > s_axi_rm_RVALID;
    sc_in< sc_logic > s_axi_rm_RREADY;
    sc_out< sc_uint<C_S_AXI_RM_DATA_WIDTH> > s_axi_rm_RDATA;
    sc_out< sc_lv<2> > s_axi_rm_RRESP;
    sc_out< sc_logic > s_axi_rm_BVALID;
    sc_in< sc_logic > s_axi_rm_BREADY;
    sc_out< sc_lv<2> > s_axi_rm_BRESP;
    sc_in_clk ap_clk;
    sc_in< sc_logic > ap_rst_n;
    sc_out< sc_logic > interrupt;
    // Port declarations for the virtual clock. 
    sc_in_clk ap_virtual_clock;


    // Module declarations
    targeted_function(sc_module_name name);
    SC_HAS_PROCESS(targeted_function);

    ~targeted_function();

    sc_trace_file* mVcdFile;

    ofstream mHdltvinHandle;
    ofstream mHdltvoutHandle;
    targeted_function_rm_s_axi<C_S_AXI_RM_ADDR_WIDTH,C_S_AXI_RM_DATA_WIDTH>* targeted_function_rm_s_axi_U;
    sc_signal< sc_logic > ap_start;
    sc_signal< sc_logic > ap_done;
    sc_signal< sc_logic > ap_idle;
    sc_signal< sc_logic > ap_ready;
    sc_signal< sc_lv<32> > input_000;
    sc_signal< sc_lv<32> > input_001;
    sc_signal< sc_lv<32> > output_000;
    sc_signal< sc_logic > output_000_ap_vld;
    sc_signal< sc_lv<32> > output_001;
    sc_signal< sc_logic > output_001_ap_vld;
    sc_signal< sc_lv<32> > ap_return;
    sc_signal< sc_logic > ap_rst_n_inv;
    sc_signal< sc_logic > targeted_function_rm_s_axi_U_ap_dummy_ce;
    sc_signal< sc_lv<32> > tmp_fu_65_p2;
    sc_signal< sc_lv<1> > tmp_1_fu_71_p3;
    sc_signal< sc_lv<32> > tmp_2_fu_79_p2;
    static const sc_logic ap_const_logic_1;
    static const int C_S_AXI_DATA_WIDTH;
    static const sc_logic ap_const_logic_0;
    static const sc_lv<32> ap_const_lv32_1F;
    static const sc_lv<32> ap_const_lv32_0;
    // Thread declarations
    void thread_ap_done();
    void thread_ap_idle();
    void thread_ap_ready();
    void thread_ap_return();
    void thread_ap_rst_n_inv();
    void thread_output_000();
    void thread_output_000_ap_vld();
    void thread_output_001();
    void thread_output_001_ap_vld();
    void thread_targeted_function_rm_s_axi_U_ap_dummy_ce();
    void thread_tmp_1_fu_71_p3();
    void thread_tmp_2_fu_79_p2();
    void thread_tmp_fu_65_p2();
    void thread_hdltv_gen();
};

}

using namespace ap_rtl;

#endif
