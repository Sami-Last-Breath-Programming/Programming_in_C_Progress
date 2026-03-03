#include <stdio.h>

#define SUCCESS_STATUS 0


int main(void)
{
    short int num = 5;
    short int *addrNum = &num;

    printf("The value of num is: %hi \n", num);
    printf("The Address of num is: %p \n", addrNum);
    printf("The Address of num in Integer is: %li \n",
        (long int)addrNum
    );
    printf("The Address of num in Binar is: %lb \n",
            (long int)addrNum
    );
    printf("The Size of Num is: %zu \n", sizeof(*addrNum));
    

    
    return SUCCESS_STATUS;
}