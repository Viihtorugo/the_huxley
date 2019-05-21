#include<stdio.h>

int waterBill (int n)
{
	int value = 7;

	if(n > 100)
	{
		value += (n-100)*5;
		n = 100;
	}
	
	if(n <= 100 && n > 30)
	{
		value += (n-30)*2;
		n = 30;
	}
	
	if(n <= 30 && n > 10)
		value += (n-10)*1;

	return value;
}

int main (void)
{
	int n;

	scanf("%d", &n);
	
	printf("%d\n", waterBill(n));	

	return 0;
}
