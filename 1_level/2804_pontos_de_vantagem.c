#include <stdio.h>

void loop(int n, int *nando, int *dunga)
{
	
	if(n == 0)
		return;
	
	int unity = n % 10;
	
	if(unity % 2 ==0)
	{
		*dunga += unity;
	}
	else
	{
		*nando += unity;
	}

	return loop(n/10, nando, dunga);
}

int main ()
{
	int n, nando = 0, dunga = 0;
	
	scanf("%d", &n);

	loop(n, &nando, &dunga);
	
	if(dunga > nando)
	{
		printf("Vencedor: Dunga\n");
		printf("%d Pontos de Vantagem\n", dunga - nando);
	}
	else if(nando > dunga)
	{
		printf("Vencedor: Nando\n");
		printf("%d Pontos de Vantagem\n", nando - dunga);
	}
	else
	{
		printf("Empate\n");
	}

	return 0;
}
