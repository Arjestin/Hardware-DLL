-- ==============================================================
-- RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
-- Version: 2015.4
-- Copyright (C) 2015 Xilinx Inc. All rights reserved.
-- 
-- ===========================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity targeted_function is
generic (
    C_S_AXI_RM_ADDR_WIDTH : INTEGER := 6;
    C_S_AXI_RM_DATA_WIDTH : INTEGER := 32 );
port (
    ap_clk : IN STD_LOGIC;
    ap_rst_n : IN STD_LOGIC;
    s_axi_rm_AWVALID : IN STD_LOGIC;
    s_axi_rm_AWREADY : OUT STD_LOGIC;
    s_axi_rm_AWADDR : IN STD_LOGIC_VECTOR (C_S_AXI_RM_ADDR_WIDTH-1 downto 0);
    s_axi_rm_WVALID : IN STD_LOGIC;
    s_axi_rm_WREADY : OUT STD_LOGIC;
    s_axi_rm_WDATA : IN STD_LOGIC_VECTOR (C_S_AXI_RM_DATA_WIDTH-1 downto 0);
    s_axi_rm_WSTRB : IN STD_LOGIC_VECTOR (C_S_AXI_RM_DATA_WIDTH/8-1 downto 0);
    s_axi_rm_ARVALID : IN STD_LOGIC;
    s_axi_rm_ARREADY : OUT STD_LOGIC;
    s_axi_rm_ARADDR : IN STD_LOGIC_VECTOR (C_S_AXI_RM_ADDR_WIDTH-1 downto 0);
    s_axi_rm_RVALID : OUT STD_LOGIC;
    s_axi_rm_RREADY : IN STD_LOGIC;
    s_axi_rm_RDATA : OUT STD_LOGIC_VECTOR (C_S_AXI_RM_DATA_WIDTH-1 downto 0);
    s_axi_rm_RRESP : OUT STD_LOGIC_VECTOR (1 downto 0);
    s_axi_rm_BVALID : OUT STD_LOGIC;
    s_axi_rm_BREADY : IN STD_LOGIC;
    s_axi_rm_BRESP : OUT STD_LOGIC_VECTOR (1 downto 0);
    interrupt : OUT STD_LOGIC );
end;


