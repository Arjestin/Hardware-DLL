; ModuleID = 'C:/xilinx/hls/fibonacci/.autopilot/db/a.o.2.bc'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"
target triple = "x86_64-w64-mingw32"

@targeted_function.str = internal unnamed_addr constant [18 x i8] c"targeted_function\00" ; [#uses=1 type=[18 x i8]*]
@.str2 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1 ; [#uses=9 type=[1 x i8]*]
@.str1 = private unnamed_addr constant [3 x i8] c"rm\00", align 1 ; [#uses=3 type=[3 x i8]*]
@.str = private unnamed_addr constant [10 x i8] c"s_axilite\00", align 1 ; [#uses=3 type=[10 x i8]*]

; [#uses=0]
define i32 @targeted_function(i32 %input_000, i32* %output_000) nounwind uwtable {
  call void (...)* @_ssdm_op_SpecBitsMap(i32 %input_000) nounwind, !map !13
  call void (...)* @_ssdm_op_SpecBitsMap(i32* %output_000) nounwind, !map !19
  call void (...)* @_ssdm_op_SpecBitsMap(i32 0) nounwind, !map !25
  call void (...)* @_ssdm_op_SpecTopModule([18 x i8]* @targeted_function.str) nounwind
  call void @llvm.dbg.value(metadata !{i32 %input_000}, i64 0, metadata !31), !dbg !32 ; [debug line = 24:28] [debug variable = input_000]
  call void @llvm.dbg.value(metadata !{i32* %output_000}, i64 0, metadata !33), !dbg !34 ; [debug line = 24:44] [debug variable = output_000]
  call void (...)* @_ssdm_op_SpecInterface(i32* %output_000, [10 x i8]* @.str, i32 0, i32 0, i32 0, i32 0, [3 x i8]* @.str1, [1 x i8]* @.str2, [1 x i8]* @.str2, [1 x i8]* @.str2) nounwind, !dbg !35 ; [debug line = 26:1]
  call void (...)* @_ssdm_op_SpecInterface(i32 %input_000, [10 x i8]* @.str, i32 0, i32 0, i32 0, i32 0, [3 x i8]* @.str1, [1 x i8]* @.str2, [1 x i8]* @.str2, [1 x i8]* @.str2) nounwind, !dbg !35 ; [debug line = 26:1]
  call void (...)* @_ssdm_op_SpecInterface(i32 0, [10 x i8]* @.str, i32 0, i32 0, i32 0, i32 0, [3 x i8]* @.str1, [1 x i8]* @.str2, [1 x i8]* @.str2, [1 x i8]* @.str2) nounwind, !dbg !35 ; [debug line = 26:1]
  %tmp = icmp slt i32 %input_000, 0, !dbg !37     ; [#uses=1 type=i1] [debug line = 27:2]
  %tmp.1 = icmp sgt i32 %input_000, 46, !dbg !37  ; [#uses=1 type=i1] [debug line = 27:2]
  %or.cond = or i1 %tmp, %tmp.1, !dbg !37         ; [#uses=1 type=i1] [debug line = 27:2]
  br i1 %or.cond, label %1, label %2, !dbg !37    ; [debug line = 27:2]

; <label>:1                                       ; preds = %0
  store i32 -1, i32* %output_000, align 4, !dbg !38 ; [debug line = 29:3]
  br label %.loopexit, !dbg !40                   ; [debug line = 30:3]

; <label>:2                                       ; preds = %0
  %tmp.2 = icmp slt i32 %input_000, 2, !dbg !41   ; [#uses=1 type=i1] [debug line = 32:2]
  br i1 %tmp.2, label %3, label %.preheader, !dbg !41 ; [debug line = 32:2]

; <label>:3                                       ; preds = %2
  store i32 %input_000, i32* %output_000, align 4, !dbg !42 ; [debug line = 34:3]
  br label %.loopexit, !dbg !44                   ; [debug line = 35:3]

.preheader:                                       ; preds = %5, %2
  %i = phi i6 [ %i.1, %5 ], [ 1, %2 ]             ; [#uses=2 type=i6]
  %first = phi i32 [ %first.1, %5 ], [ 0, %2 ]    ; [#uses=1 type=i32]
  %first.1 = phi i32 [ %second, %5 ], [ 1, %2 ]   ; [#uses=2 type=i32]
  %i.cast = zext i6 %i to i32, !dbg !45           ; [#uses=1 type=i32] [debug line = 37:7]
  %exitcond = icmp eq i32 %i.cast, %input_000, !dbg !45 ; [#uses=1 type=i1] [debug line = 37:7]
  %4 = call i32 (...)* @_ssdm_op_SpecLoopTripCount(i64 1, i64 45, i64 0) nounwind ; [#uses=0 type=i32]
  br i1 %exitcond, label %.loopexit, label %5, !dbg !45 ; [debug line = 37:7]

; <label>:5                                       ; preds = %.preheader
  %second = add nsw i32 %first.1, %first, !dbg !47 ; [#uses=2 type=i32] [debug line = 39:3]
  store i32 %second, i32* %output_000, align 4, !dbg !47 ; [debug line = 39:3]
  call void @llvm.dbg.value(metadata !{i32 %first.1}, i64 0, metadata !49), !dbg !50 ; [debug line = 40:3] [debug variable = first]
  call void @llvm.dbg.value(metadata !{i32 %second}, i64 0, metadata !51), !dbg !52 ; [debug line = 41:3] [debug variable = second]
  %i.1 = add i6 %i, 1, !dbg !53                   ; [#uses=1 type=i6] [debug line = 37:29]
  call void @llvm.dbg.value(metadata !{i6 %i.1}, i64 0, metadata !54), !dbg !53 ; [debug line = 37:29] [debug variable = i]
  br label %.preheader, !dbg !53                  ; [debug line = 37:29]

.loopexit:                                        ; preds = %.preheader, %3, %1
  %.0 = phi i1 [ true, %1 ], [ false, %3 ], [ false, %.preheader ] ; [#uses=1 type=i1]
  %.0.cast = sext i1 %.0 to i32, !dbg !55         ; [#uses=1 type=i32] [debug line = 44:1]
  ret i32 %.0.cast, !dbg !55                      ; [debug line = 44:1]
}

; [#uses=5]
declare void @llvm.dbg.value(metadata, i64, metadata) nounwind readnone

; [#uses=1]
declare void @_ssdm_op_SpecTopModule(...)

; [#uses=1]
declare i32 @_ssdm_op_SpecLoopTripCount(...)

; [#uses=3]
declare void @_ssdm_op_SpecInterface(...) nounwind

; [#uses=3]
declare void @_ssdm_op_SpecBitsMap(...)

!llvm.dbg.cu = !{!0}
!hls.encrypted.func = !{}
!llvm.map.gv = !{}

!0 = metadata !{i32 786449, i32 0, i32 1, metadata !"C:/xilinx/hls/fibonacci/.autopilot/db/targeted_function.pragma.2.c", metadata !"c:/xilinx", metadata !"clang version 3.1 ", i1 true, i1 false, metadata !"", i32 0, metadata !1, metadata !1, metadata !3, metadata !1} ; [ DW_TAG_compile_unit ]
!1 = metadata !{metadata !2}
!2 = metadata !{i32 0}
!3 = metadata !{metadata !4}
!4 = metadata !{metadata !5}
!5 = metadata !{i32 786478, i32 0, metadata !6, metadata !"targeted_function", metadata !"targeted_function", metadata !"", metadata !6, i32 24, metadata !7, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, i32 (i32, i32*)* @targeted_function, null, null, metadata !11, i32 25} ; [ DW_TAG_subprogram ]
!6 = metadata !{i32 786473, metadata !"./targeted_functions/fibonacci/targeted_function.c", metadata !"c:/xilinx", null} ; [ DW_TAG_file_type ]
!7 = metadata !{i32 786453, i32 0, metadata !"", i32 0, i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !8, i32 0, i32 0} ; [ DW_TAG_subroutine_type ]
!8 = metadata !{metadata !9, metadata !9, metadata !10}
!9 = metadata !{i32 786468, null, metadata !"int", null, i32 0, i64 32, i64 32, i64 0, i32 0, i32 5} ; [ DW_TAG_base_type ]
!10 = metadata !{i32 786447, null, metadata !"", null, i32 0, i64 64, i64 64, i64 0, i32 0, metadata !9} ; [ DW_TAG_pointer_type ]
!11 = metadata !{metadata !12}
!12 = metadata !{i32 786468}                      ; [ DW_TAG_base_type ]
!13 = metadata !{metadata !14}
!14 = metadata !{i32 0, i32 31, metadata !15}
!15 = metadata !{metadata !16}
!16 = metadata !{metadata !"input_000", metadata !17, metadata !"int", i32 0, i32 31}
!17 = metadata !{metadata !18}
!18 = metadata !{i32 0, i32 0, i32 0}
!19 = metadata !{metadata !20}
!20 = metadata !{i32 0, i32 31, metadata !21}
!21 = metadata !{metadata !22}
!22 = metadata !{metadata !"output_000", metadata !23, metadata !"int", i32 0, i32 31}
!23 = metadata !{metadata !24}
!24 = metadata !{i32 0, i32 0, i32 1}
!25 = metadata !{metadata !26}
!26 = metadata !{i32 0, i32 31, metadata !27}
!27 = metadata !{metadata !28}
!28 = metadata !{metadata !"return", metadata !29, metadata !"int", i32 0, i32 31}
!29 = metadata !{metadata !30}
!30 = metadata !{i32 0, i32 1, i32 0}
!31 = metadata !{i32 786689, metadata !5, metadata !"input_000", metadata !6, i32 16777240, metadata !9, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!32 = metadata !{i32 24, i32 28, metadata !5, null}
!33 = metadata !{i32 786689, metadata !5, metadata !"output_000", metadata !6, i32 33554456, metadata !10, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!34 = metadata !{i32 24, i32 44, metadata !5, null}
!35 = metadata !{i32 26, i32 1, metadata !36, null}
!36 = metadata !{i32 786443, metadata !5, i32 25, i32 1, metadata !6, i32 0} ; [ DW_TAG_lexical_block ]
!37 = metadata !{i32 27, i32 2, metadata !36, null}
!38 = metadata !{i32 29, i32 3, metadata !39, null}
!39 = metadata !{i32 786443, metadata !36, i32 28, i32 2, metadata !6, i32 1} ; [ DW_TAG_lexical_block ]
!40 = metadata !{i32 30, i32 3, metadata !39, null}
!41 = metadata !{i32 32, i32 2, metadata !36, null}
!42 = metadata !{i32 34, i32 3, metadata !43, null}
!43 = metadata !{i32 786443, metadata !36, i32 33, i32 2, metadata !6, i32 2} ; [ DW_TAG_lexical_block ]
!44 = metadata !{i32 35, i32 3, metadata !43, null}
!45 = metadata !{i32 37, i32 7, metadata !46, null}
!46 = metadata !{i32 786443, metadata !36, i32 37, i32 2, metadata !6, i32 3} ; [ DW_TAG_lexical_block ]
!47 = metadata !{i32 39, i32 3, metadata !48, null}
!48 = metadata !{i32 786443, metadata !46, i32 38, i32 2, metadata !6, i32 4} ; [ DW_TAG_lexical_block ]
!49 = metadata !{i32 786688, metadata !36, metadata !"first", metadata !6, i32 26, metadata !9, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!50 = metadata !{i32 40, i32 3, metadata !48, null}
!51 = metadata !{i32 786688, metadata !36, metadata !"second", metadata !6, i32 26, metadata !9, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!52 = metadata !{i32 41, i32 3, metadata !48, null}
!53 = metadata !{i32 37, i32 29, metadata !46, null}
!54 = metadata !{i32 786688, metadata !36, metadata !"i", metadata !6, i32 26, metadata !9, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!55 = metadata !{i32 44, i32 1, metadata !36, null}
