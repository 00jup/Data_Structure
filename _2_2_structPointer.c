#include <stdio.h>
struct person
{
  char name[20];
  int age;
};
int main()
{
  struct person man = {"Kim", 27};
  struct person *pMan;
  pMan = &man;
  // 구조체 변수를 이용한 출력
  printf("name : %s\n", man.name);
  printf("age : %d\n", man.age);
  // 구조체 포인터를 이용한 출력
  printf("name : %s\n", (*pMan).name);
  printf("age : %d\n", (*pMan).age);
  return 0;
}