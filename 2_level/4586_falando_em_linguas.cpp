#include <bits/stdc++.h>

using namespace std;

void solved(int t)
{
    cout << "Case #" << t << ": ";

    int array[256];

    array[(int)'a'] = (int)'y';
    array[(int)'b'] = (int)'h';
    array[(int)'c'] = (int)'e';
    array[(int)'d'] = (int)'s';
    array[(int)'e'] = (int)'o';
    array[(int)'f'] = (int)'c';
    array[(int)'k'] = (int)'i';
    array[(int)'r'] = (int)'t';
    array[(int)'i'] = (int)'d';
    array[(int)'j'] = (int)'u';
    array[(int)'p'] = (int)'r';
    array[(int)'m'] = (int)'l';
    array[(int)'y'] = (int)'a';
    array[(int)'s'] = (int)'n';
    array[(int)'q'] = (int)'z';
    array[(int)'l'] = (int)'g';
    array[(int)'n'] = (int)'b';
    array[(int)'o'] = (int)'k';
    array[(int)'v'] = (int)'p';
    array[(int)'t'] = (int)'w';
    array[(int)'g'] = (int)'v'; 
    array[(int)'h'] = (int)'x';
    array[(int)'u'] = (int)'j';
    array[(int)'x'] = (int)'m';
    array[(int)'w'] = (int)'f';
    array[(int)'y'] = (int)'a';
    array[(int)'z'] = (int)'q';

    string s;
    getline(cin, s);

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            cout << " ";
        }
        else
        {
            cout << (char)array[s[i]]; 
        }
    }
    
    cout << '\n';
}

int main()
{
    string in;
    getline(cin, in);

    int t = stoi(in);

    for (int i = 1; i <= t; i++)
        solved(i);

    return 0;
}