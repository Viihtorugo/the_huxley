#include<stdio.h>

int main(void){

	float vMax, vCar;

	scanf("%f %f", &vMax, &vCar);
	
	if(vCar > vMax)
	{ 
		if(vCar <= vMax*1.20)
		{
			printf("85.13\n");
			printf("4\n");
		}
		if((vCar > vMax*1.20) && (vCar <= vMax*1.50))
		{
			printf("127.69\n");
			printf("5\n");
		}
		if(vCar > vMax*1.50)
		{
			printf("574.62\n");
			printf("7\n");
		}
	}
	else
	{
		printf("0.00\n");
		printf("0\n");
	}

	return 0;
 }
