#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct QueueNode
{
  element data;
  struct QueueNode *link;
} QueueNode;

typedef struct LinkedQueueType
{
  QueueNode *front, *rear;
} LinkedQueueType;

void init(LinkedQueueType *q)
{
  q->front = q->rear = NULL;
}
int is_empty(LinkedQueueType *q)
{
  return (q->front == NULL);
}
int is_full(LinkedQueueType *q)
{
  return 0;
}
void enqueue(LinkedQueueType *q, element data)
{
  QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
  temp->data = data;
  temp->link = NULL;
  if (is_empty(q))
  {
    q->front = temp;
    q->rear = temp; // temp->link 가 아니다.
  }
  else
  {
    q->rear->link = temp;
    q->rear = temp;
  }
}
int dequeue(LinkedQueueType *q)
{
  QueueNode *temp = q->front;
  element data;
  if (is_empty(q))
  {
    fprintf(stderr, "NULL!");
    exit(1);
  }
  else
  {
    q->front = q->front->link;
    data = temp->data;
    if (q->front == NULL)
    {
      q->rear = NULL;
    }
    free(temp);
    return data;
  }
}
void print_queue(LinkedQueueType *q)
{
  QueueNode *p;
  for (p = q->front; p != NULL; p = p->link)
    printf("%d ->", p->data);
  printf("\n");
}
void search(LinkedQueueType *q, element data)
{
  QueueNode *p;
  int count = 1;
  for (p = q->front; p != NULL; p = p->link)
  {
    if (p->data == data)
    {
      printf("%d번째에 있습니다.\n", count);
      break;
    }
    count++;

    if (p->link == NULL)
      printf("없습니다.\n");
  }
}

void patience(LinkedQueueType *q)
{
  printf("heeeleleleleelelle");
  QueueNode *p; //
  // QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));

  int data;
  while (1)
  {
    for (p = q->front; p != NULL; p = p->link)
    {
      p->data = (p->data) - 10;
    }
    for (p = q->front; p != NULL; p = p->link)
    {
      if (q->front < 0)
      {
        dequeue(q);
      }
    }
    if (is_empty(q))
    {
      printf("stop\n");
      break;
    }
  }
}
// int search(LinkedQueueType *q, element data)
// {
//   QueueNode *p;
//   int count = 1;
//   for (p = q->front; p != NULL; p = p->link)
//   {
//     if (p->data == data)
//       return count;
//     count++;
//   }
// }
int main()
{
  LinkedQueueType *newNode;
  element data;
  int index;
  init(newNode);

  enqueue(newNode, 25);
  print_queue(newNode);
  enqueue(newNode, 5);
  print_queue(newNode);
  enqueue(newNode, 20);
  print_queue(newNode);
  enqueue(newNode, 45);
  print_queue(newNode);
  enqueue(newNode, 15);
  print_queue(newNode);
  enqueue(newNode, 55);
  print_queue(newNode);
  printf("h");
  // printf("찾고 싶은 데이터\n");
  // scanf("%d", &data);
  // search(newNode, data);
  printf("heeeleleleleelelle");
  // int size = get_size(newNode);
  patience(newNode);

  // dequeue(newNode);
  // print_queue(newNode);
  // dequeue(newNode);
  // print_queue(newNode);
  // dequeue(newNode);
  // print_queue(newNode);

  return 0;
}