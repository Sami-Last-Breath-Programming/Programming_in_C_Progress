#include <stdio.h>

int main(void)
{
    float num = 1112223334.44555666777888999f;
    double num_2 = 1112223334.44555666777888999;

    // Compare with integer
    int num_3 = 111222336; 

    printf("Size of Float %f is: %ld \n", 
        num, sizeof(num)
    );
    printf("Size of Double %f is: %ld \n", 
        num_2, sizeof(num_2)
    );
    printf("Size of Integer %i is: %ld \n\n", 
        num_3, sizeof(num_3)
    );
    
    // Raw comparision 
    printf("Size of  raw Float: %ld \n", sizeof(float));
    printf("Size of raw Double: %ld \n ", sizeof(double));
    printf("Size of raw Integer: %ld \n ", sizeof(int));
    
    return 0;
}