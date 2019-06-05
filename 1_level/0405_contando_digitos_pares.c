#include<stdio.h>

int countingPairs(int n)
{
	if(n == 0)
		return 0;

	int unity = n%10;

	if(unity%2 == 0)
		return countingPairs(n/10) + 1;
	
	return countingPairs(n/10);
}

int main()
{
	int n;
	
	scanf("%d", &n);
	printf("%d\n", countingPairs(n));

	return 0;
}
