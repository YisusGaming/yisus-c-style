/*
 * Copyright (C) 2025 Jesús "Mika" Blanco
 * Released under the MIT License.
 *
 * See LICENSE for details.
 *
 * cproj.c : CLI util that generates C projects.
 */

#include "dynstr.h"
#include "types.h"
#include "util.h"
#if defined(_WIN32) || defined(_WIN64)

#include <direct.h>
#define getcwd(a, b) _getcwd(a, b)
#define mkdir(a, b) _mkdir(a)
#define chdir(a) _chdir(a)
#define fopen fopen_s

#else

#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define fopen(a, b, c) (*(a)) = fopen(b, c)

#endif
#include <stdio.h>

const char clang_format_source[] =
    "---\nLanguage:        Cpp\n# Yisus Style\n# BasedOnStyle:  "
    "Mozilla\nAccessModifierOffset: -2\nAlignAfterOpenBracket: "
    "Align\nAlignArrayOfStructures: None\nAlignConsecutiveAssignments:\n  "
    "Enabled:         false\n  AcrossEmptyLines: false\n  AcrossComments:  "
    "false\n  AlignCompound:   false\n  PadOperators:    "
    "true\nAlignConsecutiveBitFields:\n  Enabled:         false\n  "
    "AcrossEmptyLines: false\n  AcrossComments:  false\n  AlignCompound:   "
    "false\n  PadOperators:    false\nAlignConsecutiveDeclarations:\n  "
    "Enabled:         false\n  AcrossEmptyLines: false\n  AcrossComments:  "
    "false\n  AlignCompound:   false\n  PadOperators:    "
    "false\nAlignConsecutiveMacros:\n  Enabled:         false\n  "
    "AcrossEmptyLines: false\n  AcrossComments:  false\n  AlignCompound:   "
    "false\n  PadOperators:    false\nAlignConsecutiveShortCaseStatements:\n  "
    "Enabled:         false\n  AcrossEmptyLines: false\n  AcrossComments:  "
    "false\n  AlignCaseColons: false\nAlignEscapedNewlines: "
    "Right\nAlignOperands:   Align\nAlignTrailingComments:\n  Kind:            "
    "Always\n  OverEmptyLines:  0\nAllowAllArgumentsOnNextLine: "
    "true\nAllowAllParametersOfDeclarationOnNextLine: "
    "false\nAllowShortBlocksOnASingleLine: "
    "Never\nAllowShortCaseLabelsOnASingleLine: "
    "false\nAllowShortEnumsOnASingleLine: "
    "true\nAllowShortFunctionsOnASingleLine: "
    "Inline\nAllowShortIfStatementsOnASingleLine: "
    "Never\nAllowShortLambdasOnASingleLine: All\nAllowShortLoopsOnASingleLine: "
    "false\nAlwaysBreakAfterDefinitionReturnType: "
    "None\nAlwaysBreakAfterReturnType: "
    "None\nAlwaysBreakBeforeMultilineStrings: "
    "false\nAlwaysBreakTemplateDeclarations: Yes\nAttributeMacros:\n  - "
    "__capability\nBinPackArguments: false\nBinPackParameters: "
    "false\nBitFieldColonSpacing: Both\nBraceWrapping:\n  AfterCaseLabel:  "
    "false\n  AfterClass:      true\n  AfterControlStatement: Never\n  "
    "AfterEnum:       true\n  AfterExternBlock: true\n  AfterFunction:   "
    "true\n  AfterNamespace:  false\n  AfterObjCDeclaration: false\n  "
    "AfterStruct:     true\n  AfterUnion:      true\n  BeforeCatch:     "
    "false\n  BeforeElse:      false\n  BeforeLambdaBody: false\n  "
    "BeforeWhile:     false\n  IndentBraces:    false\n  SplitEmptyFunction: "
    "true\n  SplitEmptyRecord: false\n  SplitEmptyNamespace: "
    "true\nBreakAfterAttributes: Never\nBreakAfterJavaFieldAnnotations: "
    "false\nBreakArrays:     true\nBreakBeforeBinaryOperators: "
    "None\nBreakBeforeConceptDeclarations: Always\nBreakBeforeBraces: "
    "Mozilla\nBreakBeforeInlineASMColon: "
    "OnlyMultiline\nBreakBeforeTernaryOperators: "
    "true\nBreakConstructorInitializers: BeforeComma\nBreakInheritanceList: "
    "BeforeComma\nBreakStringLiterals: true\nColumnLimit:     "
    "80\nCommentPragmas:  '^ IWYU pragma:'\nCompactNamespaces: "
    "false\nConstructorInitializerIndentWidth: 4\nContinuationIndentWidth: "
    "4\nCpp11BracedListStyle: false\nDerivePointerAlignment: "
    "false\nDisableFormat:   false\nEmptyLineAfterAccessModifier: "
    "Never\nEmptyLineBeforeAccessModifier: "
    "LogicalBlock\nExperimentalAutoDetectBinPacking: "
    "false\nFixNamespaceComments: false\nForEachMacros:\n  - foreach\n  - "
    "Q_FOREACH\n  - BOOST_FOREACH\nIfMacros:\n  - KJ_IF_MAYBE\nIncludeBlocks:  "
    " Preserve\nIncludeCategories:\n  - Regex:           "
    "'^\"(llvm|llvm-c|clang|clang-c)/'\n    Priority:        2\n    "
    "SortPriority:    0\n    CaseSensitive:   false\n  - Regex:           "
    "'^(<|\"(gtest|gmock|isl|json)/)'\n    Priority:        3\n    "
    "SortPriority:    0\n    CaseSensitive:   false\n  - Regex:           "
    "'.*'\n    Priority:        1\n    SortPriority:    0\n    CaseSensitive:  "
    " false\nIncludeIsMainRegex: '(Test)?$'\nIncludeIsMainSourceRegex: "
    "''\nIndentAccessModifiers: false\nIndentCaseBlocks: "
    "false\nIndentCaseLabels: true\nIndentExternBlock: "
    "AfterExternBlock\nIndentGotoLabels: true\nIndentPPDirectives: "
    "None\nIndentRequiresClause: true\nIndentWidth:     "
    "4\nIndentWrappedFunctionNames: false\nInsertBraces:    "
    "false\nInsertNewlineAtEOF: false\nInsertTrailingCommas: "
    "None\nIntegerLiteralSeparator:\n  Binary:          0\n  BinaryMinDigits: "
    "0\n  Decimal:         0\n  DecimalMinDigits: 0\n  Hex:             0\n  "
    "HexMinDigits:    0\nJavaScriptQuotes: Leave\nJavaScriptWrapImports: "
    "true\nKeepEmptyLinesAtTheStartOfBlocks: true\nKeepEmptyLinesAtEOF: "
    "false\nLambdaBodyIndentation: Signature\nLineEnding:      "
    "DeriveLF\nMacroBlockBegin: ''\nMacroBlockEnd:   ''\nMaxEmptyLinesToKeep: "
    "1\nNamespaceIndentation: None\nObjCBinPackProtocolList: "
    "Auto\nObjCBlockIndentWidth: 4\nObjCBreakBeforeNestedBlockParam: "
    "true\nObjCSpaceAfterProperty: true\nObjCSpaceBeforeProtocolList: "
    "false\nPackConstructorInitializers: BinPack\nPenaltyBreakAssignment: "
    "2\nPenaltyBreakBeforeFirstCallParameter: 19\nPenaltyBreakComment: "
    "300\nPenaltyBreakFirstLessLess: 120\nPenaltyBreakOpenParenthesis: "
    "0\nPenaltyBreakString: 1000\nPenaltyBreakTemplateDeclaration: "
    "10\nPenaltyExcessCharacter: 1000000\nPenaltyIndentedWhitespace: "
    "0\nPenaltyReturnTypeOnItsOwnLine: 200\nPointerAlignment: "
    "Right\nPPIndentWidth:   -1\nQualifierAlignment: "
    "Leave\nReferenceAlignment: Left\nReflowComments:  "
    "true\nRemoveBracesLLVM: false\nRemoveParentheses: Leave\nRemoveSemicolon: "
    "false\nRequiresClausePosition: OwnLine\nRequiresExpressionIndentation: "
    "OuterScope\nSeparateDefinitionBlocks: Leave\nShortNamespaceLines: "
    "1\nSortIncludes:    CaseSensitive\nSortJavaStaticImport: "
    "Before\nSortUsingDeclarations: "
    "LexicographicNumeric\nSpaceAfterCStyleCast: false\nSpaceAfterLogicalNot: "
    "false\nSpaceAfterTemplateKeyword: false\nSpaceAroundPointerQualifiers: "
    "Default\nSpaceBeforeAssignmentOperators: true\nSpaceBeforeCaseColon: "
    "false\nSpaceBeforeCpp11BracedList: "
    "false\nSpaceBeforeCtorInitializerColon: "
    "true\nSpaceBeforeInheritanceColon: true\nSpaceBeforeJsonColon: "
    "false\nSpaceBeforeParens: ControlStatements\nSpaceBeforeParensOptions:\n  "
    "AfterControlStatements: true\n  AfterForeachMacros: true\n  "
    "AfterFunctionDefinitionName: false\n  AfterFunctionDeclarationName: "
    "false\n  AfterIfMacros:   true\n  AfterOverloadedOperator: false\n  "
    "AfterRequiresInClause: false\n  AfterRequiresInExpression: false\n  "
    "BeforeNonEmptyParentheses: false\nSpaceBeforeRangeBasedForLoopColon: "
    "true\nSpaceBeforeSquareBrackets: false\nSpaceInEmptyBlock: "
    "false\nSpacesBeforeTrailingComments: 1\nSpacesInAngles:  "
    "Never\nSpacesInContainerLiterals: true\nSpacesInLineCommentPrefix:\n  "
    "Minimum:         1\n  Maximum:         -1\nSpacesInParens:  "
    "Never\nSpacesInParensOptions:\n  InCStyleCasts:   false\n  "
    "InConditionalStatements: false\n  InEmptyParentheses: false\n  Other:     "
    "      false\nSpacesInSquareBrackets: false\nStandard:        "
    "Latest\nStatementAttributeLikeMacros:\n  - Q_EMIT\nStatementMacros:\n  - "
    "Q_UNUSED\n  - QT_REQUIRE_VERSION\nTabWidth:        8\nUseTab:          "
    "Never\nVerilogBreakBetweenInstancePorts: "
    "true\nWhitespaceSensitiveMacros:\n  - BOOST_PP_STRINGIZE\n  - "
    "CF_SWIFT_NAME\n  - NS_SWIFT_NAME\n  - PP_STRINGIZE\n  - STRINGIZE\n...";

