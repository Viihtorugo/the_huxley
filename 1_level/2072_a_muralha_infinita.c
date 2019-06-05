#include<stdio.h>

int count (int n, int x, int y, int k)
{	
	printf("n = %d\n", n);
	if(n == 0)
		return 0;
	
	setbuf(stdin, NULL);
	
	char p;

	scanf("%c", &p);

	if(p == 'D')
	{
		if(x!=0 && y!=0)
			if(x == y)
				return count(--n, ++x, y, ++k);
		
		return count(--n, ++x, y, k);
	}

	if(p == 'C')
	{	
		if(x!=0 && y!=0)
			if(x == y)
				return count(--n, x, ++y, ++k);
		
		return count(--n, ++x, y, k);
	}
	
	return k;
}

int main (void)
{
	
	int n;

	scanf("%d", &n);

	printf("%d\n", count(n, 0, 0, 0));
	
	return 0;
}
