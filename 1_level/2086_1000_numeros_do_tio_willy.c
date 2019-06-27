#include <stdio.h>

int count = 0;

int loop(int i)
{
	int n;
	scanf("%d", &n);

	if(i == 1000)
		return n;
	
	int aux = loop(i+1);
	
	if(n == aux)
		count+=1;

	if(i == 0)
	{
		if(n == -1)
			return 0;
		
		printf("%d appeared %d times\n", aux, count);
		
		count = 0;
		return loop(0);
	}
	
	return aux;
}

int main ()
{
	return loop(0);
}
