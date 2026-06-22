// Avg of an float array 

#include <stdio.h>

#define EXIT_SUCCESS 0

float getAvg(float *array)
{
    float sum = 0.00f;

    for (int index = 0; index < 10; index++)
    {
        sum += array[index];
    }
    return sum / (float)10;
}


int main(void)
{
    // Define and inti array to 0.00
    float array[10] = {0.00f};

    // Styling of output 
    printf("[(");

    // Storing numbers in array and printing
    for (int index = 0; index < 10; index++)
    {
        array[index] = (float)index * 2.12f;
        if (index < 9)
            printf("%.2f + ", array[index]);
        else
            printf("%.2f) ÷ 10] = ", array[index]);
    }

    // Calculating Avg 
    float avg = getAvg(array);

    // Printing result
    printf("%.2f\n",avg);
    
    return EXIT_SUCCESS;
}