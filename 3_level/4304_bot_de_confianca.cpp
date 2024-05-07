#include <bits/stdc++.h>

using namespace std;

void increment(int &po, queue<int> o, int &pb, queue<int> b)
{
    if (!o.empty() && o.front() != po)
    {
        if (o.front() > po)
        {
            po++;
        }
        else
        {
            po--;
        }
    }

    if (!b.empty() && b.front() != pb)
    {
        if (b.front() > pb)
        {
            pb++;
        }
        else
        {
            pb--;
        }
    }
}

int solved()
{
    int n;
    cin >> n;

    queue<int> o;
    queue<int> b;
    queue<char> f;

    for (int i = 0; i < n; i++)
    {
        char r;
        int v;
        cin >> r >> v;

        if (r == 'O')
        {
            o.push(v);
        }
        else if (r == 'B')
        {
            b.push(v);
        }

        f.push(r);
    }

    int t = 0;
    int po = 1;
    int pb = 1;

    while (!f.empty())
    {
        if (f.front() == 'O')
        {
            if (po == o.front())
            {
                f.pop();
                increment(po, o, pb, b);
                o.pop();
            }
            else
            {
                increment(po, o, pb, b);
            }
        }
        else
        {
            if (pb == b.front())
            {
                f.pop();
                increment(po, o, pb, b);
                b.pop();
            }
            else
            {
                increment(po, o, pb, b);
            }
        }

        t++;
    }

    return t;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        cout << "Caso #" << i << ": " << solved() << "\n";
    }

    return 0;
}