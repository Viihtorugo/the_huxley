#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0;

    int n = 1;

    while (n >= 0)
    {
        cout << "Digite um numero inteiro:" << endl;
        cin >> n;

        if (n >= 0 && n <= 25)
        {
            c1++;
        }
        else if (n >= 26 && n <= 50)
        {
            c2++;
        }
        else if (n >= 51 && n <= 75)
        {
            c3++;
        }
        else if (n >= 76 && n <= 100)
        {
            c4++;
        }
    }
    
    cout << "Quantidade de numeros no intervalo 1: " << c1 << endl;
    cout << "Quantidade de numeros no intervalo 2: " << c2 << endl;
    cout << "Quantidade de numeros no intervalo 3: " << c3 << endl;
    cout << "Quantidade de numeros no intervalo 4: " << c4 << endl;
}

int main ()
{
    solve();
    return 0;
}