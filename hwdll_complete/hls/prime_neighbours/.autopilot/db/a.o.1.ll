; ModuleID = 'C:/xilinx/hls/prime_neighbours/.autopilot/db/a.g.1.bc'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"
target triple = "x86_64-w64-mingw32"

@targeted_function.str = internal unnamed_addr constant [18 x i8] c"targeted_function\00" ; [#uses=1 type=[18 x i8]*]
@.str2 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1 ; [#uses=1 type=[1 x i8]*]
@.str1 = private unnamed_addr constant [3 x i8] c"rm\00", align 1 ; [#uses=1 type=[3 x i8]*]
@.str = private unnamed_addr constant [10 x i8] c"s_axilite\00", align 1 ; [#uses=1 type=[10 x i8]*]

; [#uses=0]
define i32 @targeted_function(i32 %input_000, i32* %output_000, i32* %output_001) nounwind uwtable {
  call void (...)* @_ssdm_op_SpecBitsMap(i32 0) nounwind, !map !13
  call void (...)* @_ssdm_op_SpecTopModule([18 x i8]* @targeted_function.str) nounwind
  call void @llvm.dbg.value(metadata !{i32 %input_000}, i64 0, metadata !19), !dbg !20 ; [debug line = 31:28] [debug variable = input_000]
  call void @llvm.dbg.value(metadata !{i32* %output_000}, i64 0, metadata !21), !dbg !22 ; [debug line = 31:44] [debug variable = output_000]
  call void @llvm.dbg.value(metadata !{i32* %output_001}, i64 0, metadata !23), !dbg !24 ; [debug line = 31:61] [debug variable = output_001]
  call void (...)* @_ssdm_op_SpecInterface(i32* %output_001, i8* getelementptr inbounds ([10 x i8]* @.str, i64 0, i64 0), i32 0, i32 0, i32 0, i32 0, i8* getelementptr inbounds ([3 x i8]* @.str1, i64 0, i64 0), i8* getelementptr inbounds ([1 x i8]* @.str2, i64 0, i64 0), i8* getelementptr inbounds ([1 x i8]* @.str2, i64 0, i64 0), i8* getelementptr inbounds ([1 x i8]* @.str2, i64 0, i64 0)), !dbg !25 ; [debug line = 33:1]
  call void (...)* @_ssdm_op_SpecInterface(i32* %output_000, i8* getelementptr inbounds ([10 x i8]* @.str, i64 0, i64 0), i32 0, i32 0, i32 0, i32 0, i8* getelementptr inbounds ([3 x i8]* @.str1, i64 0, i64 0), i8* getelementptr inbounds ([1 x i8]* @.str2, i64 0, i64 0), i8* getelementptr inbounds ([1 x i8]* @.str2, i64 0, i64 0), i8* getelementptr inbounds ([1 x i8]* @.str2, i64 0, i64 0)), !dbg !25 ; [debug line = 33:1]
  call void (...)* @_ssdm_op_SpecInterface(i32 %input_000, i8* getelementptr inbounds ([10 x i8]* @.str, i64 0, i64 0), i32 0, i32 0, i32 0, i32 0, i8* getelementptr inbounds ([3 x i8]* @.str1, i64 0, i64 0), i8* getelementptr inbounds ([1 x i8]* @.str2, i64 0, i64 0), i8* getelementptr inbounds ([1 x i8]* @.str2, i64 0, i64 0), i8* getelementptr inbounds ([1 x i8]* @.str2, i64 0, i64 0)), !dbg !25 ; [debug line = 33:1]
  call void (...)* @_ssdm_op_SpecInterface(i32 0, i8* getelementptr inbounds ([10 x i8]* @.str, i64 0, i64 0), i32 0, i32 0, i32 0, i32 0, i8* getelementptr inbounds ([3 x i8]* @.str1, i64 0, i64 0), i8* getelementptr inbounds ([1 x i8]* @.str2, i64 0, i64 0), i8* getelementptr inbounds ([1 x i8]* @.str2, i64 0, i64 0), i8* getelementptr inbounds ([1 x i8]* @.str2, i64 0, i64 0)), !dbg !25 ; [debug line = 33:1]
  store i32 %input_000, i32* %output_000, align 4, !dbg !27 ; [debug line = 34:2]
  store i32 %input_000, i32* %output_001, align 4, !dbg !28 ; [debug line = 35:2]
  %tmp = icmp slt i32 %input_000, 2, !dbg !29     ; [#uses=1 type=i1] [debug line = 36:2]
  br i1 %tmp, label %1, label %._crit_edge, !dbg !29 ; [debug line = 36:2]

; <label>:1                                       ; preds = %0
  store i32 -1, i32* %output_000, align 4, !dbg !30 ; [debug line = 38:3]
  store i32 2, i32* %output_001, align 4, !dbg !32 ; [debug line = 39:3]
  br label %._crit_edge, !dbg !33                 ; [debug line = 43:2]

._crit_edge:                                      ; preds = %1, %0
  %flag_0 = phi i32 [ 1, %1 ], [ 0, %0 ]          ; [#uses=1 type=i32]
  %retval = phi i32 [ -1, %1 ], [ 0, %0 ]         ; [#uses=1 type=i32]
  %tmp.1 = icmp eq i32 %input_000, 2, !dbg !34    ; [#uses=1 type=i1] [debug line = 44:2]
  br i1 %tmp.1, label %2, label %._crit_edge2, !dbg !34 ; [debug line = 44:2]

; <label>:2                                       ; preds = %._crit_edge
  store i32 -1, i32* %output_000, align 4, !dbg !35 ; [debug line = 46:3]
  store i32 3, i32* %output_001, align 4, !dbg !37 ; [debug line = 47:3]
  br label %._crit_edge2, !dbg !38                ; [debug line = 51:2]

._crit_edge2:                                     ; preds = %2, %._crit_edge
  %flag_0.1 = phi i32 [ 1, %2 ], [ %flag_0, %._crit_edge ] ; [#uses=2 type=i32]
  %retval.1 = phi i32 [ -1, %2 ], [ %retval, %._crit_edge ] ; [#uses=1 type=i32]
  %tmp.2 = icmp eq i32 %input_000, 2147483647, !dbg !39 ; [#uses=1 type=i1] [debug line = 52:2]
  br i1 %tmp.2, label %3, label %._crit_edge3, !dbg !39 ; [debug line = 52:2]

; <label>:3                                       ; preds = %._crit_edge2
  store i32 -1, i32* %output_001, align 4, !dbg !40 ; [debug line = 54:3]
  br label %._crit_edge3, !dbg !42                ; [debug line = 57:2]

._crit_edge3:                                     ; preds = %3, %._crit_edge2
  %flag_1.2 = phi i32 [ 1, %3 ], [ %flag_0.1, %._crit_edge2 ] ; [#uses=1 type=i32]
  %retval.2 = phi i32 [ -1, %3 ], [ %retval.1, %._crit_edge2 ] ; [#uses=1 type=i32]
  br label %.loopexit1, !dbg !43                  ; [debug line = 58:2]

.loopexit1.loopexit:                              ; preds = %6, %5
  %flag_0.2.ph = phi i32 [ 0, %6 ], [ 1, %5 ]     ; [#uses=1 type=i32]
  br label %.loopexit1

.loopexit1:                                       ; preds = %.loopexit1.loopexit, %._crit_edge3
  %flag_0.2 = phi i32 [ %flag_0.1, %._crit_edge3 ], [ %flag_0.2.ph, %.loopexit1.loopexit ] ; [#uses=1 type=i32]
  %tmp.3 = icmp eq i32 %flag_0.2, 1, !dbg !43     ; [#uses=1 type=i1] [debug line = 58:2]
  br i1 %tmp.3, label %.loopexit.preheader, label %4, !dbg !43 ; [debug line = 58:2]

.loopexit.preheader:                              ; preds = %.loopexit1
  br label %.loopexit, !dbg !44                   ; [debug line = 71:2]

; <label>:4                                       ; preds = %.loopexit1
  %output_000.load = load i32* %output_000, align 4, !dbg !45 ; [#uses=1 type=i32] [debug line = 60:3]
  %tmp.4 = add nsw i32 %output_000.load, -1, !dbg !45 ; [#uses=3 type=i32] [debug line = 60:3]
  store i32 %tmp.4, i32* %output_000, align 4, !dbg !45 ; [debug line = 60:3]
  %tmp.5 = sdiv i32 %tmp.4, 2, !dbg !47           ; [#uses=1 type=i32] [debug line = 62:8]
  br label %5, !dbg !47                           ; [debug line = 62:8]

; <label>:5                                       ; preds = %7, %4
  %i = phi i32 [ 2, %4 ], [ %i.2, %7 ]            ; [#uses=3 type=i32]
  %tmp.7 = icmp sgt i32 %i, %tmp.5, !dbg !47      ; [#uses=1 type=i1] [debug line = 62:8]
  br i1 %tmp.7, label %.loopexit1.loopexit, label %6, !dbg !47 ; [debug line = 62:8]

; <label>:6                                       ; preds = %5
  %tmp.10 = srem i32 %tmp.4, %i, !dbg !49         ; [#uses=1 type=i32] [debug line = 64:4]
  %tmp.11 = icmp eq i32 %tmp.10, 0, !dbg !49      ; [#uses=1 type=i1] [debug line = 64:4]
  br i1 %tmp.11, label %.loopexit1.loopexit, label %7, !dbg !49 ; [debug line = 64:4]

; <label>:7                                       ; preds = %6
  %i.2 = add nsw i32 %i, 1, !dbg !51              ; [#uses=1 type=i32] [debug line = 62:37]
  call void @llvm.dbg.value(metadata !{i32 %i.2}, i64 0, metadata !52), !dbg !51 ; [debug line = 62:37] [debug variable = i]
  br label %5, !dbg !51                           ; [debug line = 62:37]

.loopexit.loopexit:                               ; preds = %10, %9
  %flag_1.3.ph = phi i32 [ 0, %10 ], [ 1, %9 ]    ; [#uses=1 type=i32]
  br label %.loopexit

.loopexit:                                        ; preds = %.loopexit.loopexit, %.loopexit.preheader
  %flag_1.3 = phi i32 [ %flag_1.3.ph, %.loopexit.loopexit ], [ %flag_1.2, %.loopexit.preheader ] ; [#uses=1 type=i32]
  %tmp.6 = icmp eq i32 %flag_1.3, 1, !dbg !44     ; [#uses=1 type=i1] [debug line = 71:2]
  br i1 %tmp.6, label %12, label %8, !dbg !44     ; [debug line = 71:2]

; <label>:8                                       ; preds = %.loopexit
  %output_001.load = load i32* %output_001, align 4, !dbg !53 ; [#uses=1 type=i32] [debug line = 73:3]
  %tmp.8 = add nsw i32 %output_001.load, 1, !dbg !53 ; [#uses=3 type=i32] [debug line = 73:3]
  store i32 %tmp.8, i32* %output_001, align 4, !dbg !53 ; [debug line = 73:3]
  %tmp.9 = sdiv i32 %tmp.8, 2, !dbg !55           ; [#uses=1 type=i32] [debug line = 75:8]
  br label %9, !dbg !55                           ; [debug line = 75:8]

; <label>:9                                       ; preds = %11, %8
  %i.1 = phi i32 [ 2, %8 ], [ %i.3, %11 ]         ; [#uses=3 type=i32]
  %tmp.12 = icmp sgt i32 %i.1, %tmp.9, !dbg !55   ; [#uses=1 type=i1] [debug line = 75:8]
  br i1 %tmp.12, label %.loopexit.loopexit, label %10, !dbg !55 ; [debug line = 75:8]

; <label>:10                                      ; preds = %9
  %tmp.14 = srem i32 %tmp.8, %i.1, !dbg !57       ; [#uses=1 type=i32] [debug line = 77:4]
  %tmp.15 = icmp eq i32 %tmp.14, 0, !dbg !57      ; [#uses=1 type=i1] [debug line = 77:4]
  br i1 %tmp.15, label %.loopexit.loopexit, label %11, !dbg !57 ; [debug line = 77:4]

; <label>:11                                      ; preds = %10
  %i.3 = add nsw i32 %i.1, 1, !dbg !59            ; [#uses=1 type=i32] [debug line = 75:37]
  call void @llvm.dbg.value(metadata !{i32 %i.3}, i64 0, metadata !52), !dbg !59 ; [debug line = 75:37] [debug variable = i]
  br label %9, !dbg !59                           ; [debug line = 75:37]

; <label>:12                                      ; preds = %.loopexit
  ret i32 %retval.2, !dbg !60                     ; [debug line = 84:2]
}

; [#uses=5]
declare void @llvm.dbg.value(metadata, i64, metadata) nounwind readnone

; [#uses=1]
declare void @_ssdm_op_SpecTopModule(...)

; [#uses=4]
declare void @_ssdm_op_SpecInterface(...) nounwind

; [#uses=1]
declare void @_ssdm_op_SpecBitsMap(...)

!llvm.dbg.cu = !{!0}
!hls.encrypted.func = !{}

!0 = metadata !{i32 786449, i32 0, i32 1, metadata !"C:/xilinx/hls/prime_neighbours/.autopilot/db/targeted_function.pragma.2.c", metadata !"c:/xilinx", metadata !"clang version 3.1 ", i1 true, i1 false, metadata !"", i32 0, metadata !1, metadata !1, metadata !3, metadata !1} ; [ DW_TAG_compile_unit ]
!1 = metadata !{metadata !2}
!2 = metadata !{i32 0}
!3 = metadata !{metadata !4}
!4 = metadata !{metadata !5}
!5 = metadata !{i32 786478, i32 0, metadata !6, metadata !"targeted_function", metadata !"targeted_function", metadata !"", metadata !6, i32 31, metadata !7, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, i32 (i32, i32*, i32*)* @targeted_function, null, null, metadata !11, i32 32} ; [ DW_TAG_subprogram ]
!6 = metadata !{i32 786473, metadata !"./targeted_functions/prime_neighbours/targeted_function.c", metadata !"c:/xilinx", null} ; [ DW_TAG_file_type ]
!7 = metadata !{i32 786453, i32 0, metadata !"", i32 0, i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !8, i32 0, i32 0} ; [ DW_TAG_subroutine_type ]
!8 = metadata !{metadata !9, metadata !9, metadata !10, metadata !10}
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
!19 = metadata !{i32 786689, metadata !5, metadata !"input_000", metadata !6, i32 16777247, metadata !9, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!20 = metadata !{i32 31, i32 28, metadata !5, null}
!21 = metadata !{i32 786689, metadata !5, metadata !"output_000", metadata !6, i32 33554463, metadata !10, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!22 = metadata !{i32 31, i32 44, metadata !5, null}
!23 = metadata !{i32 786689, metadata !5, metadata !"output_001", metadata !6, i32 50331679, metadata !10, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!24 = metadata !{i32 31, i32 61, metadata !5, null}
!25 = metadata !{i32 33, i32 1, metadata !26, null}
!26 = metadata !{i32 786443, metadata !5, i32 32, i32 1, metadata !6, i32 0} ; [ DW_TAG_lexical_block ]
!27 = metadata !{i32 34, i32 2, metadata !26, null}
!28 = metadata !{i32 35, i32 2, metadata !26, null}
!29 = metadata !{i32 36, i32 2, metadata !26, null}
!30 = metadata !{i32 38, i32 3, metadata !31, null}
!31 = metadata !{i32 786443, metadata !26, i32 37, i32 2, metadata !6, i32 1} ; [ DW_TAG_lexical_block ]
!32 = metadata !{i32 39, i32 3, metadata !31, null}
!33 = metadata !{i32 43, i32 2, metadata !31, null}
!34 = metadata !{i32 44, i32 2, metadata !26, null}
!35 = metadata !{i32 46, i32 3, metadata !36, null}
!36 = metadata !{i32 786443, metadata !26, i32 45, i32 2, metadata !6, i32 2} ; [ DW_TAG_lexical_block ]
!37 = metadata !{i32 47, i32 3, metadata !36, null}
!38 = metadata !{i32 51, i32 2, metadata !36, null}
!39 = metadata !{i32 52, i32 2, metadata !26, null}
!40 = metadata !{i32 54, i32 3, metadata !41, null}
!41 = metadata !{i32 786443, metadata !26, i32 53, i32 2, metadata !6, i32 3} ; [ DW_TAG_lexical_block ]
!42 = metadata !{i32 57, i32 2, metadata !41, null}
!43 = metadata !{i32 58, i32 2, metadata !26, null}
!44 = metadata !{i32 71, i32 2, metadata !26, null}
!45 = metadata !{i32 60, i32 3, metadata !46, null}
!46 = metadata !{i32 786443, metadata !26, i32 59, i32 2, metadata !6, i32 4} ; [ DW_TAG_lexical_block ]
!47 = metadata !{i32 62, i32 8, metadata !48, null}
!48 = metadata !{i32 786443, metadata !46, i32 62, i32 3, metadata !6, i32 5} ; [ DW_TAG_lexical_block ]
!49 = metadata !{i32 64, i32 4, metadata !50, null}
!50 = metadata !{i32 786443, metadata !48, i32 63, i32 3, metadata !6, i32 6} ; [ DW_TAG_lexical_block ]
!51 = metadata !{i32 62, i32 37, metadata !48, null}
!52 = metadata !{i32 786688, metadata !26, metadata !"i", metadata !6, i32 33, metadata !9, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!53 = metadata !{i32 73, i32 3, metadata !54, null}
!54 = metadata !{i32 786443, metadata !26, i32 72, i32 2, metadata !6, i32 8} ; [ DW_TAG_lexical_block ]
!55 = metadata !{i32 75, i32 8, metadata !56, null}
!56 = metadata !{i32 786443, metadata !54, i32 75, i32 3, metadata !6, i32 9} ; [ DW_TAG_lexical_block ]
!57 = metadata !{i32 77, i32 4, metadata !58, null}
!58 = metadata !{i32 786443, metadata !56, i32 76, i32 3, metadata !6, i32 10} ; [ DW_TAG_lexical_block ]
!59 = metadata !{i32 75, i32 37, metadata !56, null}
!60 = metadata !{i32 84, i32 2, metadata !26, null}
