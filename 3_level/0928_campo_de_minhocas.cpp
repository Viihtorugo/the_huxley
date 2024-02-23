#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    int matrix[n][m];

    int out = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int count = 0;

        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];

            count += matrix[i][j];
        }

        out = max(out, count);
    }

    for (int j = 0; j < m; j++)
    {
        int count = 0;

        for (int i = 0; i < n; i++)
            count += matrix[i][j];

        out = max(out, count);
    }

    cout << out << endl;

    return 0;
}