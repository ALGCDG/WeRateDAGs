char (*(*x)(int))(int);
int main()
{
  return 2;
}


/*gcc -std=c90 -pedantic -Werror typedef.c*/
