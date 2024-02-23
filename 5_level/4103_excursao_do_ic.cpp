#include <bits/stdc++.h>

using namespace std;

void solved()
{
    int n;
    cin >> n;

    vector <int> arr(n + 1, 0);
    int i = 1;

    int num;
    while (cin >> num)
    {
        if (num < 0)
            break;

        arr[i] = num;
        i++;
    }
    
    int k;
    cin >> k;

    cout << arr[k] << endl;
}

int main ()
{
    solved();

    return 0;
}