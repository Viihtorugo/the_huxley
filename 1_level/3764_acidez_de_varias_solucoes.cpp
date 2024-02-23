#include <bits/stdc++.h>

using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(1)
    {
        double ph;
        cin >> ph;

        if (ph == -1)
            break;

        if (ph < 7)
        {
            cout << "ACIDA" << endl;
        }
        else if (ph > 7)
        {
            cout << "BASICA" << endl;
        }
        else
        {
            cout << "NEUTRA" << endl;
        }
    }

    return 0;
}