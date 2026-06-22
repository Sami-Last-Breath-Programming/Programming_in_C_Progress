// Newton-Raphson Method to Compute the Square Root of x

#include <stdio.h>

#define EXIT_SUCCESS 0
#define Error 1

double absFloat(double);
double calSqRoot(double);

int main(void)
{
    double sqrootNum; 

    // Input from user for sqroot number
    printf("\nEnter the Number: ");
    scanf("%lf", &sqrootNum);

    // Check if it's invalid or not 
    if (sqrootNum >= 0)
    {
        // Calling function to calculate sqroot
        double result = calSqRoot(sqrootNum);
        printf("The Square Root of |%.2lf| = |%.6lf|\n", 
            sqrootNum, result
        );
    }
    else
    {
        // Error Handling 
        printf("Error: Invalid Number !\n");
        return Error;
    } 
    
    return EXIT_SUCCESS;
}

double absFloat(double num)
{
    if (num < 0)
        num = -num;
    return num;
}

double calSqRoot(double num)
{
    const double diff =  0.00001;
    double guess = 1.0;

    // Unitll guess is larger than num loop runs 
    while (absFloat((guess * guess) - num) > diff)
        guess = ((num / guess) + guess) / 2.0;

    return guess;
}