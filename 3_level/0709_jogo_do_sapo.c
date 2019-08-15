#include <stdio.h>

void set_array(int i, int n, int array[])
{
	if (i < n)
	{
		scanf("%d", &array[i]);
		set_array(i + 1, n, array);
	}
}

void set_pos_players (int i, int n, int array[])
{
	if (i < n)
	{
		array[i] = 0;
		set_pos_players(i + 1, n, array);
	}
}

void print_array (int i, int n, int array[])
{
	if(i < n)
	{
		printf("%d\n", array[i]);
		print_array(i + 1, n, array);
	}
}

void rounds(int i, int num_rounds, int n, int m, int tabuleiro[], int pos_players[])
{
	if (i < num_rounds)
	{
		int dado;
		scanf("%d", &dado);

		pos_players[i % m] += dado;
		pos_players[i % m] %= n;
		pos_players[i % m] += tabuleiro[pos_players[i % m]];
		
		if ( pos_players[i % m] < 0)
		{
			pos_players[i % m] += n;
		}

		pos_players[i % m] %= n;

		rounds(i + 1, num_rounds, n, m, tabuleiro, pos_players);
	}
}

int main ()
{
	int n, m, o;
	scanf("%d %d %d", &n, &m, &o);
	
	int tabuleiro[n];
	set_array(0, n, tabuleiro);
	
	int pos_players[m];
	set_pos_players(0, m, pos_players);
	
	rounds(0, m * o, n, m, tabuleiro, pos_players);
	
	print_array(0, m, pos_players);

	return 0;
}
