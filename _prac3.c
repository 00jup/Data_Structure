#include <stdio.h>
#include <stdlib.h>

int main()
{
  int A;
  // int *p = &A;
  int *p = NULL;
  p = 100;
  printf("%d", *p);
}