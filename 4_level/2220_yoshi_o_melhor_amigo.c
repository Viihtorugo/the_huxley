#include<stdio.h>

char *output(int pGreen, int pRed, int pBlue, int pYellow)
{
	if(!pGreen)
		if(!pRed)
			if(!pBlue)
				if(!pYellow)
					return "Acho que vou a pe :(\0";

	if(pRed > pBlue)
	{
		if(pRed > pYellow)
		{
			if(pRed - 1 > pGreen)
			{
				return "Vermelho\0";
			}
			else
			{
				return "Verde\0";
			}
		}
		else if(pYellow -1 > pGreen)
		{
			return "Amarelo\0";
		}
		else
		{
			return "Verde\0";
		}
	}
	else if(pBlue > pYellow)
	{
		if(pBlue - 1 > pGreen)
		{
			return "Azul\0";
		}
		else
		{
			return "Verde\0";
		}
	}
	else if(pYellow - 1 > pGreen)
	{
		return "Amarelo\0";
	}
	else
	{
		return "Verde\0";
	}
} 

int costBenefit(int money){
	
	int price, velocity;
	
	scanf("%d %d", &price, &velocity);
	
	if(money >= price)
	{
		return velocity/price;
	}
	else
	{
		return 0;
	}
}

int main ()
{
	int money;
	
	scanf("%d", &money);

	double pGreen 	= costBenefit(money);
	double pRed 	= costBenefit(money);
	double pBlue 	= costBenefit(money);
	double pYellow 	= costBenefit(money);

	printf("%s\n", output(pGreen, pRed, pBlue, pYellow));

	return 0;
}
