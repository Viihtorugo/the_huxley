#include<stdio.h>

void set_map (int i, int n, int m, char map[][m]) {
	
	if (i < n * m)
	{
		scanf("%c", &map[i / m][i % m]);
		set_map(i + 1, n, m, map);
	}
}

int main () {

	int n, m;
	scanf("%d %d", &n, &m);

	char map[n][m];
	set_map (0, n, m, map);

	return 0;
}
