// Triangular Number with Formula 

#include <stdio.h>

#define EXIT_SUCCESS 0

int getTriNum(int n)
{
    return n * (n + 1) / 2;
}

void makeUI(void)
{
    printf("\n     Triangular Number     \n");
    printf("---------------------------\n");
    printf("    n            TriNum    \n");
    printf("---------------------------\n");
}

int main(void)
{
    const int start = 5;
    const int end = 50;
    const int skip = 5;

    makeUI();

    for (int count = start; count <= end; count+= skip)
    {
        printf("    %2i            %4i         \n", 
            count, getTriNum(count)
        );
    }
    
    return EXIT_SUCCESS;
}