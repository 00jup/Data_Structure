#include <stdio.h>

struct simple
{
  int Data1;
  int Data2;
};

struct simple *add_1(struct simple *st);
/// @brief //////////
/// @return 아 이게 다 simple로 같아야 가능하구나...
int main()
{

  struct simple data1 = {11, 12};
  struct simple data2;
  data2 = *(add_1(&data1));
  printf("data1.data1 : %d \n", data1.Data1);
  printf("data1.data1 : %d \n", data1.Data2);
  printf("data2.data1 : %d \n", data2.Data1);
  printf("data2.data2 : %d \n", data2.Data2);
}

struct simple *add_1(struct simple *st)
{
  st->Data1++;
  st->Data2++;

  return st;
};
