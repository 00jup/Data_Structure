#include <stdio.h>

typedef struct student
{
  char name[10];
  int age;
  double grade;
} STUDENT;

int main()
{

  STUDENT s1 = {"길동", 12, 4.5};
  STUDENT s2 = {"길동2", 112, 3.5};
  STUDENT s3 = {"길동2", 112, 3.5};
  for (int i = 0; i < 3; i++)
  {
    printf("%s %d %lf\n\n", s1.name, s2.age, s3.grade);
  }
  int i = 0;
  int A1, B2, j;
}