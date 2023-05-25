#include <stdio.h>
#define MAX_LIST_SIZE 100000;

typedef int element;
typedef struct
{
  int list[MAX_LIST_SIZE];
  int length;
} ArrayListType;

void init(ArrayListType *L)
{
  L->length = 0;
}

int is_empty(ArrayListType *L)
{
  return L->length == 0;
}

int is_full(ArrayListType *L)
{
  return L->length == MAX_LIST_SIZE;
}

void add(ArrayListType *L, int position, element item)
{
  if (!is_full(L) && (position >= 0) && (position <= L->length))
  {
    int i;
    for (i = (L->length - 1); i >= position; i--)
      L->list[i + 1] = L->list[i];
    L->list[position] = item;
    L->length++;
  }
}