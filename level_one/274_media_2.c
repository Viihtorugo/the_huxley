#include<stdio.h>

int main(void)
{
	double n1, n2, n3;
	
	scanf("%lf %lf %lf", &n1, &n2, &n3);
	printf("MEDIA = %.1lf\n", (n1*2 + n2*3 + n3*5)/10);
	
	return 0;
}
