#pragma once 

// Clang
#define RunPragma(x) _Pragma(#x)
#define ClangAdd(wan) RunPragma(clang diagnostic ignored wan)
#define ClangStart RunPragma(clang diagnostic push) \
		ClangAdd("-Wgnu-binary-literal") \
		ClangAdd("-Wdeclaration-after-statement")
#define ClangStop RunPragma(clang diagnostic pop)

// Macros
#define UINT(x) ((unsigned int)x)
#define START 0UL
#define NIBLE 4UL
#define BITS (sizeof(unsigned int) * 8UL)
#define END (BITS - 1UL)
#define MASK 0x80000000UL
#define RIGHT_SHIFT mask = (mask >> 1UL)

// Functions
void printBin(unsigned int flag);
void printSigBin(signed int flag);
