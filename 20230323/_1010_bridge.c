#include <stdio.h>

int main()
{
  int T;
  scanf("%d", &T);
  int N[T], M[T];

  int sum1, sum2, sum3;
  for (int i = 0; i < T; i++)
  {
    scanf("%d %d", &N[i], &M[i]);
  }

  for (int i = 0; i < T; i++)
  {
    sum1 = 1;
    sum2 = 1;
    sum3 = 1;

    if (N[i] == M[i])
    {
      printf("1\n");
    }
    else
    {
      for (int j = 0; j < (M[i]); j++)
      {
        printf("sum1 %d sum2 %d sum3 %d\n", sum1, sum2, sum3);
        sum1 *= (M[i] - j);
        sum2 *= ((M[i] - N[i]) - j);
        sum3 *= (N[i] - j);
      }

      printf("%d \n", (sum1 / sum2 * sum3));
    }
  }
}
