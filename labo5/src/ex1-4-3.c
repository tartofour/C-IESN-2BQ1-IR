#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int * nb = (int *) malloc(sizeof(int));
    nb = (int *) realloc(nb, sizeof(double));
    free(nb);
}
