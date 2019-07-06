#include <stdio.h>

void setArray (int i, int n, int array[])
{
	if(i < n)
	{
		scanf("%d", &array[i]);
		setArray(i+1, n, array);
	}
}

int indexDoMaiorNumero(int i, int n, int array[], int index)
{
	if(i < n)
	{
		if(array[i] > array[index])
			index = i;
		
		return indexDoMaiorNumero(i+1, n, array, index); 
	}
	
	return index;
}

int indexDoMenorNumero(int i, int n, int array[], int index)
{
	if(i < n)
	{
		if(array[i] < array[index])
			index = i;
		
		return indexDoMenorNumero(i+1, n, array, index); 
	}
	
	return index;
}

int count (int num, int array[], int i, int n)
{
	if(i < n)
	{
		if (array[i] == num)
			return 1 + count(num, array, i+1, n);
		
		return count(num, array, i+1, n);
	}
	
	return 0;
}

int main ()
{
	int n, id;
	scanf("%d", &n);
	
	int array[n];
	setArray(0, n, array);
	
	id = indexDoMaiorNumero(1, n, array, 0);
	printf("Maior: %d apareceu %d vezes\n", array[id], count(array[id], array, 0, n));
	
	id = indexDoMenorNumero(1, n, array, 0);
	printf("Menor: %d apareceu %d vezes\n", array[id], count(array[id], array, 0, n));

	return 0;
}
