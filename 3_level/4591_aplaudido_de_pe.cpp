#include <bits/stdc++.h>

using namespace std;

void solved(int t)
{

    int n;
    string s;

    cin >> n >> s;

    int m = 0, x = 0;

    for (int i = 0; i < n + 1; i++)
    {
        int count = s[i] - (int)'0';
        if (x < i) {
            m += i - x;
            x = i;
        }

        x += count;
    }
     

    cout << "Case #" << t << ": " << m << "\n";
}

int main ()
{
    int t;
    cin >> t;

    for(int i = 1; i <= t; i++)
        solved(i);

    return 0;
}