#include <stdio.h>

int main(void)
{
    int nb = 5;
    char * pNb = &nb;

    printf("Valeur pointée par le pointeur char (nb = 5): %d\n", *pNb);

    nb = 150;
    printf("Valeur pointée par le pointeur char (nb = 150): %d\n", *pNb);

    // Nous constatons qu'il y a dépassement de la limite d'un char (-127 -> 127). 
    // Un pointeur doit toujours être du même type que la variable qu'il pointe. 
    // Sinon, la valeur va être mal interprété et créer un comportement bizarre.
}
