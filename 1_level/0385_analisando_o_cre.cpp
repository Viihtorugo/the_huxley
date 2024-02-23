#include <bits/stdc++.h>

using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k = 0;

    double average = 0, min = 1000000;
    string out;

    while (1)
    {
        string input;
        cin >> input;

        if (input == "999")
            break;

        double cre;
        cin >> cre;

        if (cre < min)
        {
            min = cre;
            out = input;
        }

        average += cre;
        k++;
    }
    
    cout << out << endl << fixed << setprecision(2) << average/k << endl;

    return 0;
}