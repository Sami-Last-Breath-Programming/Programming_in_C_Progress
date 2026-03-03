#include <stdio.h>
#include <stdint.h>

int main(void)
{
    unsigned char fakenum = 65;
    // int8_t fakenum = 65; 

    fakenum += 225;

    printf("The Fake Number is: %d \n", fakenum);
    printf("The Character from FakeNumber is: %c \n", fakenum);

    return 0;
}