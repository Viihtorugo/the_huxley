#include <stdio.h>

int main ()
{
	int year;
	
	scanf("%d", &year);
	
	if(year % 400 == 0)
	{
		printf("BISSEXTO\n");
	}
	else if(year % 4 == 0 && year % 100 != 0)
	{
		printf("BISSEXTO\n");
	}
	else
	{
		printf("NAOBISSEXTO\n");
	}

	return 0;
}
