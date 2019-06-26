#include <stdio.h>

long int fat (int n)
{
	if(n <= 1)
		return 1;

	return n * fat(n-1);
}

int logN (int n)
{
	if(n <= 2)
		return 0;
	
	return 1 + logN(n/3);
}

int main()
{
	int n;
	
	scanf("%d", &n);
	printf("%li\n", fat(logN(n)));

	return 0;
}
