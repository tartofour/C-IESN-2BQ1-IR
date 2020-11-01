#include <stdio.h>
#include <stdlib.h>

int * int_malloc(int n)
{
    int * ptr = (int *) malloc(sizeof(int)*n);
    return ptr;
}

int main(void)
{
    int * int_tab = int_malloc(4);

    for (int i=0; i<4; i++)
    {
        int_tab[i] = i+1;
        printf("%d\n", int_tab[i]);
    }

free(int_tab);
}
