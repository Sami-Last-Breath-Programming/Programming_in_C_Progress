#include <stdio.h>
#include <stdlib.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wvla"
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"

#define ROW  4
#define COLUMN 5

void transposeMatrix(
    int old[ROW][COLUMN], 
    int new[COLUMN][ROW]
);

void displayMatrix(int R, int C, int matrix[R][C]);

// Entry Point
int main(void)
{
    int num = 0, error; 
    
    int oldMatrix[ROW][COLUMN] = {0};
    int newMatrix[COLUMN][ROW] = {0};
    
    // Loop through each Row
    for (int row = 0; row < ROW; row++)
    {
        // Loop throught each Column
        for (int column = 0; column < COLUMN; column++)
        {
            printf("Row: %i, Column: %i: ", row+1, column+1);
            error = scanf(" %i", &num);
            
            // Store the input from the user
            if (error != 0)
            {
               oldMatrix[row][column] = num;
               continue;
            }
            
            // On Error
            oldMatrix[row][column] = 0;

        }
    }

    // Transpose Matrix
    transposeMatrix(oldMatrix, newMatrix);

    // Display Old Matrix
    printf("-------------Old Matrix-------------\n");
    displayMatrix(ROW, COLUMN, oldMatrix);

    // Display New Matrix
    printf("\n-------------New Matrix-------------\n");
    displayMatrix(COLUMN, ROW, newMatrix);
    
    return EXIT_SUCCESS;
}

void displayMatrix(int R, int C, int matrix[R][C])
{
    // Loop through each Row
    for (int row = 0; row < R; row++)
    {
        // Loop throught each Column
        for (int column = 0; column < C; column++)
        {
            printf("%3i ", matrix[row][column]);
        }
        printf("\n");
    }
}

void transposeMatrix(
    int old[ROW][COLUMN], 
    int new[COLUMN][ROW]
)
{
    // Loop through each Row
    for (int row = 0; row < ROW; row++)
    {
        // Loop throught each Column
        for (int column = 0; column < COLUMN; column++)
        {
            new[column][row] = old[row][column];
        }
    }
}

#pragma clang diagnostic pop
