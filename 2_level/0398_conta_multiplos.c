#include <stdio.h>

int countMultiple (int i, int n1, int n2)
{
	if(i >= 50)
		return 0;
	
	if(i % n1 == 0 && i % n2 == 0)
		return 1 + countMultiple(i+1, n1, n2);
	
	return countMultiple(i+1, n1, n2);
}

int main ()
{
	int n1, n2;
	
	scanf("%d %d", &n1, &n2);
	
	printf("%d\n", countMultiple(1, n1, n2));

	return 0;
}
