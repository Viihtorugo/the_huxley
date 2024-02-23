#include <bits/stdc++.h>

using namespace std;

void set_posicion(int x, int y, int w, vector <vector<int>> &matrix, int n)
{    
    int count = 0;
    
    for (int i = x; i < n; i++)
    {
        int walk = w - count;

        for (int j = y; j < n && walk >= 0; j++)
        {
            if (walk == 0)
                matrix[i][j] = 1;

            walk--;
        }

        walk = w - count;

        for (int j = y; j >= 0 && walk >= 0; j--)
        {
            if (walk == 0)
                matrix[i][j] = 1;

            walk--;
        }

        count++;
    }
    
    count = 0;

    for (int i = x; i >= 0; i--)
    {
        int walk = w - count;

        for (int j = y; j >= 0 && walk >= 0; j--)
        {
            if (walk == 0)
                matrix[i][j] = 1;

            walk--;
        }
        
        walk = w - count;

        for (int j = y; j < n && walk >= 0; j++)
        {
            if (walk == 0)
                matrix[i][j] = 1;
            
            walk--;
        }

        count++;
    }
}

bool verification (vector <vector <int>> matrix, int n, int k)
{
    int count = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (matrix[i][j] == k)
                count++;
    
    if (count > 1 || count == 0)
        return false;

    return true;
}

int main ()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector <vector <int>> matrix (n);

    for (int i = 0; i < n; i++)
    {
        vector<int> col(n, 0);
        matrix[i] = col;
    }
    
    for (int r = 0; r < k; r++)
    {
        int x, y, w;
        cin >> x >> y >> w;

        vector <vector <int>> aux (n);

        for (int i = 0; i < n; i++)
        {
            vector<int> col(n, 0);
            aux[i] = col;
        }

        set_posicion(x, y, w, aux, n);

        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (aux[i][j] == 1)
                {
                    matrix[i][j] += aux[i][j];
                }
                else
                {
                    matrix[i][j] = aux[i][j];
                }
            }
        }
        
    }
   
    if (verification(matrix, n, k))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == k)
                {
                    cout << i << " " << j << endl;
                    return 0;
                }
            }
        }
    }
    else
    {
        cout << "-1 -1" << endl;
    }
    
    return 0;
}