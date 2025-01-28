#include <bits/stdc++.h>

using namespace std;

void solved(int n, int m)
{
    int max = INT_MIN;

    vector<vector<int>> p(n, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);

        p[x][y] = z;
        p[x][y] = z;
    }

    int x = 0, y = 0, z = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (p[i][j] + p[j][k] > max)
                {
                    max = p[i][j] + p[j][k];
                    x = i;
                    y = j;
                    z = k;
                }
            }
        }
    }

    printf("%d %d %d\n", x, y, z);
}

int main()
{
    while (1)
    {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0)
            return 0;

        solved(n + 1, m);
    }
}