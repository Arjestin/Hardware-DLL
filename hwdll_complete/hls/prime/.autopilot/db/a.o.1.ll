; ModuleID = 'C:/xilinx/hls/prime/.autopilot/db/a.g.1.bc'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"
target triple = "x86_64-w64-mingw32"

@targeted_function.str = internal unnamed_addr constant [18 x i8] c"targeted_function\00" ; [#uses=1 type=[18 x i8]*]
@.str2 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1 ; [#uses=1 type=[1 x i8]*]
@.str1 = private unnamed_addr constant [3 x i8] c"rm\00", align 1 ; [#uses=1 type=[3 x i8]*]
@.str = private unnamed_addr constant [10 x i8] c"s_axilite\00", align 1 ; [#uses=1 type=[10 x i8]*]

; [#uses=0]
define i32 @targeted_function(i32 %input_000, i32* %output_000) nounwind uwtable {
  call void (...)* @_ssdm_op_SpecBitsMap(i32 0) nounwind, !map !13
  call void (...)* @_ssdm_op_SpecTopModule([18 x i8]* @targeted_function.str) nounwind
  call void @llvm.dbg.value(metadata !{i32 %input_000}, i64 0, metadata !19), !dbg !20 ; [debug line = 24:28] [debug variable = input_000]
  call void @llvm.dbg.value(metadata !{i32* %output_000}, i64 0, metadata !21), !dbg !22 ; [debug line = 24:44] [debug variable = output_000]
  call void (...)* @_ssdm_op_SpecInterface(i32* %output_000, i8* getelementptr inbounds ([10 x i8]* @.str, i64 0, i64 0), i32 0, i32 0, i32 0, i32 0, i8* getelementptr inbounds ([3 x i8]* @.str1, i64 0, i64 0), i8* getelementptr inbounds ([1 x i8]* @.str2, i64 0, i64 0), i8* getelementptr inbounds ([1 x i8]* @.str2, i64 0, i64 0), i8* getelementptr inbounds ([1 x i8]* @.str2, i64 0, i64 0)), !dbg !23 ; [debug line = 26:1]
  call void (...)* @_ssdm_op_SpecInterface(i32 %input_000, i8* getelementptr inbounds ([10 x i8]* @.str, i64 0, i64 0), i32 0, i32 0, i32 0, i32 0, i8* getelementptr inbounds ([3 x i8]* @.str1, i64 0, i64 0), i8* getelementptr inbounds ([1 x i8]* @.str2, i64 0, i64 0), i8* getelementptr inbounds ([1 x i8]* @.str2, i64 0, i64 0), i8* getelementptr inbounds ([1 x i8]* @.str2, i64 0, i64 0)), !dbg !23 ; [debug line = 26:1]
  call void (...)* @_ssdm_op_SpecInterface(i32 0, i8* getelementptr inbounds ([10 x i8]* @.str, i64 0, i64 0), i32 0, i32 0, i32 0, i32 0, i8* getelementptr inbounds ([3 x i8]* @.str1, i64 0, i64 0), i8* getelementptr inbounds ([1 x i8]* @.str2, i64 0, i64 0), i8* getelementptr inbounds ([1 x i8]* @.str2, i64 0, i64 0), i8* getelementptr inbounds ([1 x i8]* @.str2, i64 0, i64 0)), !dbg !23 ; [debug line = 26:1]
  %tmp = icmp slt i32 %input_000, 1, !dbg !25     ; [#uses=1 type=i1] [debug line = 27:2]
  %tmp.1 = icmp sgt i32 %input_000, 105097565, !dbg !25 ; [#uses=1 type=i1] [debug line = 27:2]
  %or.cond = or i1 %tmp, %tmp.1, !dbg !25         ; [#uses=1 type=i1] [debug line = 27:2]
  br i1 %or.cond, label %1, label %2, !dbg !25    ; [debug line = 27:2]

; <label>:1                                       ; preds = %0
  store i32 -1, i32* %output_000, align 4, !dbg !26 ; [debug line = 29:3]
  br label %.loopexit3, !dbg !28                  ; [debug line = 30:3]

; <label>:2                                       ; preds = %0
  store i32 2, i32* %output_000, align 4, !dbg !29 ; [debug line = 32:2]
  br label %3, !dbg !30                           ; [debug line = 33:7]

; <label>:3                                       ; preds = %.loopexit._crit_edge, %2
  %i = phi i32 [ 2, %2 ], [ %i.1, %.loopexit._crit_edge ] ; [#uses=3 type=i32]
  %ctr = phi i32 [ 3, %2 ], [ %ctr.1, %.loopexit._crit_edge ] ; [#uses=5 type=i32]
  %tmp.2 = icmp sgt i32 %i, %input_000, !dbg !30  ; [#uses=1 type=i1] [debug line = 33:7]
  br i1 %tmp.2, label %.loopexit3.loopexit, label %.preheader.preheader, !dbg !30 ; [debug line = 33:7]

.preheader.preheader:                             ; preds = %3
  %tmp.3 = add nsw i32 %ctr, -1, !dbg !32         ; [#uses=1 type=i32] [debug line = 35:8]
  br label %.preheader, !dbg !32                  ; [debug line = 35:8]

.preheader:                                       ; preds = %5, %.preheader.preheader
  %j = phi i32 [ %j.1, %5 ], [ 2, %.preheader.preheader ] ; [#uses=5 type=i32]
  %tmp.4 = icmp sgt i32 %j, %tmp.3, !dbg !32      ; [#uses=1 type=i1] [debug line = 35:8]
  br i1 %tmp.4, label %.loopexit, label %4, !dbg !32 ; [debug line = 35:8]

; <label>:4                                       ; preds = %.preheader
  %tmp.5 = srem i32 %ctr, %j, !dbg !35            ; [#uses=1 type=i32] [debug line = 37:4]
  %tmp.6 = icmp eq i32 %tmp.5, 0, !dbg !35        ; [#uses=1 type=i1] [debug line = 37:4]
  br i1 %tmp.6, label %.loopexit, label %5, !dbg !35 ; [debug line = 37:4]

; <label>:5                                       ; preds = %4
  %j.1 = add nsw i32 %j, 1, !dbg !37              ; [#uses=1 type=i32] [debug line = 35:29]
  call void @llvm.dbg.value(metadata !{i32 %j.1}, i64 0, metadata !38), !dbg !37 ; [debug line = 35:29] [debug variable = j]
  br label %.preheader, !dbg !37                  ; [debug line = 35:29]

.loopexit:                                        ; preds = %4, %.preheader
  %j.0.lcssa = phi i32 [ %j, %4 ], [ %j, %.preheader ] ; [#uses=1 type=i32]
  %tmp.7 = icmp eq i32 %ctr, %j.0.lcssa, !dbg !39 ; [#uses=1 type=i1] [debug line = 42:3]
  br i1 %tmp.7, label %6, label %.loopexit._crit_edge, !dbg !39 ; [debug line = 42:3]

; <label>:6                                       ; preds = %.loopexit
  store i32 %ctr, i32* %output_000, align 4, !dbg !40 ; [debug line = 44:4]
  %i.2 = add nsw i32 %i, 1, !dbg !42              ; [#uses=1 type=i32] [debug line = 45:4]
  call void @llvm.dbg.value(metadata !{i32 %i.2}, i64 0, metadata !43), !dbg !42 ; [debug line = 45:4] [debug variable = i]
  br label %.loopexit._crit_edge, !dbg !44        ; [debug line = 46:3]

.loopexit._crit_edge:                             ; preds = %6, %.loopexit
  %i.1 = phi i32 [ %i.2, %6 ], [ %i, %.loopexit ] ; [#uses=1 type=i32]
  %ctr.1 = add nsw i32 %ctr, 1, !dbg !45          ; [#uses=1 type=i32] [debug line = 47:3]
  call void @llvm.dbg.value(metadata !{i32 %ctr.1}, i64 0, metadata !46), !dbg !45 ; [debug line = 47:3] [debug variable = ctr]
  br label %3, !dbg !47                           ; [debug line = 48:2]

.loopexit3.loopexit:                              ; preds = %3
  br label %.loopexit3

.loopexit3:                                       ; preds = %.loopexit3.loopexit, %1
  %.0 = phi i32 [ -1, %1 ], [ 0, %.loopexit3.loopexit ] ; [#uses=1 type=i32]
  ret i32 %.0, !dbg !48                           ; [debug line = 50:1]
}

; [#uses=5]
declare void @llvm.dbg.value(metadata, i64, metadata) nounwind readnone

; [#uses=1]
declare void @_ssdm_op_SpecTopModule(...)

; [#uses=3]
declare void @_ssdm_op_SpecInterface(...) nounwind

; [#uses=1]
declare void @_ssdm_op_SpecBitsMap(...)

!llvm.dbg.cu = !{!0}
!hls.encrypted.func = !{}

!0 = metadata !{i32 786449, i32 0, i32 1, metadata !"C:/xilinx/hls/prime/.autopilot/db/targeted_function.pragma.2.c", metadata !"c:/xilinx", metadata !"clang version 3.1 ", i1 true, i1 false, metadata !"", i32 0, metadata !1, metadata !1, metadata !3, metadata !1} ; [ DW_TAG_compile_unit ]
!1 = metadata !{metadata !2}
!2 = metadata !{i32 0}
!3 = metadata !{metadata !4}
!4 = metadata !{metadata !5}
!5 = metadata !{i32 786478, i32 0, metadata !6, metadata !"targeted_function", metadata !"targeted_function", metadata !"", metadata !6, i32 24, metadata !7, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, i32 (i32, i32*)* @targeted_function, null, null, metadata !11, i32 25} ; [ DW_TAG_subprogram ]
!6 = metadata !{i32 786473, metadata !"./targeted_functions/prime/targeted_function.c", metadata !"c:/xilinx", null} ; [ DW_TAG_file_type ]
!7 = metadata !{i32 786453, i32 0, metadata !"", i32 0, i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !8, i32 0, i32 0} ; [ DW_TAG_subroutine_type ]
!8 = metadata !{metadata !9, metadata !9, metadata !10}
!9 = metadata !{i32 786468, null, metadata !"int", null, i32 0, i64 32, i64 32, i64 0, i32 0, i32 5} ; [ DW_TAG_base_type ]
!10 = metadata !{i32 786447, null, metadata !"", null, i32 0, i64 64, i64 64, i64 0, i32 0, metadata !9} ; [ DW_TAG_pointer_type ]
!11 = metadata !{metadata !12}
!12 = metadata !{i32 786468}                      ; [ DW_TAG_base_type ]
!13 = metadata !{metadata !14}
!14 = metadata !{i32 0, i32 31, metadata !15}
!15 = metadata !{metadata !16}
!16 = metadata !{metadata !"return", metadata !17, metadata !"int", i32 0, i32 31}
!17 = metadata !{metadata !18}
!18 = metadata !{i32 0, i32 1, i32 0}
!19 = metadata !{i32 786689, metadata !5, metadata !"input_000", metadata !6, i32 16777240, metadata !9, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!20 = metadata !{i32 24, i32 28, metadata !5, null}
!21 = metadata !{i32 786689, metadata !5, metadata !"output_000", metadata !6, i32 33554456, metadata !10, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!22 = metadata !{i32 24, i32 44, metadata !5, null}
!23 = metadata !{i32 26, i32 1, metadata !24, null}
!24 = metadata !{i32 786443, metadata !5, i32 25, i32 1, metadata !6, i32 0} ; [ DW_TAG_lexical_block ]
!25 = metadata !{i32 27, i32 2, metadata !24, null}
!26 = metadata !{i32 29, i32 3, metadata !27, null}
!27 = metadata !{i32 786443, metadata !24, i32 28, i32 2, metadata !6, i32 1} ; [ DW_TAG_lexical_block ]
!28 = metadata !{i32 30, i32 3, metadata !27, null}
!29 = metadata !{i32 32, i32 2, metadata !24, null}
!30 = metadata !{i32 33, i32 7, metadata !31, null}
!31 = metadata !{i32 786443, metadata !24, i32 33, i32 2, metadata !6, i32 2} ; [ DW_TAG_lexical_block ]
!32 = metadata !{i32 35, i32 8, metadata !33, null}
!33 = metadata !{i32 786443, metadata !34, i32 35, i32 3, metadata !6, i32 4} ; [ DW_TAG_lexical_block ]
!34 = metadata !{i32 786443, metadata !31, i32 34, i32 2, metadata !6, i32 3} ; [ DW_TAG_lexical_block ]
!35 = metadata !{i32 37, i32 4, metadata !36, null}
!36 = metadata !{i32 786443, metadata !33, i32 36, i32 3, metadata !6, i32 5} ; [ DW_TAG_lexical_block ]
!37 = metadata !{i32 35, i32 29, metadata !33, null}
!38 = metadata !{i32 786688, metadata !24, metadata !"j", metadata !6, i32 26, metadata !9, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!39 = metadata !{i32 42, i32 3, metadata !34, null}
!40 = metadata !{i32 44, i32 4, metadata !41, null}
!41 = metadata !{i32 786443, metadata !34, i32 43, i32 3, metadata !6, i32 7} ; [ DW_TAG_lexical_block ]
!42 = metadata !{i32 45, i32 4, metadata !41, null}
!43 = metadata !{i32 786688, metadata !24, metadata !"i", metadata !6, i32 26, metadata !9, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!44 = metadata !{i32 46, i32 3, metadata !41, null}
!45 = metadata !{i32 47, i32 3, metadata !34, null}
!46 = metadata !{i32 786688, metadata !24, metadata !"ctr", metadata !6, i32 26, metadata !9, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!47 = metadata !{i32 48, i32 2, metadata !34, null}
!48 = metadata !{i32 50, i32 1, metadata !24, null}
