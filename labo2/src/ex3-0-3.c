#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool contains(char tab[], int size, char c);

bool contains(char tab[], int size, char c)
{
    for (int i=0; i<size; i++)
    {
        if (tab[i] == c)
            return true;
    }
    return false;
}

int main(void)
{
    char name[] = "johnny";
    int size = strlen(name)+1;
    bool is_containing_c = contains(name, size, 'b');
    printf("Le résultat est : %d (0 == False, 1 == True)\n", is_containing_c);
}
