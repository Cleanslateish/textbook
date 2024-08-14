#include <stdio.h>




int main(){

  int a;
  int *p;
  a = 10;
  p = &a;
  *p = 12; //value at address p is set to 12; (dereferencing)

  printf("a = %d\n", a);

//  printf("%p\n", p);
//  printf("%d\n", *p);
//  printf("%p\n", &a);
  return 0;
}
