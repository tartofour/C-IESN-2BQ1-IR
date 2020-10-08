#include <stdio.h>

int main(void)
{
    int nb_max_table = 10, highest_multiplier = 10;

    for (int i=1; i<=nb_max_table; i++)
    {
      printf("#### TABLE DE %d ####\n", i);

      for (int j=1; j<=highest_multiplier; j++)
      {
          printf("%d x %d = %d\n", i, j, i*j);
      }
    }

}
