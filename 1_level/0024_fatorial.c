#include<stdio.h>

int inputNumbers();

int fatorial(int n)
{
	if(n < 1)
		return 1;

	return n * fatorial(n-1);
}

 
int main()
{	
	int n;
	
	scanf("%d", &n);
	
	if(n != -1)
	{
		printf("%d\n", fatorial(n));
		main();
	}

	return 0;	
}     
