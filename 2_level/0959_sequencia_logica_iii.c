#include <stdio.h>

void print (int sum, int n1, int n2, int n3, int i)
{
	if (sum <= n2)
	{
		printf("%d", sum);
		
		if(i % n1 != 0)
		{
			printf(" ");
		}
		else
		{
			printf("\n");
		}
		
		print(sum + n3, n1, n2, n3, i + 1);
	}
}

int main() 
{	
	int n1, n2, n3;
	scanf("%d %d %d", &n1, &n2, &n3);
	
	print (1, n1, n2, n3, 1);
	
	return 0;
}
