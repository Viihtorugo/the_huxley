#include <bits/stdc++.h>

using namespace std;

bool verification (vector <int> c1, vector <int> c2)
{
    for (int i = 0; i < 256; i++)
    {
        cout << "i = " << i << " c = " << (unsigned char) i << " c1 = " << c1[i] << " e c2 = " << c2[i] << endl;
        if (c1[i] != c2[i])
            return false;
    
    }
    return true;
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector <int> c1 (256, 0);
    vector <int> c2 (256, 0);

    string s1, s2;

    //getline(cin, s1);
    //getline(cin, s2);

    wchar_t c;
    while (wcin >> c)
    {
        cout << c;
        if (c != '\n')
            break;

        if (c == ' ' || c == ',' || c == '.' || c == '!' || c == '?') continue;

        if (c >= 'A' && c <= 'Z')
            c = c + 32;

        c1[c]++;
    }

    while (wcin >> c)
    {
        if (c == ' ' || c == ',' || c == '.' || c == '!' || c == '?') continue;

        if (c >= 'A' && c <= 'Z')
            c = c + 32;

        c2[c]++;
    }

    if (verification(c1, c2))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}