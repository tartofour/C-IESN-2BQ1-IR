#include <stdio.h>

void affiche_plateau(char ** plateau)
{
    int i;
   
    printf(" %c  %c  %c ", plateau[0][0], plateau[0][1], plateau[0][2]);
}


int main(void)
{
    char plateau[3][3] = {{"aaa"},
        	    		  {"aaa"},
		            	  {"aaa"}};

    affiche_plateau(plateau);
}


