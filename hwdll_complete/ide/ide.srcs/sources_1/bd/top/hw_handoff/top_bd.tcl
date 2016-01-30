
################################################################
# This is a generated script based on design: top
#
# Though there are limitations about the generated script,
# the main purpose of this utility is to make learning
# IP Integrator Tcl commands easier.
################################################################

################################################################
# Check if script is running in correct Vivado version.
################################################################
set scripts_vivado_version 2015.4
set current_vivado_version [version -short]

if { [string first $scripts_vivado_version $current_vivado_version] == -1 } {
   puts ""
   puts "ERROR: This script was generated using Vivado <$scripts_vivado_version> and is being run in <$current_vivado_version> of Vivado. Please run the script in Vivado <$scripts_vivado_version> then open the design in Vivado <$current_vivado_version>. Upgrade the design by running \"Tools => Report => Report IP Status...\", then run write_bd_tcl to create an updated script."

   return 1
}

################################################################
# START
################################################################

# To test this script, run the following commands from Vivado Tcl console:
# source top_script.tcl

# If you do not already have a project created,
# you can create a project using the following command:
#    create_project project_1 myproj -part xc7z020clg400-1

# CHECKING IF PROJECT EXISTS
if { [get_projects -quiet] eq "" } {
   puts "ERROR: Please open or create a project!"
   return 1
}



# CHANGE DESIGN NAME HERE
set design_name top

# If you do not already have an existing IP Integrator design open,
# you can create a design using the following command:
#    create_bd_design $design_name

# Creating design if needed
set errMsg ""
set nRet 0

set cur_design [current_bd_design -quiet]
set list_cells [get_bd_cells -quiet]

if { ${design_name} eq "" } {
   # USE CASES:
   #    1) Design_name not set

   set errMsg "ERROR: Please set the variable <design_name> to a non-empty value."
   set nRet 1

} elseif { ${cur_design} ne "" && ${list_cells} eq "" } {
   # USE CASES:
   #    2): Current design opened AND is empty AND names same.
   #    3): Current design opened AND is empty AND names diff; design_name NOT in project.
   #    4): Current design opened AND is empty AND names diff; design_name exists in project.

   if { $cur_design ne $design_name } {
      puts "INFO: Changing value of <design_name> from <$design_name> to <$cur_design> since current design is empty."
      set design_name [get_property NAME $cur_design]
   }
   puts "INFO: Constructing design in IPI design <$cur_design>..."

} elseif { ${cur_design} ne "" && $list_cells ne "" && $cur_design eq $design_name } {
   # USE CASES:
   #    5) Current design opened AND has components AND same names.

   set errMsg "ERROR: Design <$design_name> already exists in your project, please set the variable <design_name> to another value."
   set nRet 1
} elseif { [get_files -quiet ${design_name}.bd] ne "" } {
   # USE CASES: 
   #    6) Current opened design, has components, but diff names, design_name exists in project.
   #    7) No opened design, design_name exists in project.

   set errMsg "ERROR: Design <$design_name> already exists in your project, please set the variable <design_name> to another value."
   set nRet 2

} else {
   # USE CASES:
   #    8) No opened design, design_name not in project.
   #    9) Current opened design, has components, but diff names, design_name not in project.

   puts "INFO: Currently there is no design <$design_name> in project, so creating one..."

   create_bd_design $design_name

   puts "INFO: Making design <$design_name> as current_bd_design."
   current_bd_design $design_name

}

puts "INFO: Currently the variable <design_name> is equal to \"$design_name\"."

if { $nRet != 0 } {
   puts $errMsg
   return $nRet
}

##################################################################
# DESIGN PROCs
##################################################################


