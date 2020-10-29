#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i = 5;
    int * j = (int *) realloc(&i, 5 * sizeof(int));
}

// Nous obtenons l'erreur  : realloc(): invalid pointer 
//                           Abandon (core dumped)

// Il est impossible de réordonner la mémoire dans la pile.
