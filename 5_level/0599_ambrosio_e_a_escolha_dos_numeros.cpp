#include <bits/stdc++.h>

using namespace std;

int count_one_in_bin(int n)
{
    int count = 0;

    while (n != 0)
    {
        count += n % 2;
        n /= 2;
    }
    
    return count;
}

void solved()
{
    int n, k;
    cin >> n >> k;

    int array[n];

    for (int i = 0; i < n; i++)
        cin >> array[i];
    
    priority_queue <int> count;

    for (int i = 0; i < n; i++)
        count.push(count_one_in_bin(array[i]));
    
    int max = 0;

    for (int i = 0; i < k; i++)
    {
        max += count.top();
        count.pop();
    }
    
    cout << max << "\n";
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
        solved();
    
    return 0;
}