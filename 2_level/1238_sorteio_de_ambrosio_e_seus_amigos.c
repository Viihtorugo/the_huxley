#include <stdio.h>

void set_array (int i, int n, int array[])
{
	if (i < n)
	{
		array[i] = 0;
		set_array(i + 1, n, array);
	}
}

int losing_player (int i, int n, int array[], int count)
{
	if (count != 0)
	{
		if (i < n)
		{
			return (array[i] == -1) 
				? losing_player(i + 1, n, array, count)
				: losing_player(i + 1, n, array, count - 1);
		}
		
		return losing_player(0, n, array, count);
	}
	

	array[i - 1] = -1;
	return (i == n)
		? 0
		: i;
}

void rounds (int i, int n, int array[], int size_array)
{
	if (n == 0)
		return;
	
	int count;
	scanf("%d", &count);

	i = losing_player(i, size_array, array, count);
	
	rounds (i, n - 1, array, size_array);
}

int winner_player (int i, int n, int array[])
{
	if(i < n)
	{
		if(!array[i])
			return i;
		
		winner_player(i + 1, n, array);
	}
}

int main ()
{
	int n;
	scanf("%i", &n);	
	
	int array[n];
	set_array(0, n, array);
	
	rounds(0, n - 1, array, n);

	printf("%i\n", winner_player (0, n, array));

	return 0;
}
