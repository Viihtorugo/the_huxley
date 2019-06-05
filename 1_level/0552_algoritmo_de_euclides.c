#include<stdio.h>

int mdc (int a, int d)
{
	if(a%d != 0)
		return mdc(d, a%d);

	return d;
}

int input (int n)
{
	if(n == 0)
		return 0;

	int n1, n2;
	
	scanf("%d %d", &n1, &n2);
	printf("MDC(%d,%d) = %d\n", n1, n2, mdc(n1, n2));
	
	return input(--n);
}

int main (void)
{
	int n;

	scanf("%d", &n);

	return input(n);
}
