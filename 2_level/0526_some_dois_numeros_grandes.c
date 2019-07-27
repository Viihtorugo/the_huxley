#include <stdio.h>

int length_string (int i, char string[])
{
	if (string[i] == '\0')
		return i - 1;
	
	length_string(i + 1, string);
}

void print_sum (int n, int m, char string1[], char string2[], int aux)
{	
	if(n < 0 && m < 0)
		return;

	int sum = aux;
	if (n >= 0)
	{
		sum += (string1[n] - '0');
	}

	if (m >= 0)
	{
		sum += (string2[m] - '0');
	}
	
	print_sum(n - 1, m - 1, string1, string2, sum / 10);
	printf("%d", sum%10);
}

int main ()
{
	char num1[1000], num2[1000];
	scanf("%s %s", num1, num2);
	
	print_sum (length_string(0, num1), length_string(0, num2), num1, num2, 0);
	printf("\n");

	return 0;
}
