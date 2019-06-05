#include<stdio.h>

int main (void)
{
	
	double pH;

	scanf("%lf", &pH);	
	
	if(pH >= 1.0 && pH < 7)
	{
		printf("Acida\n");
	}
	else if (pH > 7.0 && pH <= 14.0)
	{
		printf("Basica\n");
	}
	else
	{
		printf("Neutra\n");
	}

	return 0;
}
