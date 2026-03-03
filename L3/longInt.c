#include <stdio.h>

#define EXIT_SUCCESS 0 


int main(void)
{
    // Extending Int Memory
    int myNum = 500000000;
    long int myLongNum = 5000000000L;
    long long int myMaxNum = 5000000000L;
    
    // Print each 
    printf("%-13s \"%-9i\"  size is, \t%zu \n",
        "The myNum", myNum, sizeof(myNum)
    );
    printf("%-10s \"%-10ld\" size is, \t%zu \n",
        "The myLongNum", myLongNum, sizeof(myLongNum)
    );
    printf("%-13s \"%-10lld\" size is, \t%zu \n",
        "The myMaxNum", myMaxNum, sizeof(myMaxNum)
    );
    
    return EXIT_SUCCESS;
}