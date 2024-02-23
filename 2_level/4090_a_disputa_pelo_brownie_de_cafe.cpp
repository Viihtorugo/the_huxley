#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    getline(cin, s);

    int p1, p2;
    int c1 = 0, c2 = 0;

    for (auto c : s)
    {
        if (c == 'c')
            c2++;

        if (c == 'f')
            c1++;
    }

    if (c1 > c2)
    {
        p1 = 40;
        p2 = 0;
    }
    else
    {
        p1 = 0;
        p2 = 40;
    }

    cin >> c1 >> c2;

    if (c1)
        p1 += 20;

    if (c2)
        p2 += 20;

    cin >> c1 >> c2;

    if (c1 > c2)
    {
        p1 += 15;
    }
    else if (c1 < c2)
    {
        p2 += 15;
    }

    double g1, g2;

    cin >> g1 >> g2;

    if (g1 >= 2)
        p1 += 10;

    if (g2 >= 2)
        p2 += 10;

    if (p1 > p2)
    {
        cout << "Luiza tem mais chances de comer o brownie" << endl;
        cout << "Pontos:" << p1 << endl;
    }
    else
    {
        cout << "Pedro tem mais chances de comer o brownie" << endl;
        cout << "Pontos:" << p2 << endl;
    }

    return 0;
}