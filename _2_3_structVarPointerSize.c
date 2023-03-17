#include <stdio.h>
struct person
{
     char name[20];
int *age; };
int main() {
int pAge = 27;
struct person man = {"Kim", &pAge}; printf("name : %s\n", man.name); printf("age : %d\n", *(man.age)); return 0;
}