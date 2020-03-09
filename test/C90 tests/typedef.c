int f(int a){
  return 2;
}
int f(int a);

int main()
{
  return f(2);
}

/*gcc -std=c90 -pedantic -Werror typedef.c*/
