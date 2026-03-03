#include <stdio.h>

#define EXIT_SUCCESS 0
#define CHECK_a_TO_z(symbol) (symbol >= 'a' && symbol <='z')
#define CHECK_A_TO_Z(symbol) (symbol >= 'A' && symbol <= 'Z')
#define CHECK_0_TO_9(symbol) (symbol >= '0' && symbol <= '9')

int main(void)
{
    char buff;

    printf("Enter a Symbol: ");
    scanf("%c", &buff);

    if (CHECK_a_TO_z(buff) || CHECK_A_TO_Z(buff)){
        printf("It'S Alphabetic Symbol \n");
    }
    else if (CHECK_0_TO_9(buff)) printf("It's Digit Symbol \n");
    else printf("It's Special Symbol \n");
   
    return EXIT_SUCCESS;
}