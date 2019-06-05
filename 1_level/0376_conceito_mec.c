#include<stdio.h>

char concept (int ratio)
{
	if(ratio <= 8)
		return 'A';

	if(ratio <= 12 && ratio >= 9)
		return 'B';
	
	if(ratio <= 18 && ratio >= 13)
		return 'C';
	
	if(ratio > 18)
		return 'D';
}

int main (void)
{
	int numPeoples, quantBooks;
	
	scanf("%d %d", &numPeoples, &quantBooks);

	printf("%c\n", concept(quantBooks/numPeoples));

	return 0;
}
