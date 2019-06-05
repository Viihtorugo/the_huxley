#include<stdio.h>

int inputNumbers();

int fatorial(int n)
{
	if(n < 1)
		return inputNumbers();

	return n * fatorial(n-1);
}

int inputNumbers()
{
	int n;
	
	scanf("%d", &n);
	
	if(n == -1)
		return 1;	

	printf("%d\n", fatorial(n));
}
 
int main()
{	
	return inputNumbers();
}     
