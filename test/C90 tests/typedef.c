#include "stdio.h"
void f(int a, int b){
  printf("%p\n",(void*)&a);
  printf("%p\n",(void*)&b);
}

int main()
{
  int a;
  printf("%p\n",(void*)&a);
  f(1,1);

}



/*gcc -std=c90 -pedantic -Werror typedef.c*/
