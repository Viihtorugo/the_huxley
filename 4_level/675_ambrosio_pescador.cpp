#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);

    int x1, y1, x2, y2, x3, y3, v;
    cin >> x1 >> y1 >> x2 >> y2 >> v >> x3 >> y3;

    if (v == 1)
    {
        if (x1 <= x3 || x2 <= x3)
        {
            cout << "S" << endl;   
        }
        else
        {
            cout << "N" << endl;
        }

    }
    else
    {
        if (x3 <= x1 || x3 <= x2)
        {
            cout << "S" << endl;    
        }
        else
        {
            cout << "N" << endl;
        }
    }

    return 0;
}