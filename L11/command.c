#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Clang Flags
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wvla"
#pragma clang diagnostic ignored "-Wpadded"
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#pragma clang diagnostic ignored "-Wgnu-folding-constant"

// Declarations
int sum(int, int);
int sub(int, int);
int divd(int, int);
int mul(int, int);

// Command Struct
typedef struct command
{
    char name[4];
    int (*call)(int, int);
}command;

// Main Entry 
int main(void)
{
    int result = 0;
    char buff[64];
    const int size = 4;
    int num1, num2, err = 0;

    // Array of Commands
    command array[size] = {
        {.name = "SUM", .call = sum},
        {.name = "SUB", .call = sub},
        {.name = "DIV", .call = divd},
        {.name = "MUL", .call = mul},
    };

    // Input from user
    printf("Enter the Numbers: ");
    err = scanf("%i, %i", &num1, &num2);

    // Handle err
    if (err < 1 || err == EOF)
    {
        printf("Error: Scanf Failed\n");
        exit(EXIT_FAILURE);
    }

    // Operator from the user
    printf("Enter the Operator: ");
    err = scanf("%4s", buff);

    // Handle err
    if (err < 1 || err == EOF)
    {
        printf("Error: Scanf Failed\n");
        exit(EXIT_FAILURE);
    }

    // Check the operator in array 
    for (size_t index = 0; index < size; index++)
    {
        if (!strcmp(array[index].name, buff))
        {
            // Run command 
            result = array[index].call(num1, num2);
            break;
        }
    }

    // Print the result
    printf("The Result is %i\n", result);

    return EXIT_SUCCESS;
}

// Implementations
int sum(int num1, int num2) {   return num1 + num2;  }
int sub(int num1, int num2) {   return num1 - num2;  }
int divd(int num1, int num2){   return num1 / num2;  }
int mul(int num1, int num2) {   return num1 * num2;  }

#pragma clang diagnostic pop
