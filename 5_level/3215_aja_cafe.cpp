#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, t;

    cin >> n >> t;

    vector<unsigned int> temp(t);

    while (t--)
    {
        unsigned int item;
        cin >> item;

        temp.push_back(item);
    }

    unsigned int count = 0;

    sort(temp.begin(), temp.end());
    
    while (!temp.empty())
    {
        unsigned int res = temp.pop_back();

        for (int i = 1; i < n && i < t; i++)
        {
            unsigned int aux = temp.pop();

            if (res - aux >= 0)
            {
                res -= aux;
                count += aux;
            }
            else
            {
                res = aux - res;
                count += (aux - res);
                temp.push_back(res);

                sort(temp.begin(), temp.end());

                res = temp.pop_back();
            }

            t -= 1;
        }

        t -= 1;
    }

    cout << count << endl;

    return 0;
}