#include <stdio.h>

typedef struct Data
{
  int Data1;
  int Data2;
} A_data;

struct calcul *add1(A_data *st);

int main()
{

  A_data data1 = {11, 12};
  A_data data2;
  data2 = *(add1(&data1));
}

struct calcul *add1(A_data *st)
{
  st->Data1++;
  st->Data2++;

  return st;
};
