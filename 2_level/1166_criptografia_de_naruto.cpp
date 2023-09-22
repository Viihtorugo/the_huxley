#include <bits/stdc++.h>

using namespace std;

void print_cript (string s)
{
    for (auto c: s)
    {
        if (c >= 'a' && c <= 'z')
        {
            char t = (char) (((int)'z') - ((int)c)%'a');
            cout << t; 
        }
        else
        {
            cout << c;
        }
    }
}

int main ()
{
    string s;
    getline(cin, s);

    print_cript(s);

    return 0;
}