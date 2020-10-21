#include <stdio.h>

void new_value(int * a, int new_value)
{
    *a = new_value;
}

int main(void)
{
    int number = 4;
    printf("Valeur : %d\n", number);

    new_value(&number, 18);
    printf("Nouvelle valeur : %d\n", number);
}
