#include<stdio.h>

int mdc (int n1, int n2, int i)
{
	if(n1%i == 0 && n2%i == 0)
		return i;

	return mdc(n1, n2, --i);
}

int main ()
{
	int n1, n2, d;

	scanf("%d %d", &n1, &n2);
	
	if(n1 > n2)
	{
		d = mdc(n1, n2, n2);
	}
	else
	{
		d = mdc(n1, n2, n1);
	}

	printf("%d\n", d);	

	return 0;
}
