#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int coef;
  int expon;
  struct Node *link;
} Node;

typedef struct Header
{
  int length;
  Node *head;
  Node *tail;
} Header;

void *init()
{
  Header *plist = (Header *)malloc(sizeof(Header));
  plist->length = 0;
  plist->head = plist->tail = NULL;
  return plist;
}

void insert_node_last(Header *plist, int coef, int expon)
{
  Node *temp = (Node *)malloc(sizeof(Node));
  if (temp == NULL)
    printf(stderr, "메모리 할당 에러");
  temp->coef = coef;
  temp->expon = expon;
  temp->link = NULL;
  if (plist->tail == NULL)
  {
    plist->head = plist->tail = temp;
  }
  else
  {
    plist->tail->link = temp;
    plist->tail = temp;
  }
  plist->length++;
}

void poly_add(Header *plist1, Header *plist2, Header *plist3)
{
  Node *a = plist1->head;
  Node *b = plist2->head;
  int sum;
  while (a && b)
  {
    if (a->expon == b->expon)
    {
      sum = a->coef + b->coef;
      if (sum != 0)
        insert_node_last(plist3, sum, a->expon);
      a = a->link;
      b = b->link;
    }
    else if (a->expon > b->expon)
    {
      insert_node_last(plist3, a->coef, a->expon);
      a = a->link;
    }
    else
    {
      insert_node_last(plist3, b->coef, b->expon);
      b = b->link;
    }
  }
  for (; a != NULL; a = a->link)
    insert_node_last(plist3, a->coef, a->expon);
  for (; b != NULL; b = b->link)
    insert_node_last(plist3, b->coef, b->expon);
}

void poly_print(Header *plist)
{
  Node *p = plist->head;

  printf("polynomial = ");
  for (; p; p = p->link)
  {
    printf("%d^%d + ", p->coef, p->expon);
  }
  printf("\n");
}

int main()
{
  Header *list1, *list2, *list3;
  list1 = init();
  list2 = init();
  list3 = init();

  insert_node_last(list1, 3, 12);
  insert_node_last(list1, 2, 8);
  insert_node_last(list1, 1, 0);

  insert_node_last(list2, 8, 12);
  insert_node_last(list2, -3, 10);
  insert_node_last(list2, 10, 6);
  poly_print(list1);
  poly_print(list2);

  poly_add(list1, list2, list3);
  poly_print(list3);
}