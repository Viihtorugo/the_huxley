#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<int> a, b;

    int num;

    for (int i = 0; i < 5; i++)
    {
        cin >> num;
        a.insert(num);
    }

    for (int i = 0; i < 5; i++)
    {
        cin >> num;
        b.insert(num);
    }

    set<int> c;
    int n = 0;

    while (a.size() != 0 && b.size() != 0)
    {
        int n1 = *a.begin();
        int n2 = *b.begin();

        if (n1 == n2)
        {
            c.insert(n1);
            n++;
            a.erase(n1);
            b.erase(n2);
        }
        else
        {
            if (n1 > n2)
            {
                b.erase(n2);
            }
            else
            {
                a.erase(n1);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        int num = *c.begin();
        cout << num;
        c.erase(num);

        if (i + 1 == n)
        {
            cout << '\n';
        }
        else
        {
            cout << ' ';
        }
    }

    return 0;
}