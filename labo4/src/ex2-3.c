#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TAILLE_MAX 50

void printHelp(char * prgName)
{
    printf("Utilisation :");
    printf("%s OPTION [MSG] [L] \n", prgName);
    printf("Affiche un mot de maximum %d caractère ou un caractères majuscule.\n", TAILLE_MAX);
    printf("    -h,           affiche ce message\n");
    printf("    -e MSG,       affiche le message MSG\n");
    printf("    --maj L,      affiche la lettre L en majuscule\n");
    printf("    --add A B,    affiche l'addition des entiers  A et B\n");
}

void printError(char * prgName, char * errStr)
{
    printf("Erreur : %s\n", errStr);
    printHelp(prgName);
}

int main(int argc, char * argv[])
{
    int mode; // 0 -> -e ; 1 -> --maj ; 3 -> --add
    
    // Vérification des arguments
    
    if (argc < 2 || argc > 4)
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
        if (argc > 3)
        {
            printError(argv[0], "nombre d'arguments pour l'option -e invalide");
            return EXIT_FAILURE;
        }

        if (strlen(argv[2]) > TAILLE_MAX)
        {
            printError(argv[0], "limite de caractères dépassée");
            return EXIT_FAILURE;
        }

        mode = 0;
    }

    else if (strcmp(argv[1], "--maj") == 0)
    {   

        if (argc > 3)
        {
            printError(argv[0], "nombre d'arguments pour l'option --maj invalide");
            return EXIT_FAILURE;
        }

        if (strlen(argv[2]) != 1)
        {
            printError(argv[0], "le mode --maj ne peut afficher qu'un caractère");
            return EXIT_FAILURE;
        }

        if (isalpha(*argv[2]) == 0)
        {
            printError(argv[0], "le caractère entré doit être une lettre");
            return EXIT_FAILURE;
        }
        
        else
        {
            mode = 1;
        }
    }


    else if (strcmp(argv[1], "--add") == 0)
    {
        if (argc != 4)
        {
            printError(argv[0], "nombre d'arguments pour l'option --add invalide");
            return EXIT_FAILURE;
        }


        int a = atoi(argv[2]);
        int b = atoi(argv[3]);

        if (a == 0 || b == 0)
        {
            printError(argv[0], "A et B doivent être des entiers non nuls");
            return EXIT_FAILURE;
        }

        else
        {
            mode = 2;
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
        // -e
        case 0:
            printf("%s\n", argv[2]);
            return EXIT_SUCCESS;
        
        // --maj
        case 1:
            printf("%c\n", toupper(*argv[2]));
            return EXIT_SUCCESS;

        // --add
        case 2:
            printf("%d\n", a + b);
            return EXIT_SUCCESS;
    }

}
