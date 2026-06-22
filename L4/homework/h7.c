#include <stdio.h>

#define EXIT_SUCCESS 0

void nextMultiple(int i, int j)
{   
    char *Title = "The Next Largest Even Multiple of values";
    printf("%s %i and %i is: %i \n",Title, i, j, (i + j) - (i % j));
}


int main(void)
{
    nextMultiple(365, 7);
    nextMultiple(12258, 23);
    nextMultiple(996, 4);

    return EXIT_SUCCESS;
}