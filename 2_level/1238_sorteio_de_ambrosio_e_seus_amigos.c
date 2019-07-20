#include <stdio.h>

void setArray(int array[], int i, int n)
{
	if (i < n)
	{
		array[i] = i;
		setArray(array, i+1, n);
	}
}

/*void printArray (int array[], int i, int n)
{
	if (i < n)
	{
		printf("i = %d - valor = %d\n", i, array[i]);
		printArray(array, i+1, n);
	}
}*/

void swap (int *n1, int *n2)
{
	int aux = *n1;
	*n1 	= *n2;
	*n2	= aux;
}

int indexDoMenorNumero (int array[], int i, int n, int id)
{	
	if (i < n)
	{
		if (array[i] < array[id])
			id = i;
		
		return indexDoMenorNumero (array, i+1, n, id);
	}
	
	return id;
}

void sortArray (int array[], int i, int n)
{
	if (i < n)
	{
		int id = indexDoMenorNumero(array, i+1, n, i);
		
		swap(&array[i], &array[id]);

		sortArray(array, i+1, n);
	}
}

int loop (int i, int n, int array[])
{
	if(n == 0)
		return array[n];

	int count;
	scanf("%d", &count);
	
	if (count > n + 1)
	{
		i += count % (n+1);
	}
	else
	{
		i += (n+1) % count;
	}

	swap(&array[i], &array[n]);
	
	sortArray(array, 0, n);
	//printArray(array, 0, n);

	return loop(i, n-1, array);
}

int main ()
{
	int n;
	scanf("%d", &n);

	int array[n];
	setArray(array, 0, n);
	
	printf("%d\n", loop(0, n-1, array));

	return 0;
}
