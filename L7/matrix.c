#include <stdio.h>

#define EXIT_SUCCCESS 0 
#define true 1
#define false 0

int main(void)
{
    
    int ROW = 0;
    int COLUMN = 0;

    // Start Flag 
    int isEnd= false;
    
    // Defining a matrix 
    int matrix[4][5] = {
        {1, 5, 9, 13, 17},
        {2, 6, 10, 14, 18},
        {3, 7, 11, 15, 19},
        {4, 8, 12, 16, 20}
    }; 
    
    // Taking Input from User
    while (!isEnd)
    {
        printf("\n--------------------\n");
        printf("Welcome To Matrix !\n");
        printf("--------------------\n");
        
        // Input of Row 
        printf("\nRow: ");
        scanf("%i", &ROW);

        // Input of Column
        printf("\nColumn: ");
        scanf("%i", &COLUMN);

        // Fix indexing 
        ROW--;
        COLUMN--;
        
        // Check Row and Column be in Limit
        if ((ROW <= 3) && (COLUMN <= 4) && (ROW >= 0) && (COLUMN >= 0))
        {
            // Output 
            printf("--------------------\n");
            printf("The Value at Row: %i and Column: %i is: %i\n",
                ROW, 
                COLUMN,
                matrix[ROW][COLUMN]
            );
            printf("--------------------\n");

            
            // Check for end program
            printf("Did you want to end ?: ");
            scanf("%i", &isEnd);
        }
        else printf("Error: Out of Matrix Limit\n");

    }

    return EXIT_SUCCCESS;
}