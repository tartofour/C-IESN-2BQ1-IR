#include <stdio.h>

int main(void)
{
    int a = 12;
    int b = 31;

    printf("Adresse de a : %x\n", &a);
    printf("Adresse de b : %x\n", &b);

    int * pA = &b + 1;
    *pA = 100;  

    printf("Adresse pointée par pA : %x\n", pA);
    printf("Nouvelle valeur de a : %d\n", *pA);
}

