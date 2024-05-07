#include <bits/stdc++.h>

using namespace std;

int main ()
{
    vector <string> vector;
    string numbers;

    cout << "Digite uma String de números: \n";
    getline(cin, numbers);

    cout << "O inverso dos números digitados é: ";

    for (int i = vector.size() - 1; i >= 0; i--)
    {
        cout << vector[i];

        if (i == 0)
        {
            cout << ".\n";
        }
        else
        {
            cout << ", ";
        }
    }
    

    return 0;
}