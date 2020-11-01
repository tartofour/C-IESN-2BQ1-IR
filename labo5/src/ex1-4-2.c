#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * cutflush_str(char * str)
{
    int length = strlen(str) + 1;
    
    str = (char *) realloc(str, length);
    return str;
}

int main(void)
{
    char msg[] = "Bonjour";
    char * str = (char *) malloc(sizeof(char) * 200);
    strcpy(str,msg);
    str = cutflush_str(str);
    free(str);
}
