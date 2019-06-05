#include<stdio.h>

int main(void)
{
	int n1, n2, n3;
	
	scanf("%d %d %d", &n1, &n2, &n3);

	if(n1 == n2)
	{	
		if(n2 != n3)
		{
			printf("3\n");
		}
		else
		{
			printf("1\n");
		}
	}
	else
	{
		if(n2 == n3 || n1 == n3)
		{
			printf("3\n");
		}
		else
		{
			printf("2\n");
		}
	}

	return 0;
}
