#include <stdio.h>

int fatorial (int num)
{
	if (num == 0)
		return 1;

	return num * fatorial(num-1);
}

int sumFat (int n)
{
	if (n == 0)
		return 0;
	
	int fat;
	scanf("%d", &fat);
	
	if (fat % 3 == 0)
		return fatorial(fat) + sumFat(n-1);
	
	return sumFat(n-1);
}

int main ()
{
	printf("%d\n", sumFat(5));
	return 0;
}
