#include <stdio.h>

int is_prime (int n, int i)
{
	if( (n%2 == 0 && n != 2) || i == 1)
		return 1;
	
	if(n%i == 0)
		return 1 + is_prime(n, --i);
	
	return is_prime(n, --i);
}

int next_prime (int n)
{
	if(n == 1)
		return 1;
	
	if(is_prime(n, n) == 2)
		return n;
	
	return next_prime(++n);
}

int fat (int n)
{
	if(n == 1)
        	return 1;
	
	return n * fat(n-1);
}

double loop (int n, int i, int prime)
{
	if(prime < i)
        	prime = next_prime(i);
	
	if(i == n)
    	{
        	printf("%d!/%d", i, prime);
		return (double) fat(i)/prime;
    	}

    	printf("%d!/%d + ", i, prime);
    	return (double) fat(i)/prime + loop(n, ++i, prime);
}

int main ()
{
	int n;
	
	scanf("%d", &n);
	
	if(n == 0)
	{
		printf("0.00\n");
	}
	else
	{
		printf("\n%.2lf\n", loop(n, 1, 1));
	}

	return 0;
}

