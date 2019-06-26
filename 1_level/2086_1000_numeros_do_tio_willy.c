#include<stdio.h>
#include <stdlib.h>

int count (int n, int *num, int i)
{	
	if(i == 1000)
		return 0;

	if(*num == n)
		return 1 + count(n, num+1, ++i);
	
	return count(n, num+1, ++i);
}

void loop (int i, int *num) {

	scanf("%i", num);
	
	if(i == 1000)
	{
		printf("%i appeared %i times\n", *num, count(*num, num-i, 0));
		return loop(0, realloc(num-i, 1001 * sizeof(int)));
	}

	if( (i == 0 && *num == -1) || num == NULL)
	{
		free(num);
		return;
	}

	return loop(++i, num+1);
}

int main ()
{	
	loop(0, malloc(1001 * sizeof(int)));
	
	return 0;
}

