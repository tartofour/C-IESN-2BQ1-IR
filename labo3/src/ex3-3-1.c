#include <stdio.h>

int main(void)
{
    int i = 12;
    int *pI = &i;
    int **ppI = &pI; 
    
    printf("%d\n", **ppI);

    // Il s'agit d'une variable de type double pointeur.
}