architecture behav of targeted_function is 
    attribute CORE_GENERATION_INFO : STRING;
    attribute CORE_GENERATION_INFO of behav : architecture is
    "targeted_function,hls_ip_2015_4,{HLS_INPUT_TYPE=c,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xc7z020clg400-1,HLS_INPUT_CLOCK=10.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=5.810000,HLS_SYN_LAT=-1,HLS_SYN_TPT=none,HLS_SYN_MEM=0,HLS_SYN_DSP=0,HLS_SYN_FF=539,HLS_SYN_LUT=920}";
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_const_logic_0 : STD_LOGIC := '0';
    constant ap_ST_st1_fsm_0 : STD_LOGIC_VECTOR (3 downto 0) := "0001";
    constant ap_ST_st2_fsm_1 : STD_LOGIC_VECTOR (3 downto 0) := "0010";
    constant ap_ST_st3_fsm_2 : STD_LOGIC_VECTOR (3 downto 0) := "0100";
    constant ap_ST_st4_fsm_3 : STD_LOGIC_VECTOR (3 downto 0) := "1000";
    constant ap_const_lv32_0 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000000";
    constant ap_const_lv1_1 : STD_LOGIC_VECTOR (0 downto 0) := "1";
    constant C_S_AXI_DATA_WIDTH : INTEGER range 63 downto 0 := 20;
    constant ap_const_lv32_2 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000010";
    constant ap_const_lv1_0 : STD_LOGIC_VECTOR (0 downto 0) := "0";
    constant ap_const_lv32_1 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000001";
    constant ap_const_lv32_FFFFFFFF : STD_LOGIC_VECTOR (31 downto 0) := "11111111111111111111111111111111";
    constant ap_const_lv32_1F : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000011111";
    constant ap_const_lv32_3 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000011";

    signal ap_rst_n_inv : STD_LOGIC;
    signal ap_start : STD_LOGIC;
    signal ap_done : STD_LOGIC;
    signal ap_idle : STD_LOGIC;
    signal ap_CS_fsm : STD_LOGIC_VECTOR (3 downto 0) := "0001";
    attribute fsm_encoding : string;
    attribute fsm_encoding of ap_CS_fsm : signal is "none";
    signal ap_sig_cseq_ST_st1_fsm_0 : STD_LOGIC;
    signal ap_sig_bdd_22 : BOOLEAN;
    signal ap_ready : STD_LOGIC;
    signal input_000 : STD_LOGIC_VECTOR (31 downto 0);
    signal input_001 : STD_LOGIC_VECTOR (31 downto 0);
    signal output_000 : STD_LOGIC_VECTOR (31 downto 0);
    signal output_000_ap_vld : STD_LOGIC;
    signal ap_return : STD_LOGIC_VECTOR (31 downto 0);
    signal targeted_function_rm_s_axi_U_ap_dummy_ce : STD_LOGIC;
    signal grp_fu_140_p2 : STD_LOGIC_VECTOR (31 downto 0);
    signal ap_sig_cseq_ST_st3_fsm_2 : STD_LOGIC;
    signal ap_sig_bdd_84 : BOOLEAN;
    signal grp_fu_140_ap_done : STD_LOGIC;
    signal input_000_assign_reg_56 : STD_LOGIC_VECTOR (31 downto 0);
    signal tmp_2_fu_105_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal tmp_1_fu_99_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal p_1_reg_66 : STD_LOGIC_VECTOR (31 downto 0);
    signal p_0_reg_77 : STD_LOGIC_VECTOR (0 downto 0);
    signal ap_sig_cseq_ST_st2_fsm_1 : STD_LOGIC;
    signal ap_sig_bdd_113 : BOOLEAN;
    signal tmp_6_fu_134_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal input_001_assign_fu_125_p3 : STD_LOGIC_VECTOR (31 downto 0);
    signal tmp_9_fu_160_p3 : STD_LOGIC_VECTOR (31 downto 0);
    signal tmp_fu_93_p2 : STD_LOGIC_VECTOR (31 downto 0);
    signal tmp_3_fu_111_p3 : STD_LOGIC_VECTOR (0 downto 0);
    signal tmp_4_fu_119_p2 : STD_LOGIC_VECTOR (31 downto 0);
    signal tmp_5_fu_146_p3 : STD_LOGIC_VECTOR (0 downto 0);
    signal tmp_8_fu_154_p2 : STD_LOGIC_VECTOR (31 downto 0);
    signal ap_sig_cseq_ST_st4_fsm_3 : STD_LOGIC;
    signal ap_sig_bdd_163 : BOOLEAN;
    signal grp_fu_140_ap_start : STD_LOGIC;
    signal grp_fu_140_ce : STD_LOGIC;
    signal ap_NS_fsm : STD_LOGIC_VECTOR (3 downto 0);

    component targeted_function_srem_32ns_32ns_32_36_seq IS
    generic (
        ID : INTEGER;
        NUM_STAGE : INTEGER;
        din0_WIDTH : INTEGER;
        din1_WIDTH : INTEGER;
        dout_WIDTH : INTEGER );
    port (
        clk : IN STD_LOGIC;
        reset : IN STD_LOGIC;
        start : IN STD_LOGIC;
        done : OUT STD_LOGIC;
        din0 : IN STD_LOGIC_VECTOR (31 downto 0);
        din1 : IN STD_LOGIC_VECTOR (31 downto 0);
        ce : IN STD_LOGIC;
        dout : OUT STD_LOGIC_VECTOR (31 downto 0) );
    end component;


    component targeted_function_rm_s_axi IS
    generic (
        C_S_AXI_ADDR_WIDTH : INTEGER;
        C_S_AXI_DATA_WIDTH : INTEGER );
    port (
        AWVALID : IN STD_LOGIC;
        AWREADY : OUT STD_LOGIC;
        AWADDR : IN STD_LOGIC_VECTOR (C_S_AXI_ADDR_WIDTH-1 downto 0);
        WVALID : IN STD_LOGIC;
        WREADY : OUT STD_LOGIC;
        WDATA : IN STD_LOGIC_VECTOR (C_S_AXI_DATA_WIDTH-1 downto 0);
        WSTRB : IN STD_LOGIC_VECTOR (C_S_AXI_DATA_WIDTH/8-1 downto 0);
        ARVALID : IN STD_LOGIC;
        ARREADY : OUT STD_LOGIC;
        ARADDR : IN STD_LOGIC_VECTOR (C_S_AXI_ADDR_WIDTH-1 downto 0);
        RVALID : OUT STD_LOGIC;
        RREADY : IN STD_LOGIC;
        RDATA : OUT STD_LOGIC_VECTOR (C_S_AXI_DATA_WIDTH-1 downto 0);
        RRESP : OUT STD_LOGIC_VECTOR (1 downto 0);
        BVALID : OUT STD_LOGIC;
        BREADY : IN STD_LOGIC;
        BRESP : OUT STD_LOGIC_VECTOR (1 downto 0);
        ACLK : IN STD_LOGIC;
        ARESET : IN STD_LOGIC;
        ACLK_EN : IN STD_LOGIC;
        ap_start : OUT STD_LOGIC;
        interrupt : OUT STD_LOGIC;
        ap_ready : IN STD_LOGIC;
        ap_done : IN STD_LOGIC;
        ap_idle : IN STD_LOGIC;
        ap_return : IN STD_LOGIC_VECTOR (31 downto 0);
        input_000 : OUT STD_LOGIC_VECTOR (31 downto 0);
        input_001 : OUT STD_LOGIC_VECTOR (31 downto 0);
        output_000 : IN STD_LOGIC_VECTOR (31 downto 0);
        output_000_ap_vld : IN STD_LOGIC );
    end component;



