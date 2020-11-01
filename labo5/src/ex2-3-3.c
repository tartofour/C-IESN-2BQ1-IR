#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_CHAR 255

void printHelp(char * prgName)
{
    printf("Utilisation : ");
    printf("%s SOURCE DEST \n", prgName);
    printf("Copie le fichier SOURCE vers DEST\n");
    printf("    -h,           affiche ce message\n");
}

void printError(char * prgName, char * errStr)
{
    printf("Erreur : %s\n", errStr);
    printHelp(prgName);
}

int isFileExist(char * fname)
{
    FILE * file;
    if ((file = fopen(fname, "r")))
    {
        fclose(file);
        return 1;
    }
    return 0;
}

int main(int argc, char * argv[])
{
    // Vérification des arguments
 
 if (strcmp(argv[1], "-h") == 0)
    {
       printHelp(argv[0]);
       return EXIT_SUCCESS;
    }
  
    if (argc != 3)
    {
        printError(argv[0], "nombre d'arguments invalide");
        return EXIT_FAILURE;
    }
    
    if (!isFileExist(argv[1]))
    {
        printError(argv[1], "le fichier source n'existe pas");
        return EXIT_FAILURE;
    }

    if (isFileExist(argv[2]))
    {
        printError(argv[0], "le fichier de destination existe déjà");
        return EXIT_FAILURE;
    }

    else // Copie des fichiers
    {

        FILE * sourceFile = fopen(argv[1], "r");    
        FILE * destFile = fopen(argv[2], "w");    
        char line[MAX_CHAR];

        while (fgets(line, MAX_CHAR, sourceFile) != NULL)
        {
            fputs(line, destFile);
        }

        fclose(sourceFile);
        fclose(destFile);

        return EXIT_SUCCESS;
    }
}
