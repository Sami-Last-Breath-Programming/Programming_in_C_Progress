#ifndef Linked_List_H
#define Linked_List_H

#include <stddef.h>

// Clang Flags
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"

// Macros
#define LEN(x) (x - 1)
#define INTEGER_LIST (int [])

// Int List 
typedef struct intList
{   
    int value;
    struct intList *next;

}intList;

// Linked List
typedef struct LinkedList
{
    intList *start;
    intList *end;
    size_t len;

}LinkedList;

// Functions
LinkedList *newLinkedList(int *, size_t);
void addInteger(LinkedList *, int);
void popInteger(LinkedList *);
void removeInteger(LinkedList *, size_t);
void modifyInteger(LinkedList *, size_t, int);
void freeLinkedList(LinkedList *);
void printLinkedList(LinkedList *);

// Errors
#define ERROR_LINKED_LIST_NULL "Error: Linked List pointer is NULL !\n"
#define ERROR_ARRAY_EMPTY_LEN_ZERO "Error: Array is NULL or Len is Zero !\n"
#define ERROR_LINKED_LIST_ALLOCATION "Error: Can't Allocate Memory For LinkedList !\n"
#define ERROR_INT_LIST_ALLOCATION "Error: Can't Allocate Memory For IntList !\n"

#pragma clang diagnostic pop
#endif
