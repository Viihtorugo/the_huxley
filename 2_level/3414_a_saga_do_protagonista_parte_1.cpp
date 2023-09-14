#include <bits/stdc++.h>

using namespace std;

void solve (int a, int b)
{
    int i = max(a, b) - min(a, b);
    int count = 0;

    if (i % 3 == 2)
    {
        count = 1;
        i -= 2;
    }

    if (i % 3 == 1)
    {

        if (i == 1)
        {
            i += 2;

            count = 1;
        }
        else
        {
            i -= 4;
            count = 2;
        }
    }
    
    count = i/3;
    
    cout << count << endl;
}

int main ()
{
    int a, b;
    cin >> a >> b;

    solve(a, b);

    return 0;
}