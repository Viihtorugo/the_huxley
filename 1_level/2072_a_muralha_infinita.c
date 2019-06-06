#include<stdio.h>

void cleanBuffer()
{
	if(getchar() != '\n')
		cleanBuffer();
}

int count (int n, int x, int y)
{
	if(n == 0)
		return 0;
	
	char p;

	cleanBuffer();
	scanf("%c", &p);

	if(p == 'D')
		x++;

	if(p == 'C')
		y++;

	return count(--n, x, y);
}

int main (void)
{
	
	int n;

	scanf("%d", &n);
	printf("%d\n", count(n, 0, 0));
	
	return 0;
}
