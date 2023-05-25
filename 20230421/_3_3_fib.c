#include <stdio.h>

int fib(int n)
{
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  return (fib(n - 1) + fib(n - 2));
}

int main()
{

  int A;
  scanf("%d", &A);

  // int result;
  // result = fib(A);
  // printf("결과   %d", result);
  for (int i = 0; i < A; i++)
  {
    printf("%3d", fib(i));
  } // 이거 이해 안 됨

  printf("\n");

  // 어떤 부분이 반복되는지 아는 것이 중요하다.
}
