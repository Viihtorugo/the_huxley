#include <stdio.h>

void set_array(int i, int n, int array[])
{
	if (i < n)
	{
		scanf("%d", &array[i]);
		set_array(i + 1, n, array);
	}
}

int array_index (int i, int n, int array[])
{
	if(i < n)
	{
		if(array[i] != n)
			return i;

		return array_index(i + 1, n, array);
	}
	
	return n;
}

int count_tocas (int i, int n, int array[])
{
	if (i < n)
	{
		if (array[i] == n)
			return 1 + count_tocas (array_index(0, n, array), n, array);
		
		int aux = array[i];
		array[i] = n;
		return count_tocas (aux, n, array);
	}
	
	return 0;
}

int main ()
{
	int n;
	scanf("%d", &n);
	
	int array[n];
	set_array(0, n, array);
	
	printf("%d\n", count_tocas(0, n, array));

	return 0;
}
