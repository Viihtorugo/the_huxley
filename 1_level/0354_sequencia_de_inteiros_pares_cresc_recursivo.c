#include <stdio.h>

void printPairs (int n, int i)
{
	if (i <= n)
	{
		printf("%d\n", i);
		
		printPairs(n, i+2);
	}
}

int main (void)
{
	int n;
	
	scanf("%d", &n);
	printPairs(n, 0);
	
	return 0;
}
