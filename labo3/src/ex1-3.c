#include <stdio.h>

struct rectangle 
{
    int length;
    int width;
};

struct dog
{
    char name[10];
    unsigned char age;
    unsigned char weight;
    char gender;
};

int main(void)
{
    struct dog d = {"Pipi", 6, 5, 'M'};
    d.weight = 4;

    struct rectangle r;
    printf("Longueur : %d, largeur : %d\n", r.length, r.width);
    r.length = 4;
    r.width = 8;
    printf("Longueur : %d, largeur : %d\n", r.length, r.width);
}
