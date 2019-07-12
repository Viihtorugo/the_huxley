#include <stdio.h>

int count (int n)
{
	if(n == 0)
		return 0;
	
	double productInit, productDiscount;
	scanf("%lf %lf", &productInit, &productDiscount);

	if ((int) (productInit*0.8) == (int) productDiscount)
		return 1 + count(n-1);
	
	return count(n-1);
}

int main ()
{
	printf("%d\n", count(5));
	return 0;
}
