#include <stdio.h>

int add (int n)
{
	if(n != 0)
	{
		if(n > 0 && n < 10)
			return n;

		if(add(n/10) % 2 == 0)
			return n+2;
		
		return n+1;
	}
	else
	{
		return n+2;
	}	
}


int main ()
{
	int n;
	
	scanf("%d", &n);
	
	printf("%d\n", add(n));

	return 0;
}
