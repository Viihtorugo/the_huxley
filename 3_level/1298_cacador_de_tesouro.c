#include<stdio.h>

void set_map (int i, int n, int m, char map[][m]) {
	
	if (i < n)
	{
		scanf(" %s", map[i]);
		set_map(i + 1, n, m, map);
	}
}

int count_teasures (int i, int n, int j, int m, char map[n][m], int count)
{
	if (i < 0 || i >= n || j < 0 || j > m || map[i][j] == '\0' || map[i][j] == '#')
		return count;

	if (i < n)
	{
		if (j < m)
		{
			char c = map[i][j];

			if (map[i][j] == 'b')
			{
				count += 1;
			}
			else if (map[i][j] == 'p')
			{
				count += 5;
			}
			else if (map[i][j] == 'o')
			{
				count += 10;
			}
			else if (map[i][j] == 'd')
			{
				count += 50;
			}

			map[i][j] = '#';

			int array[4];

			array[0] = count_teasures(i + 1, n, j, m, map, count);
			array[1] = count_teasures(i, n, j + 1, m, map, count);
			array[2] = count_teasures(i - 1, n, j, m, map, count);
			array[3] = count_teasures(i, n, j - 1, m, map, count);
			
			map[i][j] = c;

			int max = 0;

			for (int i = 1; i < 4; i++)
				if (array[i] > array[max])
					max = i;
			
			return array[max];
		}
	}

	return count;
}

int main () {

	int n, m;
	scanf("%d %d", &n, &m);

	char map[n][m + 1];
	set_map (0, n, m + 1, map);

	printf("%d\n", count_teasures(0, n, 0, m + 1, map, 0));

	return 0;
}
