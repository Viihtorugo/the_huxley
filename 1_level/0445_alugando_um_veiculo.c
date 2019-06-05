#include<stdio.h>

int main (void)
{
	
	int nDays, k;

	scanf("%d %d", &nDays, &k);

	k > 100 * nDays ? printf("%.2lf\n", (nDays * 90.0) + ((k - (100.0 * nDays))*12.0) ) : printf("%.2lf\n", nDays * 90.0);

	return 0;
}
