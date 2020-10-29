#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int * nb1 = (int *) malloc(sizeof(int));
    *nb1 = 5;
    printf("adresse de nb1 : %x\n", nb1);
    printf("valeur de nb1 : %d\n", *nb1);

    free(nb1);

    int * nb2 = (int *) malloc(sizeof(int));
    printf("adresse de nb2 : %x\n", nb2);
    printf("valeur de nb2 : %d\n", *nb2);
}

// On obtient bien la même adresse, mais la valeur contenue à cette adresse mémoire a changée.

