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

-- IP VLNV: adapteva.com:Adapteva:ecfg_split:1.0
-- IP Revision: 3

-- The following code must appear in the VHDL architecture header.

------------- Begin Cut here for COMPONENT Declaration ------ COMP_TAG
COMPONENT top_ecfg_split_0_0
  PORT (
    slvcfg_datain : OUT STD_LOGIC_VECTOR(10 DOWNTO 0);
    mcfg0_sw_reset : OUT STD_LOGIC;
    mcfg0_tx_enable : OUT STD_LOGIC;
    mcfg0_tx_mmu_mode : OUT STD_LOGIC;
    mcfg0_tx_gpio_mode : OUT STD_LOGIC;
    mcfg0_tx_ctrl_mode : OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
    mcfg0_tx_clkdiv : OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
    mcfg0_rx_enable : OUT STD_LOGIC;
    mcfg0_rx_mmu_mode : OUT STD_LOGIC;
    mcfg0_rx_gpio_mode : OUT STD_LOGIC;
    mcfg0_rx_loopback_mode : OUT STD_LOGIC;
    mcfg0_coreid : OUT STD_LOGIC_VECTOR(11 DOWNTO 0);
    mcfg0_dataout : OUT STD_LOGIC_VECTOR(10 DOWNTO 0);
    mcfg1_sw_reset : OUT STD_LOGIC;
    mcfg1_tx_enable : OUT STD_LOGIC;
    mcfg1_tx_mmu_mode : OUT STD_LOGIC;
    mcfg1_tx_gpio_mode : OUT STD_LOGIC;
    mcfg1_tx_ctrl_mode : OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
    mcfg1_tx_clkdiv : OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
    mcfg1_rx_enable : OUT STD_LOGIC;
    mcfg1_rx_mmu_mode : OUT STD_LOGIC;
    mcfg1_rx_gpio_mode : OUT STD_LOGIC;
    mcfg1_rx_loopback_mode : OUT STD_LOGIC;
    mcfg1_coreid : OUT STD_LOGIC_VECTOR(11 DOWNTO 0);
    mcfg1_dataout : OUT STD_LOGIC_VECTOR(10 DOWNTO 0);
    mcfg2_sw_reset : OUT STD_LOGIC;
    mcfg2_tx_enable : OUT STD_LOGIC;
    mcfg2_tx_mmu_mode : OUT STD_LOGIC;
    mcfg2_tx_gpio_mode : OUT STD_LOGIC;
    mcfg2_tx_ctrl_mode : OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
    mcfg2_tx_clkdiv : OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
    mcfg2_rx_enable : OUT STD_LOGIC;
    mcfg2_rx_mmu_mode : OUT STD_LOGIC;
    mcfg2_rx_gpio_mode : OUT STD_LOGIC;
    mcfg2_rx_loopback_mode : OUT STD_LOGIC;
    mcfg2_coreid : OUT STD_LOGIC_VECTOR(11 DOWNTO 0);
    mcfg2_dataout : OUT STD_LOGIC_VECTOR(10 DOWNTO 0);
    mcfg3_sw_reset : OUT STD_LOGIC;
    mcfg3_tx_enable : OUT STD_LOGIC;
    mcfg3_tx_mmu_mode : OUT STD_LOGIC;
    mcfg3_tx_gpio_mode : OUT STD_LOGIC;
    mcfg3_tx_ctrl_mode : OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
    mcfg3_tx_clkdiv : OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
    mcfg3_rx_enable : OUT STD_LOGIC;
    mcfg3_rx_mmu_mode : OUT STD_LOGIC;
    mcfg3_rx_gpio_mode : OUT STD_LOGIC;
    mcfg3_rx_loopback_mode : OUT STD_LOGIC;
    mcfg3_coreid : OUT STD_LOGIC_VECTOR(11 DOWNTO 0);
    mcfg3_dataout : OUT STD_LOGIC_VECTOR(10 DOWNTO 0);
    mcfg4_sw_reset : OUT STD_LOGIC;
    mcfg4_tx_enable : OUT STD_LOGIC;
    mcfg4_tx_mmu_mode : OUT STD_LOGIC;
    mcfg4_tx_gpio_mode : OUT STD_LOGIC;
    mcfg4_tx_ctrl_mode : OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
    mcfg4_tx_clkdiv : OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
    mcfg4_rx_enable : OUT STD_LOGIC;
    mcfg4_rx_mmu_mode : OUT STD_LOGIC;
    mcfg4_rx_gpio_mode : OUT STD_LOGIC;
    mcfg4_rx_loopback_mode : OUT STD_LOGIC;
    mcfg4_coreid : OUT STD_LOGIC_VECTOR(11 DOWNTO 0);
    mcfg4_dataout : OUT STD_LOGIC_VECTOR(10 DOWNTO 0);
    slvcfg_sw_reset : IN STD_LOGIC;
    slvcfg_tx_enable : IN STD_LOGIC;
    slvcfg_tx_mmu_mode : IN STD_LOGIC;
    slvcfg_tx_gpio_mode : IN STD_LOGIC;
    slvcfg_tx_ctrl_mode : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
    slvcfg_tx_clkdiv : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
    slvcfg_rx_enable : IN STD_LOGIC;
    slvcfg_rx_mmu_mode : IN STD_LOGIC;
    slvcfg_rx_gpio_mode : IN STD_LOGIC;
    slvcfg_rx_loopback_mode : IN STD_LOGIC;
    slvcfg_coreid : IN STD_LOGIC_VECTOR(11 DOWNTO 0);
    slvcfg_dataout : IN STD_LOGIC_VECTOR(10 DOWNTO 0);
    mcfg0_datain : IN STD_LOGIC_VECTOR(10 DOWNTO 0);
    mcfg1_datain : IN STD_LOGIC_VECTOR(10 DOWNTO 0);
    mcfg2_datain : IN STD_LOGIC_VECTOR(10 DOWNTO 0);
    mcfg3_datain : IN STD_LOGIC_VECTOR(10 DOWNTO 0);
    mcfg4_datain : IN STD_LOGIC_VECTOR(10 DOWNTO 0)
  );
