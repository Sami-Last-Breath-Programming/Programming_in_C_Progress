#include <stdio.h>

#define EXIT_SUCCESS 0

#define ROW 3
#define COULMN 5

void scalarMUl(int [ROW][COULMN], int);
void displayMatrix(int [ROW][COULMN], int);

int main(void)
{
    int matrix[ROW][COULMN] = {
        { 7, 16, 55, 13, 12},
        {12, 10, 52,  0,  7},
        {-2,  1,  2,  4,  9}
    };
    
    // Orginal 
    displayMatrix(matrix, 0);

    // Scale by 2
    scalarMUl(matrix, 2);
    displayMatrix(matrix, 2);

    // Scale by -1
    scalarMUl(matrix, -1);
    displayMatrix(matrix, -1);
    
    return EXIT_SUCCESS;
}

void scalarMUl(int matrix[ROW][COULMN], int scaler)
{
    // Looping on Row
    for (int row = 0; row < ROW; row++)
    {
        // Looping on Column 
        for (int column = 0; column < COULMN; column++)
        {
            matrix[row][column] *= scaler;
        }
    }
}

void displayMatrix(int matrix[ROW][COULMN], int scaler)
{
    if (scaler != 0) printf("\nScaled by %i:\n", scaler);
    else printf("\nOriginal Matrix:\n");

    // Looping on Row
    for (int row = 0; row < ROW; row++)
    {
        // Looping on Column 
        for (int column = 0; column < COULMN; column++)
        {
           printf("%5i", matrix[row][column]);
        }
        printf("\n");
    }
   
}