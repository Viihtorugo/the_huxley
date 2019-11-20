#include<stdio.h>

void set_array (int i, int n, int array[])
{
	if (i < n)
	{
		scanf("%d", &array[i]);
		set_array(i + 1, n, array);
	}
}

void print_array (int i, int range, int array[], int size_array)
{
	if (i < range)
	{
		printf("%d ", array[i % size_array]);
		
		if (i + 1 == range)
			printf("\n");
		
		print_array(i + 1, range, array, size_array);
	}
}

void set_seq(int i, int n, int array[])
{
	char c;
	int jump;
	
	scanf(" %c %d", &c, &jump);
	
	if (c == 'D')
	{
		i -= jump;
		
		if (i < 0)
			i += n;

		print_array(i, n + i, array, n);
		set_seq(i, n, array);
	}
	else if (c == 'E')
	{
		i += jump;

		print_array(i, n + i, array, n);
		set_seq(i, n, array);
	}
	
	return;
}

int main ()
{
	int n;
	scanf("%d", &n);
	
	int array[n];
	set_array(0, n, array);
	
	set_seq(0, n, array);

	return 0;
}
