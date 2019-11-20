#include<stdio.h>

void set_array(int i, int n, int array[])
{
	if (i < n)
	{
		int s, r;
		scanf("%d %d", &s, &r);
		array[i] = s - r;
		set_array(i + 1, n, array);
	}
}

int id_less_elem_array(int i, int n, int array[], int id_less)
{
	if (i < n)
	{
		if (array[i] > array[id_less])
			id_less = i;
		
		return id_less_elem_array(i + 1, n, array, id_less);	
	}
	
	return id_less;
}

void swap (int *n1, int *n2)
{
	int aux = *n1;
	*n1 = *n2;
	*n2 = aux;
}

void sort_array(int n, int array[])
{
	if (n != 1)
	{
		swap(&array[id_less_elem_array(0, n, array, 1)], &array[n - 1]);
		sort_array(n - 1, array);
	}
}

void add_goals(int n, int array[], int g)
{
	if(n >= 0)
	{
		if (g != 0)
		{
			if (array[n] <= 0)
			{
				array[n] += 1;
				g -= 1;
				return add_goals(n, array, g);
			}
			else
			{
				return add_goals(n - 1, array, g);
			}
		}
		else
		{
			return;
		}
	}
}

int count_points(int i, int n, int array[])
{
	if (i < n)
	{
		if (array[i] > 0)
		{
			return 3 + count_points(i + 1, n, array);
		}
		else if (array[i] == 0)
		{
			return 1 + count_points(i + 1, n, array);
		}
		else
		{
			return count_points(i + 1, n, array);
		}
	}
	
	return 0;
}

int last_number_less_one_on_array(int i, int n, int array[])
{
	if (i < n)
	{
		if (array[i] <= 0)
		{
			if (i + 1 != n)
			{
				if (array[i + 1] > 0)
					return i;

				return last_number_less_one_on_array(i + 1, n, array);
			}
			else
			{
				return i;
			}
		}
	}
}

int main ()
{
	
	int n, g;
	scanf("%d %d", &n, &g);
	
	int array[n];
	set_array(0, n, array);
	
	sort_array(n, array);
	
	add_goals(last_number_less_one_on_array(0, n, array), array, g);
	
	printf("%d\n", count_points(0, n, array));

	return 0;
}