END COMPONENT;
-- COMP_TAG_END ------ End COMPONENT Declaration ------------

-- The following code must appear in the VHDL architecture
-- body. Substitute your own instance name and net names.

------------- Begin Cut here for INSTANTIATION Template ----- INST_TAG
your_instance_name : top_ecfg_split_0_0
  PORT MAP (
    slvcfg_datain => slvcfg_datain,
    mcfg0_sw_reset => mcfg0_sw_reset,
    mcfg0_tx_enable => mcfg0_tx_enable,
    mcfg0_tx_mmu_mode => mcfg0_tx_mmu_mode,
    mcfg0_tx_gpio_mode => mcfg0_tx_gpio_mode,
    mcfg0_tx_ctrl_mode => mcfg0_tx_ctrl_mode,
    mcfg0_tx_clkdiv => mcfg0_tx_clkdiv,
    mcfg0_rx_enable => mcfg0_rx_enable,
    mcfg0_rx_mmu_mode => mcfg0_rx_mmu_mode,
    mcfg0_rx_gpio_mode => mcfg0_rx_gpio_mode,
    mcfg0_rx_loopback_mode => mcfg0_rx_loopback_mode,
    mcfg0_coreid => mcfg0_coreid,
    mcfg0_dataout => mcfg0_dataout,
    mcfg1_sw_reset => mcfg1_sw_reset,
    mcfg1_tx_enable => mcfg1_tx_enable,
    mcfg1_tx_mmu_mode => mcfg1_tx_mmu_mode,
    mcfg1_tx_gpio_mode => mcfg1_tx_gpio_mode,
    mcfg1_tx_ctrl_mode => mcfg1_tx_ctrl_mode,
    mcfg1_tx_clkdiv => mcfg1_tx_clkdiv,
    mcfg1_rx_enable => mcfg1_rx_enable,
    mcfg1_rx_mmu_mode => mcfg1_rx_mmu_mode,
    mcfg1_rx_gpio_mode => mcfg1_rx_gpio_mode,
    mcfg1_rx_loopback_mode => mcfg1_rx_loopback_mode,
    mcfg1_coreid => mcfg1_coreid,
    mcfg1_dataout => mcfg1_dataout,
    mcfg2_sw_reset => mcfg2_sw_reset,
    mcfg2_tx_enable => mcfg2_tx_enable,
    mcfg2_tx_mmu_mode => mcfg2_tx_mmu_mode,
    mcfg2_tx_gpio_mode => mcfg2_tx_gpio_mode,
    mcfg2_tx_ctrl_mode => mcfg2_tx_ctrl_mode,
    mcfg2_tx_clkdiv => mcfg2_tx_clkdiv,
    mcfg2_rx_enable => mcfg2_rx_enable,
    mcfg2_rx_mmu_mode => mcfg2_rx_mmu_mode,
    mcfg2_rx_gpio_mode => mcfg2_rx_gpio_mode,
    mcfg2_rx_loopback_mode => mcfg2_rx_loopback_mode,
    mcfg2_coreid => mcfg2_coreid,
    mcfg2_dataout => mcfg2_dataout,
    mcfg3_sw_reset => mcfg3_sw_reset,
    mcfg3_tx_enable => mcfg3_tx_enable,
    mcfg3_tx_mmu_mode => mcfg3_tx_mmu_mode,
    mcfg3_tx_gpio_mode => mcfg3_tx_gpio_mode,
    mcfg3_tx_ctrl_mode => mcfg3_tx_ctrl_mode,
    mcfg3_tx_clkdiv => mcfg3_tx_clkdiv,
    mcfg3_rx_enable => mcfg3_rx_enable,
    mcfg3_rx_mmu_mode => mcfg3_rx_mmu_mode,
    mcfg3_rx_gpio_mode => mcfg3_rx_gpio_mode,
    mcfg3_rx_loopback_mode => mcfg3_rx_loopback_mode,
    mcfg3_coreid => mcfg3_coreid,
    mcfg3_dataout => mcfg3_dataout,
    mcfg4_sw_reset => mcfg4_sw_reset,
    mcfg4_tx_enable => mcfg4_tx_enable,
    mcfg4_tx_mmu_mode => mcfg4_tx_mmu_mode,
    mcfg4_tx_gpio_mode => mcfg4_tx_gpio_mode,
    mcfg4_tx_ctrl_mode => mcfg4_tx_ctrl_mode,
    mcfg4_tx_clkdiv => mcfg4_tx_clkdiv,
    mcfg4_rx_enable => mcfg4_rx_enable,
    mcfg4_rx_mmu_mode => mcfg4_rx_mmu_mode,
    mcfg4_rx_gpio_mode => mcfg4_rx_gpio_mode,
    mcfg4_rx_loopback_mode => mcfg4_rx_loopback_mode,
    mcfg4_coreid => mcfg4_coreid,
    mcfg4_dataout => mcfg4_dataout,
    slvcfg_sw_reset => slvcfg_sw_reset,
    slvcfg_tx_enable => slvcfg_tx_enable,
    slvcfg_tx_mmu_mode => slvcfg_tx_mmu_mode,
    slvcfg_tx_gpio_mode => slvcfg_tx_gpio_mode,
    slvcfg_tx_ctrl_mode => slvcfg_tx_ctrl_mode,
    slvcfg_tx_clkdiv => slvcfg_tx_clkdiv,
    slvcfg_rx_enable => slvcfg_rx_enable,
    slvcfg_rx_mmu_mode => slvcfg_rx_mmu_mode,
    slvcfg_rx_gpio_mode => slvcfg_rx_gpio_mode,
    slvcfg_rx_loopback_mode => slvcfg_rx_loopback_mode,
    slvcfg_coreid => slvcfg_coreid,
    slvcfg_dataout => slvcfg_dataout,
    mcfg0_datain => mcfg0_datain,
    mcfg1_datain => mcfg1_datain,
    mcfg2_datain => mcfg2_datain,
    mcfg3_datain => mcfg3_datain,
    mcfg4_datain => mcfg4_datain
  );
-- INST_TAG_END ------ End INSTANTIATION Template ---------

