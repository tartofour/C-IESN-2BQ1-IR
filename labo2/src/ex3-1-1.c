#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void display_capitalized_string(char word[], int size);

void display_capitalized_string(char word[], int size)
{
    char capitalized_word[size];

    for (int i=0; i<size; i++)
        capitalized_word[i] = word[i] - 32;
    
    printf("%s\n", capitalized_word);
}

int main(void)
{
    char name[] = "bonjour";
    int size = strlen(name);
    display_capitalized_string(name, size);
}
