#include <stdio.h>
#include <complex.h>

#define EXIT_SUCCESS 0

int main(void)
{
    double complex cnum1 = 2.0 + 4.0 * I;

    // Printing Real And Imaginary Parts
    printf("The Real Part of Complex number is: %lf \n",
        creal(cnum1)
    );
    printf("The Imaginary Part of Complex number is: %lf \n",
        cimag(cnum1)
    );

    double complex result = cnum1 * cnum1;

    // Calculations on Complex Number
    printf("The Square is: %lf + %lfi \n",
        creal(result),
        cimag(result));
    
    return EXIT_SUCCESS;
}
