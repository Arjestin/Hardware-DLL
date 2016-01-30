; ModuleID = 'C:/xilinx/hls/multiplier/.autopilot/db/a.o.2.bc'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"
target triple = "x86_64-w64-mingw32"

@targeted_function.str = internal unnamed_addr constant [18 x i8] c"targeted_function\00" ; [#uses=1 type=[18 x i8]*]
@.str2 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1 ; [#uses=12 type=[1 x i8]*]
@.str1 = private unnamed_addr constant [3 x i8] c"rm\00", align 1 ; [#uses=4 type=[3 x i8]*]
@.str = private unnamed_addr constant [10 x i8] c"s_axilite\00", align 1 ; [#uses=4 type=[10 x i8]*]

; [#uses=0]
define i32 @targeted_function(i32 %input_000, i32 %input_001, i32* %output_000) nounwind uwtable {
  call void (...)* @_ssdm_op_SpecBitsMap(i32 %input_000) nounwind, !map !13
  call void (...)* @_ssdm_op_SpecBitsMap(i32 %input_001) nounwind, !map !19
  call void (...)* @_ssdm_op_SpecBitsMap(i32* %output_000) nounwind, !map !23
  call void (...)* @_ssdm_op_SpecBitsMap(i32 0) nounwind, !map !29
  call void (...)* @_ssdm_op_SpecTopModule([18 x i8]* @targeted_function.str) nounwind
  call void @llvm.dbg.value(metadata !{i32 %input_000}, i64 0, metadata !35), !dbg !36 ; [debug line = 24:28] [debug variable = input_000]
  call void @llvm.dbg.value(metadata !{i32 %input_001}, i64 0, metadata !37), !dbg !38 ; [debug line = 24:43] [debug variable = input_001]
  call void @llvm.dbg.value(metadata !{i32* %output_000}, i64 0, metadata !39), !dbg !40 ; [debug line = 24:59] [debug variable = output_000]
  call void (...)* @_ssdm_op_SpecInterface(i32* %output_000, [10 x i8]* @.str, i32 0, i32 0, i32 0, i32 0, [3 x i8]* @.str1, [1 x i8]* @.str2, [1 x i8]* @.str2, [1 x i8]* @.str2) nounwind, !dbg !41 ; [debug line = 26:1]
  call void (...)* @_ssdm_op_SpecInterface(i32 %input_001, [10 x i8]* @.str, i32 0, i32 0, i32 0, i32 0, [3 x i8]* @.str1, [1 x i8]* @.str2, [1 x i8]* @.str2, [1 x i8]* @.str2) nounwind, !dbg !41 ; [debug line = 26:1]
  call void (...)* @_ssdm_op_SpecInterface(i32 %input_000, [10 x i8]* @.str, i32 0, i32 0, i32 0, i32 0, [3 x i8]* @.str1, [1 x i8]* @.str2, [1 x i8]* @.str2, [1 x i8]* @.str2) nounwind, !dbg !41 ; [debug line = 26:1]
  call void (...)* @_ssdm_op_SpecInterface(i32 0, [10 x i8]* @.str, i32 0, i32 0, i32 0, i32 0, [3 x i8]* @.str1, [1 x i8]* @.str2, [1 x i8]* @.str2, [1 x i8]* @.str2) nounwind, !dbg !41 ; [debug line = 26:1]
  %output_000.assign = mul nsw i32 %input_000, %input_001, !dbg !43 ; [#uses=1 type=i32] [debug line = 26:2]
  store i32 %output_000.assign, i32* %output_000, align 4, !dbg !43 ; [debug line = 26:2]
  ret i32 0, !dbg !44                             ; [debug line = 27:2]
}

; [#uses=3]
declare void @llvm.dbg.value(metadata, i64, metadata) nounwind readnone

; [#uses=1]
declare void @_ssdm_op_SpecTopModule(...)

; [#uses=4]
declare void @_ssdm_op_SpecInterface(...) nounwind

; [#uses=4]
declare void @_ssdm_op_SpecBitsMap(...)

!llvm.dbg.cu = !{!0}
!hls.encrypted.func = !{}
!llvm.map.gv = !{}

!0 = metadata !{i32 786449, i32 0, i32 1, metadata !"C:/xilinx/hls/multiplier/.autopilot/db/targeted_function.pragma.2.c", metadata !"c:/xilinx", metadata !"clang version 3.1 ", i1 true, i1 false, metadata !"", i32 0, metadata !1, metadata !1, metadata !3, metadata !1} ; [ DW_TAG_compile_unit ]
!1 = metadata !{metadata !2}
!2 = metadata !{i32 0}
!3 = metadata !{metadata !4}
!4 = metadata !{metadata !5}
!5 = metadata !{i32 786478, i32 0, metadata !6, metadata !"targeted_function", metadata !"targeted_function", metadata !"", metadata !6, i32 24, metadata !7, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, i32 (i32, i32, i32*)* @targeted_function, null, null, metadata !11, i32 25} ; [ DW_TAG_subprogram ]
!6 = metadata !{i32 786473, metadata !"./targeted_functions/multiplier/targeted_function.c", metadata !"c:/xilinx", null} ; [ DW_TAG_file_type ]
!7 = metadata !{i32 786453, i32 0, metadata !"", i32 0, i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !8, i32 0, i32 0} ; [ DW_TAG_subroutine_type ]
!8 = metadata !{metadata !9, metadata !9, metadata !9, metadata !10}
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
!22 = metadata !{metadata !"input_001", metadata !17, metadata !"int", i32 0, i32 31}
!23 = metadata !{metadata !24}
!24 = metadata !{i32 0, i32 31, metadata !25}
!25 = metadata !{metadata !26}
!26 = metadata !{metadata !"output_000", metadata !27, metadata !"int", i32 0, i32 31}
!27 = metadata !{metadata !28}
!28 = metadata !{i32 0, i32 0, i32 1}
!29 = metadata !{metadata !30}
!30 = metadata !{i32 0, i32 31, metadata !31}
!31 = metadata !{metadata !32}
!32 = metadata !{metadata !"return", metadata !33, metadata !"int", i32 0, i32 31}
!33 = metadata !{metadata !34}
!34 = metadata !{i32 0, i32 1, i32 0}
!35 = metadata !{i32 786689, metadata !5, metadata !"input_000", metadata !6, i32 16777240, metadata !9, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!36 = metadata !{i32 24, i32 28, metadata !5, null}
!37 = metadata !{i32 786689, metadata !5, metadata !"input_001", metadata !6, i32 33554456, metadata !9, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!38 = metadata !{i32 24, i32 43, metadata !5, null}
!39 = metadata !{i32 786689, metadata !5, metadata !"output_000", metadata !6, i32 50331672, metadata !10, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!40 = metadata !{i32 24, i32 59, metadata !5, null}
!41 = metadata !{i32 26, i32 1, metadata !42, null}
!42 = metadata !{i32 786443, metadata !5, i32 25, i32 1, metadata !6, i32 0} ; [ DW_TAG_lexical_block ]
!43 = metadata !{i32 26, i32 2, metadata !42, null}
!44 = metadata !{i32 27, i32 2, metadata !42, null}
