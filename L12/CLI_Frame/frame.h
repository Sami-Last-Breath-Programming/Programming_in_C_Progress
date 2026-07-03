#ifndef UI_FRAME_H
#define UI_FRAME_H

// Include
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
void Render(Frame);
void Wait(Second);
void Clear(void);
void CHECK_FLAGS(void);


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
void Render(Frame f) { printf("%s", f); }
void Wait(Second s) { sleep(s); }
void Clear(void) { system("clear"); }
void CHECK_FLAGS(void)
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
#endif
