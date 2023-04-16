#include <stdio.h>

int main()

{

  // int s[10];
  // // char s[10];
  // s[0] = 'a';
  // s[1] = 'b';
  // s[2] = 'C';
  // // s[3] = '\0';

  // printf("%u \n", s);
  // printf("%u \n", s + 1);
  // printf("%u \n", s + 2);
  int s[4][4];
  // char s[10];
  s[0][0] = 'a';
  s[1][1] = 'b';
  s[2][2] = 'C';
  // s[3] = '\0';
  for (int i = 0; i < 3; i++)
    printf("%s \n", s[i]);
  // printf("%u \n", s + 1);
  // printf("%u \n", s + 2);
  int A, B;
  A = 2;
  B = 1;
  if(B){
    printf("B is true\n");
  }
  if(B!=0){
    printf("B is true\n");
  }
  if(B==1){
    printf("B is true\n");
  }
}