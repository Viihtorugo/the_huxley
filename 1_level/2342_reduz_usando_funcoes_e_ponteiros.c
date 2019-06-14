#include <stdio.h>

void subtraction (double *x, double *y)
{
	*x -= *y;
}

int main ()
{
	double x, y;
	
	scanf("%lf %lf", &x, &y);
	
	subtraction(&x, &y);
	printf("%.2lf %.2lf\n", x, y);	

	return 0;
}
