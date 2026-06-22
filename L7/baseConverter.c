#include <stdio.h>
#include <stdlib.h>

#define EXIT_SUCCESS 0
#define true 1
#define false 0

typedef _Bool bool;

// Globales
int Base;

// Get Input (number and base from user)
void takeInput(int *num)
{
    printf("\n---------------------------\n");
    printf("Welcome To Base Converter\n");
    printf("---------------------------\n");
    printf("Enter the Number to be Converted: ");
    scanf("%i", num);
    printf("---------------------------\n");
    printf("Enter the Base: ");
    scanf("%i", &Base);
}

int *pushRemender(int quotient, int *size, int *remenders)
{
    *size += 1;
    // Allocate the memory for array
    int *temp = realloc(remenders, (*size + 1) * sizeof(int));
    
    // if success then store the remender in array
    if (temp != NULL)
    {
        remenders = temp;
        remenders[*size] = quotient % Base;
    }       
    else
        printf("Error Can't Allocate Memorty\n");

    return remenders;
}


int *getRemenders(int num, int *size, bool isFirst)
{
    int quotient = 0;
    int *remenders = (int *)malloc(sizeof(int));
    
    // If first time running then divide by number
    if (isFirst)
        quotient = num;
  
    // While Quotient is not zero divide it    
    while ((quotient / Base) != 0)
    {            
        // Allocating the memory for remender array
        if (isFirst)
        {   
            // Store the remender in array
            remenders[*size] = quotient % Base;
            isFirst = false; 
        }
        else
        {
            // increase the remender count in array
            remenders = pushRemender(quotient, size, remenders);
        }
        
        // Storing the new quotient 
        quotient = quotient / Base;
    }
    
    // If quotient is zero reverse remenders 
    if (isFirst)
    {
        // Store the remender in array
        remenders[*size] = quotient % Base;
        isFirst = false; 
    }  
    else
        // Add the last remender in array
        remenders = pushRemender(quotient, size, remenders);

    // reverse the array
    int temp[*size + 1];

    for (int lastIndex = *size ; lastIndex >= 0; lastIndex--)
    {
        temp[*size - lastIndex] = remenders[lastIndex];
    }
    for (int index = 0;  index <= *size;  index++)
    {
        remenders[index] =  temp[index];
    }
    return remenders;
}

// Print each remender
void convertToBase(int *sortRemenders, int size)
{
    const char digits[16] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        'A', 'B', 'C', 'D', 'E', 'F'
    };
    
    for (int index = 0; index <= size; index++)
    {
        printf("%c", digits[sortRemenders[index]]);
    }
    printf("\n");
}

int main(void)
{
    int num;
    int *sortRemenders;
    int size = 0;

    // Taking Input from user 
    takeInput(&num);
    
    if (Base > 1 && Base <=16)
    {
        // Get sorted Remenders 
        sortRemenders = getRemenders(num, &size, true);
    
        //Display the Number in given base
        convertToBase(sortRemenders, size);

        // Free memory
        free(sortRemenders);
    }
    else
        printf("Invalid Base: 2 to 16\n");
    
    return EXIT_SUCCESS;
}