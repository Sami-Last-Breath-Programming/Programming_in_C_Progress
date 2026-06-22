// Double Linked Listed

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

// Main Entry
int main(void)
{
    LinkedList *num; 

    // Create A new Linked List
    num = newLinkedList(INTERGER_LIST{10, 20, 30, 40, 50}, 5);

    // Print Linked List 
    printLinkedList(num);

    // Get Elements
    printf("The Element Before %i is %i\n", 
        num->start->next->value, 
        num->start->next->last->value
    );

    // Add Integer
    addInteger(num, 60);

    // Get Elements
    printf("The Element Before %i is %i\n", 
        num->end->value, 
        num->end->last->value
    );

    // Remove Integer
    removeInteger(num, 2);
    
    // Get Elements
    printf("The Element Before %i is %i\n", 
        num->start->next->value, 
        num->start->next->last->value
    );

    // Free the LinkedList
    freeLinkedList(num);

    return EXIT_SUCCESS;
}
