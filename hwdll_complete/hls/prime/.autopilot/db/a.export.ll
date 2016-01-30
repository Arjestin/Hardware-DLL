; ModuleID = 'C:/xilinx/hls/prime/.autopilot/db/a.o.2.bc'
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
  %tmp = icmp slt i32 %input_000_read, 1
  %tmp_1 = icmp sgt i32 %input_000_read, 105097565
  %or_cond = or i1 %tmp, %tmp_1
  br i1 %or_cond, label %1, label %2

; <label>:1                                       ; preds = %0
  call void @_ssdm_op_Write.s_axilite.i32P(i32* %output_000, i32 -1) nounwind
  br label %.loopexit3

; <label>:2                                       ; preds = %0
  %i = alloca i32
  call void @_ssdm_op_Write.s_axilite.i32P(i32* %output_000, i32 2) nounwind
  store i32 2, i32* %i
  br label %3

; <label>:3                                       ; preds = %.loopexit._crit_edge, %2
  %ctr = phi i32 [ 3, %2 ], [ %ctr_1, %.loopexit._crit_edge ]
  %i_load = load i32* %i
  %tmp_2 = icmp sgt i32 %i_load, %input_000_read
  br i1 %tmp_2, label %.loopexit3, label %.preheader.preheader

.preheader.preheader:                             ; preds = %3
  %tmp_3 = add nsw i32 %ctr, -1
  br label %.preheader

.preheader:                                       ; preds = %5, %.preheader.preheader
  %j = phi i32 [ %j_1, %5 ], [ 2, %.preheader.preheader ]
  %tmp_4 = icmp sgt i32 %j, %tmp_3
  br i1 %tmp_4, label %.loopexit, label %4

; <label>:4                                       ; preds = %.preheader
  %tmp_5 = srem i32 %ctr, %j
  %tmp_6 = icmp eq i32 %tmp_5, 0
  br i1 %tmp_6, label %.loopexit, label %5

; <label>:5                                       ; preds = %4
  %j_1 = add nsw i32 %j, 1
  br label %.preheader

.loopexit:                                        ; preds = %4, %.preheader
  %tmp_7 = icmp eq i32 %ctr, %j
  br i1 %tmp_7, label %6, label %.loopexit._crit_edge

; <label>:6                                       ; preds = %.loopexit
  call void @_ssdm_op_Write.s_axilite.i32P(i32* %output_000, i32 %ctr) nounwind
  %i_1 = add nsw i32 %i_load, 1
  store i32 %i_1, i32* %i
  br label %.loopexit._crit_edge

.loopexit._crit_edge:                             ; preds = %6, %.loopexit
  %ctr_1 = add nsw i32 %ctr, 1
  br label %3

.loopexit3:                                       ; preds = %3, %1
  %p_0 = phi i1 [ true, %1 ], [ false, %3 ]
  %p_0_cast = select i1 %p_0, i32 -1, i32 0
  ret i32 %p_0_cast
}

declare void @llvm.dbg.value(metadata, i64, metadata) nounwind readnone

declare void @llvm.dbg.declare(metadata, metadata) nounwind readnone

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
