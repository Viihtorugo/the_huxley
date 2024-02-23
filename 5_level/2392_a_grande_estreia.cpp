#include <bits/stdc++.h>

using namespace std;

void solve (int n, vector <vector <int>> street)
{
    int count = 0, end = INT_MAX;

    for (int i = 0; i < n; i++)
        count += street[0][i];
    
    end = min(count, end);
    count += 1;

    for (int i = 0; i < n; i++)
    {
        count -= street[0][i];
        count += street[1][i];
        end = min(count, end);
    }


    count = 0;

    for (int i = 0; i < n; i++)
        count += street[1][i];
    
    end = min(count, end);
    count += 1;

    for (int i = 0; i < n; i++)
    {
        count -= street[1][i];
        count += street[0][i];
        end = min(count, end);
    }
    

    cout << end << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <vector<int>> street (2);
    vector <int> s1 (n);
    vector <int> s2 (n);
    street[0] = s1;
    street[1] = s2;

    for (int j = 0; j < 2; j++)
    {
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;

            street[j][i] = !num;
        }
    }

    solve (n, street);
}