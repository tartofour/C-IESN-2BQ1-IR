#include <stdio.h>
#include <math.h>

double pow(double, double);

int afficherResultat(double (*pF)(double, double), double a, double b)
{
    double resultat = (*pF)(a, b);
    printf("%f\n", resultat);
}

int main(void)
{
    double (*pPow)(double, double) = &pow;
    afficherResultat(pPow, 3, 3);
}
