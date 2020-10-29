#include <stdio.h>

int main(void)
{
    int tab[3];

    *tab = 1;
    *(tab+1) = 2;
    *(tab+2) = 3;

    for (int i=0; i<3; i++)
        printf("Valeur de l'élément %d : %d\n", i, *(tab+i));	
}
