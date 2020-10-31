#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

// Pas compris


int main(void)
{
    char input[BUFFER_SIZE];

    fputs("Entrez une chaine de caractère : ", stdout);
    fgets(input, BUFFER_SIZE, stdin);
    printf("%s\n", input);
}



