#include <bits/stdc++.h>

using namespace std;

void move(vector<vector<int>> map, int i, int j, int n, int m, int &count, int c, int b, int a)
{
    if (b != a)
        c++;

    if (i < 0 || j < 0 || i >= n || j >= m || map[i][j] == 0)
        return;

    if (i == n - 1 && j == m - 1)
    {
        count = min(count, c);
        return;
    }


    int aux = map[i][j];

    map[i][j] = 0;

    move(map, i + 1, j, n, m, count, c, a, 1);
    move(map, i, j + 1, n, m, count, c, a, 2);
    move(map, i - 1, j, n, m, count, c, a, 3);
    move(map, i, j - 1, n, m, count, c, a, 4);

    map[i][j] = aux;
}

void solve()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    int count = INT_MAX;

    if (map[0][0] == 1 && map[n - 1][m - 1] != 0)
    {
        move(map, 1, 0, n, m, count, 0, 1, 1);
        move(map, 0, 1, n, m, count, 0, 2, 2);
    }

    if (count != INT_MAX)
    {
        cout << "O caminho tem complexidade: " << count << "\n";
    }
    else
    {
        cout << "Continuem cavando!\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}