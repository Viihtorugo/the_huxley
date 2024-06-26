#include <bits/stdc++.h>

using namespace std;

vector <string> slipt(string str, char c)
{
    vector <string> tokens;
    stringstream ss(str);
    string token;

    while (getline(ss, token, c)) {
        tokens.push_back(token);
    }
    
    return tokens;
}

void solved()
{
    string input;
    getline(cin, input);

    vector <string> list = slipt(input, ' ');
    sort(list.begin(), list.end());

    vector <string> list_org;

    for (auto s: list)
    {
        bool check = true;

        for (int i = 0; i < list_org.size(); i++)
            if(list_org[i] == s)
                check = false;
        

        if (list_org.empty() || check)
            list_org.push_back(s);
    }
    

    for (int i = 0; i < list_org.size(); i++)
    {
        cout << list_org[i];

        if (i + 1 == list_org.size())
        {
            cout << "\n";
        }
        else
        {
            cout << " ";
        }
    }
}

int main()
{
    string in;
    getline(cin, in);

    int t = stoi(in);

    while (t--)
    {
        solved();
    }

    return 0;
}