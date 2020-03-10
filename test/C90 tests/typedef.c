

int main()
{
  int a = 2;
  do{
    int i = a--;
  }while(i>0);
}

/*gcc -std=c90 -pedantic -Werror typedef.c*/
