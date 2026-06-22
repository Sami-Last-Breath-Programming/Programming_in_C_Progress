#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

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

// Function which creates a new Linked List
LinkedList *newLinkedList(int *array, size_t len)
{
    size_t index;
    intList *temp;
    intList *tempLast;
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
        temp = malloc(sizeof(intList));

        // Handle Allocation Errors
        if (temp == NULL)
        {
            printf(ERROR_INT_LIST_ALLOCATION);
            exit(EXIT_FAILURE);
        }

        // Init temp
        temp->value = 0;
        temp->next = (intList *)0;

        // Handle Start index
        if (index == ARRAY_START)
        {
            newLinkedList->start = temp;
            temp->value = array[index];
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
            temp->next = (intList *) 0;
            tempLast = temp;
        }
        // Handle Other indexs
        else
        {
            tempLast->next = temp;
            temp->value = array[index];
            tempLast = temp;
        }
        
        // Increase the index
        index++;
    }

    // Return the Pointer 
    return newLinkedList;
}

void printLinkedList(LinkedList *list)
{
    size_t count;
    intList *index;

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

void freeLinkedList(LinkedList *list)
{
    intList *next;
    intList *current;
    
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
    while (current != (intList *)0)
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

void addInteger(LinkedList *list, int num)
{
    intList *temp;
    intList *lastEnd;
    
    // Handle Linked List NULL
    if (LINKED_LIST_NULL)
    {
        printf(ERROR_LINKED_LIST_NULL);
        exit(EXIT_FAILURE);
    }

    // Allocate Memory for intList
    temp = malloc(sizeof(intList));

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
            temp->next = (intList *)0;
            list->start = temp;
            list->end = temp;
            list->len = 1;
            break;
        
        default:
            // Assign the value
            temp->value = num;
            temp->next = (intList *)0;

            // Update the LinkedList
            lastEnd = list->end;
            lastEnd->next = temp;
            list->end = temp;
            list->len += 1;
            break;
    }
}

void popInteger(LinkedList *list)
{
    size_t index;
    intList *element;

    // On Start
    index = 0;
    element = list->start;
    
    // Handle Linked List NULL
    if (LINKED_LIST_NULL)
    {
        printf(ERROR_LINKED_LIST_NULL);
        exit(EXIT_FAILURE);
    }
    
    // Handle one element 
    if (list->len <= 1)
    {
        free(list->start);
        
        // Update the list
        list->start = (intList *)0;
        list->end = (intList *)0;
        list->len = 0;
        return;
    }
    
    // Pop the last element
    free(list->end);

    // Loop till the second last
    while (index != LEN(list->len) - 1)
    {
        element = element->next;
        index++;
    }
    
    // Set second last as last 
    element->next = (intList *)0;
    list->end = element;

    // Update the lenght
    list->len -= 1;

}

void removeInteger(LinkedList *list, size_t index)
{
    size_t loopIndex;
    intList *currrent;
    intList *tofree;
    
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
        list->end = (intList *)0;
        list->start = (intList *)0;

        // Set the length
        list->len = 0;

        return;
    }
    else if (index == 1 && list->len > 1)
    {
        // Logic for the start
        tofree = list->start;
        list->start = tofree->next;

        // Free the start
        free(tofree);

        // Decrease the length
        list->len -= 1;

        return;
    }
    
    // Handle last element
    if (index == list->len || index > list->len)
    {
        popInteger(list);
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

    // Free the index element
    free(tofree);

    // Decrease the length
    list->len -= 1;
    
}

void modifyInteger(LinkedList *list, size_t index, int newValue)
{
    size_t loopIndex;
    intList *currrent;

    // Check If the Linked List is empty or NULL 
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
    if (index == 1)
    {
        // Modify the Value of first index
        list->start->value = newValue;
        return;
    }

    // Handle last element
    if (index == list->len || index > list->len)
    {
        list->end->value = newValue;
        return;
    }

    // Set the current to start
    loopIndex = 0;
    currrent = list->start;

    // Loop on the List
    while (loopIndex < LEN(index))
    {
        currrent = currrent->next;
        loopIndex++;
    }

    // Modify the new Value
    currrent->value = newValue;
}
#pragma clang diagnostic pop
