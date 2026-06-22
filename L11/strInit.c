// String inti rules with pointers 

#include <stdio.h>
#include <stdlib.h>

// Main Entry 
int main(void)
{
    char *str1; // pointer to a character
    char str2[20] = "Hello Mom !"; // array of character
    
    // Init string after the declaration of ptr
    str1 = "Hello Devil !";
    /*  This will work becauae the str1 is a pointer 
        To a charater and " " string lateral returns a 
        Pointer of character array
    */

    // Init the array of character
    //  str2 = "Hello Mom !";
    /*  This will not work because the str2 is a pointer of
        first element of array and string lateral retrun the 
        first element pointer of the lateral array 
    */

    // Try to print str1
    printf("%s\n", str1);
    printf("%s\n", str2);
    
    return EXIT_SUCCESS;
}
