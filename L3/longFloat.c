#include <stdio.h>
#include <time.h>

#define EXIT_SUCCESS 0

int main(void)
{   
    // Starting clock
    clock_t start = clock();  // Assuming start at 100

    // long float myLongNum;   Long float is Double
    // long long double myMaxNum;  Long Long double does not exist

    float myNum = 20.3333339999F;
    double myLongNum = 20.3333339999; 
    long double myMaxNum = 20.3333339999L;

    // Printing Sizes
    printf("The size of %.20f is: %zu \n", 
        myNum, sizeof(myNum)
    );
    printf("The size of %.20f is: %zu \n",
        myLongNum, sizeof(myLongNum)
    );    printf("The size of %.20Lf is: %zu \n",
        myMaxNum, sizeof(myMaxNum)
    );

    
    // Stoping clock
    clock_t end = clock(); // Assuming end at 400
    
    // Assuming result 300 (200 - 100)
    double runTime =  (double)end - start; 
    
    // Assuming 300/100 = 3sec
    double totalTime = runTime / CLOCKS_PER_SEC;
    
    // Printing Running Time
    printf("Total Time to Exexcute: %f sec \n", totalTime);

    return EXIT_SUCCESS;
}