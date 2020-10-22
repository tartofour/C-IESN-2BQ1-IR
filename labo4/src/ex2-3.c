#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void printHelp(char * prgName)
{
    printf("Utilisation :");
    printf("%s OPTION [MSG] [L] \n", prgName);
    printf("Affiche un mot ou un caractères majuscule.\n");
    printf("    -h,         affiche ce message\n");
    printf("    -e MSG,     affiche le message MSG\n");
    printf("    --maj L,    affiche la lettre L en majuscule\n");
    printf("\n");
}

void printError(char * prgName, char * errStr)
{
    printf("Erreur : %s\n", errStr);
    printHelp(prgName);
}

int main(int argc, char * argv[])
{
    int mode; // 0 -> -e; 1 -> --maj
    
    // Vérification des arguments
    
    if (argc < 2 || argc > 3)
    {
        printError(argv[0], "nombre d'arguments invalide");
        return EXIT_FAILURE;
    }
    
    if (strcmp(argv[1], "-h") == 0)
    {
       printHelp(argv[0]);
       return EXIT_SUCCESS;
    }

    if (strcmp(argv[1], "-e") == 0)
    {
        mode = 0;
    }

    else if (strcmp(argv[1], "--maj") == 0)
    {   
        if (strlen(argv[2]) != 1)
        {
            printError(argv[0], "le mode --maj ne peut afficher qu'un caractère");
            return EXIT_FAILURE;
        }
        
        else
        {
            mode = 1;
        }
    }
    
    else 
    {
        printError(argv[0], "-e ou --maj requis");
        return EXIT_FAILURE;
    }

    //Exécution du programme

    switch(mode)
    {
        case 0:
            printf("%s\n", argv[2]);
            return EXIT_SUCCESS;

        case 1:
            printf("%c\n", toupper(*argv[2]));
            return EXIT_SUCCESS;
    }

}
