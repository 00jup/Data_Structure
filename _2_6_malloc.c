#include <stdio.h>
#include <stdlib.h>
void main()
{
  int *arr;
  arr = (int *)malloc(sizeof(int) * 4); // size 4 동적할당
  arr[0] = 100;
  arr[1] = 200;
  arr[2] = 300;
  arr[3] = 400;
  for (int i = 0; i < 4; i++)
  {
    printf("arr[%d] : %d\n", i, arr[i]);
  }
  // Valid. Size of the array is taken as the number of elements
  // in the initializer list (5)
  // int arr[] = {1, 2, 3, 4, 5};

  // // Also valid. But here, size of a is 3
  // int a[] = {1, 2, 3};
  free(arr); // 동적할당 해제
}