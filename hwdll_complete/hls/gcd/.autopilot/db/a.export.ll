; ModuleID = 'C:/xilinx/hls/gcd/.autopilot/db/a.o.2.bc'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"
target triple = "x86_64-w64-mingw32"

@targeted_function_str = internal unnamed_addr constant [18 x i8] c"targeted_function\00"
@p_str2 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@p_str1 = private unnamed_addr constant [3 x i8] c"rm\00", align 1
@p_str = private unnamed_addr constant [10 x i8] c"s_axilite\00", align 1

define i32 @targeted_function(i32 %input_000, i32 %input_001, i32* %output_000) nounwind uwtable {
  call void (...)* @_ssdm_op_SpecBitsMap(i32 %input_000) nounwind, !map !0
  call void (...)* @_ssdm_op_SpecBitsMap(i32 %input_001) nounwind, !map !6
  call void (...)* @_ssdm_op_SpecBitsMap(i32* %output_000) nounwind, !map !10
  call void (...)* @_ssdm_op_SpecBitsMap(i32 0) nounwind, !map !16
  call void (...)* @_ssdm_op_SpecTopModule([18 x i8]* @targeted_function_str) nounwind
  %input_001_read = call i32 @_ssdm_op_Read.s_axilite.i32(i32 %input_001) nounwind
  %input_000_read = call i32 @_ssdm_op_Read.s_axilite.i32(i32 %input_000) nounwind
  call void (...)* @_ssdm_op_SpecInterface(i32* %output_000, [10 x i8]* @p_str, i32 0, i32 0, i32 0, i32 0, [3 x i8]* @p_str1, [1 x i8]* @p_str2, [1 x i8]* @p_str2, [1 x i8]* @p_str2) nounwind
  call void (...)* @_ssdm_op_SpecInterface(i32 %input_001, [10 x i8]* @p_str, i32 0, i32 0, i32 0, i32 0, [3 x i8]* @p_str1, [1 x i8]* @p_str2, [1 x i8]* @p_str2, [1 x i8]* @p_str2) nounwind
  call void (...)* @_ssdm_op_SpecInterface(i32 %input_000, [10 x i8]* @p_str, i32 0, i32 0, i32 0, i32 0, [3 x i8]* @p_str1, [1 x i8]* @p_str2, [1 x i8]* @p_str2, [1 x i8]* @p_str2) nounwind
  call void (...)* @_ssdm_op_SpecInterface(i32 0, [10 x i8]* @p_str, i32 0, i32 0, i32 0, i32 0, [3 x i8]* @p_str1, [1 x i8]* @p_str2, [1 x i8]* @p_str2, [1 x i8]* @p_str2) nounwind
  %tmp = or i32 %input_001_read, %input_000_read
  %tmp_1 = icmp eq i32 %tmp, 0
  br i1 %tmp_1, label %1, label %2

; <label>:1                                       ; preds = %0
  call void @_ssdm_op_Write.s_axilite.i32P(i32* %output_000, i32 -1) nounwind
  br label %6

; <label>:2                                       ; preds = %0
  %tmp_2 = icmp eq i32 %input_000_read, 0
  br i1 %tmp_2, label %3, label %.preheader

; <label>:3                                       ; preds = %2
  %tmp_3 = call i1 @_ssdm_op_BitSelect.i1.i32.i32(i32 %input_001_read, i32 31)
  %tmp_4 = sub nsw i32 0, %input_001_read
  %input_001_assign = select i1 %tmp_3, i32 %tmp_4, i32 %input_001_read
  call void @_ssdm_op_Write.s_axilite.i32P(i32* %output_000, i32 %input_001_assign) nounwind
  br label %6

.preheader:                                       ; preds = %2, %4
  %input_000_assign = phi i32 [ %input_001_assign_1, %4 ], [ %input_001_read, %2 ]
  %p_1 = phi i32 [ %input_000_assign, %4 ], [ %input_000_read, %2 ]
  %tmp_6 = icmp eq i32 %input_000_assign, 0
  br i1 %tmp_6, label %5, label %4

; <label>:4                                       ; preds = %.preheader
  %input_001_assign_1 = srem i32 %p_1, %input_000_assign
  br label %.preheader

; <label>:5                                       ; preds = %.preheader
  %tmp_5 = call i1 @_ssdm_op_BitSelect.i1.i32.i32(i32 %p_1, i32 31)
  %tmp_8 = sub nsw i32 0, %p_1
  %tmp_9 = select i1 %tmp_5, i32 %tmp_8, i32 %p_1
  call void @_ssdm_op_Write.s_axilite.i32P(i32* %output_000, i32 %tmp_9) nounwind
  br label %6

; <label>:6                                       ; preds = %5, %3, %1
  %p_0 = phi i1 [ true, %1 ], [ false, %3 ], [ false, %5 ]
  %p_0_cast = select i1 %p_0, i32 -1, i32 0
  ret i32 %p_0_cast
}

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

declare i16 @_ssdm_op_HSub(...)

declare i16 @_ssdm_op_HMul(...)

declare i16 @_ssdm_op_HDiv(...)

declare i16 @_ssdm_op_HAdd(...)

define weak i1 @_ssdm_op_BitSelect.i1.i32.i32(i32, i32) nounwind readnone {
entry:
  %empty = shl i32 1, %1
  %empty_2 = and i32 %0, %empty
  %empty_3 = icmp ne i32 %empty_2, 0
  ret i1 %empty_3
}

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
