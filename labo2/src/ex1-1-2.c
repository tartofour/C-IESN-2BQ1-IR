#include <stdio.h>

int main(void)
{
    int nb = 19;

    if (nb % 2 == 0)
        printf("Le plus petit diviseur de %d est 2.\n", nb);
    else if (nb % 3 == 0)
        printf("Le plus petit diviseur de %d est 3.\n", nb);
    else if (nb % 4 == 0)
        printf("Le plus petit diviseur de %d est 4.\n", nb);
    else
        printf("%d est premier.\n", nb);
}
