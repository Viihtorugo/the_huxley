#include <bits/stdc++.h>

using namespace std;

void inter (vector <int> v1, vector <int> v2)
{
    vector <int> in;

    int i = 0, j = 0, k = 0;

    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] > v2[j])
        {
            j++;
        }
        else if (v1[i] < v2[j])
        {
            i++;
        }
        else
        {
            if (k == 0)
            {
                in.push_back(v1[i]);
                k++;
            }
            else if (in[k - 1] != v1[i])
            {
                in.push_back(v1[i]);
                k++;
            }

            i++;
            j++;
        }
    }

    cout << "Vetor interseção (ordenado):";

    for (auto v: in)
        cout << " " << v;
    
    cout << endl;
}

int main ()
{
    cout << "Digite o vetor 1: " << endl;
    cout << "Digite o vetor 2: " << endl << endl;
    vector <int> v1, v2;
    
    int num;

    while (1)
    {
        scanf("%d", &num);

        if (num < 0)
            break;

        v1.push_back(num);
    }

    while (1)
    {
        scanf("%d", &num);

        if (num < 0)
            break;

        v2.push_back(num);
    }

    sort(v1.begin(), v1.end());

    vector <int> aux1;
    
    for (int i = 0; i < v1.size(); i++)
    {
        if (aux1.size() == 0)
            aux1.push_back(v1[i]);

        if (aux1.size() > 0)
            if (aux1[aux1.size() - 1] != v1[i])
                aux1.push_back(v1[i]);

    }
    
    sort(v2.begin(), v2.end());

    vector <int> aux2;
    
    for (int i = 0; i < v2.size(); i++)
    {
        if (aux2.size() == 0)
            aux2.push_back(v2[i]);

        if (aux2.size() > 0)
            if (aux2[aux2.size() - 1] != v2[i])
                aux2.push_back(v2[i]);

    }

    cout << "Vetor 1 (ordenado): ";

    for (auto v: aux1)
        cout << v << " ";
    
    cout << endl;

    cout << "Vetor 2 (ordenado): ";

    for (auto v: aux2)
        cout << v << " ";
    
    cout << endl;

    inter(aux1, aux2);

    return 0;
}