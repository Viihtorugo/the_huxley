#include <bits/stdc++.h>

using namespace std;

void solve ()
{
    long long int n;
    cin >> n;

    cout << 1000000007 % n*(n-1)*(n-2) << endl;
}

int main ()
{
    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}