#include <stdio.h>

int add(int a, int b)
{
  return a + b;
}

int q(int (*get)(int))
{
  return get;
}

int main()
{
  printf("%d\n", q(add(10, 20)));

  return 0;
}