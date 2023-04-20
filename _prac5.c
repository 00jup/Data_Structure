#include <stdio.h>
void show_arr(int *(ptr)[4], int a);

int main()
{
  int arr1[2][4] = {1, 2, 3, 4, 5, 6, 7, 8};
  int arr2[3][4] = {{10}, {20}, {30}};
  show_arr(arr1, 2);
  show_arr(arr2, 3);
  return 0;
}
void show_arr(int *(ptr)[4], int a)
{
  int i, j;
  printf("----Start Print----\n");
  for (i = 0; i < a; i++)
  {
    for (j = 0; j < 4; j++)
      printf("%d ", ptr[i][j]);
    printf("\n");
  }
}