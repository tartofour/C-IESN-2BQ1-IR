#include <stdio.h>

float division(int, int);

float division(int dividend, int divider)
{
    return (float) dividend/divider;
}

int main(void)
{
    printf("%.2F", division(12393,5));
}
