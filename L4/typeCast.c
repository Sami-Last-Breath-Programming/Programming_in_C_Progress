#include <stdio.h>

#define EXIT_SUCCESS 0

int main(void)
{
    float f1 = 123.125f, f2;
    signed int i1, i2 = -150;
    // char c = 'a';

    // Float to Integer
    i1 = (int)f1;
    printf("%f in Integer is: %i \n",f1, i1);

    // Integer to float
    f1 = (float)i2;
    printf("%i in Float is: %f \n",i2, f1);

    // Integer / Integer assign to Float
    f1 = i2 / 100;
    printf("The Value of %i / 100 is: %f \n",i2, f1);

    // Integer / Integer assign to Float with TypeCast
    f1 = (float)i2 / 100;
    printf("The Value of %i / 100 is: %f \n",i2, f1);

    // Integer / Float 
    f2 = i2 / 100.0f;
    printf("%i / 100.0f = %f \n",i2, f2);


    return EXIT_SUCCESS;
}