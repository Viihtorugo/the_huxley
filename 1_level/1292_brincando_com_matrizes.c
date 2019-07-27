#include <stdio.h>

void set_array (int j, int i, int n, int matrix[][n])
{
	if (i < n)
	{
		scanf("%d", &matrix[j][i]);
		set_array(j, i + 1, n, matrix);
	}
}

void set_matrix (int j, int n, int matrix[][n])
{
	if (j < n)
	{
		set_array(j, 0, n, matrix);
		set_matrix(j + 1, n, matrix);
	}
}

int sum_array (int j, int i, int n, int matrix[][n])
{
	if (i < n)
	{
		return matrix[j][i] + sum_array(j, i + 1, n, matrix);
	}
	
	return 0;
}

int sum_matrix (int j, int n, int matrix[][n])
{
	if (j < n)
	{
		return sum_array(j, 0, n, matrix) + sum_matrix(j + 1, n, matrix);
	}
	
	return 0;
}

int maior_elem (int i, int n, int m, int matrix[][m], int maior_num)
{
	if (i < n*m)
	{
		
		if (matrix[i / n][i % m] > maior_num)
			maior_num = matrix[i / n][i % m];
		
		return maior_elem (i + 1, n, m, matrix, maior_num);
	}
	
	return maior_num;
}

int sum_diag_princ (int i, int n, int matrix[][n])
{
	if (i < n)
	{
		return matrix[i][i] + sum_diag_princ (i + 1, n, matrix);
	}
	
	return 0;
}

int main ()
{
	int matrix[3][3];
	
	set_matrix(0, 3, matrix);
	
	int maior_num = maior_elem(1, 3, 3, matrix, matrix[0][0]);
	int delta;
	
	if (maior_num > 0)
	{
		delta = 1;
	}
	else if (maior_num == 0)
	{
		delta = 0;
	}
	else
	{
		delta = -1;
	}

	printf("%.2lf %d %d %d\n", sum_matrix(0, 3, matrix)/9.0, maior_num, delta, sum_diag_princ(0, 3, matrix));

	return 0;
}
