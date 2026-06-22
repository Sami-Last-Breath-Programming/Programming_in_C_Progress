#include <stdio.h>
#include <stdlib.h>

// Main Entry
int main(void)
{
    // A - Z | a - z
    char alpha[] = 
{
"A B C D E F G H I J K\
 L M N O P Q R S T V U\
 W X Y Z\
 a b c d e f g h i j k\
 l m n o p q r s t v u\
 w x y z"
};

    char brea_k[] = {
        "Hello " "Hi "
        "It's " "Nice "
        "To " "Meet "
        "You " "!"
    };

    // Print the String
    printf("%s\n",  alpha);
    printf("%s\n", brea_k);

    // Break in prinf()
    printf("The Sum of %i" " + %i is " "%i" "\n", 5, 10, 5 + 10);
    
    return EXIT_SUCCESS;
}
