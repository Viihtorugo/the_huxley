#include <bits/stdc++.h>

using namespace std;

bool solved(int num)
{
    int n;
    cin >> n;

    int array[n];

    for (int i = 0; i < n; i++)
        cin >> array[i];
    
    for (int i = 0; i < n; i++)
        if (array[i] == num)
            return true;
    
    return false;
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin.tie(0);

    int num;
    cin >> num;

    if (solved(num))
    {
        cout << "sim" << endl;
    }
    else
    {
        cout << "nao" << endl;
    }

    return 0;
}