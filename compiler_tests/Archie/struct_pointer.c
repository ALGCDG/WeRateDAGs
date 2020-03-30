struct a {int a; int b; int c};

int f()
{
    struct a b;
    struct a * c;
    struct a * d;
    c=&b;
    c++;
    return !((c-d)==8) ;
}