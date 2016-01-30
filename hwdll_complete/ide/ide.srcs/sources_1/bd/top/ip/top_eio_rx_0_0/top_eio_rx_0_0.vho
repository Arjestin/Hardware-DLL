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

-- IP VLNV: adapteva.com:Adapteva:eio_rx:1.0
-- IP Revision: 9

-- The following code must appear in the VHDL architecture header.

------------- Begin Cut here for COMPONENT Declaration ------ COMP_TAG
COMPONENT top_eio_rx_0_0
  PORT (
    RX_WR_WAIT_P : OUT STD_LOGIC;
    RX_WR_WAIT_N : OUT STD_LOGIC;
    RX_RD_WAIT_P : OUT STD_LOGIC;
    RX_RD_WAIT_N : OUT STD_LOGIC;
    rxlclk_p : OUT STD_LOGIC;
    rxframe_p : OUT STD_LOGIC_VECTOR(7 DOWNTO 0);
    rxdata_p : OUT STD_LOGIC_VECTOR(63 DOWNTO 0);
    ecfg_datain : OUT STD_LOGIC_VECTOR(10 DOWNTO 0);
    RX_LCLK_P : IN STD_LOGIC;
    RX_LCLK_N : IN STD_LOGIC;
    reset : IN STD_LOGIC;
    ioreset : IN STD_LOGIC;
    RX_FRAME_P : IN STD_LOGIC;
    RX_FRAME_N : IN STD_LOGIC;
    RX_DATA_P : IN STD_LOGIC_VECTOR(7 DOWNTO 0);
    RX_DATA_N : IN STD_LOGIC_VECTOR(7 DOWNTO 0);
    rx_wr_wait : IN STD_LOGIC;
    rx_rd_wait : IN STD_LOGIC;
    ecfg_rx_enable : IN STD_LOGIC;
    ecfg_rx_gpio_mode : IN STD_LOGIC;
    ecfg_rx_loopback_mode : IN STD_LOGIC;
    ecfg_dataout : IN STD_LOGIC_VECTOR(10 DOWNTO 0);
    tx_wr_wait : IN STD_LOGIC;
    tx_rd_wait : IN STD_LOGIC;
    txlclk_p : IN STD_LOGIC;
    loopback_data : IN STD_LOGIC_VECTOR(63 DOWNTO 0);
    loopback_frame : IN STD_LOGIC_VECTOR(7 DOWNTO 0)
  );
END COMPONENT;
-- COMP_TAG_END ------ End COMPONENT Declaration ------------

-- The following code must appear in the VHDL architecture
-- body. Substitute your own instance name and net names.

------------- Begin Cut here for INSTANTIATION Template ----- INST_TAG
your_instance_name : top_eio_rx_0_0
  PORT MAP (
    RX_WR_WAIT_P => RX_WR_WAIT_P,
    RX_WR_WAIT_N => RX_WR_WAIT_N,
    RX_RD_WAIT_P => RX_RD_WAIT_P,
    RX_RD_WAIT_N => RX_RD_WAIT_N,
    rxlclk_p => rxlclk_p,
    rxframe_p => rxframe_p,
    rxdata_p => rxdata_p,
    ecfg_datain => ecfg_datain,
    RX_LCLK_P => RX_LCLK_P,
    RX_LCLK_N => RX_LCLK_N,
    reset => reset,
    ioreset => ioreset,
    RX_FRAME_P => RX_FRAME_P,
    RX_FRAME_N => RX_FRAME_N,
    RX_DATA_P => RX_DATA_P,
    RX_DATA_N => RX_DATA_N,
    rx_wr_wait => rx_wr_wait,
    rx_rd_wait => rx_rd_wait,
    ecfg_rx_enable => ecfg_rx_enable,
    ecfg_rx_gpio_mode => ecfg_rx_gpio_mode,
    ecfg_rx_loopback_mode => ecfg_rx_loopback_mode,
    ecfg_dataout => ecfg_dataout,
    tx_wr_wait => tx_wr_wait,
    tx_rd_wait => tx_rd_wait,
    txlclk_p => txlclk_p,
    loopback_data => loopback_data,
    loopback_frame => loopback_frame
  );
-- INST_TAG_END ------ End INSTANTIATION Template ---------

