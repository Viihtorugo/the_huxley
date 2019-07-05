#include<stdio.h>

void setArray(int i, float array[])
{
	if(i < 4)
	{
		scanf("%f", &array[i]);
		setArray(i+1, array);
	}
}

void printArray(int i, float array[])
{
	if(i < 4)
	{
		printf("%.2f\n", array[i]);
		printArray(i+1, array);
	}
}

int indexOfHighestNumber(int i, float array[], int index)
{
	if(i < 3)
	{
		if(array[i] > array[index])
			index = i;
		
		return indexOfHighestNumber(i+1, array, index);
	}
	
	return index;
}

int indexOfLowerNumber(int i, float array[], int index)
{
	if(i < 4)
	{
		if(array[i] < array[index])
			index = i;

		return indexOfLowerNumber(i+1, array, index);
	}

	return index;
}

void swap (float *a, float *b)
{
	float aux = *b;
	*b = *a;
	*a = aux;
}

void sort(float array[])
{
	int id = indexOfLowerNumber(0, array, 1);
	
	if(id != 0)
		swap(&array[id], &array[0]);

	id = indexOfLowerNumber(1, array, 2);
	
	if(id != 3)	
		swap(&array[id], &array[3]);

	id = indexOfHighestNumber(1, array, 2);
	
	if(id != 2)
		swap(&array[id], &array[2]);
}

int main(){
	
	float array[4];
	
	setArray(0, array);
	sort(array);
	printArray(0, array);

	return 0;
}
