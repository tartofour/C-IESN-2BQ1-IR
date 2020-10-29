#include <stdio.h>

int main(void)
{
    int a = 12;
    int b = 31;

    printf("Adresse de a : %x\n", &a);
    printf("Adresse de b : %x\n", &b);
    printf("Valeur de b : %d\n", b);

    int * pB = &a + 1;
    *pB = 100;  

    printf("Adresse pointée par pB : %x\n", pB);
    printf("Nouvelle valeur de b : %d\n", b);
}

