#include <bits/stdc++.h>

using namespace std;

int string_with_int (int &i, string input)
{
    int number = 0;
    
    while ((int)input[i] >= (int)'0' && (int)input[i] <= (int)'9')
    {
        number = number * 10 + ((int) input[i]) % '0';
        i++;
    }
    
    return number;
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    int array[n];
    for (int i = 0, aux = n; i < n; i++, aux--)
        array[i] = aux;
    
    vector <pair<int, int>> cord;
    string input;
    cin >> input;
    
    for (int i = 0; i < input.size(); i++)
    {
        int c1 = -1, c2 =-1;
        
        if ((int)input[i] >= (int)'0' && (int)input[i] <= (int)'9')
        {
            c1 = string_with_int(i, input);
            i++;
        }
        
        
        if ((int)input[i] >= (int)'0' && (int)input[i] <= (int)'9')
        {
            c2 = string_with_int(i, input);
        }
        
        //cout << "(" << c1 << "," << c2 << ")\n";
        
        if (c2 != -1 && c1 != -1)
        {
            cord.push_back({c1, c2});
        }
    }
    
    for (int i = 0; i < cord.size(); i++)
    {
        cout << "(" << cord[i].first << "," << array[cord[i].second - 1] << ")";
        
        if (i + 1 != cord.size())
        {
            cout << ",";
        }
        else
        {
            cout << endl;
        }
    }
    
    return 0;
}