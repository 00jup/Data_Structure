#include <stdio.h>
#include <stdlib.h>
// 비교 함수 (오름차순으로 정렬하기 위해 작성한 예시)
int compare(const void *a, const void *b)
{
  double num1 = *(double *)a;
  double num2 = *(double *)b;
  if (num1 < num2)
    return -1;
  else if (num1 > num2)
    return 1;
  else
    return 0;
}
int main()
{
  double arr[] = {2.1, 0.9, 1.6, 3.8, 1.2, 4.4, 6.2, 9.1, 7.7}; // 퀵 정렬 함수 qsort() 사용
  qsort(arr, sizeof(arr) / sizeof(double), sizeof(double), compare);
  // 정렬 결과 출력
  for (int i = 0; i < sizeof(arr) / sizeof(double); i++)
  {
    printf("%4.1f ", arr[i]);
  }
  return 0;
}