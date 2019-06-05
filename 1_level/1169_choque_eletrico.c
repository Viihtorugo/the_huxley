#include<stdio.h>

int potency (int level)
{
	if(level >= 1 && level <= 20)
		return 20 + (level * level * level);

	if(level >= 21 && level <= 40)
		return 8000 + ((level - 10) * (level - 10));

	if(level >= 41 && level <= 60)
		return 9000 + ( 5 * level );
	
	if(level >= 61 && level <= 80)
		return 9300 + ( 2 * level );

	return 9500 + level;
}

int main (void)
{
	int level;
	
	scanf("%d", &level);
	
	printf("Potencia de : %d W\n", potency(level));	
	
	return 0;
}
