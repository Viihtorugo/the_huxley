#include <stdio.h>

int possibilidades(int n, int i, int dif)
{	
	if (n < 0)
		return 0;

	int aux = n - i;

	if (aux < 0)
		aux *= -1;
	
	if (dif == aux)
		return 1 + possibilidades(--n, ++i, dif);
	
	return possibilidades(--n, ++i, dif);
}

int main ()
{
	int nMoedas, dif;

	scanf("%i %i", &nMoedas, &dif);
	
	printf("%d\n", possibilidades(nMoedas, 0, dif));
	
	return 0;
}
