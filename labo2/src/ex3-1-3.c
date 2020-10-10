#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char str[], int size);

bool isPalindrome(char str[], int size)
{
    char reversed_str[size];
    int i = size - 2;
    int j = 0;

    for (i, j; i>=0; i--, j++)
        reversed_str[j] = str[i];

    reversed_str[size] = '\0';
    return strcmp(reversed_str,str) == 0;
}

int main(void)
{
    char name[] = "kayak";
    int size = strlen(name)+1;
    printf("%d\n", isPalindrome(name, size));
}
