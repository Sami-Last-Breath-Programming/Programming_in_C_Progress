#pragma once

// Include
#include <stdio.h>
#include <stdlib.h>

// Platfrom 
#ifdef _WIN32
	#include <windows.h>	
	#define SLEEP(x) Sleep(1000 * (x))
	#define CLEAR "cls"
#else
	#include <unistd.h>
	#define SLEEP(x) sleep((x))
	#define CLEAR "clear"
#endif


// Clang Fix
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgnu-binary-literal"
#pragma clang diagnostic ignored "-Wmissing-variable-declarations"

// Macros
#define ENGINE int main(void)
#define START {
#define END }
#define UI_THREAD while (1)
#define IS_RED 0b10000000
#define IS_GREEN 0b01000000
#define IS_BLUE 0b00100000

// Types
typedef char * Frame;
typedef unsigned int Second;

// Declarations
int flag = 0b10000000;
static inline void Render(Frame);
static inline void Wait(Second);
static inline void Clear(void);
static inline void CHECK_FLAGS(void);


// All Frames of the UI=
Frame frame_0 =
    " ___________________________\n"
    "|                           |\n"
    "|                           |\n"
    "|          _______          |\n"
    "|         |_ERROR_|         |\n"
    "|                           |\n"
    "|                           |\n"
    "|___________________________|\n";

Frame frame_1 =
    " ___________________________\n"
    "|                           |\n"
    "|                           |\n"
    "|                           |\n"
    "|       [R]  [ ]  [ ]       |\n"
    "|                           |\n"
    "|                           |\n"
    "|___________________________|\n";

Frame frame_2 =
    " ___________________________\n"
    "|                           |\n"
    "|                           |\n"
    "|                           |\n"
    "|       [ ]  [G]  [ ]       |\n"
    "|                           |\n"
    "|                           |\n"
    "|___________________________|\n";

Frame frame_3 =
    " ___________________________\n"
    "|                           |\n"
    "|                           |\n"
    "|                           |\n"
    "|       [ ]  [ ]  [B]       |\n"
    "|                           |\n"
    "|                           |\n"
    "|___________________________|\n";

// Functions
static inline void Render(Frame f) { printf("%s", f); }
static inline void Wait(Second s) { SLEEP(s); }
static inline void Clear(void) { system(CLEAR); }
static inline void CHECK_FLAGS(void)
{
    if (flag & IS_RED)
    {
        Render(frame_1);
        flag = (~flag) & IS_GREEN;
    }
    else if (flag & IS_GREEN)
    {
        Render(frame_2);
        flag = (~flag) & IS_BLUE;
    }
    else if ( flag & IS_BLUE)
    {
        Render(frame_3);
        flag = (~flag) & IS_RED;
    }
    else
    {
        Render(frame_0);
        exit(EXIT_FAILURE);
    }
}
#pragma clang diagnostic pop
