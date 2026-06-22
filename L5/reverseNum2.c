/*  Added support for Handling 
    0 and single digits 
*/

#include <stdio.h>

#define EXIT_SUCCESS 0
#define true 1
#define false 0

typedef _Bool bool;

int popLast(int num)
{
    return num / 10;
}

int getLast(int num)
{
    return num % 10;
}


int main(void)
{
    int num; 
    bool isNeg = false;

    printf("Enter A Number To Be Reversed: ");
    scanf("%i", &num);

    if (num < 0)
    {
        num = -num;
        isNeg = true;
    }
    
    do
    {   
        printf("%i", getLast(num));
        num = popLast(num);
    }
    while (num != 0);

    if(isNeg) printf("-");
    
    printf("\n");
    
    return EXIT_SUCCESS;
}