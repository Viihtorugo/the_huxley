#include<stdio.h>

int main(void)
{
	double liters;
	char typeOfFuel;

	scanf("%lf %c", &liters, &typeOfFuel);
	
	switch (typeOfFuel)
	{
		case 'A':
			liters <= 20 ? printf("R$ %.2lf\n", (liters*1.9)*0.97 ) : printf("R$ %.2lf\n", (liters*1.9)*0.95 );
		break;

		case 'G':
			liters <= 20 ? printf("R$ %.2lf\n", (liters*2.5)*0.96 ) : printf("R$ %.2lf\n", (liters*2.5)*0.94 );		
		break;

		case 'D':
			liters <= 25 ? printf("R$ %.2lf\n", liters*1.66 ) : printf("R$ %.2lf\n", (liters*1.66)*0.96 );
		break;
	}
	
	return 0;
}
