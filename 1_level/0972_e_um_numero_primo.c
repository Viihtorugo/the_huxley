#include<stdio.h>

int isPrime (int n, int k)
{
	if(k == 0)
		return 0;

	if(n%k == 0)
		return 1 + isPrime(n, k-1);
	
	return isPrime(n, k-1);
}


int main ()
{

	int n;

	scanf("%d", &n);

	if(n == -1)
	{
		return 0;
	}
	else
	{
		if(isPrime(n, n) == 2)
		{
			printf("1\n");
		}
		else
		{
			printf("0\n");
		}

		main();
	}
}
