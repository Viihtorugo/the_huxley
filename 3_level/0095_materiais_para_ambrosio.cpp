#include <bits/stdc++.h>

using namespace std;

bool compare (pair<double,string> e1, pair<double,string> e2)
{
    return e1.second < e2.second;
}

int main ()
{
    double value;
    cin >> value;

    int n;
    cin >> n;

    priority_queue <pair<double, string>> pq;

    for (int i = 0; i < n; i++)
    {
        string s;
        double v;
        cin >> s >> v;

        pq.push({-v, s});
    }
    
    vector <pair<double, string>> output;

    while(!pq.empty())
    {
        double v = -pq.top().first;

        if (value - v >= 0)
        {
            value -= v;

            output.push_back({v, pq.top().second});
            pq.pop();
        }
        else
        {
            break;
        }
    }
    
    sort(output.begin(), output.end(), compare);
    cout << fixed << setprecision(2);

    for (auto o: output)
        cout << o.second << " " << o.first << endl;
    
    cout << value << endl;

    return 0;
}