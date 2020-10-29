#include <stdio.h>

void double_value(int * a)
{
    *a = *a * 2;
}

int main(void)
{
    int number = 4;
    printf("Valeur : %d\n", number);

    double_value(&number);
    printf("Nouvelle valeur : %d\n", number);
}
