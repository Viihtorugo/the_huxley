#include <bits/stdc++.h>

using namespace std;

char seacher_char(vector <pair<char, char>> input, char item)
{
    for (int i = 0; i < input.size(); i++)
        if(input[i].first == item)
            return input[i].second;
        
    return '0';
}

void solved(vector <pair<char, char>> input)
{
    string out;
    cin >> out;

    for (int i = 0; i < out.size(); i++)
    {
        if (out[i] >= '0' && out[i] <= '9')
        {
            cout << seacher_char(input, out[i]);
        }
        else
        {
            cout << out[i];
        }
    }
    
    cout << "\n";
}

int main ()
{
    string num, in;
    cin >> num >> in;


    vector <pair<char, char>> input;

    for (int i = 0; i < num.size(); i++)
        input.push_back({num[i], in[i]});
    
    int t;
    cin >> t;
    
    while (t--)
        solved(input);

    return 0;
}