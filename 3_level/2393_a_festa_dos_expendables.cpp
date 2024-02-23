#include <bits/stdc++.h>

using namespace std;

//TLE!!!!

void pow(int &tam, int n, vector<int> &num)
{
    num[0] = 1;
    tam++;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        int j;

        for (j = 0; j < tam; j++)
        {
            int mult = sum + (num[j] * 2);
            num[j] =  mult % 10;
            sum = mult/10;
        }

        if (sum != 0)
        {
            num[j] = sum;
            j++;
        }

        tam = j;
    }
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, tam = 0;
    cin >> n;

    vector <int> num (100000, 0);

    pow(tam, n, num);

    for (int i = tam - 1, j = 1; i >= 0; i--, j++)
    {
        cout << num[i];

        if (j % 50 == 0)
            cout << endl;
    }
    
    cout << endl;

    return 0;
}