#pragma once

// Clang Macros
#define RunPragma(x) _Pragma(#x)
#define ClangAdd(wan) RunPragma(clang diagnostic ignored wan)
#define ClangStart RunPragma(clang diagnostic push) \
		ClangAdd("-Wgnu-binary-literal") \
		ClangAdd("-Wdeclaration-after-statement")
#define ClangStop RunPragma(clang diagnostic pop)