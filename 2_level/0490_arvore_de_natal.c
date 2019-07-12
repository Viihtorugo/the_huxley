#include <stdio.h>

float countPrecoDosObjetos(int i)
{ 	
	float qtdObjetos, preco;
	
	scanf("%f %f", &qtdObjetos, &preco);

	if (i == 2)
	{
		return qtdObjetos * preco;	 
	}
	else
	{
		return qtdObjetos * preco + countPrecoDosObjetos(i+1);
	}
}

int main ()
{	
	float valorArvore;
	
	scanf("%f", &valorArvore);
	
	float total = valorArvore + countPrecoDosObjetos(0);
		
	printf("%.2f\n%.2f\n", total, (total/21.0));

	return 0;
}
