#include <stdio.h>
#include <stdlib.h>

#define EXIT_SUCCESS 0

typedef struct 
{
    int size;
    int *elements;

} List;

int getLastNum(int num) {return num % 10;}

int popLastNum(int num) {return num / 10;}

// void debug(int size, int element)
// {
//     printf("------------------------\n");
//     printf("The Size of List: %i\n", size);
//     printf("The Element in List: %i\n", element);
//     printf("------------------------\n");
// }

int sumDigits(int num)
{   
    int sum = 0;
    
    while (num != 0)
    {
        sum += getLastNum(num);
        num = popLastNum(num);
    }
    return sum;
}


void appendList(int num, List *list)
{
    int *tmp = realloc((list->elements), (list->size + 1) * sizeof(int));
    
    if (tmp != NULL) 
    {
        list->elements = tmp;
        list->size += 1;
        list->elements[list->size - 1] = num;
    }
    else printf("Error: Cant append List \n");
}
void reverseList(List *list)
{
    int temp[list->size]; 

    for (int index = list->size - 1; index > -1; index--)
    {
        temp[(list->size - 1) - index] = list->elements[index];
    }
    for (int index = 0; index < list->size; index++)
    {
        list->elements[index] = temp[index];
    }    
}

void makeText(int num)
{ 
    // printf("The Sum: ");

    int digit;
    List digitsList = {
        .size = 0,
    };

    // debug(digitsList.size, *(digitsList.elements));

    while (num != 0)
    {
        digit = getLastNum(num);
        if (digitsList.size == 0)
        {   
            digitsList.elements = calloc(1, sizeof(int));
            *(digitsList.elements) = digit;
            digitsList.size += 1;
            // debug(digitsList.size, *(digitsList.elements));
        }
        else appendList(digit, &digitsList);
        // debug(digitsList.size, digitsList.elements[1]);
        num = popLastNum(num);
    }
    
    reverseList(&digitsList);

    for (int index = 0; index < digitsList.size; index++)
    {
        printf("%i", digitsList.elements[index]);
        if (index != digitsList.size - 1) printf(" + ");

    }
    printf(" = ");
    free(digitsList.elements);
}

int main(void)
{   
    int num;
    
    printf("Enter Number To get Sum of Digits: ");
    scanf("%i", &num);
    makeText(num);
    printf("%i\n", sumDigits(num));

    return EXIT_SUCCESS;
}