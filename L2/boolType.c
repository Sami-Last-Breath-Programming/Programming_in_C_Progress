#include <stdio.h>


#define True 1
#define False 0
#define EXIT_SUCCESS 0

int main(void)
{
    int isok = False;

    printf("Are you OK ?: ");
    scanf("%d", &isok);
    
    printf("He/She is %s\n", isok ? "Fine": "not Fine");
      
    return EXIT_SUCCESS;
}