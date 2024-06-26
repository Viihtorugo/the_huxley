#include <bits/stdc++.h>

using namespace std;

int char_to_int(int i, int n, string s)
{
    int count = 1;
    int sum;
    
    if (s[n - 1] == 'I')
    {
        sum = 1;
    }
    else
    {
        sum = 0;
    }

    for (int j = n - 2; j >=  i; j--)
    {
        if (s[j] == 'I')
            sum = sum + (1 << count);
        
        count++;
    }

    return sum;
}

void solved(int t)
{
    int n;
    string s;
    cin >> n;
    cin >> s;

    bool flag = true;
    string out;

    cout << "Case #" << t <<": ";

    for (int i = 1; i <= n && flag; i++)
    {
        int num = char_to_int(8 * (i - 1), 8 * i, s);
        
        cout << (char) num;
    }
    cout << "\n";
}

int main ()
{
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
        solved(i);

    return 0;
}