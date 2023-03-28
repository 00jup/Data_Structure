#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct
{
  int data;
  // struct *Node link;
  struct Node *link;

} Node;

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
