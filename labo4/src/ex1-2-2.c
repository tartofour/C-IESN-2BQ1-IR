#include <stdio.h>

char * find_char(char string[], char character)
{
    int i = 0;
    char * pChar = NULL;

    while (string[i] != '\0')
    {
        if (string[i] == character)
    	{   
	        pChar = string + i;
	        //pChar = &string[i];
   	        return pChar;
    	}
    	i++;
    }
    return pChar;
}

int main(void)
{
    char * pChar = find_char("Hello world", 'w');

    printf("Adresse du caractère : %x\n", pChar);
}
