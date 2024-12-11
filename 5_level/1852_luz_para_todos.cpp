#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &g, vector<vector<int>> &w, vector<bool> &visited, int i, int f, long long &s1, long long &s2, int n)
{
    if (visited[i])
        return;

    visited[i] = true;

    if (f != -1 && w[f][i] != INT_MIN)
    {
        // cout << w[f][i] << "\n";

        s1 += w[f][i];

        if (n % 2 == 0)
            s2 += w[f][i];
    }

    for (auto v : g[i])
    {
        dfs(g, w, visited, v, i, s1, s2, n + 1);
    }
}

vector<vector<int>> prim(vector<vector<int>> g, vector<vector<int>> w, int n, int o)
{
    priority_queue<pair<int, int>> pq;
    vector<vector<int>> agm(n, vector<int>());

    pq.push({o, 0});

    vector<bool> visited(n, false);

    vector<int> parent(n, -1);

    while (!pq.empty())
    {
        int u = -pq.top().second;

        cout << u << "\n";
        pq.pop();

        if (parent[u] != -1 && visited[u] == false)
        {
            agm[parent[u]].push_back(u);
        }

        visited[u] = true;

        for (auto v : g[u])
        {
            if (!visited[v])
            {
                pq.push({-w[u][v], -v});
                parent[v] = u;
            }
        }
    }

    return agm;
}

void print_graph(vector<vector<int>> g, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i << ":";
        for (auto v : g[i])
        {
            cout << " " << v;
        }

        cout << "\n";
    }
}

int main()
{
    int n, m, c, r;
    cin >> n >> m >> c >> r;

    vector<vector<int>> g(n, vector<int>());
    vector<vector<int>> w(n, vector<int>(n, INT_MIN));

    for (int i = 0; i < m; i++)
    {
        int u, v, p;
        cin >> u >> v >> p;

        g[u].push_back(v);
        g[v].push_back(u);

        w[u][v] = p;
        w[v][u] = p;
    }

    vector<vector<int>> agm = prim(g, w, n, 0);

    long long sum1 = 0, sum2 = 0;
    vector<bool> visited(n, false);

    dfs(agm, w, visited, 0, -1, sum1, sum2, 0);
    print_graph(agm, n);

    cout << sum1 << " " << sum2 << "\n";

    return 0;
}