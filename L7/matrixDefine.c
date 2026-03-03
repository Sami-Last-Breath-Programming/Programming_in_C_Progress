#include <stdio.h>

#define EXIT_SUCCESS 0

int main(void)
{   
    
    const short int row = 3;
    const short int column =  3;
    
    // 3 x 3 Matrix
    char *matrix[3][3] = {
        
        [0][0] = "Abdul",
        [0][1] = "Armaan",
        [0][2] = "Ali",
        [1][0] = "Lion",
        [2][0] = "King",
    };

    for (int indexRow = 0; indexRow < row; indexRow++)
    {
        printf("----------------------------\n");   
        
        for (int indexColumn = 0; indexColumn < column; indexColumn++)
        {
            printf("Row: %i, Column: %i --> %s \n",
                indexRow + 1, indexColumn + 1, matrix[indexRow][indexColumn]
            );

            if (indexRow == (row - 1) && indexColumn == (column - 1))
                printf("----------------------------\n");  

        }
    }

    return EXIT_SUCCESS;
}