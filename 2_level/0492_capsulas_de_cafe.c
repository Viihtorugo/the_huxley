#include<stdio.h>

int countOfCups (int i)
{
	if(i > 7)
		return 0;

	int n;
	char  t;

	scanf("%d %c", &n, &t);

	if(t == 'P' || t == 'p')
		return (n * 10) + countOfCups(++i);
		
	if(t == 'G' || t == 'g')
		return (n * 16) + countOfCups(++i);

	return countOfCups(++i);
}


int main ()
{
	int nCups = countOfCups(1);
	
	printf("%d\n",nCups);
	printf("%d\n",(2*nCups)/7);

	return 0;
}
