#include<stdio.h>
#include<math.h>

int main(void)
{
	double a, b, c;
	
	scanf("%lf %lf %lf", &a, &b, &c);
	
	if(a != 0)
	{
		double delta = (b*b) - (4*a*c);
	
		if(delta >= 0)
		{	
			printf("%.2lf\n", (-b + sqrt(delta))/(2.0*a));
			printf("%.2lf\n", (-b - sqrt(delta))/(2.0*a));
		}
		else
		{
			printf("NRR");
		}
	}
	else
	{
		printf("NEESG\n");
	}

	return 0;
}
