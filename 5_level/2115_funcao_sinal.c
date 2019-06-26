#include <stdio.h>

int main ()
{
	float n;

	scanf("%f", &n);
	
	if(n == 0)
	{
		printf("sinal(%.4e) = 0\n", n);
	}
	else if (n > 0)
	{
		printf("sinal(%.4e) = +1\n", n);
	}
	else
	{
		printf("sinal(%.4e) = -1\n", n);
	}

	return 0;
}
