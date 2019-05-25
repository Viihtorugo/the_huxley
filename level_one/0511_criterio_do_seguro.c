#include<stdio.h>

short criterion (int n1, int n2)
{
	if(n1 == 0)
		if(n2 == 1)
			return 1;

	return 0;
}

int main (void)
{
	int n1, n2;
	
	scanf("%d %d", &n1, &n2);
	
	printf("%d\n", criterion(n1, n2));
	
	return 0;
}
