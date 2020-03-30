#include <string.h>
#include <stdio.h>
int ok;

void fakeputs(char *x)
{
    while(*x)
	{
    		printf("%c", *x);
		x++;
	}
	printf("\n");
    ok=!strcmp(x,"wibble");
}

int g();

int main()
{
    ok=0;
    g();
    return !(ok==1);
}
