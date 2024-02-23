#include <bits/stdc++.h>

using namespace std;

bool fight(vector <string> m1, vector <string> m2, int life[2])
{
    int t = 0;

    string in;
    int f;
    
    while (life[0] > 0 && life[1] > 0)
    {
        cin >> in;
        //cout << in << endl;
        if (in[0] == 'M')
            cin >> f;

        if (t % 2 == 0)
        {
            if (in[0] == 'C')
            {
                m1.push_back(in);
            }
            else
            {
                if (m2.size() > 0)
                {
                    vector <int> indexs;
                    
                    for (int i = m2.size() - 1; i >= 0; i--)
                        if (in[1] == m2[i][1])
                            indexs.push_back(i);
                    
                    for (auto i : indexs)
                        m2.erase(m2.begin() + i);
                }
                else
                {
                    life[1] -= f;
                }
            }
        }
        else
        {
            if (in[0] == 'C')
            {
                m2.push_back(in);
            }
            else
            {
                if (m1.size() > 0)
                {
                    vector <int> indexs;
                    
                    for (int i = m1.size() - 1; i >= 0; i--)
                        if (in[1] == m1[i][1])
                            indexs.push_back(i);
                    
                    for (auto i : indexs)
                        m1.erase(m1.begin() + i);
                }
                else
                {
                    life[0] -= f;
                }
            }
        }

        t++;
    }

    if (life[0] <= 0)
        return false;
    
    return true;
}


int main ()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);

    int life[2];
    
    cin >> life[0];

    life[1] = life[0];

    vector <string> m1, m2;

    if (fight(m1, m2, life))
    {
        cout << "O jogador 1 ganhou!" << endl;
    }
    else
    {
        cout << "O jogador 2 ganhou!" << endl;
    }

    return 0;
}