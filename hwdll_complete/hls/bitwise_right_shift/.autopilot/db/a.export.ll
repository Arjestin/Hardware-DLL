; ModuleID = 'C:/xilinx/hls/bitwise_right_shift/.autopilot/db/a.o.2.bc'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"
target triple = "x86_64-w64-mingw32"

@targeted_function_str = internal unnamed_addr constant [18 x i8] c"targeted_function\00"
@p_str2 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@p_str1 = private unnamed_addr constant [3 x i8] c"rm\00", align 1
@p_str = private unnamed_addr constant [10 x i8] c"s_axilite\00", align 1

define i32 @targeted_function(i32 %input_000, i32* %output_000) nounwind uwtable {
  call void (...)* @_ssdm_op_SpecBitsMap(i32 %input_000) nounwind, !map !0
  call void (...)* @_ssdm_op_SpecBitsMap(i32* %output_000) nounwind, !map !6
  call void (...)* @_ssdm_op_SpecBitsMap(i32 0) nounwind, !map !12
  call void (...)* @_ssdm_op_SpecTopModule([18 x i8]* @targeted_function_str) nounwind
  %input_000_read = call i32 @_ssdm_op_Read.s_axilite.i32(i32 %input_000) nounwind
  call void (...)* @_ssdm_op_SpecInterface(i32* %output_000, [10 x i8]* @p_str, i32 0, i32 0, i32 0, i32 0, [3 x i8]* @p_str1, [1 x i8]* @p_str2, [1 x i8]* @p_str2, [1 x i8]* @p_str2) nounwind
  call void (...)* @_ssdm_op_SpecInterface(i32 %input_000, [10 x i8]* @p_str, i32 0, i32 0, i32 0, i32 0, [3 x i8]* @p_str1, [1 x i8]* @p_str2, [1 x i8]* @p_str2, [1 x i8]* @p_str2) nounwind
  call void (...)* @_ssdm_op_SpecInterface(i32 0, [10 x i8]* @p_str, i32 0, i32 0, i32 0, i32 0, [3 x i8]* @p_str1, [1 x i8]* @p_str2, [1 x i8]* @p_str2, [1 x i8]* @p_str2) nounwind
  %tmp_1 = call i31 @_ssdm_op_PartSelect.i31.i32.i32.i32(i32 %input_000_read, i32 1, i32 31)
  %output_000_assign = sext i31 %tmp_1 to i32
  call void @_ssdm_op_Write.s_axilite.i32P(i32* %output_000, i32 %output_000_assign) nounwind
  ret i32 0
}

declare i32 @llvm.part.select.i32(i32, i32, i32) nounwind readnone

declare void @llvm.dbg.value(metadata, i64, metadata) nounwind readnone

define weak void @_ssdm_op_Write.s_axilite.i32P(i32*, i32) {
entry:
  store i32 %1, i32* %0
  ret void
}

define weak void @_ssdm_op_SpecTopModule(...) {
entry:
  ret void
}

define weak void @_ssdm_op_SpecInterface(...) nounwind {
entry:
  ret void
}

define weak void @_ssdm_op_SpecBitsMap(...) {
entry:
  ret void
}

define weak i32 @_ssdm_op_Read.s_axilite.i32(i32) {
entry:
  ret i32 %0
}

define weak i31 @_ssdm_op_PartSelect.i31.i32.i32.i32(i32, i32, i32) nounwind readnone {
entry:
  %empty = call i32 @llvm.part.select.i32(i32 %0, i32 %1, i32 %2)
  %empty_4 = trunc i32 %empty to i31
  ret i31 %empty_4
}

declare i16 @_ssdm_op_HSub(...)

declare i16 @_ssdm_op_HMul(...)

declare i16 @_ssdm_op_HDiv(...)

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
