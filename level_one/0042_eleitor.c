#include<stdio.h>

int main()
{
	int idade;
	
	scanf("%d", &idade);

	if(idade<16)
		printf("nao eleitor\n");
	
	if(idade>=18 && idade<=65)
		printf("eleitor obrigatorio\n");
	
	if(idade>=16 && idade<18 || idade>65)
		printf("eleitor facultativo\n");

	return 0;
}
