// (c) Copyright 1995-2016 Xilinx, Inc. All rights reserved.
// 
// This file contains confidential and proprietary information
// of Xilinx, Inc. and is protected under U.S. and
// international copyright and other intellectual property
// laws.
// 
// DISCLAIMER
// This disclaimer is not a license and does not grant any
// rights to the materials distributed herewith. Except as
// otherwise provided in a valid license issued to you by
// Xilinx, and to the maximum extent permitted by applicable
// law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
// WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
// AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
// BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
// INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
// (2) Xilinx shall not be liable (whether in contract or tort,
// including negligence, or under any other theory of
// liability) for any loss or damage of any kind or nature
// related to, arising under or in connection with these
// materials, including for any direct, or any indirect,
// special, incidental, or consequential loss or damage
// (including loss of data, profits, goodwill, or any type of
// loss or damage suffered as a result of any action brought
// by a third party) even if such damage or loss was
// reasonably foreseeable or Xilinx had been advised of the
// possibility of the same.
// 
// CRITICAL APPLICATIONS
// Xilinx products are not designed or intended to be fail-
// safe, or for use in any application requiring fail-safe
// performance, such as life-support or safety devices or
// systems, Class III medical devices, nuclear facilities,
// applications related to the deployment of airbags, or any
// other applications that could lead to death, personal
// injury, or severe property or environmental damage
// (individually and collectively, "Critical
// Applications"). Customer assumes the sole risk and
// liability of any use of Xilinx products in Critical
// Applications, subject only to applicable laws and
// regulations governing limitations on product liability.
// 
// THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
// PART OF THIS FILE AT ALL TIMES.
// 
// DO NOT MODIFY THIS FILE.


// IP VLNV: adapteva.com:Adapteva:parallella_i2c:1.0
// IP Revision: 2

(* X_CORE_INFO = "parallella_i2c,Vivado 2015.4" *)
(* CHECK_LICENSE_TYPE = "top_parallella_i2c_0_0,parallella_i2c,{}" *)
(* DowngradeIPIdentifiedWarnings = "yes" *)
module top_parallella_i2c_0_0 (
  I2C_SDA_I,
  I2C_SCL_I,
  I2C_SDA,
  I2C_SCL,
  I2C_SDA_O,
  I2C_SDA_T,
  I2C_SCL_O,
  I2C_SCL_T
);

(* X_INTERFACE_INFO = "xilinx.com:interface:iic:1.0 I2C SDA_I" *)
output wire I2C_SDA_I;
(* X_INTERFACE_INFO = "xilinx.com:interface:iic:1.0 I2C SCL_I" *)
output wire I2C_SCL_I;
inout wire I2C_SDA;
inout wire I2C_SCL;
(* X_INTERFACE_INFO = "xilinx.com:interface:iic:1.0 I2C SDA_O" *)
input wire I2C_SDA_O;
(* X_INTERFACE_INFO = "xilinx.com:interface:iic:1.0 I2C SDA_T" *)
input wire I2C_SDA_T;
(* X_INTERFACE_INFO = "xilinx.com:interface:iic:1.0 I2C SCL_O" *)
input wire I2C_SCL_O;
(* X_INTERFACE_INFO = "xilinx.com:interface:iic:1.0 I2C SCL_T" *)
input wire I2C_SCL_T;

  parallella_i2c inst (
    .I2C_SDA_I(I2C_SDA_I),
    .I2C_SCL_I(I2C_SCL_I),
    .I2C_SDA(I2C_SDA),
    .I2C_SCL(I2C_SCL),
    .I2C_SDA_O(I2C_SDA_O),
    .I2C_SDA_T(I2C_SDA_T),
    .I2C_SCL_O(I2C_SCL_O),
    .I2C_SCL_T(I2C_SCL_T)
  );
endmodule
