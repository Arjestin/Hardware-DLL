; ModuleID = 'C:/xilinx/hls/fibonacci/.autopilot/db/a.o.2.bc'
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
  %tmp = call i1 @_ssdm_op_BitSelect.i1.i32.i32(i32 %input_000_read, i32 31)
  %tmp_1 = icmp sgt i32 %input_000_read, 46
  %or_cond = or i1 %tmp, %tmp_1
  br i1 %or_cond, label %1, label %2

; <label>:1                                       ; preds = %0
  call void @_ssdm_op_Write.s_axilite.i32P(i32* %output_000, i32 -1) nounwind
  br label %.loopexit

; <label>:2                                       ; preds = %0
  %tmp_2 = call i31 @_ssdm_op_PartSelect.i31.i32.i32.i32(i32 %input_000_read, i32 1, i32 31)
  %icmp = icmp slt i31 %tmp_2, 1
  br i1 %icmp, label %3, label %.preheader

; <label>:3                                       ; preds = %2
  call void @_ssdm_op_Write.s_axilite.i32P(i32* %output_000, i32 %input_000_read) nounwind
  br label %.loopexit

.preheader:                                       ; preds = %2, %4
  %i = phi i6 [ %i_1, %4 ], [ 1, %2 ]
  %first = phi i32 [ %first_1, %4 ], [ 0, %2 ]
  %first_1 = phi i32 [ %second, %4 ], [ 1, %2 ]
  %i_cast = zext i6 %i to i32
  %exitcond = icmp eq i32 %i_cast, %input_000_read
  %empty = call i32 (...)* @_ssdm_op_SpecLoopTripCount(i64 1, i64 45, i64 0) nounwind
  br i1 %exitcond, label %.loopexit, label %4

; <label>:4                                       ; preds = %.preheader
  %second = add nsw i32 %first, %first_1
  call void @_ssdm_op_Write.s_axilite.i32P(i32* %output_000, i32 %second) nounwind
  %i_1 = add i6 %i, 1
  br label %.preheader

.loopexit:                                        ; preds = %.preheader, %3, %1
  %p_0 = phi i1 [ true, %1 ], [ false, %3 ], [ false, %.preheader ]
  %p_0_cast = select i1 %p_0, i32 -1, i32 0
  ret i32 %p_0_cast
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

define weak i32 @_ssdm_op_SpecLoopTripCount(...) {
entry:
  ret i32 0
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

define weak i1 @_ssdm_op_BitSelect.i1.i32.i32(i32, i32) nounwind readnone {
entry:
  %empty = shl i32 1, %1
  %empty_5 = and i32 %0, %empty
  %empty_6 = icmp ne i32 %empty_5, 0
  ret i1 %empty_6
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
!9 = metadata !{metadata !"output_000", metadata !10, metadata !"int", i32 0, i32 31}
!10 = metadata !{metadata !11}
!11 = metadata !{i32 0, i32 0, i32 1}
!12 = metadata !{metadata !13}
!13 = metadata !{i32 0, i32 31, metadata !14}
!14 = metadata !{metadata !15}
!15 = metadata !{metadata !"return", metadata !16, metadata !"int", i32 0, i32 31}
!16 = metadata !{metadata !17}
!17 = metadata !{i32 0, i32 1, i32 0}
