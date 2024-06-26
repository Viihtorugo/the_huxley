#include <bits/stdc++.h>

using namespace std;

bool is_primo(long long s)
{
    if (s == 1 || s == 2 || s == 3)
        return true;

    for (long long i = 2; i <= sqrt(s); i++)
        if (s % i == 0)
            return false;

    return true;
}

void solved(long long s)
{

    for (long long i = 1; i < s; i++)
    {
        if (is_primo(i) && is_primo((1 << i) - 1))
        {
            cout << i << " ";
        }
    }

    cout << "\n";
}

int main()
{
    while (1)
    {
        long long s;
        cin >> s;

        if (s < 0)
            return 0;

        solved(s);
    }
}