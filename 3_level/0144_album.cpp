#include <bits/stdc++.h>

using namespace std;

void solved()
{
    bool v = false;

    int x, y;
    cin >> x >> y;

    int l1, l2, h1, h2;
    cin >> l1 >> h1 >> l2 >> h2;

    if (l1 + l2 <= x)
        if (max(h1, h2) <= y)
            v = true;

    if (l1 + l2 <= y)
        if (max(h1, h2) <= x)
            v = true;

    if (h1 + h2 <= x)
        if (max(l1, l2) <= y)
            v = true;

    if (h1 + h2 <= y)
        if (max(l1, l2) <= x)
            v = true;

    if (l1 + h2 <= x)
        if (max(h1, l2) <= y)
            v = true;

    if (l1 + h2 <= y)
        if (max(h1, l2) <= x)
            v = true;
    
    if (h1 + l2 <= x)
        if (max(l1, h2) <= y)
            v = true;

    if (h1 + l2 <= y)
        if (max(l1, h2) <= x)
            v = true;

    if (v)
    {
        cout << 'S' << endl;
    }
    else
    {
        cout << 'N' << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solved();

    return 0;
}