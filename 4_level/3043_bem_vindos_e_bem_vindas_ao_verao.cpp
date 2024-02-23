#include <bits/stdc++.h>

using namespace std;

void solved()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    if (n1 < n2)
    {
        if (n2 >= n3)
        {
            cout << ":(" << endl;
            return;
        }
        else
        {
            int v1 = n2 - n1;
            int v2 = n3 - n2;

            if (v2 < v1)
            {
                cout << ":(" << endl;
                return;
            }
        }
    }
    else if (n1 > n2)
    {
        if (n2 > n3)
        {
            int v1 = n1 - n2;
            int v2 = n2 - n3;

            if (v2 >= v1)
            {
                cout << ":(" << endl;
                return;
            }
        }
    }
    else
    {
        if (n2 >= n3)
        {
            cout << ":(" << endl;
            return;
        }
    }

    cout << ":)"  << endl;
}

int main ()
{
    solved();
    return 0;
}