#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int i = 2; 
    int random_number = rand();
    int is_divider_found = 0;
    
    while (!is_divider_found && i<=(int) sqrt(random_number)+1)
    {
        if (random_number % i == 0)
        {
            printf("Le plus petit diviseur de %d est %d\n", random_number, i);
            is_divider_found = 1;
        }    
        i++;
    }

    if (!is_divider_found)
    {
        printf("This is a prime number !\n");
    }
}
