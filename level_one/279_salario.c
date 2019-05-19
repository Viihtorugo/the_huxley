#include<stdio.h>

int main(void)
{
	int numFuncionario, timeOfWork;
	double cashByHours;
	
	scanf("%d %d %lf", &numFuncionario, &timeOfWork, &cashByHours);
	printf("NUMBER = %d\n", numFuncionario);
	printf("SALARY = %.2lf\n", cashByHours*timeOfWork);
 
	return 0;
}
