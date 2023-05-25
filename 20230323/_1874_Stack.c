#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100000 // https://organize-study.tistory.com/60
typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

int is_empty()
{
  return (top == -1);
}

int is_full()
{
  return (top == MAX_STACK_SIZE - 1);
}

void push(element item)
{
  if (is_full())
  {
    fprintf(stderr, "stack full error\n");
    exit(1);
  }
  else
    stack[++top] = item;
}

element pop()
{
  if (is_empty())
  {
    fprintf(stderr, "stack empty error\n");
    exit(1);
  }
  else
    return stack[top--];
}

element peek()
{
  if (is_empty())
  {
    fprintf(stderr, "stack empty error\n");
    exit(1);
  }
  else
    return stack[top];
}

int main()
{
  int totalNum;
  scanf("%d", &totalNum);
  int *arr = (int *)malloc(sizeof(int) * totalNum);
  // int numArr[totalNum];
  while (1)
  {

    scanf("%d", &arr[]);
  }
  int signArr[totalNum];

  free(arr);
  return 0;
}