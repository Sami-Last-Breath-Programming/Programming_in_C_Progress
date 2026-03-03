#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;

// Extracting and poping Digit from Number
uint getLastDigit(uint num) {return (num % 10);}
uint popLastDigit(uint num) {return (num / 10);}

// Function to Extract digits and store in array
uint *extractDigits(uint num, uint *arraySize)
{
    uint *numArray = (uint*) malloc(4 * sizeof(uint));
    *arraySize = 4;
    uint arrayCapacity = 4;
    int count = 0;
    
    // Including zero and storing number in heap array
    do
    {
        if (count < arrayCapacity)
            numArray[count] = getLastDigit(num);
        else
        {
            numArray = (uint *) realloc(
                numArray,
                (arrayCapacity + arrayCapacity) * sizeof(uint)
            );

            arrayCapacity += arrayCapacity;
            numArray[count] = getLastDigit(num);
        }
        
        num = popLastDigit(num);
        count++;
    }
    while (num !=0);
    
    *arraySize = count;
    return numArray;
};

void reverseArray(uint *numArray, uint arraySize)
{
    uint *temp = (uint *) malloc(arraySize * sizeof(uint));
    int count = arraySize -1;
    
    for (; count >= 0 ; count--)
        temp[(arraySize - 1) - count] = numArray[count];
    
    for (count = 0; count < arraySize; count++)
        numArray[count] = temp[count];

    free(temp);
}

// Logic for number to word conversion
void printDigitWord(uint *numArray, uint arraySize)
{
    char *word[10] = {
        "Zero", "One", "Two", "Three", "Four",
        "Five", "Six","Seven", "Eight", "Nine"
    };

    // Checking for Num and word match then printng
    for (int count = 0; count < arraySize; count++)
    {
        if (count != 0)
            printf(" %s", word[numArray[count]]);
        else printf("%s", word[numArray[count]]);
    }
    printf("\n");

}
// MainPoint
void runApp()
{
    uint num;
    uint *numArray;
    uint arraySize;
    
    // Opening
    printf("\n------------------------------\n");
    printf("Welcome, Num To Word Converter\n");
    printf("------------------------------\n");
    
    // Getting number from user
    printf("\nEnter A Number: ");
    scanf("%u", &num);

    // Check if not more then 1Crore
    if (num <= 10000000)
    {
        // Extracting digits
        numArray = extractDigits(num,&arraySize);

        // Reverse digits Array
        reverseArray(numArray, arraySize);

        // Printing each digit in text
        printDigitWord(numArray, arraySize);

        // free numArray heap
        free(numArray);
    }
    else printf("Number more than One Crore\n");
    
    // Closing
    printf("------------------------------\n");
    printf("Program Ended !\n");
    printf("------------------------------\n");
}

int main(void)
{
    runApp();   
    return EXIT_SUCCESS;
}