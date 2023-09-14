#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

lli count (lli n, lli p, lli i)
{
    if (n == 0)
        return p * i;

    lli num;
    cin >> num;

    return (num % 2 == 0) ? count (n-1, p + 1, i) : count (n - 1, p, i + 1);
}

int main ()
{
    lli n;
    cin >> n;

    cout << count(n, 0, 0) << endl;

    return 0;
}