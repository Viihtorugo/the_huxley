#include<stdio.h>

int isPerfect(int *array, int n, int e)
{
	int j, i;

	for(j = 0; j < n; j++)
		for(i = j + 1; i < n; i++)
			if(array[j] + array[i] == e)
				return 1;

	return 0;
}

int main (void)
{
	int n, e;
	
	scanf("%d %d", &n, &e);
	
	int array[n], i, j;

	for(i = 0; i < n; i++)
		scanf("%d", &array[i]);
		
	isPerfect(array, n, e) ? printf("SIM\n") : printf("NAO\n");

	return 0;
}
