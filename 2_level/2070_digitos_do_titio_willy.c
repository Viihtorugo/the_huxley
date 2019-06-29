#include <stdio.h>

int digitos (int n, int i)
{
	if(n > 0 && n < 10)
	{
		if(n % 2 == 0)
			return n*2*i;
		
		return n*3*i;
	}
	
	int unity = n % 10;

	if( unity % 2 == 0)
		return unity*2*i + digitos(n/10, ++i);
		
	return unity*3*i + digitos(n/10, ++i);
}

void loop ()
{
	int n;
	
	scanf("%i", &n);
	
	if(n == 0)
		return;
	
	printf("%d\n", digitos(n, 1));
	loop();
}

int main ()
{
	loop();
	return 0;
}
