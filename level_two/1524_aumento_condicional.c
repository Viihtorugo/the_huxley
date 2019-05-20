#include<stdio.h>

void salaryOutput (double oldSalary, double newSalary)
{
	printf("%.2lf\n", oldSalary);
	printf("%.lf\n", (newSalary-oldSalary)*100/oldSalary );
	printf("%.2lf\n", newSalary - oldSalary);
	printf("%.2lf\n", newSalary);
}

int main (void)
{
	double salary;	
	
	scanf("%lf", &salary);	
	
	if(salary <= 280 && salary > 0)
		salaryOutput(salary, salary*1.20);
		
	if(salary > 280 && salary <= 700)
		salaryOutput(salary, salary*1.15);
		
	if(salary > 700 && salary < 1500)
		salaryOutput(salary, salary*1.10);
	
	if(salary >= 1500)
		salaryOutput(salary, salary*1.05);

	return 0;
}
