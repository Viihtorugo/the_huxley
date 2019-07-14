#include <stdio.h>

int main ()
{
	int n;
	
	printf("Digite um numero:\n");
	scanf("%d", &n);

	printf("Algarismo das unidades: %d\n", n%10);
	return 0;
}
