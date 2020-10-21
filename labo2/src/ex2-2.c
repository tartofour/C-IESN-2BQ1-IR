#include <stdio.h>

float poww(unsigned int, unsigned int);

float poww(unsigned int base , unsigned int exponent)
{
    if (exponent == 0)
        return 1;
    
    unsigned int result = base;

    for (unsigned int i=2; i<=exponent; i++)
        result = result * base;
    
    return result;
}

int main(void)
{
    unsigned int a = poww(12,3);
    printf("%u\n", a);
}
