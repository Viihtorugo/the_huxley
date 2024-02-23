#include <bits/stdc++.h>

using namespace std;

int sum_dig(int num)
{
    int sum = 0;

    while (num > 0)
    {
        sum += num % 10;
        num = num / 10;
    }

    return sum;
}

int is_prime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return 0;

    return 1;
}

int next_prime(int n)
{
    while (1)
    {
        n++;

        if (is_prime(n))
            return n;
    }
}

int mult_of_six(int n)
{
    int sum = 0;

    for (int i = 6; i < n; i += 6)
        sum += i;

    return sum;
}

bool check (vector <int> v, int cod)
{
    for (int i = 0; i < v.size(); i++)
        if (v[i] == cod)
            return true;
    
    return false;
}

void solve()
{
    vector<int> v_cod;
    vector<int> v_pos;

    while (1)
    {
        int cod, pos;
        cin >> cod >> pos;

        if (cod == 0 && pos == 0)
            break;

        int new_cod = (double)(cod + next_prime(cod)) / (double)(sum_dig(cod));
        int new_pos = mult_of_six(cod) - pos;

        if (new_pos < 0)
            new_pos *= -1;

        while (check(v_cod, new_cod))
            new_cod++;

        while (check(v_pos, new_pos))
            new_pos++;

        v_cod.push_back(new_cod);
        v_pos.push_back(new_pos);       
    }

    for (int i = v_cod.size() - 1; i >= 0; i--)
        cout << v_cod[i] << " - " << v_pos[i] << endl;
    
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}