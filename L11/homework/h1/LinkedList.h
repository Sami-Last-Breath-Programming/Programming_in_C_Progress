#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <stddef.h>

// Clang Flags
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"

// Interger List
typedef struct IntList
{
    int value;
    struct IntList *last;
    struct IntList *next;

}IntList;

// LinkedList 
typedef struct LinkedList
{   
    size_t len;
    IntList *start;
    IntList *end;

}LinkedList;

// Macros
#define INTERGER_LIST (int[])
#define LEN(x) (x - 1)

// Declarations
LinkedList *newLinkedList(int *, size_t);
void addInteger(LinkedList *, int);
void removeInteger(LinkedList *, size_t);
void freeLinkedList(LinkedList *);
void printLinkedList(LinkedList *);

// Errors
#define ERROR_LINKED_LIST_NULL "Error: Linked List pointer is NULL !\n"
#define ERROR_ARRAY_EMPTY_LEN_ZERO "Error: Array is NULL or Len is Zero !\n"
#define ERROR_LINKED_LIST_ALLOCATION "Error: Can't Allocate Memory For LinkedList !\n"
#define ERROR_INT_LIST_ALLOCATION "Error: Can't Allocate Memory For IntList !\n"

#pragma clang diagnostic pop
#endif
