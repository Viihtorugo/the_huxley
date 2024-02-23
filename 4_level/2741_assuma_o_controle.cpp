#include <bits/stdc++.h>

using namespace std;

int get_index(vector<string> output, string remove)
{
    for (int i = 0; i < output.size(); i++)
        if (output[i] == remove)
            return i;
    
    return -1;
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    bool v = false;
    vector <string> output;

    while (cin >> s)
    {
        if (s == "INSERIR")
        {
            string name;
            cin >> name;
            
            output.push_back(name);
        }
        else if (s == "REMOVER")
        {
            string name;
            cin >> name;
            
            int i = get_index(output, name);

            if (i != -1)
                output.erase(output.begin() + i);
        }
        else if (s == "IMPRIMIR")
        {
            if (v)
                cout << endl;

            v = true;

            cout << "Atualmente trabalhando:" << endl;

            for (auto o: output)
                cout << o << endl;

        }
    }

    return 0;
}