#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Pas certain d'avoir compris

bool isString(char tab[], int size);

bool isString(char tab[], int size)
{
    return tab[size] == '\0';
}

int main(void)
{
    char name[] = "bonjour";
    int size = strlen(name);
    printf("%d\n", isString(name, size));
}
