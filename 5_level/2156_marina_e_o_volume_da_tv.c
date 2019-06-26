#include <stdio.h>

void chances (int n, int *vol)
{
	if(n == 0)
		return;

	int chanceVol;
	scanf("%i",  &chanceVol);
	
	(*vol) = (*vol) + chanceVol;
	
	if (*vol > 100)
		*vol = 100;

	if (*vol < 0)
		*vol = 0;
	
	return chances(--n, vol);	
}

void setData(int *vol, int *n)
{
	scanf("%i %i", vol, n);

	if(*n>=0 && *n<=10)
		if(*vol>=0 && *vol<=100)
			return;
	
	return setData(vol, n);
}

int main () 
{
	int vol, nChances;
	
	setData(&vol, &nChances);
	chances(nChances, &vol);

	printf("%i\n", vol);
}
