#include <bits/stdc++.h>

using namespace std;

void convert_base(int n, int b, vector <int> &c_f)
{
    if (n > 0)
    {
        convert_base(n / b, b, c_f);
        c_f.push_back(n % b);
    }
}

unsigned long long fat (int n)
{
    if (n == 0 || n == 1)
        return 1;

    return n * fat(n - 1);
}

int main ()
{
    string s1;

    while (cin >> s1)
    {
        if (s1[0] == 'f' || s1[0] == 'F')
            break;

        int n = stoi(s1);
        int b;
        
        cin >> b;

        if (n < 0)
        {
            cout << "Numero negativo" << endl;
        }
        else
        {
            if (b <= 1 || b > 16)
            {
                cout << "Base invalida" << endl;
            }
            else
            {
                unsigned long long f = fat(n);
                vector <int> num_convert;
                
                convert_base(f, b, num_convert);

                int count_zero = 0, count_dig = 0;

                unsigned long long c_f = 0;

                for (auto d: num_convert)
                {
                    if (d > 10)
                    {
                        c_f = c_f * 100 + d;
                    }
                    else
                    {
                        c_f = c_f * 10 + d;
                    }
                }
                
                unsigned long long aux = c_f;

                while (aux > 0)
                {
                    count_dig++;

                    if (aux % 10 == 0)
                    {
                        count_zero++;
                    }

                    aux = aux/10;
                }

                cout << f << " " << c_f << " " << count_zero << " " << count_dig << endl;
            }
        }

    }

    return 0;
}