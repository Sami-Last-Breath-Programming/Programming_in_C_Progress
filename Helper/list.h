#pragma once
#include <stdio.h>
#include <stddef.h> 

// Clang Macros
#define CLANG_START _Pragma("clang diagnostic push")
#define CLANG_END  _Pragma("clang diagnostic pop")

// Clang Fix
#pragma clang diagnostic ignored "-Wdouble-promotion"
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#pragma clang diagnostic ignored "-Wcovered-switch-default"

// List type enum
typedef enum LIST_TYPE
{
    FLOAT,
    INTEGER,
    STRING,
    BOOLEAN,

}LIST_TYPE;

// Functions
void printList(void *list, size_t size, LIST_TYPE type);
