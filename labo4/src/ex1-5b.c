#include <stdio.h>
#include <string.h>
#define SIZE 3

// À REFAIRE

void affiche_plateau(char * plateau, int size)
{
    int i;
    int j;

    for(i=0; i<size*size; i=i+size)
    {   
        for(j=0; j<size; j++)
            printf("%c ", *(plateau+i+j));
        printf("\n");
    }
}



int main(void)
{
    char plateau[3][3] = {{'O', 'X', 'O'},
        	    		  {'O', 'X', 'O'},
		            	  {'O', 'X', 'O'}};

    affiche_plateau(*plateau, SIZE);
}


