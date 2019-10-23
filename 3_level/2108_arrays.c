#include<stdio.h>

void set_array(int i, int n, int array[])
{
	if (i < n)
	{
		scanf("%d", &array[i]);
		set_array(i + 1, n, array);
	}
}

int is_less(int i, int n, int array[], int num)
{
	if (i < n)
		return (array[i] > num) ? is_less(i + 1, n, array, num) : 0;

	return 1;
}

int build_algorithm (int i, int k, int count_a1, int n, int m int array1[], int array2[])
{
	if (i < k)
	{
		if (is_less(0, m, array2, array1[count_a1]))
			++i;
		
		if (count_a1 + 1 == n)
		{
			return build_algorithm(i, k, count_a1 + 1, n, m, array1, array2);
		}
		else
		{
			return 0;
		}
	}
	
	return 1;
}

int main ()
{
	int n, m, i, k;
	scanf("%d %d %d %d", &n, &m, &i, &k);

	int array1[n], array2[m];
	set_array(0, n, array1);
	set_array(0, m, array2);
	
	if (build_algorithm(0, k, 0, n, m, array1, array2))
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}
