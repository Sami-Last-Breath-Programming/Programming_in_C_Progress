#include <stdio.h>

#define EXIT_SUCCESS 0;

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
    int scale[11], responce;

    // Scale default count to zero
    setZero(scale, 11);

    // Display Welcome message
    welcomeMSG();
    
    //Taking 20 Rating from user 
    for (int count = 1; count <= 20; count++)
    {
         printf("Rating: ");
         scanf("%i", &responce);

        if (responce < 1 || responce > 10)
            printf("\nError Invalid Review\n\n");
        else
            scale[responce]++;
    }       
    
    // Displaying Ratings count
    makeTableHeader();
    makeTable(scale,11);

    return EXIT_SUCCESS;
}