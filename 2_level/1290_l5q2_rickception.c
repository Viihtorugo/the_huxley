#include<stdio.h>

int count (int n, int t, int i)
{
	if(i > t)
		return n;

	if(i%2 == 0)
		return count(n + (n % 5), t, ++i);
	
	return count(n + 3, t, ++i);
}

int main ()
{
	int n, t;
	
	scanf("%d %d", &n, &t);
	printf("%d\n", count(n, t, 1));
	
	return 0;
}
