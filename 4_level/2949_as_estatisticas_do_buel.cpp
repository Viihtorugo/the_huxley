#include <bits/stdc++.h>

using namespace std;

void solve(int i)
{
    cout << "sequencia " << i << ":" << endl;

    int n;
    cin >> n;

    vector <int> array(n);
    vector <int> moda(202, 0);
    double average = 0;
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> array[i];

        int j = array[i];

        if (j < 0)
        {
            j *= -1;
            j += 100;
        }

        moda[j]++;

        if (moda[k] < moda[j])
            k = j;

        average += array[i];
    }

    sort(array.begin(), array.end());

    for (int i = 0; i < n; i++)
        cout << array[i] << " ";
    
    cout << endl;

    cout << array[0] << " " << array[n - 1] << endl;
    cout << average/n << endl;
    
    k = moda[k];

    for (int i = 202; i > 100; i--)
    {
        if (k > 1 && k == moda[i])
        {
            int aux = i - 100;

            aux = aux * (-1);

            cout << aux << " ";
        }
    }

    for (int i = 0; i < 101; i++)
        if (k > 1 && k == moda[i])
            cout << i << " ";
    
    cout << endl;

    if (n % 2 == 0)
    {
        cout << ((double) (array[n/2] + array[(n/2) - 1]))/2 << endl;
    }
    else
    {
        cout << array[n/2] << endl;
    }
}

int main ()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        solve(i);
    }
    

    return 0;
}