#include <stdio.h>

int m;

int input(int Mat[][m], int N, int M);

int main()
{
  int N, M;
  scanf("%d", &N, &M);
  int A[N][M];
  int B[N][M];
  input(A, N, M);
  input(B, N, M);
}

int input(int Mat[][m], int N, int M)
{

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      scanf("%d", Mat[i][j]);
    }
  }
}