#include <bits/stdc++.h>

using namespace std;

void solve (vector <string> names, vector <int> path, int init)
{
    vector <string> output;

    while (init != -1 && path[init] != -1)
    {
        output.push_back(names[init]);
        int aux = init;
        init = path[init];
        path[aux] = -1;
    }

    for (int i = 0; i < output.size(); i++)
    {
        if (i + 1 == output.size())
        {
            cout << output[i] << endl;
        }
        else
        {
            cout << output[i] << " ";
        }
    }
    
}

int get_index(vector <string> names, string name)
{
    for (int i = 0; i < names.size(); i++)
        if (names[i] == name)
            return i;
    
    return -1;
}

int main ()
{
    int n, tam = 0;
    cin >> n;

    vector <string> names;
    vector <int> path;

    for (int i = 0; i < n; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;

        int index1 = get_index(names, s1);

        if (index1 == -1)
        {
            path.push_back(-1);
            names.push_back(s1);
            index1 = tam;
            tam++;
        }

        int index2 = get_index(names, s2);

        if (index2 == -1)
        {
            path.push_back(-1);
            names.push_back(s2);
            index2 = tam;
            tam++;
        }

        path[index1] = index2;
    }
    
    string init;

    cin >> init;
    cin >> init;

    int start = get_index(names, init);

    solve(names, path, start);

    return 0;
}