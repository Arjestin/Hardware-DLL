set C_TypeInfoList {{ 
"targeted_function" : [[], {"return": [[], {"scalar": "int"}] }, [{"ExternC" : 0}], [ {"input_000": [[], {"scalar": "int"}] }, {"output_000": [[],{ "pointer":  {"scalar": "int"}}] }],[],""]
}}
set moduleName targeted_function
set isCombinational 0
set isDatapathOnly 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set C_modelName {targeted_function}
set C_modelType { int 32 }
set C_modelArgList { 
	{ input_000 int 32 regular {axi_slave 0}  }
	{ output_000 int 32 regular {axi_slave 1}  }
}
set C_modelArgMapList {[ 
	{ "Name" : "input_000", "interface" : "axi_slave", "bundle":"rm","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "input_000","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}], "offset" : {"in":24}, "offset_end" : {"in":31}} , 
 	{ "Name" : "output_000", "interface" : "axi_slave", "bundle":"rm","type":"ap_vld","bitwidth" : 32, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "output_000","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}], "offset" : {"out":32}, "offset_end" : {"out":39}} , 
 	{ "Name" : "ap_return", "interface" : "axi_slave", "bundle":"rm","type":"ap_none","bitwidth" : 32,"bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "return","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 1,"step" : 0}]}]}], "offset" : {"out":16}} ]}
# RTL Port declarations: 
set portNum 20
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst_n sc_in sc_logic 1 reset -1 active_low_sync } 
	{ s_axi_rm_AWVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_rm_AWREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_rm_AWADDR sc_in sc_lv 6 signal -1 } 
	{ s_axi_rm_WVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_rm_WREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_rm_WDATA sc_in sc_lv 32 signal -1 } 
	{ s_axi_rm_WSTRB sc_in sc_lv 4 signal -1 } 
	{ s_axi_rm_ARVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_rm_ARREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_rm_ARADDR sc_in sc_lv 6 signal -1 } 
	{ s_axi_rm_RVALID sc_out sc_logic 1 signal -1 } 
	{ s_axi_rm_RREADY sc_in sc_logic 1 signal -1 } 
	{ s_axi_rm_RDATA sc_out sc_lv 32 signal -1 } 
	{ s_axi_rm_RRESP sc_out sc_lv 2 signal -1 } 
	{ s_axi_rm_BVALID sc_out sc_logic 1 signal -1 } 
	{ s_axi_rm_BREADY sc_in sc_logic 1 signal -1 } 
	{ s_axi_rm_BRESP sc_out sc_lv 2 signal -1 } 
	{ interrupt sc_out sc_logic 1 signal -1 } 
}
set NewPortList {[ 
	{ "name": "s_axi_rm_AWADDR", "direction": "in", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "rm", "role": "AWADDR" },"address":[{"name":"targeted_function","role":"start","value":"0","valid_bit":"0"},{"name":"targeted_function","role":"continue","value":"0","valid_bit":"4"},{"name":"targeted_function","role":"auto_start","value":"0","valid_bit":"7"},{"name":"input_000","role":"data","value":"24"}] },
	{ "name": "s_axi_rm_AWVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "rm", "role": "AWVALID" } },
	{ "name": "s_axi_rm_AWREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "rm", "role": "AWREADY" } },
	{ "name": "s_axi_rm_WVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "rm", "role": "WVALID" } },
	{ "name": "s_axi_rm_WREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "rm", "role": "WREADY" } },
	{ "name": "s_axi_rm_WDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "rm", "role": "WDATA" } },
	{ "name": "s_axi_rm_WSTRB", "direction": "in", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "rm", "role": "WSTRB" } },
	{ "name": "s_axi_rm_ARADDR", "direction": "in", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "rm", "role": "ARADDR" },"address":[{"name":"targeted_function","role":"start","value":"0","valid_bit":"0"},{"name":"targeted_function","role":"done","value":"0","valid_bit":"1"},{"name":"targeted_function","role":"idle","value":"0","valid_bit":"2"},{"name":"targeted_function","role":"ready","value":"0","valid_bit":"3"},{"name":"targeted_function","role":"auto_start","value":"0","valid_bit":"7"},{"name":"return","role":"data","value":"16"},{"name":"output_000","role":"data","value":"32"}, {"name":"output_000","role":"valid","value":"36","valid_bit":"0"}] },
	{ "name": "s_axi_rm_ARVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "rm", "role": "ARVALID" } },
	{ "name": "s_axi_rm_ARREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "rm", "role": "ARREADY" } },
	{ "name": "s_axi_rm_RVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "rm", "role": "RVALID" } },
	{ "name": "s_axi_rm_RREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "rm", "role": "RREADY" } },
	{ "name": "s_axi_rm_RDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "rm", "role": "RDATA" } },
	{ "name": "s_axi_rm_RRESP", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "rm", "role": "RRESP" } },
	{ "name": "s_axi_rm_BVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "rm", "role": "BVALID" } },
	{ "name": "s_axi_rm_BREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "rm", "role": "BREADY" } },
	{ "name": "s_axi_rm_BRESP", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "rm", "role": "BRESP" } }, 
 	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst_n", "role": "default" }} , 
 	{ "name": "interrupt", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "interrupt", "role": "default" }}  ]}
set Spec2ImplPortList { 
}

# RTL port scheduling information:
set fifoSchedulingInfoList { 
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}
