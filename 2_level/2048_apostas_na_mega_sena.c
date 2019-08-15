#include <stdio.h>

void set_matrix (int i, int j, int n, char c, int matrix[][10], int columns[])
{
	if (i < n)
	{
		if (j < 10 && c == ',')
		{
			scanf("%d%c", &matrix[i][j], &c);
			return set_matrix(i, j + 1, n, c, matrix, columns);
		}
		
		columns[i] = j;
		return set_matrix(i + 1, 0, n, ',', matrix, columns);
	}
}

void set_array (int i, int array[])
{
	if (i < 6)
	{
		scanf("%d", &array[i]);
		set_array(i + 1, array);
	}
}

int mega_sena_round(int i, int j, int columns, int matrix[][10], int number)
{
	if (j < columns)
	{
		if(matrix[i][j] == number)
		{
			return 1;
		}

		return mega_sena_round (i, j + 1, columns, matrix, number);
	}
	
	return 0;
}

int count_winners(int i, int j, int n, int game[], int matrix[][10], int columns[])
{
	if (i < n)
	{
		if (j < 6)
		{
			if (mega_sena_round(i, 0, columns[i], matrix, game[j]))
			{
				return count_winners(i, j + 1, n, game, matrix, columns);
			}
			else
			{
				return count_winners(i + 1, 0, n, game, matrix, columns);
			}
		}
		
		if (j == 6)
		{
			return 1 + count_winners(i + 1, 0, n, game, matrix, columns);
		}
		else
		{
			return count_winners(i + 1, 0, n, game, matrix, columns);
		}
	}

	return 0;
}

int main ()
{
	int n;
	scanf("%d", &n);
	
	int matrix[n][10], columns[n];
	set_matrix(0, 0, n, ',', matrix, columns);
	
	int game[6];
	set_array(0, game);
	
	printf("Total de ganhadores: %d\n", count_winners(0, 0, n, game, matrix, columns));
	
	return 0;
}
