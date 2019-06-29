#include <stdio.h>

int fibonacc(int n, int num, int aux)
{
	if(n == 1)
		return num;
	
	if(!num)
		return fibonacc(--n, 1, aux);
	
	return fibonacc(--n, num + aux, num);
}

int main ()
{
	int n;
	
	scanf("%d", &n);
	printf("%d\n", fibonacc(n, 0, 0));
		
	return 0;
}
