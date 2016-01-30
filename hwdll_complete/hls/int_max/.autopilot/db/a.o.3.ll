; ModuleID = 'C:/xilinx/hls/int_max/.autopilot/db/a.o.3.bc'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"
target triple = "x86_64-w64-mingw32"

@targeted_function_str = internal unnamed_addr constant [18 x i8] c"targeted_function\00" ; [#uses=1 type=[18 x i8]*]
@p_str2 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1 ; [#uses=6 type=[1 x i8]*]
@p_str1 = private unnamed_addr constant [3 x i8] c"rm\00", align 1 ; [#uses=2 type=[3 x i8]*]
@p_str = private unnamed_addr constant [10 x i8] c"s_axilite\00", align 1 ; [#uses=2 type=[10 x i8]*]

; [#uses=0]
define i32 @targeted_function(i32* %output_000) nounwind uwtable {
  call void (...)* @_ssdm_op_SpecBitsMap(i32* %output_000) nounwind, !map !0
  call void (...)* @_ssdm_op_SpecBitsMap(i32 0) nounwind, !map !6
  call void (...)* @_ssdm_op_SpecTopModule([18 x i8]* @targeted_function_str) nounwind
  call void @llvm.dbg.value(metadata !{i32* %output_000}, i64 0, metadata !12), !dbg !21 ; [debug line = 30:29] [debug variable = output_000]
  call void (...)* @_ssdm_op_SpecInterface(i32* %output_000, [10 x i8]* @p_str, i32 0, i32 0, i32 0, i32 0, [3 x i8]* @p_str1, [1 x i8]* @p_str2, [1 x i8]* @p_str2, [1 x i8]* @p_str2) nounwind, !dbg !22 ; [debug line = 32:1]
  call void (...)* @_ssdm_op_SpecInterface(i32 0, [10 x i8]* @p_str, i32 0, i32 0, i32 0, i32 0, [3 x i8]* @p_str1, [1 x i8]* @p_str2, [1 x i8]* @p_str2, [1 x i8]* @p_str2) nounwind, !dbg !22 ; [debug line = 32:1]
  call void @_ssdm_op_Write.s_axilite.i32P(i32* %output_000, i32 2147483647) nounwind, !dbg !24 ; [debug line = 32:2]
  ret i32 0, !dbg !25                             ; [debug line = 33:2]
}

; [#uses=1]
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

; [#uses=2]
define weak void @_ssdm_op_SpecInterface(...) nounwind {
entry:
  ret void
}

; [#uses=2]
define weak void @_ssdm_op_SpecBitsMap(...) {
entry:
  ret void
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
!3 = metadata !{metadata !"output_000", metadata !4, metadata !"int", i32 0, i32 31}
!4 = metadata !{metadata !5}
!5 = metadata !{i32 0, i32 0, i32 1}
!6 = metadata !{metadata !7}
!7 = metadata !{i32 0, i32 31, metadata !8}
!8 = metadata !{metadata !9}
!9 = metadata !{metadata !"return", metadata !10, metadata !"int", i32 0, i32 31}
!10 = metadata !{metadata !11}
!11 = metadata !{i32 0, i32 1, i32 0}
!12 = metadata !{i32 786689, metadata !13, metadata !"output_000", metadata !14, i32 16777246, metadata !18, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!13 = metadata !{i32 786478, i32 0, metadata !14, metadata !"targeted_function", metadata !"targeted_function", metadata !"", metadata !14, i32 30, metadata !15, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, i32 (i32*)* @targeted_function, null, null, metadata !19, i32 31} ; [ DW_TAG_subprogram ]
!14 = metadata !{i32 786473, metadata !"./targeted_functions/int_max/targeted_function.c", metadata !"c:/xilinx", null} ; [ DW_TAG_file_type ]
!15 = metadata !{i32 786453, i32 0, metadata !"", i32 0, i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !16, i32 0, i32 0} ; [ DW_TAG_subroutine_type ]
!16 = metadata !{metadata !17, metadata !18}
!17 = metadata !{i32 786468, null, metadata !"int", null, i32 0, i64 32, i64 32, i64 0, i32 0, i32 5} ; [ DW_TAG_base_type ]
!18 = metadata !{i32 786447, null, metadata !"", null, i32 0, i64 64, i64 64, i64 0, i32 0, metadata !17} ; [ DW_TAG_pointer_type ]
!19 = metadata !{metadata !20}
!20 = metadata !{i32 786468}                      ; [ DW_TAG_base_type ]
!21 = metadata !{i32 30, i32 29, metadata !13, null}
!22 = metadata !{i32 32, i32 1, metadata !23, null}
!23 = metadata !{i32 786443, metadata !13, i32 31, i32 1, metadata !14, i32 0} ; [ DW_TAG_lexical_block ]
!24 = metadata !{i32 32, i32 2, metadata !23, null}
!25 = metadata !{i32 33, i32 2, metadata !23, null}
