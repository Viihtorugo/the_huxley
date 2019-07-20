#include <stdio.h>

void setArray(int array[], int i, int n)
{
	if (i < n)
	{
		scanf("%d", &array[i]);
		setArray(array, i+1, n);
	}
}

int tunelDeSaida (int array[], int i, int n)
{
	if (i < n)
	{
		if(array[i] == -1)
			return i;
		
		return tunelDeSaida(array, i+1, n);
	}
	
	return tunelDeSaida(array, 0, n);
}

int main ()
{
	int n, t;
	scanf("%d", &n);

	int array[n];
	setArray(array, 0, n);
	
	scanf("%d", &t);

	printf("%d\n", tunelDeSaida(array, t, n));

	return 0;
}
