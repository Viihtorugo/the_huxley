#include <stdio.h>

int main ()
{
	int hStart, mStart,  hEnd, mEnd;
	
	scanf("%d %d %d %d", &hStart, &mStart, &hEnd, &mEnd);
	
	int minutes = ((hEnd*60)+mEnd) - ((hStart*60)+mStart);	
	
	if(minutes <= 0)
	{	
		minutes = 24*60 + minutes;
		printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", minutes/60, minutes%60);
	}
	else
	{
		printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", minutes/60, minutes%60);
	}

	return 0;
}
