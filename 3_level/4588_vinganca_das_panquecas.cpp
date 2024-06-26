#include <bits/stdc++.h>

using namespace std;

void solved(int t)
{
    string s;
    getline(cin, s);

    stack <char> p;

    p.push(s[0]);
    int count = 0;

    for (int i = 1; i < s.size(); i++)
    {
        if(p.top() != s[i])
        {
            count++;

            stack <char> aux;

            while(!p.empty())
            {
                aux.push(s[i]);
                p.pop();
            }

            aux.push(s[i]);
            p = aux;
        }
        else
        {
            p.push(s[i]);
        }
    }
    
    if(p.top() == '-')
        count++;

    cout << "Case #" << t << ": " << count << "\n";
}

int main ()
{
    string in;
    getline(cin, in);

    int t = stoi(in);

    for(int i = 1; i <= t; i++)
    {
        solved(i);
    }

    return 0;
}