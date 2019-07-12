#include <stdio.h>

void precoFinal (int n, int d, double *preco)
{	
	if (n == 0)
		return;
	
	if(*preco <= 45)
		return;

	double desconto;	

	switch (d)
	{
		case 0:
			desconto = 0.25;
			break;
		case 1:
			desconto = 0.20;
			break;
		case 2:
			desconto = 0.18;
			break;
		case 3:
			desconto = 0.15;
			break;
		case 4:
			desconto= 0.12;
			break;
		case 5:
			desconto = 0.10;
			break;
	}
	
	if (*preco <= 100)
		desconto /= 2;
	
	if (*preco * (1-desconto) < 45)
	{
		*preco = 45;
	}
	else
	{
		*preco = *preco * (1-desconto);
	}

	
	precoFinal(n-1, d, preco);
}

void loop (int n, int i)
{	
	if(i < n)
	{
		int d;
		double preco;
	
		scanf("%d %lf", &d, &preco);
		
		precoFinal(3, d, &preco);		
		printf("Jogo[%d] = R$%.2lf\n", i, preco);
		
		loop(n, i+1);
	}
}

int main ()
{	
	int n;
	scanf("%d", &n);	
	
	loop(n, 0);
	
	return 0;
}
