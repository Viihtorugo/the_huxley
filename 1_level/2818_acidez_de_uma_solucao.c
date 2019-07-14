#include <stdio.h>

int main ()
{
	float ph;

	printf("Digite o pH da solucao:\n");
	scanf("%f", &ph);
	
	if (ph > 7 && ph <= 14)
	{
		printf("Solucao basica");
	}
	else if (ph < 7 && ph > 0)
	{
		printf("Solucao acida");
	} 
	else if (ph == 7)
	{
			printf("Solucao neutra");
	}
	else
	{
		printf("Valor do pH deve estar entre 0 e 14");
	}
	
	return 0;
}
