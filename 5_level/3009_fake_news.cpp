#include <bits/stdc++.h>

using namespace std;

void solved()
{
    int n, k;
    cin >> n >> k;

    vector<int> pos(n);

    for (int i = 0; i < n; i++)
        cin >> pos[i];

    sort(pos.begin(), pos.end());

    int init = pos[0], end = pos[n - 1];

    int p = init, max = INT_MIN;

    while (init <= end)
    {
        int count = 0;

        for (int j = init; j <= init + k; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (pos[i] == j)
                {
                    count++;
                    break;
                }
            }
        }

        for (int j = init - k; j < init; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (pos[i] == j)
                {
                    count++;
                    break;
                }
            }
        }

        if (max < count)
        {
            max = count;
            p = init;
        }

        init++;
    }

    cout << p << "\n";
}

int main()
{
    int t;
    cin >> t;

    while (t--)
        solved();

    return 0;
}