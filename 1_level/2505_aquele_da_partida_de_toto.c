#include <stdio.h>

void setArray (int array[], int i, int n)
{
	if (i < n)
	{
		scanf("%d", &array[i]);
		setArray(array, i+1, n);
	}
}

void 

int main ()
{
	int pointWinner, n, count;

	scanf("%d %d", &pointWinner, &n);
	
	int pointsJ[n], pointsC[n];
	
	setArray(pointsJ, 0, n);
	setArray(pointsC, 0, n);

	return 0;
}
