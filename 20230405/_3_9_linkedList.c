#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int data;
  struct Node *link;
} Node;

typedef struct
{
  int size;
  Node *head;
  Node *tail;
  //////////////////*******struct Header *tail;

} Header;

Node *getNode()
{
  Node *new = (Node *)malloc(sizeof(Node));
  new->link = NULL;

  return new;
}

Header *initList()
{
  Header *init = (Header *)malloc(sizeof(Header));
  init->size = 0;
  init->head = getNode();
  // init->head = init->tail = NULL; ///////////////////

  return init;
}

void insert(Header *plist, int num)
{
  Node *new = getNode();
  new->data = num;

  if (plist->head->link == NULL)
  {
    new->link = NULL;
    plist->head->link = new;
  }
  else
  {
    new->link = plist->head->link;
    plist->head->link = new;
  }
}
void display(Header *phead)
{
  Node *p = phead->head->link;
  //(Node *)malloc(sizeof(Node));xxxxxxxxxxx
  printf("생성된 연결 리스트\n");
  while (p != NULL)
  { ///////p->link 랑 p 랑 결과가 다르다.
    printf("%d ->", p->data);
    p = p->link;
  }
  printf("\n");
}
void sum(Header *phead)
{
  Node *p = phead->head->link;
  printf("연결 리스트의 합 : ");
  int sum = 0;
  while (p != NULL)
  {
    sum += p->data;
    p = p->link;
  }
  printf("%d\n", sum);
}
void search(Header *phead, int num)
{
  Node *p = phead->head->link;
  int total = 0;
  while (p != NULL)
  {
    if (p->data == num)
    {
      total++;
    }
    p = p->link;
  }
  printf("%d는 연결 리스트에서 %d번 나타납니다.\n", num, total);
}

int main()
{
  int A, B, count;
  Header *hello = initList();
  printf("노드 개수 : ");
  scanf("%d", &count);
  for (int i = 0; i < count; i++)
  {
    A = 0;
    printf("노드 #%d 데이터 : ", i + 1);
    scanf("%d", &A);
    insert(hello, A);
  }
  display(hello);
  sum(hello);
  printf("탐색할 값을 입력하시오 : ");
  scanf("%d", &B);
  search(hello, B);
  return 0;
}