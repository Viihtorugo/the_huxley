#include <stdio.h>

int higherNumber(int num)
{
	int n;
	scanf("%d", &n);
	
	if(n == 0)
		return num;

	if(n > num)
		num = n;
	
	return higherNumber(num);
}

int main ()
{
	printf("%d\n", higherNumber(0));
	return 0;
}
