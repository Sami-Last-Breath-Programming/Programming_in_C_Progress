#include <stdio.h>

#define EXIT_SUCCESS 0

int main(void)
{
    
    int numArray[10]; 
    size_t size = sizeof(numArray) / sizeof(numArray[0]);

    numArray[0] = 197;
    numArray[2] = -100;
    numArray[5] = 350;
    numArray[3] = numArray[0] + numArray[5];
    numArray[9] = numArray[5] / 10;
    numArray[2]--;
    
    for(int index = 0; index < size; index++)
    {
        printf("numArray[%i] = %3i\n", 
            index, 
            numArray[index]
        );
    }

    return EXIT_SUCCESS; 
}