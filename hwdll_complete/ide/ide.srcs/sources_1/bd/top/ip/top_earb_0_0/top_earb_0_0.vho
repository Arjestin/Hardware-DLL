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

-- IP VLNV: adapteva.com:Adapteva:earb:1.0
-- IP Revision: 4

-- The following code must appear in the VHDL architecture header.

------------- Begin Cut here for COMPONENT Declaration ------ COMP_TAG
COMPONENT top_earb_0_0
  PORT (
    emwr_empty : IN STD_LOGIC;
    emrq_rd_en : OUT STD_LOGIC;
    emrr_rd_en : OUT STD_LOGIC;
    emm_tx_access : OUT STD_LOGIC;
    emm_tx_write : OUT STD_LOGIC;
    emm_tx_datamode : OUT STD_LOGIC_VECTOR(1 DOWNTO 0);
    emm_tx_ctrlmode : OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
    emm_tx_dstaddr : OUT STD_LOGIC_VECTOR(31 DOWNTO 0);
    emm_tx_srcaddr : OUT STD_LOGIC_VECTOR(31 DOWNTO 0);
    emm_tx_data : OUT STD_LOGIC_VECTOR(31 DOWNTO 0);
    clock : IN STD_LOGIC;
    reset : IN STD_LOGIC;
    emwr_rd_data : IN STD_LOGIC_VECTOR(102 DOWNTO 0);
    emrq_rd_data : IN STD_LOGIC_VECTOR(102 DOWNTO 0);
    emwr_rd_en : OUT STD_LOGIC;
    emrq_empty : IN STD_LOGIC;
    emrr_rd_data : IN STD_LOGIC_VECTOR(102 DOWNTO 0);
    emrr_empty : IN STD_LOGIC;
    emm_tx_rd_wait : IN STD_LOGIC;
    emm_tx_wr_wait : IN STD_LOGIC;
    emtx_ack : IN STD_LOGIC
  );
END COMPONENT;
-- COMP_TAG_END ------ End COMPONENT Declaration ------------

-- The following code must appear in the VHDL architecture
-- body. Substitute your own instance name and net names.

------------- Begin Cut here for INSTANTIATION Template ----- INST_TAG
your_instance_name : top_earb_0_0
  PORT MAP (
    emwr_empty => emwr_empty,
    emrq_rd_en => emrq_rd_en,
    emrr_rd_en => emrr_rd_en,
    emm_tx_access => emm_tx_access,
    emm_tx_write => emm_tx_write,
    emm_tx_datamode => emm_tx_datamode,
    emm_tx_ctrlmode => emm_tx_ctrlmode,
    emm_tx_dstaddr => emm_tx_dstaddr,
    emm_tx_srcaddr => emm_tx_srcaddr,
    emm_tx_data => emm_tx_data,
    clock => clock,
    reset => reset,
    emwr_rd_data => emwr_rd_data,
    emrq_rd_data => emrq_rd_data,
    emwr_rd_en => emwr_rd_en,
    emrq_empty => emrq_empty,
    emrr_rd_data => emrr_rd_data,
    emrr_empty => emrr_empty,
    emm_tx_rd_wait => emm_tx_rd_wait,
    emm_tx_wr_wait => emm_tx_wr_wait,
    emtx_ack => emtx_ack
  );
-- INST_TAG_END ------ End INSTANTIATION Template ---------

