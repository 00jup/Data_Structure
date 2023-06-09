#include <stdio.h>
#include <stdlib.h>

// 학생의 데이터를 담는 구조체를 새로운 타입 element로 정의
typedef struct student
{
  int num;
  char name[20];
  int kor, math, eng, com;
  // 이름은 4글자까지 가능 int kor, math, eng, com;
} element;
// 이중 연결리스트의 자기참조구조체 구현

typedef struct DListNode
{
  struct DListNode *llink; // before after해도 됨.
  element data;
  struct DListNode *rlink;
} DListNode;

// 함수 원형
void init(DListNode *phead);                                     // 처음에 노드를 초기화
DListNode *dinsert_node(DListNode *before, DListNode *new_node); // 새로운 노드를 before 노드 다음에 삽입
void search(DListNode *head, element data);                      // 학생 번호에 입력 받아 노드 탐색 후 출력
void sort_dinsert(DListNode *head);                              // 이중 연결리스트를 정렬
void display(DListNode *phead);                                  // 연결 리스트 전체 출력
void free_node(DListNode *phead);
// 초기화가 먼저나오고 함수 구조를 설계한다.
//  동적 할당된 메모리 반환
void init(DListNode *phead)
{ // printf("[Init Doubly List]\n");
  phead->llink = phead;
  phead->rlink = phead;
}

DListNode *dinsert_node(DListNode *before, DListNode *new_node)
{ // before -> aaa => before -> new_node -> aaa
  // new_node의 링크 필드 먼저 생성
  new_node->llink = before;
  new_node->rlink = before->rlink;
  before->rlink->llink = new_node; // aaa의 llink에는 new_node 주소를 저장

  before->rlink = new_node;
  // before의 rlink에는 new_node 주소를 저장
  // printf("\n\n new_node 성공적\n\n");
}

void search(DListNode *head, element data)
{
  DListNode *p;
  for (p = head->rlink; p != head; p = p->rlink)
  {
    if (p->data.num == data.num)
    {
      printf("%6d %10s %6d %6d %6d %6d\n",
             p->data.num, p->data.name, p->data.kor, p->data.math, p->data.eng, p->data.com);
      return;
    }
  }
  printf("%d 번 학생의 번호 검색 실패\n\n", data.num);
}
void display(DListNode *phead)
{
  printf("=====================================================\n");
  printf("|번 호| 이 름 | 언어 | 수리 | 영어 |컴퓨터|\n");
  printf("=====================================================\n");
  for (DListNode *p = phead->rlink; p != phead; p = p->rlink)
  {
    printf("|%3d | %5s | %4d | %4d | %4d | %5d |\n",
           p->data.num, p->data.name, p->data.kor, p->data.math, p->data.eng, p->data.com);
    printf("=====================================================\n");
  }
}
void free_node(DListNode *phead)
{
  DListNode *p = phead->rlink, *next;
  while (p != phead)
  {
    next = p;
    free(p);
    p = p->rlink;
  }
}

int main()
{
  FILE *fp;
  DListNode *head = (DListNode *)malloc(sizeof(DListNode)); // 헤드 노드 생성(데이터 필드는 empty)
  DListNode *tmp;                                           // 임시로 데이터를 입력받는 노드
  element dat;                                              // 데이터 임시로 입력 받는 구조체
  int flag;                                                 // 입력받는 메뉴
  // 연결 리스트 초기화
  init(head);
  // 파일 열기
  fp = fopen("data.txt", "rt");
  if (fp == NULL)
  {
    printf("File not found\n");
    return 0;
  }
  // 파일로부터 데이터 입력 받아 tmp 노드에 저장후 노드 삽입
  while (!feof(fp))
  {
    fscanf(fp, "%d %s %d %d %d %d",
           &dat.num, dat.name, &dat.kor, &dat.math, &dat.eng, &dat.com);
    printf("%6d %10s %6d %6d %6d %6d\n",
           dat.num, dat.name, dat.kor, dat.math, dat.eng, dat.com);
    tmp->data = dat;
    tmp = (DListNode *)malloc(sizeof(DListNode)); // create_node 함수 구현 대신 파일 내에서 생성
    dinsert_node(head, tmp);                      // head에 새로 만든 tmp를 insert
  }
  while (1)
  {
    printf("\n종료(0) 학생 데이터 입력(1) 학생 검색(2) 목록 보기(3)\n");
    printf("메뉴 입력 : ");
    scanf("%d", &flag);
    switch (flag)
    {
    case 0: // 0인 경우 종료
      exit(1);
      break;
    case 1: // 데이터 입력 받아 새로운 노드 추가 후 삽입
            /////////띄어쓰기 해줘야 함.
      tmp = (DListNode *)malloc(sizeof(DListNode));
      printf("추가할 학생 번호: ");
      scanf("%d", &dat.num);
      printf("이름 : ");
      scanf("%s", dat.name);
      printf("국어 : ");
      scanf("%d", &dat.kor);
      printf("수학 : ");
      scanf("%d", &dat.math);
      printf("영어 : ");
      scanf("%d", &dat.eng);
      printf("컴퓨터 : ");
      scanf("%d", &dat.com);
      tmp->data = dat; // 새로운 노드의 데이터 필드에 입력 받은 dat구조체를 대입 dinsert_node(head, tmp); // 노드 맨 앞에 삽입
      break;
    case 2: // 학생 번호 입력 받아 리스트에서 탐색 후 출력
      printf("검색할 학생 번호 : ");
      scanf("%d", &dat.num);
      search(head, dat);  // 학생 번호 찾아 출력 break;
    case 3:               // 리스트를 정렬하여 출력 printf("\n<정렬된 목록 보기>\n\n");
      sort_dinsert(head); // 목록을 학생 번호 순대로 정렬 display(head); // 출력
      break;
    default:
      break;
    }
  }
  free_node(head);
  fclose(fp);
  return 0;
}