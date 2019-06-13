#include <stdio.h>

char *battle(int v1, int v2, int d1, int d2, int round)
{
	if(v1 <= 0)
		return "Bezaliel\0";

	if(v2 <= 0)
		return "Clodes\0";

	if(round%2 == 0)
	{
		if(v2 > (round/2)*d1)
		{
			return battle(v1, v2, d1+50, d2, --round);
		}
		else
		{
			return battle(v1, v2-d1, d1, d2, --round);
		}
	}
	else
	{
		return battle(v1-d2, v2, d1, d2, --round);
	}
}

void loop(int n)
{	
	if(n == 0)
		return;	

	int v1, v2, d1, d2, round;

	scanf("%d %d %d %d", &v1, &v2, &d1, &d2);
	
	if((double) v2/d1 < (double)v1/d2)
	{
		if(v2%d1 == 0)
		{
			round = v2/d1;
		}
		else
		{
			round = (v2/d1)+1;
		}
	}
	else
	{
		if(v1%d2 == 0)
		{
			round = v1/d2;
		}
		else
		{
			round = (v1/d2)+1; 
		}
	}
	
	printf("%s\n", battle(v1, v2, d1, d2, round*2));

	loop(--n);
}

int main()
{
	int n;
	
	scanf("%d", &n);
	loop(n);	

	return 0;
}
