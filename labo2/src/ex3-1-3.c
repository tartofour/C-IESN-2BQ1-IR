#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char str[], int size);

bool isPalindrome(char str[], int size)
{
    char reversed_str[size];
    int i = 0;
    int j = size - 2;

    for (i, j; j>=0; i++, j--)
        reversed_str[i] = str[j];

    reversed_str[size] = '\0';
    return strcmp(reversed_str,str) == 0;
}

int main(void)
{
    char name[] = "kayak";
    int size = strlen(name)+1;
    printf("%d\n", isPalindrome(name, size));
}
