#include <stdio.h>
#include <locale.h>

long double accumulator(int n, int i, long double count, int op)
{
	if(n==0)
		return count;

	if(op)
		return accumulator(--n, i+2, (count - (4.0/i)), 0);
	
	return accumulator(--n, i+2, (count + (4.0/i)), 1);
}

int main ()
{
	int n;

	scanf("%d", &n);
	
	setlocale(LC_NUMERIC, "");	

	if(n > 1)
	{
		printf("%.5Lf\n", accumulator(--n, 3, 4.0, 1));
	}
	else
	{
		printf("3,14159\n");
	}

	return 0;
}
