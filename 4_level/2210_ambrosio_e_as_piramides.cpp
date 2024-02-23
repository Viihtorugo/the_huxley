#include <bits/stdc++.h>

using namespace std;

int get_tam_string(int n, int i, int count)
{
    if (i < n)
    {
        return get_tam_string(n, i + 1, count + 2);
    }

    return count;
}

void print(int tam, int h)
{
    if (h > 1)
    {
        print(tam, h - 2);
        int aux = tam - h;

        for (int i = 0; i < aux/2; i++)
            cout << ".";
        

        cout << "*";
        for (int i = 0; i < h - 2; i++)
            cout << "-";
        
        cout << "*";
        
        for (int i = 0; i < aux/2; i++)
            cout << ".";
        
        cout << endl;

    }
    else
    {
        int aux = tam;

        for (int i = 0; i < aux/2; i++)
            cout << ".";
        

        cout << "*";
        
        for (int i = 0; i < aux/2; i++)
            cout << ".";
        
        cout << endl;
    }
}

int main ()
{
    int n;
    cin >> n;

    int tam = get_tam_string(n, 1, 1);

    print(tam, tam);

    return 0;
}