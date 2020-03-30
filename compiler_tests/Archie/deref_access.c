struct a { int a; int b; };

int f()
{
	struct a b;
	struct a * c = &b;
	b.a=1;
	b.b=4;
	return c->b;
}
