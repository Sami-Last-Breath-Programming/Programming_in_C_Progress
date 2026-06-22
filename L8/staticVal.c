// Static vs Automatic variables

#include <stdio.h>

// To System
#define EXIT_SUCCESS 0

void count_num();

// Main Entry
int main(void)
{
    // Counting Till Ten
    for (int count = 0; count < 10; count++)
        count_num();
    return EXIT_SUCCESS;
}

void count_num()
{
    static int num_static; // By Default 0
    auto int num_auto = 0;

    // Increasing By one one each call
    num_static++;
    num_auto++;

    // Printing the count 
    printf("Auto: %i, Static %i\n", num_auto, num_static);
}