#include<stdio.h>

int numbersOfHousesPenalties(double countPenalty)
{
	
	int nCar;

	scanf("%d", &nCar);

	if(nCar == 999)
	{
		printf("%.2lf\n", countPenalty);
		return 0;
	}

	if(nCar > 2)
		return numbersOfHousesPenalties( countPenalty + ((nCar-2) * 12.89) ) + 1;

	return numbersOfHousesPenalties(countPenalty);
}

int main(void)
{
	printf("%d\n", numbersOfHousesPenalties(0));
	
	return 0;
}
