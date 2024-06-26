#include <bits/stdc++.h>

using namespace std;


int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    while(1)
    {
        string number;
        getline(cin, number);

        int t = stoi(number);
        
        if (t == 0)
            return 0;

        vector <string> names(t);
        
        for (int i = 0; i < t; i++)
            getline(cin, names[i]);

        sort(names.begin(), names.end());

        for (auto name: names)
            cout << name << "\n";
        
    }

}