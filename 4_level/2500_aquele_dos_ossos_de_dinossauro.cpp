#include <bits/stdc++.h>

using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string s;

    vector <string> box;

    while (cin >> n >> s)
        while(n--)
            box.push_back(s);
    
    sort(box.begin(), box.end());

    cout << "[";

    for (int i = 0; i < box.size(); i++)
    {
        if (i + 1 != box.size())
        {
            cout << box[i] << ", ";
        }
        else
        {
            cout << box[i];
        }
    }
    

    cout << "]" << endl;

    return 0;
}