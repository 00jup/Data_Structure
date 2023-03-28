#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct
{
  int data;
  // struct *Node link;
  struct Node *link;

} Node;

typedef struct
{
  Node *head;
  int num;
} List;

Node *getNode()
{
  Node *new = (Node *)malloc(sizeof(Node));
  new->link = NULL;

  return new;
}
List *initList()
{
  List *L = (List *)malloc(sizeof(List));
  L->head = getNode();

  return L;
}

void display(List *phead)
{
  Node *p = phead->head->link;
  while (p != NULL)
  {
    printf("%d-> ", p->data);
    p = p->link;
  }
  printf("\n");
}

void insert(List *L, int num)
{
  Node *new = getNode();
  new->data = num;

  if (L->head->link == NULL)
  {
    new->link = NULL;
    L->head->link = new;
  }
  else
  {
    new->link = L->head->link;
    // new->link = Node; 아님...
    L->head->link = new;
  }
}

void insertNode(Node **phead, Node *p, Node *newNode)
{
  if (*phead == NULL)
  {
    *phead = newNode;
    newNode->link = NULL; // 순서 상관 없나? 이건 상관없을 거 같아
  }
  else if (p == NULL)
  {
    newNode->link = *phead;
    *phead = newNode;
  }
  else
  {
    newNode->link = p->link;
    // p = newNode;
    p->link = newNode;
  }
}

int main()
{
  List *helloNode = initList();
  insert(helloNode, 3);
  insert(helloNode, 2);
  insert(helloNode, 1);
  display(helloNode);

  return 0;
}