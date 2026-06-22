// Finds area of circle 

#include <stdio.h> 
#include <stdlib.h>

// #define PI = 3.14f  --> Not working in Return

float circleArea(int area)
{
    return (area * area) * 3.14f;
}

int main(int argc, char **argv)
{
    int radius;

    if (argc > 1 && argc < 3)
    {
        radius = atoi(argv[1]);
    }
    else
    {
        printf("Invalid Radius!\n");
        printf("Enter the Radius of Circle: ");
        scanf("%i", &radius);
    
    }
    printf("The Area Of Circle is: %.2f\n", circleArea((int)radius));
    
    return EXIT_SUCCESS;
}