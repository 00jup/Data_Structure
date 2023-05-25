#include <stdio.h>
#include <stdlib.h>
int main()
{
  int row, col;
  printf("row col 입력");
  scanf("%d %d", &row, &col);
  int *arr = (int *)malloc(row * col * sizeof(int));
  int i, j;
  for (i = 0; i < row; i++)
    for (j = 0; j < col; j++)
      *(arr + i * col + j) = i + j;
  printf("The matrix elements are:\n");
  for (i = 0; i < row; i++)
  {
    for (j = 0; j < col; j++)
    {
      printf("%4d ", *(arr + i * col + j));
    }
    printf("\n");
  }
  free(arr);
  return 0;
}
