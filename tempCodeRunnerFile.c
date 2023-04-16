#include <stdio.h>

#define MAX_DEGREE 101
struct
{
  int expon;
  float coef;
} terms[MAX_DEGREE] = {{8, 3}, {7, 1}, {5, 0}, {2, 3}, {10, 2}, {0, 1}};
int avail = 6;
char compare(int i, int j)
{
  if (i > j)
    return '>';
  else if (i == j)
    return '=';
  else
    return '<';
}

void attach(float coefficient, int exponent)
{
  if (avail > MAX_DEGREE)
  {
    fprintf(stderr, "Too many terms in the polynomial\n");
  }
  terms[avail].coef = coefficient;
  terms[avail++].expon = exponent;
}
poly_add2(int As, int Ae, int Bs, int Be, int *Cs, int *Ce)
{
  float coefficient;
  *Cs = avail;
  while (As <= Ae && Bs <= Be)
    switch (compare(terms[As].expon, terms[Bs].expon))
    {
    case '>':
      attach(terms[As].coef, terms[As].expon);
      As++;
      break;
    case '=':
      coefficient = terms[As].coef + terms[Bs].coef;
      if (coefficient)
        attach(coefficient, terms[As].expon);
      As++;
      Bs++;
      break;
    case '<':
      attach(terms[Bs].coef, terms[Bs].expon);
      Bs++;
      break;
    }
  for (; As <= Ae; As++)
    attach(terms[As].coef, terms[As].expon);
  for (; Bs <= Be; Bs++)
    attach(terms[Bs].coef, terms[Bs].expon);
  *Ce = avail - 1;
}
int main()
{
  int As = 0, Ae = 2, Bs = 3, Be = 5, Cs, Ce;
  poly_add2(As, Ae, Bs, Be, &Cs, &Ce);
  for (int i = Cs; i >= Ce; i--)
    printf("%.2fx^%d + ", terms[i].coef, terms[i].expon);
  printf("\b\b  ");
}