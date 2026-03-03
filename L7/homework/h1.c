#include <stdio.h>

#define EXIT_SUCCESS 0

int main(void)
{
    int array[10];

    // Loop to all elements and init them to zero
    for (int index = 0; index < 10; index++)
    {
        array[index] = 0;
    }

    // Assigning the Array elements custom value
    array[0] = 197;
    array[2] = -100;
    array[5] = 350;
    array[3] = array[0] + array[5];
    array[9] = 
    array[5] / 10;
    array[2]--;
    
    // Printing All Values of Array
    for(int index = 0; index < 10; index++)
    {
        printf("array[%i] = %i\n", index, array[index]);
    }

    return EXIT_SUCCESS;
}