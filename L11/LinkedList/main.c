#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

// Main Entry
int main(void)
{
    LinkedList *numbers;
    
    // Make the new list
    numbers = newLinkedList(INTEGER_LIST{10}, 1);

    // Add Integer
    addInteger(numbers, 50);
    addInteger(numbers, 60);
    addInteger(numbers, 70);
    addInteger(numbers, 100);
    addInteger(numbers, 200);
    addInteger(numbers, 300);

    // Pop Integer 
    popInteger(numbers);

    // Remove Integer
    removeInteger(numbers, 1);
    removeInteger(numbers, 2);

    // Modify Integer
    modifyInteger(numbers, 1, 2000);
    modifyInteger(numbers, 2, 5000);

    // Extra Test
    removeInteger(numbers, 99);
    modifyInteger(numbers, numbers->len, 0);

    // Print the LinkedList
    printLinkedList(numbers);

    // Print the LinkedList Length
    printf("Length: %zu\n", numbers->len);

    // Free the LinkedList
    freeLinkedList(numbers);

    return EXIT_SUCCESS;
}
