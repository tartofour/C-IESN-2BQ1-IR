#include <stdio.h>

float poww(unsigned int, unsigned int);

float poww(unsigned int base , unsigned int exponent)
{
    unsigned int result = 0;

    for (unsigned int i = 1; i<=exponent; i++)
    {
        result = result + i * base;
    }
    return result;
}

int main(void)
{
    unsigned int a = poww(2,3);
    printf("%u\n", a);
}
