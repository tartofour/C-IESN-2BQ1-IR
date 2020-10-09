#include <stdio.h>

int main(void)
{
    int until_table = 10;
    int highest_multiplier = 10;

    for (int i=1; i<=until_table; i++)
    {
      printf("#### TABLE DE %d ####\n", i);
      for (int j=1; j<=highest_multiplier; j++)
          printf("%d x %d = %d\n", i, j, i*j);
    }
}
