#include <stdio.h>

void print (int i, int n1, int n2)
{
	if (i <= n2)
	{
		printf("%d", i);
		
		if(i % n1 != 0)
		{
			printf(" ");
		}
		else
		{
			printf("\n");
		}
		
		print(i + 1, n1, n2);
	}
}

int main() 
{	
	int n1, n2;
	scanf("%d %d", &n1, &n2);
	
	print (1, n1, n2);
	
	return 0;
}
