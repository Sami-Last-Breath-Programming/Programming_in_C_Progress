#include "list.h"

// Declatrations
void printList(void *list, size_t size, LIST_TYPE type)
{  
    _Bool end = 0;

    // Print Header
    printf("[");
    
    // Loop on the list
    for (size_t index = 0; index < size; index++)
    {
        // Handle last comma
        if (index == size - 1) end = 1;

        // Check the type of list
        switch (type)
        {
            case FLOAT:    
                printf("%.2f%s", ((float *)list)[index], (end)? "]" : ", ");
                break;
            case INTEGER:
                printf("%i%s", ((int *)list)[index], (end)? "]" : ", ");
                break; 
            case STRING:
                printf("%s%s", ((char **)list)[index], (end)? "]" : ", ");
                break;
            case BOOLEAN:
                printf("%s%s", (((_Bool *)list)[index])? "T": "F", (end)? "]" : ", ");
                break;
            default:
                printf("Unknown List\n");
                break;
        }
    }
    // Post Header
    printf("\n");
}
