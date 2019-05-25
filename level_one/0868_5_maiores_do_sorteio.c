#include<stdio.h>

int *ordernedNumbers (int *array, int n)
{
	int i, k, aux;

	for(i = 0; i < n; i++)
	{
		for(k = i + 1; k < n; k++)
		{
			if(array[i] > array[k])
			{
				aux = array[k];
				array[k] = array[i];
				array[i] = aux;
			}
		}
	}
	
	return array;	
}

int *formatFiveNumbers(int *array, int k)
{
	int newArray[5], i;
	
	if(k < 5)
	{
		int n = 4;

		for(i = 0; i < 5; i++)
		{
			if(array[i] != 0)
			{
				newArray[n] = array[i];
			}
			else
			{
				newArray[n] = -1;
			}
			
			n--;	
		}
	}
	else
	{
		for(i = k - 5; i < k; i++)
			newArray[i - (k-5)] = array[i];
	}
	
	return newArray;	
}

int *lottery (int *array, int n, int d)
{
	int fiveNumbers[n], i, k = 0;

	for(i = 0; i < n; i++)
	{
		if(array[i]%10 == d)
		{
			fiveNumbers[k] = array[i];
			k++;
		}
	}

	return formatFiveNumbers(ordernedNumbers(fiveNumbers, k), k);
}

int main (void)
{
	
	int n, d;

	scanf("%d %d", &n, &d);

	int array[n], i;

	for(i = 0; i < n; i++)
		scanf("%d", &array[i]);

	int *fiveNumbers;
	fiveNumbers = lottery(array, n, d);
	
	for(i = 0; i < 5; i++)
		printf("%d\n", fiveNumbers[i]);

	return 0;
}
