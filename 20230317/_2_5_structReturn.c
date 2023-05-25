#include <stdio.h>
struct simple
{
  int data1;
  int data2;
};
struct simple *add_1(struct simple *st);
int main()
{
  struct simple s1 = {1, 2};
  struct simple s2;
  s2 = *(add_1(&s1));
  printf("s1.data1 : %d\n", s1.data1);
  printf("s1.data2 : %d\n", s1.data2);
  printf("s2.data1 : %d\n", s2.data1);
  printf("s2.data2 : %d\n", s2.data2);
  return 0;
}
struct simple *add_1(struct simple *st)
{
  st->data1++;
  st->data2++;
  return st;
}