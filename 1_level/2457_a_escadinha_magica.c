#include <stdio.h>

void iteration (int n, int i)
{
	if(i > n)
		return;
	
	if(i == 1)
	{
		printf("%d", i);
	}
	else
	{
		printf(" %d", i);
	}

	iteration(n, ++i);
}

void loop(int n, int i)
{	
	if(i > n)
		return;

	iteration(i, 1);
	printf("\n");

	loop(n, ++i);
}

int main ()
{
	int n;
	scanf("%d", &n);
	
	loop(n, 1);

	return 0;
}
