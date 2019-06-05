#include<stdio.h>
 
int main(void)
{
	double f;

	scanf("%lf", &f);
	printf("%.2lf\n", ((f-32)/1.8));

	return 0;
}
