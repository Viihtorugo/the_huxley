#include <bits/stdc++.h>

using namespace std;

bool check (vector <bool> number)
{
    for (int i = 0; i < 10; i++)
        if(!number[i])
            return true;
    
    return false;
}

void solved(int t)
{
    vector <bool> number (10, false);
    
    int n;
    cin >> n;

    if (n == 0)
    {
        cout << "Case #" << t <<": INSOMNIA\n";
        return;
    }
    
    int count = 1;
    int num;
    while(check(number))
    {
        int aux = count * n;
        num = aux;
        while(aux != 0)
        {
            int d = aux % 10;
            number[d] = true;
            aux = aux/ 10;

        }
        
        count++;
    }

    cout << "Case #" << t <<": " << num << "\n";
}

int main ()
{   
    int t;
    cin >> t;
    

    for (int i = 1; i <= t; i++)
        solved(i);

    return 0;
}