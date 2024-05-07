#include <bits/stdc++.h>

using namespace std;

bool move(vector<vector<int>> map, int i, int j, int n, int m, int count, int p)
{
    //if (i >= 0 && j >= 0 && i < n && j < m)
    //    cout << "i = " << i << " e j = " << j << " e map = " << map[i][j] << "\n";

    if (i < 0 || j < 0 || i >= n || j >= m || map[i][j] == 0 || map[n - 1][m - 1] == 0 || count == p)
        return false;

    if (i == n - 1 && j == m - 1)
        return true;

    if (map[i][j] > 1)
    {
        int aux = map[i][j];
        //cout << "aux = " << aux << "\n";

        map[i][j] = 0;

        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < m; x++)
            {
                if (aux == map[y][x])
                {
                    map[y][x] = 1;

                    if (move(map, y, x, n, m, count + 1, p))
                        return true;

                    map[y][x] = aux;
                }
            }
        }

        map[i][j] = aux;
    }

    int aux = map[i][j];

    map[i][j] = 0;

    bool v = move(map, i + 1, j, n, m, count, p);

    if (!v)
        v = move(map, i, j + 1, n, m, count, p);

    if (!v)
        v = move(map, i - 1, j, n, m, count, p);

    if (!v)
        v = move(map, i, j - 1, n, m, count, p);

    map[i][j] = aux;

    return v;
}

bool verification(vector<int> array, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (array[i] == i)
            return true;
    }

    return false;
}

void solve(int p)
{
    cout << "Vamos nessa, temos que sair rapido..." << endl;

    int n, m;
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    if (move(map, 0, 0, n, m, 0, p))
    {
        cout << "Tudo nosso" << endl;
    }
    else
    {
        cout << "Continuem cavando!" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> array(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        array[num]++;
    }

    if (verification(array, n))
    {
        solve(n);
    }
    else
    {
        cout << "Ja nao se pode confiar nos refens como antigamente..." << endl;
    }

    return 0;
}