begin
    targeted_function_rm_s_axi_U : component targeted_function_rm_s_axi
    generic map (
        C_S_AXI_ADDR_WIDTH => C_S_AXI_RM_ADDR_WIDTH,
        C_S_AXI_DATA_WIDTH => C_S_AXI_RM_DATA_WIDTH)
    port map (
        AWVALID => s_axi_rm_AWVALID,
        AWREADY => s_axi_rm_AWREADY,
        AWADDR => s_axi_rm_AWADDR,
        WVALID => s_axi_rm_WVALID,
        WREADY => s_axi_rm_WREADY,
        WDATA => s_axi_rm_WDATA,
        WSTRB => s_axi_rm_WSTRB,
        ARVALID => s_axi_rm_ARVALID,
        ARREADY => s_axi_rm_ARREADY,
        ARADDR => s_axi_rm_ARADDR,
        RVALID => s_axi_rm_RVALID,
        RREADY => s_axi_rm_RREADY,
        RDATA => s_axi_rm_RDATA,
        RRESP => s_axi_rm_RRESP,
        BVALID => s_axi_rm_BVALID,
        BREADY => s_axi_rm_BREADY,
        BRESP => s_axi_rm_BRESP,
        ACLK => ap_clk,
        ARESET => ap_rst_n_inv,
        ACLK_EN => targeted_function_rm_s_axi_U_ap_dummy_ce,
        ap_start => ap_start,
        interrupt => interrupt,
        ap_ready => ap_ready,
        ap_done => ap_done,
        ap_idle => ap_idle,
        ap_return => ap_return,
        input_000 => input_000,
        input_001 => input_001,
        output_000 => output_000,
        output_000_ap_vld => output_000_ap_vld);

    targeted_function_srem_32ns_32ns_32_36_seq_U0 : component targeted_function_srem_32ns_32ns_32_36_seq
    generic map (
        ID => 1,
        NUM_STAGE => 36,
        din0_WIDTH => 32,
        din1_WIDTH => 32,
        dout_WIDTH => 32)
    port map (
        clk => ap_clk,
        reset => ap_rst_n_inv,
        start => grp_fu_140_ap_start,
        done => grp_fu_140_ap_done,
        din0 => p_1_reg_66,
        din1 => input_000_assign_reg_56,
        ce => grp_fu_140_ce,
        dout => grp_fu_140_p2);





    -- the current state (ap_CS_fsm) of the state machine. --
    ap_CS_fsm_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst_n_inv = '1') then
                ap_CS_fsm <= ap_ST_st1_fsm_0;
            else
                ap_CS_fsm <= ap_NS_fsm;
            end if;
        end if;
    end process;


    -- input_000_assign_reg_56 assign process. --
    input_000_assign_reg_56_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_logic_1 = ap_sig_cseq_ST_st1_fsm_0) and not((ap_start = ap_const_logic_0)) and (tmp_2_fu_105_p2 = ap_const_lv1_0) and (ap_const_lv1_0 = tmp_1_fu_99_p2))) then 
                input_000_assign_reg_56 <= input_001;
            elsif (((ap_const_logic_1 = ap_sig_cseq_ST_st3_fsm_2) and not((ap_const_logic_0 = grp_fu_140_ap_done)))) then 
                input_000_assign_reg_56 <= grp_fu_140_p2;
            end if; 
        end if;
    end process;

    -- p_0_reg_77 assign process. --
    p_0_reg_77_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((((ap_const_logic_1 = ap_sig_cseq_ST_st1_fsm_0) and not((ap_start = ap_const_logic_0)) and (ap_const_lv1_0 = tmp_1_fu_99_p2) and not((tmp_2_fu_105_p2 = ap_const_lv1_0))) or ((ap_const_logic_1 = ap_sig_cseq_ST_st2_fsm_1) and not((ap_const_lv1_0 = tmp_6_fu_134_p2))))) then 
                p_0_reg_77 <= ap_const_lv1_0;
            elsif (((ap_const_logic_1 = ap_sig_cseq_ST_st1_fsm_0) and not((ap_start = ap_const_logic_0)) and not((ap_const_lv1_0 = tmp_1_fu_99_p2)))) then 
                p_0_reg_77 <= ap_const_lv1_1;
            end if; 
        end if;
    end process;

    -- p_1_reg_66 assign process. --
    p_1_reg_66_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_logic_1 = ap_sig_cseq_ST_st1_fsm_0) and not((ap_start = ap_const_logic_0)) and (tmp_2_fu_105_p2 = ap_const_lv1_0) and (ap_const_lv1_0 = tmp_1_fu_99_p2))) then 
                p_1_reg_66 <= input_000;
            elsif (((ap_const_logic_1 = ap_sig_cseq_ST_st3_fsm_2) and not((ap_const_logic_0 = grp_fu_140_ap_done)))) then 
                p_1_reg_66 <= input_000_assign_reg_56;
            end if; 
        end if;
    end process;

    -- the next state (ap_NS_fsm) of the state machine. --
    ap_NS_fsm_assign_proc : process (ap_start, ap_CS_fsm, grp_fu_140_ap_done, tmp_2_fu_105_p2, tmp_1_fu_99_p2, tmp_6_fu_134_p2)
    begin
        case ap_CS_fsm is
            when ap_ST_st1_fsm_0 => 
                if ((not((ap_start = ap_const_logic_0)) and (not((ap_const_lv1_0 = tmp_1_fu_99_p2)) or not((tmp_2_fu_105_p2 = ap_const_lv1_0))))) then
                    ap_NS_fsm <= ap_ST_st4_fsm_3;
                elsif ((not((ap_start = ap_const_logic_0)) and (tmp_2_fu_105_p2 = ap_const_lv1_0) and (ap_const_lv1_0 = tmp_1_fu_99_p2))) then
                    ap_NS_fsm <= ap_ST_st2_fsm_1;
                else
                    ap_NS_fsm <= ap_ST_st1_fsm_0;
                end if;
            when ap_ST_st2_fsm_1 => 
                if (not((ap_const_lv1_0 = tmp_6_fu_134_p2))) then
                    ap_NS_fsm <= ap_ST_st4_fsm_3;
                else
                    ap_NS_fsm <= ap_ST_st3_fsm_2;
                end if;
            when ap_ST_st3_fsm_2 => 
                if (not((ap_const_logic_0 = grp_fu_140_ap_done))) then
                    ap_NS_fsm <= ap_ST_st2_fsm_1;
                else
                    ap_NS_fsm <= ap_ST_st3_fsm_2;
                end if;
            when ap_ST_st4_fsm_3 => 
                ap_NS_fsm <= ap_ST_st1_fsm_0;
            when others =>  
                ap_NS_fsm <= "XXXX";
        end case;
    end process;

    -- ap_done assign process. --
    ap_done_assign_proc : process(ap_sig_cseq_ST_st4_fsm_3)
    begin
        if ((ap_const_logic_1 = ap_sig_cseq_ST_st4_fsm_3)) then 
            ap_done <= ap_const_logic_1;
        else 
            ap_done <= ap_const_logic_0;
        end if; 
    end process;


    -- ap_idle assign process. --
    ap_idle_assign_proc : process(ap_start, ap_sig_cseq_ST_st1_fsm_0)
    begin
        if ((not((ap_const_logic_1 = ap_start)) and (ap_const_logic_1 = ap_sig_cseq_ST_st1_fsm_0))) then 
            ap_idle <= ap_const_logic_1;
        else 
            ap_idle <= ap_const_logic_0;
        end if; 
    end process;


    -- ap_ready assign process. --
    ap_ready_assign_proc : process(ap_sig_cseq_ST_st4_fsm_3)
    begin
        if ((ap_const_logic_1 = ap_sig_cseq_ST_st4_fsm_3)) then 
            ap_ready <= ap_const_logic_1;
        else 
            ap_ready <= ap_const_logic_0;
        end if; 
    end process;

    ap_return <= 
        ap_const_lv32_FFFFFFFF when (p_0_reg_77(0) = '1') else 
        ap_const_lv32_0;

    -- ap_rst_n_inv assign process. --
    ap_rst_n_inv_assign_proc : process(ap_rst_n)
    begin
                ap_rst_n_inv <= not(ap_rst_n);
    end process;


    -- ap_sig_bdd_113 assign process. --
    ap_sig_bdd_113_assign_proc : process(ap_CS_fsm)
    begin
                ap_sig_bdd_113 <= (ap_const_lv1_1 = ap_CS_fsm(1 downto 1));
    end process;


    -- ap_sig_bdd_163 assign process. --
    ap_sig_bdd_163_assign_proc : process(ap_CS_fsm)
    begin
                ap_sig_bdd_163 <= (ap_const_lv1_1 = ap_CS_fsm(3 downto 3));
    end process;


    -- ap_sig_bdd_22 assign process. --
    ap_sig_bdd_22_assign_proc : process(ap_CS_fsm)
    begin
                ap_sig_bdd_22 <= (ap_CS_fsm(0 downto 0) = ap_const_lv1_1);
    end process;


    -- ap_sig_bdd_84 assign process. --
    ap_sig_bdd_84_assign_proc : process(ap_CS_fsm)
    begin
                ap_sig_bdd_84 <= (ap_const_lv1_1 = ap_CS_fsm(2 downto 2));
    end process;


    -- ap_sig_cseq_ST_st1_fsm_0 assign process. --
    ap_sig_cseq_ST_st1_fsm_0_assign_proc : process(ap_sig_bdd_22)
    begin
        if (ap_sig_bdd_22) then 
            ap_sig_cseq_ST_st1_fsm_0 <= ap_const_logic_1;
        else 
            ap_sig_cseq_ST_st1_fsm_0 <= ap_const_logic_0;
        end if; 
    end process;


    -- ap_sig_cseq_ST_st2_fsm_1 assign process. --
    ap_sig_cseq_ST_st2_fsm_1_assign_proc : process(ap_sig_bdd_113)
    begin
        if (ap_sig_bdd_113) then 
            ap_sig_cseq_ST_st2_fsm_1 <= ap_const_logic_1;
        else 
            ap_sig_cseq_ST_st2_fsm_1 <= ap_const_logic_0;
        end if; 
    end process;


    -- ap_sig_cseq_ST_st3_fsm_2 assign process. --
    ap_sig_cseq_ST_st3_fsm_2_assign_proc : process(ap_sig_bdd_84)
    begin
        if (ap_sig_bdd_84) then 
            ap_sig_cseq_ST_st3_fsm_2 <= ap_const_logic_1;
        else 
            ap_sig_cseq_ST_st3_fsm_2 <= ap_const_logic_0;
        end if; 
    end process;


    -- ap_sig_cseq_ST_st4_fsm_3 assign process. --
    ap_sig_cseq_ST_st4_fsm_3_assign_proc : process(ap_sig_bdd_163)
    begin
        if (ap_sig_bdd_163) then 
            ap_sig_cseq_ST_st4_fsm_3 <= ap_const_logic_1;
        else 
            ap_sig_cseq_ST_st4_fsm_3 <= ap_const_logic_0;
        end if; 
    end process;


    -- grp_fu_140_ap_start assign process. --
    grp_fu_140_ap_start_assign_proc : process(ap_sig_cseq_ST_st2_fsm_1, tmp_6_fu_134_p2)
    begin
        if (((ap_const_logic_1 = ap_sig_cseq_ST_st2_fsm_1) and (ap_const_lv1_0 = tmp_6_fu_134_p2))) then 
            grp_fu_140_ap_start <= ap_const_logic_1;
        else 
            grp_fu_140_ap_start <= ap_const_logic_0;
        end if; 
    end process;

    grp_fu_140_ce <= ap_const_logic_1;
    input_001_assign_fu_125_p3 <= 
        tmp_4_fu_119_p2 when (tmp_3_fu_111_p3(0) = '1') else 
        input_001;

    -- output_000 assign process. --
    output_000_assign_proc : process(ap_start, ap_sig_cseq_ST_st1_fsm_0, tmp_2_fu_105_p2, tmp_1_fu_99_p2, ap_sig_cseq_ST_st2_fsm_1, tmp_6_fu_134_p2, input_001_assign_fu_125_p3, tmp_9_fu_160_p3)
    begin
        if (((ap_const_logic_1 = ap_sig_cseq_ST_st2_fsm_1) and not((ap_const_lv1_0 = tmp_6_fu_134_p2)))) then 
            output_000 <= tmp_9_fu_160_p3;
        elsif (((ap_const_logic_1 = ap_sig_cseq_ST_st1_fsm_0) and not((ap_start = ap_const_logic_0)) and not((ap_const_lv1_0 = tmp_1_fu_99_p2)))) then 
            output_000 <= ap_const_lv32_FFFFFFFF;
        elsif (((ap_const_logic_1 = ap_sig_cseq_ST_st1_fsm_0) and not((ap_start = ap_const_logic_0)) and (ap_const_lv1_0 = tmp_1_fu_99_p2) and not((tmp_2_fu_105_p2 = ap_const_lv1_0)))) then 
            output_000 <= input_001_assign_fu_125_p3;
        else 
            output_000 <= "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
        end if; 
    end process;


    -- output_000_ap_vld assign process. --
    output_000_ap_vld_assign_proc : process(ap_start, ap_sig_cseq_ST_st1_fsm_0, tmp_2_fu_105_p2, tmp_1_fu_99_p2, ap_sig_cseq_ST_st2_fsm_1, tmp_6_fu_134_p2)
    begin
        if ((((ap_const_logic_1 = ap_sig_cseq_ST_st1_fsm_0) and not((ap_start = ap_const_logic_0)) and not((ap_const_lv1_0 = tmp_1_fu_99_p2))) or ((ap_const_logic_1 = ap_sig_cseq_ST_st1_fsm_0) and not((ap_start = ap_const_logic_0)) and (ap_const_lv1_0 = tmp_1_fu_99_p2) and not((tmp_2_fu_105_p2 = ap_const_lv1_0))) or ((ap_const_logic_1 = ap_sig_cseq_ST_st2_fsm_1) and not((ap_const_lv1_0 = tmp_6_fu_134_p2))))) then 
            output_000_ap_vld <= ap_const_logic_1;
        else 
            output_000_ap_vld <= ap_const_logic_0;
        end if; 
    end process;

    targeted_function_rm_s_axi_U_ap_dummy_ce <= ap_const_logic_1;
    tmp_1_fu_99_p2 <= "1" when (tmp_fu_93_p2 = ap_const_lv32_0) else "0";
    tmp_2_fu_105_p2 <= "1" when (input_000 = ap_const_lv32_0) else "0";
    tmp_3_fu_111_p3 <= input_001(31 downto 31);
    tmp_4_fu_119_p2 <= std_logic_vector(unsigned(ap_const_lv32_0) - unsigned(input_001));
    tmp_5_fu_146_p3 <= p_1_reg_66(31 downto 31);
    tmp_6_fu_134_p2 <= "1" when (input_000_assign_reg_56 = ap_const_lv32_0) else "0";
    tmp_8_fu_154_p2 <= std_logic_vector(unsigned(ap_const_lv32_0) - unsigned(p_1_reg_66));
    tmp_9_fu_160_p3 <= 
        tmp_8_fu_154_p2 when (tmp_5_fu_146_p3(0) = '1') else 
        p_1_reg_66;
    tmp_fu_93_p2 <= (input_001 or input_000);
end behav;
