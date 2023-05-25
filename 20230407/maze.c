#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int x;
  int y;
  struct node *link;
} node;
int main()
{
  node *head = NULL;
  node *tail = NULL;
  node *cur = NULL;
  node *newNode = NULL;
  int readData;
  newNode = (node *)malloc(sizeof(node));
  newNode->x = 1;
  newNode->y = 1;
  newNode->link = NULL;
  head = newNode;
  tail = newNode;
  newNode = (node *)malloc(sizeof(node));
  newNode->x = 2;
  newNode->y = 2;
  newNode->link = NULL;
  tail->link = newNode;
  tail = newNode;
  newNode = (node *)malloc(sizeof(node));
  newNode->x = 3;
  newNode->y = 3;
  newNode->link = NULL;
  tail->link = newNode;
  tail = newNode;
  printf("데이터 입력 완료\n");
  if (head == NULL)
  {
    printf("저장된 데이터가 존재하지 않습니다.\n");
  }
  else
  {
    cur = head;
    printf("%d %d \n", cur->x, cur->y);
    while (cur->link != NULL)
    {
      cur = cur->link;
      printf("%d %d \n", cur->x, cur->y);
    }
  }
  printf("\n");
  if (head == NULL)
  {
    return 0;
  }
  else
  {
    node *delNode = head;
    node *delNextNode = head->link;
    printf("%d %d를 삭제합니다.\n", delNode->x, delNode->y);
    free(delNode);
    while (delNextNode != NULL)
    {
      delNode = delNextNode;
      delNextNode = delNextNode->link;
      printf("%d %d를 삭제합니다.\n", delNode->x, delNode->y);
      free(delNode);
    }
  }
  return 0;
}