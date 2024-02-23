#include <bits/stdc++.h>

using namespace std;

void print(int tam, int h, int n)
{

    if (tam >= h)
    {
        for (int i = 0; i < (tam - h)/2; i++)
            cout << " ";
        
        for (int i = 0; i < h; i++)
            cout << "X"; 

        cout << endl;

        print(tam, h + 2, n);
    }
    else
    {
        for (int i = 0; i < n/2; i++)
        {
            for (int i = 0; i < (tam - 2)/2; i++)
            {
                cout << " ";   
            }
            
            cout << "XX" << endl;
        }
    }
    
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int tam = 0;

    for (int i = 0; i < n; i++)
        tam += 2;

    print(tam, 2, n);

    return 0;
}