int f(int x)
{
	switch(x)
	{
		case 1:
			x = 2;
			break;
		case 2:
			x = x + 1;
		default:
			x = x*2;
			
	}
	return x;
}
