#include <stdio.h>

int getLengthString (char *string)
{
	if (*string == '\0')
		return 0;

	return 1 + getLengthString(string+1);
}

void printReverseString(char string[], int i)
{
	if(i >= 0)
	{
		printf("%c", string[i]);
		printReverseString(string, i-1);
	}
	else
	{
		printf("\n");
	}
}

int main()
{
	char string[255];
	
	scanf("%[^\n]%*c", string);

	int i = getLengthString(string);
 	printReverseString(string, i);

	return 0;
}

