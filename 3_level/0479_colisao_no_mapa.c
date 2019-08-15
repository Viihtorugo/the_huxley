#include <stdio.h>

void set_matrix (int i, int n, int m, int matrix[][m])
{
	if (i < n * m)
	{
		scanf("%d", &matrix[i / m][i % m]);
		set_matrix(i + 1, n, m, matrix);
	}
}

void set_array(int i, int n, char array[])
{
	if (i < n)
	{
		array[i] = getchar();
		
		if (array[i] != '\n')
		{
			set_array(i + 1, n, array);
		}
		else
		{
			set_array(i, n, array);
		}
	}
}

void comandos(int i, int n, char array[], int *x, int *y, int lines, int columns, int matrix[][columns])
{
	if (i < n)
	{	
		if (array[i] == 'D')
			if (*y + 1 != columns)
				if (matrix[*x][*y + 1] != 0)
					*y += 1;

		if (array[i] == 'E')
			if (*y - 1 != -1)
				if (matrix[*x][*y - 1] != 0)
					*y -= 1;

		if (array[i] == 'C')
			if (*x - 1 != -1)
				if (matrix[*x - 1][*y] != 0)
					*x -= 1;
				
		if (array[i] == 'B')
			if (*x + 1 != lines)
				if (matrix[*x + 1][*y] != 0)
					*x += 1;
		
		comandos(i + 1, n, array, x, y, lines, columns, matrix);
	}
}

int main ()
{
	int lines, columns;
	scanf("%d %d", &lines, &columns);
	
	int matrix[lines][columns];
	set_matrix(0, lines, columns, matrix);
	
	int n;
	scanf("%d", &n);
	
	char array[n];
	set_array(0, n, array);
	
	int x, y;
	scanf("%d %d", &x, &y);

	comandos(0, n, array, &x, &y, lines, columns, matrix);
	
	printf("(%d,%d)\n", x, y);

	return 0;
}
