#include <stdio.h>

#define EXIT_SUCCESS 0;
#define pixel(segment) imageData[row][column][segment]

typedef  short unsigned int imageInt;

int main(void)
{
    const imageInt Height = 1080;
    const imageInt Width =  1080;

    // Image Data Array 
    imageInt imageData[Height][Width][3];

    // Header for Image file
    printf("P3\n"); // Process RBG
    printf("%i %i\n", Height, Width); 
    printf("%i\n", 255); 

    // Image Filling Data 
    for (imageInt row = 0; row < Height; row++)
    {
        for (imageInt column = 0; column < Width; column++)
        {
            if  (column <= 200)
            {
                pixel(0) = 255;
                pixel(1) = 222;
                pixel(2) = 0;         
            }
            else if (column > 200 && column <= 600)
            {
                pixel(0) = 43;
                pixel(1) = 0;
                pixel(2) = 255;
            }
            else
            {
                pixel(0) = 255;
                pixel(1) = 0;
                pixel(2) = 0;
            }
        }
    }
    
    // Image Data for file
    for (imageInt row = 0; row < Height; row++)
    {
        for (imageInt column = 0; column < Width; column++)
        {
            printf("%i ", imageData[row][column][0]);
            printf("%i ", imageData[row][column][1]);
            printf("%i ", imageData[row][column][2]);
        }
    }


    return EXIT_SUCCESS;
}