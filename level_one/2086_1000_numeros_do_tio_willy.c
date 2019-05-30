#include<stdio.h>
#include <stdlib.h>

int main (void)
{
	int *array = malloc (1001 * sizeof(int));
	int k = 0, i, j;
	
	while(1)
	{
		for(i = k; i < k+1001; i++)
		{	
			scanf("%d", &array[i]);
			
			if(array[k] == -1)
				break;
		}
		
		if(array[k] == -1)
		{
			break;
		}
		else
		{
			k+=1001;
			array = (int *) realloc(array, k*sizeof(int *));
		}
	}
	
	
	for(j = 0; j < k/1001; j++)
	{
		int count = 0;

		for(i = j*1001; i < (j*1001)+1000; i++)
			if(array[i] == array[(j*1001)+1000])
				++count;
		
		printf("%d appeared %d times\n", array[(j*1001)+1000], count);
	}


	return 0;
}
