#include<stdio.h>

int main (void)
{
	int n1, n2;
	
	scanf("%d %d", &n1, &n2);

	n1 > n2 ? printf("1\n") : printf("0\n");
	n1 == n2 ? printf("1\n") : printf("0\n");
	n1 < n2 ? printf("1\n") : printf("0\n");
	n1 != n2 ? printf("1\n") : printf("0\n");
	n1 >= n2 ? printf("1\n") : printf("0\n");	
	n1 <= n2 ? printf("1\n") : printf("0\n");
	
	return 0;
}
