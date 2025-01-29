#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int house[n], index[1000000001] = {0};

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &house[i]);
        index[house[i]] = i;
    }

    int dist[n][n];

    for (int i = 0; i < n; i++)
    {
        int c = 0;
        for (int j = i; j >= 0; j--)
        {
            dist[i][j] = c;
            c++;
        }

        c = 1;
        for (int j = i + 1; j < n; j++)
        {
            dist[i][j] = c;
            c++;
        }
    }

    int count = 0, pos = 0, num;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &num);

        count += dist[pos][index[num]];
        pos = index[num];
    }

    printf("%d\n", count);
}