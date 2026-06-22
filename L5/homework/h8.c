// nested While loop for Tringular Number

#include <stdio.h>
#include <stdlib.h>

#define EXIT_SUCCESS 0

int calculateTriNum(int row)
{
    int count = 1, triNum = 0;
    
    while (count <= row)
    {
        triNum += count;
        count++;
    }
    return triNum;
} 


int* makeUI(int times)
{   
    int drawUI = 1, row = 0, result = 0;
    int *resultList = calloc(times, sizeof(int));

    while (drawUI <= times)
    {
        printf("Enter The Triangle Row %i: ", drawUI);
        scanf("%i", &row);
        result = calculateTriNum(row);
        resultList[drawUI-1] = result;
        drawUI++;
    }
    printf("\n");

    return resultList;
}

int main(void)
{
    int times, index = 0;
    int *resultList;

    printf("How many Valus to Find: ");
    scanf("%i", &times);
    
    resultList = makeUI(times);

    while (index < times)
    {
        printf("The Triangular Number %i is: %i \n",
            index + 1, resultList[index]
        );
        index++;
    }
    
    free(resultList);

    return EXIT_SUCCESS;
}