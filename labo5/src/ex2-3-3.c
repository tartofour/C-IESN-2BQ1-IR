#include <stdio.h>
#include <stdlib.h>

void printFile(char * filename)
{
    FILE * file = fopen(filename, "r");
    
    if(file==NULL)
    {
        printf("Entrez le nom d'un fichier valide!\n");
    }

    else
    {
        char c = fgetc(file);
        while (c != EOF)
        {
            printf("%c", c);
            c = fgetc(file);
        }
    }
}

int main(void)
{
    printFile("test.txt");    
}
