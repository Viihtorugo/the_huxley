#include <bits/stdc++.h>

using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int amount_ch;
    cin >> amount_ch;

    int count_ch = 0, count_adult = 0;

    while(1)
    {
        int amount_adult;
        cin >> amount_adult;

        if (amount_adult < 0)
        {
            break;
        }
        else
        {

            int amount_ch_res, amount_ch_guest;

            cin >> amount_ch_res >> amount_ch_guest;

            if (amount_ch_guest + amount_ch_res + count_ch <= amount_ch || (amount_ch_guest == 0 && amount_ch_res == 0))
            {
                cout << "Acesso permitido!" << endl;
                count_ch += amount_ch_guest + amount_ch_res;
                count_adult += amount_adult;
            }
            else
            {
                if (amount_ch_guest > 0)
                {
                    cout << "Acesso permitido devido a presenca de convidado(s)." << endl;
                    count_ch += amount_ch_guest + amount_ch_res;
                    count_adult += amount_adult;
                }
                else
                {
                    cout << "Capacidade maxima de criancas atingida/excedida." << endl;
                    cout << "Tem "<< count_ch - amount_ch << " crianca(s) a mais que as " << amount_ch << " permitidas." << endl;
                }
            }

            cout << "Adultos na piscina: " << count_adult << endl;
            cout << "Criancas na piscina: " << count_ch << endl;
            cout << "***" << endl;
        }
    }

    return 0;
}