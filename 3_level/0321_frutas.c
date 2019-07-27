#include <stdio.h>

float count_massa (int i, char frutas[])
{
	if(frutas[i] == '\0')
		return 1;
	
	return (frutas[i] == ' ')
			? 1 + count_massa (i + 1, frutas)
			: count_massa (i + 1, frutas);
}

float consumo_total (int i, int n, float gastos[])
{	
	if (i < n)
	{
		char frutas[256];
		scanf("%f %[^\n]s", &gastos[i], frutas);
		
		float massa_total = count_massa(0, frutas);
		
		printf("dia %d: %.f kg\n", i + 1, massa_total);
		return massa_total + consumo_total (i + 1, n, gastos);
	}
	
	return 0;
}

float gasto_total (int i, int n, float gastos[])
{
	if (i < n)
		return gastos[i] + gasto_total(i + 1, n, gastos);
	
	return 0;
}

int main ()
{
	int n;
	scanf("%d", &n);

	float gastos[n];
	
	printf("%.2f kg por dia\n", consumo_total(0, n, gastos) / n );
	printf("R$ %.2f por dia\n", gasto_total(0, n, gastos) / n);

	return 0;
}
