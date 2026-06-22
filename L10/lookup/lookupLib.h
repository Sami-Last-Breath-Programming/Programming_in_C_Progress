#ifndef LOOKUP_LIB_H
#define LOOKUP_LIB_H

#include <stddef.h>
#include <stdbool.h>

// Externals
extern const size_t MAX_ENTRY_WORD_LEN;
extern const size_t MAX_ENTRY_MEANING_LEN;

// Entry Struct 
typedef struct Entry
{
    char word[16];
    char meaning[81];

} Entry;

// Macros for String
#define SMALL -1
#define GREATER 1
#define EQUAL 0

// Declarations
Entry *newEntry(const char *, const char *);
size_t lookup(const char *,  Entry **, size_t);
size_t lookupBinarySearch(const char *, Entry **, size_t);
int compareString(const char *, char *);
bool isStringEqual(const char *, char *);


// Errors
#define ENTRY_EMPTY "Error! Entry Word or Meaning cannot be Empty !\n"
#define ENTRY_ALLOCATION "Error! Can't Allocate the Memory For Entry !\n"
#define ENTRY_WORD_OVERFLOW "Error! Buffer OverFlow Word is more then %zu Char\n"
#define ENTRY_MEANING_OVERFLOW "Error! Buffer OverFlow Meaning is more then %zu Char\n"

#endif
