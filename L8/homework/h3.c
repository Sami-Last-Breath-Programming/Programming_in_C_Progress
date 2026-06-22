// Quadratic Equation Roots Finder

#include <stdio.h>
#include <stdlib.h>

double absFloat(double);
double sqroot(int);
int findDisc(int [3]);
void findRoots(int disc, double roots[2], int cof[3]);

int main(void)
{
    // Init cofficients and roots
    int cof[3] = {0, 0, 0};
    double roots[2] = {0, 0};

    // Header
    printf("\n------------------------------------\n");
    printf("Welcome to Quadratic Roots Finder\n");
    printf("Example: a, b, c \n");
    printf("------------------------------------\n");
    
    // Input of cofficients
    scanf("%i, %i, %i", &cof[0], &cof[1], &cof[2]);

    // Find the Discriminamt
    int disc = findDisc(cof);

    // Check if Roots Real or Not
    if (disc >= 0)
    {
        printf("\nThe Roots are Real !\n");
        findRoots(disc, roots, cof);
    }
    else
    {
        printf("\nThe Roots are not Real\n");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}

double absFloat(double num)
{
    if (num < 0)
        num = -num;
    
    // If positive return 
    return num;
}

double sqroot(int num)
{
    double guess =  1.0;
    const double diff = 0.00001;

    // if num is zero
    if (num < 0) exit(EXIT_FAILURE);

    // If guess minus num different is more than diff loop
    while (absFloat((guess * guess) - num) > diff)
        guess = ((num / guess) + guess) / 2.0;

    return guess;
}

int findDisc(int cof[3])
{
    return (cof[1] * cof[1]) - (4 * cof[0] * cof[2]);
}

void findRoots(int disc, double roots[2], int cof[3])
{
    double sqtDisc = sqroot(disc);

    // Calculation of Both Roots
    roots[0] = ((-cof[1] + sqtDisc) / (2.0 * cof[0]));
    roots[1] = ((-cof[1] - sqtDisc) / (2.0 * cof[0]));

    // Header
    printf("\n------------------------------------\n");

    // Printing roots
    for (int index = 0; index <= 1; index++)
        printf("The root %i = %.2lf\n", index + 1, roots[index]);
   
    // Header Close
    printf("------------------------------------\n");
}