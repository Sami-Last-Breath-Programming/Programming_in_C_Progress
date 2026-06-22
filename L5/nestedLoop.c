#include <stdio.h>
#include <stdlib.h>

#define EXIT_SUCCESS 0


int triNumCalculator(int rows)
{   
    int currentNum;
    // int *triNum = calloc(1, sizeof(int));
    int triNum = 0;
    
    for (currentNum =1; currentNum <= rows; currentNum ++)
    {
        triNum += currentNum;
    }

    return triNum;
}


int* makeUI(int times)
{   
    int rows;
    int result;
    int *resultStore = calloc(times, sizeof(int));
    int currentDraw;
    
    for (currentDraw = 1; currentDraw <= times; currentDraw++)
    {
        printf("Enter The Rows Of Triangle %i: ", currentDraw);
        scanf("%i", &rows);
        result = triNumCalculator(rows);
        resultStore[currentDraw -1] = result;
        // free(result); 
    }
    return resultStore;
}


int main(void)
{
    int times;
    int *resultStore;

    printf("Welcome, How many Values to find ?: ");
    scanf("%i", &times);

    resultStore = makeUI(times);

    for (int index = 0; index < times; index++)
    {
        printf("\nThe Results Are -----> %i: %i \n", 
            index+1 ,resultStore[index]
        );
    }

    free(resultStore);

    return EXIT_SUCCESS;
}