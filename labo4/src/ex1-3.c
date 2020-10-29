#include <stdio.h>
#include <string.h>

typedef struct chien 
{
   	char name[100];
    double poids;
  	int age;

} Chien;

double changerPoids(struct chien * c, double poids)
{
    double ancien_poids = c->poids;
    c->poids = poids;

    return ancien_poids;
}

void copierChien(struct chien c, struct chien * p)
{
    strcpy(p->name, c.name);
    p->poids = c.poids; 
    p->age = c.age;
}

int main(void)
{
    // Mise à jour du poids
    Chien chien1 = {"Pipi", 11.984, 5};
    printf("Nom de chien1: %s\n", chien1.name);
    printf("Poids de chien1: %.3f Kg\n", chien1.poids);
    printf("Âge de chien1 : %d\n", chien1.age);
    changerPoids(&chien1, 55);
    printf("Nouveau poids de chien1: %.3f Kg\n", chien1.poids);

    // Copie d'un chien
    Chien chien2;
    copierChien(chien1, &chien2);
    printf("Nom de chien2: %s\n", chien2.name);
    printf("Poids de chien2 : %.3f Kg\n", chien2.poids);
    printf("Âge de chien2 : %d\n", chien2.age);
}
