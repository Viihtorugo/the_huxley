#include<stdio.h>

int fatorial (int n)
{
	if(n < 1)
		return 1;

	return n * fatorial(n-1);
}

void loop ()
{
	int n;
	
	scanf("%d", &n);
	
	if(n != -1)
	{
		printf("%d\n", fatorial(n));
		loop();
	}

}
 
int main()
{	
	loop();
	return 0;	
}     
