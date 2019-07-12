#include <stdio.h>

int countCycle (long long int n)
{
	if(n == 1)
		return 1;

	if (n % 2 == 0)
	{
		n /= 2;
	}
	else
	{
		n = (n*3) + 1;
	}
	
	return 1 + countCycle(n);
}

int loopMaxCycleSize (int n1, int n2, int aux)
{	
	int numMax;

	if(n2-n1 < 1000)
	{	
		if(n1 < 0)
			n1 = aux;

		if(n1 == n2)
			return countCycle(n2);
			
		int n 	= countCycle(n2);
		numMax = loopMaxCycleSize(n1, n2-1, aux);

		if (n > numMax)
			numMax = n;
		
		return numMax;
	}
	
	numMax = loopMaxCycleSize(n2-1000, n2, aux);
	return numMax;
}

void loop (int n)
{
	if(n == 0)
		return;
	
	int n1, n2;
	
	scanf("%d %d", &n1, &n2);	
	printf("%d %d %d\n", n1, n2, loopMaxCycleSize(n1, n2, n1));
	
	return loop(n-1);
}

int main () 
{
	loop(4);
	return 0;
}
