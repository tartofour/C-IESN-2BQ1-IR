#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double * ptr = NULL;
    ptr = (double *) realloc(ptr, sizeof(double));
}
