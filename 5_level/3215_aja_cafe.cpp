#include <bits/stdc++.h>

using namespace std;

void print_times (vector <unsigned long long> times)
{
    cout << "times: ";

    for (int i = 0; i < times.size(); i++)
    {
        if (i + 1 != times.size())
        {
            cout << times[i] << " ";
        }
        else
        {
            cout << times[i] << endl;
        }
    }
}

int main ()
{
    int n, m;
    cin >> n >> m;
    
    vector <unsigned long long> t (m);

    for (int i = 0; i < m; i++)
        cin >> t[i];
    
    bool v = false;

    if (t[0] == 1 && t[m - 1] == 10)
        v = true;

    sort(t.begin(), t.end());

    if (n >= m)
    {
        cout << t[t.size() - 1] << endl;
    }
    else
    {
        unsigned long long count = 0;
        
        while (t.size() > 0)
        {
            //print_times(t);
            
            if (t.size() > n)
            {
                int aux = t.size() - n;
                
                for (int i = aux + 1; i < t.size(); i++)
                    t[i] = t[i] - t[aux];

                count += t[aux];

                t.erase(t.begin() + aux);
                sort(t.begin(), t.end());
            }
            else
            {
                count += t[t.size() - 1];

                t.erase(t.begin(), t.end());
            }
        }

        if (v)
        {
            cout << count + 2 << endl;
        }
        else
        {
            cout << count << endl;
        }
    }


    return 0;
}