# Hierarchical cell: elink2
proc create_hier_cell_elink2 { parentCell nameHier } {

  if { $parentCell eq "" || $nameHier eq "" } {
     puts "ERROR: create_hier_cell_elink2() - Empty argument(s)!"
     return
  }

  # Get object for parentCell
  set parentObj [get_bd_cells $parentCell]
  if { $parentObj == "" } {
     puts "ERROR: Unable to find parent cell <$parentCell>!"
     return
  }

  # Make sure parentObj is hier blk
  set parentType [get_property TYPE $parentObj]
  if { $parentType ne "hier" } {
     puts "ERROR: Parent <$parentObj> has TYPE = <$parentType>. Expected to be <hier>."
     return
  }

  # Save current instance; Restore later
  set oldCurInst [current_bd_instance .]

  # Set parent object as current
  current_bd_instance $parentObj

  # Create cell and set as current instance
  set hier_obj [create_bd_cell -type hier $nameHier]
  current_bd_instance $hier_obj

  # Create interface pins
  create_bd_intf_pin -mode Master -vlnv adapteva.com:Adapteva:eMesh_rtl:1.0 EMM_TOMMU
  create_bd_intf_pin -mode Slave -vlnv adapteva.com:Adapteva:eMesh_rtl:1.0 EMS_FROMMMU
  create_bd_intf_pin -mode Master -vlnv xilinx.com:interface:aximm_rtl:1.0 M00_AXI
  create_bd_intf_pin -mode Slave -vlnv adapteva.com:interface:eLink_rtl:1.0 RX
  create_bd_intf_pin -mode Slave -vlnv xilinx.com:interface:aximm_rtl:1.0 S00_AXI
  create_bd_intf_pin -mode Slave -vlnv xilinx.com:interface:aximm_rtl:1.0 S_AXI_CFG
  create_bd_intf_pin -mode Master -vlnv adapteva.com:interface:eLink_rtl:1.0 TX

  # Create pins
  create_bd_pin -dir O CCLK_N
  create_bd_pin -dir O CCLK_P
  create_bd_pin -dir O -from 0 -to 0 DSP_RESET_N
  create_bd_pin -dir I clkin
  create_bd_pin -dir I -type clk m00_axi_aclk
  create_bd_pin -dir I -from 0 -to 0 -type rst m00_axi_aresetn
  create_bd_pin -dir I -from 0 -to 0 -type rst reset
  create_bd_pin -dir I -type clk s00_axi_aclk
  create_bd_pin -dir I -from 0 -to 0 -type rst s00_axi_aresetn
  create_bd_pin -dir I -type clk s_axi_aclk
  create_bd_pin -dir I -from 0 -to 0 -type rst s_axi_aresetn

  # Create instance: axi_bram_ctrl_2, and set properties
  set axi_bram_ctrl_2 [ create_bd_cell -type ip -vlnv xilinx.com:ip:axi_bram_ctrl:4.0 axi_bram_ctrl_2 ]
  set_property -dict [ list \
CONFIG.PROTOCOL {AXI4LITE} \
CONFIG.SINGLE_PORT_BRAM {1} \
 ] $axi_bram_ctrl_2

  # Create instance: eCfg_0, and set properties
  set eCfg_0 [ create_bd_cell -type ip -vlnv adapteva.com:Adapteva:eCfg:1.0 eCfg_0 ]
  set_property -dict [ list \
CONFIG.E_VERSION {0x01010303} \
 ] $eCfg_0

  # Create instance: earb_0, and set properties
  set earb_0 [ create_bd_cell -type ip -vlnv adapteva.com:Adapteva:earb:1.0 earb_0 ]

  # Create instance: ecfg_split_0, and set properties
  set ecfg_split_0 [ create_bd_cell -type ip -vlnv adapteva.com:Adapteva:ecfg_split:1.0 ecfg_split_0 ]

  # Create instance: eclock_0, and set properties
  set eclock_0 [ create_bd_cell -type ip -vlnv adapteva.com:Adapteva:eclock:1.0 eclock_0 ]

  # Create instance: edistrib_0, and set properties
  set edistrib_0 [ create_bd_cell -type ip -vlnv adapteva.com:Adapteva:edistrib:1.0 edistrib_0 ]
  set_property -dict [ list \
CONFIG.C_READ_TAG_ADDR {0x810} \
 ] $edistrib_0

  # Create instance: eio_rx_0, and set properties
  set eio_rx_0 [ create_bd_cell -type ip -vlnv adapteva.com:Adapteva:eio_rx:1.0 eio_rx_0 ]

  # Create instance: eio_tx_0, and set properties
  set eio_tx_0 [ create_bd_cell -type ip -vlnv adapteva.com:Adapteva:eio_tx:1.0 eio_tx_0 ]

  # Create instance: emaxi_0, and set properties
  set emaxi_0 [ create_bd_cell -type ip -vlnv adapteva.com:Adapteva:emaxi:1.0 emaxi_0 ]

  # Create instance: emesh_split_0, and set properties
  set emesh_split_0 [ create_bd_cell -type ip -vlnv adapteva.com:Adapteva:emesh_split:1.0 emesh_split_0 ]

  # Create instance: eproto_rx_0, and set properties
  set eproto_rx_0 [ create_bd_cell -type ip -vlnv adapteva.com:Adapteva:eproto_rx:1.0 eproto_rx_0 ]

  # Create instance: eproto_tx_0, and set properties
  set eproto_tx_0 [ create_bd_cell -type ip -vlnv adapteva.com:Adatpeva:eproto_tx:1.0 eproto_tx_0 ]

  # Create instance: esaxi_0, and set properties
  set esaxi_0 [ create_bd_cell -type ip -vlnv adapteva.com:Adapteva:esaxi:1.0 esaxi_0 ]

  # Create instance: fifo_103x16_rdreq, and set properties
  set fifo_103x16_rdreq [ create_bd_cell -type ip -vlnv xilinx.com:ip:fifo_generator:13.0 fifo_103x16_rdreq ]
  set_property -dict [ list \
CONFIG.Fifo_Implementation {Independent_Clocks_Distributed_RAM} \
CONFIG.Full_Threshold_Assert_Value {12} \
CONFIG.Input_Data_Width {103} \
CONFIG.Input_Depth {16} \
CONFIG.Performance_Options {First_Word_Fall_Through} \
CONFIG.Programmable_Full_Type {Single_Programmable_Full_Threshold_Constant} \
CONFIG.Use_Dout_Reset {true} \
 ] $fifo_103x16_rdreq

  # Create instance: fifo_103x16_rresp, and set properties
  set fifo_103x16_rresp [ create_bd_cell -type ip -vlnv xilinx.com:ip:fifo_generator:13.0 fifo_103x16_rresp ]
  set_property -dict [ list \
CONFIG.Fifo_Implementation {Independent_Clocks_Distributed_RAM} \
CONFIG.Full_Threshold_Assert_Value {12} \
CONFIG.Input_Data_Width {103} \
CONFIG.Input_Depth {16} \
CONFIG.Performance_Options {First_Word_Fall_Through} \
CONFIG.Programmable_Full_Type {Single_Programmable_Full_Threshold_Constant} \
CONFIG.Use_Dout_Reset {true} \
 ] $fifo_103x16_rresp

  # Create instance: fifo_103x16_write, and set properties
  set fifo_103x16_write [ create_bd_cell -type ip -vlnv xilinx.com:ip:fifo_generator:13.0 fifo_103x16_write ]
  set_property -dict [ list \
CONFIG.Fifo_Implementation {Independent_Clocks_Distributed_RAM} \
CONFIG.Full_Threshold_Assert_Value {12} \
CONFIG.Input_Data_Width {103} \
CONFIG.Input_Depth {16} \
CONFIG.Performance_Options {First_Word_Fall_Through} \
CONFIG.Programmable_Full_Type {Single_Programmable_Full_Threshold_Constant} \
CONFIG.Use_Dout_Reset {true} \
 ] $fifo_103x16_write

  # Create instance: fifo_103x32_rdreq, and set properties
  set fifo_103x32_rdreq [ create_bd_cell -type ip -vlnv xilinx.com:ip:fifo_generator:13.0 fifo_103x32_rdreq ]
  set_property -dict [ list \
CONFIG.Fifo_Implementation {Independent_Clocks_Distributed_RAM} \
CONFIG.Full_Threshold_Assert_Value {16} \
CONFIG.Input_Data_Width {103} \
CONFIG.Input_Depth {32} \
CONFIG.Performance_Options {First_Word_Fall_Through} \
CONFIG.Programmable_Full_Type {Single_Programmable_Full_Threshold_Constant} \
CONFIG.Use_Dout_Reset {false} \
 ] $fifo_103x32_rdreq

  # Create instance: fifo_103x32_rresp, and set properties
  set fifo_103x32_rresp [ create_bd_cell -type ip -vlnv xilinx.com:ip:fifo_generator:13.0 fifo_103x32_rresp ]
  set_property -dict [ list \
CONFIG.Fifo_Implementation {Independent_Clocks_Distributed_RAM} \
CONFIG.Full_Threshold_Assert_Value {16} \
CONFIG.Input_Data_Width {103} \
CONFIG.Input_Depth {32} \
CONFIG.Performance_Options {First_Word_Fall_Through} \
CONFIG.Programmable_Full_Type {Single_Programmable_Full_Threshold_Constant} \
CONFIG.Use_Dout_Reset {false} \
 ] $fifo_103x32_rresp

  # Create instance: fifo_103x32_write, and set properties
  set fifo_103x32_write [ create_bd_cell -type ip -vlnv xilinx.com:ip:fifo_generator:13.0 fifo_103x32_write ]
  set_property -dict [ list \
CONFIG.Fifo_Implementation {Independent_Clocks_Distributed_RAM} \
CONFIG.Full_Threshold_Assert_Value {16} \
CONFIG.Input_Data_Width {103} \
CONFIG.Input_Depth {32} \
CONFIG.Performance_Options {First_Word_Fall_Through} \
CONFIG.Programmable_Full_Type {Single_Programmable_Full_Threshold_Constant} \
CONFIG.Use_Dout_Reset {false} \
 ] $fifo_103x32_write

  # Create instance: util_vector_logic_0, and set properties
  set util_vector_logic_0 [ create_bd_cell -type ip -vlnv xilinx.com:ip:util_vector_logic:2.0 util_vector_logic_0 ]
  set_property -dict [ list \
CONFIG.C_OPERATION {not} \
CONFIG.C_SIZE {1} \
 ] $util_vector_logic_0

  # Create interface connections
  connect_bd_intf_net -intf_net Conn1 [get_bd_intf_pins EMM_TOMMU] [get_bd_intf_pins emesh_split_0/emm1]
  connect_bd_intf_net -intf_net Conn2 [get_bd_intf_pins EMS_FROMMMU] [get_bd_intf_pins edistrib_0/ems_mmu]
  connect_bd_intf_net -intf_net Conn3 [get_bd_intf_pins M00_AXI] [get_bd_intf_pins emaxi_0/M00_AXI]
  connect_bd_intf_net -intf_net RX_1 [get_bd_intf_pins RX] [get_bd_intf_pins eio_rx_0/RX]
  connect_bd_intf_net -intf_net S00_AXI_1 [get_bd_intf_pins S00_AXI] [get_bd_intf_pins esaxi_0/S00_AXI]
  connect_bd_intf_net -intf_net S_AXI_REGS_1 [get_bd_intf_pins S_AXI_CFG] [get_bd_intf_pins axi_bram_ctrl_2/S_AXI]
  connect_bd_intf_net -intf_net axi_bram_ctrl_2_BRAM_PORTA [get_bd_intf_pins axi_bram_ctrl_2/BRAM_PORTA] [get_bd_intf_pins eCfg_0/mi]
  connect_bd_intf_net -intf_net eCfg_0_ecfg [get_bd_intf_pins eCfg_0/ecfg] [get_bd_intf_pins ecfg_split_0/slvcfg]
  connect_bd_intf_net -intf_net eCfg_0_ecfg_cclk [get_bd_intf_pins eCfg_0/ecfg_cclk] [get_bd_intf_pins eclock_0/ecfg_cclk]
  connect_bd_intf_net -intf_net earb_0_emm_tx [get_bd_intf_pins earb_0/emm_tx] [get_bd_intf_pins eproto_tx_0/emtx]
  connect_bd_intf_net -intf_net earb_0_emrq [get_bd_intf_pins earb_0/emrq] [get_bd_intf_pins fifo_103x16_rdreq/FIFO_READ]
  connect_bd_intf_net -intf_net earb_0_emrr [get_bd_intf_pins earb_0/emrr] [get_bd_intf_pins fifo_103x16_rresp/FIFO_READ]
  connect_bd_intf_net -intf_net earb_0_emwr [get_bd_intf_pins earb_0/emwr] [get_bd_intf_pins fifo_103x16_write/FIFO_READ]
  connect_bd_intf_net -intf_net ecfg_split_0_mcfg0 [get_bd_intf_pins ecfg_split_0/mcfg0] [get_bd_intf_pins eio_rx_0/ecfg]
  connect_bd_intf_net -intf_net ecfg_split_0_mcfg1 [get_bd_intf_pins ecfg_split_0/mcfg1] [get_bd_intf_pins eio_tx_0/ecfg]
  connect_bd_intf_net -intf_net ecfg_split_0_mcfg2 [get_bd_intf_pins ecfg_split_0/mcfg2] [get_bd_intf_pins edistrib_0/ecfg]
  connect_bd_intf_net -intf_net ecfg_split_0_mcfg3 [get_bd_intf_pins ecfg_split_0/mcfg3] [get_bd_intf_pins esaxi_0/ecfg]
  connect_bd_intf_net -intf_net edistrib_0_emrq [get_bd_intf_pins edistrib_0/emrq] [get_bd_intf_pins fifo_103x32_rdreq/FIFO_WRITE]
  connect_bd_intf_net -intf_net edistrib_0_emrr [get_bd_intf_pins edistrib_0/emrr] [get_bd_intf_pins fifo_103x32_rresp/FIFO_WRITE]
  connect_bd_intf_net -intf_net edistrib_0_emwr [get_bd_intf_pins edistrib_0/emwr] [get_bd_intf_pins fifo_103x32_write/FIFO_WRITE]
  connect_bd_intf_net -intf_net eio_tx_0_TX [get_bd_intf_pins TX] [get_bd_intf_pins eio_tx_0/TX]
  connect_bd_intf_net -intf_net emaxi_0_emrq [get_bd_intf_pins emaxi_0/emrq] [get_bd_intf_pins fifo_103x32_rdreq/FIFO_READ]
  connect_bd_intf_net -intf_net emaxi_0_emrr [get_bd_intf_pins emaxi_0/emrr] [get_bd_intf_pins fifo_103x16_rresp/FIFO_WRITE]
  connect_bd_intf_net -intf_net emaxi_0_emwr [get_bd_intf_pins emaxi_0/emwr] [get_bd_intf_pins fifo_103x32_write/FIFO_READ]
  connect_bd_intf_net -intf_net emesh_split_0_emm0 [get_bd_intf_pins edistrib_0/ems_dir] [get_bd_intf_pins emesh_split_0/emm0]
  connect_bd_intf_net -intf_net eproto_rx_0_emrx [get_bd_intf_pins emesh_split_0/ems] [get_bd_intf_pins eproto_rx_0/emrx]
  connect_bd_intf_net -intf_net esaxi_0_emrq [get_bd_intf_pins esaxi_0/emrq] [get_bd_intf_pins fifo_103x16_rdreq/FIFO_WRITE]
  connect_bd_intf_net -intf_net esaxi_0_emrr [get_bd_intf_pins esaxi_0/emrr] [get_bd_intf_pins fifo_103x32_rresp/FIFO_READ]
  connect_bd_intf_net -intf_net esaxi_0_emwr [get_bd_intf_pins esaxi_0/emwr] [get_bd_intf_pins fifo_103x16_write/FIFO_WRITE]

  # Create port connections
  connect_bd_net -net aresetn_1 [get_bd_pins s_axi_aresetn] [get_bd_pins axi_bram_ctrl_2/s_axi_aresetn]
  connect_bd_net -net clkin_1 [get_bd_pins clkin] [get_bd_pins eclock_0/clkin]
  connect_bd_net -net ecfg_split_0_mcfg4_sw_reset [get_bd_pins ecfg_split_0/mcfg4_sw_reset] [get_bd_pins util_vector_logic_0/Op1]
  connect_bd_net -net eclock_0_CCLK_N [get_bd_pins CCLK_N] [get_bd_pins eclock_0/CCLK_N]
  connect_bd_net -net eclock_0_CCLK_P [get_bd_pins CCLK_P] [get_bd_pins eclock_0/CCLK_P]
  connect_bd_net -net eclock_0_lclk_out [get_bd_pins eclock_0/lclk_out] [get_bd_pins eio_tx_0/txlclk_out]
  connect_bd_net -net eclock_0_lclk_p [get_bd_pins earb_0/clock] [get_bd_pins eclock_0/lclk_p] [get_bd_pins eio_rx_0/txlclk_p] [get_bd_pins eio_tx_0/txlclk_p] [get_bd_pins eproto_tx_0/txlclk_p] [get_bd_pins fifo_103x16_rdreq/rd_clk] [get_bd_pins fifo_103x16_rresp/rd_clk] [get_bd_pins fifo_103x16_write/rd_clk]
  connect_bd_net -net eclock_0_lclk_s [get_bd_pins eclock_0/lclk_s] [get_bd_pins eio_tx_0/txlclk_s]
  connect_bd_net -net eio_rx_0_rxdata_p [get_bd_pins eio_rx_0/rxdata_p] [get_bd_pins eproto_rx_0/rxdata_p]
  connect_bd_net -net eio_rx_0_rxframe_p [get_bd_pins eio_rx_0/rxframe_p] [get_bd_pins eproto_rx_0/rxframe_p]
  connect_bd_net -net eio_rx_0_rxlclk_p [get_bd_pins edistrib_0/rxlclk] [get_bd_pins eio_rx_0/rxlclk_p] [get_bd_pins eproto_rx_0/rxlclk_p] [get_bd_pins fifo_103x32_rdreq/wr_clk] [get_bd_pins fifo_103x32_rresp/wr_clk] [get_bd_pins fifo_103x32_write/wr_clk]
  connect_bd_net -net eio_tx_0_tx_rd_wait [get_bd_pins eio_rx_0/tx_rd_wait] [get_bd_pins eio_tx_0/tx_rd_wait] [get_bd_pins eproto_tx_0/tx_rd_wait]
  connect_bd_net -net eio_tx_0_tx_wr_wait [get_bd_pins eio_rx_0/tx_wr_wait] [get_bd_pins eio_tx_0/tx_wr_wait] [get_bd_pins eproto_tx_0/tx_wr_wait]
  connect_bd_net -net eproto_rx_0_rx_rd_wait [get_bd_pins eio_rx_0/rx_rd_wait] [get_bd_pins eproto_rx_0/rx_rd_wait]
  connect_bd_net -net eproto_rx_0_rx_wr_wait [get_bd_pins eio_rx_0/rx_wr_wait] [get_bd_pins eproto_rx_0/rx_wr_wait]
  connect_bd_net -net eproto_tx_0_emtx_ack [get_bd_pins earb_0/emtx_ack] [get_bd_pins eproto_tx_0/emtx_ack]
  connect_bd_net -net eproto_tx_0_txdata_p [get_bd_pins eio_rx_0/loopback_data] [get_bd_pins eio_tx_0/txdata_p] [get_bd_pins eproto_tx_0/txdata_p]
  connect_bd_net -net eproto_tx_0_txframe_p [get_bd_pins eio_rx_0/loopback_frame] [get_bd_pins eio_tx_0/txframe_p] [get_bd_pins eproto_tx_0/txframe_p]
  connect_bd_net -net fifo_103x16_rdreq_prog_full [get_bd_pins esaxi_0/emrq_prog_full] [get_bd_pins fifo_103x16_rdreq/prog_full]
  connect_bd_net -net fifo_103x16_rresp_prog_full [get_bd_pins emaxi_0/emrr_prog_full] [get_bd_pins fifo_103x16_rresp/prog_full]
  connect_bd_net -net fifo_103x16_write_prog_full [get_bd_pins esaxi_0/emwr_prog_full] [get_bd_pins fifo_103x16_write/prog_full]
  connect_bd_net -net fifo_103x32_0_prog_full [get_bd_pins edistrib_0/emwr_prog_full] [get_bd_pins fifo_103x32_write/prog_full]
  connect_bd_net -net fifo_103x32_1_prog_full [get_bd_pins edistrib_0/emrr_prog_full] [get_bd_pins fifo_103x32_rresp/prog_full]
  connect_bd_net -net fifo_103x32_2_prog_full [get_bd_pins edistrib_0/emrq_prog_full] [get_bd_pins fifo_103x32_rdreq/prog_full]
  connect_bd_net -net m00_axi_aclk_1 [get_bd_pins m00_axi_aclk] [get_bd_pins emaxi_0/m00_axi_aclk] [get_bd_pins fifo_103x16_rresp/wr_clk] [get_bd_pins fifo_103x32_rdreq/rd_clk] [get_bd_pins fifo_103x32_write/rd_clk]
  connect_bd_net -net m00_axi_aresetn_1 [get_bd_pins m00_axi_aresetn] [get_bd_pins emaxi_0/m00_axi_aresetn]
  connect_bd_net -net reset_1 [get_bd_pins reset] [get_bd_pins eCfg_0/hw_reset] [get_bd_pins earb_0/reset] [get_bd_pins eclock_0/reset] [get_bd_pins eio_rx_0/ioreset] [get_bd_pins eio_rx_0/reset] [get_bd_pins eio_tx_0/ioreset] [get_bd_pins eio_tx_0/reset] [get_bd_pins eproto_rx_0/reset] [get_bd_pins eproto_tx_0/reset] [get_bd_pins fifo_103x16_rdreq/rst] [get_bd_pins fifo_103x16_rresp/rst] [get_bd_pins fifo_103x16_write/rst] [get_bd_pins fifo_103x32_rdreq/rst] [get_bd_pins fifo_103x32_rresp/rst] [get_bd_pins fifo_103x32_write/rst]
  connect_bd_net -net s00_axi_aclk_1 [get_bd_pins s00_axi_aclk] [get_bd_pins esaxi_0/s00_axi_aclk] [get_bd_pins fifo_103x16_rdreq/wr_clk] [get_bd_pins fifo_103x16_write/wr_clk] [get_bd_pins fifo_103x32_rresp/rd_clk]
  connect_bd_net -net s00_axi_aresetn_1 [get_bd_pins s00_axi_aresetn] [get_bd_pins esaxi_0/s00_axi_aresetn]
  connect_bd_net -net s_axi_aclk_1 [get_bd_pins s_axi_aclk] [get_bd_pins axi_bram_ctrl_2/s_axi_aclk]
  connect_bd_net -net util_vector_logic_0_Res [get_bd_pins DSP_RESET_N] [get_bd_pins util_vector_logic_0/Res]

  # Restore current instance
  current_bd_instance $oldCurInst
}

