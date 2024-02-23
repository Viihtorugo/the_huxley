#include <bits/stdc++.h>

using namespace std;

void dijkstra(vector<vector<pair<int, int>>> graph, vector <int> &dist)
{
    priority_queue <pair<int, int>> pq;
    pq.push({0,0});

    dist[0] = 0;

    while(!pq.empty())
    {
        int v = pq.top().second;
        pq.pop();

        for (auto edge: graph[v])
        {
            int u = edge.first;
            int w = edge.second;

            if (dist[v] + w < dist[u])
            {
                dist[u] = dist[v] + w;
                pq.push({-w,u});
            }
        }
    }
}

void solved(int t)
{
    int n, m;
    cin >> n >> m;

    vector <vector<pair<int, int>>> graph (n);
    vector <int> dist(n, INT_MAX);

    for (int i = 0; i < m; i++)
    {
        int v, u, w;
        cin >> v >> u >> w;

        graph[v - 1].push_back({u - 1, w});
        graph[u - 1].push_back({v - 1, w});
    }
    
    dijkstra(graph, dist);

    int count = 0;

    int k;
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        int c;
        cin >> c;

        count += 2*dist[c - 1];
    }
    
    cout << "caso " << t << ": " << count << endl;
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
        solved(i);

    return 0;
}