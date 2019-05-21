#include<stdio.h>

int present (int t1, int t2, int t3)
{
	if(t1 == t2 || t1 == t3 || t2 == t3)
		return 1;

	if(t1 + t2 == t3 || t1 + t3 == t2 || t2 + t3 == t1)
		return 1;

	return 0;
}

int main (void)
{
	int t1, t2, t3;
	
	scanf("%d %d %d", &t1, &t2, &t3);
	
	present(t1, t2, t3) ? printf("S\n") : printf("N\n");
	
	return 0;
}
