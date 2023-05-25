#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct Node
{
  element data;
  struct Node *link;
} Node;

typedef struct List
{
  Node *head;
  int num;
} List;

List *initList()
{
  List *L = (List *)malloc(sizeof(List));
  L->head = (Node *)malloc(sizeof(Node));
  L->head->link = NULL;
  L->num = 0;
  return L;
}

Node *getNode()
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = 0;
  newNode->link = NULL;
  return newNode;
}

void insert(List *L, element data)
{
  Node *newNode = getNode();
  newNode->data = data;
  newNode->link = L->head->link;
  L->head->link = newNode;
  L->num++;
}

void display(List *L)
{
  Node *p = L->head->link;
  while (p != NULL)
  {
    printf("%d ", p->data);
    p = p->link;
  }
  printf("\n");
}

int main()
{
  List *L = initList();
  insert(L, 1);
  insert(L, 2);
  insert(L, 3);
  display(L);
  return 0;
}