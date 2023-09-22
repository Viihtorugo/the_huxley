#include<stdio.h>

void set_array(int i, int n, int array[])
{
	if (i < n)
	{
		scanf("%d", &array[i]);
		set_array(i + 1, n, array);
	}
}

int count_less(int i, int n, int array[], int num, int count, int m)
{
	if (count == m)
		return 1;

	if (i < n)
	{
		if (num < array[i]) 
		{
			return count_less(i + 1, n, array, num, count + 1, m);
		}
		else
		{
			return count_less(i + 1, n, array, num, count, m);
		}
	}

	return 0;
}

int build_algorithm (int array1[], int array2[], int n1, int n2, int k, int m, int i, int count)
{
	if (count == k)
		return 1;

	if (i < n1)
	{
		if (count_less(0, n2, array2, array1[i], 0, m))
		{
			return build_algorithm(array1, array2, n1, n2, k, m, i + 1, count + 1);
		}
		else
		{
			return build_algorithm(array1, array2, n1, n2, k, m, i + 1, count);
		}
	}
	
	return 0;
}

int main ()
{
	int n1, n2, k, m;
	scanf("%d %d %d %d", &n1, &n2, &k, &m);

	int array1[n1], array2[n2];
	set_array(0, n1, array1);
	set_array(0, n2, array2);
	
	if (build_algorithm(array1, array2, n1, n2, k, m, 0, 0))
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}