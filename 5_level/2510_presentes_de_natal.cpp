#include <bits/stdc++.h>

using namespace std;

bool compare (const pair<int, pair<double, string>> &v1, const pair<int, pair<double, string>> &v2)
{
    
    return v1.first > v2.first;
}

void solve()
{
    bool first = false;

    while (1)
    {
        string name;
        cin >> name;

        if (name == "*")
            return;

        if (first)
            cout << endl;

        int n;
        cin >> n;

        priority_queue <pair<int, pair<double, string>>, vector<pair<int, pair<double, string>>>, greater<pair<int, pair<double, string>>>> output;

        for (int i = 0; i < n; i++)
        {
            int priority;
            double value;
            string in;

            getline(cin, in);
            getline(cin, in);
            cin >> value >> priority;

            output.push({-priority, {value, in}});
        }
        
        //sort(output.begin(), output.end());

        cout << "Lista de " << name << endl;
        while (!output.empty())
        {
            auto p = output.top().second;
            output.pop();

            cout << fixed << setprecision(2) << p.second << " - R$" << p.first << endl;
        }

        first = true;
    }

}

int main ()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}