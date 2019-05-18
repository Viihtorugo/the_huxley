#include<stdio.h>

int loop(int n)
{
	if(n == 100)
	{
		return 0;
	}
	else
	{
		printf("%d\n", n);
		loop(++n);
	}
}

int main(void)
{
	return loop(0);
}

