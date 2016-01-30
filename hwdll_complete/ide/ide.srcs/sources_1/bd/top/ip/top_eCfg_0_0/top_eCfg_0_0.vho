-- (c) Copyright 1995-2016 Xilinx, Inc. All rights reserved.
-- 
-- This file contains confidential and proprietary information
-- of Xilinx, Inc. and is protected under U.S. and
-- international copyright and other intellectual property
-- laws.
-- 
-- DISCLAIMER
-- This disclaimer is not a license and does not grant any
-- rights to the materials distributed herewith. Except as
-- otherwise provided in a valid license issued to you by
-- Xilinx, and to the maximum extent permitted by applicable
-- law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
-- WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
-- AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
-- BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
-- INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
-- (2) Xilinx shall not be liable (whether in contract or tort,
-- including negligence, or under any other theory of
-- liability) for any loss or damage of any kind or nature
-- related to, arising under or in connection with these
-- materials, including for any direct, or any indirect,
-- special, incidental, or consequential loss or damage
-- (including loss of data, profits, goodwill, or any type of
-- loss or damage suffered as a result of any action brought
-- by a third party) even if such damage or loss was
-- reasonably foreseeable or Xilinx had been advised of the
-- possibility of the same.
-- 
-- CRITICAL APPLICATIONS
-- Xilinx products are not designed or intended to be fail-
-- safe, or for use in any application requiring fail-safe
-- performance, such as life-support or safety devices or
-- systems, Class III medical devices, nuclear facilities,
-- applications related to the deployment of airbags, or any
-- other applications that could lead to death, personal
-- injury, or severe property or environmental damage
-- (individually and collectively, "Critical
-- Applications"). Customer assumes the sole risk and
-- liability of any use of Xilinx products in Critical
-- Applications, subject only to applicable laws and
-- regulations governing limitations on product liability.
-- 
-- THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
-- PART OF THIS FILE AT ALL TIMES.
-- 
-- DO NOT MODIFY THIS FILE.

-- IP VLNV: adapteva.com:Adapteva:eCfg:1.0
-- IP Revision: 7

-- The following code must appear in the VHDL architecture header.

------------- Begin Cut here for COMPONENT Declaration ------ COMP_TAG
COMPONENT top_eCfg_0_0
  PORT (
    mi_dout : OUT STD_LOGIC_VECTOR(31 DOWNTO 0);
    ecfg_sw_reset : OUT STD_LOGIC;
    ecfg_reset : OUT STD_LOGIC;
    ecfg_tx_enable : OUT STD_LOGIC;
    ecfg_tx_mmu_mode : OUT STD_LOGIC;
    ecfg_tx_gpio_mode : OUT STD_LOGIC;
    ecfg_tx_ctrl_mode : OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
    ecfg_tx_clkdiv : OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
    ecfg_rx_enable : OUT STD_LOGIC;
    ecfg_rx_mmu_mode : OUT STD_LOGIC;
    ecfg_rx_gpio_mode : OUT STD_LOGIC;
    ecfg_rx_loopback_mode : OUT STD_LOGIC;
    ecfg_cclk_en : OUT STD_LOGIC;
    ecfg_cclk_div : OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
    ecfg_cclk_pllcfg : OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
    ecfg_coreid : OUT STD_LOGIC_VECTOR(11 DOWNTO 0);
    ecfg_dataout : OUT STD_LOGIC_VECTOR(10 DOWNTO 0);
    mi_clk : IN STD_LOGIC;
    mi_rst : IN STD_LOGIC;
    mi_en : IN STD_LOGIC;
    mi_we : IN STD_LOGIC;
    mi_addr : IN STD_LOGIC_VECTOR(11 DOWNTO 0);
    mi_din : IN STD_LOGIC_VECTOR(31 DOWNTO 0);
    hw_reset : IN STD_LOGIC;
    ecfg_datain : IN STD_LOGIC_VECTOR(10 DOWNTO 0)
  );
END COMPONENT;
-- COMP_TAG_END ------ End COMPONENT Declaration ------------

-- The following code must appear in the VHDL architecture
-- body. Substitute your own instance name and net names.

------------- Begin Cut here for INSTANTIATION Template ----- INST_TAG
your_instance_name : top_eCfg_0_0
  PORT MAP (
    mi_dout => mi_dout,
    ecfg_sw_reset => ecfg_sw_reset,
    ecfg_reset => ecfg_reset,
    ecfg_tx_enable => ecfg_tx_enable,
    ecfg_tx_mmu_mode => ecfg_tx_mmu_mode,
    ecfg_tx_gpio_mode => ecfg_tx_gpio_mode,
    ecfg_tx_ctrl_mode => ecfg_tx_ctrl_mode,
    ecfg_tx_clkdiv => ecfg_tx_clkdiv,
    ecfg_rx_enable => ecfg_rx_enable,
    ecfg_rx_mmu_mode => ecfg_rx_mmu_mode,
    ecfg_rx_gpio_mode => ecfg_rx_gpio_mode,
    ecfg_rx_loopback_mode => ecfg_rx_loopback_mode,
    ecfg_cclk_en => ecfg_cclk_en,
    ecfg_cclk_div => ecfg_cclk_div,
    ecfg_cclk_pllcfg => ecfg_cclk_pllcfg,
    ecfg_coreid => ecfg_coreid,
    ecfg_dataout => ecfg_dataout,
    mi_clk => mi_clk,
    mi_rst => mi_rst,
    mi_en => mi_en,
    mi_we => mi_we,
    mi_addr => mi_addr,
    mi_din => mi_din,
    hw_reset => hw_reset,
    ecfg_datain => ecfg_datain
  );
-- INST_TAG_END ------ End INSTANTIATION Template ---------

