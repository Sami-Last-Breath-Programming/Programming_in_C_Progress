// Variable length Array test

#include <stdio.h> 

#define EXIT_SUCCESS 0
#define ERROR 1

int main(void)
{
    // Variables
    int len;

    // Array length input from user
    printf("Enter The Size Of Array: ");
    scanf("%i", &len);

    if (len > 1000 || len <= 0)
    {
        printf("Invalid Array Length !\n");
        return ERROR;
    }
   
    // Defining a Variable length Array
    int array[len];

    // Counting in Array 
    for (int index = 0; index < len; index++)
    {
        array[index] = index + 1;
    }
    
    // Printing Variable length Array
    for (int index = 0; index < len; index++)
    {
        printf("%3i: %3i\n", index, array[index]);
    }

    return EXIT_SUCCESS;
}