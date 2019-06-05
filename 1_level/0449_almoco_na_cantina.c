#include<stdio.h>

double count (char f, char d)
{
	double count = 0;
	
	if(f == 'e' || f == 'E')
		count += 11.0;

	if(f == 'L' || f == 'l')
		count += 8.0;

	if(d == 'r' || d == 'R')
		count += 3.0;
	
	if(d == 's' || d == 'S')
		count += 2.5;

	return count;
}

int main ()
{
	char food[12], drink[13], c;
	int i = 0;

	while( (c = getchar()) != '\n' && i < 11)
		food[i++] = c;

	food[++i] = '\0';	

	setbuf(stdin, NULL);
	i = 0;

	while( (c = getchar()) != '\n' && i < 12)
		drink[i++] = c;
	
	drink[++i] = '\0';

	printf("%.2lf\n", count(food[0], drink[0]) );

	return 0;
}
