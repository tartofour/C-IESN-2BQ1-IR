#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * copy_str(char * str)
{
    int size = strlen(str);
    char * ptr = (char *) malloc(size+1);
    strcpy(ptr, str);
    return ptr;
}

int main(void)
{
    char msg[] = "Bonjour";
    char * new_msg = copy_str(msg);

    printf("%s\n", new_msg);
}
