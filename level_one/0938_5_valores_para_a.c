#include<stdio.h>

int inputNumbersNegatives(int i, int count)
{	
	int n;
	
	printf("Digite um valor:\n");
	scanf("%d", &n);
	
	if (n < 0)
		++count;

	if(i == 5)
		return count;
	
	return inputNumbersNegatives(++i, count);
}

int main(void)
{
	
	printf("Foram digitados %d numeros negativos\n", inputNumbersNegatives(1, 0));
	
	return 0;
}
