/*  Floating point Numbers (with decimal places)
    Ex: 187.6, 0.9, 1.7x10^-2, 0.4x10^8
*/

#include <stdio.h>

int main(void)
{
    // Floating Point Numbers
    float decimalNum= 78.6f;
    float scientificNum = 2.0e3f;  // Smaller then e5
    float scientificNum2 = 0.4E-6f; // Greater than e-4

    printf("Size of Float is: %zu \n", sizeof(float)); // for sizeof use %zu
    printf("%f \n", decimalNum);
    printf("%e \n", scientificNum);
    printf("%E \n", scientificNum2);

    // Float to Float Hex 
    printf("%f in Hex: %#a \n",decimalNum, decimalNum);
    printf("%e in Hex: %#a \n", scientificNum,scientificNum);  // use '%a' or '%A' for Float Hex
    printf("%e in Hex: %#a \n", scientificNum2, scientificNum2);

    // Using '%E instead of '%e'
    printf("%E, in Hex: %#A \n", scientificNum2, scientificNum2);

    // Using '%g'instead of '%e' (Choice)
    printf("%e is Smaller than e5, \t%g \n",
        scientificNum, scientificNum
    );
    printf("%e is Greater than e-4, \t%g \n",
        scientificNum2,scientificNum2
    );

    // Using '%G instead of '%d'
    printf("%e is Greater than e-4, \t%G \n",
        scientificNum2,scientificNum2
    );
   
    return 0;
}