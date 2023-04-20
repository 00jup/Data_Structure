#include <stdio.h>

void sub(int *p)
{
  *p = 100;
}

int main()
{
  int a = 10;
  sub(&a);
  printf("%d", a);
}