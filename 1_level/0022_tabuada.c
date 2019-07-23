#include<stdio.h>

void print_tabuada (int i, int n)
{
	if (i < 10)
	{
		printf("%d x %d = %d\n", n, i, n*i);
		print_tabuada(i + 1, n);
	}
}

int main(void)
{
	int n;
	
	scanf("%d", &n);
	print_tabuada(1, n);
	
	return 0;
}
