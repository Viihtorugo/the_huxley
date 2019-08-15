#include<stdio.h>
#define MAX 3

void set_matrix (int i, int matrix[][MAX])
{
	if (i < MAX * MAX)
	{
		scanf("%d", &matrix[i / MAX][i % MAX]);
		set_matrix(i + 1, matrix);
	}
}

double sum_positivos (int i, int *n, int matrix[][MAX])
{
	if (i < MAX * MAX)
	{
		if (matrix[i / MAX][i % MAX] > 0)
		{
			*n += 1;
			return matrix[i / MAX][i % MAX] + sum_positivos(i + 1, n, matrix);
		}

		return sum_positivos(i + 1, n, matrix);
	}

	return 0;
}

int menor_num (int i, int matrix[][MAX], int menor)
{
	if (i < MAX * MAX)
	{
		if (matrix[i / MAX][i % MAX] < menor)
			menor = matrix[i / MAX][i % MAX];
		
		return menor_num(i + 1, matrix, menor);
	}
	
	return menor;
}

int sum_diag_princ (int i, int matrix[][MAX])
{
	if (i < MAX * MAX)
	{
		if ((i / MAX) != (i % MAX))
			return matrix[i / MAX][i % MAX] + sum_diag_princ(i + 1, matrix);
		
		return sum_diag_princ(i + 1, matrix);
	}

	return 0;
}

int main ()
{
	int matrix[MAX][MAX], n = 0;	
	set_matrix(0, matrix);
	
	int menor = menor_num(1, matrix, matrix[0][0]);
	int delta;
	
	if (menor % 2 == 0)
	{
		delta = 1;
	}
	else
	{
		delta = 0;
	}

	printf("%.2lf %d %d %d\n", (sum_positivos(0, &n, matrix) / n), menor, delta, sum_diag_princ(0, matrix));

	return 0;
}
