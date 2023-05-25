#include <stdio.h>

typedef struct Person
{
  char a[10];
  char c;
  char f;
  int b[4];
  double e;
  int d;
} Person;
int main()
{
  printf("%lu\n", sizeof(Person));
}