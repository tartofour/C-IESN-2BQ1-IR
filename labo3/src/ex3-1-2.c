#include <stdio.h>

int main(void)
{
    char a;
    char b;

    printf("Adresse de a : %x\n", &a);
    printf("Adresse de b : %x\n", &b);
    // On constate ici que les deux adresses sont décalées de 1 octet (soit le sizeof(char)).
}
