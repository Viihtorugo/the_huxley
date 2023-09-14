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
    int n;
    cin >> n;

    int rua[2][n];

    for (int j = 0; j < 2; j++)
        for (int i = 0; i < n; i++)
            cin >> rua[j][i];

    int aux = count_zeros(n, &rua[0][0]);

    for (int i = 0; i < n; i++)
    {
        if (rua[0][i] == 1)
        {
            rua[0][i] = 0;
        }
        else
        {
            rua[0][i] = aux;
            aux--;
        }
    }

    aux = count_zeros(n, &rua[1][0]);

    for (int i = 0; i < n; i++)
    {
        if (rua[1][i] == 1)
        {
            rua[1][i] = 0;
        }
        else
        {
            rua[1][i] = aux;
            aux--;
        }
    }
    
    int dir, swap = 1;

    int z1 = count_zeros(n, &rua[0][0]);
    int z2 = count_zeros(n, &rua[1][0]);

    if (z1 < z2)
    {
        dir = 0;
    }
    else
    {
        dir = 1;
    }

    int m = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (i + 1 != n && rua[dir][i + 1] != 0)
        {
            if (swap)
            {
                if (dir == 0)
                {
                    if (rua[1][i] != 0)
                    {
                        if (i + 1 != n && rua[1][i] < rua[dir][i + 1])
                        {
                            dir = 1;
                            swap--;
                        }
                    }
                    else
                    {
                        if (next_number_not_zero(i, n, &rua[1][i]) < rua[dir][i + 1])
                        {
                            dir = 1;
                            swap--;
                        }
                    }
                }
                else
                {
                    if (rua[0][i] != 0)
                    {
                        if (i + 1 != n && rua[0][i] < rua[dir][i + 1])
                        {
                            dir = 0;
                            swap--;
                        }
                    }
                    else
                    {
                        if (next_number_not_zero(i, n, &rua[0][i]) < rua[dir][i + 1])
                        {
                            dir = 0;
                            swap--;
                        }
                    }
                }
            }

            m++;
        }
    }
    
    cout <<  m << endl;

}