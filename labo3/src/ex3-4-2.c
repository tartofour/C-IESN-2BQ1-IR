#include <stdio.h>

void swap_values(int * a, int * b)
{
    int buffer = *a;
    *a = *b;
    *b = buffer;
}

int main(void)
{
    int number1 = 4;
    int number2 = 9;

    printf("Valeur 1: %d\n", number1);
    printf("Valeur 2: %d\n", number2);

    swap_values(&number1, &number2);

    printf("Valeur 1: %d\n", number1);
    printf("Valeur 2: %d\n", number2);
}
