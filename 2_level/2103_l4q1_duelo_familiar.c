#include<stdio.h>

void set_matrix (int i, int n, int matrix[][n])
{
	if (i < n * n)
		if ( scanf("%d", &matrix[i / n][i % n]) != EOF)
		set_matrix(i + 1, n, matrix);
}

int diag_princ_is_golpe (int i, int n, int matrix[][n])
{
	if (i < n)
	{
		if (matrix[i][i] != 1)
			return 0;
		
		return diag_princ_is_golpe(i + 1, n, matrix);
	}

	return 1;
}

int diag_sec_is_golpe (int i, int n, int matrix[][n])
{
	if (n != -1)
	{
		if (matrix[n][i] != 1)
			return 0;

		return diag_sec_is_golpe(i + 1, n - 1, matrix);
	}

	return 1;
}

int count_number_one (int i, int n, int matrix[][n])
{
	if (i < n * n)
	{
		if (matrix[i / n][i % n] == 1)
			return 1 + count_number_one(i + 1, n, matrix);
		
		return count_number_one(i + 1, n, matrix);
	}

	return 0;
}

int is_valid (int matrix[][3])
{
	if (count_number_one(0, 3, matrix) == 3)
	{
		if (diag_princ_is_golpe(0, 3, matrix))
			return 1;
		
		if (diag_sec_is_golpe(0, 2, matrix))
			return 1;
	}

	return 0;
}

int diag_princ_sec_matrixs(int matrix1[][3], int matrix2[][3])
{
	if (count_number_one(0, 3, matrix1) == 3 && count_number_one(0, 3, matrix2) == 3)
	{
		if (diag_princ_is_golpe(0, 3, matrix1) && diag_sec_is_golpe(0, 2, matrix2))
			return 0;
		
		if (diag_princ_is_golpe(0, 3, matrix2) && diag_sec_is_golpe(0, 2, matrix1))
			return 0;
	}

	return 1;
}

void batalha (int i, int *life_luke, int *life_darth)
{
	if (i == 0 || ((*life_luke) <= 0) || ((*life_darth) <= 0))
		return;
	

	int golpe_luke[3][3], golpe_darth[3][3];
	
	set_matrix(0, 3, golpe_luke);
	set_matrix(0, 3, golpe_darth);
	
	if (is_valid(golpe_luke))
		if(diag_princ_sec_matrixs(golpe_luke, golpe_darth))
			*life_darth -= 15;
	
	if (is_valid(golpe_darth))
		if(diag_princ_sec_matrixs(golpe_luke, golpe_darth))
			*life_luke -= 15;
	
	return batalha (i - 1, life_luke, life_darth);
}

int main ()
{
	int life_luke, life_darth;
	
	scanf("%d %d", &life_luke, &life_darth);
	
	batalha(10, &life_luke, &life_darth);
	
	if (life_luke == life_darth)
	{
		printf("Houve empate.\n");
	}
	else if (life_luke > life_darth)
	{
		printf("Luke Skywalker venceu.\n");
	}
	else
	{
		printf("Darth Vader venceu.\n");
	}

	return 0;
}
