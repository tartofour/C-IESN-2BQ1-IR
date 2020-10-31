#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char input[10];
    printf("Entrez une chaine de caractère : ");
    scanf("%s", &input);
    printf("%s\n", input);
}

// Nous obtenons l'erreur *** stack smashing detected ***: terminated


