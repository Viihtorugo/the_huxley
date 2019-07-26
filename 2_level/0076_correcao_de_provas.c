#include <stdio.h>

double cal_nota (int i, int n, char gabarito[], char resp_aluno[])
{
	if (i < n)
	{
		if(gabarito[i] == resp_aluno[i])
			return 1 + cal_nota(i + 1, n, gabarito, resp_aluno);
		
		return cal_nota(i + 1, n, gabarito, resp_aluno);
	}

	return 0;
}



int set_arrays(int i, int numAluno[], double notas[], char gabarito[])
{
	int n;
	scanf("%d", &n);
	
	if (n == 9999)
		return i;
	
	char resp_aluno[11];
	scanf(" %s", resp_aluno);
	
	numAluno[i] 	= n;
	notas[i] 	= cal_nota(0, 10, gabarito, resp_aluno); 
	
	return set_arrays(i + 1, numAluno, notas, gabarito);
}

void print_arrays(int i, int n, int numAluno[], double notas[])
{
	if (i < n)
	{
		printf("%d %.1lf\n", numAluno[i], notas[i]);
		print_arrays(i + 1, n, numAluno, notas);
	}
}

double num_aprovados (int i, int n, double notas[])
{
	if (i < n)
	{
		return (notas[i] >= 6)
			? 1 + num_aprovados(i + 1, n, notas)
			: num_aprovados(i + 1, n, notas);
	}
	
	return 0;
}

int count_n_notas (int i, int n, double notas[],  double nota)
{
	if (i < n)
	{
		
		return (nota == notas[i])
			? 1 + count_n_notas (i + 1, n, notas, nota)
			: count_n_notas (i + 1, n, notas, nota);
	}
	
	return 0;
}

double maior_nota(int i, int n, double notas[], int n_nota, int id)
{
	if (i < n)
	{
		if(notas[i] != notas[id])
		{
			int aux = count_n_notas(i, n, notas, notas[i]);

			if (aux > n_nota)
			{
				n_nota = aux;
				id 	= i;
			}
		}
		
		return maior_nota(i + 1, n, notas, n_nota, id);
	}

	return notas[id];
}

int main ()
{
	char gabarito[11];
	scanf("%s", gabarito);

	int numAluno[10000];	
	double notas[10000];
	
	int n = set_arrays(0, numAluno, notas, gabarito);
	
	print_arrays(0, n, numAluno, notas);

	printf("%.1lf%%\n", (num_aprovados(0, n, notas) / n) * 100.0);
	printf("%.1lf\n", maior_nota(0, n, notas, 0, 0));

	return 0;
}
