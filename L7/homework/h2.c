#include <stdio.h>

#define EXIT_SUCCESS 0
#define true 1

void setZero(int *array, int size)
{
    for (int count = 1; count < size; count++)
    {
        array[count] = 0;
    }
}

void welcomeMSG()
{
    printf("\n---------------------------------------\n");
    printf("Welcome, Review Us\n");
    printf("From 1 to 10 !\n");
    printf("\n---------------------------------------\n");
}

void makeTableHeader(void)
{
    printf("\n---------------------------------------\n");
    printf("   Rating        Number of Responces   \n");
    printf("---------------------------------------\n");
}

void makeTable(int *array, int size)
{
    for (int count = 1; count < size; count++)
    {
        printf("%4i%22i\n",
            count, array[count]
        );
    }
}

int main(void)
{
    // Scale with count 
    int scale[11], response;

    // Scale default count to zero
    setZero(scale, 11);

    // Display Welcome message
    welcomeMSG();
    
    //Taking 20 Rating from user 
    while (true)
    {
        printf("Rating: ");
        scanf("%i", &response);

        if (response == 999)
            break;
        else if (response < 1 || response > 10)
            printf("\nError Invalid Review\n\n");
        else
            scale[response]++;     
    }      
    
    // Displaying Ratings count
    makeTableHeader();
    makeTable(scale,11);

    return EXIT_SUCCESS;
}