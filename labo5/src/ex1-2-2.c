#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char msg[] = "Bonjour";
    char * new_msg = (char *) malloc(strlen(msg) * sizeof(char));
    strcpy(new_msg, msg);

    printf("%s\n", new_msg);
    free(new_msg);
    printf("%s\n", new_msg);
}
