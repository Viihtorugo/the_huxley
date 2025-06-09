#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];

    vector<int> b_left(n);
    b_left[0] = h[0];
    int index = 0;
    for (int i = 1; i < n; i++)
    {
        if (h[i] <= b_left[index])
        {
            b_left[i] = b_left[index];
        }
        else
        {
            b_left[i] = h[i];
            index = i;
        }
    }

    vector<int> b_rigth(n);
    index = n - 1;
    b_rigth[index] = h[index];
    for (int i = n - 2; i >= 0; --i)
    {
        if (h[i] <= b_rigth[index])
        {
            b_rigth[i] = b_rigth[index];
        }
        else
        {
            b_rigth[i] = h[i];
            index = i;
        }
    }

    // for (int i = 0; i < n; i++)
    //     cout << b_left[i] << " ";
    // cout << '\n';
    // for (int i = 0; i < n; i++)
    //     cout << b_rigth[i] << " ";
    // cout << '\n';
    // for (int i = 0; i < n; i++)
        // cout << h[i] << " ";
    // cout << '\n';

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += b_left[i] > h[i] && b_rigth[i] > h[i];

    cout << ans << '\n';

    return 0;
}