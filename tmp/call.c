int f()
{
	return g()-1;
}

int g()
{
	return 2*h();
}

int h()
{
	return 4;
}
