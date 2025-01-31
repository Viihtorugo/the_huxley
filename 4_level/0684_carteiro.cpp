#include <bits/stdc++.h>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(NULL);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int house[n];

    unordered_map<int, int> index;

    for (int i = 0; i < n; i++)
    {
        cin >> house[i];
        index[house[i]] = i;
    }


    long long count = 0;
    int pos = 0, num;
    for (int i = 0; i < m; i++)
    {
        cin >> num;

        if (index.find(num) != index.end())
        {
            count += abs(pos - index[num]);
            pos = index[num];
        }

    }

    cout << count << '\n';
}