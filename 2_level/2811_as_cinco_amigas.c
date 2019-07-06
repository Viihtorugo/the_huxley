#include <stdio.h>

void output (char *name)
{
	printf("%s ganhou 50 reais\n", name);
}

int isPrime (int n, int i)
{	
	if(i == n)
		return 1;
	
	if(n % i == 0)
		return 1 + isPrime(n, i+1);
	
	return isPrime(n, i + 1);
}

void roundPlayer (int *count, int d)
{
	*count += d;

	if(*count > 50)
		*count -= 50;	

	if(isPrime(*count, 1) == 2)
		*count += 1;
}

int loop(int i, int count1, int count2, int count3, int count4, int count5)
{	
	if(i == 100)
		return 1;

	int d1, d2, d3, d4, d5;
	scanf("%d %d %d %d %d", &d1, &d2, &d3, &d4, &d5);
	
	roundPlayer(&count1, d1);
	roundPlayer(&count2, d2);
	roundPlayer(&count3, d3);
	roundPlayer(&count4, d4);
	roundPlayer(&count5, d5);
	
	if(count1 == 50)
	{
		output("Maria Magda");
		return 0;
	}

	if(count2 == 50)
	{
		output("Sofia");
		return 0;
	}
	
	if(count3 == 50)
	{
		output("Mikasa");
		return 0;
	}

	if(count4 == 50)
	{
		output("Pedrita");
		return 0;
	}
	
	if(count5 == 50)
	{
		output("Leticia");
		return 0;
	}

	return loop(i+1, count1, count2, count3, count4, count5);
}

int main ()
{
	if(loop(0, 1, 1, 1, 1, 1))
		printf("Ninguem ganhou\n");

	return 0;
}