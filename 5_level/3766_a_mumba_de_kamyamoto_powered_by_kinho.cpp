#include <bits/stdc++.h>

using namespace std;

double dist(int x1, int y1, int z1, int x2, int y2, int z2)
{
    int value = pow((x2 - x1), 2) + pow((y2 - y1), 2) + pow((z2 - z1), 2);
    return sqrt(value);
}

bool check(vector<bool> visited)
{
    int count = 0;
    for (auto v : visited)
    {
        if (!v)
        {
            return true;
        }
        else
        {
            cout << count << endl;
        }

        count++;
    }

    return false;
}

int main()
{
    while (1)
    {
        int n;
        cin >> n;

        if (n == 0)
            return 0;

        vector<bool> visited(n + 1, false);
        int matrix[n + 1][3];

        for (int i = 1; i <= n; i++)
        {
            cin >> matrix[i][0] >> matrix[i][1] >> matrix[i][2];
        }

        cout << "Distancias: ";
        int aux = 0;
        while (check(visited))
        {
            visited[aux] = true;
            double m = 1000000;
            for (int i = 1; i <= n; i++)
            {
                if (!visited[i])
                {
                    double d = dist(matrix[i - 1][0], matrix[i - 1][1], matrix[i - 1][2], matrix[i][0], matrix[i][1], matrix[i][2]);
                    if (m > d)
                    {
                        m = d;
                        aux = i;
                    }

                    cout << d << endl;
                }
            }

            cout << aux << endl;
        }
    }
}