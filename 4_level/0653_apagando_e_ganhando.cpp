#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, d;

    while (cin >> n >> d && (n+d))
    {
        int t = -1;
        char stack[n + 1];

        for (int i = 0; i < n; i++)
        {
            char c;
            cin >> c;

            while(t > -1 && d > 0 && c > stack[t])
            {
                t--;
                d--;
            }

            stack[++t] = c;
        }

        stack[++t] = '\0';
        cout << stack << endl;
    }
}

int main()
{
    solve();
    return 0;
}