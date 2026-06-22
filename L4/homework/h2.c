#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    const double constDouble = 123.456;
    const double constDoubleHex = 0x10.5p0; // 0x10.5
    // const int constIntHex = 0x0G1;
    const int constInt = 0001;
    const int constIntHex2 = 0xFFFF;
    const long int constLongInt = 123L;
    const int contIntHex3 = 0Xab05;
    const long int constLongInt2 = 0L;
    const double constDouble2 = -597.25;
    const double constDouble3 = 123.5e2;
    const double constDouble4 = .0001;
    const unsigned int constUnsignedInt = +12;
    const float constFloat = 98.6F;
    // const unsigned double = 98.7U; double can't be unsigned
    // const int constInt2 = 17777s; 
    // const int constInt3 = 09965; octa out of 7 digits
    const int constInt4 = -12E-12;
    const int constInt5 = 07777; // Valid octa 
    const unsigned long int constUnsignedLongInt = 1234uL;
    // const float constFloat2 = 1.2Fe-7;   1.2e-7F
    // const int constInt6 = 15,000; 
    const long double constLongDouble = 1.234L ;
    const unsigned int constUnsignedInt2  = 197u;
    const unsigned int constUnsignedInt3 = 100U;
    const long int constlongIntHex = 0XABCDEFL;
    const unsigned int constUnsignedIntHex = 0xabcu;
    const unsigned int constUnsignedInt4 = +123;

    return EXIT_SUCCESS;
}