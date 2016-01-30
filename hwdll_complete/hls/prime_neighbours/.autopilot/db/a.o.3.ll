; ModuleID = 'C:/xilinx/hls/prime_neighbours/.autopilot/db/a.o.3.bc'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"
target triple = "x86_64-w64-mingw32"

@targeted_function_str = internal unnamed_addr constant [18 x i8] c"targeted_function\00" ; [#uses=1 type=[18 x i8]*]
@p_str2 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1 ; [#uses=12 type=[1 x i8]*]
@p_str1 = private unnamed_addr constant [3 x i8] c"rm\00", align 1 ; [#uses=4 type=[3 x i8]*]
@p_str = private unnamed_addr constant [10 x i8] c"s_axilite\00", align 1 ; [#uses=4 type=[10 x i8]*]

; [#uses=0]
define i32 @targeted_function(i32 %input_000, i32* %output_000, i32* %output_001) nounwind uwtable {
  call void (...)* @_ssdm_op_SpecBitsMap(i32 %input_000) nounwind, !map !0
  call void (...)* @_ssdm_op_SpecBitsMap(i32* %output_000) nounwind, !map !6
  call void (...)* @_ssdm_op_SpecBitsMap(i32* %output_001) nounwind, !map !12
  call void (...)* @_ssdm_op_SpecBitsMap(i32 0) nounwind, !map !16
  call void (...)* @_ssdm_op_SpecTopModule([18 x i8]* @targeted_function_str) nounwind
  %input_000_read = call i32 @_ssdm_op_Read.s_axilite.i32(i32 %input_000) nounwind ; [#uses=7 type=i32]
  call void @llvm.dbg.value(metadata !{i32 %input_000_read}, i64 0, metadata !22), !dbg !31 ; [debug line = 31:28] [debug variable = input_000]
  call void @llvm.dbg.value(metadata !{i32 %input_000}, i64 0, metadata !22), !dbg !31 ; [debug line = 31:28] [debug variable = input_000]
  call void @llvm.dbg.value(metadata !{i32* %output_000}, i64 0, metadata !32), !dbg !33 ; [debug line = 31:44] [debug variable = output_000]
  call void @llvm.dbg.value(metadata !{i32* %output_001}, i64 0, metadata !34), !dbg !35 ; [debug line = 31:61] [debug variable = output_001]
  call void (...)* @_ssdm_op_SpecInterface(i32* %output_001, [10 x i8]* @p_str, i32 0, i32 0, i32 0, i32 0, [3 x i8]* @p_str1, [1 x i8]* @p_str2, [1 x i8]* @p_str2, [1 x i8]* @p_str2) nounwind, !dbg !36 ; [debug line = 33:1]
  call void (...)* @_ssdm_op_SpecInterface(i32* %output_000, [10 x i8]* @p_str, i32 0, i32 0, i32 0, i32 0, [3 x i8]* @p_str1, [1 x i8]* @p_str2, [1 x i8]* @p_str2, [1 x i8]* @p_str2) nounwind, !dbg !36 ; [debug line = 33:1]
  call void (...)* @_ssdm_op_SpecInterface(i32 %input_000, [10 x i8]* @p_str, i32 0, i32 0, i32 0, i32 0, [3 x i8]* @p_str1, [1 x i8]* @p_str2, [1 x i8]* @p_str2, [1 x i8]* @p_str2) nounwind, !dbg !36 ; [debug line = 33:1]
  call void (...)* @_ssdm_op_SpecInterface(i32 0, [10 x i8]* @p_str, i32 0, i32 0, i32 0, i32 0, [3 x i8]* @p_str1, [1 x i8]* @p_str2, [1 x i8]* @p_str2, [1 x i8]* @p_str2) nounwind, !dbg !36 ; [debug line = 33:1]
  call void @_ssdm_op_Write.s_axilite.i32P(i32* %output_000, i32 %input_000_read) nounwind, !dbg !38 ; [debug line = 34:2]
  call void @_ssdm_op_Write.s_axilite.i32P(i32* %output_001, i32 %input_000_read) nounwind, !dbg !39 ; [debug line = 35:2]
  %tmp = call i31 @_ssdm_op_PartSelect.i31.i32.i32.i32(i32 %input_000_read, i32 1, i32 31), !dbg !40 ; [#uses=1 type=i31] [debug line = 36:2]
  %icmp = icmp slt i31 %tmp, 1, !dbg !40          ; [#uses=1 type=i1] [debug line = 36:2]
  br i1 %icmp, label %1, label %._crit_edge, !dbg !40 ; [debug line = 36:2]

; <label>:1                                       ; preds = %0
  call void @_ssdm_op_Write.s_axilite.i32P(i32* %output_000, i32 -1) nounwind, !dbg !41 ; [debug line = 38:3]
  call void @_ssdm_op_Write.s_axilite.i32P(i32* %output_001, i32 2) nounwind, !dbg !43 ; [debug line = 39:3]
  br label %._crit_edge, !dbg !44                 ; [debug line = 43:2]

._crit_edge:                                      ; preds = %1, %0
  %output_000_promoted7 = phi i32 [ -1, %1 ], [ %input_000_read, %0 ] ; [#uses=1 type=i32]
  %output_001_promoted5 = phi i32 [ 2, %1 ], [ %input_000_read, %0 ] ; [#uses=1 type=i32]
  %flag_0 = phi i1 [ true, %1 ], [ false, %0 ]    ; [#uses=1 type=i1]
  %tmp_1 = icmp eq i32 %input_000_read, 2, !dbg !45 ; [#uses=1 type=i1] [debug line = 44:2]
  br i1 %tmp_1, label %2, label %._crit_edge2, !dbg !45 ; [debug line = 44:2]

; <label>:2                                       ; preds = %._crit_edge
  call void @_ssdm_op_Write.s_axilite.i32P(i32* %output_000, i32 -1) nounwind, !dbg !46 ; [debug line = 46:3]
  call void @_ssdm_op_Write.s_axilite.i32P(i32* %output_001, i32 3) nounwind, !dbg !48 ; [debug line = 47:3]
  br label %._crit_edge2, !dbg !49                ; [debug line = 51:2]

._crit_edge2:                                     ; preds = %2, %._crit_edge
  %output_000_promoted = phi i32 [ -1, %2 ], [ %output_000_promoted7, %._crit_edge ] ; [#uses=1 type=i32]
  %output_001_promoted4 = phi i32 [ 3, %2 ], [ %output_001_promoted5, %._crit_edge ] ; [#uses=1 type=i32]
  %flag_0_1 = phi i1 [ true, %2 ], [ %flag_0, %._crit_edge ] ; [#uses=2 type=i1]
  %tmp_2 = icmp eq i32 %input_000_read, 2147483647, !dbg !50 ; [#uses=1 type=i1] [debug line = 52:2]
  br i1 %tmp_2, label %3, label %._crit_edge3, !dbg !50 ; [debug line = 52:2]

; <label>:3                                       ; preds = %._crit_edge2
  call void @_ssdm_op_Write.s_axilite.i32P(i32* %output_001, i32 -1) nounwind, !dbg !51 ; [debug line = 54:3]
  br label %._crit_edge3, !dbg !53                ; [debug line = 57:2]

._crit_edge3:                                     ; preds = %3, %._crit_edge2
  %output_001_promoted = phi i32 [ -1, %3 ], [ %output_001_promoted4, %._crit_edge2 ] ; [#uses=1 type=i32]
  %flag_1_2 = phi i1 [ true, %3 ], [ %flag_0_1, %._crit_edge2 ] ; [#uses=2 type=i1]
  %retval_2_cast = select i1 %flag_1_2, i32 -1, i32 0, !dbg !54 ; [#uses=1 type=i32] [debug line = 58:2]
  br i1 %flag_0_1, label %.loopexit.preheader, label %.critedge, !dbg !54 ; [debug line = 58:2]

.loopexit.preheader.loopexit:                     ; preds = %4
  call void @_ssdm_op_Write.s_axilite.i32P(i32* %output_000, i32 %tmp_4) nounwind, !dbg !55 ; [debug line = 60:3]
  br label %.loopexit.preheader

.loopexit.preheader:                              ; preds = %.loopexit.preheader.loopexit, %._crit_edge3
  br i1 %flag_1_2, label %.critedge1, label %.critedge2, !dbg !57 ; [debug line = 71:2]

.critedge:                                        ; preds = %5, %._crit_edge3
  %tmp_12 = phi i32 [ %output_000_promoted, %._crit_edge3 ], [ %tmp_4, %5 ], !dbg !55 ; [#uses=2 type=i32] [debug line = 60:3]
  %tmp_4 = add nsw i32 %tmp_12, -1, !dbg !55      ; [#uses=5 type=i32] [debug line = 60:3]
  %tmp_17 = call i1 @_ssdm_op_BitSelect.i1.i32.i32(i32 %tmp_4, i32 31), !dbg !58 ; [#uses=1 type=i1] [debug line = 62:8]
  %p_neg = sub i32 1, %tmp_12, !dbg !58           ; [#uses=1 type=i32] [debug line = 62:8]
  %p_lshr = call i31 @_ssdm_op_PartSelect.i31.i32.i32.i32(i32 %p_neg, i32 1, i32 31), !dbg !58 ; [#uses=1 type=i31] [debug line = 62:8]
  %tmp_13 = zext i31 %p_lshr to i32, !dbg !58     ; [#uses=1 type=i32] [debug line = 62:8]
  %p_neg_t = sub i32 0, %tmp_13, !dbg !58         ; [#uses=1 type=i32] [debug line = 62:8]
  %p_lshr_f = call i31 @_ssdm_op_PartSelect.i31.i32.i32.i32(i32 %tmp_4, i32 1, i32 31), !dbg !58 ; [#uses=1 type=i31] [debug line = 62:8]
  %tmp_14 = zext i31 %p_lshr_f to i32, !dbg !58   ; [#uses=1 type=i32] [debug line = 62:8]
  %tmp_5 = select i1 %tmp_17, i32 %p_neg_t, i32 %tmp_14, !dbg !58 ; [#uses=1 type=i32] [debug line = 62:8]
  br label %4, !dbg !58                           ; [debug line = 62:8]

; <label>:4                                       ; preds = %6, %.critedge
  %i = phi i32 [ 2, %.critedge ], [ %i_2, %6 ]    ; [#uses=3 type=i32]
  %tmp_7 = icmp sgt i32 %i, %tmp_5, !dbg !58      ; [#uses=1 type=i1] [debug line = 62:8]
  br i1 %tmp_7, label %.loopexit.preheader.loopexit, label %5, !dbg !58 ; [debug line = 62:8]

; <label>:5                                       ; preds = %4
  %tmp_s = srem i32 %tmp_4, %i, !dbg !60          ; [#uses=1 type=i32] [debug line = 64:4]
  %tmp_3 = icmp eq i32 %tmp_s, 0, !dbg !60        ; [#uses=1 type=i1] [debug line = 64:4]
  br i1 %tmp_3, label %.critedge, label %6, !dbg !60 ; [debug line = 64:4]

; <label>:6                                       ; preds = %5
  %i_2 = add nsw i32 %i, 1, !dbg !62              ; [#uses=1 type=i32] [debug line = 62:37]
  call void @llvm.dbg.value(metadata !{i32 %i_2}, i64 0, metadata !63), !dbg !62 ; [debug line = 62:37] [debug variable = i]
  br label %4, !dbg !62                           ; [debug line = 62:37]

.critedge2:                                       ; preds = %8, %.loopexit.preheader
  %tmp_15 = phi i32 [ %output_001_promoted, %.loopexit.preheader ], [ %tmp_8, %8 ], !dbg !64 ; [#uses=2 type=i32] [debug line = 73:3]
  %tmp_8 = add nsw i32 %tmp_15, 1, !dbg !64       ; [#uses=5 type=i32] [debug line = 73:3]
  %tmp_18 = call i1 @_ssdm_op_BitSelect.i1.i32.i32(i32 %tmp_8, i32 31), !dbg !66 ; [#uses=1 type=i1] [debug line = 75:8]
  %p_neg3_cast = call i31 @_ssdm_op_PartSelect.i31.i32.i32.i32(i32 %tmp_15, i32 1, i32 31), !dbg !66 ; [#uses=1 type=i31] [debug line = 75:8]
  %p_lshr4 = xor i31 %p_neg3_cast, -1, !dbg !66   ; [#uses=1 type=i31] [debug line = 75:8]
  %p_lshr4_cast = zext i31 %p_lshr4 to i32, !dbg !66 ; [#uses=1 type=i32] [debug line = 75:8]
  %p_neg_t5 = sub i32 0, %p_lshr4_cast, !dbg !66  ; [#uses=1 type=i32] [debug line = 75:8]
  %p_lshr_f6 = call i31 @_ssdm_op_PartSelect.i31.i32.i32.i32(i32 %tmp_8, i32 1, i32 31), !dbg !66 ; [#uses=1 type=i31] [debug line = 75:8]
  %tmp_16 = zext i31 %p_lshr_f6 to i32, !dbg !66  ; [#uses=1 type=i32] [debug line = 75:8]
  %tmp_9 = select i1 %tmp_18, i32 %p_neg_t5, i32 %tmp_16, !dbg !66 ; [#uses=1 type=i32] [debug line = 75:8]
  br label %7, !dbg !66                           ; [debug line = 75:8]

; <label>:7                                       ; preds = %9, %.critedge2
  %i_1 = phi i32 [ 2, %.critedge2 ], [ %i_3, %9 ] ; [#uses=3 type=i32]
  %tmp_6 = icmp sgt i32 %i_1, %tmp_9, !dbg !66    ; [#uses=1 type=i1] [debug line = 75:8]
  br i1 %tmp_6, label %.critedge1.loopexit, label %8, !dbg !66 ; [debug line = 75:8]

; <label>:8                                       ; preds = %7
  %tmp_10 = srem i32 %tmp_8, %i_1, !dbg !68       ; [#uses=1 type=i32] [debug line = 77:4]
  %tmp_11 = icmp eq i32 %tmp_10, 0, !dbg !68      ; [#uses=1 type=i1] [debug line = 77:4]
  br i1 %tmp_11, label %.critedge2, label %9, !dbg !68 ; [debug line = 77:4]

; <label>:9                                       ; preds = %8
  %i_3 = add nsw i32 %i_1, 1, !dbg !70            ; [#uses=1 type=i32] [debug line = 75:37]
  call void @llvm.dbg.value(metadata !{i32 %i_3}, i64 0, metadata !63), !dbg !70 ; [debug line = 75:37] [debug variable = i]
  br label %7, !dbg !70                           ; [debug line = 75:37]

.critedge1.loopexit:                              ; preds = %7
  call void @_ssdm_op_Write.s_axilite.i32P(i32* %output_001, i32 %tmp_8) nounwind, !dbg !64 ; [debug line = 73:3]
  br label %.critedge1

.critedge1:                                       ; preds = %.critedge1.loopexit, %.loopexit.preheader
  ret i32 %retval_2_cast, !dbg !71                ; [debug line = 84:2]
}

; [#uses=1]
declare i32 @llvm.part.select.i32(i32, i32, i32) nounwind readnone

; [#uses=6]
declare void @llvm.dbg.value(metadata, i64, metadata) nounwind readnone

; [#uses=9]
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

; [#uses=1]
define weak i32 @_ssdm_op_Read.s_axilite.i32(i32) {
entry:
  ret i32 %0
}

; [#uses=5]
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

; [#uses=2]
define weak i1 @_ssdm_op_BitSelect.i1.i32.i32(i32, i32) nounwind readnone {
entry:
  %empty = shl i32 1, %1                          ; [#uses=1 type=i32]
  %empty_5 = and i32 %0, %empty                   ; [#uses=1 type=i32]
  %empty_6 = icmp ne i32 %empty_5, 0              ; [#uses=1 type=i1]
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
!22 = metadata !{i32 786689, metadata !23, metadata !"input_000", metadata !24, i32 16777247, metadata !27, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!23 = metadata !{i32 786478, i32 0, metadata !24, metadata !"targeted_function", metadata !"targeted_function", metadata !"", metadata !24, i32 31, metadata !25, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, i32 (i32, i32*, i32*)* @targeted_function, null, null, metadata !29, i32 32} ; [ DW_TAG_subprogram ]
!24 = metadata !{i32 786473, metadata !"./targeted_functions/prime_neighbours/targeted_function.c", metadata !"c:/xilinx", null} ; [ DW_TAG_file_type ]
!25 = metadata !{i32 786453, i32 0, metadata !"", i32 0, i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !26, i32 0, i32 0} ; [ DW_TAG_subroutine_type ]
!26 = metadata !{metadata !27, metadata !27, metadata !28, metadata !28}
!27 = metadata !{i32 786468, null, metadata !"int", null, i32 0, i64 32, i64 32, i64 0, i32 0, i32 5} ; [ DW_TAG_base_type ]
!28 = metadata !{i32 786447, null, metadata !"", null, i32 0, i64 64, i64 64, i64 0, i32 0, metadata !27} ; [ DW_TAG_pointer_type ]
!29 = metadata !{metadata !30}
!30 = metadata !{i32 786468}                      ; [ DW_TAG_base_type ]
!31 = metadata !{i32 31, i32 28, metadata !23, null}
!32 = metadata !{i32 786689, metadata !23, metadata !"output_000", metadata !24, i32 33554463, metadata !28, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!33 = metadata !{i32 31, i32 44, metadata !23, null}
!34 = metadata !{i32 786689, metadata !23, metadata !"output_001", metadata !24, i32 50331679, metadata !28, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!35 = metadata !{i32 31, i32 61, metadata !23, null}
!36 = metadata !{i32 33, i32 1, metadata !37, null}
!37 = metadata !{i32 786443, metadata !23, i32 32, i32 1, metadata !24, i32 0} ; [ DW_TAG_lexical_block ]
!38 = metadata !{i32 34, i32 2, metadata !37, null}
!39 = metadata !{i32 35, i32 2, metadata !37, null}
!40 = metadata !{i32 36, i32 2, metadata !37, null}
!41 = metadata !{i32 38, i32 3, metadata !42, null}
!42 = metadata !{i32 786443, metadata !37, i32 37, i32 2, metadata !24, i32 1} ; [ DW_TAG_lexical_block ]
!43 = metadata !{i32 39, i32 3, metadata !42, null}
!44 = metadata !{i32 43, i32 2, metadata !42, null}
!45 = metadata !{i32 44, i32 2, metadata !37, null}
!46 = metadata !{i32 46, i32 3, metadata !47, null}
!47 = metadata !{i32 786443, metadata !37, i32 45, i32 2, metadata !24, i32 2} ; [ DW_TAG_lexical_block ]
!48 = metadata !{i32 47, i32 3, metadata !47, null}
!49 = metadata !{i32 51, i32 2, metadata !47, null}
!50 = metadata !{i32 52, i32 2, metadata !37, null}
!51 = metadata !{i32 54, i32 3, metadata !52, null}
!52 = metadata !{i32 786443, metadata !37, i32 53, i32 2, metadata !24, i32 3} ; [ DW_TAG_lexical_block ]
!53 = metadata !{i32 57, i32 2, metadata !52, null}
!54 = metadata !{i32 58, i32 2, metadata !37, null}
!55 = metadata !{i32 60, i32 3, metadata !56, null}
!56 = metadata !{i32 786443, metadata !37, i32 59, i32 2, metadata !24, i32 4} ; [ DW_TAG_lexical_block ]
!57 = metadata !{i32 71, i32 2, metadata !37, null}
!58 = metadata !{i32 62, i32 8, metadata !59, null}
!59 = metadata !{i32 786443, metadata !56, i32 62, i32 3, metadata !24, i32 5} ; [ DW_TAG_lexical_block ]
!60 = metadata !{i32 64, i32 4, metadata !61, null}
!61 = metadata !{i32 786443, metadata !59, i32 63, i32 3, metadata !24, i32 6} ; [ DW_TAG_lexical_block ]
!62 = metadata !{i32 62, i32 37, metadata !59, null}
!63 = metadata !{i32 786688, metadata !37, metadata !"i", metadata !24, i32 33, metadata !27, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!64 = metadata !{i32 73, i32 3, metadata !65, null}
!65 = metadata !{i32 786443, metadata !37, i32 72, i32 2, metadata !24, i32 8} ; [ DW_TAG_lexical_block ]
!66 = metadata !{i32 75, i32 8, metadata !67, null}
!67 = metadata !{i32 786443, metadata !65, i32 75, i32 3, metadata !24, i32 9} ; [ DW_TAG_lexical_block ]
!68 = metadata !{i32 77, i32 4, metadata !69, null}
!69 = metadata !{i32 786443, metadata !67, i32 76, i32 3, metadata !24, i32 10} ; [ DW_TAG_lexical_block ]
!70 = metadata !{i32 75, i32 37, metadata !67, null}
!71 = metadata !{i32 84, i32 2, metadata !37, null}
