#include <stdio.h>
#include <math.h>

# define TAB_SIZE 4

// Absolument dégeulasse

void display_bin_to_dec(int binary_number[]);

void display_bin_to_dec(int binary_number[])
{
    int result = 0;
    int exponent = TAB_SIZE - 1;

    for (int i=0; i<TAB_SIZE; i++)
    {
        result = result + binary_number[i] * pow(2,exponent);
        exponent = exponent - 1;
    }
    printf("%d\n", result);
}

int main(void)
{
    int binary_number[TAB_SIZE] = {1,1,1,1};
    display_bin_to_dec(binary_number);
}
