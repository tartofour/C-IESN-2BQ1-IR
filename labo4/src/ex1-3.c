#include <stdio.h>

typedef struct chien 
{
  	int age;
   	double poids;
} Chien;

double changerPoids(struct chien * c, double poids)
{
    double ancien_poids = c->poids;
    c->poids = poids;

    return ancien_poids;
}

void copierChien(struct chien c, struct chien * p)
{
    p->age = c.age;
    p->poids = c.poids; 
}

int main(void)
{
    // Mise à jour du poids
    Chien chien1 = {5, 11.984};
    printf("Âge de chien1 : %d\n", chien1.age);
    printf("Poids de chien1: %.3f Kg\n", chien1.poids);
    changerPoids(&chien1, 55);
    printf("Nouveau poids de chien1: %.3f Kg\n", chien1.poids);

    // Copie d'un chien
    Chien chien2;
    copierChien(chien1, &chien2);
    printf("Âge de chien2 : %d\n", chien2.age);
    printf("Poids de chien2 : %.3f Kg\n", chien2.poids);
}
