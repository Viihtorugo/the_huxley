#include <bits/stdc++.h>

using namespace std;

int dijkstra(vector <vector <int>> g, int o, int d)
{
    vector <int> dist (d, INT_MAX);

    queue <int> q;
    
    q.push(o);
    dist[o] = 0;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for (auto u: g[v])
        {
            if (dist[v] + 1 < dist[u])
            {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
        
    }

    return dist[d - 1];
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector <vector <int>> graph (n + 1);

    for (int i = 0; i < m; i++)
    {
        int v, u;
        cin >> v >> u;

        graph[v].push_back(u);
        graph[u].push_back(v);
    }
    
    int out = dijkstra(graph, 1, n + 1);

    if (out == INT_MAX)
        out = -1;

    cout << out << endl;
}

int main ()
{
    int n;
    cin >> n;

    while (n--)
        solve();
    
    return 0;
}