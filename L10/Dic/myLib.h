#ifndef MYLIB__H
#define MYLIB__H

#include <stddef.h>

typedef struct String
{
    size_t len;
    char str[];
    
} String;

typedef struct List
{
    size_t len;
    size_t cap;
    String **elements;

} List;

typedef struct Pair
{
    String *key;
    List *values;

}Pair;

typedef struct Dictionary
{
    size_t size;
    Pair **pairs;

} Dictionary ;

// Macros
#define dicStr(index) dic->pairs[index]->key->str 

// Declerations
String *newString(char *);
List *newList(String **, size_t);
Dictionary *newDictionary(void);

void addEntry(Dictionary *, String *, List *);
void sortDictionary(Dictionary *);
void printDictionary(Dictionary *);
void freeDictionary(Dictionary *);
void freeList(List *);

#endif
