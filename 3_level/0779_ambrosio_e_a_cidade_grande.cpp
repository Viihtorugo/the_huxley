#include <bits/stdc++.h>

using namespace std;

void print_temp (vector<int> temp_travel, vector<int> temp_wait, int n)
{
    if (n <= 0)
    {
        cout << "0" << endl;
        return;
    }

    int count = temp_travel[0];

    for (int i = 1; i < n; i++)
    {
        if (temp_travel[i] % temp_wait[i] == 0)
        {
            count += temp_travel[i];
        }
        else
        {
            int x = count / temp_wait[i];

            if (x != 0)
            {
                count = ((x + 1) * temp_wait[i]) + temp_travel[i];
            }
            else
            {
                count = temp_travel[i] + temp_wait[i];
            }
        }
    }
    
    cout << count << endl;
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> temp_travel(n);
    vector<int> temp_wait(n);

    for (int i = 0; i < n; i++)
        cin >> temp_travel[i];

    for (int i = 0; i < n; i++)
        cin >> temp_wait[i];
    
    print_temp(temp_travel, temp_wait, n);

    return 0;
}