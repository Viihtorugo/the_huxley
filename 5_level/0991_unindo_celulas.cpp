#include <bits/stdc++.h>

using namespace std;

int get_index (vector <int> a)
{
    int menor = 0;

    if (a.size() > 1)
        for (int i = 1; i < a.size(); i++)
            if (a[i] < a[menor])
                menor = i;

    return menor;
}

void print_array (vector <int> a, int menor)
{
    for (int i = menor; i < menor + a.size(); i++)
    {
        if (i + 1 == menor + a.size())
        {
            cout << a[i % a.size()] << endl;
        }
        else
        {
            cout << a[i % a.size()] << " ";
        }
    }
    
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector <int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int menor = get_index(a);

    print_array(a, menor);

    for (int i = 0; i < m; i++)
    {

        int begin;
        cin >> begin;
        
        while (begin < 0)
            begin += a.size();
        
        begin = (begin + menor) % a.size();
        
        int end = (begin + 1) % a.size(); 

        a[end] = a[begin] + a[end];

        vector<int>::iterator it;
        it = a.begin() + begin;

        a.erase(it);

        menor = get_index(a);
        print_array(a, menor);
    }
    

}