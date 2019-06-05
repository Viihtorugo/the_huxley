#include<stdio.h>

int main (void)
{
	
	double n1, n2, n3;
	int count = 0;

	scanf("%lf %lf %lf", &n1, &n2, &n3);
	
	double m = (n1 + n2 + n3)/3.0;	
	
	if(n1 > m)
		count++;
	
	if(n2 > m)
		count++;
	
	if(n3 > m)
		count++;

	printf("%d\n", count);	

	return 0;
}
