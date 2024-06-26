#include <bits/stdc++.h>

using namespace std;

void backtracking(int i, string t, string w, int k, vector<int> pos, int aux, bool &check)
{
    if (i == k)
    {
        check = false;

        for (int j = 0; j < k; j++)
        {
            cout << pos[j];

            if (j + 1 == k)
            {
                cout << "\n";
            }
            else
            {
                cout << " ";
            }
        }
        
        return;
    }

    for (int j = aux; j < t.size(); j++)
    {
        if (w[i] == t[j])
        {
            pos[i] = j + 1;
            backtracking(i + 1, t, w, k, pos, j, check);

        }
    }
    
}

int main ()
{
    string text, word;
    getline(cin, text);
    getline(cin, word);

    int k = word.size();
    vector <int> pos (k);
    
    bool check = true;

    backtracking(0, text, word, k, pos, 0, check);

    if(check)
        cout << "-1\n";
}