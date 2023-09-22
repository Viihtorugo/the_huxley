#include <bits/stdc++.h>

using namespace std;

typedef long long lli;

lli pot (lli b, lli n)
{
    return (n == 0) ? 1: b * pot(b, n - 1);
}

void convert (lli num)
{
    lli sum = 0;
    int count = 0;

    while (num > 0)
    {
        int d = num % 10;

        sum = sum + d * pot(2, count);

        ++count;
        num /= 10;
    }

    cout << sum << endl;
}

int main ()
{
    lli num;
    cin >> num;

    convert(num);

    return 0;
}