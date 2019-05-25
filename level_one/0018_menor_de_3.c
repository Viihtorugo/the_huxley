#include<stdio.h>

int less(int n1, int n2, int n3)
{
	if(n1 <= n2)
	{
		if(n1 <= n3)
		{
			return n1;
		}
	}
	else
	{
		if(n2<=n3)
		{
			return n2;
		}
	}

	return n3;		
}

int main(void)
{
	int n1, n2, n3;
	
	scanf("%d %d %d", &n1, &n2, &n3);
	printf("%d\n", less(n1, n2, n3));	

	return 0;
}
