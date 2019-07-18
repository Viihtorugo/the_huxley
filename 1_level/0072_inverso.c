#include<stdio.h>

void loop (int n)
{
	int num;
	
	scanf("%d", &num);
	
	if(n == 1)
	{
		printf("%d", num);
		return;
	}
	
	loop(n-1);
	printf(" %d", num);
	return;
}
 
int main()
{ 
	int n;
	
	scanf("%d", &n);

	loop(n);
	printf("\n");

	return 0; 
}
