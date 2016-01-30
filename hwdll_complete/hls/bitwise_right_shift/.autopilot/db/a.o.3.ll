; ModuleID = 'C:/xilinx/hls/bitwise_right_shift/.autopilot/db/a.o.3.bc'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"
target triple = "x86_64-w64-mingw32"

@targeted_function_str = internal unnamed_addr constant [18 x i8] c"targeted_function\00" ; [#uses=1 type=[18 x i8]*]
@p_str2 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1 ; [#uses=9 type=[1 x i8]*]
@p_str1 = private unnamed_addr constant [3 x i8] c"rm\00", align 1 ; [#uses=3 type=[3 x i8]*]
@p_str = private unnamed_addr constant [10 x i8] c"s_axilite\00", align 1 ; [#uses=3 type=[10 x i8]*]

; [#uses=0]
define i32 @targeted_function(i32 %input_000, i32* %output_000) nounwind uwtable {
  call void (...)* @_ssdm_op_SpecBitsMap(i32 %input_000) nounwind, !map !0
  call void (...)* @_ssdm_op_SpecBitsMap(i32* %output_000) nounwind, !map !6
  call void (...)* @_ssdm_op_SpecBitsMap(i32 0) nounwind, !map !12
  call void (...)* @_ssdm_op_SpecTopModule([18 x i8]* @targeted_function_str) nounwind
  %input_000_read = call i32 @_ssdm_op_Read.s_axilite.i32(i32 %input_000) nounwind ; [#uses=1 type=i32]
  call void @llvm.dbg.value(metadata !{i32 %input_000_read}, i64 0, metadata !18), !dbg !27 ; [debug line = 24:28] [debug variable = input_000]
  call void @llvm.dbg.value(metadata !{i32 %input_000}, i64 0, metadata !18), !dbg !27 ; [debug line = 24:28] [debug variable = input_000]
  call void @llvm.dbg.value(metadata !{i32* %output_000}, i64 0, metadata !28), !dbg !29 ; [debug line = 24:44] [debug variable = output_000]
  call void (...)* @_ssdm_op_SpecInterface(i32* %output_000, [10 x i8]* @p_str, i32 0, i32 0, i32 0, i32 0, [3 x i8]* @p_str1, [1 x i8]* @p_str2, [1 x i8]* @p_str2, [1 x i8]* @p_str2) nounwind, !dbg !30 ; [debug line = 26:1]
  call void (...)* @_ssdm_op_SpecInterface(i32 %input_000, [10 x i8]* @p_str, i32 0, i32 0, i32 0, i32 0, [3 x i8]* @p_str1, [1 x i8]* @p_str2, [1 x i8]* @p_str2, [1 x i8]* @p_str2) nounwind, !dbg !30 ; [debug line = 26:1]
  call void (...)* @_ssdm_op_SpecInterface(i32 0, [10 x i8]* @p_str, i32 0, i32 0, i32 0, i32 0, [3 x i8]* @p_str1, [1 x i8]* @p_str2, [1 x i8]* @p_str2, [1 x i8]* @p_str2) nounwind, !dbg !30 ; [debug line = 26:1]
  %tmp_1 = call i31 @_ssdm_op_PartSelect.i31.i32.i32.i32(i32 %input_000_read, i32 1, i32 31), !dbg !32 ; [#uses=1 type=i31] [debug line = 26:2]
  %output_000_assign = sext i31 %tmp_1 to i32, !dbg !32 ; [#uses=1 type=i32] [debug line = 26:2]
  call void @_ssdm_op_Write.s_axilite.i32P(i32* %output_000, i32 %output_000_assign) nounwind, !dbg !32 ; [debug line = 26:2]
  ret i32 0, !dbg !33                             ; [debug line = 27:2]
}

; [#uses=1]
declare i32 @llvm.part.select.i32(i32, i32, i32) nounwind readnone

; [#uses=3]
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

; [#uses=3]
define weak void @_ssdm_op_SpecInterface(...) nounwind {
entry:
  ret void
}

; [#uses=3]
define weak void @_ssdm_op_SpecBitsMap(...) {
entry:
  ret void
}

; [#uses=1]
define weak i32 @_ssdm_op_Read.s_axilite.i32(i32) {
entry:
  ret i32 %0
}

; [#uses=1]
define weak i31 @_ssdm_op_PartSelect.i31.i32.i32.i32(i32, i32, i32) nounwind readnone {
entry:
  %empty = call i32 @llvm.part.select.i32(i32 %0, i32 %1, i32 %2) ; [#uses=1 type=i32]
  %empty_4 = trunc i32 %empty to i31              ; [#uses=1 type=i31]
  ret i31 %empty_4
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
!9 = metadata !{metadata !"output_000", metadata !10, metadata !"int", i32 0, i32 31}
!10 = metadata !{metadata !11}
!11 = metadata !{i32 0, i32 0, i32 1}
!12 = metadata !{metadata !13}
!13 = metadata !{i32 0, i32 31, metadata !14}
!14 = metadata !{metadata !15}
!15 = metadata !{metadata !"return", metadata !16, metadata !"int", i32 0, i32 31}
!16 = metadata !{metadata !17}
!17 = metadata !{i32 0, i32 1, i32 0}
!18 = metadata !{i32 786689, metadata !19, metadata !"input_000", metadata !20, i32 16777240, metadata !23, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!19 = metadata !{i32 786478, i32 0, metadata !20, metadata !"targeted_function", metadata !"targeted_function", metadata !"", metadata !20, i32 24, metadata !21, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, i32 (i32, i32*)* @targeted_function, null, null, metadata !25, i32 25} ; [ DW_TAG_subprogram ]
!20 = metadata !{i32 786473, metadata !"./targeted_functions/bitwise_right_shift/targeted_function.c", metadata !"c:/xilinx", null} ; [ DW_TAG_file_type ]
!21 = metadata !{i32 786453, i32 0, metadata !"", i32 0, i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !22, i32 0, i32 0} ; [ DW_TAG_subroutine_type ]
!22 = metadata !{metadata !23, metadata !23, metadata !24}
!23 = metadata !{i32 786468, null, metadata !"int", null, i32 0, i64 32, i64 32, i64 0, i32 0, i32 5} ; [ DW_TAG_base_type ]
!24 = metadata !{i32 786447, null, metadata !"", null, i32 0, i64 64, i64 64, i64 0, i32 0, metadata !23} ; [ DW_TAG_pointer_type ]
!25 = metadata !{metadata !26}
!26 = metadata !{i32 786468}                      ; [ DW_TAG_base_type ]
!27 = metadata !{i32 24, i32 28, metadata !19, null}
!28 = metadata !{i32 786689, metadata !19, metadata !"output_000", metadata !20, i32 33554456, metadata !24, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!29 = metadata !{i32 24, i32 44, metadata !19, null}
!30 = metadata !{i32 26, i32 1, metadata !31, null}
!31 = metadata !{i32 786443, metadata !19, i32 25, i32 1, metadata !20, i32 0} ; [ DW_TAG_lexical_block ]
!32 = metadata !{i32 26, i32 2, metadata !31, null}
!33 = metadata !{i32 27, i32 2, metadata !31, null}
