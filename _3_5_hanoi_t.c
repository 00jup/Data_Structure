#include <stdio.h>

void hanoi_t(int n, char from, char tmp, char to)
{
  if (n == 1)
    printf("...........원판 1을 %c에서 %c로 옮긴다.\n", from, to);
  else
  {
    hanoi_t(n - 1, from, to, tmp);
    printf("원판 %d를 %c에서 %c로 옮긴다.\n", n, from, to);
    hanoi_t(n - 1, tmp, from, to);
  }
}

main()
{
  hanoi_t(3, 'A', 'B', 'C');
}