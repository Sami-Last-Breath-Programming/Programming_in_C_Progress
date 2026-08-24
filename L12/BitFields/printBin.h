#pragma once 

// Clang
#define ClangStart _Pragma("clang diagnostic push") \
	_Pragma("clang diagnostic ignored \"-Wgnu-binary-literal\"") \
	_Pragma("clang diagnostic ignored \"-Wdeclaration-after-statement\"")
#define ClangStop _Pragma("clang diagnostic pop")

// Macros
#define START 0UL
#define NIBLE 4UL
#define BITS (sizeof(unsigned int) * 8UL)
#define END (BITS - 1UL)
#define MASK 0x80000000U
#define RIGHT_SHIFT mask = (mask >> 1U)

// Functions
void printBin(unsigned int flag);
