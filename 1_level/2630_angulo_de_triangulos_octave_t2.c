#include <stdio.h>
#include <locale.h>

int greaterAngle(int a1, int a2, int a3)
{
	if (a1 > a2)
	{
		if(a1 > a3)
			return a1;
	}
	else if(a2 > a3)
	{
		return a2;
	}

	return a3;
}

int main ()
{
	setlocale(LC_ALL, "Portuguese");

	int a1, a2, a3;

	printf("Digite o valor do primeiro ângulo:\n");
	scanf("%d", &a1);
	
	printf("Digite o valor do segundo ângulo:\n");
	scanf("%d", &a2);
	
	printf("Digite o valor do terceiro ângulo:\n");
	scanf("%d", &a3);
	
	int a = greaterAngle(a1, a2, a3);
	
	if(a == 90)
	{
		printf("Este e um triangulo retangulo.\n");
	}
	else if (a > 90)
	{
		printf("Este e um triangulo obtusangulo.\n");
	}
	else
	{
		printf("Este e um triangulo acutangulo.");
	}

	return 0;
}
