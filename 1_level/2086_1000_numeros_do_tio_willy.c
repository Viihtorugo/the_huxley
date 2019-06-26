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

	printf("i = ");	
	if(i == 1000)
	{
		printf("%d appeared %d times\n", *num, count(*num, num-i, 0));
		loop(0, NULL);
	}
	
	int n;
	scanf("%d", &n);

	if(num == NULL)
		if(n == -1)
			return;
	*num = n;
	loop(++i, num+1);
}

int main ()
{	
	
	loop(0, NULL);

	return 0;
}

