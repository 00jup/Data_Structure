#include <stdio.h>

struct a_struct
{
  char a[10];
  char c;
  char f;
  int d;
  int b[4];
  double e;
};

int main()
{
  struct a_struct a;

  printf("%d\n", sizeof(a));
  int b[10][20];

  printf("%d\n", sizeof(b));
  float c[100];
  printf("%u\n", c);
  printf("%u\n", c + 10 );
}