const char cmakelists_source[] =
    "cmake_minimum_required(VERSION 3.10)\n\n# ...";

const char gitignore_source[] = "# folders\nbuild/\n.cache/\n";

i32 main(i32 argc, str *argv)
{
    if (argc < 2) {
        eprintf("cproj error: no metadata provided.\n");
        eprintf("\nusage is: cproj.exe <project name>\n");
        return -1;
    }

    str proj_name = argv[1];

    char cwd[1024];
    getcwd(cwd, 1024);

#if defined(_WIN32) || defined(_WIN64)
#define PATH_SEPARATOR '\\'
#else
#define PATH_SEPARATOR '/'
#endif

    String path = string_new(cwd);
    string_pushc(&path, PATH_SEPARATOR);
    string_pushstr(&path, proj_name);
    string_pushc(&path, PATH_SEPARATOR);

    printf("Creating '%s' at '%s'... ", proj_name, cstr(path));
    mode_t const f_Permissions = 0755;

    mkdir(cstr(path), f_Permissions);
    chdir(cstr(path));

    FILE *clangformat;
    fopen(&clangformat, "./.clang-format", "w");
    fprintf(clangformat, "%s\n\n", clang_format_source);
    fclose(clangformat);

    FILE *cmakelists;

    fopen(&cmakelists, "./CMakeLists.txt", "w");
    fprintf(cmakelists, "%s", cmakelists_source);
    fclose(cmakelists);

    FILE *gitignore;

    fopen(&gitignore, "./.gitignore", "w");
    fprintf(gitignore, "%s", gitignore_source);
    fclose(gitignore);

    mkdir("./src", f_Permissions);

    printf("Done.\n");

    string_drop(&path);
    return 0;
}
