#include <stdio.h>
int main(int argc, char **argv)
{
  printf("받은 인자의 개수 : %d \n", argc);
  printf("이 프로그램의 경로 : %s \n", argv[0]);

  return 0;
}