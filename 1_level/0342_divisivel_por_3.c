#include<stdio.h>

int divisibleByThree (int n, int i)
{
	if(i > n)
		return 0;

	if(n%i == 0)
		if(i%3 == 0)
			return 1 + divisibleByThree(n, ++i);

	return divisibleByThree(n, ++i);
}

int main ()
{
	int n;

	scanf("%d", &n);

	int count = divisibleByThree(n, 3);
	
	count != 0 ? printf("%d\n", count): printf("O numero nao possui divisores multiplos de 3!\n");

	return 0;
}
