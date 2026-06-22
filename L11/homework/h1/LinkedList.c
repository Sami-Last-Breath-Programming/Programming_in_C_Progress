#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

// Clang Flags
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#pragma clang diagnostic ignored "-Wswitch-default"

// Macros
#define ARRAY_START 0
#define ARRAY_END LEN(newLinkedList->len)
#define ARRAY_NULL_OR_LEN_ZERO (array == NULL || len == 0)
#define LINKED_LIST_NULL (list == NULL || list == (LinkedList *)0)
#define LINKED_LIST_EMPTY "Empty Linked List !\n"

// Function to create new Linked LIst
LinkedList *newLinkedList(int *array, size_t len)
{
    size_t index;
    IntList *temp;
    IntList *tempLast;
    LinkedList *newLinkedList;
    
    // On Start
    tempLast = NULL;
    
    // Check if the array is NULL ptr or len is zero
    if (ARRAY_NULL_OR_LEN_ZERO)
    {
        printf(ERROR_ARRAY_EMPTY_LEN_ZERO);
        exit(EXIT_FAILURE);
    }

    // Allocate Memory for the LinkedList
    newLinkedList = malloc(sizeof(LinkedList));

    // Handel Memory Error
    if (newLinkedList == NULL)
    {
        printf(ERROR_LINKED_LIST_ALLOCATION);
        exit(EXIT_FAILURE);
    }

    // Set the length of the LinkedList
    newLinkedList->len = len;

    // Allocate Interger List
    index = 0;
    while (index < newLinkedList->len)
    {
        // Allocate IntList for each value 
        temp = malloc(sizeof(IntList));

        // Handle Allocation Errors
        if (temp == NULL)
        {
            printf(ERROR_INT_LIST_ALLOCATION);
            exit(EXIT_FAILURE);
        }

        // Init temp
        temp->value = 0;
        temp->next = NULL;
        temp->last = NULL;

        // Handle Start index
        if (index == ARRAY_START)
        {
            newLinkedList->start = temp;
            temp->value = array[index];
            temp->last = tempLast;
            tempLast = temp;

            // Handle one element
            if (len == 1) newLinkedList->end = temp;
        }
        // Handle End index
        else if (index == ARRAY_END)
        {
            tempLast->next = temp;
            newLinkedList->end = temp;
            temp->value = array[index];
            temp->next = NULL;
            temp->last = tempLast;
            tempLast = temp;
        }
        // Handle Other indexs
        else
        {
            tempLast->next = temp;
            temp->value = array[index];
            temp->last = tempLast;
            tempLast = temp;
        }
        
        // Increase the index
        index++;
    }

    // Return the Pointer 
    return newLinkedList;
}

// Function to print DLinked List 
void printLinkedList(LinkedList *list)
{
    size_t count;
    IntList *index;

    // Handle zero length
    if (list->len == 0)
    {
        printf(LINKED_LIST_EMPTY);
        return;
    }

    index = list->start;
    count = 1;
    while (index != list->end->next)
    {
        printf("Value %zu: %i\n", count, index->value);
        count++;
        index = index->next;
    }
}

// Free Linked List 
void freeLinkedList(LinkedList *list)
{
    IntList *next;
    IntList *current;
    
    // On Start
    current = list->start;

    // Handle zero and one case
    switch (list->len)
    {
        case 0:
            free(list);
            return;
        case 1:
            free(list->start);
            free(list);
            return;
    }

    // Loop untill reached NULL ptr
    while (current != NULL)
    {
        // Next Element
        next = current->next;

        // Free last one 
        free(current);

        // Reassign current 
        current = next;
    }

    // Free the LinkedList
    free(list);
}

//  Add Integer in the LinkedList
void addInteger(LinkedList *list, int num)
{
    IntList *temp;
    IntList *lastEnd;
    
    // Handle Linked List NULL
    if (LINKED_LIST_NULL)
    {
        printf(ERROR_LINKED_LIST_NULL);
        exit(EXIT_FAILURE);
    }

    // Allocate Memory for intList
    temp = malloc(sizeof(IntList));

    // Handle Allocations Errors
    if (temp == NULL)
    {
        printf(ERROR_INT_LIST_ALLOCATION);
        exit(EXIT_FAILURE);
    }

    // Logic 
    switch (list->len)
    {
        case 0:
            // Handle Zero Element    
            temp->value = num;
            temp->next = NULL;
            temp->last = NULL;
            list->start = temp;
            list->end = temp;
            list->len = 1;
            break;
        
        default:
            // Assign the value
            temp->value = num;
            temp->next = NULL;
            // Update the LinkedList
            lastEnd = list->end;
            temp->last = lastEnd;
            lastEnd->next = temp;
            list->end = temp;
            list->len += 1;
            break;
    }
}

// Remove Integer from the LinkedList
void removeInteger(LinkedList *list, size_t index)
{
    size_t loopIndex;
    IntList *currrent;
    IntList *tofree;
    
    // Check if the Linked List is empty or NULL 
    if (LINKED_LIST_NULL)
    {
        printf(ERROR_LINKED_LIST_NULL);
        exit(EXIT_FAILURE);
    }
    else if (list->len == 0)
    {
        printf(LINKED_LIST_EMPTY);
        return;
    }

    // Handle one element
    if (index == 1 && list->len == 1)
    {
        free(list->start);
        
        // Set start and end
        list->end = NULL;
        list->start = NULL;

        // Set the length
        list->len = 0;

        return;
    }
    else if (index == 1 && list->len > 1)
    {
        // Logic for the start
        tofree = list->start;
        list->start = tofree->next;
        list->start->last = NULL;

        // Free the start
        free(tofree);

        // Decrease the length
        list->len -= 1;

        return;
    }
    
    // Handle last element
    if (index == list->len || index > list->len)
    {
        tofree = list->end;
        list->end = list->end->last;
        list->end->next = NULL;
        
        // Free the last element
        free(tofree);

        return;
    }

    // Set the current to start
    loopIndex = 0;
    currrent = list->start;

    // Loop on the List
    while (loopIndex < LEN(index) - 1)
    {
        currrent = currrent->next;
        loopIndex++;
    }

    // Logic for inbetween
    tofree = currrent->next;
    currrent->next = tofree->next;
    currrent->next->last = tofree->last;

    // Free the index element
    free(tofree);

    // Decrease the length
    list->len -= 1;
    
}
#pragma clang diagnostic pop
