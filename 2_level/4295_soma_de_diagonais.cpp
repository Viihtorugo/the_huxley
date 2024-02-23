#include <bits/stdc++.h>

using namespace std;

int char_to_int(int &i, string s1, bool s)
{
    int num = 0;

    while (i < s1.size() && (s1[i] >= '0' && s1[i] <= '9'))
    {
        num = num * 10 + ((int)s1[i]) % ((int)'0');
        i++;
    }

    if (s)
        num = -num;

    i--;

    return num;
}

int sum(vector< vector <int> > m1, vector< vector <int>> m2)
{
    int s = 0;

    for (int i = 0; i < m1.size(); i++)
    {
        for (int j = 0; j < m1[i].size(); j++)
        {
            if (i == j)
            {
                s += m1[i][j];
                break;
            }    
        }
    }
    
    for (int i = 0, j = m2.size() - 1; i < m2.size(); i++, j--)
    {
        s += m2[i][j];
    }
    
    return s;
}

int main()
{
    string s1;
    getline(cin, s1);

    vector<vector<int>> m1;

    for (int i = 1; i < s1.size() - 1; i++)
    {

        if (s1[i] == '[')
        {
            vector <int> c;
            
            m1.push_back(c);
            i++;

            int l = m1.size() - 1;

            while ((i < (s1.size() - 1)) && (s1[i] != ']'))
            {

                if (s1[i] == '-')
                {
                    i++;
                    m1[l].push_back(char_to_int(i, s1, true));
                }

                if (s1[i] >= '0' && s1[i] <= '9')
                    m1[l].push_back(char_to_int(i, s1, false));

                i++;
            }
        }
    }

    /*
    for (int i = 0; i < m1.size(); i++)
    {        
        for (int j = 0; j < m1[i].size(); j++)
        {
            cout << m1[i][j] << " ";
        }

        cout << endl;
    }
    */
    
    string s2;
    getline(cin, s2);

    vector<vector<int>> m2;

    for (int i = 1; i < s2.size() - 1; i++)
    {

        if (s2[i] == '[')
        {
            vector <int> c;
            
            m2.push_back(c);
            i++;

            int l = m2.size() - 1;

            while ((i < (s2.size() - 1)) && (s2[i] != ']'))
            {

                if (s2[i] == '-')
                {
                    i++;
                    m2[l].push_back(char_to_int(i, s2, true));
                }

                if (s2[i] >= '0' && s2[i] <= '9')
                    m2[l].push_back(char_to_int(i, s2, false));

                i++;
            }
        }
    }

    /*
    for (int i = 0; i < m2.size(); i++)
    {        
        for (int j = 0; j < m2[i].size(); j++)
        {
            cout << m2[i][j] << " ";
        }

        cout << endl;
    }
    */

    cout << sum(m1, m2) << endl;

    return 0;
}