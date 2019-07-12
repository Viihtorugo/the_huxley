#include <stdio.h>

void tratarFluxoDoElevador(int *numPessoas)
{
	int numSaida, numEntrada;	
	scanf("%d %d", &numSaida, &numEntrada);

	*numPessoas -= numSaida;
		
	if (*numPessoas < 0)
		*numPessoas = 0;
		
	*numPessoas += numEntrada;
}

int fluxoDoElevador (int i, int n, int numMax, int numIni)
{
	if (i < n)
	{
		tratarFluxoDoElevador(&numIni);

		if (numIni > numMax)
			return 1 + fluxoDoElevador(i+1, n, numMax, numIni);
		
		return fluxoDoElevador(i+1, n, numMax, numIni);
	}
	
	return 0;
}


int main () 
{
	int n, numMax;
	
	scanf("%d %d", &n, &numMax);	
	
	if(fluxoDoElevador(0, n, numMax, 0))
	{
		printf("S\n");
	}
	else
	{
		printf("N\n");
	}
	
	return 0;
}
