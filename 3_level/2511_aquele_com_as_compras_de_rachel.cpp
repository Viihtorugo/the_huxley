#include <bits/stdc++.h>

using namespace std;

int solve (vector <string> lista)
{
    int count = 0;

    for (int i = 0; i < 7; i++)
    {
        string item;
        getline(cin, item);

        for (int j = 0; j < 5; j++)
        {
            if (lista[j] == item)
            {
                count++;
                break;
            }
        }
    }
    
    if (count == 5)
        return 1;
    
    return 0;
}

int main ()
{
    vector <string> lista (5);

    for (int i = 0; i < 5; i++)
        getline(cin, lista[i]);

    if (!solve(lista))
    {
        cout << "It is all just a moo point" << endl;
    }
    else
    {
        cout << "Could I be more happy?" << endl;
    }

    return 0;
}