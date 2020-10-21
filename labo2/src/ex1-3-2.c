#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int random_number = rand();

    while (random_number % 10 != 0)
    {
        random_number = rand();
        printf("%d\n", random_number);
    }
}
