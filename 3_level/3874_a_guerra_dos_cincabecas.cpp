#include <bits/stdc++.h>

using namespace std;

bool perfect_square (int n)
{
    int i = 1;

    while (i * i <= n)
    {
        if (i * i == n)
            return true;

        i++;
    }

    return false;
}

bool is_prime(int n)
{
    int m = sqrt(n);

    for (int i = 2; i < m; i++)
        if (n % i == 0)
            return false;
    
    return true;
}

void solved ()
{
    int id1, id2, age2, age1;
    string name1, name2;

    cin >> age1 >> id1 >> name1 >> age2 >> id2 >> name2;

    int count1 = 0, count2 = 0;

    if (name1 > name2)
    {
        count1 += 2;
    }
    else if (name1 < name2)
    {
        count2 += 2;
    }

    if (is_prime(age1))
        count1 += 4;

    if (is_prime(age2))
        count2 += 4;

    if (perfect_square(id1))
        count1 += 3;

    if (perfect_square(id2))
        count2 += 2;

    if (count1 > count2)
    {
        cout << name1 << " WINS" << endl;
    }
    else if (count1 < count2)
    {
        cout << name2 << " WINS" << endl;
    }
    else
    {
        cout << "CInCABECAS EMPATADOS" << endl;
    }
}

int main ()
{
    solved();
    return 0;
}