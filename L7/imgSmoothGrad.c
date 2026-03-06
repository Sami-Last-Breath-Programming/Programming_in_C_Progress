// formual pixelSegemnt  =  (inc* MaxBrightness) / Width;

#include <stdio.h>

#define EXIT_SUCCESS 0
#define pixel(segment) imgData[row][column][segment]


typedef short unsigned int  imgInt;

int main(void)
{
    const imgInt Height =  720;
    const imgInt Width =  720;

    // Array to store image data 
    imgInt imgData[Height][Width][3];

    // Header For Image file
    printf("P3\n");
    printf("%i %i\n", Height, Width);
    printf("%i\n", 255);

    // Image Data 
    for (imgInt row = 0; row < Height; row++)
    {
        for (imgInt column = 0, inc = 0; column < Width; column++, inc += 2)
        {
            if (column <= 240)
            {
                pixel(0) = 255;
                pixel(1) = (inc * 255) / Width + 85;
                pixel(2) = 0;
            }
            else if (column > 240 && column <= 480)
            {
                pixel(0) = 255 - (column * 255 / Width) + 80;
                pixel(1) = 255;
                pixel(2) = 0;
            }
            else
            {
                pixel(0) = 255 - (column * 255 / Width) + 80;
                pixel(1) = 255;
                pixel(2) = 0;
            }

        }
    }

    
    // Image Data in Stdin buffer
    for (imgInt row = 0; row < Height; row++)
    {
        for (imgInt column = 0; column < Width; column++)
        {
            // Pixel
            printf("%i ", pixel(0));
            printf("%i ", pixel(1));
            printf("%i ", pixel(2));
        }
    }
    
    
    return EXIT_SUCCESS;
}

