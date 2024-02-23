#include <bits/stdc++.h>

using namespace std;

int main ()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <pair<string, int>> players (n);

    for (int i = 0; i < n; i++)
    {
        cin >> players[i].first >> players[i].second;
    }
    
    int id;

    while(true)
    {
        cin >> id;

        if (id == -1)
            break;

        int v;
        cin >> v;

        if (id < n && id >= 0)
        {
            players[id].second += v; 
        }

        for (auto p: players)
            cout << p.first << " = " << p.second << endl;
        
    }

    return 0;
}