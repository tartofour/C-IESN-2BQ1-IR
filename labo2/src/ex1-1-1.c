#include <stdio.h>
#include <math.h>

int main(void)
{
    double a = 112.2134;

    if (a > 0)
        printf("%.2f\n", pow(a, 0.5));
    else
        printf("Erreur ! Le nombre entré est négatif");
}