# Hierarchical cell: static_logic
proc create_hier_cell_static_logic { parentCell nameHier } {

  if { $parentCell eq "" || $nameHier eq "" } {
     puts "ERROR: create_hier_cell_static_logic() - Empty argument(s)!"
     return
  }

  # Get object for parentCell
  set parentObj [get_bd_cells $parentCell]
  if { $parentObj == "" } {
     puts "ERROR: Unable to find parent cell <$parentCell>!"
     return
  }

  # Make sure parentObj is hier blk
  set parentType [get_property TYPE $parentObj]
  if { $parentType ne "hier" } {
     puts "ERROR: Parent <$parentObj> has TYPE = <$parentType>. Expected to be <hier>."
     return
  }

  # Save current instance; Restore later
  set oldCurInst [current_bd_instance .]

  # Set parent object as current
  current_bd_instance $parentObj

  # Create cell and set as current instance
  set hier_obj [create_bd_cell -type hier $nameHier]
  current_bd_instance $hier_obj

  # Create interface pins
  create_bd_intf_pin -mode Master -vlnv xilinx.com:interface:ddrx_rtl:1.0 DDR
  create_bd_intf_pin -mode Master -vlnv xilinx.com:display_processing_system7:fixedio_rtl:1.0 FIXED_IO
  create_bd_intf_pin -mode Master -vlnv xilinx.com:interface:aximm_rtl:1.0 M00_AXI
  create_bd_intf_pin -mode Master -vlnv xilinx.com:interface:aximm_rtl:1.0 M01_AXI
  create_bd_intf_pin -mode Master -vlnv xilinx.com:interface:aximm_rtl:1.0 M02_AXI
  create_bd_intf_pin -mode Master -vlnv xilinx.com:interface:aximm_rtl:1.0 M03_AXI
  create_bd_intf_pin -mode Master -vlnv xilinx.com:interface:aximm_rtl:1.0 M04_AXI
  create_bd_intf_pin -mode Master -vlnv xilinx.com:interface:aximm_rtl:1.0 M05_AXI
  create_bd_intf_pin -mode Master -vlnv xilinx.com:interface:aximm_rtl:1.0 M06_AXI
  create_bd_intf_pin -mode Master -vlnv xilinx.com:interface:aximm_rtl:1.0 M07_AXI
  create_bd_intf_pin -mode Master -vlnv xilinx.com:interface:aximm_rtl:1.0 M08_AXI
  create_bd_intf_pin -mode Master -vlnv xilinx.com:interface:aximm_rtl:1.0 M09_AXI
  create_bd_intf_pin -mode Master -vlnv xilinx.com:interface:aximm_rtl:1.0 M10_AXI
  create_bd_intf_pin -mode Master -vlnv xilinx.com:interface:aximm_rtl:1.0 M11_AXI
  create_bd_intf_pin -mode Master -vlnv xilinx.com:interface:aximm_rtl:1.0 M12_AXI
  create_bd_intf_pin -mode Master -vlnv xilinx.com:interface:aximm_rtl:1.0 M13_AXI
  create_bd_intf_pin -mode Master -vlnv xilinx.com:interface:aximm_rtl:1.0 M14_AXI
  create_bd_intf_pin -mode Master -vlnv xilinx.com:interface:aximm_rtl:1.0 M15_AXI
  create_bd_intf_pin -mode Slave -vlnv adapteva.com:interface:eLink_rtl:1.0 RX
  create_bd_intf_pin -mode Master -vlnv adapteva.com:interface:eLink_rtl:1.0 TX

  # Create pins
  create_bd_pin -dir O CCLK_N
  create_bd_pin -dir O CCLK_P
  create_bd_pin -dir O -from 0 -to 0 DSP_RESET_N
  create_bd_pin -dir O -type clk FCLK_CLK0
  create_bd_pin -dir IO -from 23 -to 0 GPIO_N
  create_bd_pin -dir IO -from 23 -to 0 GPIO_P
  create_bd_pin -dir IO I2C_SCL
  create_bd_pin -dir IO I2C_SDA
  create_bd_pin -dir O -from 0 -to 0 -type rst aresetn

  # Create instance: axi_bram_ctrl_0, and set properties
  set axi_bram_ctrl_0 [ create_bd_cell -type ip -vlnv xilinx.com:ip:axi_bram_ctrl:4.0 axi_bram_ctrl_0 ]
  set_property -dict [ list \
CONFIG.ECC_TYPE {0} \
CONFIG.PROTOCOL {AXI4LITE} \
 ] $axi_bram_ctrl_0

  # Create instance: axi_interconnect_0, and set properties
  set axi_interconnect_0 [ create_bd_cell -type ip -vlnv xilinx.com:ip:axi_interconnect:2.1 axi_interconnect_0 ]
  set_property -dict [ list \
CONFIG.NUM_MI {18} \
 ] $axi_interconnect_0

  # Create instance: axi_protocol_converter_0, and set properties
  set axi_protocol_converter_0 [ create_bd_cell -type ip -vlnv xilinx.com:ip:axi_protocol_converter:2.1 axi_protocol_converter_0 ]
  set_property -dict [ list \
CONFIG.TRANSLATION_MODE {0} \
 ] $axi_protocol_converter_0

  # Create instance: axi_protocol_converter_1, and set properties
  set axi_protocol_converter_1 [ create_bd_cell -type ip -vlnv xilinx.com:ip:axi_protocol_converter:2.1 axi_protocol_converter_1 ]
  set_property -dict [ list \
CONFIG.TRANSLATION_MODE {2} \
 ] $axi_protocol_converter_1

  # Create instance: axi_protocol_converter_2, and set properties
  set axi_protocol_converter_2 [ create_bd_cell -type ip -vlnv xilinx.com:ip:axi_protocol_converter:2.1 axi_protocol_converter_2 ]

  # Create instance: blk_mem_gen_0, and set properties
  set blk_mem_gen_0 [ create_bd_cell -type ip -vlnv xilinx.com:ip:blk_mem_gen:8.3 blk_mem_gen_0 ]
  set_property -dict [ list \
CONFIG.Enable_B {Use_ENB_Pin} \
CONFIG.Memory_Type {True_Dual_Port_RAM} \
CONFIG.Port_B_Clock {100} \
CONFIG.Port_B_Enable_Rate {100} \
CONFIG.Port_B_Write_Rate {50} \
CONFIG.Use_RSTB_Pin {true} \
 ] $blk_mem_gen_0

  # Create instance: elink2
  create_hier_cell_elink2 $hier_obj elink2

  # Create instance: parallella_gpio_emio_0, and set properties
  set parallella_gpio_emio_0 [ create_bd_cell -type ip -vlnv adapteva.com:Adapteva:parallella_gpio_emio:1.0 parallella_gpio_emio_0 ]
  set_property -dict [ list \
CONFIG.NUM_GPIO_PAIRS {24} \
 ] $parallella_gpio_emio_0

  # Create instance: parallella_i2c_0, and set properties
  set parallella_i2c_0 [ create_bd_cell -type ip -vlnv adapteva.com:Adapteva:parallella_i2c:1.0 parallella_i2c_0 ]

  # Create instance: proc_sys_reset_0, and set properties
  set proc_sys_reset_0 [ create_bd_cell -type ip -vlnv xilinx.com:ip:proc_sys_reset:5.0 proc_sys_reset_0 ]

  # Create instance: processing_system7_0, and set properties
  set processing_system7_0 [ create_bd_cell -type ip -vlnv xilinx.com:ip:processing_system7:5.5 processing_system7_0 ]
  set_property -dict [ list \
CONFIG.PCW_ENET0_ENET0_IO {MIO 16 .. 27} \
CONFIG.PCW_ENET0_GRP_MDIO_ENABLE {1} \
CONFIG.PCW_ENET0_PERIPHERAL_ENABLE {1} \
CONFIG.PCW_EN_CLK3_PORT {1} \
CONFIG.PCW_FPGA0_PERIPHERAL_FREQMHZ {100} \
CONFIG.PCW_FPGA3_PERIPHERAL_FREQMHZ {100} \
CONFIG.PCW_GPIO_EMIO_GPIO_ENABLE {1} \
CONFIG.PCW_GPIO_MIO_GPIO_ENABLE {1} \
CONFIG.PCW_I2C0_PERIPHERAL_ENABLE {1} \
CONFIG.PCW_PRESET_BANK1_VOLTAGE {LVCMOS 1.8V} \
CONFIG.PCW_QSPI_PERIPHERAL_ENABLE {1} \
CONFIG.PCW_SD1_PERIPHERAL_ENABLE {1} \
CONFIG.PCW_SD1_SD1_IO {MIO 10 .. 15} \
CONFIG.PCW_SDIO_PERIPHERAL_FREQMHZ {50} \
CONFIG.PCW_UART1_PERIPHERAL_ENABLE {1} \
CONFIG.PCW_UART1_UART1_IO {MIO 8 .. 9} \
CONFIG.PCW_UIPARAM_DDR_BOARD_DELAY0 {.434} \
CONFIG.PCW_UIPARAM_DDR_BOARD_DELAY1 {.398} \
CONFIG.PCW_UIPARAM_DDR_BOARD_DELAY2 {.410} \
CONFIG.PCW_UIPARAM_DDR_BOARD_DELAY3 {.455} \
CONFIG.PCW_UIPARAM_DDR_CL {9} \
CONFIG.PCW_UIPARAM_DDR_CWL {9.00} \
CONFIG.PCW_UIPARAM_DDR_DEVICE_CAPACITY {8192 MBits} \
CONFIG.PCW_UIPARAM_DDR_DQS_TO_CLK_DELAY_0 {.315} \
CONFIG.PCW_UIPARAM_DDR_DQS_TO_CLK_DELAY_1 {.391} \
CONFIG.PCW_UIPARAM_DDR_DQS_TO_CLK_DELAY_2 {.374} \
CONFIG.PCW_UIPARAM_DDR_DQS_TO_CLK_DELAY_3 {.271} \
CONFIG.PCW_UIPARAM_DDR_DRAM_WIDTH {32 Bits} \
CONFIG.PCW_UIPARAM_DDR_FREQ_MHZ {400} \
CONFIG.PCW_UIPARAM_DDR_PARTNO {Custom} \
CONFIG.PCW_UIPARAM_DDR_TRAIN_DATA_EYE {1} \
CONFIG.PCW_UIPARAM_DDR_TRAIN_READ_GATE {1} \
CONFIG.PCW_UIPARAM_DDR_TRAIN_WRITE_LEVEL {1} \
CONFIG.PCW_UIPARAM_DDR_T_FAW {50} \
CONFIG.PCW_UIPARAM_DDR_T_RAS_MIN {40} \
CONFIG.PCW_UIPARAM_DDR_T_RC {60} \
CONFIG.PCW_UIPARAM_DDR_T_RCD {9} \
CONFIG.PCW_UIPARAM_DDR_T_RP {9} \
CONFIG.PCW_UIPARAM_DDR_USE_INTERNAL_VREF {1} \
CONFIG.PCW_USB0_PERIPHERAL_ENABLE {1} \
CONFIG.PCW_USB1_PERIPHERAL_ENABLE {1} \
CONFIG.PCW_USE_M_AXI_GP0 {1} \
CONFIG.PCW_USE_M_AXI_GP1 {1} \
CONFIG.PCW_USE_S_AXI_HP1 {1} \
 ] $processing_system7_0

  # Create interface connections
  create_bd_intf_net EMS_FROMMMU_1
  connect_bd_intf_net -intf_net [get_bd_intf_nets EMS_FROMMMU_1] [get_bd_intf_pins elink2/EMM_TOMMU] [get_bd_intf_pins elink2/EMS_FROMMMU]
  connect_bd_intf_net -intf_net RX_1 [get_bd_intf_pins RX] [get_bd_intf_pins elink2/RX]
  connect_bd_intf_net -intf_net S00_AXI_1 [get_bd_intf_pins axi_interconnect_0/S00_AXI] [get_bd_intf_pins processing_system7_0/M_AXI_GP0]
  connect_bd_intf_net -intf_net axi_bram_ctrl_0_BRAM_PORTA [get_bd_intf_pins axi_bram_ctrl_0/BRAM_PORTA] [get_bd_intf_pins blk_mem_gen_0/BRAM_PORTA]
  connect_bd_intf_net -intf_net axi_bram_ctrl_0_BRAM_PORTB [get_bd_intf_pins axi_bram_ctrl_0/BRAM_PORTB] [get_bd_intf_pins blk_mem_gen_0/BRAM_PORTB]
  connect_bd_intf_net -intf_net axi_interconnect_0_M00_AXI [get_bd_intf_pins M00_AXI] [get_bd_intf_pins axi_interconnect_0/M00_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_0_M01_AXI [get_bd_intf_pins M01_AXI] [get_bd_intf_pins axi_interconnect_0/M01_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_0_M02_AXI [get_bd_intf_pins M02_AXI] [get_bd_intf_pins axi_interconnect_0/M02_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_0_M03_AXI [get_bd_intf_pins M03_AXI] [get_bd_intf_pins axi_interconnect_0/M03_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_0_M04_AXI [get_bd_intf_pins M04_AXI] [get_bd_intf_pins axi_interconnect_0/M04_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_0_M05_AXI [get_bd_intf_pins M05_AXI] [get_bd_intf_pins axi_interconnect_0/M05_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_0_M06_AXI [get_bd_intf_pins M06_AXI] [get_bd_intf_pins axi_interconnect_0/M06_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_0_M07_AXI [get_bd_intf_pins M07_AXI] [get_bd_intf_pins axi_interconnect_0/M07_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_0_M08_AXI [get_bd_intf_pins M08_AXI] [get_bd_intf_pins axi_interconnect_0/M08_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_0_M09_AXI [get_bd_intf_pins M09_AXI] [get_bd_intf_pins axi_interconnect_0/M09_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_0_M10_AXI [get_bd_intf_pins M10_AXI] [get_bd_intf_pins axi_interconnect_0/M10_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_0_M11_AXI [get_bd_intf_pins M11_AXI] [get_bd_intf_pins axi_interconnect_0/M11_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_0_M12_AXI [get_bd_intf_pins M12_AXI] [get_bd_intf_pins axi_interconnect_0/M12_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_0_M13_AXI [get_bd_intf_pins M13_AXI] [get_bd_intf_pins axi_interconnect_0/M13_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_0_M14_AXI [get_bd_intf_pins M14_AXI] [get_bd_intf_pins axi_interconnect_0/M14_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_0_M15_AXI [get_bd_intf_pins M15_AXI] [get_bd_intf_pins axi_interconnect_0/M15_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_0_M16_AXI [get_bd_intf_pins axi_bram_ctrl_0/S_AXI] [get_bd_intf_pins axi_interconnect_0/M16_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_0_M17_AXI [get_bd_intf_pins axi_interconnect_0/M17_AXI] [get_bd_intf_pins axi_protocol_converter_1/S_AXI]
  connect_bd_intf_net -intf_net axi_protocol_converter_0_M_AXI [get_bd_intf_pins axi_protocol_converter_0/M_AXI] [get_bd_intf_pins processing_system7_0/S_AXI_HP1]
  connect_bd_intf_net -intf_net axi_protocol_converter_1_M_AXI [get_bd_intf_pins axi_protocol_converter_1/M_AXI] [get_bd_intf_pins elink2/S_AXI_CFG]
  connect_bd_intf_net -intf_net axi_protocol_converter_2_M_AXI [get_bd_intf_pins axi_protocol_converter_2/M_AXI] [get_bd_intf_pins elink2/S00_AXI]
  connect_bd_intf_net -intf_net elink2_M00_AXI [get_bd_intf_pins axi_protocol_converter_0/S_AXI] [get_bd_intf_pins elink2/M00_AXI]
  connect_bd_intf_net -intf_net elink2_TX [get_bd_intf_pins TX] [get_bd_intf_pins elink2/TX]
  connect_bd_intf_net -intf_net processing_system7_0_DDR [get_bd_intf_pins DDR] [get_bd_intf_pins processing_system7_0/DDR]
  connect_bd_intf_net -intf_net processing_system7_0_FIXED_IO [get_bd_intf_pins FIXED_IO] [get_bd_intf_pins processing_system7_0/FIXED_IO]
  connect_bd_intf_net -intf_net processing_system7_0_IIC_0 [get_bd_intf_pins parallella_i2c_0/I2C] [get_bd_intf_pins processing_system7_0/IIC_0]
  connect_bd_intf_net -intf_net processing_system7_0_M_AXI_GP1 [get_bd_intf_pins axi_protocol_converter_2/S_AXI] [get_bd_intf_pins processing_system7_0/M_AXI_GP1]

  # Create port connections
  connect_bd_net -net ARESETN_1 [get_bd_pins axi_interconnect_0/ARESETN] [get_bd_pins proc_sys_reset_0/interconnect_aresetn]
  connect_bd_net -net Net [get_bd_pins GPIO_P] [get_bd_pins parallella_gpio_emio_0/GPIO_P]
  connect_bd_net -net Net1 [get_bd_pins GPIO_N] [get_bd_pins parallella_gpio_emio_0/GPIO_N]
  connect_bd_net -net Net2 [get_bd_pins I2C_SDA] [get_bd_pins parallella_i2c_0/I2C_SDA]
  connect_bd_net -net Net3 [get_bd_pins I2C_SCL] [get_bd_pins parallella_i2c_0/I2C_SCL]
  connect_bd_net -net elink2_CCLK_N [get_bd_pins CCLK_N] [get_bd_pins elink2/CCLK_N]
  connect_bd_net -net elink2_CCLK_P [get_bd_pins CCLK_P] [get_bd_pins elink2/CCLK_P]
  connect_bd_net -net elink2_mcfg4_sw_reset [get_bd_pins DSP_RESET_N] [get_bd_pins elink2/DSP_RESET_N]
  connect_bd_net -net parallella_gpio_emio_0_PS_GPIO_I [get_bd_pins parallella_gpio_emio_0/PS_GPIO_I] [get_bd_pins processing_system7_0/GPIO_I]
  connect_bd_net -net proc_sys_reset_0_peripheral_aresetn [get_bd_pins aresetn] [get_bd_pins axi_bram_ctrl_0/s_axi_aresetn] [get_bd_pins axi_interconnect_0/M00_ARESETN] [get_bd_pins axi_interconnect_0/M01_ARESETN] [get_bd_pins axi_interconnect_0/M02_ARESETN] [get_bd_pins axi_interconnect_0/M03_ARESETN] [get_bd_pins axi_interconnect_0/M04_ARESETN] [get_bd_pins axi_interconnect_0/M05_ARESETN] [get_bd_pins axi_interconnect_0/M06_ARESETN] [get_bd_pins axi_interconnect_0/M07_ARESETN] [get_bd_pins axi_interconnect_0/M08_ARESETN] [get_bd_pins axi_interconnect_0/M09_ARESETN] [get_bd_pins axi_interconnect_0/M10_ARESETN] [get_bd_pins axi_interconnect_0/M11_ARESETN] [get_bd_pins axi_interconnect_0/M12_ARESETN] [get_bd_pins axi_interconnect_0/M13_ARESETN] [get_bd_pins axi_interconnect_0/M14_ARESETN] [get_bd_pins axi_interconnect_0/M15_ARESETN] [get_bd_pins axi_interconnect_0/M16_ARESETN] [get_bd_pins axi_interconnect_0/M17_ARESETN] [get_bd_pins axi_interconnect_0/S00_ARESETN] [get_bd_pins axi_protocol_converter_0/aresetn] [get_bd_pins axi_protocol_converter_1/aresetn] [get_bd_pins axi_protocol_converter_2/aresetn] [get_bd_pins elink2/m00_axi_aresetn] [get_bd_pins elink2/s00_axi_aresetn] [get_bd_pins elink2/s_axi_aresetn] [get_bd_pins proc_sys_reset_0/peripheral_aresetn]
  connect_bd_net -net proc_sys_reset_0_peripheral_reset [get_bd_pins elink2/reset] [get_bd_pins proc_sys_reset_0/peripheral_reset]
  connect_bd_net -net processing_system7_0_FCLK_CLK0 [get_bd_pins FCLK_CLK0] [get_bd_pins axi_bram_ctrl_0/s_axi_aclk] [get_bd_pins axi_interconnect_0/ACLK] [get_bd_pins axi_interconnect_0/M00_ACLK] [get_bd_pins axi_interconnect_0/M01_ACLK] [get_bd_pins axi_interconnect_0/M02_ACLK] [get_bd_pins axi_interconnect_0/M03_ACLK] [get_bd_pins axi_interconnect_0/M04_ACLK] [get_bd_pins axi_interconnect_0/M05_ACLK] [get_bd_pins axi_interconnect_0/M06_ACLK] [get_bd_pins axi_interconnect_0/M07_ACLK] [get_bd_pins axi_interconnect_0/M08_ACLK] [get_bd_pins axi_interconnect_0/M09_ACLK] [get_bd_pins axi_interconnect_0/M10_ACLK] [get_bd_pins axi_interconnect_0/M11_ACLK] [get_bd_pins axi_interconnect_0/M12_ACLK] [get_bd_pins axi_interconnect_0/M13_ACLK] [get_bd_pins axi_interconnect_0/M14_ACLK] [get_bd_pins axi_interconnect_0/M15_ACLK] [get_bd_pins axi_interconnect_0/M16_ACLK] [get_bd_pins axi_interconnect_0/M17_ACLK] [get_bd_pins axi_interconnect_0/S00_ACLK] [get_bd_pins axi_protocol_converter_0/aclk] [get_bd_pins axi_protocol_converter_1/aclk] [get_bd_pins axi_protocol_converter_2/aclk] [get_bd_pins elink2/clkin] [get_bd_pins elink2/m00_axi_aclk] [get_bd_pins elink2/s00_axi_aclk] [get_bd_pins elink2/s_axi_aclk] [get_bd_pins proc_sys_reset_0/slowest_sync_clk] [get_bd_pins processing_system7_0/FCLK_CLK0] [get_bd_pins processing_system7_0/M_AXI_GP0_ACLK] [get_bd_pins processing_system7_0/M_AXI_GP1_ACLK] [get_bd_pins processing_system7_0/S_AXI_HP1_ACLK]
  connect_bd_net -net processing_system7_0_FCLK_RESET0_N [get_bd_pins proc_sys_reset_0/ext_reset_in] [get_bd_pins processing_system7_0/FCLK_RESET0_N]
  connect_bd_net -net processing_system7_0_GPIO_O [get_bd_pins parallella_gpio_emio_0/PS_GPIO_O] [get_bd_pins processing_system7_0/GPIO_O]
  connect_bd_net -net processing_system7_0_GPIO_T [get_bd_pins parallella_gpio_emio_0/PS_GPIO_T] [get_bd_pins processing_system7_0/GPIO_T]

  # Restore current instance
  current_bd_instance $oldCurInst
}

# Hierarchical cell: reconfigurable_logic
proc create_hier_cell_reconfigurable_logic { parentCell nameHier } {

  if { $parentCell eq "" || $nameHier eq "" } {
     puts "ERROR: create_hier_cell_reconfigurable_logic() - Empty argument(s)!"
     return
  }

  # Get object for parentCell
  set parentObj [get_bd_cells $parentCell]
  if { $parentObj == "" } {
     puts "ERROR: Unable to find parent cell <$parentCell>!"
     return
  }

  # Make sure parentObj is hier blk
  set parentType [get_property TYPE $parentObj]
  if { $parentType ne "hier" } {
     puts "ERROR: Parent <$parentObj> has TYPE = <$parentType>. Expected to be <hier>."
     return
  }

  # Save current instance; Restore later
  set oldCurInst [current_bd_instance .]

  # Set parent object as current
  current_bd_instance $parentObj

  # Create cell and set as current instance
  set hier_obj [create_bd_cell -type hier $nameHier]
  current_bd_instance $hier_obj

  # Create interface pins
  create_bd_intf_pin -mode Slave -vlnv xilinx.com:interface:aximm_rtl:1.0 s_axi_rm
  create_bd_intf_pin -mode Slave -vlnv xilinx.com:interface:aximm_rtl:1.0 s_axi_rm1
  create_bd_intf_pin -mode Slave -vlnv xilinx.com:interface:aximm_rtl:1.0 s_axi_rm2
  create_bd_intf_pin -mode Slave -vlnv xilinx.com:interface:aximm_rtl:1.0 s_axi_rm3
  create_bd_intf_pin -mode Slave -vlnv xilinx.com:interface:aximm_rtl:1.0 s_axi_rm4
  create_bd_intf_pin -mode Slave -vlnv xilinx.com:interface:aximm_rtl:1.0 s_axi_rm5
  create_bd_intf_pin -mode Slave -vlnv xilinx.com:interface:aximm_rtl:1.0 s_axi_rm6
  create_bd_intf_pin -mode Slave -vlnv xilinx.com:interface:aximm_rtl:1.0 s_axi_rm7
  create_bd_intf_pin -mode Slave -vlnv xilinx.com:interface:aximm_rtl:1.0 s_axi_rm8
  create_bd_intf_pin -mode Slave -vlnv xilinx.com:interface:aximm_rtl:1.0 s_axi_rm9
  create_bd_intf_pin -mode Slave -vlnv xilinx.com:interface:aximm_rtl:1.0 s_axi_rm10
  create_bd_intf_pin -mode Slave -vlnv xilinx.com:interface:aximm_rtl:1.0 s_axi_rm11
  create_bd_intf_pin -mode Slave -vlnv xilinx.com:interface:aximm_rtl:1.0 s_axi_rm12
  create_bd_intf_pin -mode Slave -vlnv xilinx.com:interface:aximm_rtl:1.0 s_axi_rm13
  create_bd_intf_pin -mode Slave -vlnv xilinx.com:interface:aximm_rtl:1.0 s_axi_rm14
  create_bd_intf_pin -mode Slave -vlnv xilinx.com:interface:aximm_rtl:1.0 s_axi_rm15

  # Create pins
  create_bd_pin -dir I -type clk ap_clk
  create_bd_pin -dir I -from 0 -to 0 -type rst ap_rst_n

  # Create instance: reconfigurable_module_00, and set properties
  set reconfigurable_module_00 [ create_bd_cell -type ip -vlnv hwdll:hls:targeted_function:1.0 reconfigurable_module_00 ]

  # Create instance: reconfigurable_module_01, and set properties
  set reconfigurable_module_01 [ create_bd_cell -type ip -vlnv hwdll:hls:targeted_function:1.0 reconfigurable_module_01 ]

  # Create instance: reconfigurable_module_02, and set properties
  set reconfigurable_module_02 [ create_bd_cell -type ip -vlnv hwdll:hls:targeted_function:1.0 reconfigurable_module_02 ]

  # Create instance: reconfigurable_module_03, and set properties
  set reconfigurable_module_03 [ create_bd_cell -type ip -vlnv hwdll:hls:targeted_function:1.0 reconfigurable_module_03 ]

  # Create instance: reconfigurable_module_04, and set properties
  set reconfigurable_module_04 [ create_bd_cell -type ip -vlnv hwdll:hls:targeted_function:1.0 reconfigurable_module_04 ]

  # Create instance: reconfigurable_module_05, and set properties
  set reconfigurable_module_05 [ create_bd_cell -type ip -vlnv hwdll:hls:targeted_function:1.0 reconfigurable_module_05 ]

  # Create instance: reconfigurable_module_06, and set properties
  set reconfigurable_module_06 [ create_bd_cell -type ip -vlnv hwdll:hls:targeted_function:1.0 reconfigurable_module_06 ]

  # Create instance: reconfigurable_module_07, and set properties
  set reconfigurable_module_07 [ create_bd_cell -type ip -vlnv hwdll:hls:targeted_function:1.0 reconfigurable_module_07 ]

  # Create instance: reconfigurable_module_08, and set properties
  set reconfigurable_module_08 [ create_bd_cell -type ip -vlnv hwdll:hls:targeted_function:1.0 reconfigurable_module_08 ]

  # Create instance: reconfigurable_module_09, and set properties
  set reconfigurable_module_09 [ create_bd_cell -type ip -vlnv hwdll:hls:targeted_function:1.0 reconfigurable_module_09 ]

  # Create instance: reconfigurable_module_10, and set properties
  set reconfigurable_module_10 [ create_bd_cell -type ip -vlnv hwdll:hls:targeted_function:1.0 reconfigurable_module_10 ]

  # Create instance: reconfigurable_module_11, and set properties
  set reconfigurable_module_11 [ create_bd_cell -type ip -vlnv hwdll:hls:targeted_function:1.0 reconfigurable_module_11 ]

  # Create instance: reconfigurable_module_12, and set properties
  set reconfigurable_module_12 [ create_bd_cell -type ip -vlnv hwdll:hls:targeted_function:1.0 reconfigurable_module_12 ]

  # Create instance: reconfigurable_module_13, and set properties
  set reconfigurable_module_13 [ create_bd_cell -type ip -vlnv hwdll:hls:targeted_function:1.0 reconfigurable_module_13 ]

  # Create instance: reconfigurable_module_14, and set properties
  set reconfigurable_module_14 [ create_bd_cell -type ip -vlnv hwdll:hls:targeted_function:1.0 reconfigurable_module_14 ]

  # Create instance: reconfigurable_module_15, and set properties
  set reconfigurable_module_15 [ create_bd_cell -type ip -vlnv hwdll:hls:targeted_function:1.0 reconfigurable_module_15 ]

  # Create interface connections
  connect_bd_intf_net -intf_net axi_interconnect_0_M00_AXI [get_bd_intf_pins s_axi_rm] [get_bd_intf_pins reconfigurable_module_00/s_axi_rm]
  connect_bd_intf_net -intf_net axi_interconnect_0_M01_AXI [get_bd_intf_pins s_axi_rm1] [get_bd_intf_pins reconfigurable_module_01/s_axi_rm]
  connect_bd_intf_net -intf_net axi_interconnect_0_M02_AXI [get_bd_intf_pins s_axi_rm2] [get_bd_intf_pins reconfigurable_module_02/s_axi_rm]
  connect_bd_intf_net -intf_net axi_interconnect_0_M03_AXI [get_bd_intf_pins s_axi_rm3] [get_bd_intf_pins reconfigurable_module_03/s_axi_rm]
  connect_bd_intf_net -intf_net axi_interconnect_0_M04_AXI [get_bd_intf_pins s_axi_rm4] [get_bd_intf_pins reconfigurable_module_04/s_axi_rm]
  connect_bd_intf_net -intf_net axi_interconnect_0_M05_AXI [get_bd_intf_pins s_axi_rm5] [get_bd_intf_pins reconfigurable_module_05/s_axi_rm]
  connect_bd_intf_net -intf_net axi_interconnect_0_M06_AXI [get_bd_intf_pins s_axi_rm6] [get_bd_intf_pins reconfigurable_module_06/s_axi_rm]
  connect_bd_intf_net -intf_net axi_interconnect_0_M07_AXI [get_bd_intf_pins s_axi_rm7] [get_bd_intf_pins reconfigurable_module_07/s_axi_rm]
  connect_bd_intf_net -intf_net axi_interconnect_0_M08_AXI [get_bd_intf_pins s_axi_rm8] [get_bd_intf_pins reconfigurable_module_08/s_axi_rm]
  connect_bd_intf_net -intf_net axi_interconnect_0_M09_AXI [get_bd_intf_pins s_axi_rm9] [get_bd_intf_pins reconfigurable_module_09/s_axi_rm]
  connect_bd_intf_net -intf_net axi_interconnect_0_M10_AXI [get_bd_intf_pins s_axi_rm10] [get_bd_intf_pins reconfigurable_module_10/s_axi_rm]
  connect_bd_intf_net -intf_net axi_interconnect_0_M11_AXI [get_bd_intf_pins s_axi_rm11] [get_bd_intf_pins reconfigurable_module_11/s_axi_rm]
  connect_bd_intf_net -intf_net axi_interconnect_0_M12_AXI [get_bd_intf_pins s_axi_rm12] [get_bd_intf_pins reconfigurable_module_12/s_axi_rm]
  connect_bd_intf_net -intf_net axi_interconnect_0_M13_AXI [get_bd_intf_pins s_axi_rm13] [get_bd_intf_pins reconfigurable_module_13/s_axi_rm]
  connect_bd_intf_net -intf_net axi_interconnect_0_M14_AXI [get_bd_intf_pins s_axi_rm14] [get_bd_intf_pins reconfigurable_module_14/s_axi_rm]
  connect_bd_intf_net -intf_net axi_interconnect_0_M15_AXI [get_bd_intf_pins s_axi_rm15] [get_bd_intf_pins reconfigurable_module_15/s_axi_rm]

  # Create port connections
  connect_bd_net -net proc_sys_reset_0_peripheral_aresetn [get_bd_pins ap_rst_n] [get_bd_pins reconfigurable_module_00/ap_rst_n] [get_bd_pins reconfigurable_module_01/ap_rst_n] [get_bd_pins reconfigurable_module_02/ap_rst_n] [get_bd_pins reconfigurable_module_03/ap_rst_n] [get_bd_pins reconfigurable_module_04/ap_rst_n] [get_bd_pins reconfigurable_module_05/ap_rst_n] [get_bd_pins reconfigurable_module_06/ap_rst_n] [get_bd_pins reconfigurable_module_07/ap_rst_n] [get_bd_pins reconfigurable_module_08/ap_rst_n] [get_bd_pins reconfigurable_module_09/ap_rst_n] [get_bd_pins reconfigurable_module_10/ap_rst_n] [get_bd_pins reconfigurable_module_11/ap_rst_n] [get_bd_pins reconfigurable_module_12/ap_rst_n] [get_bd_pins reconfigurable_module_13/ap_rst_n] [get_bd_pins reconfigurable_module_14/ap_rst_n] [get_bd_pins reconfigurable_module_15/ap_rst_n]
  connect_bd_net -net processing_system7_0_FCLK_CLK0 [get_bd_pins ap_clk] [get_bd_pins reconfigurable_module_00/ap_clk] [get_bd_pins reconfigurable_module_01/ap_clk] [get_bd_pins reconfigurable_module_02/ap_clk] [get_bd_pins reconfigurable_module_03/ap_clk] [get_bd_pins reconfigurable_module_04/ap_clk] [get_bd_pins reconfigurable_module_05/ap_clk] [get_bd_pins reconfigurable_module_06/ap_clk] [get_bd_pins reconfigurable_module_07/ap_clk] [get_bd_pins reconfigurable_module_08/ap_clk] [get_bd_pins reconfigurable_module_09/ap_clk] [get_bd_pins reconfigurable_module_10/ap_clk] [get_bd_pins reconfigurable_module_11/ap_clk] [get_bd_pins reconfigurable_module_12/ap_clk] [get_bd_pins reconfigurable_module_13/ap_clk] [get_bd_pins reconfigurable_module_14/ap_clk] [get_bd_pins reconfigurable_module_15/ap_clk]

  # Restore current instance
  current_bd_instance $oldCurInst
}


# Procedure to create entire design; Provide argument to make
# procedure reusable. If parentCell is "", will use root.
proc create_root_design { parentCell } {

  if { $parentCell eq "" } {
     set parentCell [get_bd_cells /]
  }

  # Get object for parentCell
  set parentObj [get_bd_cells $parentCell]
  if { $parentObj == "" } {
     puts "ERROR: Unable to find parent cell <$parentCell>!"
     return
  }

  # Make sure parentObj is hier blk
  set parentType [get_property TYPE $parentObj]
  if { $parentType ne "hier" } {
     puts "ERROR: Parent <$parentObj> has TYPE = <$parentType>. Expected to be <hier>."
     return
  }

  # Save current instance; Restore later
  set oldCurInst [current_bd_instance .]

  # Set parent object as current
  current_bd_instance $parentObj


  # Create interface ports
  set DDR [ create_bd_intf_port -mode Master -vlnv xilinx.com:interface:ddrx_rtl:1.0 DDR ]
  set FIXED_IO [ create_bd_intf_port -mode Master -vlnv xilinx.com:display_processing_system7:fixedio_rtl:1.0 FIXED_IO ]
  set RX [ create_bd_intf_port -mode Slave -vlnv adapteva.com:interface:eLink_rtl:1.0 RX ]
  set TX [ create_bd_intf_port -mode Master -vlnv adapteva.com:interface:eLink_rtl:1.0 TX ]

  # Create ports
  set CCLK_N [ create_bd_port -dir O CCLK_N ]
  set CCLK_P [ create_bd_port -dir O CCLK_P ]
  set DSP_RESET_N [ create_bd_port -dir O -from 0 -to 0 DSP_RESET_N ]
  set GPIO_N [ create_bd_port -dir IO -from 23 -to 0 GPIO_N ]
  set GPIO_P [ create_bd_port -dir IO -from 23 -to 0 GPIO_P ]
  set I2C_SCL [ create_bd_port -dir IO I2C_SCL ]
  set I2C_SDA [ create_bd_port -dir IO I2C_SDA ]

  # Create instance: reconfigurable_logic
  create_hier_cell_reconfigurable_logic [current_bd_instance .] reconfigurable_logic

  # Create instance: static_logic
  create_hier_cell_static_logic [current_bd_instance .] static_logic

  # Create interface connections
  connect_bd_intf_net -intf_net RX_1 [get_bd_intf_ports RX] [get_bd_intf_pins static_logic/RX]
  connect_bd_intf_net -intf_net axi_interconnect_0_M00_AXI [get_bd_intf_pins reconfigurable_logic/s_axi_rm] [get_bd_intf_pins static_logic/M00_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_0_M01_AXI [get_bd_intf_pins reconfigurable_logic/s_axi_rm1] [get_bd_intf_pins static_logic/M01_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_0_M02_AXI [get_bd_intf_pins reconfigurable_logic/s_axi_rm2] [get_bd_intf_pins static_logic/M02_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_0_M03_AXI [get_bd_intf_pins reconfigurable_logic/s_axi_rm3] [get_bd_intf_pins static_logic/M03_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_0_M04_AXI [get_bd_intf_pins reconfigurable_logic/s_axi_rm4] [get_bd_intf_pins static_logic/M04_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_0_M05_AXI [get_bd_intf_pins reconfigurable_logic/s_axi_rm5] [get_bd_intf_pins static_logic/M05_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_0_M06_AXI [get_bd_intf_pins reconfigurable_logic/s_axi_rm6] [get_bd_intf_pins static_logic/M06_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_0_M07_AXI [get_bd_intf_pins reconfigurable_logic/s_axi_rm7] [get_bd_intf_pins static_logic/M07_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_0_M08_AXI [get_bd_intf_pins reconfigurable_logic/s_axi_rm8] [get_bd_intf_pins static_logic/M08_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_0_M09_AXI [get_bd_intf_pins reconfigurable_logic/s_axi_rm9] [get_bd_intf_pins static_logic/M09_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_0_M10_AXI [get_bd_intf_pins reconfigurable_logic/s_axi_rm10] [get_bd_intf_pins static_logic/M10_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_0_M11_AXI [get_bd_intf_pins reconfigurable_logic/s_axi_rm11] [get_bd_intf_pins static_logic/M11_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_0_M12_AXI [get_bd_intf_pins reconfigurable_logic/s_axi_rm12] [get_bd_intf_pins static_logic/M12_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_0_M13_AXI [get_bd_intf_pins reconfigurable_logic/s_axi_rm13] [get_bd_intf_pins static_logic/M13_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_0_M14_AXI [get_bd_intf_pins reconfigurable_logic/s_axi_rm14] [get_bd_intf_pins static_logic/M14_AXI]
  connect_bd_intf_net -intf_net axi_interconnect_0_M15_AXI [get_bd_intf_pins reconfigurable_logic/s_axi_rm15] [get_bd_intf_pins static_logic/M15_AXI]
  connect_bd_intf_net -intf_net elink2_TX [get_bd_intf_ports TX] [get_bd_intf_pins static_logic/TX]
  connect_bd_intf_net -intf_net processing_system7_0_DDR [get_bd_intf_ports DDR] [get_bd_intf_pins static_logic/DDR]
  connect_bd_intf_net -intf_net processing_system7_0_FIXED_IO [get_bd_intf_ports FIXED_IO] [get_bd_intf_pins static_logic/FIXED_IO]

  # Create port connections
  connect_bd_net -net Net [get_bd_ports GPIO_P] [get_bd_pins static_logic/GPIO_P]
  connect_bd_net -net Net1 [get_bd_ports GPIO_N] [get_bd_pins static_logic/GPIO_N]
  connect_bd_net -net Net2 [get_bd_ports I2C_SDA] [get_bd_pins static_logic/I2C_SDA]
  connect_bd_net -net Net3 [get_bd_ports I2C_SCL] [get_bd_pins static_logic/I2C_SCL]
  connect_bd_net -net elink2_CCLK_N [get_bd_ports CCLK_N] [get_bd_pins static_logic/CCLK_N]
  connect_bd_net -net elink2_CCLK_P [get_bd_ports CCLK_P] [get_bd_pins static_logic/CCLK_P]
  connect_bd_net -net elink2_mcfg4_sw_reset [get_bd_ports DSP_RESET_N] [get_bd_pins static_logic/DSP_RESET_N]
  connect_bd_net -net proc_sys_reset_0_peripheral_aresetn [get_bd_pins reconfigurable_logic/ap_rst_n] [get_bd_pins static_logic/aresetn]
  connect_bd_net -net processing_system7_0_FCLK_CLK0 [get_bd_pins reconfigurable_logic/ap_clk] [get_bd_pins static_logic/FCLK_CLK0]

  # Create address segments
  create_bd_addr_seg -range 0x2000 -offset 0x70002000 [get_bd_addr_spaces static_logic/processing_system7_0/Data] [get_bd_addr_segs static_logic/axi_bram_ctrl_0/S_AXI/Mem0] SEG_axi_bram_ctrl_0_Mem0
  create_bd_addr_seg -range 0x2000 -offset 0x70000000 [get_bd_addr_spaces static_logic/processing_system7_0/Data] [get_bd_addr_segs static_logic/elink2/axi_bram_ctrl_2/S_AXI/Mem0] SEG_axi_bram_ctrl_2_Mem0
  create_bd_addr_seg -range 0x40000000 -offset 0x80000000 [get_bd_addr_spaces static_logic/processing_system7_0/Data] [get_bd_addr_segs static_logic/elink2/esaxi_0/S00_AXI/S00_AXI_mem] SEG_esaxi_0_S00_AXI_mem
  create_bd_addr_seg -range 0x1000 -offset 0x40000000 [get_bd_addr_spaces static_logic/processing_system7_0/Data] [get_bd_addr_segs reconfigurable_logic/reconfigurable_module_00/s_axi_rm/Reg] SEG_reconfigurable_module_00_Reg
  create_bd_addr_seg -range 0x1000 -offset 0x40001000 [get_bd_addr_spaces static_logic/processing_system7_0/Data] [get_bd_addr_segs reconfigurable_logic/reconfigurable_module_01/s_axi_rm/Reg] SEG_reconfigurable_module_01_Reg
  create_bd_addr_seg -range 0x1000 -offset 0x40002000 [get_bd_addr_spaces static_logic/processing_system7_0/Data] [get_bd_addr_segs reconfigurable_logic/reconfigurable_module_02/s_axi_rm/Reg] SEG_reconfigurable_module_02_Reg
  create_bd_addr_seg -range 0x1000 -offset 0x40003000 [get_bd_addr_spaces static_logic/processing_system7_0/Data] [get_bd_addr_segs reconfigurable_logic/reconfigurable_module_03/s_axi_rm/Reg] SEG_reconfigurable_module_03_Reg
  create_bd_addr_seg -range 0x1000 -offset 0x40004000 [get_bd_addr_spaces static_logic/processing_system7_0/Data] [get_bd_addr_segs reconfigurable_logic/reconfigurable_module_04/s_axi_rm/Reg] SEG_reconfigurable_module_04_Reg
  create_bd_addr_seg -range 0x1000 -offset 0x40005000 [get_bd_addr_spaces static_logic/processing_system7_0/Data] [get_bd_addr_segs reconfigurable_logic/reconfigurable_module_05/s_axi_rm/Reg] SEG_reconfigurable_module_05_Reg
  create_bd_addr_seg -range 0x1000 -offset 0x40006000 [get_bd_addr_spaces static_logic/processing_system7_0/Data] [get_bd_addr_segs reconfigurable_logic/reconfigurable_module_06/s_axi_rm/Reg] SEG_reconfigurable_module_06_Reg
  create_bd_addr_seg -range 0x1000 -offset 0x40007000 [get_bd_addr_spaces static_logic/processing_system7_0/Data] [get_bd_addr_segs reconfigurable_logic/reconfigurable_module_07/s_axi_rm/Reg] SEG_reconfigurable_module_07_Reg
  create_bd_addr_seg -range 0x1000 -offset 0x40008000 [get_bd_addr_spaces static_logic/processing_system7_0/Data] [get_bd_addr_segs reconfigurable_logic/reconfigurable_module_08/s_axi_rm/Reg] SEG_reconfigurable_module_08_Reg
  create_bd_addr_seg -range 0x1000 -offset 0x40009000 [get_bd_addr_spaces static_logic/processing_system7_0/Data] [get_bd_addr_segs reconfigurable_logic/reconfigurable_module_09/s_axi_rm/Reg] SEG_reconfigurable_module_09_Reg
  create_bd_addr_seg -range 0x1000 -offset 0x4000A000 [get_bd_addr_spaces static_logic/processing_system7_0/Data] [get_bd_addr_segs reconfigurable_logic/reconfigurable_module_10/s_axi_rm/Reg] SEG_reconfigurable_module_10_Reg
  create_bd_addr_seg -range 0x1000 -offset 0x4000B000 [get_bd_addr_spaces static_logic/processing_system7_0/Data] [get_bd_addr_segs reconfigurable_logic/reconfigurable_module_11/s_axi_rm/Reg] SEG_reconfigurable_module_11_Reg
  create_bd_addr_seg -range 0x1000 -offset 0x4000C000 [get_bd_addr_spaces static_logic/processing_system7_0/Data] [get_bd_addr_segs reconfigurable_logic/reconfigurable_module_12/s_axi_rm/Reg] SEG_reconfigurable_module_12_Reg
  create_bd_addr_seg -range 0x1000 -offset 0x4000D000 [get_bd_addr_spaces static_logic/processing_system7_0/Data] [get_bd_addr_segs reconfigurable_logic/reconfigurable_module_13/s_axi_rm/Reg] SEG_reconfigurable_module_13_Reg
  create_bd_addr_seg -range 0x1000 -offset 0x4000E000 [get_bd_addr_spaces static_logic/processing_system7_0/Data] [get_bd_addr_segs reconfigurable_logic/reconfigurable_module_14/s_axi_rm/Reg] SEG_reconfigurable_module_14_Reg
  create_bd_addr_seg -range 0x1000 -offset 0x4000F000 [get_bd_addr_spaces static_logic/processing_system7_0/Data] [get_bd_addr_segs reconfigurable_logic/reconfigurable_module_15/s_axi_rm/Reg] SEG_reconfigurable_module_15_Reg
  create_bd_addr_seg -range 0x40000000 -offset 0x0 [get_bd_addr_spaces static_logic/elink2/emaxi_0/M00_AXI] [get_bd_addr_segs static_logic/processing_system7_0/S_AXI_HP1/HP1_DDR_LOWOCM] SEG_processing_system7_0_HP1_DDR_LOWOCM

  # Perform GUI Layout
  regenerate_bd_layout -layout_string {
   guistr: "# # String gsaved with Nlview 6.5.5  2015-06-26 bk=1.3371 VDI=38 GEI=35 GUI=JA:1.6
#  -string -flagsOSRD
preplace port RX -pg 1 -y 320 -defaultsOSRD
preplace port DDR -pg 1 -y 20 -defaultsOSRD
preplace port CCLK_N -pg 1 -y 520 -defaultsOSRD
preplace port I2C_SDA -pg 1 -y 600 -defaultsOSRD
preplace port CCLK_P -pg 1 -y 500 -defaultsOSRD
preplace port FIXED_IO -pg 1 -y 40 -defaultsOSRD
preplace port TX -pg 1 -y 480 -defaultsOSRD
preplace port I2C_SCL -pg 1 -y 620 -defaultsOSRD
preplace portBus GPIO_N -pg 1 -y 580 -defaultsOSRD
preplace portBus DSP_RESET_N -pg 1 -y 540 -defaultsOSRD
preplace portBus GPIO_P -pg 1 -y 560 -defaultsOSRD
preplace inst static_logic -pg 1 -lvl 1 -y 320 -defaultsOSRD
preplace inst reconfigurable_logic -pg 1 -lvl 2 -y 260 -defaultsOSRD
preplace netloc axi_interconnect_0_M09_AXI 1 1 1 N
preplace netloc processing_system7_0_DDR 1 1 2 NJ 20 NJ
preplace netloc elink2_CCLK_N 1 1 2 NJ 490 NJ
preplace netloc axi_interconnect_0_M13_AXI 1 1 1 N
preplace netloc axi_interconnect_0_M12_AXI 1 1 1 N
preplace netloc RX_1 1 0 1 N
preplace netloc elink2_CCLK_P 1 1 2 NJ 500 NJ
preplace netloc axi_interconnect_0_M10_AXI 1 1 1 N
preplace netloc axi_interconnect_0_M02_AXI 1 1 1 N
preplace netloc elink2_mcfg4_sw_reset 1 1 2 NJ 540 NJ
preplace netloc axi_interconnect_0_M07_AXI 1 1 1 N
preplace netloc axi_interconnect_0_M08_AXI 1 1 1 N
preplace netloc axi_interconnect_0_M04_AXI 1 1 1 N
preplace netloc axi_interconnect_0_M15_AXI 1 1 1 N
preplace netloc processing_system7_0_FIXED_IO 1 1 2 NJ 30 NJ
preplace netloc axi_interconnect_0_M05_AXI 1 1 1 N
preplace netloc axi_interconnect_0_M00_AXI 1 1 1 N
preplace netloc proc_sys_reset_0_peripheral_aresetn 1 1 1 250
preplace netloc axi_interconnect_0_M01_AXI 1 1 1 N
preplace netloc processing_system7_0_FCLK_CLK0 1 1 1 240
preplace netloc Net1 1 1 2 NJ 550 NJ
preplace netloc Net 1 1 2 NJ 520 NJ
preplace netloc axi_interconnect_0_M14_AXI 1 1 1 N
preplace netloc axi_interconnect_0_M06_AXI 1 1 1 N
preplace netloc elink2_TX 1 1 2 NJ 480 NJ
preplace netloc Net2 1 1 2 NJ 570 NJ
preplace netloc axi_interconnect_0_M11_AXI 1 1 1 N
preplace netloc axi_interconnect_0_M03_AXI 1 1 1 N
preplace netloc Net3 1 1 2 NJ 590 NJ
levelinfo -pg 1 -20 110 400 550 -top 0 -bot 640
",
}

  # Restore current instance
  current_bd_instance $oldCurInst

  save_bd_design
}
# End of create_root_design()


##################################################################
# MAIN FLOW
##################################################################

create_root_design ""


