#include<stdio.h>

double newSalary (double salary)
{
	if(salary > 500)
		return salary*1.10;

	if(salary <= 500 && salary > 300)
		return salary*1.07;
	
	return salary*1.05;
}

int main (void)
{
	double salary;
	
	scanf("%lf", &salary);

	printf("%.2lf\n", newSalary(salary));
	
	return 0;
}
