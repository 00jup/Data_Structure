#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int element;
typedef struct Node
{
  struct Node *link;
  element item;
} Node;
typedef struct
{
  Node *top;
} Stack;

void init(Stack *s)
{
  s->top = NULL;
}
int is_empty(Stack *s)
{
  return (s->top == NULL);
}
void push(Stack *s, element item)
{
  Node *temp = (Node *)malloc(sizeof(Node));
  if (temp == NULL)
  {
    fprintf(stderr, "메모리할당에러\n");
    return;
  }
  else
  {
    temp->item = item;
    temp->link = s->top;
    s->top = temp;
  }
}
element pop(Stack *s)
{
  if (is_empty(s))
  {
    return -1;
  }
  else
  {
    Node *temp = s->top;
    element item = temp->item;
    s->top = s->top->link;
    free(temp); // 이렇게 해도 되는 구나..
    return item;
  }
}
element peek(Stack *s)
{
  if (is_empty(s))
  {
    fprintf(stderr, "스택이 비어있음\n");
    exit(1);
  }
  else
  {
    return s->top->item;
  }
}

void print_stack(Stack *s)
{
  for (Node *p = s->top; p != NULL; p = p->link)
    printf("%d\n", p->item);
}
int size(Stack *s)
{

  int size = 0;
  for (Node *p = s->top; p != NULL; p = p->link) // 여기서 p->link랑 p != NULL
  {
    size++;
  }
  return size;
}
int main()
{
  int N, num;
  scanf("%d", &N);
  Stack *s = (Stack *)malloc(sizeof(Stack));
  printf("%p", s->top);
  // init(s); // 왜 초기화 안 해도 되지?

  char *cmd = (char *)malloc(sizeof(char) * N);
  char *result = (char *)malloc(sizeof(char) * N);

  for (int i = 0; i < N; i++)
  {
    scanf("%s", cmd + i);
    if (strcmp(cmd + i, "push") == 0)
    {
      scanf("%d", &num);
      push(s, num);
      i--;
      N--;
    }
    else if (strcmp(cmd + i, "top") == 0)
    {
      if (is_empty(s))
        printf("-1\n");
      else
        printf("%d\n", s->top->item);
    }
    else if (strcmp(cmd + i, "size") == 0)
    {
      printf("%d\n", size(s));
    }
    else if (strcmp(cmd + i, "empty") == 0)
    {
      if (is_empty(s))
        printf("1\n");
      else
        printf("0\n");
    }
    else if (strcmp(cmd + i, "pop") == 0)
    {
      printf("%d\n", pop(s));
    }
  }

  free(s);
  return 0;
}

/// 제한이 없는 건가??