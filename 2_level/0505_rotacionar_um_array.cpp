#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int n;
    cin >> n;

    int array[n];

    for (int i = 0; i < n; i++)
        cin >> array[i];
    
    int i;
    cin >> i;

    for (int j = i; j < n + i; j++)
        cout << array[j % n] << endl;

    return 0;
}