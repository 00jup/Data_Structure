#include <stdio.h>
#include <stdlib.h>

typedef struct Data
{
  int Data1;
  int Data2;
} A_data;

A_data *add1(A_data *st);

int main()
{

  A_data *data1 = (A_data *)malloc(sizeof(A_data));
  data1->Data1 = 11;
  data1->Data2 = 12;
  A_data *data2;
  data2 = (add1(data1));
  printf("%d %d", data2->Data1, data2->Data2);
}

A_data *add1(A_data *st)
{
  st->Data1++;
  st->Data2++;

  return st;
};
