#include<stdio.h>

int mdc (int a, int d)
{
	int aux;

	while(a%d != 0)
	{
		aux = d;
		d = a%d;
		a = aux;
	}

	return d;
}

int main (void)
{
	int n, i;
	scanf("%d", &n);
	
	int array[n][2];

	for(i = 0; i < n; i++)
		scanf("%d %d", &array[i][0], &array[i][1]);
			
	for(i = 0; i < n; i++)	
		printf("MDC(%d,%d) = %d\n", array[i][0], array[i][1], mdc(array[i][0], array[i][1]));

	return 0;
}
