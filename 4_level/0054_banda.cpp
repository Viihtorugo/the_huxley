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
        p[y][x] = z;
    }


    vector <int> a (3, 0);

    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (p[i][j] + p[j][k] + p[i][k] > max)
                {
                    max = p[i][j] + p[j][k] + p[i][k];
                    a[0] = i;
                    a[1] = j;
                    a[2] = k;
                }
            }
        }
    }

    sort(a.begin(), a.end());
    printf("%d %d %d\n", a[0], a[1], a[2]);
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