#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);

    string in;
    vector<pair<int, string>> requests;

    while (true)
    {
        getline(cin, in);

        if (in == "Fechando")
        {
            break;
        }
        
        if (in == "prato")
        {
            int n;
            string r;

            cin >> n;
            getline(cin, r);
            getline(cin, r);

            requests.push_back({n, r});
        }
        
        if (in == "clima")
        {
            string c;
            getline(cin, c);

            if (c == "Mare alta")
            {
                cout << "Retire os cliente e mesas 21 22 23 24 25 26" << endl;
            }
            else if (c == "Mare baixa")
            {
                cout << "prepare as mesas 21 22 23 24 25 26" << endl;
            }
            else if (c == "chuva leve")
            {
                cout << "Retire os cliente das mesas 13 14 15 16 17 18 19 20" << endl;
            }
            else if (c == "chuva")
            {
                cout << "Retire os clientes das mesas 13 14 15 16 17 18 19 20 21 22 23 24 25 26" << endl;
            }
            else if (c == "Tempestade")
            {
                cout << "Retire os clientes e mesas 13 14 15 16 17 18 19 20 21 22 23 24 25 26" << endl;
            }
            else if (c == "Armagedom")
            {
                cout << "Pawb allan, y gweddill yn cael eu tanio" << endl;
            }
        }
    }


    for (int i = 0; i < requests.size(); i++)
        cout << "Pedido " << i+1 << " ,mesa " << requests[i].first << " ,prato: " << requests[i].second << endl;
    

    cout << "tchau" << endl;

    return 0;
}