#include <bits/stdc++.h>

using namespace std;

int main ()
{
    queue <char> t;

    for (char i = 'A'; i <= 'P'; i++)
        t.push(i);
    
    for (int i = 1; i <= 15; i++)
    {
        int u, v;
        cin >> u >> v;

        char t1 = t.front();
        t.pop();
        char t2 = t.front();
        t.pop();

        if(u > v)
        {
            t.push(t1);
        }
        else
        {
            t.push(t2);
        }

    }
    
    cout << t.front() << '\n';

    return 0;
}