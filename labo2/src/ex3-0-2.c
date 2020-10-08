#include <stdio.h>

# define TAB_SIZE_MAX 4

int tab_values_sum(int tab[], int tab_size);

int tab_values_sum(int tab[], int tab_size)
{
    int result = 0;

    for (int i=0; i<tab_size; i++)
    {
        result = result + tab[i];
    }
    return result;
}

int main(void)
{
    int tab[TAB_SIZE_MAX] = {9874,2234,12331,23};
    int sum = tab_values_sum(tab, TAB_SIZE_MAX);
    printf("Le résultat est : %d\n", sum);
}
