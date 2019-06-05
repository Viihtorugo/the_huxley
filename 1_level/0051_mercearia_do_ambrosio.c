#include<stdio.h>

float valueProduct(float value, int quant)
{
	if(quant >= 15 || value >= 40)
		return value*0.85;

	return value;
}

int main(void){
	
	int n, quant;
	
	scanf("%i %i", &n, &quant);
	
	switch (n)
	{
		case 1:
			printf("R$ %.2f\n", valueProduct(5.30*quant, quant));
			break;
		case 2:
			printf("R$ %.2f\n", valueProduct(6.00*quant, quant));
			break;
	  	case 3:
			printf("R$ %.2f\n", valueProduct(3.20*quant, quant));
			break;
	  	case 4:
			printf("R$ %.2f\n", valueProduct(2.50*quant, quant));
			break;	 
	}
	
	return 0;
}
