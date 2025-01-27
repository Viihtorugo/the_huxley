#include <bits/stdc++.h>

using namespace std;

int count (vector <int> v, int n)
{
    int c = 0;

    for (int i = 0; i < 3; i++)
    {
        c += v[i];

        if (c == n)
            return i + 1;
        
        if (c > n)
            return i;
    }
    
    return 3;
}

int main ()
{
    int n;
    cin >> n;

    vector <int> v(3);
    for (int i = 0; i < 3; i++)
        cin >> v[i];
    
    sort(v.begin(), v.end());

    cout << count(v, n) << '\n';

    return 0;
}