#include<stdio.h>

int main (void)
{
	int nDays, k;
	
	scanf("%d %d", &nDays, &k);

	printf("%.2lf\n", ((nDays * 30.0) + (k * 0.01)) * 0.9 );
	
	return 0;
}
