#include <stdio.h>

int main()
{
  int A, B, C;
  A = 5;
  printf("%d %d %d\n", A, B, C);
  B = C = A;
  printf("%d %d %d\n", A, B, C);
}