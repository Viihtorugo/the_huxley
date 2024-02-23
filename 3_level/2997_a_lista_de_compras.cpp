#include <bits/stdc++.h>

using namespace std;

typedef struct item
{
    int amount;
    double value;
    string name;
} item;


void insert(vector <item> &list)
{
    string name;
    double value;
    int amount;

    cin >> name >> value >> amount;

    item i;

    i.name = name;
    i.value = value;
    i.amount = amount;

    list.push_back(i);
}

void remove_item (vector <item> &list)
{
    double value;
    cin >> value;
    
    vector <int> indexs;

    for (int i = 0; i < list.size(); i++)
        if (list[i].value > value)
            indexs.push_back(i);
    
    for (auto i: indexs)
        list.erase(list.begin() + i);
}

void remove_amount (vector <item> &list)
{
    string name;
    int r;
    cin >> name >> r;

    for (int i = 0; i < list.size(); i++)
    {
        if (name == list[i].name)
        {
            if (list[i].amount > r)
            {
                list[i].amount = list[i].amount - r;
            }
            else
            {
                list.erase(list.begin()+i);
            }
        }

    }
}

void print(vector <item> &list)
{
    double count = 0;

    for (auto i: list)
        count += (i.value * i.amount);

    cout << fixed << setprecision(1) << "Atualmente a lista esta em R$" << count << endl << endl;
}

void search (vector <item> &list)
{
    string name;
    cin >> name;

    for (auto i: list)
    {
        if (i.name == name)
        {
            cout << i.name << endl;
            cout << "- " << i.value << endl;
            cout << "- " << i.amount << endl << endl;
            return;
        }
    }

    cout << name << " nao foi encontrado." << endl << endl;
}

int main ()
{
    vector <item> list;
    string op;

    while (cin >> op)
    {
        if (op == "INSERIR")
            insert(list);
        
        if (op == "REMOVER")
            remove_amount(list);
        
        if (op == "REMOVERGRUPO")
            remove_item(list);

        if (op == "CONSULTAR")
            print(list);

        if (op == "PROCURAR")
            search(list);
    }

    return 0;
}