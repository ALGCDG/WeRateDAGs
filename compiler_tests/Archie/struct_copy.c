struct a
{
	int a;
	int b;
};

int f()
{
	struct a alpha;
	struct a beta;
	alpha.a = 1;
	alpha.b=2;
	beta=alpha;
	alpha.b = 4;
	return beta.b;
}
