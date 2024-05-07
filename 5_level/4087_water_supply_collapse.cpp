#include <bits/stdc++.h>

using namespace std;

int main ()
{
    string name;
    getline(cin, name);

    if (name == "Moon Knight" || name == "Daredevil" || name == "Jessica Jones")
    {
        string day;
        getline(cin, day);

        int hours;
        cin >> hours;

        if (day == "Tuesday" && (hours >= 9 && hours <= 20))
        {
            cout << "Water Available\n";
        }
        else
        {
            cout << "Water not Available\n";
        }
    }
    else if (name == "WandaVision" || name == "Loki" || name == "Hawkeye")
    {
        string day;
        getline(cin, day);

        int hours;
        cin >> hours;

        if (day == "Wednesday" && hours >= 2)
        {
            cout << "Water Available\n";
        }
        else
        {
            cout << "Water not Available\n";
        }
    }
    else
    {
        cout << "Invalid Neighborhood\n";
    }

    return 0;
}