#include <stdio.h>

int countMul(int n, int i)
{
	if(i == n)
		return 0;
	
	if(n % i == 0)
		return i + countMul(n, i+1);
	
	return countMul(n, i+1);
}

int loop(int n1, int n2)
{
	if(n1 > n2)
		return 0;

	int sum = countMul(n1, 1);

	if(sum >= n1 && sum <= n2)
	{
		printf("%d e amigo de %d\n", n1, sum);
		return 1 + loop(n1+1, n2);
	}
	
	return loop(n1+1, n2);
}

int main ()
{
	int n1, n2;

	scanf("%d %d", &n1, &n2);	
	
	if(!loop(n1, n2))
		printf("Nao existem numeros amigos\n");

	return 0;
}
