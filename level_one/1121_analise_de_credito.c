#include<stdio.h>

int main(void)
{
	double salary, income;
	
	scanf("%lf %lf", &salary, &income);	
	
	income >= salary*0.3 ? printf("0.00\n") : printf("%.2lf\n", salary*0.3 - income);

	return 0;
}
