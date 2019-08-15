#include <stdio.h>
#define MAX 9

void set_matrix(int i, int matrix[][MAX])
{
	if (i < MAX * MAX)
	{
		scanf("%d", &matrix[i / MAX][i % MAX]);
		set_matrix(i + 1, matrix);
	}
}

void set_array_with_matrix_order_3 (int i, int j, int n, int m, int matrix[][MAX], int count, int array[])
{
	if (i < n)
	{
		if (j < m)
		{
			array[count] = matrix[i][j];
			return set_array_with_matrix_order_3(i, j + 1, n, m, matrix, count + 1, array);
		}

		return set_array_with_matrix_order_3(i + 1, j - 3, n, m, matrix, count, array);
	}
	
	return;
}

void set_array_with_line_matrix (int i, int j, int matrix[][MAX], int array[])
{
	if (j < MAX)
	{
		array[j] = matrix[i][j];
		set_array_with_line_matrix(i, j + 1, matrix, array);
	}
}

void set_array_with_column_matrix(int i, int j, int matrix[][MAX], int array[])
{
	if (j < MAX)
	{
		array[j] = matrix[j][i]; 
		set_array_with_column_matrix(i, j + 1, matrix, array);
	}
}

int elem_equal_array (int count, int i, int array[])
{
	if (count < MAX)
	{
		if (i < MAX)
		{
			if (array[count] == array[i])
				return 0;
			
			return elem_equal_array(count, i + 1, array);
		}
		
		count += 1;
		i = count + 1;
		return elem_equal_array(count, i, array);
	}
	
	return 1;
}

int is_sudoku (int i, int matrix[][MAX])
{
	if (i < MAX)
	{
		int array[MAX];		
		set_array_with_line_matrix(i, 0, matrix, array);
		
		if (elem_equal_array(0, 1, array))
		{
			set_array_with_column_matrix(i, 0, matrix, array);
			
			if (elem_equal_array(0, 1, array))
			{
				int m;
				
				if ( ((i + 1) % 3) * 3 == 0)
				{
					m = MAX;
				}
				else
				{
					m = ((i + 1) % 3) * 3;
				}

				set_array_with_matrix_order_3((i/3)*3, (i%3)*3, ((i + 3)/3)*3, m, matrix, 0, array);
				
				if(elem_equal_array(0, 1, array))
				{
					return is_sudoku(i + 1, matrix);
				}
			}		
		}

		return 0;
		
	}

	return 1;
}

void print_instancia (int i, int n)
{
	if (i < n)
	{
		int matrix[MAX][MAX];
		set_matrix(0, matrix);
	
		printf("Instancia %d\n", i + 1);
		
		if (is_sudoku(0, matrix))
		{
			printf("SIM\n\n");
		}
		else
		{
			printf("NAO\n\n");
		}

		print_instancia(i + 1, n);
	}
}

int main ()
{
	int n;
	scanf("%d", &n);
	
	print_instancia(0, n);

	return 0;
}
