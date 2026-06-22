#include <stdio.h>
#include <stdlib.h>

typedef struct month
{
    int days;
    char name[4];

}month;


int main(void)
{
    // Array of Struct of Months
    month months[12] = 
    {
        { 31, {'J', 'a', 'n', '\0'} }, { 28, {'F', 'e', 'b', '\0'} },
        { 31, {'M', 'a', 'r', '\0'} }, { 30, {'A', 'p', 'r', '\0'} },
        { 31, {'M', 'a', 'y', '\0'} }, { 30, {'J', 'u', 'n', '\0'} },
        { 31, {'J', 'u', 'l', '\0'} }, { 31, {'A', 'u', 'g', '\0'} },
        { 30, {'S', 'e', 'p', '\0'} }, { 31, {'O', 'c', 't', '\0'} },
        { 30, {'N', 'o', 'v', '\0'} }, { 31, {'D', 'e', 'c', '\0'} } 
    };
    
    // Header 
    printf("Month\t\tNumber Of Days\n");
    printf("-----\t\t--------------\n");

    // Printing Months
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
    for (size_t index = 0; index < 12; index++)
    {
        printf(" %s  \t\t     %i\n", 
            months[index].name,
            months[index].days
        );
    }
    #pragma clang diagnostic pop

    return EXIT_SUCCESS;
}
