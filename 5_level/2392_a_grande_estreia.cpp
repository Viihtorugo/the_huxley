#include <bits/stdc++.h>

using namespace std;

int count_zeros(int n, int *rua)
{
    int count = 0;

    for (int i = 0; i < n; i++)
        if (rua[i] == 0)
            count++;
    
    return count;
}

int next_number_not_zero (int i, int n, int *rua)
{
    
    while (i < n)
    {
        if (rua[i] != 0)
            return rua[i];

        i++;
    }
    
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int rua[2][n];

    for (int j = 0; j < 2; j++)
        for (int i = 0; i < n; i++)
            cin >> rua[j][i];

    int aux = count_zeros(n, &rua[0][0]);

    for (int i = 0; i < n; i++)
    {
        int v = rua[0][i];
        rua[0][i] = aux;

        if (v == 0)
            aux--;
        
    }

    aux = count_zeros(n, &rua[1][0]);

    for (int i = 0; i < n; i++)
    {
        int v = rua[0][i];
        rua[1][i] = aux;

        if (v == 0)
            aux--;

    }
    
    int dir, swap = 1;

    if (rua[0][0] < rua[1][0])
    {
        dir = 0;
    }
    else
    {
        dir = 1;
    }

    int m = 0, num = rua[dir][0];
    
    for (int i = 0; i < n; i++)
    {
        if (i + 1 != n)
        {           
            if (swap)
            {
                if (dir)
                {
                    if (rua[dir][i + 1] > rua[0][i + 1])
                    {
                        m++;
                        i++;
                        swap--;
                    }
                }
                else
                {
                    if (rua[dir][i + 1] > rua[1][i + 1])
                    {
                        m++;
                        i++;
                        swap--;
                    }
                }
            }
            
        }

        if (rua[dir][i] != num)
        {
            m++;
            num = rua[dir][i];
        }
    }

    cout << m << endl;

}