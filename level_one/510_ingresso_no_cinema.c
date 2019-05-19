#include<stdio.h>

int main(void)
{
	
	int student, old;
	
	scanf("%d %d", &student, &old);
	
	if(student == 1 || old == 1)
	{	
		printf("1\n");	
	}
	else
	{
		printf("0");
	}

	return 0;
}
