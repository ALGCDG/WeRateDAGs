struct a { int a; int b; }

int f()
{
	struct a b;
	b.a=1;
	b.b=4;
	struct a * c = &b;
	return c->b;
}
