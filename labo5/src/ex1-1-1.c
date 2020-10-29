#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int * int_malloc(int n)
{
    int * ptr = (int *) malloc(sizeof(int)*n);
    return ptr;
}

int main(void)
{
    int * pInt = int_malloc(4);

    pInt[0]= 1;
    pInt[1] = 2;
    pInt[2] = 3;
    pInt[3] = 4;

    for (int i=0; i<4; i++)
        printf("%d ", pInt[i]);
}
