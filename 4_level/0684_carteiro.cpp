#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int house[n];

    unordered_map<int, unordered_map<int, int>> dist;
    unordered_map<int, int> index;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &house[i]);
        index[house[i]] = i;
    }

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

        if (dist.find(pos) != dist.end())
        {
            count += dist[pos][index[num]];
            pos = index[num];
        }
    }

    cout << count << '\n';
}