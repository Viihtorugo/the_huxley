#include <bits/stdc++.h>

using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int array[n + 1] = {0};

    for (int i = 1; i <= n; i++)
        cin >> array[i];    
    
    int b = 1, e = 1, count_final = INT_MIN;

    for (int i = 1; i <= n; i++)
    {
        int aux = i;
        int count = array[i];

        while (i + 1 <= n && array[i] < array[i + 1])
        {
            count += array[i + 1];
            i++;
        }

        if (count_final < count)
        {
            count_final = count;
            b = aux;
            e = i;
        }
    }

    cout << b << " " << e << " " << count_final << endl; 

    return 0;
}