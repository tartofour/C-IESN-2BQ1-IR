#include <stdio.h>

void display_chartype(char character);

void display_chartype(char character)
{
    switch(character)
    {
        // Très moche.
        case 65: case 69: case 73: case 79: case 85: case 59:
        case 97: case 101: case 105: case 111: case 117: case 121:
            printf("Voyelle\n");
            break;

        case 37: case 42: case 43: case 45: case 47:
            printf("Symbole\n");
            break;

        default :
            printf("Erreur\n");
    }
}


int main(void)
{
    display_chartype('A');
    display_chartype('+');
    display_chartype('0');
}
