#include <stdio.h>

struct simple
{
  int data1;
  int data2;
};

int main()
{
  struct simple s1 = {1, 2};
  struct simple s2;
  s2 = s1; // 대입 연산 시 양쪽의 구조체는 같은 자료형이어야 한다. printf("s2.data1 : %d\n", s2.data1);
  printf("s1.data2 : %d\n", s1.data2);
  printf("s2.data2 : %d\n", s2.data2);
  return 0;
}