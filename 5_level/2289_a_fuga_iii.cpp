#include <bits/stdc++.h>

using namespace std;

bool desc(int a, int b) {
    return a > b; 
}

bool move(int n, int m, vector<vector<int>> &map, int i, int j, vector<string> &walking)
{
    if (i < 0 || j < 0 || i >= n || j >= m || map[i][j] == 0)
        return false;

    if (i == n - 1 && j == m - 1)
        return true;

    int p = map[i][j];

    map[i][j] = 0;

    walking.push_back("Sul");
    bool v = move(n, m, map, i + 1, j, walking);
    
    if(!v)
    {
        walking.erase(walking.end());
        walking.push_back("Leste");
        v = move(n, m, map, i, j + 1, walking);
    }
    
    if(!v)
    {
        walking.erase(walking.end());
        walking.push_back("Norte");
        v = move(n, m, map, i - 1, j, walking);
    }

    if(!v)
    {
        walking.erase(walking.end());
        walking.push_back("Oeste");
        v = move(n, m, map, i, j - 1, walking);
    }

    if (!v)
        walking.erase(walking.end());

    map[i][j] = p;

    return v;
}

bool verification (vector <int> array, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (array[i] == i)
            return true;

    }
    
    return false;
}

void solve ()
{
    cout << "Vamos nessa, temos que sair rapido..." << endl;

    int n, m;
    cin >> n >> m;

    vector <vector <int>> map;

    for (int i = 0; i < n; i++)
    {
        vector <int> aux(m);

        map.push_back(aux);

        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    }
    
    vector <string> walking;

    if (move(n, m, map, 0, 0, walking))
    {
        for (int i = 0; i < walking.size(); i++)
        {
            if (i + 1 != walking.size())
            {
                cout << walking[i] << ", ";
            }
            else
            {
                cout << walking[i] << endl;
            }
        }
    }
    else
    {
        cout << "Continuem cavando!" << endl;
    }

}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> array (n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        array[num]++;
    }

    if (verification(array, n))
    {
        solve();
    }
    else
    {
        cout << "Ja nao se pode confiar nos refens como antigamente..." << endl;
    }

    return 0;
}