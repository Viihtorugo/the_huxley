#include <stdio.h>

int loop (int yearStart, int yearEnd)
{
	if(yearStart > yearEnd)
		return 0;
	
	if((yearStart%400==0) || (yearStart%4==0 && yearStart%100!=0))
	{
		printf("%d\n", yearStart);
		return 1 + loop(++yearStart, yearEnd);
	}
	
	return loop(++yearStart, yearEnd);	
}

int main ()
{
	int yearStart, yearEnd;
	
	scanf("%d %d", &yearStart, &yearEnd);

	if(!loop(yearStart, yearEnd))
		printf("-1\n");
		
	return 0;
}
