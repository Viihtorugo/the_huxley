#include <bits/stdc++.h>

using namespace std;

void solved(int t)
{
    int r, c, n;

    vector <vector<bool>> m(r, vector <bool> (c, false));

    int k = 0, count = 0;

    if (n > 0)
    {
        for (int i = 0; i < r && k < n; i++)
        {
            m[i][0] = true;
            k++;
        }

        for (int i = 0; i < r && k < n; i++)
        {
            m[i][c - 1] = true;
            k++;
        }

        for (int i = 1; i < r && k < n;; i++)
        {
            for (int j = 0; j < c && k < n; j ++)
            {
                if (m[i][j] == false)
                {
                    m[i][j] = true;
                    k++;
                }
            }
            
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c && k < n; j ++)
            {
                if (j + 1 != c)
                {
                    if (m[i][j] && m[i][j + 1])
                    {
                        count+=2;
                    }
                }
                else
                {
                    
                }
            }
        }
        
        
    }
    
    cout << "Case #" << t << ": " << count << "\n";
}

int main ()
{
    int t;
    cin >> t;

    for(int i = 1; i <= t; i++)
    {
        solved(i);
    }

    return 0;
}