#include<stdio.h>

int isNumberTriangular(int n, int i)
{
	if(n == i || n <= 0)
		return 0;

	if(n % i == 0)
	{
		if( (i * (i+1) * (i+2)) == n)
		{
			printf("%d * %d * %d = %d\n", i, i+1, i+2, n);
			return 1;
		}
	}
	
	return isNumberTriangular(n, ++i);
}

int main()
{
	int n;
	
	scanf("%d", &n);

	if(isNumberTriangular(n, 1))
	{
		printf("Verdadeiro\n");
	}
	else
	{
		printf("Falso\n");
	}

	return 0;
}
