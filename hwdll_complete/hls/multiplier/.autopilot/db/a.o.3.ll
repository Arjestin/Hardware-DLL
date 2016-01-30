; ModuleID = 'C:/xilinx/hls/multiplier/.autopilot/db/a.o.3.bc'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"
target triple = "x86_64-w64-mingw32"

@targeted_function_str = internal unnamed_addr constant [18 x i8] c"targeted_function\00" ; [#uses=1 type=[18 x i8]*]
@p_str2 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1 ; [#uses=12 type=[1 x i8]*]
@p_str1 = private unnamed_addr constant [3 x i8] c"rm\00", align 1 ; [#uses=4 type=[3 x i8]*]
@p_str = private unnamed_addr constant [10 x i8] c"s_axilite\00", align 1 ; [#uses=4 type=[10 x i8]*]

; [#uses=0]
define i32 @targeted_function(i32 %input_000, i32 %input_001, i32* %output_000) nounwind uwtable {
  call void (...)* @_ssdm_op_SpecBitsMap(i32 %input_000) nounwind, !map !0
  call void (...)* @_ssdm_op_SpecBitsMap(i32 %input_001) nounwind, !map !6
  call void (...)* @_ssdm_op_SpecBitsMap(i32* %output_000) nounwind, !map !10
  call void (...)* @_ssdm_op_SpecBitsMap(i32 0) nounwind, !map !16
  call void (...)* @_ssdm_op_SpecTopModule([18 x i8]* @targeted_function_str) nounwind
  %input_001_read = call i32 @_ssdm_op_Read.s_axilite.i32(i32 %input_001) nounwind ; [#uses=1 type=i32]
  call void @llvm.dbg.value(metadata !{i32 %input_001_read}, i64 0, metadata !22), !dbg !31 ; [debug line = 24:43] [debug variable = input_001]
  %input_000_read = call i32 @_ssdm_op_Read.s_axilite.i32(i32 %input_000) nounwind ; [#uses=1 type=i32]
  call void @llvm.dbg.value(metadata !{i32 %input_000_read}, i64 0, metadata !32), !dbg !33 ; [debug line = 24:28] [debug variable = input_000]
  call void @llvm.dbg.value(metadata !{i32 %input_000}, i64 0, metadata !32), !dbg !33 ; [debug line = 24:28] [debug variable = input_000]
  call void @llvm.dbg.value(metadata !{i32 %input_001}, i64 0, metadata !22), !dbg !31 ; [debug line = 24:43] [debug variable = input_001]
  call void @llvm.dbg.value(metadata !{i32* %output_000}, i64 0, metadata !34), !dbg !35 ; [debug line = 24:59] [debug variable = output_000]
  call void (...)* @_ssdm_op_SpecInterface(i32* %output_000, [10 x i8]* @p_str, i32 0, i32 0, i32 0, i32 0, [3 x i8]* @p_str1, [1 x i8]* @p_str2, [1 x i8]* @p_str2, [1 x i8]* @p_str2) nounwind, !dbg !36 ; [debug line = 26:1]
  call void (...)* @_ssdm_op_SpecInterface(i32 %input_001, [10 x i8]* @p_str, i32 0, i32 0, i32 0, i32 0, [3 x i8]* @p_str1, [1 x i8]* @p_str2, [1 x i8]* @p_str2, [1 x i8]* @p_str2) nounwind, !dbg !36 ; [debug line = 26:1]
  call void (...)* @_ssdm_op_SpecInterface(i32 %input_000, [10 x i8]* @p_str, i32 0, i32 0, i32 0, i32 0, [3 x i8]* @p_str1, [1 x i8]* @p_str2, [1 x i8]* @p_str2, [1 x i8]* @p_str2) nounwind, !dbg !36 ; [debug line = 26:1]
  call void (...)* @_ssdm_op_SpecInterface(i32 0, [10 x i8]* @p_str, i32 0, i32 0, i32 0, i32 0, [3 x i8]* @p_str1, [1 x i8]* @p_str2, [1 x i8]* @p_str2, [1 x i8]* @p_str2) nounwind, !dbg !36 ; [debug line = 26:1]
  %output_000_assign = mul nsw i32 %input_001_read, %input_000_read, !dbg !38 ; [#uses=1 type=i32] [debug line = 26:2]
  call void @_ssdm_op_Write.s_axilite.i32P(i32* %output_000, i32 %output_000_assign) nounwind, !dbg !38 ; [debug line = 26:2]
  ret i32 0, !dbg !39                             ; [debug line = 27:2]
}

; [#uses=5]
declare void @llvm.dbg.value(metadata, i64, metadata) nounwind readnone

; [#uses=1]
define weak void @_ssdm_op_Write.s_axilite.i32P(i32*, i32) {
entry:
  store i32 %1, i32* %0
  ret void
}

; [#uses=1]
define weak void @_ssdm_op_SpecTopModule(...) {
entry:
  ret void
}

; [#uses=4]
define weak void @_ssdm_op_SpecInterface(...) nounwind {
entry:
  ret void
}

; [#uses=4]
define weak void @_ssdm_op_SpecBitsMap(...) {
entry:
  ret void
}

; [#uses=2]
define weak i32 @_ssdm_op_Read.s_axilite.i32(i32) {
entry:
  ret i32 %0
}

; [#uses=0]
declare i16 @_ssdm_op_HSub(...)

; [#uses=0]
declare i16 @_ssdm_op_HMul(...)

; [#uses=0]
declare i16 @_ssdm_op_HDiv(...)

; [#uses=0]
declare i16 @_ssdm_op_HAdd(...)

!hls.encrypted.func = !{}
!llvm.map.gv = !{}

!0 = metadata !{metadata !1}
!1 = metadata !{i32 0, i32 31, metadata !2}
!2 = metadata !{metadata !3}
!3 = metadata !{metadata !"input_000", metadata !4, metadata !"int", i32 0, i32 31}
!4 = metadata !{metadata !5}
!5 = metadata !{i32 0, i32 0, i32 0}
!6 = metadata !{metadata !7}
!7 = metadata !{i32 0, i32 31, metadata !8}
!8 = metadata !{metadata !9}
!9 = metadata !{metadata !"input_001", metadata !4, metadata !"int", i32 0, i32 31}
!10 = metadata !{metadata !11}
!11 = metadata !{i32 0, i32 31, metadata !12}
!12 = metadata !{metadata !13}
!13 = metadata !{metadata !"output_000", metadata !14, metadata !"int", i32 0, i32 31}
!14 = metadata !{metadata !15}
!15 = metadata !{i32 0, i32 0, i32 1}
!16 = metadata !{metadata !17}
!17 = metadata !{i32 0, i32 31, metadata !18}
!18 = metadata !{metadata !19}
!19 = metadata !{metadata !"return", metadata !20, metadata !"int", i32 0, i32 31}
!20 = metadata !{metadata !21}
!21 = metadata !{i32 0, i32 1, i32 0}
!22 = metadata !{i32 786689, metadata !23, metadata !"input_001", metadata !24, i32 33554456, metadata !27, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!23 = metadata !{i32 786478, i32 0, metadata !24, metadata !"targeted_function", metadata !"targeted_function", metadata !"", metadata !24, i32 24, metadata !25, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, i32 (i32, i32, i32*)* @targeted_function, null, null, metadata !29, i32 25} ; [ DW_TAG_subprogram ]
!24 = metadata !{i32 786473, metadata !"./targeted_functions/multiplier/targeted_function.c", metadata !"c:/xilinx", null} ; [ DW_TAG_file_type ]
!25 = metadata !{i32 786453, i32 0, metadata !"", i32 0, i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !26, i32 0, i32 0} ; [ DW_TAG_subroutine_type ]
!26 = metadata !{metadata !27, metadata !27, metadata !27, metadata !28}
!27 = metadata !{i32 786468, null, metadata !"int", null, i32 0, i64 32, i64 32, i64 0, i32 0, i32 5} ; [ DW_TAG_base_type ]
!28 = metadata !{i32 786447, null, metadata !"", null, i32 0, i64 64, i64 64, i64 0, i32 0, metadata !27} ; [ DW_TAG_pointer_type ]
!29 = metadata !{metadata !30}
!30 = metadata !{i32 786468}                      ; [ DW_TAG_base_type ]
!31 = metadata !{i32 24, i32 43, metadata !23, null}
!32 = metadata !{i32 786689, metadata !23, metadata !"input_000", metadata !24, i32 16777240, metadata !27, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!33 = metadata !{i32 24, i32 28, metadata !23, null}
!34 = metadata !{i32 786689, metadata !23, metadata !"output_000", metadata !24, i32 50331672, metadata !28, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!35 = metadata !{i32 24, i32 59, metadata !23, null}
!36 = metadata !{i32 26, i32 1, metadata !37, null}
!37 = metadata !{i32 786443, metadata !23, i32 25, i32 1, metadata !24, i32 0} ; [ DW_TAG_lexical_block ]
!38 = metadata !{i32 26, i32 2, metadata !37, null}
!39 = metadata !{i32 27, i32 2, metadata !37, null}
