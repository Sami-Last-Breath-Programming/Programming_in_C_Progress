#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <omp.h>  // open multi processing

#define EXIT_STATUS 0
#define true 1

int *cores;

/* void cry(long int times)
{   
    #pragma omp parallel for
    for (long int i = 0; i <= times; i++)
    {
        printf("Crying... %ld times\n", i);
    }
}
*/


long int  *dontCry(long int times)
{
    long int *count = (long int*)malloc(sizeof(long int));

    #pragma omp parallel for 
    for (long int i = 0; i<= times; i++)
    {
        if (i == times){
            *count = i;
            
            #pragma omp critical
            *cores = omp_get_num_threads();
        }
    };

    return count;
}

int main(void)
{   
    cores = (int*)malloc(sizeof(int)); 

    clock_t snap1 = clock();
    // cry(100000000000);
    long int *result = dontCry(100000000000);
    printf("Done Counting Till %ld \n", *result);

    clock_t snap2 = clock();
    printf("Total time Taken While Crying: %f \n",
        ((double)(snap2-snap1)/CLOCKS_PER_SEC)/ *cores
    );

    free(result);
    free(cores);
    
    return EXIT_STATUS;
}