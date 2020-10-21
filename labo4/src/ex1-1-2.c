#include <stdio.h>

int * last_tab_elmt(int * tab, int tab_size)
{
    return tab + tab_size - 1;
}

int main(void)
{
    int tableau[] = {4, 5, 1, 4, 1, 3, 6, 7};
    int size_tableau = sizeof(tableau) / sizeof(int);
    int * pLast_elmt = last_tab_elmt(tableau, size_tableau);
    
    printf("Adresse du dernier élément du tableau : %x\n", pLast_elmt);

}
