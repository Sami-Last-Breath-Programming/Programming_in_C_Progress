#include <stdio.h>

#define EXIT_SUCCESS 0;
typedef  short unsigned int imageInt;

int main(void)
{
    const imageInt Height = 1080;
    const imageInt Width =  1080;
    const imageInt redBrightness = 255;
    const imageInt greenBrightness = 0;
    const imageInt blueBrightness = 255;

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
            imageData[row][column][0] = redBrightness;
            imageData[row][column][1] = greenBrightness;
            imageData[row][column][2] = blueBrightness;
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