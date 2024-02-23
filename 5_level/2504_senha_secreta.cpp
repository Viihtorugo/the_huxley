#include <bits/stdc++.h>

using namespace std;

int main ()
{
    string s;
    getline(cin, s);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int index;
        char c;

        cin >> index >> c;

        s[index] = c;
    }
    
    cout << s << endl;
}