#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
    // srand(time(NULL));
    int random_number = rand();
    printf("%d", random_number);
}
