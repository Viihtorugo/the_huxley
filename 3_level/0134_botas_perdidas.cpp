#include <bits/stdc++.h>

using namespace std;

int count_pair(int boots[2][61])
{
    int count = 0;

    for (int i = 30; i < 61; i++)
        count += min(boots[0][i], boots[1][i]);
    
    return count;
}

void solve()
{
    int n;
    cin >> n;
    
    if (n != -1)
    {
        int boots[2][61];

        for (int i = 30; i < 61; i++)
        {
            boots[0][i] = 0;
            boots[1][i] = 0;
        }
        
        while (n--)
        {
            char c;
            int num;

            cin >> num >> c;

            if (c == 'D')
            {
                boots[0][num]++;
            }
            else
            {
                boots[1][num]++;
            }
        }

        cout << count_pair(boots) << endl;

        solve();
    }

    return;
}

int main ()
{
    solve ();

    return 0;
}