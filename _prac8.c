#include <stdio.h>

typedef struct Person
{
  char a[10];
  char c;
  char f;
  int b[4];
  int d;
  double e;
} Person;
int main()
{
  printf("%lu\n", sizeof(Person));
}