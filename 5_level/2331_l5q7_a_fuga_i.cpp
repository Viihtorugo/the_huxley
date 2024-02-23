#include <bits/stdc++.h>

using namespace std;

bool desc(int a, int b) {
    return a > b; 
}

bool move(int map[10][10], int i, int j)
{
    if (i < 0 || j < 0 || i >= 10 || j >= 10 || map[i][j] == 0)
        return false;

    if (i == 9 && j == 9)
        return true;


    int up = i + 1, down = i - 1, left = j - 1, right = j + 1;

    int m = map[i][j];
    
    map[i][j] = 0;

    bool v = false;

    if (up != 10)
    {
        if ( map[up][j] == 1)
        {
            if (left != -1)
                map[i][left] = 0;

            if (right != 10)
                map[i][right] = 0;

            if (down != -1)
                map[down][j] = 0;

            v = move(map, up, j);
        }

    }


    if (v)
        return v;
    
    if (right != 10)
    {
        if ( map[i][right] == 1)
        {
            if (up != 10)
                map[up][j] = 0;

            if (left != -1)
                map[i][left] = 0;

            if (down != -1)
                map[down][j] = 0;

            v = move(map, i, right);
        }

    }
    

    if (v)
        return v;

    if (down != -1)
    {
        if ( map[down][j] == 1)
        {
            if (up != 10)
                map[up][j] = 0;

            if (left != -1)
                map[i][left] = 0;

            if (right != 10)
                map[i][right] = 0;

            v = move(map, down, j);
        }

    }
    
    if (v)
        return v;

    if (left != -1)
    {
        if ( map[i][left] == 1)
        {
            if (up != 10)
                map[up][j] = 0;

            if (down != -1)
                map[down][j] = 0;

            if (right != 10)
                map[i][right] = 0;

            v = move(map, i, left);
        }

    }   
    
    if (v)
        return v;
        
    map[i][j] = m;

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

    int map[10][10];

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            cin >> map[i][j];
    
    if (move(map, 0, 0))
    {
        cout << "Tudo nosso." << endl;
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