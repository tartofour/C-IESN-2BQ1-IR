#include <stdio.h>
#include <string.h>
#define SIZE 3

// À REFAIRE

void affiche_plateau(char * p)
{
    

    for (int i=0; i<9; i++) 
        {
            
            printf(" %c ", *(p+i));
            if (i == 2 | i == 5 | i == 8)
                printf("\n");
        }
}   


int main(void)
{
    char plateau[3][3] = {{'a', 'z', 'e'},
        	    		  {'a', 'l', 'a'},
		            	  {'t', 'e', 'a'}};

    
    affiche_plateau(*plateau);
 
}


