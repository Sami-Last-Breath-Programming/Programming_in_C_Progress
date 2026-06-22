#include <stdio.h> 
#include <stdlib.h>

// To Operating System
#define EXIT_SUCCESS 0
#define ERROR 1

// Booleans
#define true 1
#define false 0

// Globals 
int BASE = 0, NUM = 0;
int *remainders;
int remElements, remMaxElements;

// Decleration Of Functions
void get_Num_And_Base();
int resize_array();
void convert_Num_to_Base();
void reverse_array();
void display_Converted_Num();

// Main Entry 
int main(void)
{
    int *temp;
    
    // Init Remainders Array, size and capacity
    temp = malloc(4 * sizeof(int));

    // Allocating Memory
    if (temp != NULL)
    {
        remainders = temp;
        remElements = 0;
        remMaxElements = 4;
    }
    else
    {
        printf("Error: Can't Get Memory From System !\n");
        exit(ERROR);
    }

    // Input of Number and Base from User
    get_Num_And_Base();

    // Convert Number to Given Base
    convert_Num_to_Base();

    // Reverse the  Remainders Array
    reverse_array();

    // Display Converted Number in Given Base
    display_Converted_Num();

    // Free Remainders Array
    free(remainders);

    return EXIT_SUCCESS;
}

void get_Num_And_Base()
{
    int flush;

    while (true)
    {
        // Header
        printf("\n-------------------\n");
        printf("Base Converter\n");
        printf("Example: 20 in 2\n");
        printf("-------------------\n");
    
        // Input Handle
        scanf("%i in %i", &NUM, &BASE);
        while ((flush = getchar() != '\n' && flush != EOF));

        // Error Handle
        if (BASE <= 1 || BASE > 16)
            printf("Error: Invalid Base !\n");
        else break;
    }
}

int resize_array()
{   
    int *temp;
    // Request more space from OS
    temp = realloc(
        remainders,
        (remMaxElements * 2) * sizeof(int)
    );

    // If got more space from OS
    if (temp != NULL)
    {
        remainders = temp;
        remMaxElements *= 2;
    }
    else
    {
        // Handel Error
        printf("Error: Can't Get More Memory From System !\n");
        return ERROR;
    }

    return EXIT_SUCCESS;
}

void convert_Num_to_Base()
{   
    int quotient = NUM;
    int remainder = 0;

    // Divide, Modulos and store Remainders untill Zero
    while ((quotient / BASE) != 0)
    {
        remainder = quotient % BASE;

        // Check For Limit Cross
        if (remElements > remMaxElements - 1)
            if(resize_array()) exit(ERROR);

        // Store Remainder in Array
        remainders[remElements]= remainder;
        remElements++;

        // Storing the new quotient 
        quotient = quotient / BASE;
    }

    // Run for last Remainder
    remainder = quotient % BASE;

    // Check For Limit Cross
    if (remElements > remMaxElements - 1)
        if(resize_array()) exit(ERROR);

    // Store Last Remainder in Array
    remainders[remElements] = remainder;
    remElements++;

}

void reverse_array()
{
    int temp[remElements];

    // Swapping Back And forth Elements
    for (
            int lastIndex = remElements - 1;
            lastIndex >= 0;
            lastIndex--
        )
    {
        temp[remElements - 1 - lastIndex] = remainders[lastIndex];
    }
    for (int index = 0; index < remElements; index++)
    {
        remainders[index] = temp[index];
    }
}

void display_Converted_Num()
{
    // Loop table for Numbers
    int lookup_digit[] = {
        '0', '1', '2', '3', '4', '5', 
        '6', '7', '8', '9', 'A', 'B',
        'C', 'D', 'E', 'F'
    };
    
    // Header
    printf("The %i in Base %i: ", NUM, BASE);
    

    // Print Each Remainder in Array With LookUp Table form
    for (int index = 0;  index < remElements; index++)
    {
        printf("%c", lookup_digit[remainders[index]]);
    }
    printf("\n");
}