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

-- IP VLNV: adapteva.com:Adapteva:edistrib:1.0
-- IP Revision: 5

-- The following code must appear in the VHDL architecture header.

------------- Begin Cut here for COMPONENT Declaration ------ COMP_TAG
COMPONENT top_edistrib_0_0
  PORT (
    ems_dir_rd_wait : OUT STD_LOGIC;
    ems_dir_wr_wait : OUT STD_LOGIC;
    emwr_wr_data : OUT STD_LOGIC_VECTOR(102 DOWNTO 0);
    emwr_wr_en : OUT STD_LOGIC;
    emrq_wr_data : OUT STD_LOGIC_VECTOR(102 DOWNTO 0);
    emrq_wr_en : OUT STD_LOGIC;
    emrr_wr_data : OUT STD_LOGIC_VECTOR(102 DOWNTO 0);
    emrr_wr_en : OUT STD_LOGIC;
    rxlclk : IN STD_LOGIC;
    ems_dir_access : IN STD_LOGIC;
    ems_dir_write : IN STD_LOGIC;
    ems_dir_datamode : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
    ems_dir_ctrlmode : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
    ems_dir_dstaddr : IN STD_LOGIC_VECTOR(31 DOWNTO 0);
    ems_dir_srcaddr : IN STD_LOGIC_VECTOR(31 DOWNTO 0);
    ems_dir_data : IN STD_LOGIC_VECTOR(31 DOWNTO 0);
    ems_mmu_access : IN STD_LOGIC;
    ems_mmu_write : IN STD_LOGIC;
    ems_mmu_datamode : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
    ems_mmu_ctrlmode : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
    ems_mmu_dstaddr : IN STD_LOGIC_VECTOR(31 DOWNTO 0);
    ems_mmu_srcaddr : IN STD_LOGIC_VECTOR(31 DOWNTO 0);
    ems_mmu_data : IN STD_LOGIC_VECTOR(31 DOWNTO 0);
    emwr_full : IN STD_LOGIC;
    emwr_prog_full : IN STD_LOGIC;
    emrq_full : IN STD_LOGIC;
    emrq_prog_full : IN STD_LOGIC;
    emrr_full : IN STD_LOGIC;
    emrr_prog_full : IN STD_LOGIC;
    ecfg_rx_enable : IN STD_LOGIC;
    ecfg_rx_mmu_mode : IN STD_LOGIC
  );
END COMPONENT;
-- COMP_TAG_END ------ End COMPONENT Declaration ------------

-- The following code must appear in the VHDL architecture
-- body. Substitute your own instance name and net names.

------------- Begin Cut here for INSTANTIATION Template ----- INST_TAG
your_instance_name : top_edistrib_0_0
  PORT MAP (
    ems_dir_rd_wait => ems_dir_rd_wait,
    ems_dir_wr_wait => ems_dir_wr_wait,
    emwr_wr_data => emwr_wr_data,
    emwr_wr_en => emwr_wr_en,
    emrq_wr_data => emrq_wr_data,
    emrq_wr_en => emrq_wr_en,
    emrr_wr_data => emrr_wr_data,
    emrr_wr_en => emrr_wr_en,
    rxlclk => rxlclk,
    ems_dir_access => ems_dir_access,
    ems_dir_write => ems_dir_write,
    ems_dir_datamode => ems_dir_datamode,
    ems_dir_ctrlmode => ems_dir_ctrlmode,
    ems_dir_dstaddr => ems_dir_dstaddr,
    ems_dir_srcaddr => ems_dir_srcaddr,
    ems_dir_data => ems_dir_data,
    ems_mmu_access => ems_mmu_access,
    ems_mmu_write => ems_mmu_write,
    ems_mmu_datamode => ems_mmu_datamode,
    ems_mmu_ctrlmode => ems_mmu_ctrlmode,
    ems_mmu_dstaddr => ems_mmu_dstaddr,
    ems_mmu_srcaddr => ems_mmu_srcaddr,
    ems_mmu_data => ems_mmu_data,
    emwr_full => emwr_full,
    emwr_prog_full => emwr_prog_full,
    emrq_full => emrq_full,
    emrq_prog_full => emrq_prog_full,
    emrr_full => emrr_full,
    emrr_prog_full => emrr_prog_full,
    ecfg_rx_enable => ecfg_rx_enable,
    ecfg_rx_mmu_mode => ecfg_rx_mmu_mode
  );
-- INST_TAG_END ------ End INSTANTIATION Template ---------

