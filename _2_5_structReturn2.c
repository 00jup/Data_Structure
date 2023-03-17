#include <stdio.h>

typedef struct
{
  int math;
  int english;
  int korean;
} Grade;
typedef struct
{
  char name[10];
  int age;
  // int *grading;
  Grade *grading; /******************** 여기가 중요함 ********************************/
} Name;

int main()
{
  Grade grade_1 = {90, 100, 40};
  Name name_1 = {"철수", 15};
  // int *p_grade;
  // name_1.grading = p_grade;
  // *p_grade = &grade_1;
  // printf("%d %d %d", grade_1.english, grade_1.korean, grade_1.math);
  // printf("%d %d %d", p_grade->english, p_grade->korean, p_grade->math);

  name_1.grading = &grade_1;
  printf("%d %d %d\n", name_1.grading->english, name_1.grading->korean, name_1.grading->math);
  printf("%d %d %d\n", grade_1.english, grade_1.korean, grade_1.math);
}