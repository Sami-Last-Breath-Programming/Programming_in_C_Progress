#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int main(void)
{
    int iVar = 200;
    float fVar = 224.19;
    double dVar = 3.0e+8;
    char cvar = 'A';
    _Bool bVar = true;
    
    printf("Integer Value: %i \n",iVar);
    printf("Float Value: %f \n", fVar);
    printf("Double Value: %e \n", dVar);
    printf("Double Value Choice: %g \n", dVar);
    printf("Character Value: %i:%c \n", cvar, cvar);
    printf("Boolean Vaalue: %i \n", bVar);
    
    return EXIT_SUCCESS;
}