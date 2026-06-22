#include <stdio.h> 

#define EXIT_SUCCESS 0

float absFloat(float num)
{
    if (num < 0)
        num = -num;
    
    return num;
}

int main(void)
{
    float num1 = -15.5f, num2 = 20.0f, num3 = -5.0f;
    int num4 = -716;

    float result;

    result = absFloat(num1);
    printf("Absoulte is |%06.2f|\n", result);

    result = absFloat(num2);
    printf("Absoulte is |%06.2f|\n", result);

    result = absFloat(num3);
    printf("Absoulte is |%06.2f|\n", result);

    result = absFloat((float)num4);
    printf("Absoulte is |%06.2f|\n", result);

    result = absFloat(num4);
    printf("Absoulte is |%06.2f|\n", result);

    result = absFloat( (-6.0) / 4);
    printf("Absoulte is |%06.2f|\n", result);
    
    return EXIT_SUCCESS;
}
