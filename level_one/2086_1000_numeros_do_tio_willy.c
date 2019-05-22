#include<stdio.h>
#include <stdlib.h>

int main (void)
{
	int k = 1;	
	int *array = (int *) malloc (1001 * sizeof(int));
	
	while(1)
	{
		int i;
	
		for(i = (1001 - (1001*k)); i < (1001 * k); i++)
			scanf("%d", &array[i]);

		if(array[(1001 * k)] == -1)
			break;

		printf("%d\n", array[(1001 * k)]);		

		k++;
		array = (int *) realloc (array, (1001 * k) * sizeof(int));
	}
	
	int i, count = 0;
		
	for(i = 0; i < 1001*k; i++)
		count++;
	
	printf("%d\n", count);	

	return 0;
}
