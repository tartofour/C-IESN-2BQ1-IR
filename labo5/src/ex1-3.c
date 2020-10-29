#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[])
{
    // Copie de argc
    int * new_argc = (int *) malloc(sizeof(int));
    * new_argc = argc;
    printf("Valeur de new_argc : %d\n", *new_argc);

    // Copie de argv
    char ** new_argv = (char **) calloc(argc, sizeof(char *));

    for (int i=0; i<argc; i++)
    {
        new_argv[i] = (char *) calloc(strlen(argv[i])+1, sizeof(char));

        strcpy(new_argv[i], argv[i]); 
        printf("Valeur de new_argv[%d] : %s\n", i,  new_argv[i]);
    }
}

