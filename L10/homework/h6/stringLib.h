#ifndef STRING_LIB_H
#define STRING_LIB_H

#include <stddef.h>

// Macros
#define STRING_EMPTY_NULL(str) (str == NULL || str[0] == '\0' || str[0] == '\n')

// Declarations
int findString(const char *, const char *);
char *removeString(char *, size_t, size_t);
void insertString(char *, const char *, size_t, size_t);

// Errors
#define ERROR_STRING_EMPTY_NULL "Error: Given Strings Arguments are Empty or NULL pointer !\n"
#define ERROR_STRING_MEMORY_ALLOCATE "Error: Can't Allocate Memory for tempString !\n"
#define ERROR_NO_EMPTY_SPACE "Error: Source String has no empty space or garbage !\n"

#endif
