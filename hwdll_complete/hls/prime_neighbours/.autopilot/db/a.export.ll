; ModuleID = 'C:/xilinx/hls/prime_neighbours/.autopilot/db/a.o.2.bc'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"
target triple = "x86_64-w64-mingw32"

@targeted_function_str = internal unnamed_addr constant [18 x i8] c"targeted_function\00"
@p_str2 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@p_str1 = private unnamed_addr constant [3 x i8] c"rm\00", align 1
@p_str = private unnamed_addr constant [10 x i8] c"s_axilite\00", align 1

define i32 @targeted_function(i32 %input_000, i32* %output_000, i32* %output_001) nounwind uwtable {
  call void (...)* @_ssdm_op_SpecBitsMap(i32 %input_000) nounwind, !map !0
  call void (...)* @_ssdm_op_SpecBitsMap(i32* %output_000) nounwind, !map !6
  call void (...)* @_ssdm_op_SpecBitsMap(i32* %output_001) nounwind, !map !12
  call void (...)* @_ssdm_op_SpecBitsMap(i32 0) nounwind, !map !16
  call void (...)* @_ssdm_op_SpecTopModule([18 x i8]* @targeted_function_str) nounwind
  %input_000_read = call i32 @_ssdm_op_Read.s_axilite.i32(i32 %input_000) nounwind
  call void (...)* @_ssdm_op_SpecInterface(i32* %output_001, [10 x i8]* @p_str, i32 0, i32 0, i32 0, i32 0, [3 x i8]* @p_str1, [1 x i8]* @p_str2, [1 x i8]* @p_str2, [1 x i8]* @p_str2) nounwind
  call void (...)* @_ssdm_op_SpecInterface(i32* %output_000, [10 x i8]* @p_str, i32 0, i32 0, i32 0, i32 0, [3 x i8]* @p_str1, [1 x i8]* @p_str2, [1 x i8]* @p_str2, [1 x i8]* @p_str2) nounwind
  call void (...)* @_ssdm_op_SpecInterface(i32 %input_000, [10 x i8]* @p_str, i32 0, i32 0, i32 0, i32 0, [3 x i8]* @p_str1, [1 x i8]* @p_str2, [1 x i8]* @p_str2, [1 x i8]* @p_str2) nounwind
  call void (...)* @_ssdm_op_SpecInterface(i32 0, [10 x i8]* @p_str, i32 0, i32 0, i32 0, i32 0, [3 x i8]* @p_str1, [1 x i8]* @p_str2, [1 x i8]* @p_str2, [1 x i8]* @p_str2) nounwind
  call void @_ssdm_op_Write.s_axilite.i32P(i32* %output_000, i32 %input_000_read) nounwind
  call void @_ssdm_op_Write.s_axilite.i32P(i32* %output_001, i32 %input_000_read) nounwind
  %tmp = call i31 @_ssdm_op_PartSelect.i31.i32.i32.i32(i32 %input_000_read, i32 1, i32 31)
  %icmp = icmp slt i31 %tmp, 1
  br i1 %icmp, label %1, label %._crit_edge

; <label>:1                                       ; preds = %0
  call void @_ssdm_op_Write.s_axilite.i32P(i32* %output_000, i32 -1) nounwind
  call void @_ssdm_op_Write.s_axilite.i32P(i32* %output_001, i32 2) nounwind
  br label %._crit_edge

._crit_edge:                                      ; preds = %1, %0
  %output_000_promoted7 = phi i32 [ -1, %1 ], [ %input_000_read, %0 ]
  %output_001_promoted5 = phi i32 [ 2, %1 ], [ %input_000_read, %0 ]
  %flag_0 = phi i1 [ true, %1 ], [ false, %0 ]
  %tmp_1 = icmp eq i32 %input_000_read, 2
  br i1 %tmp_1, label %2, label %._crit_edge2

; <label>:2                                       ; preds = %._crit_edge
  call void @_ssdm_op_Write.s_axilite.i32P(i32* %output_000, i32 -1) nounwind
  call void @_ssdm_op_Write.s_axilite.i32P(i32* %output_001, i32 3) nounwind
  br label %._crit_edge2

._crit_edge2:                                     ; preds = %2, %._crit_edge
  %output_000_promoted = phi i32 [ -1, %2 ], [ %output_000_promoted7, %._crit_edge ]
  %output_001_promoted4 = phi i32 [ 3, %2 ], [ %output_001_promoted5, %._crit_edge ]
  %flag_0_1 = phi i1 [ true, %2 ], [ %flag_0, %._crit_edge ]
  %tmp_2 = icmp eq i32 %input_000_read, 2147483647
  br i1 %tmp_2, label %3, label %._crit_edge3

; <label>:3                                       ; preds = %._crit_edge2
  call void @_ssdm_op_Write.s_axilite.i32P(i32* %output_001, i32 -1) nounwind
  br label %._crit_edge3

._crit_edge3:                                     ; preds = %3, %._crit_edge2
  %output_001_promoted = phi i32 [ -1, %3 ], [ %output_001_promoted4, %._crit_edge2 ]
  %flag_1_2 = phi i1 [ true, %3 ], [ %flag_0_1, %._crit_edge2 ]
  %retval_2_cast = select i1 %flag_1_2, i32 -1, i32 0
  br i1 %flag_0_1, label %.loopexit.preheader, label %.critedge

.loopexit.preheader.loopexit:                     ; preds = %4
  call void @_ssdm_op_Write.s_axilite.i32P(i32* %output_000, i32 %tmp_4) nounwind
  br label %.loopexit.preheader

.loopexit.preheader:                              ; preds = %.loopexit.preheader.loopexit, %._crit_edge3
  br i1 %flag_1_2, label %.critedge1, label %.critedge2

.critedge:                                        ; preds = %5, %._crit_edge3
  %tmp_12 = phi i32 [ %output_000_promoted, %._crit_edge3 ], [ %tmp_4, %5 ]
  %tmp_4 = add nsw i32 %tmp_12, -1
  %tmp_17 = call i1 @_ssdm_op_BitSelect.i1.i32.i32(i32 %tmp_4, i32 31)
  %p_neg = sub i32 1, %tmp_12
  %p_lshr = call i31 @_ssdm_op_PartSelect.i31.i32.i32.i32(i32 %p_neg, i32 1, i32 31)
  %tmp_13 = zext i31 %p_lshr to i32
  %p_neg_t = sub i32 0, %tmp_13
  %p_lshr_f = call i31 @_ssdm_op_PartSelect.i31.i32.i32.i32(i32 %tmp_4, i32 1, i32 31)
  %tmp_14 = zext i31 %p_lshr_f to i32
  %tmp_5 = select i1 %tmp_17, i32 %p_neg_t, i32 %tmp_14
  br label %4

; <label>:4                                       ; preds = %6, %.critedge
  %i = phi i32 [ 2, %.critedge ], [ %i_2, %6 ]
  %tmp_7 = icmp sgt i32 %i, %tmp_5
  br i1 %tmp_7, label %.loopexit.preheader.loopexit, label %5

; <label>:5                                       ; preds = %4
  %tmp_s = srem i32 %tmp_4, %i
  %tmp_3 = icmp eq i32 %tmp_s, 0
  br i1 %tmp_3, label %.critedge, label %6

; <label>:6                                       ; preds = %5
  %i_2 = add nsw i32 %i, 1
  br label %4

.critedge2:                                       ; preds = %8, %.loopexit.preheader
  %tmp_15 = phi i32 [ %output_001_promoted, %.loopexit.preheader ], [ %tmp_8, %8 ]
  %tmp_8 = add nsw i32 %tmp_15, 1
  %tmp_18 = call i1 @_ssdm_op_BitSelect.i1.i32.i32(i32 %tmp_8, i32 31)
  %p_neg3_cast = call i31 @_ssdm_op_PartSelect.i31.i32.i32.i32(i32 %tmp_15, i32 1, i32 31)
  %p_lshr4 = xor i31 %p_neg3_cast, -1
  %p_lshr4_cast = zext i31 %p_lshr4 to i32
  %p_neg_t5 = sub i32 0, %p_lshr4_cast
  %p_lshr_f6 = call i31 @_ssdm_op_PartSelect.i31.i32.i32.i32(i32 %tmp_8, i32 1, i32 31)
  %tmp_16 = zext i31 %p_lshr_f6 to i32
  %tmp_9 = select i1 %tmp_18, i32 %p_neg_t5, i32 %tmp_16
  br label %7

; <label>:7                                       ; preds = %9, %.critedge2
  %i_1 = phi i32 [ 2, %.critedge2 ], [ %i_3, %9 ]
  %tmp_6 = icmp sgt i32 %i_1, %tmp_9
  br i1 %tmp_6, label %.critedge1.loopexit, label %8

; <label>:8                                       ; preds = %7
  %tmp_10 = srem i32 %tmp_8, %i_1
  %tmp_11 = icmp eq i32 %tmp_10, 0
  br i1 %tmp_11, label %.critedge2, label %9

; <label>:9                                       ; preds = %8
  %i_3 = add nsw i32 %i_1, 1
  br label %7

.critedge1.loopexit:                              ; preds = %7
  call void @_ssdm_op_Write.s_axilite.i32P(i32* %output_001, i32 %tmp_8) nounwind
  br label %.critedge1

.critedge1:                                       ; preds = %.critedge1.loopexit, %.loopexit.preheader
  ret i32 %retval_2_cast
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
!15 = metadata !{metadata !"output_001", metadata !10, metadata !"int", i32 0, i32 31}
!16 = metadata !{metadata !17}
!17 = metadata !{i32 0, i32 31, metadata !18}
!18 = metadata !{metadata !19}
!19 = metadata !{metadata !"return", metadata !20, metadata !"int", i32 0, i32 31}
!20 = metadata !{metadata !21}
!21 = metadata !{i32 0, i32 1, i32 0}
