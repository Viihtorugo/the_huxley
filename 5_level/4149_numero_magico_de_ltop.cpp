#include <bits/stdc++.h>

using namespace std;

int main ()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);

    double fib[100001];

    int n;
    cin >> n;

    if (n > 2)
    {
        if (n == 3)
        {
            cout << "1.000000000000000" << endl;
        }
        else
        {
            fib[0] = 0;
            fib[1] = 1;

            for (int i = 2; i <= n; i++)
                fib[i] = fib[i - 1] + fib[i - 2];
            
            cout << fixed << setprecision(15) << fib[n]/fib[n - 1] << endl;
        }
    }
    else
    {
        cout << "Valor invalido" << endl;
    }

    return 0;
}