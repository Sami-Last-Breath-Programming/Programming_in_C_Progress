#include <stdio.h> 

// Debuging
#define Debug(x) printf("Debug: (INT) %4i\n", x)

// To Operating System
#define EXIT_SUCCESS 0;
#define ERROR 1;

// Declaration of functions
void fillMatrix(int row, int column, int [row][column]);
void scaleMatrix(int row, int column, int [row][column], int);
void displayMatrix(int row, int column, int[row][column], int);
 
// Entry Point 
int main(void)
{
    int row, column, scalar;
    
    // Input of Row and Column from User
    printf("-------------------------\n");
    printf("Enter Row And Coulun \n");
    printf("Example: 3 x 3 \n");
    printf("-------------------------\n");
    printf(": ");
    scanf("%i x %i", &row, &column);
    printf("-------------------------\n");

    // If Input Valid and Greater than Zero
    if (row > 0 && column > 0)
    {
        // Declaration of Matrix and Filling 
        int matrix[row][column];
        fillMatrix(row, column, matrix);
        
        printf("-------------------------\n");

        //Input Scalar from User
        printf("Enter the Scale by Value: ");
        scanf("%i", &scalar);
        
        printf("-------------------------\n");

        // Display Orginal Matrix
        displayMatrix(row, column, matrix, 0);
        
        // Scale Matrix
        scaleMatrix(row, column, matrix, scalar);
        
        // Display Matrix After Scaleing
        displayMatrix(row, column, matrix, scalar);
    }
    else
    {
        // If Input is Zero or Negative Handle Error
        printf("Error: Can't Be Zero or Negative !");
        return ERROR;
    }

    return EXIT_SUCCESS;
}

void fillMatrix(int row, int column, int matrix[row][column])
{
    // For Recent Input from User
    int temp;

    // Looping Throught each Row 
    for (int indexRow = 0; indexRow < row; indexRow++)
    {
        // Looping Throught each Column
        for (int indexColumn= 0;  indexColumn < column; indexColumn++)
        {
            // Input from User for each Row and Column
            printf("Input for Row | %i | and Column | %i |: ",
                indexRow + 1, indexColumn + 1
            );
            scanf("%i", &temp);
            
            // Storing The Input in The Matrix
            matrix[indexRow][indexColumn] = temp;
            printf("\n");
        }
    }
}

void scaleMatrix(int row, int column, int matrix[row][column], int scalar)
{
    // Looping Throught each Row 
    for (int indexRow = 0; indexRow < row; indexRow++)
    {
        // Looping Throught each Column
        for (int indexColumn= 0;  indexColumn < column; indexColumn++)
        {   
            // Scale the Matrix each Row Column by Scaler
            // Debug(matrix[indexRow][indexColumn]);
            matrix[indexRow][indexColumn] *= scalar;
           // Debug(matrix[indexRow][indexColumn]);
        }
    }
}

void displayMatrix(int row, int column, int matrix[row][column], int scalar)
{
    // Header 
    if (scalar != 0) printf("\nMatrix Scaled By %i:\n", scalar);
    else printf("\nOrginal Matrix: \n");
    
    // Looping Throught each Row 
    for (int indexRow = 0; indexRow < row; indexRow++)
    {
        // Looping Throught each Column
        for (int indexColumn= 0;  indexColumn < column; indexColumn++)
        {   
            // Each Row Matrix Display
            printf("%5i", matrix[indexRow][indexColumn]);
        }
        printf("\n");
    }
    printf("\n");
}