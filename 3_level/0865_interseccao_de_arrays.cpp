#include <bits/stdc++.h>

using namespace std;

vector <int> inter(vector <int> v1, vector <int> v2, int n)
{
    vector <int> r;

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int i = 0, j = 0;

    while (i < n && j < n)
    {
        if (v1[i] > v2[j])
        {
            j++;
        }
        else if (v1[i] < v2[j])
        {
            i++;
        }
        else
        {
            int k = r.size() - 1;
            
            if (k == -1)
            {
                r.push_back(v1[i]);
            }
            else if (r[k] != v1[i])
            {
                r.push_back(v1[i]);;
            }

            i++;
            j++;
        }
    }

    return r;
}

int main ()
{
    int n;
    cin >> n;

    vector <int> v1 (n);
    vector <int> v2 (n);

    for (int i = 0; i < n; i++)
        cin >> v1[i];

    for (int i = 0; i < n; i++)
        cin >> v2[i];

    vector <int> r = inter(v1, v2, n);

    for (int i = 0; i < r.size(); i++)
        cout << r[i] << endl;

    return 0;
}