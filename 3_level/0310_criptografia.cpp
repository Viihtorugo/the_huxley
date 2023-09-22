#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s;
    getline(cin, s);

    vector <char> msg;

    for (auto c: s)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            char m = (char) ((int)c + 3);
            msg.push_back(m);
        }
        else
        {
            msg.push_back(c);
        }
    }
    
    vector <char> rev;

    for (int i = msg.size() - 1; i >= 0; i--)
        rev.push_back(msg[i]);
    
    for (int i = rev.size()/2; i < rev.size(); i++)
        rev[i] = rev[i] - 1;
    
    for (auto c: rev)
        cout << c;

    cout << endl;
}

int main ()
{
    int n;
    cin >> n;
    n++;

    while(n--)
        solve();

    return 0;
}