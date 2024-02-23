#include <bits/stdc++.h>

using namespace std;

void print_priority_queue(priority_queue<pair<int, pair<int, int>>> pq, vector<pair<string, int>> v)
{
    cout << "[";

    while (!pq.empty())
    {
        auto p = pq.top();
        auto w = p.second;
        pq.pop();

        cout << "['" << v[w.first].first << "', '" << v[w.second].first << "', " << -p.first << "]";

        if (pq.size() != 0)
            cout << ", ";
    }

    cout << "]" << endl;
}

int get_index(vector<pair<string, int>> v, string name)
{
    for (int i = 0; i < v.size(); i++)
        if (name == v[i].first)
            return i;

    return -1;
}

void bfs(vector<vector<pair<int, int>>> g, vector<pair<string, int>> v, int o, int d)
{
    if (o == -1 || d == -1)
        return;

    vector<int> distance(g.size(), INT_MAX);
    vector<int> heuristic(g.size(), INT_MAX);
    vector<int> destiny(g.size(), -1);
    priority_queue<pair<int, pair<int, int>>> pq;

    pq.push({0, {o, o}});
    distance[o] = 0;
    heuristic[o] = 0;

    while (!pq.empty())
    {
        auto p = pq.top();
        auto u = p.second;
        pq.pop();

        if (u.second == d)
            break;

        for (auto w : g[u.second])
        {
            if (distance[u.second] + w.second < distance[w.first])
            {
                distance[w.first] = distance[u.second] + w.second;
                pq.push({-(distance[w.first] + v[w.first].second), {u.second, w.first}});
                destiny[w.first] = u.second;
            }
        }

        print_priority_queue(pq, v);
    }

    stack <string> output;

    if (destiny[d] != -1)
    {
        int aux = d;

        while (aux != -1)
        {
            output.push(v[aux].first);
            aux = destiny[aux];
        }

        while (!output.empty())
        {
            cout << output.top();
            output.pop();

            if (output.size() != 0)
                cout << " ";
        }

        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);

    string o, d;
    cin >> o >> d;

    vector<pair<string, int>> v;
    string input;
    getline(cin, input);

    while (getline(cin, input))
    {
        istringstream iss(input);

        vector<string> s;

        do
        {
            string aux;
            iss >> aux;
            s.push_back(aux);
        } while (iss);

        if (s.size() == 1)
            break;

        v.push_back({s[0], stoi(s[1])});
    }

    vector<vector<pair<int, int>>> graph(v.size());

    string n1, n2;
    int w;

    while (cin >> n1 >> n2 >> w)
    {
        int id1 = get_index(v, n1), id2 = get_index(v, n2);

        if (id1 != -1 && id2 != -1)
            graph[id1].push_back({id2, w});
    }

    bfs(graph, v, get_index(v, o), get_index(v, d));

    return 0;
}