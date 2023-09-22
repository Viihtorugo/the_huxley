#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

void binary (lli n)
{
    if (n > 0)
    {
        binary(n/2);
        cout << n % 2 << endl;
    }
}

int main ()
{
    int n;
    cin >> n;

    if (n == 0)
    {
        cout << "0" << endl;
    }
    else
    {
        binary(n);
    }


    return 0;
}