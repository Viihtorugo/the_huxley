#include <bits/stdc++.h>

using namespace std;

int prim (vector <vector <pair<int, int>>> g, int n)
{
    priority_queue <pair<int,int>> pq;
    vector <int> pesos(n, INT_MIN);
    vector <bool> visited (n , false);

    pesos[0] = 0;
    pq.push({0, 0});

    while (!pq.empty())
    {
        int u = -pq.top().second;
        visited[u] = true;
        pq.pop();

        for (auto e: g[u])
        {
            int v = e.first;
            int w = e.second;
            
            if (w > pesos[v] && visited[v] == false)
            {
                pesos[v] = w;
                pq.push({w, -v});
            }
        }
        
    }
    
    int sum = 0;

    for (auto d : pesos)
        if (d != INT_MIN)
            sum += d;
    
    return sum;
}

void solved ()
{
    int n, m;
    cin >> n >> m;

    vector <vector <pair<int, int>>> graph (n);

    for (int i = 0; i < n; i++)
    {
        vector <pair<int, int>> e;
        graph[i] = e;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u - 1].push_back({v - 1, w});
        graph[v - 1].push_back({u - 1, w});
    }
    
    cout << prim(graph, n) << endl;
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
        solved();

    return 0;
}