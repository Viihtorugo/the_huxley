#include <bits/stdc++.h>

using namespace std;

int backtracking(int i, int j, int n, int m, vector <vector<char>> map, bool &check, int count)
{
    if (i == n || j == m || map[i][j] == '|')
        return count;
    
    if(map[i][j] == 'o')
        count++;

    if(map[i][j] == '8')
        count+=2;

    if (i == n - 1 && j == m - 1)
    {
        check = true;
        return count;
    }

    int aux2 = backtracking(i, j + 1, n, m, map, check, count);
    int aux1 = backtracking(i + 1, j, n, m, map, check, count);

    if (aux1 > aux2)
        return aux1;
    
    return aux2;
}

void solved()
{
    int n, m;
    cin >> n >> m;

    vector <vector <char>>  map(n, vector<char>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    
    bool check = false;

    int count = backtracking(0, 0, n, m, map, check, 0);

    if (check)
    {
        cout << "SIM\n";
    }
    else
    {
        cout << "NAO\n";
    }

    cout << "Valor maximo de moedas: " << count << "\n";
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    solved();
    return 0;
}