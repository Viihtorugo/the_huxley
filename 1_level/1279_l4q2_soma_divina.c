#include <stdio.h>

void set_matrix (int i, int n, int matrix[][n])
{
	if (i < (n * n))
	{
		scanf("%d", &matrix[i / n][i % n]);
		set_matrix (i + 1, n, matrix);
	}
}

void set_sum_matrix (int i, int n, int matrix1[][n], int matrix2[][n], int sum[][n])
{
	if (i < (n * n))
	{
		sum[i / n][i % n] = matrix1[i / n][i % n] + matrix2 [i / n][i % n];
		set_sum_matrix(i + 1, n, matrix1, matrix2, sum);
	}
}

void print_matrix(int i, int n, int matrix[n][n])
{
	if (i < (n * n))
	{
		printf("%d\n", matrix[i / n][i % n]);
		print_matrix (i + 1, n, matrix);
	}
}

int main ()
{
	int n;
	scanf("%d", &n);

	if (n > 0)
	{
		int matrix1[n][n];
		int matrix2[n][n];
		int sum[n][n];

		set_matrix(0, n, matrix1);
		set_matrix(0, n, matrix2);
		
		set_sum_matrix(0, n, matrix1, matrix2, sum);
		
		print_matrix(0, n, sum);
	}
	else
	{
		printf("Vazia\n");
	}

	return 0;
}
