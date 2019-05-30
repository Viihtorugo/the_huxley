#include<stdio.h>
#include<stdlib.h>

int main (void)
{
	int k = 0, i;
	int *array = malloc(sizeof(int *));
	
	while(1)
	{
		scanf("%d", &array[k]);

		if(array[k] == 0)
			break;

		k++;
		array = realloc(array, (k+1)*sizeof(int *));
	}

	for(i = 0; i < k; i++)
	{
		int j = 1;

		while(1)
		{
			if( (j * j - (j-1) * (j-1)) == array[i] )
			{
				printf("%d - %d\n", j*j, (j-1)*(j-1));
				break;
			}

			j++;	
		}
	}

	return 0;
}
