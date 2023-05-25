#include <stdio.h>
#define MAX 10
int main()
{
  int rear, front;
  rear = 0;
  front = 0;
  int A;
  printf("rear++ %d\n", rear++);
  printf("++rear %d\n", ++rear);
  printf("front++ %d\n", front++);
  printf("++front %d\n", ++front);
  A = rear++;
  printf("rear++ %d\n", A);
  A = ++rear;
  printf("++rear %d\n", A);
  A = front++;
  printf("front++ %d\n", A);
  A = ++front;
  printf("++front %d\n", A);
  int queue[MAX];
  printf("\n\n\n\n");
  for (int i = 0; i < MAX; i++)
  {
    queue[i] = i;
  }
  rear = 0;
  front = 0;
  printf("rear++ %d\n", queue[rear++]);
  printf("++rear %d\n", queue[++rear]);
  printf("front++ %d\n", queue[front++]);
  printf("++front %d\n", queue[++front]);
}