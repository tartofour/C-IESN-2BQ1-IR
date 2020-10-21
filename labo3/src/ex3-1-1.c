#include <stdio.h>

int main(void)
{
    int a;
    int b;

    printf("Adresse de a : %x\n", &a);
    printf("Adresse de b : %x\n", &b);
    // On constate que les deux adresses sont décalées de 4 octets (soit le sizeof(int)).
}
