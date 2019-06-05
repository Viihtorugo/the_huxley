#include<stdio.h>

int isPrime (int n, int k)
{
	if(k == 0)
		return 0;

	if(n%k == 0)
		return 1 + isPrime(n, k-1);
	
	return isPrime(n, k-1);
}

void output (int n)
{
	if(isPrime(n, n) == 2)
	{
		printf("1\n");
	}
	else
	{
		printf("0\n");
	}
}

void input()
{
	int n;

	scanf("%d", &n);

	if(n != -1)
		output(n);
}


int main ()
{

	input();

	return 0;
}
