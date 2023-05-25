#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100
typedef struct
{
  char data[max];
  int top;
} stackType;

int check(char *exp);
void init(stackType *s);
void push(stackType *s, int x);
int pop(stackType *s);
int is_full(stackType *s);
int is_empty(stackType *s);
int eval(const char *s);
int main()
{
  int result;
  puts("82/3-32*+ 계산하기\n");
  result = eval("942/1+-5-2*2-");
  printf("결과값은%d\n", result);
}
void init(stackType *s)
{
  s->top = -1;
}
int is_full(stackType *s)
{
  return s->top == max - 1;
}
int is_empty(stackType *s)
{
  return s->top == -1;
}
void push(stackType *s, int x)
{
  if (is_full(s))
  {
    fprintf(stderr, "원소가 다 찼습니다.\n");
    return;
  }
  s->data[++(s->top)] = x;
}
int pop(stackType *s)
{
  if (is_empty(s))
  {
    fprintf(stderr, "원소가 없습니다\n");
    exit(1);
  }
  return s->data[(s->top)--];
}
int eval(const char *s)
{
  int op1, op2, value;
  int len = strlen(s);
  char ch;
  stackType st;
  init(&st);
  for (int i = 0; i < len; i++)
  {
    ch = s[i];
    if (ch != '+' && ch != '*' && ch != '/' && ch != '-')
    {
      value = ch - '0';
      push(&st, value);
    }
    else
    {
      // op1, op2 순서 조심, op2가 최근에 넣은 피연산자임
      op2 = pop(&st);
      op1 = pop(&st);
      switch (ch)
      {
      case '+':
        push(&st, op1 + op2);
        break;
      case '-':
        push(&st, op1 - op2);
        break;
      case '*':
        push(&st, op1 * op2);
        break;
      case '/':
        push(&st, op1 / op2);
        break;
      }
    }
  }
  return pop(&st);
}
