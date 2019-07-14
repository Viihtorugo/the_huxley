#include <stdio.h>
#include <stdint.h>

void printPairs(uint8_t n)
{
	printf("%hhu\n", n);

	if(n == 0)
		return;

	printPairs(n-2);
}

int main ()
{
	uint8_t n;
	
	scanf("%hhu", &n);
	
	if (n % 2 != 0)
		n -= 1;
	
	printPairs(n);
 
	return 0;
}
