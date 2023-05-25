#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *pointer = (int *)malloc(sizeof(int));
  *pointer = 0x12345678;
  printf("%x\n", *pointer);
  char *pointer2 = (char *)pointer;
  for (int i = 0; i < 4; i++)
  {
    printf("%x\n", *pointer2);
    pointer2++;
  }
  free(pointer);
}