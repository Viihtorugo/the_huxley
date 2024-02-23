#include <bits/stdc++.h>

using namespace std;

int solve (int array[], int i, int n)
{
    if (i < n)
    {
        int l = i * 2;
        int r = l + 1;

        int pli = array[i] * solve(array, l, n);
        int pri = array[i] * solve(array, r, n);

        return max(pli, pri);
    }

    return 1;
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int h;
    cin >> h;

    int n = pow(2, h);

    int array[n];
    array[0] = INT_MIN;

    for (int i = 1; i < n; i++)
        cin >> array[i];

    cout << solve (array, 1, n) << endl;

    return 0;
}