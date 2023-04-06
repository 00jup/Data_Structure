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
    printf("-1\n");
    exit(1);
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
  for (Node *p = s->top; p != NULL; p = p->link)
  {
    size++;
  }
  return size;
}

// 중위 표기 수식->후위 표기 수식
void infix_to_postfix(char exp[])
{
  int i = 0;
  char ch, top_op;
  int len = strlen(exp);
  Stack s;
  init(&s); // 스택 초기화
  for (i = 0; i < len; i++)
  {
    ch = exp[i];
    // 연산자이면
    switch (ch)
    {
    case '+':
    case '-':
    case '*':
    case '/': // 연산자
      // 스택에 있는 연산자의 우선순위가 더 크거나 같으면 출력
      while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
        printf("%c", pop(&s));
      push(&s, ch);
      break;
    case '(': // 왼쪽 괄호
      push(&s, ch);
      break;
    case ')': // 오른쪽 괄호 top_op = pop(&s);
      // 왼쪽 괄호를 만날때까지 출력
      while (top_op != '(')
      {
        printf("%c", top_op);
        top_op = pop(&s);
      }
      break;
    default: // 피연산자
      printf("%c", ch);
      break;
    }
  }
  while (!is_empty(&s)) // 스택에 저장된 연산자들 출력
    printf("%c", pop(&s));
}

int main()
{
  infix_to_postfix("(2+3)*4+9");
  return 0;
}

/// 제한이 없는 건가??