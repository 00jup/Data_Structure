#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct person
{
  char name[20];
  int *age;
} Person;

int main()
{
  int pAge = 27;
  // struct person man = {"Kim", &pAge};
  Person *man = (Person *)malloc(sizeof(Person));
  strcpy(man->name, "KIM");
  man->age = &pAge;

  printf("name : %s\n", man->name);
  printf("age : %d\n", *(man->age));
  return 0;
}


// structure사이즈
// 동적메모리 할당과 관련이 있다. 메모리를 낭비하지 않을 수 있다 구조체 자체를 전달하는 것보다 포인터를 전달하는 것이 효과적이다.,
// 메모리 끼리의 복