#include <stdio.h>
int main()
{
  int tarr[2][3];

  printf("2차원 배열 입력\n");
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      printf("tarr[%d][%d] 입력 : ", i, j);
      scanf("%d", &tarr[i][j]);
    }
  }

  printf("\n2차원 배열 출력\n");
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      printf("\t%d", tarr[i][j]);
    }
    printf("\n");
  }

  return 0;
}